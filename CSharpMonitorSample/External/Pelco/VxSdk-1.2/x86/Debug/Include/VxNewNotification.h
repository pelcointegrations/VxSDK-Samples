#ifndef VxNewNotification_h__
#define VxNewNotification_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new notification configuration for a situation.
    /// </summary>
    struct VxNewNotification {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewNotification"/> struct.
        /// </summary>
        VxNewNotification() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewNotification"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewNotification(const VxNewNotification& ref) {
            this->roleIds = ref.roleIds;
            this->roleIdSize = ref.roleIdSize;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewNotification"/> class.
        /// </summary>
        ~VxNewNotification() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->roleIds = nullptr;
            this->roleIdSize = 0;
        }

    public:
        /// <summary>
        /// The ids for each role that should receive this notification.
        /// </summary>
        char** roleIds;
        /// <summary>
        /// The size of <see cref="roleIds"/>.
        /// </summary>
        int roleIdSize;
    };
}

#endif // VxNewNotification_h__