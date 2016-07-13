#ifndef GstVars_h__
#define GstVars_h__

#include "Controller.h"
#include <gst\gstelement.h>

namespace MediaController {

    /// <summary>
    /// Variables required for GStreamer.
    /// </summary>
    struct GstVars {

        /// <summary>
        /// The GStreamer pipeline.
        /// </summary>
        std::unique_ptr<GstElement*> pipeline;

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
    };
}
#endif // GstVars_h__
