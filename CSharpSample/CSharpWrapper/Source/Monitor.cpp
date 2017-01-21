/// <summary>
/// Implements the monitor class.
/// </summary>
#include "Device.h"
#include "Monitor.h"
#include "MonitorCell.h"

using namespace System::Collections::Generic;

CPPCli::Monitor::Monitor(VxSdk::IVxMonitor* vxMonitor) {
    _monitor = vxMonitor;
}

CPPCli::Monitor::!Monitor() {
    _monitor->Delete();
    _monitor = nullptr;
}

CPPCli::Results::Value CPPCli::Monitor::Refresh() {
    return (CPPCli::Results::Value)_monitor->Refresh();
}

CPPCli::Device^ CPPCli::Monitor::_GetHostDevice() {
    // Get the device which hosts this monitor
    VxSdk::IVxDevice* device = nullptr;
    VxSdk::VxResult::Value result = _monitor->GetHostDevice(device);

    // Return the device if GetHostDevice was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew Device(device);

    return nullptr;
}

List<CPPCli::MonitorCell^>^ CPPCli::Monitor::_GetMonitorCells() {
    // Create a list of managed monitor cell objects
    List<MonitorCell^>^ mlist = gcnew List<MonitorCell^>();
    // Create a collection of unmanaged monitor cell objects
    VxSdk::VxCollection<VxSdk::IVxMonitorCell**> monitorCells;

    // Make the call, which will return with the total count of monitor cells, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _monitor->GetMonitorCells(monitorCells);
    // Unless there are no monitor cells on the monitor, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetMonitorCells call
        monitorCells.collection = new VxSdk::IVxMonitorCell*[monitorCells.collectionSize];
        result = _monitor->GetMonitorCells(monitorCells);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < monitorCells.collectionSize; i++)
                mlist->Add(gcnew CPPCli::MonitorCell(monitorCells.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] monitorCells.collection;
    }
    return mlist;
}

List<CPPCli::Monitor::Layouts>^ CPPCli::Monitor::_GetAvailableLayouts() {
    // Create a list of managed layout objects
    List<CPPCli::Monitor::Layouts>^ mlist = gcnew List<CPPCli::Monitor::Layouts>();
    // Create a collection of unmanaged layout objects
    VxSdk::VxCollection<VxSdk::VxCellLayout::Value*> availableLayouts;

    // Make the call, which will return with the total count of available layouts, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _monitor->GetAvailableLayouts(availableLayouts);
    // Unless there are no available layouts for the monitor, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetAvailableLayouts call
        availableLayouts.collection = new VxSdk::VxCellLayout::Value[availableLayouts.collectionSize];
        result = _monitor->GetAvailableLayouts(availableLayouts);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < availableLayouts.collectionSize; i++)
            {
                CPPCli::Monitor::Layouts limit = (CPPCli::Monitor::Layouts)availableLayouts.collection[i];
                mlist->Add(limit);
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] availableLayouts.collection;
    }
    return mlist;
}
