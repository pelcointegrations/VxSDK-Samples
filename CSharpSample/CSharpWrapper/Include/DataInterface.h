// Declares the data interface class.
#ifndef DataInterface_h__
#define DataInterface_h__

#include "VxSdk.h"

namespace CPPCli {

    /// <summary>
    /// The DataInterface class represents an interface to a data source.
    /// </summary>
    public ref class DataInterface {
    public:

        /// <summary>
        /// Values that represent stream protocols.
        /// </summary>
        enum class RenderTypes {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>Evo renderer.</summary>
            Evo,

            /// <summary>Optera 180 renderer.</summary>
            Optera180,

            /// <summary>Optera 270 renderer.</summary>
            Optera270,

            /// <summary>Optera 360 renderer.</summary>
            Optera360,

            /// <summary>Standard renderer.</summary>
            Standard
        };

        /// <summary>
        /// Values that represent stream protocols.
        /// </summary>
        enum class StreamFormats {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>H.264 encoding format.</summary>
            H264,

            /// <summary>H.265 encoding format.</summary>
            H265,

            /// <summary>MPEG-4 encoding format.</summary>
            Mpeg4,

            /// <summary>JPEG encoding format.</summary>
            Jpeg,

            /// <summary>G.711 encoding format.</summary>
            G711
        };

        /// <summary>
        /// Values that represent stream protocols.
        /// </summary>
        enum class StreamProtocols {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>The Mjpeg (pull) protocol.</summary>
            MjpegPull,

            /// <summary>The RTSP/RTP protocol.</summary>
            RtspRtp
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxDataInterface">The vx data interface.</param>
        DataInterface(VxSdk::IVxDataInterface* vxDataInterface);

        /// <summary>
        /// Gets the average bitrate of the stream, if available (in kbps).
        /// </summary>
        /// <value>The average bitrate of the stream.</value>
        property int Bitrate {
        public:
            int get() { return _dataInterface->bitrate; }
        }

        /// <summary>
        /// Gets the unique identifier for a specific data encoding (based on encoding quality, framerate, and resolution). Multiple identical
        /// copies of the data may exist across the system; these will have the same dataEncodingId. This ID may be used when requesting a specific
        /// encoding to export, record, playback, etc.
        /// </summary>
        /// <value>The data encoding unique identifier.</value>
        property System::String^ DataEncodingId {
        public:
            System::String^ get() { return gcnew System::String(_dataInterface->dataEncodingId); }
        }

        /// <summary>
        /// Gets the endpoint of the data interface.
        /// </summary>
        /// <value>The data interface endpoint.</value>
        property System::String^ DataEndpoint {
        public:
            System::String^ get() { return gcnew System::String(_dataInterface->dataEndpoint); }
        }

        /// <summary>
        /// Gets the media stream encoding format.
        /// </summary>
        /// <value>The encoding format.</value>
        property StreamFormats Format {
        public:
            StreamFormats get() { return StreamFormats(_dataInterface->format); }
        }

        /// <summary>
        /// Gets the framerate of the data.
        /// </summary>
        /// <value>The framerate.</value>
        property float Framerate {
        public:
            float get() { return _dataInterface->framerate; }
        }

        /// <summary>
        /// Gets the multicast test IP used to test transmission capabilities.
        /// </summary>
        /// <value>The multicast test IP.</value>
        property System::String^ MulticastTestIp {
        public:
            System::String^ get() { return gcnew System::String(_dataInterface->multicastTestIp); }
        }

        /// <summary>
        /// Gets the multicast test port used to test transmission capabilities.
        /// </summary>
        /// <value>The multicast test port.</value>
        property int MulticastTestPort {
        public:
            int get() { return _dataInterface->multicastTestPort; }
        }

        /// <summary>
        /// Gets the protocol of the data interface.
        /// </summary>
        /// <value>The interface protocol.</value>
        property StreamProtocols Protocol {
        public:
            StreamProtocols get() { return StreamProtocols(_dataInterface->protocol); }
        }

        /// <summary>
        /// Gets the type of rendering required for the media data delivered by this interface.
        /// </summary>
        /// <value>The rendering type.</value>
        property RenderTypes RenderType {
        public:
            RenderTypes get() { return RenderTypes(_dataInterface->renderType); }
        }

        /// <summary>
        /// Gets a value indicating whether the interface supports multicast transmission.
        /// </summary>
        /// <value><c>true</c> if multicast is supported, <c>false</c> if not.</value>
        property bool SupportsMulticast {
        public:
            bool get() { return _dataInterface->supportsMulticast; }
        }

        /// <summary>
        /// Gets the horizontal resolution of the data.
        /// </summary>
        /// <value>The horizontal resolution.</value>
        property int XResolution {
        public:
            int get() { return _dataInterface->xResolution; }
        }

        /// <summary>
        /// Gets the vertical resolution of the data.
        /// </summary>
        /// <value>The vertical resolution.</value>
        property int YResolution {
        public:
            int get() { return _dataInterface->yResolution; }
        }

    internal:
        VxSdk::IVxDataInterface* _dataInterface;
    };
}
#endif // DataInterface_h__
