#ifndef RtspCommands_h__
#define RtspCommands_h__

#include "RtspSdpParser.h"
#include "Controller.h"

namespace MediaController {
    namespace Rtsp {
        class Controller;
        struct RtspSetupRequest;

        /// <summary>
        /// Establishes and controls an RTSP stream.
        /// </summary>
        class Commands {
        public:

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="controller">A media controller object.</param>
            /// <param name="liveUri">The location of the live RTSP stream.</param>
            Commands(MediaController::Controller* controller, const std::string& liveUri);

            /// <summary>
            /// Send the OPTIONS method and read the server response.
            /// </summary>
            void Options();

            /// <summary>
            /// Send the GET_PARAMETER method and read the server response.
            /// </summary>
            void GetParameter();

            /// <summary>
            /// Send the DESCRIBE method and read the server response.
            /// </summary>
            void Describe();

            /// <summary>
            /// Send the SETUP method and read the server response.
            /// </summary>
            void Setup();

            /// <summary>
            /// Send the PLAY method and read the server response.
            /// </summary>
            /// <param name="speed">The playback speed.  Negative values can be used for reverse playback.</param>
            void Play(int speed);

            /// <summary>
            /// Send the PAUSE method and read the server response.
            /// </summary>
            void Pause();

            /// <summary>
            /// Send the PLAY method with a Range header and read the server response.
            /// </summary>
            /// <param name="unixTime">The start time for playback.</param>
            /// <param name="speed">The playback speed.  Negative values can be used for reverse playback.</param>
            void SeekPlay(unsigned int unixTime, int speed);

            /// <summary>
            /// Send the TEARDOWN method and read the server response.
            /// </summary>
            void Teardown();

            /// <summary>
            /// Reset the live RTSP stream location.
            /// </summary>
            /// <param name="liveUri">The location of the live RTSP stream.</param>
            void ResetPath(const std::string& liveUri);

        private:
            MediaController::Controller* _controller;
            std::string _session;
            std::string _liveUri;
            std::string _playbackUri;
            SdpParser _liveSdp;
            SdpParser _playbackSdp;
            int _port;
        };
    }
}
#endif // RtspCommands_h__
