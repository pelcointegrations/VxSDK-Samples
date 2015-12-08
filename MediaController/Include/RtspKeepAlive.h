#ifndef RtspKeepAlive_h__
#define RtspKeepAlive_h__

#include "RtspCommands.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>

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
            /// <param name="io">A <c>boost::asio::io_service</c> object.</param>
            /// <param name="commands">The <see cref="Commands"/> instance for the associated stream.</param>
            KeepAlive(boost::asio::io_service& io, Commands& commands)
                : shutdownRequested(false),
                _commands(commands),
                _strand(io),
                _timer(io, boost::posix_time::seconds(1)),
                _count(0) {
                _timer.async_wait(_strand.wrap(boost::bind(&KeepAlive::CallGetParams, this)));
            }

            /// <summary>
            /// Destructor.
            /// </summary>
            ~KeepAlive() { }

            /// <summary>
            /// Make a GET_PARAMETERS method call to the associated stream.
            /// </summary>
            void CallGetParams() {
                if (!shutdownRequested) {
                    if (_count < Constants::kKeepAliveRefreshSec) {
                        ++_count;
                    }
                    else {
                        _commands.GetParameter();
                        _count = 0;
                    }
                    _timer.expires_at(_timer.expires_at() + boost::posix_time::seconds(1));
                    _timer.async_wait(_strand.wrap(boost::bind(&KeepAlive::CallGetParams, this)));
                }
            }

            /// <summary>
            /// Specifies whether the keep alive thread should shutdown.
            /// </summary>
            bool shutdownRequested;

        private:
            Commands _commands;
            boost::asio::strand _strand;
            boost::asio::deadline_timer _timer;
            int _count;
        };
    }
}
#endif // RtspKeepAlive_h__
