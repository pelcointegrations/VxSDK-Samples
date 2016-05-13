#ifndef RtspKeepAlive_h__
#define RtspKeepAlive_h__

#include "RtspCommands.h"

namespace MediaController {
    namespace Rtsp {

        /// <summary>
        /// Manages the keep alive requests for a stream instance.
        /// </summary>
        class KeepAlive {
        public:

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="commands">The <see cref="Commands"/> instance for the associated stream.</param>
            KeepAlive(Commands& commands);

            /// <summary>
            /// Destructor.
            /// </summary>
            ~KeepAlive();

            /// <summary>
            /// Make a GET_PARAMETERS method call to the associated stream.
            /// </summary>
            void GetParamsLoop();

        private:
            Commands _commands;
            struct ThreadInfo;
            std::unique_ptr<ThreadInfo> d_ptr;
        };
    }
}
#endif // RtspKeepAlive_h__
