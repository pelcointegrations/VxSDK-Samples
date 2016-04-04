#ifndef RtspKeepAlive_h__
#define RtspKeepAlive_h__

#include "RtspCommands.h"
#include <thread>
#include <atomic>

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
            KeepAlive(Commands& commands)
                : _shutdownRequested(false),
                _commands(commands),
                _keepAliveThread(std::thread(&KeepAlive::GetParamsLoop, this)){
            }

            /// <summary>
            /// Destructor.
            /// </summary>
            ~KeepAlive() {
                _shutdownRequested = true;
                this->_keepAliveThread.join();
            }

            /// <summary>
            /// Make a GET_PARAMETERS method call to the associated stream.
            /// </summary>
            void GetParamsLoop() {
                int _count = 0;
                while (!_shutdownRequested) {
                    if (_count < Constants::kKeepAliveRefreshSec) {
                        ++_count;
                    }
                    else {
                        _commands.GetParameter();
                        _count = 0;
                    }
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
            }

        private:
            Commands _commands;
            std::thread _keepAliveThread;
            std::atomic<bool> _shutdownRequested;
        };
    }
}
#endif // RtspKeepAlive_h__
