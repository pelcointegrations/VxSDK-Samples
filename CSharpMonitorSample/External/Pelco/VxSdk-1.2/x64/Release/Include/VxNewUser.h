#ifndef VxNewUser_h__
#define VxNewUser_h__

#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new user to be created.
    /// </summary>
    struct VxNewUser {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewUser"/> struct.
        /// </summary>
        VxNewUser() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewUser"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewUser(const VxNewUser& ref) {
            this->mustChangePassword = ref.mustChangePassword;
            Utilities::StrCopySafe(this->domain, ref.domain);
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->password, ref.password);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewUser"/> struct.
        /// </summary>
        ~VxNewUser() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->mustChangePassword = false;
            VxZeroArray(this->domain);
            VxZeroArray(this->name);
            VxZeroArray(this->password);
        }

    public:
        /// <summary>
        /// If true, the new user will be forced to change their password the first time they log in.
        /// </summary>
        bool mustChangePassword;
        /// <summary>
        /// The network domain for the user. Defaults to LOCAL.
        /// </summary>
        char domain[64];
        /// <summary>
        /// The unique name of the user that this resource is representing.
        /// </summary>
        char name[64];
        /// <summary>
        /// The password to associate with the user.  Must contain more than 7 characters.
        /// </summary>
        char password[64];
    };
}

#endif // VxNewUser_h__