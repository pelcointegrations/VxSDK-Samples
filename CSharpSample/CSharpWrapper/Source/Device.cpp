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

List<CPPCli::AlarmInput^>^ CPPCli::Device::_GetAlarmInputs() {
    // Create a list of managed alarm input objects
    List<AlarmInput^>^ mlist = gcnew List<AlarmInput^>();
    // Create a collection of unmanaged alarm input objects
    VxSdk::VxCollection<VxSdk::IVxAlarmInput**> alarmInputs;

    // Make the GetAlarmInputs call, which will return with the total count of alarm inputs, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _device->GetAlarmInputs(alarmInputs);
    // Unless there are no alarm inputs hosted on the device, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetAlarmInputs call
        alarmInputs.collection = new VxSdk::IVxAlarmInput*[alarmInputs.collectionSize];
        result = _device->GetAlarmInputs(alarmInputs);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < alarmInputs.collectionSize; i++)
                mlist->Add(gcnew CPPCli::AlarmInput(alarmInputs.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] alarmInputs.collection;
    }
    return mlist;
}

List<CPPCli::DataSource^>^ CPPCli::Device::_GetDataSources() {
    // Create a list of managed data source objects
    List<DataSource^>^ mlist = gcnew List<DataSource^>();
    // Create a collection of unmanaged data source objects
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetDataSources call, which will return with the total count of data sources, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _device->GetDataSources(dataSources);
    // Unless there are no data sources hosted on the device, this should return VxSdk::VxResult::kInsufficientSize
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
    // Unless there are no device assignments hosted on the device, this should return VxSdk::VxResult::kInsufficientSize
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

List<CPPCli::RelayOutput^>^ CPPCli::Device::_GetRelayOutputs() {
    // Create a list of managed relay output objects
    List<RelayOutput^>^ mlist = gcnew List<RelayOutput^>();
    // Create a collection of unmanaged relay output objects
    VxSdk::VxCollection<VxSdk::IVxRelayOutput**> relayOutputs;

    // Make the GetRelayOutputs call, which will return with the total count of relay outputs, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _device->GetRelayOutputs(relayOutputs);
    // Unless there are no relay outputs hosted on the device, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetRelayOutputs call
        relayOutputs.collection = new VxSdk::IVxRelayOutput*[relayOutputs.collectionSize];
        result = _device->GetRelayOutputs(relayOutputs);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < relayOutputs.collectionSize; i++)
                mlist->Add(gcnew CPPCli::RelayOutput(relayOutputs.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] relayOutputs.collection;
    }
    return mlist;
}
