/// <summary>
/// Implements the role class.
/// </summary>

#include "Role.h"
#include "User.h"

using namespace System::Collections::Generic;

CPPCli::Role::Role(VxSdk::IVxRole* vxRole) {
    _role = vxRole;
}

CPPCli::Role::!Role() {
    _role->Delete();
    _role = nullptr;
}

CPPCli::Results::Value CPPCli::Role::AddPrivilege(CPPCli::NewPrivilege^ newPrivilege) {
    // Make the call to add the privilege to the role
    VxSdk::VxResult::Value result = _role->AddPrivilege(*newPrivilege->_newPrivilege);
    // Unless there was an issue merging tags the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Role::RemovePrivilege(CPPCli::Privilege^ privilegeItem) {
    // Create a privilege object using the privilegeItem
    VxSdk::IVxPrivilege* delPrivilege = privilegeItem->_privilege;

    // To remove a privilege simply make a DeletePrivilege call
    VxSdk::VxResult::Value result = delPrivilege->DeletePrivilege();
    // Unless there was an issue removing the privilege the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

System::Collections::Generic::List<CPPCli::Privilege^>^ CPPCli::Role::_GetPrivileges() {
    // Create a list of managed privileges
    List<Privilege^>^ mlist = gcnew List<Privilege^>();
    // Create a collection of unmanaged privileges
    VxSdk::VxCollection<VxSdk::IVxPrivilege**> privileges;

    // Make the GetPrivileges call, which will return with the total privilege count, this allows the
    // client to allocate memory.
    VxSdk::VxResult::Value result = _role->GetPrivileges(privileges);
    // As long as there are privileges linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxPrivilege collection
        privileges.collection = new VxSdk::IVxPrivilege*[privileges.collectionSize];
        result = _role->GetPrivileges(privileges);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < privileges.collectionSize; i++)
                mlist->Add(gcnew Privilege(privileges.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] privileges.collection;
    }
    return mlist;
}

System::Collections::Generic::List<CPPCli::User^>^ CPPCli::Role::_GetUsers() {
    // Create a list of managed users
    List<User^>^ mlist = gcnew List<User^>();
    // Create a collection of unmanaged users
    VxSdk::VxCollection<VxSdk::IVxUser**> users;

    // Make the GetUsers call, which will return with the total user count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _role->GetUsers(users);
    // As long as there are users linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxUser collection
        users.collection = new VxSdk::IVxUser*[users.collectionSize];
        result = _role->GetUsers(users);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < users.collectionSize; i++)
                mlist->Add(gcnew User(users.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] users.collection;
    }
    return mlist;
}
