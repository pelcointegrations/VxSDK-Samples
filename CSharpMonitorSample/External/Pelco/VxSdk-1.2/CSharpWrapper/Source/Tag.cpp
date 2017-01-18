/// <summary>
/// Implements the tag class.
/// </summary>

#include "Device.h"
#include "Tag.h"
#include "User.h"

using namespace System::Collections::Generic;

CPPCli::Tag::Tag(VxSdk::IVxTag* vxTag) {
    _tag = vxTag;
}

CPPCli::Tag::!Tag() {
    _tag->Delete();
    _tag = nullptr;
}

CPPCli::Results::Value CPPCli::Tag::Link(List<CPPCli::DataSource^>^ dataSources) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of data sources
    for (int i = 0; i < dataSources->Count; i++) {
        // Link the data sources to the tag
        result = _tag->Link(*dataSources[i]->_dataSource);
    }

    // Unless there was an issue linking the data sources the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Tag::Link(List<CPPCli::Device^>^ devices) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of devices
    for (int i = 0; i < devices->Count; i++) {
        // Link the devices to the tag
        result = _tag->Link(*devices[i]->_device);
    }

    // Unless there was an issue linking the devices the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Tag::Merge(CPPCli::Tag^ tag) {
    // Make the call to merge this tag into an existing tag
    VxSdk::VxResult::Value result = _tag->Merge(*tag->_tag);
    // Unless there was an issue merging tags the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Tag::Refresh() {
    return (CPPCli::Results::Value)_tag->Refresh();
}

CPPCli::Results::Value CPPCli::Tag::Unlink(List<CPPCli::DataSource^>^ dataSources) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of data sources
    for (int i = 0; i < dataSources->Count; i++) {
        // UnLink the data sources to the tag
        result = _tag->UnLink(*dataSources[i]->_dataSource);
    }

    // Unless there was an issue unlinking the data sources the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Tag::Unlink(List<CPPCli::Device^>^ devices) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of devices
    for (int i = 0; i < devices->Count; i++) {
        // UnLink the devices to the tag
        result = _tag->UnLink(*devices[i]->_device);
    }

    // Unless there was an issue unlinking the devices the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

System::Collections::Generic::List<CPPCli::DataSource^>^ CPPCli::Tag::_GetLinkedDataSources() {
    // Create a list of managed data sources
    List<DataSource^>^ mlist = gcnew List<DataSource^>();
    // Create a collection of unmanaged data sources
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetLinkedDataSources call, which will return with the total data source count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _tag->GetLinks(dataSources);
    // As long as there are data sources linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataSource collection
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _tag->GetLinks(dataSources);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataSources.collectionSize; i++)
                mlist->Add(gcnew DataSource(dataSources.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataSources.collection;
    }
    return mlist;
}

System::Collections::Generic::List<CPPCli::Device^>^ CPPCli::Tag::_GetLinkedDevices() {
    // Create a list of managed devices
    List<Device^>^ mlist = gcnew List<Device^>();
    // Create a collection of unmanaged devices
    VxSdk::VxCollection<VxSdk::IVxDevice**> devices;

    // Make the GetLinkedDevices call, which will return with the total device count, this allows the
    // client to allocate memory.
    VxSdk::VxResult::Value result = _tag->GetLinks(devices);
    // As long as there are devices linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDevice collection
        devices.collection = new VxSdk::IVxDevice*[devices.collectionSize];
        result = _tag->GetLinks(devices);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < devices.collectionSize; i++)
                mlist->Add(gcnew Device(devices.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] devices.collection;
    }
    return mlist;
}

CPPCli::User^ CPPCli::Tag::_GetOwner() {
    // Get the user that owns this tag
    VxSdk::IVxUser* user = nullptr;
    VxSdk::VxResult::Value result = _tag->GetOwner(user);

    // Return the user if GetOwner was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::User(user);

    return nullptr;
}
