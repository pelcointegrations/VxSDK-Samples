#include "stdafx.h"
#include "GstWrapper.h"

#include <gst/gst.h>
#include <gst/base/gstbasesrc.h>
#include <gst/rtp/gstrtcpbuffer.h>
#include <gst/rtp/gstrtpbuffer.h>
#include <gst/video/video.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include <Winsock2.h>

using namespace std;
using namespace MediaController;

GstPadProbeReturn OnRtcpPacketReceived(GstPad *localPad, GstPadProbeInfo *info, GstVars *vars) {
    if (GST_PAD_PROBE_INFO_TYPE(info) | GST_PAD_PROBE_TYPE_BUFFER) {
        GstBuffer *buff = gst_pad_probe_info_get_buffer(info);
        GstRTCPBuffer rtcp = { 0 };
        if (gst_rtcp_buffer_map(buff, GST_MAP_READ, &rtcp)) {
            guint64 ntptime;
            GstRTCPPacket packet;
            gboolean more = gst_rtcp_buffer_get_first_packet(&rtcp, &packet);
            while (more) {
                // Check if the packet type is a sender report.
                GstRTCPType type = gst_rtcp_packet_get_type(&packet);
                if (type == GST_RTCP_TYPE_SR) {
                    // Parse the sender info.
                    gst_rtcp_packet_sr_get_sender_info(&packet, NULL, &ntptime, NULL, NULL, NULL);
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
        GstRTPBuffer rtp = { 0 };
        gpointer data;

        if (gst_rtp_buffer_map(buff, GST_MAP_READ, &rtp)) {
            // Parse the buffer based on the current mode.
            if (vars->mode == MediaController::Controller::kPlayback) {
                // Playback packets contain extension data, which gives us the stream time.
                if (gst_rtp_buffer_get_extension_data(&rtp, NULL, &data, NULL)) {
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
                        vars->currentTimestamp += abs(static_cast<int>(streamTs - vars->lastTimestamp)) * vars->speed;
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
        gst_element_set_state(*vars->pipeline, GST_STATE_NULL);
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
        gst_element_set_state(*vars->pipeline, GST_STATE_PLAYING);
        break;
    default:
        break;
    }
}

GstWrapper::GstWrapper() : _gstVars(GstVars()) {
    SetMode(Controller::kStopped);
    _gstVars.pipeline.reset(nullptr);
    Init();
}

GstWrapper::~GstWrapper() {
    Cleanup();
}

bool GstWrapper::IsPipelineActive() {
    return (_gstVars.pipeline != nullptr);
}

void GstWrapper::Init() {
    if (!gst_is_initialized())
        gst_init(nullptr, nullptr);
}

void GstWrapper::SetPipeline() {
    _gstVars.pipeline = std::make_unique<GstElement*>(gst_parse_launch(_pipelineDescription.c_str(), nullptr));
    SetOverlay();
}

void GstWrapper::SetWindowHandle(intptr_t winhandle) {
    _winhandle = winhandle;
}

void GstWrapper::SetOverlay() {
    // Get the video overlay element from the pipeline.
    GstElement *video_sink = gst_bin_get_by_interface(GST_BIN(*_gstVars.pipeline), GST_TYPE_VIDEO_OVERLAY);
    // Set the window handle.
    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(video_sink), _winhandle);
    gst_video_overlay_expose(GST_VIDEO_OVERLAY(video_sink));
    gst_object_unref(video_sink);
}

void GstWrapper::ClearWindow() {
    Cleanup();
    //SetPipeline();
}

void GstWrapper::Play(int speed) {
    _gstVars.rtcpTimestamp = 0;
    _gstVars.speed = speed;

    if (_gstVars.pipeline) {
        gst_element_set_state(*_gstVars.pipeline, GST_STATE_PLAYING);
    }
}

void GstWrapper::Pause() {
    gst_element_set_state(*_gstVars.pipeline, GST_STATE_PAUSED);
}

void GstWrapper::AddObserver(TimestampEventCallback observer) {
    _gstVars.observerList.push_back(observer);
}
void GstWrapper::AddEventData(void* customData) {
    _gstVars.eventData = customData;
}

void GstWrapper::RemoveObserver(TimestampEventCallback observer) {
    _gstVars.observerList.erase(remove(_gstVars.observerList.begin(), _gstVars.observerList.end(), observer), _gstVars.observerList.end());
}

void GstWrapper::ClearObservers() {
    _gstVars.observerList.clear();
}

void GstWrapper::SetMode(Controller::Mode mode) {
    _gstVars.rtcpTimestamp = 0;
    _gstVars.mode = mode;
}

void GstWrapper::SetLocation(char* location, std::string uuid) {
    // Get the Bin pipeline element and set the location property to the new location.
    GstElement *httpsrc = gst_bin_get_by_name(GST_BIN(*_gstVars.pipeline), g_strconcat(Constants::kHttpSrc, uuid.c_str(), NULL));
    g_object_set(httpsrc, "location", location, NULL);
}

void GstWrapper::SubscribeToBusEvents(std::string uuid) {
    _loop = g_main_loop_new(nullptr, FALSE);
    boost::thread _workerThread(g_main_loop_run, _loop);

    // Get the pipeline Bus element and subscribe to its events.
    GstBus *bus = gst_pipeline_get_bus(GST_PIPELINE(*_gstVars.pipeline));
    gst_bus_add_watch(bus, GstBusFunc(OnBusMessage), &_gstVars);

    // Subscribe to the probe events on the pipelines httpsrc Bin element.
    GstElement* httpsrc = gst_bin_get_by_name(GST_BIN(*_gstVars.pipeline), g_strconcat(Constants::kHttpSrc, uuid.c_str(), NULL));
    GstPad *httpsrcpad = gst_element_get_static_pad(httpsrc, Constants::kSrc);
    gst_pad_add_probe(httpsrcpad, GST_PAD_PROBE_TYPE_EVENT_BOTH, GstPadProbeCallback(OnJpegPacketReceived), &_gstVars, nullptr);
    gst_object_unref(httpsrcpad);
}

void GstWrapper::SubscribeToProbeEvents(std::string uuid) {
    // Subscribe to the probe events on the pipelines udpsrc1 Bin element.
    GstElement* udpsrc1 = gst_bin_get_by_name(GST_BIN(*_gstVars.pipeline), g_strconcat("udpsrc1", uuid.c_str(), NULL));
    GstPad *udpsrc1pad = gst_element_get_static_pad(udpsrc1, Constants::kSrc);
    gst_pad_add_probe(udpsrc1pad, GST_PAD_PROBE_TYPE_BUFFER, GstPadProbeCallback(OnRtcpPacketReceived), &_gstVars, nullptr);
    gst_object_unref(udpsrc1pad);

    // Subscribe to the probe events on the pipelines udpsrc0 Bin element.
    GstElement* udpsrc0 = gst_bin_get_by_name(GST_BIN(*_gstVars.pipeline), g_strconcat("udpsrc0", uuid.c_str(), NULL));
    GstPad *udpsrc0pad = gst_element_get_static_pad(udpsrc0, Constants::kSrc);
    gst_pad_add_probe(udpsrc0pad, GST_PAD_PROBE_TYPE_BUFFER, GstPadProbeCallback(OnRtpPacketReceived), &_gstVars, nullptr);
    gst_object_unref(udpsrc0pad);
}

unsigned int GstWrapper::GetLastTimestamp(VxSdk::VxStreamProtocol::Value protocol) {
    // If the protocol is MjpegPull do not convert the timestamp.
    if (protocol == VxSdk::VxStreamProtocol::kMjpegPull) {
        return _gstVars.currentTimestamp;
    }
    // If the current mode is playback do not convert the timestamp.
    if (_gstVars.mode == Controller::kPlayback) {
        return _gstVars.currentTimestamp;
    }

    return static_cast<unsigned int>(_gstVars.rtcpTimestamp / Constants::kMillisecondsInt);
}

void GstWrapper::SetTimestamp(unsigned int seekTime) {
    _gstVars.currentTimestamp = seekTime;
    _gstVars.lastTimestamp = NULL;
}

void GstWrapper::Cleanup() {
    if (_loop != nullptr)
        g_main_loop_quit(_loop);

    gst_element_set_state(*_gstVars.pipeline, GST_STATE_NULL);
    gst_object_unref(GST_OBJECT(*_gstVars.pipeline));
    _gstVars.pipeline.reset(nullptr);
    _gstVars.lastTimestamp = NULL;
}

void GstWrapper::UpdatePipeline(const std::string& pipelineDescription) {
    if (pipelineDescription != _pipelineDescription) {
        _pipelineDescription = pipelineDescription;
    }
}
