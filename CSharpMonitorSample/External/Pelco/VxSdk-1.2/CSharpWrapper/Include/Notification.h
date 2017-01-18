// Declares the notification class.
#ifndef Notification_h__
#define Notification_h__

#include "VxSdk.h"
#include "Role.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The Notification class represents a particular notification configuration for a situation.
    /// </summary>
    public ref class Notification {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNotification">The vx notification.</param>
        Notification(VxSdk::IVxNotification* vxNotification);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Notification() {
            this->!Notification();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Notification();

        /// <summary>
        /// Add a role to the list of roles that this notification serves.
        /// </summary>
        /// <param name="role">The role to add to this notification.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the role.</returns>
        CPPCli::Results::Value AddRole(Role^ role);

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Remove a role from the list of roles that this notification serves.
        /// </summary>
        /// <param name="role">The role to remove from this notification.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the role.</returns>
        CPPCli::Results::Value RemoveRole(Role^ role);

        /// <summary>
        /// Gets the unique notification identifier.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_notification->id); }
        }

        /// <summary>
        /// Gets the roles that this notification serves.
        /// </summary>
        /// <value>A list of roles.</value>
        property System::Collections::Generic::List<Role^>^ Roles {
        public:
            System::Collections::Generic::List<Role^>^ get() { return _GetRoles(); }
        }

    internal:
        VxSdk::IVxNotification* _notification;
        System::Collections::Generic::List<Role^>^ _GetRoles();
    };
}
#endif // Notification_h__
