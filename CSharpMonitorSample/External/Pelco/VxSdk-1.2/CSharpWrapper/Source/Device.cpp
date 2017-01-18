/// <summary>
/// Implements the device class.
/// </summary>
#include "Device.h"

using namespace System::Collections::Generic;

CPPCli::Device::Device(VxSdk::IVxDevice* vxDevice) {
    _device = vxDevice;
}

CPPCli::Device::!Device() {
    _device->Delete();
    _device = nullptr;
}

CPPCli::Results::Value CPPCli::Device::Refresh() {
    return (CPPCli::Results::Value)_device->Refresh();
}

List<CPPCli::DataSource^>^ CPPCli::Device::_GetDataSources() {
    // Create a list of managed data source objects
    List<DataSource^>^ mlist = gcnew List<DataSource^>();
    // Create a collection of unmanaged data source objects
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetDataSources call, which will return with the total count of data sources, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _device->GetDataSources(dataSources);
    // Unless there are no data sources on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetDataSources call
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _device->GetDataSources(dataSources);
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

List<CPPCli::DeviceAssignment^>^ CPPCli::Device::_GetDeviceAssignments() {
    // Create a list of managed device assignment objects
    List<DeviceAssignment^>^ mlist = gcnew List<DeviceAssignment^>();
    // Create a collection of unmanaged device assignment objects
    VxSdk::VxCollection<VxSdk::IVxDeviceAssignment**> deviceAssignments;

    // Make the GetDeviceAssignments call, which will return with the total count of device assignments, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _device->GetDeviceAssignments(deviceAssignments);
    // Unless there are no device assignments on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetDeviceAssignments call
        deviceAssignments.collection = new VxSdk::IVxDeviceAssignment*[deviceAssignments.collectionSize];
        result = _device->GetDeviceAssignments(deviceAssignments);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < deviceAssignments.collectionSize; i++)
                mlist->Add(gcnew CPPCli::DeviceAssignment(deviceAssignments.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] deviceAssignments.collection;
    }
    return mlist;
}
