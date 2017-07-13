#ifndef GstVars_h__
#define GstVars_h__

#include "Controller.h"
#include <gst/gstelement.h>

namespace MediaController {

    /// <summary>
    /// Variables required for GStreamer.
    /// </summary>
    struct GstVars {
        GstElement *pipeline;
        GstElement *bin;
        GstElement *src;
        GstElement *rtcpSrc;
        GstElement *rtcpSink;
        GstElement *videoDepay;
        GstElement *videoDec;
        GstElement *videoSink;
        GstElement *audioDepay;
        GstElement *audioDec;
        GstElement *audioSink;
        GstCaps *caps;
        GstPadLinkReturn linkReturn;
        GstPad *srcPad;
        GstPad *sinkPad;

        /// <summary>
        /// The list of timestamp event observers.
        /// </summary>
        std::vector<TimestampEventCallback> observerList;

        /// <summary>
        /// The current timestamp of the stream.
        /// </summary>
        unsigned long currentTimestamp;

        /// <summary>
        /// The last timestamp received from the stream.
        /// </summary>
        uint32_t  lastTimestamp;

        /// <summary>
        /// The latest timestamp received from an RTCP packet.
        /// </summary>
        uint64_t  rtcpTimestamp;

        /// <summary>
        /// The current <see cref="Controller::Mode"/> of the stream.
        /// </summary>
        Controller::Mode mode;

        /// <summary>
        /// The current speed of the stream.
        /// </summary>
        float speed;

        /// <summary>
        /// Store the custom data from caller and send back on event callback.
        /// </summary>
        void* eventData;

        bool isPipelineActive;
        bool isMjpeg;
        std::string rtpCaps;
        std::string cookie;
        std::string hostIp;
        std::string multicastAddress;
        std::string location;
        gint rtpPort;
        gint rtcpPort;
        gint rtcpSinkPort;
        guintptr windowHandle;
        guint busWatchId;
        GMainLoop *loop;
        VxSdk::VxStreamProtocol::Value protocol;
    };
}
#endif // GstVars_h__
