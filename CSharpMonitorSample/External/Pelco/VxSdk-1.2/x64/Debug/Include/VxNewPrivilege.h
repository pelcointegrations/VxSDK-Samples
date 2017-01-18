#ifndef VxNewPrivilege_h__
#define VxNewPrivilege_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new privilege to be created.
    /// </summary>
    struct VxNewPrivilege {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewPrivilege"/> struct.
        /// </summary>
        VxNewPrivilege() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewPrivilege"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewPrivilege(const VxNewPrivilege& ref) {
            this->priority = ref.priority;
            this->permissionId = ref.permissionId;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewPrivilege"/> struct.
        /// </summary>
        ~VxNewPrivilege() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->priority = 0;
            this->permissionId = VxPermissionId::kUnknown;
        }

    public:
        /// <summary>
        /// Relative priority for the privilege, from 1 to 250. Smaller numbers have higher priority than larger
        /// numbers (e.g. 1 is the highest priority).
        /// </summary>
        int priority;
        /// <summary>
        /// Identifier of the permission being granted.
        /// </summary>
        VxPermissionId::Value permissionId;
    };
}

#endif // VxNewPrivilege_h__
