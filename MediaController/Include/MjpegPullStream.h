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
            Stream(MediaRequest& request);

            /// <summary>
            /// Virtual destructor.
            /// </summary>
            virtual ~Stream();
            bool Play(float speed, unsigned int unixTime) override;
            void PlayStream(float speed, unsigned int unixTime) override;
            void Pause() override;
            void Stop() override;
            bool Resume(float speed, unsigned int unixTime) override;
            bool GoToLive() override;
            void NewRequest(MediaRequest& request) override;

        private:
            VxSdk::IVxDataSession* _dataSession;
        };
    }
}
#endif // MjpegPullStream_h__
