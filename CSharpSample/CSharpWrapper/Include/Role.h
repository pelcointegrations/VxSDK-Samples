// Declares the role class.
#ifndef Role_h__
#define Role_h__

#include "VxSdk.h"
#include "Utils.h"
#include "NewPrivilege.h"

namespace CPPCli {

    /// <summary>
    /// The Role class represents a collection of permissions which can be assigned to a user.
    /// </summary>
    public ref class Role {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxRole">The vx role.</param>
        Role(VxSdk::IVxRole* vxRole);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Role() {
            this->!Role();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Role();

        /// <summary>
        /// Add a new privilege to the role.
        /// </summary>
        /// <param name="newPrivilege">The new privilege to add.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the privilege.</returns>
        CPPCli::Results::Value AddPrivilege(CPPCli::NewPrivilege^ newPrivilege);

        /// <summary>
        /// Update this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Remove a privilege from the role.
        /// </summary>
        /// <param name="privilegeItem">The privilege to remove.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the privilege.</returns>
        CPPCli::Results::Value RemovePrivilege(CPPCli::Privilege^ privilegeItem);

        /// <summary>
        /// Gets the unique identifier for this role.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_role->id); }
        }

        /// <summary>
        /// Indicates that the role was created internally on the server and is read-only.
        /// </summary>
        /// <value>The read-only value.</value>
        property bool IsReadOnly {
        public:
            bool get() { return _role->isReadOnly; }
        }

        /// <summary>
        /// Gets or sets the friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_role->name); }
            void set(System::String^ value) {
                char name[64];
                VxSdk::Utilities::StrCopySafe(name, Utils::ConvertSysStringNonConst(value));
                _role->SetName(name);
            }
        }

        /// <summary>
        /// Gets the privileges assigned to this role.
        /// </summary>
        /// <value>A list of privileges.</value>
        property System::Collections::Generic::List<Privilege^>^ Privileges {
        public:
            System::Collections::Generic::List<Privilege^>^ get() { return _GetPrivileges(); }
        }

        /// <summary>
        /// Gets the users assigned to this role.
        /// </summary>
        /// <value>A list of users.</value>
        property System::Collections::Generic::List<User^>^ Users {
        public:
            System::Collections::Generic::List<User^>^ get() { return _GetUsers(); }
        }

    internal:
        VxSdk::IVxRole* _role;
        System::Collections::Generic::List<Privilege^>^ _GetPrivileges();
        System::Collections::Generic::List<User^>^ _GetUsers();
    };
}
#endif // Role_h__
