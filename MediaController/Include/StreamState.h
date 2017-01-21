#ifndef StreamState_h__
#define StreamState_h__

#include "Controller.h"

namespace MediaController {

    /// <summary>
    /// Provides an interface for managing calls to the stream based on its current state.
    /// </summary>
    class StreamState {
    public:

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~StreamState() {}

        /// <summary>
        /// Perform the Play action based on the stream state.
        /// </summary>
        /// <param name="stream">The stream instance.</param>
        /// <param name="speed">The playback speed.</param>
        /// <param name="unixTime">The start time for playback.</param>
        virtual bool Play(StreamBase& stream, float speed, unsigned int unixTime) { return false; }

        /// <summary>
        /// Perform the Pause action based on the stream state.
        /// </summary>
        /// <param name="stream">The stream instance.</param>
        virtual void Pause(StreamBase& stream) {}

        /// <summary>
        /// Perform the Stop action based on the stream state.
        /// </summary>
        /// <param name="stream">The stream instance.</param>
        virtual void Stop(StreamBase& stream) {}

        /// <summary>
        /// Perform the GoToLive action based on the stream state.
        /// </summary>
        /// <param name="stream">The stream instance.</param>
        virtual bool GoToLive(StreamBase& stream) { return false; }

    protected:
        /// <summary>
        /// Constructor.
        /// </summary>
        StreamState() {}
    };

    /// <summary>
    /// Represents a stream that is currently in the playing state.
    /// </summary>
    class PlayingState : public StreamState {
    public:

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~PlayingState() {}
        bool Play(StreamBase& stream, float speed, unsigned int unixTime) override;
        void Pause(StreamBase& stream) override;
        void Stop(StreamBase& stream) override;
        bool GoToLive(StreamBase& stream) override;
    };

    /// <summary>
    /// Represents a stream that is currently in the paused state.
    /// </summary>
    class PausedState : public StreamState {
    public:

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~PausedState() {}
        bool Play(StreamBase& stream, float speed, unsigned int unixTime) override;
        void Stop(StreamBase& stream) override;
        bool GoToLive(StreamBase& stream) override;
    };

    /// <summary>
    /// Represents a stream that is currently in the stopped state.
    /// </summary>
    class StoppedState : public StreamState {
    public:

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~StoppedState() {}
        bool Play(StreamBase& stream, float speed, unsigned int unixTime) override;
        bool GoToLive(StreamBase& stream) override;
    };
}
#endif // StreamState_h__
