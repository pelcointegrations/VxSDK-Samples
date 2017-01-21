// Declares the new notification class.
#ifndef NewNotification_h__
#define NewNotification_h__

#include "Notification.h"

namespace CPPCli {

    /// <summary>
    /// The NewNotification class represents a new notification.
    /// </summary>
    public ref class NewNotification {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewNotification() {
            _newNotification = new VxSdk::VxNewNotification();
            _roles = gcnew System::Collections::Generic::List<Role^>();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewNotification">The new notification.</param>
        NewNotification(VxSdk::VxNewNotification* vxNewNotification) {
            _newNotification = vxNewNotification;
            _roles = gcnew System::Collections::Generic::List<Role^>();
        }

        /// <summary>
        /// Gets or sets the roles that should receive this notification.
        /// </summary>
        /// <value>A <c>List</c> of role ids.</value>
        property System::Collections::Generic::List<Role^>^ Roles {
        public:
            System::Collections::Generic::List<Role^>^ get() { return _roles; }
            void set(System::Collections::Generic::List<Role^>^ value) { _roles = value; }
        }

    internal:
        VxSdk::VxNewNotification* _newNotification;
        System::Collections::Generic::List<Role^>^ _roles;
    };
}
#endif // NewNotification_h__
