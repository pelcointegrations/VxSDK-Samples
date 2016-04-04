/// <summary>
/// Implements the device assignment class.
/// </summary>
#include "Device.h"
#include "DataStorage.h"

using namespace System::Collections::Generic;

CPPCli::DeviceAssignment::DeviceAssignment(VxSdk::IVxDeviceAssignment* vxDeviceAssignment) {
    _deviceAssignment = vxDeviceAssignment;
}

CPPCli::DeviceAssignment::!DeviceAssignment() {
    _deviceAssignment->Delete();
    _deviceAssignment = nullptr;
}

List<CPPCli::DataSource^>^ CPPCli::DeviceAssignment::_GetDataSources() {
    // Create a list of managed data source objects
    List<CPPCli::DataSource^>^ mlist = gcnew List<CPPCli::DataSource^>();
    // Create a collection of unmanaged data source objects
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetDataSources call, which will return with the total count of data sources, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _deviceAssignment->GetDataSources(dataSources);
    // Unless there are no data sources on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetDataSources call
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _deviceAssignment->GetDataSources(dataSources);
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

CPPCli::DataStorage^ CPPCli::DeviceAssignment::_GetDataStorage() {
    // Get the data storage object
    VxSdk::IVxDataStorage* dataStorage = nullptr;
    VxSdk::VxResult::Value result = _deviceAssignment->GetDataStorage(dataStorage);

    // Return the data storage if GetDataStorage was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::DataStorage(dataStorage);

    return nullptr;
}

CPPCli::Device^ CPPCli::DeviceAssignment::_GetDevice() {
    // Get the device object
    VxSdk::IVxDevice* device = nullptr;
    VxSdk::VxResult::Value result = _deviceAssignment->GetDevice(device);

    // Return the device if GetDevice was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::Device(device);

    return nullptr;
}

CPPCli::Driver^ CPPCli::DeviceAssignment::_GetDriver() {
    // Get the driver object
    VxSdk::IVxDriver* driver = nullptr;
    VxSdk::VxResult::Value result = _deviceAssignment->GetDriver(driver);

    // Return the driver if GetDriver was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::Driver(driver);

    return nullptr;
}
