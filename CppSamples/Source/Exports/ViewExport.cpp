#include "stdafx.h"
#include "ViewExport.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

// Print all exports available in the current system.
Plugin* CppSamples::Exports::ViewExport::Run(DataModel* dataModel) {
    system("cls");

    // Get a collection of exports from the system
    VxCollection<IVxExport**> exportCollection = GetExports(dataModel->VxSystem);
    // Display the details of exports in the collection on screen.
    DisplayExportDetailsOnScreen(exportCollection);

    cout << "\n\n";
    // Pause for user input before going back to parent menu.
    system("pause");
    // Remove the memory allocated to the collection.
    delete[] exportCollection.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

// Prints the given collection of exports to the screen.
void CppSamples::Exports::ViewExport::DisplayExportDetailsOnScreen(VxCollection<IVxExport**> exportCollection) {
    cout << exportCollection.collectionSize << " exports found.";
    if (exportCollection.collectionSize == 0)
        return;

    // Header Line
    cout << "\n-----------------------------------------------------------------";
    for (int i = 0; i < exportCollection.collectionSize; i++) {
        IVxExport* vxExport = exportCollection.collection[i];
        VxExportStatus::Value expStatus = vxExport->status;

        // Status to string value
        string expStatusInString = "U";
        switch (expStatus) {
        case VxExportStatus::Value::kExporting:
            expStatusInString = "E";
            break;
        case VxExportStatus::Value::kSuccessful:
            expStatusInString = "S";
            break;
        case VxExportStatus::Value::kFailed:
            expStatusInString = "F";
            break;
        case VxExportStatus::Value::kPending:
            expStatusInString = "P";
            break;
        case VxExportStatus::Value::kUnknown:
        default:
            break;
        }

        // Print details of single export
        cout << "\n\t" << (i + 1) << "\t" << vxExport->name << "\t" << expStatusInString;
    }

    // Footer
    cout << "\n-----------------------------------------------------------------";
    cout << "\n  Status: E-Exporting  S-Successful  F-Failed  P-Pending  U-Unknown\n";
}

// Get a collection of exports from the given VideoExpert system.
VxCollection<IVxExport**> CppSamples::Exports::ViewExport::GetExports(IVxSystem* vxSystem) {
    cout << "Fetching exports from system. Please wait...\n";
    // Read the size of collection from system.
    VxCollection<IVxExport**> exports;
    VxResult::Value result = vxSystem->GetExports(exports);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        exports.collection = new IVxExport*[exports.collectionSize];
        // Read the collection from system.
        vxSystem->GetExports(exports);
    }
    return exports;
}
