#ifndef VxAuthInfo_h__
#define VxAuthInfo_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents the information needed to authenticate with a VideoXpert system.
    /// </summary>
    struct VxAuthInfo {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxAuthInfo"/> struct.
        /// </summary>
        VxAuthInfo() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxAuthInfo"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxAuthInfo(const VxAuthInfo& ref) {
            this->useSsl = ref.useSsl;
            Utilities::StrCopySafe(this->authToken, ref.authToken);
            Utilities::StrCopySafe(this->ipAddress, ref.ipAddress);
            this->port = ref.port;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxAuthInfo"/> class.
        /// </summary>
        ~VxAuthInfo() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->useSsl = false;
            VxZeroArray(this->authToken);
            VxZeroArray(this->ipAddress);
            this->port = 0;
        }

    public:
        /// <summary>
        /// Indicates whether the connection will use SSL.
        /// </summary>
        bool useSsl;
        /// <summary>
        /// The authentication token to use.
        /// </summary>
        char authToken[512];
        /// <summary>
        /// The VideoXpert system IP.
        /// </summary>
        char ipAddress[64];
        /// <summary>
        /// The VideoXpert system port.
        /// </summary>
        unsigned short port;
    };
}

#endif // VxAuthInfo_h__
