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
        /// Gets a value indicating whether the interface supports multicast transmission.
        /// </summary>
        /// <value><c>true</c> if multicast is supported, <c>false</c> if not.</value>
        property bool SupportsMulticast {
        public:
            bool get() { return _dataInterface->supportsMulticast; }
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
        /// Gets the endpoint of the data interface.
        /// </summary>
        /// <value>The data interface endpoint.</value>
        property System::String^ DataEndpoint {
        public:
            System::String^ get() { return gcnew System::String(_dataInterface->dataEndpoint); }
        }

    internal:
        VxSdk::IVxDataInterface* _dataInterface;
    };
}
#endif // DataInterface_h__
