#ifndef IVxDataInterface_h__
#define IVxDataInterface_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a data interface for a data source. Clients can retrieve data from the data source using the protocol specified
    /// by this interface.
    /// </summary>
    struct IVxDataInterface {
    public:
        /// <summary>
        /// Indicates whether the interface provides multicast transmission.
        /// </summary>
        bool supportsMulticast;
        /// <summary>
        /// The protocol-specific stream control endpoint URI.
        /// </summary>
        char dataEndpoint[512];
        /// <summary>
        /// The multicast test IP used to test transmission capabilities.
        /// </summary>
        char multicastTestIp[64];
        /// <summary>
        /// The multicast test port used to test transmission capabilities.
        /// </summary>
        unsigned short multicastTestPort;
        /// <summary>
        /// The transport protocol used by the data interface.
        /// </summary>
        VxStreamProtocol::Value protocol;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->supportsMulticast = false;
            VxZeroArray(this->dataEndpoint);
            VxZeroArray(this->multicastTestIp);
            this->multicastTestPort = 0;
            this->protocol = VxStreamProtocol::kUnknown;
        }
    };
}

#endif // IVxDataInterface_h__