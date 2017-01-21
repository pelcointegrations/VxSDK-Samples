/// <summary>
/// Implements the data storage class.
/// </summary>
#include "DataStorage.h"

using namespace System::Collections::Generic;

CPPCli::DataStorage::DataStorage(VxSdk::IVxDataStorage* vxDataStorage) {
    _dataStorage = vxDataStorage;
}

CPPCli::DataStorage::!DataStorage() {
    _dataStorage->Delete();
    _dataStorage = nullptr;
}

CPPCli::Results::Value CPPCli::DataStorage::AssignDevice(CPPCli::NewDeviceAssignment^ newDeviceAssignment) {
    // Create a new device assignment object and populate its fields using newDeviceAssignment
    VxSdk::VxNewDeviceAssignment vxNewDeviceAssignment;
    VxSdk::Utilities::StrCopySafe(vxNewDeviceAssignment.deviceId, Utils::ConvertSysString(newDeviceAssignment->DeviceId));
    VxSdk::Utilities::StrCopySafe(vxNewDeviceAssignment.driverType, Utils::ConvertSysString(newDeviceAssignment->DriverType));
    int size = newDeviceAssignment->DataSourceIds->Count;

    vxNewDeviceAssignment.dataSourceIdSize = size;
    vxNewDeviceAssignment.dataSourceIds = new char*[size];
    for (int i = 0; i < size; i++) {
        int idLength = newDeviceAssignment->DataSourceIds[i]->Length + 1;
        vxNewDeviceAssignment.dataSourceIds[i] = new char[idLength];
        VxSdk::Utilities::StrCopySafe(vxNewDeviceAssignment.dataSourceIds[i], Utils::ConvertSysString(newDeviceAssignment->DataSourceIds[i]), idLength);
    }

    // Make the call to add the situation into VideoXpert
    VxSdk::VxResult::Value result = _dataStorage->AssignDevice(vxNewDeviceAssignment);
    // Unless there was an issue adding the situation the result should be VxSdk::VxResult::kOK
    if (result == VxSdk::VxResult::kOK) {
        // Remove the memory we previously allocated
        delete[] vxNewDeviceAssignment.dataSourceIds;
    }
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::DataStorage::Refresh() {
    return (CPPCli::Results::Value)_dataStorage->Refresh();
}

CPPCli::Results::Value CPPCli::DataStorage::UnassignDevice(CPPCli::Device^ device) {
    // Create an IVxDevice object using the device
    VxSdk::IVxDevice* delDevice = device->_device;

    // Call UnassignDevice using the IVxDevice object
    VxSdk::VxResult::Value result = _dataStorage->UnassignDevice(*delDevice);
    // Unless there was an issue unassigning the device the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<CPPCli::DataSource^>^ CPPCli::DataStorage::_GetDataSources() {
    // Create a list of managed data source objects
    List<DataSource^>^ mlist = gcnew List<DataSource^>();
    // Create a collection of unmanaged data source objects
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetDataSources call, which will return with the total count of data sources, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataStorage->GetDataSources(dataSources);
    // Unless there are no data sources on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetDataSources call
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _dataStorage->GetDataSources(dataSources);
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

List<CPPCli::DeviceAssignment^>^ CPPCli::DataStorage::_GetDeviceAssignments() {
    // Create a list of managed device assignment objects
    List<DeviceAssignment^>^ mlist = gcnew List<DeviceAssignment^>();
    // Create a collection of unmanaged device assignment objects
    VxSdk::VxCollection<VxSdk::IVxDeviceAssignment**> deviceAssignments;

    // Make the GetDeviceAssignments call, which will return with the total count of device assignments, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataStorage->GetDeviceAssignments(deviceAssignments);
    // Unless there are no device assignments on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetDeviceAssignments call
        deviceAssignments.collection = new VxSdk::IVxDeviceAssignment*[deviceAssignments.collectionSize];
        result = _dataStorage->GetDeviceAssignments(deviceAssignments);
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

List<CPPCli::Driver^>^ CPPCli::DataStorage::_GetDrivers() {
    // Create a list of managed driver objects
    List<Driver^>^ mlist = gcnew List<Driver^>();
    // Create a collection of unmanaged driver objects
    VxSdk::VxCollection<VxSdk::IVxDriver**> drivers;

    // Make the GetDrivers call, which will return with the total count of drivers, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataStorage->GetDrivers(drivers);
    // Unless there are no drivers on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetDrivers call
        drivers.collection = new VxSdk::IVxDriver*[drivers.collectionSize];
        result = _dataStorage->GetDrivers(drivers);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < drivers.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Driver(drivers.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] drivers.collection;
    }
    return mlist;
}

CPPCli::Device^ CPPCli::DataStorage::_GetHostDevice() {
    // Get the device which hosts this data storage
    VxSdk::IVxDevice* device = nullptr;
    VxSdk::VxResult::Value result = _dataStorage->GetHostDevice(device);

    // Return the device if GetHostDevice was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew Device(device);

    return nullptr;
}

CPPCli::Configuration::Storage^ CPPCli::DataStorage::_GetStorageConfig() {
    // Get the storage config
    VxSdk::IVxConfiguration::Storage* storageConfig = nullptr;
    VxSdk::VxResult::Value result = _dataStorage->GetStorageConfiguration(storageConfig);

    // Return the storage config if GetStorageConfiguration was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::Configuration::Storage(storageConfig);

    return nullptr;
}
