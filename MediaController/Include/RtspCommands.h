#ifndef RtspCommands_h__
#define RtspCommands_h__

#include "RtspSdpParser.h"
#include "GstWrapper.h"
#include <boost/asio/ip/tcp.hpp>

namespace MediaController {
    namespace Rtsp {
        /// <summary>
        /// Establishes and controls an RTSP stream.
        /// </summary>
        class Commands {
        public:

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="streamUri">The location of the RTSP stream.</param>
            /// <param name="isVideo">Specifies wheather this command handles audio or video.</param>
            Commands(const std::string& streamUri, bool isVideo);

            /// <summary>
            /// Destructor.
            /// </summary>
            ~Commands() {
                ClearSocket();
            }

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
            bool Describe(bool firstAttempt = false);

            /// <summary>
            /// Send the SETUP method and read the server response.
            /// </summary>
            bool Setup(bool firstAttempt = false);

            /// <summary>
            /// Send the PAUSE method and read the server response.
            /// </summary>
            void Pause();

            /// <summary>
            /// Send the PLAY method with a Range header and read the server response.
            /// </summary>
            /// <param name="speed">The playback speed.  Negative values can be used for reverse
            /// playback. A value of 0 will resume a paused stream.</param>
            /// <param name="unixTime">The start time for playback. A value of 0 will start a live stream.</param>
            bool SetupStream(GstWrapper* gstwrapper, float speed = 0, unsigned int unixTime = 0);

            /// <summary>
            /// Create a pipe line
            /// </summary>
            void PlayStream(GstWrapper* gstwrapper);

            /// <summary>
            /// Send the TEARDOWN method and read the server response.
            /// </summary>
            void Teardown();

            /// <summary>
            /// Reset the RTSP stream location.
            /// </summary>
            /// <param name="streamUri">The location of the RTSP stream.</param>
            void ResetPath(const std::string& streamUri);

            /// <summary>
            /// Get the current session ID for the video stream.
            /// </summary>
            /// <returns>The session ID.</returns>
            std::string GetSessionId() const { return _sessionId; }

        private:
            void GetSocket(const std::string& uriString, int bindPort);
            void ClearSocket();
            std::string _sessionId;
            std::string _baseUri;
            std::string _controlUri;
            std::string _uuid;
            SdpParser _sdp;
            int _dataPort;
            int _rtcpPort;
            int _cSeqNum;
            boost::asio::io_service _ioService;
            boost::asio::ip::tcp::socket _pSocket;
            boost::asio::ip::tcp::socket _rSocket;
            bool _isVideo;
        };
    }
}
#endif // RtspCommands_h__
