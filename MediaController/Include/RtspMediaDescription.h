#ifndef RtspMediaDescription_h__
#define RtspMediaDescription_h__

namespace MediaController {
    namespace Rtsp {

        /// <summary>
        /// The parsed media information from an SDP packet.
        /// </summary>
        struct MediaDescription {

            /// <summary>
            /// Default constructor.
            /// </summary>
            MediaDescription() {
                this->type.clear();
                this->protocol.clear();
                this->ip.clear();
                this->encoding.clear();
                this->port = 0;
                this->payload = 0;
                this->ttl = 0;
                this->rate = 0;
                this->isMulticast = false;
            }

            /// <summary>
            /// The type of media.
            /// </summary>
            std::string type;

            /// <summary>
            /// The transport port for media.
            /// </summary>
            unsigned short port;

            /// <summary>
            /// The transport protocol.
            /// </summary>
            std::string protocol;

            /// <summary>
            /// RTP payload type number.
            /// </summary>
            unsigned short payload;

            /// <summary>
            /// The address for media.
            /// </summary>
            std::string ip;

            /// <summary>
            /// The time to live (TTL) value.
            /// </summary>
            unsigned short ttl;

            /// <summary>
            /// The encoding name denoting the payload format to be used.
            /// </summary>
            std::string encoding;

            /// <summary>
            /// The stream clock rate.
            /// </summary>
            unsigned int rate;

            /// <summary>
            /// Specifies whether the transport type is multicast or unicast.
            /// </summary>
            bool isMulticast;
        };
    }
}
#endif // RtspMediaDescription_h__
