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
        /// Values that represent the type of a phone number.
        /// </summary>
        enum class PhoneType {
            /// <summary>Home number.</summary>
            Home,

            /// <summary>Home fax number.</summary>
            HomeFax,

            /// <summary>Mobile number.</summary>
            Mobile,

            /// <summary>Other number.</summary>
            Other,

            /// <summary>Pager number.</summary>
            Pager,

            /// <summary>Work number.</summary>
            Work,

            /// <summary>Work fax number.</summary>
            WorkFax
        };

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
                VxSdk::Utilities::StrCopySafe(domain, Utils::ConvertSysStringNonConst(value));
                _user->SetName(domain);
            }
        }

        /// <summary>
        /// Gets or sets the employee identifier associated with the user.
        /// </summary>
        /// <value>The employee identifier.</value>
        property System::String^ EmployeeId {
        public:
            System::String^ get() { return gcnew System::String(_user->employeeId); }
            void set(System::String^ value) {
                char employeeId[64];
                VxSdk::Utilities::StrCopySafe(employeeId, Utils::ConvertSysStringNonConst(value));
                _user->SetName(employeeId);
            }
        }

        /// <summary>
        /// Gets or sets the first name of user.
        /// </summary>
        /// <value>The first name of user.</value>
        property System::String^ FirstName {
        public:
            System::String^ get() { return gcnew System::String(_user->firstName); }
            void set(System::String^ value) {
                char firstName[64];
                VxSdk::Utilities::StrCopySafe(firstName, Utils::ConvertSysStringNonConst(value));
                _user->SetName(firstName);
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
        /// Gets or sets the last name of user.
        /// </summary>
        /// <value>The last name of user.</value>
        property System::String^ LastName {
        public:
            System::String^ get() { return gcnew System::String(_user->lastName); }
            void set(System::String^ value) {
                char lastName[64];
                VxSdk::Utilities::StrCopySafe(lastName, Utils::ConvertSysStringNonConst(value));
                _user->SetName(lastName);
            }
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
                VxSdk::Utilities::StrCopySafe(name, Utils::ConvertSysStringNonConst(value));
                _user->SetName(name);
            }
        }

        /// <summary>
        /// Gets or sets supplemental information about the user.
        /// </summary>
        /// <value>Information about the user.</value>
        property System::String^ Note {
        public:
            System::String^ get() { return gcnew System::String(_user->note); }
            void set(System::String^ value) {
                char note[1024];
                VxSdk::Utilities::StrCopySafe(note, Utils::ConvertSysStringNonConst(value));
                _user->SetName(note);
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
        /// Gets or sets the telephone number(s) for the user.
        /// </summary>
        /// <value>The telephone number(s) for the user.</value>
        property System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>^ PhoneNumbers {
        public:
            System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>^ get() {
                System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>^ mList =
                    gcnew System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>();

                for (int i = 0; i < _user->phoneNumberSize; i++)
                {
                    auto phoneNumber = _user->phoneNumbers[i];
                    System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^> kvPair((User::PhoneType)phoneNumber.type,
                        gcnew System::String(phoneNumber.number));

                    mList->Add(kvPair);
                }

                return mList;
            }
            void set(System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>^ value) {
                int size = value->Count;
                VxSdk::VxPhoneNumber *numbers = new VxSdk::VxPhoneNumber[size];
                for (int i = 0; i < size; i++) {
                    numbers[i].type = (VxSdk::VxPhoneType::Value)value[i].Key;
                    VxSdk::Utilities::StrCopySafe(numbers[i].number, Utils::ConvertSysString(value[i].Value));
                }

                _user->SetPhoneNumbers(numbers, size);
            }
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
