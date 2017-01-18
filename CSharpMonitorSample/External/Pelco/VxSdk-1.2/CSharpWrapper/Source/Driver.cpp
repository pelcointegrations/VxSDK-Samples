/// <summary>
/// Implements the driver class.
/// </summary>
#include "Driver.h"
#include "DataStorage.h"

using namespace System::Collections::Generic;

CPPCli::Driver::Driver(VxSdk::IVxDriver* vxDriver) {
    _driver = vxDriver;
}

CPPCli::Driver::!Driver() {
    _driver->Delete();
    _driver = nullptr;
}

CPPCli::Results::Value CPPCli::Driver::Refresh() {
    return (CPPCli::Results::Value)_driver->Refresh();
}

CPPCli::DataStorage^ CPPCli::Driver::_GetDataStorage() {
    // Get the data storage which hosts this driver
    VxSdk::IVxDataStorage* dataStorage = nullptr;
    VxSdk::VxResult::Value result = _driver->GetDataStorage(dataStorage);

    // Return the device if GetDataStorage was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::DataStorage(dataStorage);

    return nullptr;
}
