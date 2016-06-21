#include "stdafx.h"
#include "RtspCommands.h"

#include "RtspResponse.h"
#include "Controller.h"
#include "Utilities.h"
#include "StreamBase.h"
#include "GstWrapper.h"
#include <boost/asio.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace std;
using namespace MediaController::Constants;
using namespace MediaController::Rtsp;

static int _cSeqNum;

void GetSocket(const string& uri, boost::asio::io_service& ioService, boost::asio::ip::tcp::socket& socket);
void Extract(const string& ip, string& address, string& service);
string GetControlLocation(string response);
string GetSessionUuid(const string& session);
Response ProcessResponse(boost::asio::ip::tcp::socket& socket);
string BuildGstCaps(MediaDescription description);

Commands::Commands(MediaController::Controller* controller, const string& liveUri) : _port(0) {
    this->_controller = controller;
    // The playback URI is returned as a redirect location when a Play call includes a range (seek).  So the initial playback
    // URI needs to be set to the live URI and get updated when the seek is performed.
    this->_liveUri = this->_playbackUri = liveUri;
}

bool Commands::Options() {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    // The locations of the live and playback streams are different, so we need to choose the right one for the current mode.
    string uri = this->_controller->GetMode() == MediaController::Controller::kLive ? _liveUri : _playbackUri;

    // Send the OPTIONS request in the following format:
    // OPTIONS {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket(ioService);
    GetSocket(uri, ioService, socket);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kOptions << kWhitespace << uri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kTwoNewLines;
    try { write(socket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp = ProcessResponse(socket);
    if (resp.statusCode != kStatusCode200) { return false; }
    
    return true;
}

bool Commands::GetParameter() {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    // The locations of the live and playback streams are different, so we need to choose the right one for the current mode.
    string uri = this->_controller->GetMode() == MediaController::Controller::kLive ? this->_liveUri : this->_playbackUri;

    // Send the GET_PARAMETER request in the following format:
    // GET_PARAMETER {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Session: {_session}
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket(ioService);
    GetSocket(uri, ioService, socket);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kGetParameter << kWhitespace << uri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderSession << kColonSpace << this->_sessionId << kTwoNewLines;
    try { write(socket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp = ProcessResponse(socket);
    if (resp.statusCode != kStatusCode200) { return false; }

    return true;
}

bool Commands::Describe() {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    // The locations of the live and playback streams are different, so we need to choose the right one for the current mode.
    string uri = this->_controller->GetMode() == MediaController::Controller::kLive ? this->_liveUri : this->_playbackUri;

    // Send the DESCRIBE request in the following format:
    // DESCRIBE {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Accept: application/sdp
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket(ioService);
    GetSocket(uri, ioService, socket);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kDescribe << kWhitespace << uri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderAccept << kColonSpace << kSdpMimeType << kTwoNewLines;
    try { write(socket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp = ProcessResponse(socket);
    if (resp.statusCode != kStatusCode200) { return false; }
    // Parse the session description information.
    SdpParser& parser = this->_controller->GetMode() == MediaController::Controller::kLive ? this->_liveSdp : this->_playbackSdp;
    parser.Parse(resp.content);
    const MediaDescription& md = parser.GetFirstVideo();

    if (!this->_controller->stream->GetGstreamer()->IsPipelineActive()) {
        // Set up the pipeline variables to use the correct values based on the transport protocol.
        _port = md.isMulticast ? md.port : socket.local_endpoint().port();;
        string multiOptions;
        if (md.isMulticast)
            multiOptions = str(boost::format(" address=%1%") % md.ip);

        // The elements in the GStreamer pipeline need to have unique names in order to run multiple instances.
        // So a random UUID is generated and appended to the element names.
        _uuid = boost::uuids::to_string(boost::uuids::random_generator()());
        string pipeline = str(boost::format(kRtspPipeline) % _uuid % BuildGstCaps(md) % _port % multiOptions % (_port + 1));
        // Update the pipeline using the description generated above.
        this->_controller->stream->GetGstreamer()->UpdatePipeline(pipeline);
    }

    // Set the live/playback URI to the control URL obtained from the server response.
    string newUri = GetControlLocation(resp.content);
    if (this->_controller->GetMode() == MediaController::Controller::kLive)
        this->_liveUri = newUri;
    else
        this->_playbackUri = newUri;

    return true;
}

bool Commands::Setup() {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    // The locations of the live and playback streams are different, so we need to choose the right one for the current mode.
    string uri = this->_controller->GetMode() == MediaController::Controller::kLive ? this->_liveUri : this->_playbackUri;
    const MediaDescription& md = (this->_controller->GetMode() == MediaController::Controller::kLive ? this->_liveSdp : this->_playbackSdp).GetFirstVideo();

    // Send the SETUP request in the following format:
    // SETUP {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Transport: {md.protocol};unicast;client_port={_port}-{_port+1}
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket(ioService);
    GetSocket(uri, ioService, socket);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kSetup << kWhitespace << uri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderTransport << kColonSpace << md.protocol << kSemicolon << (md.isMulticast ? "multicast" : "unicast");
    requestStream << ";client_port=" << _port << "-" << _port + 1 << kTwoNewLines;
    try { write(socket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp = ProcessResponse(socket);
    if (resp.statusCode != kStatusCode200) { return false; }
    // Set the session ID using the UUID obtained from the server response.
    this->_sessionId = GetSessionUuid(resp.session);

    return true;
}

bool Commands::Play(int speed) {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    bool ret = false;
    // The locations of the live and playback streams are different, so we need to choose the right one for the current mode.
    string uri = this->_controller->GetMode() == MediaController::Controller::kLive ? this->_liveUri : this->_playbackUri;

    // Send the PLAY request in the following format:
    // PLAY {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Session: {_sessionId}
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket(ioService);
    GetSocket(uri, ioService, socket);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kPlay << kWhitespace << uri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderSession << kColonSpace << this->_sessionId << kTwoNewLines;
    try { write(socket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp = ProcessResponse(socket);
    // If a redirect code was returned we need to tear down the current session and start a new one using the redirect location.
    if (resp.statusCode == kStatusCode301 || resp.statusCode == kStatusCode302) {
        // Copy the redirect location.
        string temploc = resp.headers[kHeaderLocation];

        // Redirect location cannot have "/video" on the end of the url.
        string videoEnding = "%2Fvideo";
        if (0 == temploc.compare(temploc.length() - videoEnding.length(), videoEnding.length(), videoEnding)) {
            boost::replace_last(temploc, videoEnding, "");
        }

        // Tear down the current session.
        Teardown();
        // Set the live URI to the copied redirect location.
        this->_liveUri = temploc;
        this->_controller->stream->GetGstreamer()->SetMode(MediaController::Controller::kLive);
        // Reset the value for the CSeq field.
        _cSeqNum = 0;
        // Send the sequence of RTSP commands needed to start a new stream using the new location.
        Options();
        Describe();
        Setup();
        ret = Play(speed);
    }
    if (resp.statusCode == kStatusCode200) {
        if (!this->_controller->stream->GetGstreamer()->IsPipelineActive()) {
            this->_controller->stream->GetGstreamer()->SetPipeline();

            // Subscribe to the GStreamer Src element in order to get timestamps.
            this->_controller->stream->GetGstreamer()->SubscribeToProbeEvents(_uuid);
        }
        return true;
    }
    return ret;
}

bool Commands::SeekPlay(unsigned int unixTime, int speed) {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    bool ret = false;
    // The locations of the live and playback streams are different, so we need to choose the right one for the current mode.
    string uri = this->_controller->GetMode() == MediaController::Controller::kLive ? this->_liveUri : this->_playbackUri;
    if (uri.empty())
        uri = this->_liveUri;

    // Send the PLAY request in the following format:
    // PLAY {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Session: {_sessionId}
    // Scale: {speed}
    // Range: clock={timeStr}
    string timeStr = Utilities::UnixTimeToRfc3339(unixTime);
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket(ioService);
    GetSocket(uri, ioService, socket);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kPlay << kWhitespace << uri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderSession << kColonSpace << this->_sessionId << kOneNewLine;
    requestStream << kHeaderScale << kColonSpace << speed << kOneNewLine;
    requestStream << kHeaderRange << kColonSpace << "clock=" << timeStr.c_str() << kTwoNewLines;
    try { write(socket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp = ProcessResponse(socket);
    // If a redirect code was returned we need to tear down the current session and start a new one using the redirect location.
    if (resp.statusCode == kStatusCode301 || resp.statusCode == kStatusCode302) {
        // Set the playback URI to the redirect location.
        this->_playbackUri = resp.headers[kHeaderLocation];
        this->_controller->stream->GetGstreamer()->SetMode(MediaController::Controller::kPlayback);
        // Reset the value for the CSeq field.
        _cSeqNum = 0;
        // Send the sequence of RTSP commands needed to start a new stream using the new location.
        Options();
        Describe();
        Setup();
        ret = SeekPlay(unixTime, speed);
    }
    if (resp.statusCode == kStatusCode200) {
        if (!this->_controller->stream->GetGstreamer()->IsPipelineActive()) {
            this->_controller->stream->GetGstreamer()->SetPipeline();

            // Subscribe to the GStreamer Src element in order to get timestamps.
            this->_controller->stream->GetGstreamer()->SubscribeToProbeEvents(_uuid);
        }
        return true;
    }
    return ret;
}

void Commands::Pause() {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    // The locations of the live and playback streams are different, so we need to choose the right one for the current mode.
    string uri = this->_controller->GetMode() == MediaController::Controller::kLive ? this->_liveUri : this->_playbackUri;

    // Send the PAUSE request in the following format:
    // PAUSE {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Session: {_sessionId}
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket(ioService);
    GetSocket(uri, ioService, socket);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kPause << kWhitespace << uri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderSession << kColonSpace << this->_sessionId << kTwoNewLines;
    try { write(socket, request); }
    catch (...) { return; }

    // Parse the server response.
    ProcessResponse(socket);
}

void Commands::Teardown() {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    // The locations of the live and playback streams are different, so we need to choose the right one for the current mode.
    string uri = this->_controller->GetMode() == MediaController::Controller::kLive ? this->_liveUri : this->_playbackUri;

    // Send the TEARDOWN request in the following format:
    // TEARDOWN {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Session: {_sessionId}
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket(ioService);
    GetSocket(uri, ioService, socket);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kTeardown << kWhitespace << uri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderSession << kColonSpace << this->_sessionId << kTwoNewLines;
    try { write(socket, request); }
    catch (...) { return; }

    // Parse the server response.
    ProcessResponse(socket);
    // Reset the session and URI values to their defaults.
    this->_sessionId.clear();
    this->_playbackUri = this->_liveUri;
    // Reset the value for the CSeq field.
    _cSeqNum = 0;
}

void Commands::ResetPath(const string& liveUri) {
    this->_liveUri.clear();
    this->_playbackUri.clear();
    this->_liveUri = liveUri;
}

//=======================================================
// Helpers
//=======================================================

/// <summary>
/// Create a new socket connection.
/// </summary>
/// <param name="uriString">The location of the media.</param>
/// <param name="ioService">An io_service reference.</param>
/// <param name="socket">A socket reference.</param>
void GetSocket(const string& uriString, boost::asio::io_service& ioService, boost::asio::ip::tcp::socket& socket) {
    string ip, port;
    Extract(uriString, ip, port);
    boost::asio::ip::tcp::resolver resolver(ioService);
    boost::asio::ip::tcp::resolver::query query(ip, port);
    boost::asio::ip::tcp::resolver::iterator endpointIterator = resolver.resolve(query);
    boost::asio::ip::tcp::resolver::iterator end;

    boost::system::error_code error = boost::asio::error::host_not_found;
    while (error && endpointIterator != end) {
        socket.close();
        socket.connect(*endpointIterator++, error);
    }
}

/// <summary>
/// Parse the IP and Port of an RTSP URI.
/// </summary>
/// <param name="uriString">The location of the media.</param>
/// <param name="ip">A string reference for the IP.</param>
/// <param name="port">A string reference for the port.</param>
void Extract(const string& uriString, string& ip, string& port) {
    boost::regex e("rtsp://(.+):(\\d+)/(.*)");
    boost::smatch what;
    if (regex_match(uriString, what, e, boost::match_extra)) {
        boost::smatch::iterator it = what.begin();
        ++it; // skip the first entry..
        ip = *it;
        ++it;
        port = *it;
    }
}

/// <summary>
/// Parse the control location contained within an RTSP response.
/// </summary>
/// <param name="response">An RTSP response.</param>
/// <returns>The control location.</returns>
string GetControlLocation(string response) {
    string controlLocation;
    string contentLine;
    stringstream responseStream(response);
    bool isVideoSection = false;

    while (getline(responseStream, contentLine)) {
        if (contentLine.substr(0, 7) == "m=video")
            isVideoSection = true;

        if (isVideoSection && contentLine.substr(0, 10) == str(boost::format("%1%:") % kControl)) {
            controlLocation = contentLine.substr(10, contentLine.length());
            boost::trim(controlLocation);
            break;
        }
    }
    return controlLocation;
}

/// <summary>
/// Build the GStreamers caps based on the values contained in the SDP response.
/// </summary>
/// <param name="description">The media description built from the SDP response.</param>
/// <returns>A GStreamer caps string.</returns>
string BuildGstCaps(MediaDescription description) {
    string caps;
    if (description.rate != -1)
        caps += str(boost::format(",clock-rate=(int)%1%") % description.rate);
    if (description.encoding != "")
        caps += str(boost::format(",encoding-name=(string)%1%") % description.encoding);
    if (description.payload != -1)
        caps += str(boost::format(",payload=(int)%1%") % description.payload);
    if (description.packetizationMode != "")
        caps += str(boost::format(",packetizationMode=(string)%1%") % description.packetizationMode);
    if (description.profileLevelId != "")
        caps += str(boost::format(",profile-level-id=(string)%1%") % description.profileLevelId);
    if (description.spropParameterSets != "")
        caps += str(boost::format(",sprop-parameter-sets=(string)\"%1%\"") % description.spropParameterSets);
    if (description.conferenceType != "")
        caps += str(boost::format(",a-type=(string)%1%") % description.conferenceType);

    return caps;
}

/// <summary>
/// Parse the session ID contained within an RTSP response.
/// </summary>
/// <param name="response">An RTSP response.</param>
/// <returns>The session ID.</returns>
string GetSessionUuid(const string& session) {
    string uuid = session;
    size_t pos = uuid.find(kSemicolon);
    if (pos != string::npos)
        uuid = uuid.substr(0, pos);
    return uuid;
}

/// <summary>
/// Process an RTSP response.
/// </summary>
/// <param name="socket">The socket to listen for the response on.</param>
/// <returns>The processed response.</returns>
Response ProcessResponse(boost::asio::ip::tcp::socket& socket) {
    Response res;
    boost::asio::streambuf buf;
    read_until(socket, buf, kOneNewLine);

    // Check that buf is OK.
    istream responseStream(&buf);
    string rtspVersion;
    responseStream >> rtspVersion;
    unsigned int statusCode;
    responseStream >> statusCode;
    string statusMessage;

    getline(responseStream, statusMessage);
    stringstream ss;
    ss << rtspVersion << kWhitespace << statusCode << statusMessage;
    res.statusCode = statusCode;
    if (!responseStream || rtspVersion.substr(0, 5) != "RTSP/")
        return res;

    // Read the buf headers, which are terminated by a blank line.
    read_until(socket, buf, kTwoNewLines);

    // Process the buf headers.
    string header;
    int contentLength = 0;
    while (getline(responseStream, header) && header != kReturn) {
        string name = header.substr(0, header.find(kColon));
        string value = header.substr(header.find(kColon) + 1);
        value = value.substr(0, value.find(kReturn));
        boost::algorithm::trim(value);

        if (name == kHeaderContentLength) contentLength = stoi(value);
        if (name == kHeaderSession) res.session = value;
        res.headers[name] = value;
    }
    if (contentLength == 0)
        return res;

    // Write whatever content we already have to output.
    stringstream ssContent;
    if (buf.size() > 0) ssContent << &buf;
    ssContent.seekg(0, ios::end);
    int size = static_cast<int>(ssContent.tellg());
    if (size > 0) contentLength -= size;
    ssContent.seekg(0, ios::beg);

    if (contentLength > 0) {
        // Read until EOF, writing data to output as we go.
        boost::system::error_code error = boost::asio::error::host_not_found;
        read(socket, buf,
            boost::asio::transfer_exactly(contentLength), error);
        ssContent << &buf;
    }
    res.content = ssContent.str();
    return res;
}
