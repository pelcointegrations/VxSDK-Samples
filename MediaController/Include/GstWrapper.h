#ifndef GstWrapper_h__
#define GstWrapper_h__

#include "Controller.h"
#include "GstVars.h"
#include <gst/gstelement.h>

namespace MediaController {

    /// <summary>
    /// Manages the GStreamer instance.
    /// </summary>
    class GstWrapper {
    public:

        /// <summary>
        /// Destructor.
        /// </summary>
        ~GstWrapper();

        /// <summary>
        /// Set the display window using the given window handle.
        /// </summary>
        /// <param name="winhandle">The window handle of the display.</param>
        void SetWindowHandle(intptr_t winhandle);

        /// <summary>
        /// Clear the display window.
        /// </summary>
        void ClearWindow();

        /// <summary>
        /// Set the pipeline state to playing and update the speed value for determining the framerate.
        /// </summary>
        void Play(int speed);

        /// <summary>
        /// Set the pipeline state to paused.
        /// </summary>
        void Pause();

        /// <summary>
        /// Add a new subscriber to timestamp events.
        /// </summary>
        /// <param name="observer">The <see cref="TimestampEventCallback"/> event handler.</param>
        void AddObserver(TimestampEventCallback observer);

        /// <summary>
        /// Remove an existing timestamp event subscriber.
        /// </summary>
        /// <param name="observer">The <see cref="TimestampEventCallback"/> event handler.</param>
        void RemoveObserver(TimestampEventCallback observer);

        /// <summary>
        /// Remove all existing timestamp event subscribers.
        /// </summary>
        void ClearObservers();

        /// <summary>
        /// Get the current playback mode.
        /// </summary>
        /// <returns>The current stream <see cref="Controller::Mode"/>.</returns>
        Controller::Mode GetMode() const { return _gstVars.mode; }

        /// <summary>
        /// Set the current playback mode.
        /// </summary>
        /// <param name="mode">The stream <see cref="Controller::Mode"/> to set.</param>
        void SetMode(Controller::Mode mode);

        /// <summary>
        /// Set the description for the current pipeline.
        /// </summary>
        /// <param name="pipelineDescription">The description to set the pipeline to.</param>
        /// <returns>The builder instance with the newly set pipeline.</returns>
        void SetPipeline();

        /// <summary>
        /// Add custom data to be stored in here, which will be send back to caller inside <see cref="TimestampEvent"/> on <see cref="TimestampEventCallback"/>.
        /// </summary>
        /// <param name="customData">Custom data pointer.</param>
        void AddEventData(void* customData);

        /// <summary>
        /// Get the last timestamp received from the stream.
        /// </summary>
        /// <param name="protocol">The current stream protocol.</param>
        /// <returns>The unix timestamp.</returns>
        unsigned int GetLastTimestamp(VxSdk::VxStreamProtocol::Value protocol);

        /// <summary>
        /// Set the internal timestamp variable.
        /// </summary>
        /// <param name="seekTime">A unix timestamp.</param>
        void SetTimestamp(unsigned int seekTime);

        /// <summary>
        /// Update the pipeline description.
        /// </summary>
        /// <param name="pipelineDescription">The new pipeline description.</param>
        void UpdatePipeline(const std::string& pipelineDescription);

        /// <summary>
        /// Get the status of the pipeline.
        /// </summary>
        /// <returns>True if pipeline is active, otherwise false.</returns>
        bool IsPipelineActive();

        /// <summary>
        /// Set the stream location.
        /// </summary>
        /// <param name="location">The URI of the new stream location.</param>
        void SetLocation(char* location, std::string uuid);

        /// <summary>
        /// Subscribe to the the events sent from the GStreamer Bus element.
        /// </summary>
        /// <param name="uuid">The UUID used in the current pipeline description.</param>
        void SubscribeToBusEvents(std::string uuid);

        /// <summary>
        /// Subscribe to the the probe events sent from the GStreamer Src element.
        /// </summary>
        /// <param name="uuid">The UUID used in the current pipeline description.</param>
        void SubscribeToProbeEvents(std::string uuid);

        GstWrapper();
        void SetOverlay();
    private:
        void Init();
        void Cleanup();
        std::string _pipelineDescription;
        intptr_t _winhandle;
        GstVars _gstVars;
        GMainLoop *_loop;
    };
}
#endif // GstWrapper_h__
