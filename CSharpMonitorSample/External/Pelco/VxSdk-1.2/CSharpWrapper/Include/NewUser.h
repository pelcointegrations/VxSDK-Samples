// Declares the new user class.
#ifndef NewUser_h__
#define NewUser_h__

#include "User.h"

namespace CPPCli {

    /// <summary>
    /// The NewUser class represents a new user.
    /// </summary>
    public ref class NewUser {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewUser() {
            _newUser = new VxSdk::VxNewUser();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewUser">The new user.</param>
        NewUser(VxSdk::VxNewUser* vxNewUser) {
            _newUser = vxNewUser;
        }

        /// <summary>
        /// Gets or sets the network domain for this user.
        /// </summary>
        /// <value>The network domain.</value>
        property System::String^ Domain {
        public:
            System::String^ get() { return gcnew System::String(_newUser->domain); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newUser->domain, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets whether the new user will be forced to change their password the first time they log in.
        /// </summary>
        /// <value><c>true</c> if the user must change its password, <c>false</c> if if not.</value>
        property bool MustChangePassword {
        public:
            bool get() { return _newUser->mustChangePassword; }
            void set(bool value) { _newUser->mustChangePassword = value; }
        }

        /// <summary>
        /// Gets or sets the unique users friendly name.
        /// </summary>
        /// <value>The unique friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_newUser->name); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newUser->name, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the user password.
        /// </summary>
        /// <value>The user password</value>
        property System::String^ Password {
        public:
            System::String^ get() { return gcnew System::String(_newUser->password); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newUser->password, Utils::ConvertSysString(value)); }
        }

    internal:
        VxSdk::VxNewUser* _newUser;
    };
}
#endif // NewUser_h__
