#ifndef StreamBase_h__
#define StreamBase_h__

#include "IStream.h"
#include "MediaRequest.h"

namespace MediaController {
    class GstWrapper;
    class Controller;

    /// <summary>
    /// The base class for the different stream types.
    /// </summary>
    class StreamBase : public IStream {
    public:

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~StreamBase();
        virtual void Play(int speed) override;
        virtual void Pause() override;
        virtual void Stop() override;
        virtual void FrameForward() override;
        virtual void FrameBackward() override;
        virtual void Seek(unsigned int unixTime, int speed) override;
        virtual void NewRequest(MediaRequest& request) override;

        /// <summary>
        /// Call Seek on the stream using the last timestamp received as the start time.
        /// </summary>
        /// <param name="speed">The playback speed.  Negative values can be used for reverse playback.</param>
        virtual void Resume(int speed);

        /// <summary>
        /// Get the current GStreamer wrapper instance.
        /// </summary>
        /// <returns>The current <see cref="GstWrapper"/> instance.</returns>
        GstWrapper* GetGstreamer();

    protected:
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="request">The requested media.</param>
        /// <param name="controller">A media controller object.</param>
        StreamBase(MediaRequest& request, Controller& controller);

    private:
        /// <summary>
        /// Default constructor.
        /// </summary>
        StreamBase();

    protected:
        MediaRequest _mediaRequest;
        Controller* _controller;
        GstWrapper* _gst;
    };
}
#endif // StreamBase_h__
