// Declares the user class.
#ifndef User_h__
#define User_h__

#include "VxSdk.h"
#include "Utils.h"
#include "DataObject.h"
#include "Role.h"
#include "Tag.h"

namespace CPPCli {

    /// <summary>
    /// The User class represents information about a system user.
    /// </summary>
    public ref class User {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxUser">The vx user.</param>
        User(VxSdk::IVxUser* vxUser);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~User() {
            this->!User();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !User();

        /// <summary>
        /// Add this user to a role.
        /// </summary>
        /// <param name="role">The role to add this user to.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the user.</returns>
        CPPCli::Results::Value AddToRole(CPPCli::Role^ role);

        /// <summary>
        /// Update this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Remove this user from a role.
        /// </summary>
        /// <param name="role">The role to remove this user from.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the user.</returns>
        CPPCli::Results::Value RemoveFromRole(CPPCli::Role^ role);

        /// <summary>
        /// Submit a request for a password change.
        /// </summary>
        /// <param name="newPassword">The new password.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of setting the password.</returns>
        CPPCli::Results::Value SetPassword(System::String^ newPassword);

        /// <summary>
        /// Gets or sets the state of the user account, either enabled or disabled.
        /// </summary>
        /// <value>The state of the user account.</value>
        property bool AccountState {
        public:
            bool get() { return _GetAccountState(); }
            void set(bool value) { _user->SetAccountState(value); }
        }

        /// <summary>
        /// Gets all private data objects owned by this user and all public data objects. Other user’s private data
        /// objects will not be returned.
        /// </summary>
        /// <value>A list of data objects.</value>
        property System::Collections::Generic::List<DataObject^>^ DataObjects {
        public:
            System::Collections::Generic::List<DataObject^>^ get() { return _GetDataObjects(); }
        }

        /// <summary>
        /// Gets or sets the network domain for this user.
        /// </summary>
        /// <value>The network domain.</value>
        property System::String^ Domain {
        public:
            System::String^ get() { return gcnew System::String(_user->domain); }
            void set(System::String^ value) {
                char domain[64];
                strncpy_s(domain, Utils::ConvertSysStringNonConst(value), sizeof(domain));
                _user->SetName(domain);
            }
        }

        /// <summary>
        /// Gets the unique identifier of the user.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_user->id); }
        }

        /// <summary>
        /// Gets or sets the friendly name, within the domain, of the user.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_user->name); }
            void set(System::String^ value) {
                char name[64];
                strncpy_s(name, Utils::ConvertSysStringNonConst(value), sizeof(name));
                _user->SetName(name);
            }
        }

        /// <summary>
        /// Gets the time at which the user’s password will expire.
        /// </summary>
        /// <value>The password experation date.</value>
        property System::DateTime PasswordExpiration {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_user->passwordExpiration); }
        }

        /// <summary>
        /// Gets the roles currently assigned to this user.
        /// </summary>
        /// <value>A list of assigned roles.</value>
        property System::Collections::Generic::List<Role^>^ Roles {
        public:
            System::Collections::Generic::List<Role^>^ get() { return _GetRoles(); }
        }

        /// <summary>
        /// Gets the tags currently assigned to this user.
        /// </summary>
        /// <value>A list of assigned tags.</value>
        property System::Collections::Generic::List<Tag^>^ Tags {
        public:
            System::Collections::Generic::List<Tag^>^ get() { return _GetTags(); }
        }

    internal:
        VxSdk::IVxUser* _user;
        bool _GetAccountState();
        System::Collections::Generic::List<DataObject^>^ _GetDataObjects();
        System::Collections::Generic::List<Role^>^ _GetRoles();
        System::Collections::Generic::List<Tag^>^ _GetTags();
    };
}
#endif // User_h__
