#ifndef MjpegPullStream_h__
#define MjpegPullStream_h__

#include "StreamBase.h"

namespace MediaController {

    /// <summary>
    /// Contains classes that manage MJPEG pull streams.
    /// </summary>
    namespace MjpegPull {

        /// <summary>
        /// Represents an MJPEG pull stream.
        /// </summary>
        class Stream : public StreamBase {
        public:

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="request">The requested media.</param>
            /// <param name="controller">A media controller object.</param>
            Stream(MediaRequest& request, Controller& controller);

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
            virtual void Resume(int speed) override;
            virtual void NewRequest(MediaRequest& request) override;

        private:
            VxSdk::IVxDataSession* _dataSession;
            std::string _uuid;
        };
    }
}
#endif // MjpegPullStream_h__
