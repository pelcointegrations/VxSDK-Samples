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
        /// Virtual destructor.
        /// </summary>
        virtual ~IStream() {}

        /// <summary>
        /// Call Play on the stream.
        /// </summary>
        /// <param name="speed">The playback speed.  Negative values can be used for reverse playback.</param>
        virtual bool Play(int speed) = 0;

        /// <summary>
        /// Call Pause on the stream.
        /// </summary>
        virtual void Pause() = 0;

        /// <summary>
        /// Call TearDown on the stream.
        /// </summary>
        virtual void Stop() = 0;

        /// <summary>
        /// Not implemented.
        /// </summary>
        virtual void FrameForward() = 0;

        /// <summary>
        /// Not implemented.
        /// </summary>
        virtual void FrameBackward() = 0;

        /// <summary>
        /// Call Play on the stream with the supplied start time, resulting in a playback stream.
        /// </summary>
        /// <param name="unixTime">The start time for playback.</param>
        /// <param name="speed">The playback speed.  Negative values can be used for reverse playback.</param>
        virtual bool Seek(unsigned int unixTime, int speed) = 0;

        /// <summary>
        /// Set the stream to Live and call Play.
        /// </summary>
        virtual bool GoToLive() = 0;

        /// <summary>
        /// Set the stream to a new source.
        /// </summary>
        /// <param name="request">The new <see cref="MediaRequest"/> to reset the stream to.</param>
        virtual void NewRequest(MediaRequest& request) = 0;
    };
}
#endif // IStream_h__
