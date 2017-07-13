#include "stdafx.h"
#include "ViewAllDevices.h"
#include "Utility.h"
#include "TabularPrinter.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Print all devices available in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Devices::ViewAllDevices::Run(DataModel* dataModel) {
    Utility::ClearScreen();

    VxCollection<IVxDevice**> devices = GetDevices(dataModel->VxSystem);
    PrintDevices(devices);

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Remove the memory allocated to the collection.
    delete[] devices.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of devices from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of devices.</returns>
VxCollection<IVxDevice**> CppSamples::Devices::ViewAllDevices::GetDevices(IVxSystem* vxSystem) {
    VxCollection<IVxDevice**> devices;
    VxResult::Value result = vxSystem->GetDevices(devices);
    if (result == VxResult::kInsufficientSize) {
        devices.collection = new IVxDevice*[devices.collectionSize];
        vxSystem->GetDevices(devices);
    }
    return devices;
}

/// <summary>
/// Prints the given collection of devices to the screen.
/// </summary>
/// <param name="deviceCollection">Collection of devices.</param>
void CppSamples::Devices::ViewAllDevices::PrintDevices(VxCollection<IVxDevice**> deviceCollection) {

    cout << deviceCollection.collectionSize << " devices found." << "\n";
    if (deviceCollection.collectionSize == 0)
        return;

    TabularPrinter tabularPrinter;
    tabularPrinter.AddColumn("No", 5);
    tabularPrinter.AddColumn("Name", 35);
    tabularPrinter.AddColumn("Model", 35);
    tabularPrinter.AddColumn("Status", 8);
    for (int i = 0; i < deviceCollection.collectionSize; i++) {
        IVxDevice* device = deviceCollection.collection[i];

        tabularPrinter.AddRow();
        tabularPrinter.AddCellValue(i + 1);
        tabularPrinter.AddCellValue(device->name);
        tabularPrinter.AddCellValue(device->model);
        tabularPrinter.AddCellValue((device->state == VxDeviceState::kOnline ? "Online " : "Offline"));
    }
    string tableValue = tabularPrinter.ToString();
    cout << tableValue;
}
