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
        /// Gets or sets the employee identifier associated with the user.
        /// </summary>
        /// <value>The employee identifier.</value>
        property System::String^ EmployeeId {
        public:
            System::String^ get() { return gcnew System::String(_newUser->employeeId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newUser->employeeId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the first name of user.
        /// </summary>
        /// <value>The first name of user.</value>
        property System::String^ FirstName {
        public:
            System::String^ get() { return gcnew System::String(_newUser->firstName); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newUser->firstName, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the last name of user.
        /// </summary>
        /// <value>The last name of user.</value>
        property System::String^ LastName {
        public:
            System::String^ get() { return gcnew System::String(_newUser->lastName); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newUser->lastName, Utils::ConvertSysString(value)); }
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
        /// Gets or sets supplemental information about the user.
        /// </summary>
        /// <value>Information about the user.</value>
        property System::String^ Note {
        public:
            System::String^ get() { return gcnew System::String(_newUser->note); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newUser->note, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the user password.
        /// </summary>
        /// <value>The user password.</value>
        property System::String^ Password {
        public:
            System::String^ get() { return gcnew System::String(_newUser->password); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newUser->password, Utils::ConvertSysString(value)); }
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

                for (int i = 0; i < _newUser->phoneNumberSize; i++)
                {
                    System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^> kvPair(
                        (User::PhoneType)_newUser->phoneNumbers[i].type,
                        gcnew System::String(_newUser->phoneNumbers[i].number));

                    mList->Add(kvPair);
                }

                return mList;
            }
            void set(System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>^ value) {
                _newUser->phoneNumberSize = value->Count;
                VxSdk::VxPhoneNumber *numbers = new VxSdk::VxPhoneNumber[_newUser->phoneNumberSize];
                _newUser->phoneNumbers = numbers;

                for (int i = 0; i < _newUser->phoneNumberSize; i++)
                {
                    _newUser->phoneNumbers[i].type = (VxSdk::VxPhoneType::Value)value[i].Key;
                    VxSdk::Utilities::StrCopySafe(_newUser->phoneNumbers[i].number, Utils::ConvertSysString(value[i].Value));
                }
            }
        }

    internal:
        VxSdk::VxNewUser* _newUser;
    };
}
#endif // NewUser_h__
