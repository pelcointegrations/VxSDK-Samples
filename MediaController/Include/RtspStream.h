#ifndef RtspStream_h__
#define RtspStream_h__

#include "StreamBase.h"
#include "RtspCommands.h"

namespace MediaController {

    /// <summary>
    /// Contains classes that manage RTSP streams.
    /// </summary>
    namespace Rtsp {

        /// <summary>
        /// Represents an RTSP stream.
        /// </summary>
        class Stream : public StreamBase {
        public:

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="request">The requested media.</param>
            /// <param name="controller">A media controller object.</param>
            /// <param name="liveUri">The location of the live RTSP stream.</param>
            Stream(MediaRequest& request, MediaController::Controller& controller, const std::string& liveUri);

            /// <summary>
            /// Virtual destructor.
            /// </summary>
            virtual ~Stream();
            virtual void Play(int speed) override;
            virtual void Pause() override;
            virtual void Stop() override;
            virtual void FrameForward() override;
            virtual void FrameBackward() override;
            virtual void Seek(unsigned int unixTime, int speed) override;
            virtual void GoToLive() override;
            virtual void NewRequest(MediaRequest& request) override;
            virtual void Resume(int speed) override;

        private:
            Commands _rtspCommands;
            bool _keepAliveRunning;
        };
    }
}
#endif // RtspStream_h__
