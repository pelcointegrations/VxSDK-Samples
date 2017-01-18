/// <summary>
/// Implements the user class.
/// </summary>

#include "User.h"

using namespace System::Collections::Generic;

CPPCli::User::User(VxSdk::IVxUser* vxUser) {
    _user = vxUser;
}

CPPCli::User::!User() {
    _user->Delete();
    _user = nullptr;
}

CPPCli::Results::Value CPPCli::User::AddToRole(CPPCli::Role^ role) {
    // Make the call to add the user to the role
    VxSdk::VxResult::Value result = _user->AddToRole(*role->_role);
    // Unless there was an issue adding the user the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::User::Refresh() {
    return (CPPCli::Results::Value)_user->Refresh();
}

CPPCli::Results::Value CPPCli::User::RemoveFromRole(CPPCli::Role^ role) {
    // Make the call to remove the user from the role
    VxSdk::VxResult::Value result = _user->RemoveFromRole(*role->_role);
    // Unless there was an issue removing the user from the role the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::User::SetPassword(System::String^ newPassword) {
    char password[64];
    strncpy_s(password, Utils::ConvertSysStringNonConst(newPassword), sizeof(password));

    // Make the call to set the users password
    VxSdk::VxResult::Value result = _user->SetPassword(password);
    // Unless there was an issue setting the password the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

bool CPPCli::User::_GetAccountState() {
    // Get and return the account state
    bool state;
    _user->GetAccountState(state);
    return state;
}

System::Collections::Generic::List<CPPCli::DataObject^>^ CPPCli::User::_GetDataObjects() {
    // Create a list of managed data objects
    List<DataObject^>^ mlist = gcnew List<DataObject^>();
    // Create a collection of unmanaged data objects
    VxSdk::VxCollection<VxSdk::IVxDataObject**> dataObjects;

    // Make the GetDataObjects call, which will return with the total data object count, this allows the
    // client to allocate memory.
    VxSdk::VxResult::Value result = _user->GetDataObjects(dataObjects);
    // As long as there are data objects linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataObject collection
        dataObjects.collection = new VxSdk::IVxDataObject*[dataObjects.collectionSize];
        result = _user->GetDataObjects(dataObjects);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataObjects.collectionSize; i++)
                mlist->Add(gcnew DataObject(dataObjects.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataObjects.collection;
    }
    return mlist;
}

System::Collections::Generic::List<CPPCli::Role^>^ CPPCli::User::_GetRoles() {
    // Create a list of managed roles
    List<Role^>^ mlist = gcnew List<Role^>();
    // Create a collection of unmanaged roles
    VxSdk::VxCollection<VxSdk::IVxRole**> roles;

    // Make the GetRoles call, which will return with the total role count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _user->GetRoles(roles);
    // As long as there are roles linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxRole collection
        roles.collection = new VxSdk::IVxRole*[roles.collectionSize];
        result = _user->GetRoles(roles);
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

System::Collections::Generic::List<CPPCli::Tag^>^ CPPCli::User::_GetTags() {
    // Create a list of managed tags
    List<Tag^>^ mlist = gcnew List<Tag^>();
    // Create a collection of unmanaged tags
    VxSdk::VxCollection<VxSdk::IVxTag**> tags;

    // Make the GetTags call, which will return with the total tag count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _user->GetTags(tags);
    // As long as there are tags linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxTag collection
        tags.collection = new VxSdk::IVxTag*[tags.collectionSize];
        result = _user->GetTags(tags);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < tags.collectionSize; i++)
                mlist->Add(gcnew Tag(tags.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] tags.collection;
    }
    return mlist;
}
