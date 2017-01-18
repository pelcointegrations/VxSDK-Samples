#ifndef IVxUser_h__
#define IVxUser_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxCollection.h"
#include "IVxDataObject.h"
#include "IVxTag.h"
#include "IVxRole.h"

namespace VxSdk {
    /// <summary>
    /// Represents information about a system user.
    /// </summary>
    struct IVxUser {
    public:
        /// <summary>
        /// Adds a role to this user.
        /// </summary>
        /// <param name="role">The role to add the user to.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddToRole(IVxRole& role) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this user from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this user.</returns>
        virtual VxResult::Value DeleteUser() const = 0;
        /// <summary>
        /// Gets the account state of the user.
        /// </summary>
        /// <param name="isEnabled">True if the user account is enabled, false if disabled.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAccountState(bool& isEnabled) const = 0;
        /// <summary>
        /// Gets the data objects associated with this user.
        /// <para>Available filters: kClientType, kModifiedSince, kOwned, kOwner.</para>
        /// </summary>
        /// <param name="dataObjectCollection">A <see cref="VxCollection"/> of data objects associated with this user.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataObjects(VxCollection<IVxDataObject**>& dataObjectCollection) const = 0;
        /// <summary>
        /// Gets the roles associated with this user.
        /// <para>Available filters: kId, kInternal, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="roleCollection">The roles associated with this user.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRoles(VxCollection<IVxRole**>& roleCollection) const = 0;
        /// <summary>
        /// Gets all private tags owned by this user and all public tags.  Other user’s private tags will not be returned regardless of permissions.
        /// <para>Available filters: kModifiedSince, kName, kOwned, kOwner, kResourceId, kResourceType.</para>
        /// </summary>
        /// <param name="tagCollection">A <see cref="VxCollection"/> of tags available to the user.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetTags(VxCollection<IVxTag**>& tagCollection) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Removes a role from this user.
        /// </summary>
        /// <param name="role">The role to remove the user from.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value RemoveFromRole(IVxRole& role) const = 0;
        /// <summary>
        /// Sets the account state of the user. A disabled account will not be able to access the system.
        /// </summary>
        /// <param name="isEnabled">True to enable the user account, false to disable.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetAccountState(bool isEnabled) const = 0;
        /// <summary>
        /// Sets the domain property.
        /// </summary>
        /// <param name="domain">The new domain value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDomain(char domain[64]) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets a new password for the user.
        /// </summary>
        /// <param name="newPassword">The new password to set for this user.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetPassword(char newPassword[64]) const = 0;

    public:
        /// <summary>
        /// The network domain for this user.
        /// </summary>
        char domain[64];
        /// <summary>
        /// The unique identifier of the user.
        /// </summary>
        char id[64];
        /// <summary>
        /// The unique name, within the domain, of the user.
        /// </summary>
        char name[64];
        /// <summary>
        /// The time at which the user’s password will expire.
        /// </summary>
        char passwordExpiration[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->domain);
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->passwordExpiration);
        }
    };
}

#endif // IVxUser_h__
