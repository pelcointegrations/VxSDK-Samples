#include "stdafx.h"
#include "GstWrapper.h"

#include <gst/gst.h>
#include <gst/rtp/gstrtcpbuffer.h>
#include <gst/rtp/gstrtpbuffer.h>
#include <gst/video/video.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include <Winsock2.h>
#include "libsoup/soup-logger.h"

using namespace std;
using namespace MediaController;

GstPadProbeReturn OnRtcpPacketReceived(GstPad *localPad, GstPadProbeInfo *info, GstVars *vars) {
    if (GST_PAD_PROBE_INFO_TYPE(info) | GST_PAD_PROBE_TYPE_BUFFER) {
        GstBuffer *buff = gst_pad_probe_info_get_buffer(info);
        GstRTCPBuffer rtcp = { nullptr };
        if (gst_rtcp_buffer_map(buff, GST_MAP_READ, &rtcp)) {
            guint64 ntptime;
            GstRTCPPacket packet;
            gboolean more = gst_rtcp_buffer_get_first_packet(&rtcp, &packet);
            while (more) {
                // Check if the packet type is a sender report.
                GstRTCPType type = gst_rtcp_packet_get_type(&packet);
                if (type == GST_RTCP_TYPE_SR) {
                    // Parse the sender info.
                    gst_rtcp_packet_sr_get_sender_info(&packet, nullptr, &ntptime, nullptr, nullptr, nullptr);
                    // Convert the timestamp from NTP format to Unix format.
                    guint64 unixMsTime = gst_rtcp_ntp_to_unix(ntptime);
                    // Set the rtcpTimestamp value to the unixMsTime converted from milliseconds to seconds.
                    vars->rtcpTimestamp = static_cast<guint64>(unixMsTime / Constants::kMsInNs);
                }
                more = gst_rtcp_packet_move_to_next(&packet);
            }
            gst_rtcp_buffer_unmap(&rtcp);
        }
    }
    return GST_PAD_PROBE_OK;
}

GstPadProbeReturn OnRtpPacketReceived(GstPad *localPad, GstPadProbeInfo *info, GstVars *vars) {
    if (GST_PAD_PROBE_INFO_TYPE(info) | GST_PAD_PROBE_TYPE_BUFFER) {
        GstBuffer *buff = gst_pad_probe_info_get_buffer(info);
        GstRTPBuffer rtp = { nullptr };
        gpointer data;

        if (gst_rtp_buffer_map(buff, GST_MAP_READ, &rtp)) {
            // Parse the buffer based on the current mode.
            if (vars->mode == MediaController::Controller::kPlayback) {
                // Playback packets contain extension data, which gives us the stream time.
                if (gst_rtp_buffer_get_extension_data(&rtp, nullptr, &data, nullptr)) {
                    // Convert the time contained in the extension data from NTP format to Unix format.
                    vars->currentTimestamp = ntohl(*reinterpret_cast<unsigned long*>(data)) - Constants::kNtpToEpochDiffSec;
                    unsigned int curTime = vars->currentTimestamp;
                    // Send the timestamp event to all observers.
                    for (size_t i = 0; i < vars->observerList.size(); i++) {
                        TimestampEvent* newEvent = new TimestampEvent();
                        newEvent->unixTime = curTime;
                        newEvent->eventData = vars->eventData;
                        vars->observerList[i](newEvent);
                        delete newEvent;
                    }
                }
            }
            else {
                // Check if the packet is a marker packet.
                if (gst_rtp_buffer_get_marker(&rtp)) {
                    // Get the timestamp of the packet.  Note that this is not the actual time of the stream.  It is a
                    // time generated for the session to keep the internal clock in sync.
                    guint32 currentTs = gst_rtp_buffer_get_timestamp(&rtp);
                    guint64 rtcpTsMs = vars->rtcpTimestamp;

                    // If we have not received an RTCP timestamp yet, we set the current time to the time of the local PC.  Otherwise
                    // we calculate the stream time based on the RTCP timestamp and the elapsed time of the buffer clock.
                    if (rtcpTsMs != 0) {
                        if (vars->lastTimestamp != currentTs) {
                            // Get the payload type of the buffer.
                            guint8 payloadType = gst_rtp_buffer_get_payload_type(&rtp);
                            // Set the clock rate to the default value.
                            guint32 clockRate = Constants::kClockRate;
                            // If the payload type is not the standard type then use the default clock rate provided by GStreamer.
                            if (payloadType < Constants::kPayloadType)
                                clockRate = gst_rtp_buffer_default_clock_rate(payloadType);

                            // Calculate the frames per second of the stream based on the elapsed time between timestamps and the clock rate.
                            double fps = clockRate / ((currentTs - vars->lastTimestamp) * 1.0);
                            // Calculate the millisecond duration and add it to the last timestamp.
                            int ms = static_cast<int>((Constants::kMillisecondsFloat / (fps < 1 ? Constants::kMillisecondsInt : fps)) + 0.5);
                            rtcpTsMs += ms;

                            if (rtcpTsMs - ms == vars->rtcpTimestamp)
                                vars->rtcpTimestamp = rtcpTsMs;

                            // Send the timestamp event to all observers.
                            for (size_t i = 0; i < vars->observerList.size(); i++) {
                                TimestampEvent* newEvent = new TimestampEvent();
                                newEvent->unixTime = static_cast<unsigned int>(rtcpTsMs / Constants::kMillisecondsInt);
                                newEvent->eventData = vars->eventData;
                                vars->observerList[i](newEvent);
                                delete newEvent;
                            }
                        }
                    }
                    else {
                        vars->rtcpTimestamp = Utilities::CurrentUnixTime();
                        vars->rtcpTimestamp *= Constants::kMillisecondsInt;
                    }
                    // Set the lastTimestamp value to the newly generated value.
                    vars->lastTimestamp = currentTs;
                }
            }
            gst_rtp_buffer_unmap(&rtp);
        }
    }
    return GST_PAD_PROBE_OK;
}

GstPadProbeReturn OnJpegPacketReceived(GstPad *localPad, GstPadProbeInfo *info, GstVars *vars) {
    // Get the event info if available.
    GstEvent *event = GST_PAD_PROBE_INFO_EVENT(info);
    const GstStructure *baseEvent = gst_event_get_structure(event);
    if (baseEvent == nullptr)
        return GST_PAD_PROBE_OK;

    // Check if the event contains an http-headers element.
    if (g_ascii_strncasecmp(gst_structure_get_name(baseEvent), Constants::kHttpHeaders, sizeof Constants::kHttpHeaders) == 0) {
        // Get the response-headers element and verify it has the Content-Disposition header.
        const GstStructure *responseHeaders = gst_value_get_structure(gst_structure_get_value(baseEvent, Constants::kResponseHeaders));
        if (gst_structure_has_field(responseHeaders, Constants::kHeaderContentDisposition)) {
            // Parse the Content-Disposition header value.
            string content(gst_structure_get_string(responseHeaders, Constants::kHeaderContentDisposition));
            // Parse the timestamp contained within the Content-Disposition header value.
            boost::regex e("dataSession_(.*)Z_dataSourceId");
            boost::smatch what;
            if (regex_search(content, what, e, boost::match_partial)) {
                boost::smatch::iterator it = what.begin();
                ++it;
                string timestamp = *it;
                if (timestamp.empty())
                    return GST_PAD_PROBE_OK;

                // Format the timestamp string and convert it to a ptime value.
                boost::replace_all(timestamp, "T", Constants::kWhitespace);
                timestamp = timestamp.substr(0, timestamp.size() - 4);
                boost::posix_time::ptime t(boost::posix_time::time_from_string(timestamp));
                // Convert the time to a Unix timestamp.
                static boost::posix_time::ptime epoch(boost::gregorian::date(1970, 1, 1));
                unsigned int streamTs = static_cast<unsigned int>((t - epoch).total_seconds());
                // The timestamp is the current time on the server.  So we must adjust it for playback.
                if (vars->mode == Controller::kPlayback) {
                    // For playback, the initial time is set using the seek time.  It is then incremented based on the elapsed time between
                    // timestamps and the playback speed.
                    if (vars->lastTimestamp != 0 && vars->lastTimestamp != streamTs) {
                        vars->currentTimestamp += abs(static_cast<int>(streamTs - vars->lastTimestamp)) * static_cast<int>(vars->speed);
                    }
                }
                else {
                    // Substract one second from the time to adjust for latency.
                    vars->currentTimestamp = streamTs - 1;
                }
                // Set the lastTimestamp value to the newly generated value.
                vars->lastTimestamp = streamTs;
            }
        }
    }
    return GST_PAD_PROBE_OK;
}

void OnBusMessage(GstBus *bus, GstMessage *msg, GstVars *vars) {
    // GStreamer does not support MJPEG pull sources.  After receiving a JPEG from the server we receive an EOS (End of Stream) message
    // since no further images will be pushed out.  To work around this we set the pipeline to state to NULL when we get an EOS event
    // and then set it back to PLAYING.  This reinitializes the pipeline and it fetches a new image and the process repeats.  We also do
    // this when an error is received since it has the same effect of stopping the pipeline.
    switch (GST_MESSAGE_TYPE(msg)) {
    case GST_MESSAGE_EOS:
    case GST_MESSAGE_ERROR:
        // Set the pipeline to NULL.
        gst_element_set_state(vars->pipeline, GST_STATE_READY);
        // Send the latest timestamp parsed in the OnJpegPacketReceived method.
        for (size_t i = 0; i < vars->observerList.size(); i++) {
            if (vars->currentTimestamp == 0)
                break;

            // Send the timestamp event to all observers.
            for (size_t ii = 0; ii < vars->observerList.size(); ii++) {
                TimestampEvent* newEvent = new TimestampEvent();
                newEvent->unixTime = vars->currentTimestamp;
                newEvent->eventData = vars->eventData;
                vars->observerList[ii](newEvent);
                delete newEvent;
            }
        }
        // Set the pipeline back to playing.
        gst_element_set_state(vars->pipeline, GST_STATE_PLAYING);
        break;
    default:
        break;
    }
}

// Called when rtpbin has validated a payload that we can depayload.
static void OnPadAdded(GstElement * rtpbin, GstPad * new_pad, GstElement * depay)
{
    GstPad *sinkpad;
    GstPadLinkReturn lres;

    g_print("New payload on pad: %s\n", GST_PAD_NAME(new_pad));

    sinkpad = gst_element_get_static_pad(depay, Constants::kSink);
    g_assert(sinkpad);

    lres = gst_pad_link(new_pad, sinkpad);

    gst_object_unref(sinkpad);
}

GstWrapper::GstWrapper() {
    SetMode(Controller::kStopped);
    Init();
    _gstVars.isPipelineActive = false;
}

GstWrapper::~GstWrapper() { }

void GstWrapper::Init() {
    if (!gst_is_initialized())
        gst_init(nullptr, nullptr);
}

void GstWrapper::SetWindowHandle(guintptr winhandle) {
    _gstVars.windowHandle = winhandle;
}

void GstWrapper::SetLocation(std::string location) {
    _gstVars.location = location;
}

void GstWrapper::SetPorts(int port, int port2) {
    _gstVars.rtpPort = port;
    _gstVars.rtcpPort = port2;
    _gstVars.rtcpSinkPort = port2 + 4;
}

void GstWrapper::SetCaps(std::string caps, bool isMjpeg) {
    _gstVars.rtpCaps = "application/x-rtp,media=(string)" + caps;
    _gstVars.isMjpeg = isMjpeg;
}

void GstWrapper::SetCookie(std::string cookie) {
    _gstVars.cookie = cookie;
}

void GstWrapper::SetRtcpHostIP(std::string hostIp) {
    _gstVars.hostIp = hostIp;
}

void GstWrapper::SetMulticastAddress(std::string multicastAddress) {
    _gstVars.multicastAddress = multicastAddress;
}

void GstWrapper::SetTimestamp(unsigned int seekTime) {
    _gstVars.currentTimestamp = seekTime;
    _gstVars.lastTimestamp = NULL;
}

unsigned int GstWrapper::GetLastTimestamp() const {
    // If the protocol is MjpegPull do not convert the timestamp.
    if (_gstVars.protocol == VxSdk::VxStreamProtocol::kMjpegPull) {
        return _gstVars.currentTimestamp;
    }
    // If the current mode is playback do not convert the timestamp.
    if (_gstVars.mode == Controller::kPlayback) {
        return _gstVars.currentTimestamp;
    }

    return static_cast<unsigned int>(_gstVars.rtcpTimestamp / Constants::kMillisecondsInt);
}

void GstWrapper::SetMode(Controller::Mode mode) {
    _gstVars.rtcpTimestamp = 0;
    _gstVars.mode = mode;
}

bool GstWrapper::IsPipelineActive() const {
    return _gstVars.isPipelineActive;
}

void GstWrapper::AddObserver(TimestampEventCallback observer) {
    _gstVars.observerList.push_back(observer);
}

void GstWrapper::RemoveObserver(TimestampEventCallback observer) {
    _gstVars.observerList.erase(remove(_gstVars.observerList.begin(), _gstVars.observerList.end(), observer), _gstVars.observerList.end());
}

void GstWrapper::ClearObservers() {
    _gstVars.observerList.clear();
}

void GstWrapper::AddEventData(void* customData) {
    _gstVars.eventData = customData;
}

void GstWrapper::CreatePipeline() {
    // Create the pipeline.
    _gstVars.pipeline = gst_pipeline_new(nullptr);
    g_assert(_gstVars.pipeline);
    _gstVars.isPipelineActive = true;

    // Create the udpsrc.
    _gstVars.src = gst_element_factory_make(Constants::kUdpSrc, "rtpSrc");
    g_assert(_gstVars.src);
    g_object_set(_gstVars.src, Constants::kPort, _gstVars.rtpPort, NULL);
    if (!_gstVars.multicastAddress.empty())
        g_object_set(_gstVars.src, Constants::kAddress, _gstVars.multicastAddress.c_str(), NULL);

    // Set the caps on udpsrc.
    _gstVars.caps = gst_caps_from_string(_gstVars.rtpCaps.c_str());
    g_object_set(_gstVars.src, Constants::kCaps, _gstVars.caps, NULL);
    gst_caps_unref(_gstVars.caps);

    // Create the udpsrc for RTCP.
    _gstVars.rtcpSrc = gst_element_factory_make(Constants::kUdpSrc, "rtcpSrc");
    g_assert(_gstVars.rtcpSrc);
    g_object_set(_gstVars.rtcpSrc, Constants::kPort, _gstVars.rtcpPort, NULL);

    // Create the udpsink for RTCP.
    _gstVars.rtcpSink = gst_element_factory_make(Constants::kUdpSink, "rtcpSink");
    g_assert(_gstVars.rtcpSink);
    g_object_set(_gstVars.rtcpSink, Constants::kPort, _gstVars.rtcpSinkPort, Constants::kHost, _gstVars.hostIp.c_str(), NULL);
    g_object_set(_gstVars.rtcpSink, Constants::kAsync, FALSE, Constants::kSync, FALSE, NULL);

    // Add the elements to the pipeline.
    gst_bin_add_many(GST_BIN(_gstVars.pipeline), _gstVars.src, _gstVars.rtcpSrc, _gstVars.rtcpSink, NULL);
}

void GstWrapper::LinkBinElements() {
    // Create the bin element.
    _gstVars.bin = gst_element_factory_make(Constants::kRtpBin, "rtpBin");
    g_assert(_gstVars.bin);

    // Add the bin element to the pipeline.
    gst_bin_add(GST_BIN(_gstVars.pipeline), _gstVars.bin);

    // Start linking elements to the bin, beginning with the RTP sinkPad for session 0.
    _gstVars.srcPad = gst_element_get_static_pad(_gstVars.src, Constants::kSrc);
    gst_pad_add_probe(_gstVars.srcPad, GST_PAD_PROBE_TYPE_BUFFER, GstPadProbeCallback(OnRtpPacketReceived), &_gstVars, nullptr);
    _gstVars.sinkPad = gst_element_get_request_pad(_gstVars.bin, "recv_rtp_sink_0");
    _gstVars.linkReturn = gst_pad_link(_gstVars.srcPad, _gstVars.sinkPad);
    g_assert(_gstVars.linkReturn == GST_PAD_LINK_OK);
    gst_object_unref(_gstVars.srcPad);
    gst_object_unref(_gstVars.sinkPad);

    // Link the RTCP sinkPad for session 0.
    _gstVars.srcPad = gst_element_get_static_pad(_gstVars.rtcpSrc, Constants::kSrc);
    gst_pad_add_probe(_gstVars.srcPad, GST_PAD_PROBE_TYPE_BUFFER, GstPadProbeCallback(OnRtcpPacketReceived), &_gstVars, nullptr);
    _gstVars.sinkPad = gst_element_get_request_pad(_gstVars.bin, "recv_rtcp_sink_0");
    _gstVars.linkReturn = gst_pad_link(_gstVars.srcPad, _gstVars.sinkPad);
    g_assert(_gstVars.linkReturn == GST_PAD_LINK_OK);
    gst_object_unref(_gstVars.srcPad);
    gst_object_unref(_gstVars.sinkPad);

    // Link the RTCP srcPad for session 0.
    _gstVars.srcPad = gst_element_get_request_pad(_gstVars.bin, "send_rtcp_src_0");
    _gstVars.sinkPad = gst_element_get_static_pad(_gstVars.rtcpSink, Constants::kSink);
    _gstVars.linkReturn = gst_pad_link(_gstVars.srcPad, _gstVars.sinkPad);
    g_assert(_gstVars.linkReturn == GST_PAD_LINK_OK);
    gst_object_unref(_gstVars.srcPad);
    gst_object_unref(_gstVars.sinkPad);
}

void GstWrapper::CreateVideoRtspPipeline() {
    // Create the pipeline.
    CreatePipeline();

    // Create the depayloader, decoder and video sink.
    _gstVars.videoDepay = gst_element_factory_make(_gstVars.isMjpeg ? Constants::kRtpJpegDepay : Constants::kRtpDepay, "videoDepay");
    g_assert(_gstVars.videoDepay);
    _gstVars.videoDec = gst_element_factory_make(_gstVars.isMjpeg ? Constants::kJpegDec : Constants::kRtpDec, "videoDec");
    g_assert(_gstVars.videoDec);
    _gstVars.videoSink = gst_element_factory_make(Constants::kVideoSink, "videoSink");
    g_assert(_gstVars.videoSink);

    // Add elements to the pipeline and link.
    gst_bin_add_many(GST_BIN(_gstVars.pipeline), _gstVars.videoDepay, _gstVars.videoDec, _gstVars.videoSink, NULL);
    gst_element_link_many(_gstVars.videoDepay, _gstVars.videoDec, _gstVars.videoSink, NULL);

    // Create the bin element and start linking
    LinkBinElements();

    // The RTP pad that connects to the depayloader will be created dynamically.
    // So connect to the pad-added signal and pass the depayloader to link to it.
    g_signal_connect(_gstVars.bin, "pad-added", G_CALLBACK(OnPadAdded), _gstVars.videoDepay);

    // Set the window handle for the video sink.
    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(_gstVars.videoSink), _gstVars.windowHandle);

    _gstVars.protocol = VxSdk::VxStreamProtocol::kRtspRtp;
    g_print("Starting RTP video receiver pipeline.\n");
}

void GstWrapper::CreateAudioRtspPipeline() {
    // Create the pipeline.
    CreatePipeline();

    // Create the depayloader, decoder and audio sink.
    _gstVars.audioDepay = gst_element_factory_make(Constants::kRtpAudioDepay, "audioDepay");
    g_assert(_gstVars.audioDepay);
    _gstVars.audioDec = gst_element_factory_make(Constants::kRtpAudioDec, "audioDec");
    g_assert(_gstVars.audioDec);
    _gstVars.audioSink = gst_element_factory_make(Constants::kAudioSink, "audioSink");
    g_assert(_gstVars.audioSink);

    // Add elements to the pipeline and link.
    gst_bin_add_many(GST_BIN(_gstVars.pipeline), _gstVars.audioDepay, _gstVars.audioDec, _gstVars.audioSink, NULL);
    gst_element_link_many(_gstVars.audioDepay, _gstVars.audioDec, _gstVars.audioSink, NULL);

    // Create the bin element and start linking
    LinkBinElements();

    // The RTP pad that connects to the depayloader will be created dynamically.
    // So connect to the pad-added signal and pass the depayloader to link to it.
    g_signal_connect(_gstVars.bin, "pad-added", G_CALLBACK(OnPadAdded), _gstVars.audioDepay);

    _gstVars.protocol = VxSdk::VxStreamProtocol::kRtspRtp;
    g_print("Starting RTP audio receiver pipeline.\n");
}

void GstWrapper::CreateMjpegPipeline() {
    // Create the pipeline.
    _gstVars.pipeline = gst_pipeline_new(nullptr);
    g_assert(_gstVars.pipeline);
    _gstVars.isPipelineActive = true;
    GstBus *bus = gst_pipeline_get_bus(GST_PIPELINE(_gstVars.pipeline));
    _gstVars.busWatchId = gst_bus_add_watch(bus, GstBusFunc(OnBusMessage), &_gstVars);
    gst_object_unref(bus);

    // Create the souphttpsrc.
    _gstVars.src = gst_element_factory_make(Constants::kHttpSrc, "httpSrc");
    g_assert(_gstVars.src);
    g_object_set(_gstVars.src, Constants::kRetries, 5, NULL);
    g_object_set(_gstVars.src, Constants::kKeepAlive, TRUE, NULL);
    g_object_set(_gstVars.src, Constants::kLocation, _gstVars.location.c_str(), NULL);
    g_object_set(_gstVars.src, Constants::kHttpLogLevel, SOUP_LOGGER_LOG_HEADERS, NULL);
    g_object_set(_gstVars.src, Constants::kSslStrict, FALSE, NULL);
    static const char *cookie[] = { _gstVars.cookie.c_str(), NULL };
    g_object_set(_gstVars.src, Constants::kCookies, cookie, NULL);

    // Create the decoder and video sink.
    _gstVars.videoDec = gst_element_factory_make(Constants::kJpegDec, "videoDec");
    g_assert(_gstVars.videoDec);
    _gstVars.videoSink = gst_element_factory_make(Constants::kVideoSink, "videoSink");
    g_assert(_gstVars.videoSink);

    // Add elements to the pipeline and link.
    gst_bin_add_many(GST_BIN(_gstVars.pipeline), _gstVars.src, _gstVars.videoDec, _gstVars.videoSink, NULL);
    gst_element_link_many(_gstVars.src, _gstVars.videoDec, _gstVars.videoSink, NULL);

    // Add a probe to souphttpsrc.
    GstPad *httpsrcpad = gst_element_get_static_pad(_gstVars.src, Constants::kSrc);
    gst_pad_add_probe(httpsrcpad, GST_PAD_PROBE_TYPE_EVENT_BOTH, GstPadProbeCallback(OnJpegPacketReceived), &_gstVars, nullptr);
    gst_object_unref(httpsrcpad);

    // Set the window handle for the video sink.
    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(_gstVars.videoSink), _gstVars.windowHandle);

    // Start the loop to receive bus messages.
    _gstVars.loop = g_main_loop_new(nullptr, FALSE);
    boost::thread _workerThread(g_main_loop_run, _gstVars.loop);

    _gstVars.protocol = VxSdk::VxStreamProtocol::kMjpegPull;
    g_print("Starting MJPEG receiver pipeline.\n");
}

void GstWrapper::Play(float speed) {
    _gstVars.rtcpTimestamp = 0;
    _gstVars.speed = speed;

    if (_gstVars.pipeline) {
        gst_element_set_state(_gstVars.pipeline, GST_STATE_PLAYING);
    }
}

void GstWrapper::Pause() const {
    gst_element_set_state(_gstVars.pipeline, GST_STATE_PAUSED);
}

void GstWrapper::ClearPipeline() {
    g_print("Stopping receiver pipeline.\n");
    gst_element_set_state(_gstVars.pipeline, GST_STATE_NULL);
    gst_object_unref(_gstVars.pipeline);
    _gstVars.isPipelineActive = false;
    _gstVars.lastTimestamp = NULL;
    if (_gstVars.protocol == VxSdk::VxStreamProtocol::kMjpegPull) {
        g_source_remove(_gstVars.busWatchId);
        g_main_loop_unref(_gstVars.loop);
    }
}
