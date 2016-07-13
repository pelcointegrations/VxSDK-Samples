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
        virtual void SetWindow(void* handle) override;
        virtual bool GoToLive() override;
        virtual bool Play(float speed) override;
        virtual void Pause() override;
        virtual void Stop() override;
        virtual void FrameForward() override;
        virtual void FrameBackward() override;
        virtual bool Seek(unsigned int unixTime, float speed) override;
        virtual void NewRequest(MediaRequest& request) override;
        virtual void AddObserver(TimestampEventCallback observer) override;
        virtual void RemoveObserver(TimestampEventCallback observer) override;
        virtual void ClearObservers() override;
        virtual Mode GetMode() override;
        virtual bool IsPipelineActive() override;
        virtual void AddEventData(void* customData) override;

        /// <summary>
        /// The current state of the stream.
        /// </summary>
        StreamState* state;

        /// <summary>
        /// The current stream instance.
        /// </summary>
        StreamBase* stream;
    };
}
#endif // Controller_h__
