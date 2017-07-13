// Declares the user info class.
#ifndef UserInfo_h__
#define UserInfo_h__

#include "VxSdk.h"
#include "Utils.h"
#include "User.h"

namespace CPPCli {

    /// <summary>
    /// The UserInfo class represents general information about a user.
    /// </summary>
    public ref class UserInfo {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxUserInfo">The vx user info.</param>
        UserInfo(VxSdk::IVxUserInfo* vxUserInfo) {
            _userInfo = vxUserInfo;
        }

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~UserInfo() {
            this->!UserInfo();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !UserInfo() {
            _userInfo->Delete();
            _userInfo = nullptr;
        }

        /// <summary>
        /// Gets the employee identifier associated with the user.
        /// </summary>
        /// <value>The employee identifier.</value>
        property System::String^ EmployeeId {
        public:
            System::String^ get() { return gcnew System::String(_userInfo->employeeId); }
        }

        /// <summary>
        /// Gets the first name of the user.
        /// </summary>
        /// <value>The first name of user.</value>
        property System::String^ FirstName {
        public:
            System::String^ get() { return gcnew System::String(_userInfo->firstName); }
        }

        /// <summary>
        /// Gets the last name of the user.
        /// </summary>
        /// <value>The last name of user.</value>
        property System::String^ LastName {
        public:
            System::String^ get() { return gcnew System::String(_userInfo->lastName); }
        }

        /// <summary>
        /// Gets the friendly name, within the domain, of the user.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_userInfo->name); }
        }

        /// <summary>
        /// Gets supplemental information about the user.
        /// </summary>
        /// <value>Information about the user.</value>
        property System::String^ Note {
        public:
            System::String^ get() { return gcnew System::String(_userInfo->note); }
        }

        /// <summary>
        /// Gets the telephone number(s) for the user.
        /// </summary>
        /// <value>The telephone number(s) for the user.</value>
        property System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>^ PhoneNumbers {
        public:
            System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>^ get() {
                System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>^ mList =
                    gcnew System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^>>();

                for (int i = 0; i < _userInfo->phoneNumberSize; i++)
                {
                    auto phoneNumber = _userInfo->phoneNumbers[i];
                    System::Collections::Generic::KeyValuePair<User::PhoneType, System::String^> kvPair((User::PhoneType)phoneNumber.type,
                        gcnew System::String(phoneNumber.number));

                    mList->Add(kvPair);
                }

                return mList;
            }
        }

    internal:
        VxSdk::IVxUserInfo* _userInfo;
    };
}
#endif // UserInfo_h__
