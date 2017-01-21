#ifndef RtspSdpParser_h__
#define RtspSdpParser_h__

#include "RtspMediaDescription.h"

namespace MediaController {
    namespace Rtsp {

        /// <summary>
        /// Parses the SDP packets sent from an RTSP source.
        /// </summary>
        class SdpParser {
        public:

            /// <summary>
            /// Default constructor.
            /// </summary>
            SdpParser();

            /// <summary>
            /// Default destructor.
            /// </summary>
            ~SdpParser();

            /// <summary>
            /// Get all available media descriptions.
            /// </summary>
            /// <returns>A list of <see cref="MediaDescription"/> objects.</returns>
            const std::vector<MediaDescription>& GetMediaDescriptions() const;

            /// <summary>
            /// Get the first available video media description.
            /// </summary>
            /// <returns>An empty <see cref="MediaDescription"/> if no description is found, otherwise the first
            /// video <see cref="MediaDescription"/>.</returns>
            const MediaDescription& GetFirstVideo();

            /// <summary>
            /// Get the first available audio media description.
            /// </summary>
            /// <returns>An empty <see cref="MediaDescription"/> if no description is found, otherwise the first
            /// audio <see cref="MediaDescription"/>.</returns>
            const MediaDescription& GetFirstAudio();

            /// <summary>
            /// Parses a raw SDP packet string.
            /// </summary>
            /// <param name="sdp">The SDP packet as a string.</param>
            void Parse(const std::string& sdp);

            /// <summary>
            /// The session control URI.
            /// </summary>
            std::string sessionControlUri;

        private:
            std::vector<MediaDescription> _mediaDescriptions;
        };
    }
}
#endif // RtspSdpParser_h__
