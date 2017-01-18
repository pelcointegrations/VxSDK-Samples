#ifndef IVxRole_h__
#define IVxRole_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxCollection.h"
#include "IVxPrivilege.h"
#include "VxNewPrivilege.h"

namespace VxSdk {
    struct IVxUser;

    /// <summary>
    /// Represents a collection of permissions which can be assigned to a user.
    /// </summary>
    struct IVxRole {
    public:
        /// <summary>
        /// Adds a new privilege to this role.
        /// </summary>
        /// <param name="newPrivilege">The privilege to add.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddPrivilege(VxNewPrivilege& newPrivilege) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this role from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this role.</returns>
        virtual VxResult::Value DeleteRole() const = 0;
        /// <summary>
        /// Gets the privileges assigned to this role.
        /// <para>Available filters: kModifiedSince, kPermission, kResourceId.</para>
        /// </summary>
        /// <param name="privilegeCollection">The privileges assigned to this role.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPrivileges(VxCollection<IVxPrivilege**>& privilegeCollection) const = 0;
        /// <summary>
        /// Gets the users which are currently assigned this role.
        /// <para>Available filters: kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="userCollection">A <see cref="VxCollection"/> of users which are currently assigned this role.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUsers(VxCollection<IVxUser**>& userCollection) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;

    public:
        /// <summary>
        /// Indicates whether this role is read-only.
        /// </summary>
        bool isReadOnly;
        /// <summary>
        /// The unique identifier of the role.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the role.
        /// </summary>
        char name[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isReadOnly = false;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
        }
    };
}

#endif // IVxRole_h__
