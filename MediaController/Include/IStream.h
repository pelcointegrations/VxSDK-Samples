#ifndef IStream_h__
#define IStream_h__

#include "MediaRequest.h"

namespace MediaController {

    /// <summary>
    /// Defines the stream interface.
    /// </summary>
    class IStream {
    public:
        /// <summary>
        /// Values that represent the different playback modes.
        /// </summary>
        enum Mode {
            /// <summary>The stream is stopped.</summary>
            kStopped,

            /// <summary>The stream is playing live video.</summary>
            kLive,

            /// <summary>The stream is playing recorded video.</summary>
            kPlayback
        };

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~IStream() {}

        /// <summary>
        /// Call Play on the stream.
        /// </summary>
        /// <param name="speed">The playback speed.  Negative values can be used for reverse
        /// playback. A value of 0 will resume a paused stream.</param>
        /// <param name="unixTime">The start time for playback. A value of 0 will start a live stream.</param>
        virtual bool Play(float speed = 0, unsigned int unixTime = 0) = 0;
        
        virtual void PlayStream(float speed, unsigned int unixTime) = 0;

        /// <summary>
        /// Call Pause on the stream.
        /// </summary>
        virtual void Pause() = 0;

        /// <summary>
        /// Call TearDown on the stream.
        /// </summary>
        virtual void Stop() = 0;

        /// <summary>
        /// Set the stream to Live and call Play.
        /// </summary>
        virtual bool GoToLive() = 0;

        /// <summary>
        /// Set the stream to a new source.
        /// </summary>
        /// <param name="request">The new <see cref="MediaRequest"/> to reset the stream to.</param>
        virtual void NewRequest(MediaRequest& request) = 0;

        /// <summary>
        /// Get the current playback mode.
        /// </summary>
        /// <returns>The current stream <see cref="Mode"/>.</returns>
        virtual Mode GetMode() = 0;
    };
}
#endif // IStream_h__
