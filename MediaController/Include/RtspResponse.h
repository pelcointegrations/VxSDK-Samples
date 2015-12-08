#ifndef RtspResponse_h__
#define RtspResponse_h__

namespace MediaController {
    namespace Rtsp {

        /// <summary>
        /// The parsed information from an RTSP response.
        /// </summary>
        struct Response {

            /// <summary>
            /// The reponse status code.
            /// </summary>
            unsigned int statusCode;

            /// <summary>
            /// The session identifier.
            /// </summary>
            std::string session;

            /// <summary>
            /// A list of response headers.
            /// </summary>
            std::map<std::string, std::string> headers;

            /// <summary>
            /// The body of the response.
            /// </summary>
            std::string content;
        };
    }
}
#endif // RtspResponse_h__
