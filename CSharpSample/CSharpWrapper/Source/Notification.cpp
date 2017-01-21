/// <summary>
/// Implements the notification class.
/// </summary>
#include "Notification.h"

using namespace System::Collections::Generic;

CPPCli::Notification::Notification(VxSdk::IVxNotification* vxNotification) {
    _notification = vxNotification;
}

CPPCli::Notification::!Notification() {
    _notification->Delete();
    _notification = nullptr;
}

CPPCli::Results::Value CPPCli::Notification::AddRole(CPPCli::Role^ role) {
    // Make the call to add the role to the notification
    VxSdk::VxResult::Value result = _notification->AddRole(*role->_role);
    // Unless there was an issue adding the role the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Notification::Refresh() {
    return (CPPCli::Results::Value)_notification->Refresh();
}

CPPCli::Results::Value CPPCli::Notification::RemoveRole(CPPCli::Role^ role) {
    // Make the call to remove the role from the notification
    VxSdk::VxResult::Value result = _notification->RemoveRole(*role->_role);
    // Unless there was an issue removing the role the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

System::Collections::Generic::List<CPPCli::Role^>^ CPPCli::Notification::_GetRoles() {
    // Create a list of managed roles
    List<Role^>^ mlist = gcnew List<Role^>();
    // Create a collection of unmanaged roles
    VxSdk::VxCollection<VxSdk::IVxRole**> roles;

    // Make the GetRoles call, which will return with the total role count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _notification->GetRoles(roles);
    // As long as there are roles linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxRole collection
        roles.collection = new VxSdk::IVxRole*[roles.collectionSize];
        result = _notification->GetRoles(roles);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < roles.collectionSize; i++)
                mlist->Add(gcnew Role(roles.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] roles.collection;
    }
    return mlist;
}
