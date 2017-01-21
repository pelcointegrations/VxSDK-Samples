/// <summary>
/// Implements the privilege class.
/// </summary>

#include "Privilege.h"
#include "User.h"

using namespace System::Collections::Generic;

CPPCli::Privilege::Privilege(VxSdk::IVxPrivilege* vxPrivilege) {
    _privilege = vxPrivilege;
}

CPPCli::Privilege::!Privilege() {
    _privilege->Delete();
    _privilege = nullptr;
}

CPPCli::Results::Value CPPCli::Privilege::Link(List<CPPCli::DataSource^>^ dataSources) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of data sources
    for (int i = 0; i < dataSources->Count; i++) {
        // Link the data sources to the privilege
        result = _privilege->Link(*dataSources[i]->_dataSource);
    }

    // Unless there was an issue linking the data sources the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Privilege::Link(List<CPPCli::Device^>^ devices) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of devices
    for (int i = 0; i < devices->Count; i++) {
        // Link the devices to the privilege
        result = _privilege->Link(*devices[i]->_device);
    }

    // Unless there was an issue linking the devices the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Privilege::Link(List<CPPCli::User^>^ users) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of users
    for (int i = 0; i < users->Count; i++) {
        // Link the users to the privilege
        result = _privilege->Link(*users[i]->_user);
    }

    // Unless there was an issue linking the users the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Privilege::Refresh() {
    return (CPPCli::Results::Value)_privilege->Refresh();
}

CPPCli::Results::Value CPPCli::Privilege::Unlink(List<CPPCli::DataSource^>^ dataSources) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of data sources
    for (int i = 0; i < dataSources->Count; i++) {
        // UnLink the data sources to the privilege
        result = _privilege->UnLink(*dataSources[i]->_dataSource);
    }

    // Unless there was an issue unlinking the data sources the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Privilege::Unlink(List<CPPCli::Device^>^ devices) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of devices
    for (int i = 0; i < devices->Count; i++) {
        // UnLink the devices to the privilege
        result = _privilege->UnLink(*devices[i]->_device);
    }

    // Unless there was an issue unlinking the devices the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Privilege::Unlink(List<CPPCli::User^>^ users) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of users
    for (int i = 0; i < users->Count; i++) {
        // UnLink the data sources to the privilege
        result = _privilege->UnLink(*users[i]->_user);
    }

    // Unless there was an issue unlinking the users the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

System::Collections::Generic::List<CPPCli::DataSource^>^ CPPCli::Privilege::_GetLinkedDataSources() {
    // Create a list of managed data sources
    List<CPPCli::DataSource^>^ mlist = gcnew List<CPPCli::DataSource^>();
    // Create a collection of unmanaged data sources
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetLinks call, which will return with the total data source count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _privilege->GetLinks(dataSources);
    // As long as there are data sources linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataSource collection
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _privilege->GetLinks(dataSources);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataSources.collectionSize; i++)
                mlist->Add(gcnew CPPCli::DataSource(dataSources.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataSources.collection;
    }
    return mlist;
}

System::Collections::Generic::List<CPPCli::Device^>^ CPPCli::Privilege::_GetLinkedDevices() {
    // Create a list of managed devices
    List<CPPCli::Device^>^ mlist = gcnew List<CPPCli::Device^>();
    // Create a collection of unmanaged devices
    VxSdk::VxCollection<VxSdk::IVxDevice**> devices;

    // Make the GetLinks call, which will return with the total device count, this allows the
    // client to allocate memory.
    VxSdk::VxResult::Value result = _privilege->GetLinks(devices);
    // As long as there are devices linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDevice collection
        devices.collection = new VxSdk::IVxDevice*[devices.collectionSize];
        result = _privilege->GetLinks(devices);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < devices.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Device(devices.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] devices.collection;
    }
    return mlist;
}

System::Collections::Generic::List<CPPCli::User^>^ CPPCli::Privilege::_GetLinkedUsers() {
    // Create a list of managed users
    List<CPPCli::User^>^ mlist = gcnew List<CPPCli::User^>();
    // Create a collection of unmanaged users
    VxSdk::VxCollection<VxSdk::IVxUser**> users;

    // Make the GetLinks call, which will return with the total user count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _privilege->GetLinks(users);
    // As long as there are users linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxUser collection
        users.collection = new VxSdk::IVxUser*[users.collectionSize];
        result = _privilege->GetLinks(users);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < users.collectionSize; i++)
                mlist->Add(gcnew CPPCli::User(users.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] users.collection;
    }
    return mlist;
}

int CPPCli::Privilege::_GetPriority() {
    // Get and return the priority
    int priority;
    _privilege->GetPriority(priority);
    return priority;
}

bool CPPCli::Privilege::_GetRestricted() {
    // Get and return the restriction state
    bool isRestricted;
    _privilege->GetRestricted(isRestricted);
    return isRestricted;
}

System::Collections::Generic::List<CPPCli::DataSource^>^ CPPCli::Privilege::_GetUnLinkedDataSources() {
    // Create a list of managed data sources
    List<CPPCli::DataSource^>^ mlist = gcnew List<CPPCli::DataSource^>();
    // Create a collection of unmanaged data sources
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetUnLinked call, which will return with the total data source count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _privilege->GetUnLinked(dataSources);
    // As long as there are data sources linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataSource collection
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _privilege->GetUnLinked(dataSources);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataSources.collectionSize; i++)
                mlist->Add(gcnew CPPCli::DataSource(dataSources.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataSources.collection;
    }
    return mlist;
}

System::Collections::Generic::List<CPPCli::Device^>^ CPPCli::Privilege::_GetUnLinkedDevices() {
    // Create a list of managed devices
    List<CPPCli::Device^>^ mlist = gcnew List<CPPCli::Device^>();
    // Create a collection of unmanaged devices
    VxSdk::VxCollection<VxSdk::IVxDevice**> devices;

    // Make the GetUnLinked call, which will return with the total device count, this allows the
    // client to allocate memory.
    VxSdk::VxResult::Value result = _privilege->GetUnLinked(devices);
    // As long as there are devices linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDevice collection
        devices.collection = new VxSdk::IVxDevice*[devices.collectionSize];
        result = _privilege->GetUnLinked(devices);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < devices.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Device(devices.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] devices.collection;
    }
    return mlist;
}

System::Collections::Generic::List<CPPCli::User^>^ CPPCli::Privilege::_GetUnLinkedUsers() {
    // Create a list of managed users
    List<CPPCli::User^>^ mlist = gcnew List<CPPCli::User^>();
    // Create a collection of unmanaged users
    VxSdk::VxCollection<VxSdk::IVxUser**> users;

    // Make the GetUnLinked call, which will return with the total user count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _privilege->GetUnLinked(users);
    // As long as there are users linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxUser collection
        users.collection = new VxSdk::IVxUser*[users.collectionSize];
        result = _privilege->GetUnLinked(users);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < users.collectionSize; i++)
                mlist->Add(gcnew CPPCli::User(users.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] users.collection;
    }
    return mlist;
}
