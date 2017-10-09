#include "stdafx.h"
#include "RtspCommands.h"

#include "RtspResponse.h"
#include "Utilities.h"
#include <boost/asio.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iomanip>

using namespace std;
using namespace MediaController::Constants;
using namespace MediaController::Rtsp;

void Extract(const std::string& ip, std::string& address, std::string& service);
string GetSessionUuid(const string& session);
Response ProcessResponse(boost::asio::ip::tcp::socket& socket);
string BuildGstCaps(MediaDescription description);

Commands::Commands(const string& streamUri, bool isVideo) :
    _baseUri(streamUri),
    _controlUri(streamUri),
    _dataPort(0),
    _rtcpPort(0),
    _cSeqNum(0),
    _ioService(),
    _pSocket(_ioService),
    _rSocket(_ioService),
    _isVideo(isVideo) { }

bool Commands::Options() {
    // Reset the value for the CSeq field.
    _cSeqNum = 0;

    // Send the OPTIONS request in the following format:
    // OPTIONS {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    GetSocket(this->_controlUri, this->_dataPort);
    this->_dataPort = _pSocket.local_endpoint().port();
    this->_rtcpPort = _rSocket.local_endpoint().port();
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kOptions << kWhitespace << this->_controlUri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kTwoNewLines;
    try { write(_pSocket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp;
    try { resp = ProcessResponse(_pSocket); }
    catch (...) { return false; }
    if (resp.statusCode == kStatusCode301 || resp.statusCode == kStatusCode302) {
        // Set the playback URI to the redirect location.
        typedef std::map<std::string, std::string>::iterator it_type;
        for (it_type iterator = resp.headers.begin(); iterator != resp.headers.end(); ++iterator) {
            string name = iterator->first;
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            if (name == kLowerCaseHeaderLocation) {
                this->_controlUri = iterator->second;
                Options();
                break;
            }
        }
    }
    
    if (resp.statusCode != kStatusCode200) { return false; }
    
    return true;
}

bool Commands::GetParameter() {
    // Increment the value for the CSeq field.
    _cSeqNum++;

    // Send the GET_PARAMETER request in the following format:
    // GET_PARAMETER {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Session: {_session}
    GetSocket(this->_controlUri, this->_dataPort);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kGetParameter << kWhitespace << this->_controlUri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderSession << kColonSpace << _sessionId << kTwoNewLines;
    try { write(_pSocket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp;
    try { resp = ProcessResponse(_pSocket); }
    catch (...) { return false; }
    if (resp.statusCode != kStatusCode200) { return false; }

    return true;
}

bool Commands::Describe(bool firstAttempt) {
    // Increment the value for the CSeq field.
    _cSeqNum++;

    // Send the DESCRIBE request in the following format:
    // DESCRIBE {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Accept: application/sdp
    GetSocket(this->_controlUri, this->_dataPort);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kDescribe << kWhitespace << this->_controlUri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderAccept << kColonSpace << kSdpMimeType << kTwoNewLines;
    try { write(_pSocket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp;
    try { resp = ProcessResponse(_pSocket); }
    catch (...) { return false; }
    if (resp.statusCode != kStatusCode200) { return false; }
    // Parse the session description information.
    SdpParser& parser = this->_sdp;
    parser.Parse(resp.content);
    MediaDescription md;
    if (_isVideo)
        md = parser.GetFirstVideo();
    else
        md = parser.GetFirstAudio();

    if (!firstAttempt) {
        // Set up the pipeline variables to use the correct values based on the transport protocol.
        this->_dataPort = md.isMulticast ? md.port : _pSocket.local_endpoint().port();
        this->_rtcpPort = md.isMulticast ? md.port + 1 : _rSocket.local_endpoint().port();
    }

    if (!parser.sessionControlUri.empty() && parser.sessionControlUri != "*")
        this->_controlUri = parser.sessionControlUri;

    return true;
}

bool Commands::Setup(bool firstAttempt) {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    MediaDescription md;
    if (_isVideo)
        md = this->_sdp.GetFirstVideo();
    else
        md = this->_sdp.GetFirstAudio();

    if (md.controlUri == "video" || md.controlUri == "audio")
        md.controlUri = _controlUri;

    // Send the SETUP request in the following format:
    // SETUP {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Transport: {md.protocol};unicast;client_port={_port}-{_port+1}
    GetSocket(md.controlUri, this->_dataPort);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kSetup << kWhitespace << md.controlUri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    if (!firstAttempt)
        requestStream << kHeaderTransport << kColonSpace << md.protocol << kSemicolon << (md.isMulticast ? "multicast" : "unicast");
    else
        requestStream << kHeaderTransport << kColonSpace << md.protocol << kSemicolon << "unicast";

    requestStream << ";client_port=" <<this->_dataPort << "-" <<this->_rtcpPort << kTwoNewLines;
    try { write(_pSocket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp;
    try { resp = ProcessResponse(_pSocket); }
    catch (...) { return false; }
    if (resp.statusCode != kStatusCode200) { return false; }
    // Set the session ID using the UUID obtained from the server response.
    this->_sessionId = GetSessionUuid(resp.session);

    return true;
}

bool Commands::SetupStream(MediaController::GstWrapper* gstwrapper, float speed, unsigned int unixTime) {
    // Increment the value for the CSeq field.
    _cSeqNum++;
    bool ret = false;

    // Send the PLAY request in the following format:
    // PLAY {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Session: {_sessionId}
    // Scale: {speed}
    // Range: clock={timeStr}
    string timeStr = Utilities::UnixTimeToRfc3339(unixTime);
    GetSocket(this->_controlUri, this->_dataPort);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kPlay << kWhitespace << this->_controlUri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    if (speed != 0)
        if (speed < 1.0f && speed > -1.0f)
            requestStream << kHeaderScale << kColonSpace << setprecision(1) << fixed << speed << kOneNewLine;
        else
            requestStream << kHeaderScale << kColonSpace << static_cast<int>(speed) << kOneNewLine;
    else
        requestStream << kHeaderRange << kColonSpace << "npt=0-" << kOneNewLine;

    if (unixTime != 0)
        requestStream << kHeaderRange << kColonSpace << "clock=" << timeStr.c_str() << kOneNewLine;

    requestStream << kHeaderSession << kColonSpace << this->_sessionId << kTwoNewLines;
    
    try { write(_pSocket, request); }
    catch (...) { return false; }

    // Parse the server response.
    Response resp;
    try { resp = ProcessResponse(_pSocket); }
    catch (...) { return false; }

    // If a redirect code was returned we need to tear down the current session and start a new one using the redirect location.
    if (resp.statusCode == kStatusCode301 || resp.statusCode == kStatusCode302) {
        // Set the playback URI to the redirect location.
        typedef std::map<std::string, std::string>::iterator it_type;
        for (it_type iterator = resp.headers.begin(); iterator != resp.headers.end(); ++iterator) {
            string name = iterator->first;
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            if (name == kLowerCaseHeaderLocation) {
                this->_controlUri = iterator->second;
                break;
            }
        }

        if (int(speed) != 0)
            gstwrapper->SetMode(MediaController::Controller::kPlayback);
        else
            gstwrapper->SetMode(MediaController::Controller::kLive);

        // Send the sequence of RTSP commands needed to start a new stream using the new location.
#ifndef WIN32
        ClearSocket();
#endif
        Options();
        Describe();
        Setup();
        ret = SetupStream(gstwrapper, speed, unixTime);
    }
    else if (resp.statusCode == kStatusCode200)
        return true;

    return ret;
}

void Commands::PlayStream(MediaController::GstWrapper* gstwrapper) {
    if (!gstwrapper->IsPipelineActive()) {
        // Update the pipeline using the description generated above.
        gstwrapper->SetPorts(this->_dataPort, this->_rtcpPort);
        gstwrapper->SetRtcpHostIP(this->_pSocket.remote_endpoint().address().to_string());

        if (_isVideo) {
            MediaDescription md = this->_sdp.GetFirstVideo();
            if (md.isMulticast)
                gstwrapper->SetMulticastAddress(md.ip);
            if (md.payload == 26)
                md.encoding = "JPEG";

            gstwrapper->SetCaps("video" + BuildGstCaps(md));
            gstwrapper->CreateVideoRtspPipeline(md.encoding);
        }
        else {
            MediaDescription md = this->_sdp.GetFirstAudio();
            if (md.isMulticast)
                gstwrapper->SetMulticastAddress(md.ip);

            gstwrapper->SetCaps("audio" + BuildGstCaps(md));
            gstwrapper->CreateAudioRtspPipeline();
        }
    }
}

void Commands::Pause() {
    // Increment the value for the CSeq field.
    _cSeqNum++;

    // Send the PAUSE request in the following format:
    // PAUSE {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Session: {_sessionId}
    GetSocket(this->_controlUri, this->_dataPort);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kPause << kWhitespace << this->_controlUri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderSession << kColonSpace << this->_sessionId << kTwoNewLines;
    try { write(_pSocket, request); }
    catch (...) { return; }

    // Parse the server response.
    try { ProcessResponse(_pSocket); }
    catch (...) { }
}

void Commands::Teardown() {
    // Increment the value for the CSeq field.
    _cSeqNum++;

    // Send the TEARDOWN request in the following format:
    // TEARDOWN {uri} RTSP/1.0
    // CSeq: {_cSeqNum}
    // User-Agent: Pelco VxSdk
    // Session: {_sessionId}
    GetSocket(this->_controlUri, this->_dataPort);
    boost::asio::streambuf request;
    ostream requestStream(&request);
    requestStream << kTeardown << kWhitespace << this->_controlUri << kWhitespace << kRtspVersion << kOneNewLine;
    requestStream << kHeaderCSeq << kColonSpace << _cSeqNum << kOneNewLine;
    requestStream << kHeaderUserAgent << kColonSpace << kActualUserAgent << kOneNewLine;
    requestStream << kHeaderSession << kColonSpace << this->_sessionId << kTwoNewLines;

    try { write(_pSocket, request); }
    catch (...) { return; }

    // Parse the server response.
    try { ProcessResponse(_pSocket); }
    catch (...) { return; }

    // Reset the value for the CSeq field.
    _cSeqNum = 0;
    // Reset the control URI
    this->_controlUri = _baseUri;
    this->_dataPort = this->_rtcpPort = 0;
}

void Commands::ResetPath(const string& streamUri) {
    this->_baseUri.clear();
    this->_controlUri.clear();
    this->_baseUri = this->_controlUri = streamUri;
}

//=======================================================
// Helpers
//=======================================================

/// <summary>
/// Get the existing socket connection or return a new socket.
/// </summary>
/// <param name="uriString">The location of the media.</param>
/// <param name="bindPort">The initial port to bind to.</param>
void Commands::GetSocket(const string& uriString, int bindPort) {
    string ip, port;
    Extract(uriString, ip, port);

    boost::system::error_code ec;
    boost::asio::ip::tcp::endpoint endpoint = _pSocket.remote_endpoint(ec);
    if (ec) {
        _pSocket.open(boost::asio::ip::tcp::v4());
        _pSocket.bind(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 0));
        _rSocket.open(boost::asio::ip::tcp::v4());
        _rSocket.bind(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 0));

        boost::asio::ip::tcp::resolver resolver(_ioService);
        boost::asio::ip::tcp::resolver::query query(ip, port);
        boost::asio::ip::tcp::resolver::iterator endpointIterator = resolver.resolve(query);
        boost::asio::ip::tcp::resolver::iterator end;

        boost::system::error_code error = boost::asio::error::host_not_found;
        while (error && endpointIterator != end) {
            _pSocket.connect(*endpointIterator++, error);
        }
    }
    else if (endpoint.address().to_string() != ip || to_string(endpoint.port()) != port) {
        _pSocket.shutdown(boost::asio::socket_base::shutdown_both);
        _pSocket.close();
        _rSocket.close();
        _pSocket.open(boost::asio::ip::tcp::v4());
        _pSocket.set_option(boost::asio::ip::tcp::socket::reuse_address(true));
        _pSocket.bind(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), bindPort));
        _rSocket.open(boost::asio::ip::tcp::v4());
        _rSocket.bind(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 0));

        boost::asio::ip::tcp::resolver resolver(_ioService);
        boost::asio::ip::tcp::resolver::query query(ip, port);
        boost::asio::ip::tcp::resolver::iterator endpointIterator = resolver.resolve(query);
        boost::asio::ip::tcp::resolver::iterator end;

        boost::system::error_code error = boost::asio::error::host_not_found;
        while (error && endpointIterator != end) {
            _pSocket.connect(*endpointIterator++, error);
        }
    }
}

/// <summary>
/// Clear any existing socket connections.
/// </summary>
void Commands::ClearSocket()
{
    _pSocket.close();
    _rSocket.close();
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
/// Build the GStreamers caps based on the values contained in the SDP response.
/// </summary>
/// <param name="description">The media description built from the SDP response.</param>
/// <returns>A GStreamer caps string.</returns>
string BuildGstCaps(MediaDescription description) {
    string caps;
    if (description.rate != -1)
        caps += str(boost::format(",clock-rate=(int)%1%") % description.rate);
    else {
        if (description.type == "audio")
            caps += ",clock-rate=(int)8000";
    }
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

        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (name == kLowerCaseHeaderContentLength) contentLength = stoi(value);
        if (name == kLowerCaseHeaderSession) res.session = value;
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
