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
            bool Options();

            /// <summary>
            /// Send the GET_PARAMETER method and read the server response.
            /// </summary>
            bool GetParameter();

            /// <summary>
            /// Send the DESCRIBE method and read the server response.
            /// </summary>
            bool Describe();

            /// <summary>
            /// Send the SETUP method and read the server response.
            /// </summary>
            bool Setup();

            /// <summary>
            /// Send the PLAY method and read the server response.
            /// </summary>
            /// <param name="speed">The playback speed.  Negative values can be used for reverse playback.</param>
            bool Play(int speed);

            /// <summary>
            /// Send the PAUSE method and read the server response.
            /// </summary>
            void Pause();

            /// <summary>
            /// Send the PLAY method with a Range header and read the server response.
            /// </summary>
            /// <param name="unixTime">The start time for playback.</param>
            /// <param name="speed">The playback speed.  Negative values can be used for reverse playback.</param>
            bool SeekPlay(unsigned int unixTime, int speed);

            /// <summary>
            /// Send the TEARDOWN method and read the server response.
            /// </summary>
            void Teardown();

            /// <summary>
            /// Reset the live RTSP stream location.
            /// </summary>
            /// <param name="liveUri">The location of the live RTSP stream.</param>
            void ResetPath(const std::string& liveUri);

            /// <summary>
            /// Get the current session ID.
            /// </summary>
            /// <returns>The session ID.</returns>
            std::string GetSessionId() const { return _sessionId; }

            /// <summary>
            /// Get the URI to the live stream.
            /// </summary>
            /// <returns>The URI.</returns>
            std::string GetLiveUri() const { return _liveUri; }

            /// <summary>
            /// Get the URI to the playback stream.
            /// </summary>
            /// <returns>The URI.</returns>
            std::string GetPlaybackUri() const { return _playbackUri; }

        private:
            std::string _sessionId;
            std::string _liveUri;
            std::string _playbackUri;
            std::string _uuid;
            MediaController::Controller* _controller;
            SdpParser _liveSdp;
            SdpParser _playbackSdp;
            int _port;
        };
    }
}
#endif // RtspCommands_h__
