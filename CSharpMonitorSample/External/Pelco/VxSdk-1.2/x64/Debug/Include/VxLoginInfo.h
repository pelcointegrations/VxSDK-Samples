#ifndef VxLoginInfo_h__
#define VxLoginInfo_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents the information needed to log in to a VideoXpert system.
    /// </summary>
    struct VxLoginInfo {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxLoginInfo"/> struct.
        /// </summary>
        VxLoginInfo() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxLoginInfo"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxLoginInfo(const VxLoginInfo& ref) {
            this->useSsl = ref.useSsl;
            Utilities::StrCopySafe(this->authToken, ref.authToken);
            Utilities::StrCopySafe(this->ipAddress, ref.ipAddress);
            Utilities::StrCopySafe(this->password, ref.password);
            Utilities::StrCopySafe(this->username, ref.username);
            this->port = ref.port;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxLoginInfo"/> class.
        /// </summary>
        ~VxLoginInfo() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->useSsl = false;
            VxZeroArray(this->authToken);
            VxZeroArray(this->ipAddress);
            VxZeroArray(this->password);
            VxZeroArray(this->username);
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
        /// The password to login with.
        /// </summary>
        char password[64];
        /// <summary>
        /// The username to login with.
        /// </summary>
        char username[64];
        /// <summary>
        /// The VideoXpert system port.
        /// </summary>
        unsigned short port;
    };
}

#endif // VxLoginInfo_h__
