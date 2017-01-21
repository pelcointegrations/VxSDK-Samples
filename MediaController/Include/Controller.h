#ifndef Controller_h__
#define Controller_h__

#include "IController.h"

namespace MediaController {
    class StreamState;
    struct MediaRequest;
    class StreamBase;

    /// <summary>
    /// Implements the IController interface methods.
    /// </summary>
    class Controller : public IController {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="request">The requested media.</param>
        Controller(MediaRequest& request);

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~Controller();
        void SetWindow(void* handle) override;
        bool GoToLive() override;
        bool Play(float speed, unsigned int unixTime) override;
        void PlayStream(float speed, unsigned int unixTime) override;
        void Pause() override;
        void Stop() override;
        void NewRequest(MediaRequest& request) override;
        void AddObserver(TimestampEventCallback observer) override;
        void RemoveObserver(TimestampEventCallback observer) override;
        void ClearObservers() override;
        Mode GetMode() override;
        bool IsPipelineActive() override;
        void AddEventData(void* customData) override;

        /// <summary>
        /// The current video stream instance.
        /// </summary>
        StreamBase* stream;

        /// <summary>
        /// The current audio stream instance.
        /// </summary>
        StreamBase* audioStream;

    private:
        static void CallSetupStream(StreamBase* stream, float speed, unsigned int unixTime, bool* result);
        static void CallPlayStream(StreamBase* stream, float speed, unsigned int unixTime);
    };
}
#endif // Controller_h__
