#include "stdafx.h"
#include "DeleteExport.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

// Deletes an export from the current system.
Plugin* CppSamples::Exports::DeleteExport::Run(DataModel* dataModel) {
    DeleteSingleExport(dataModel->VxSystem);

    cout << "\n\n";
    // Pause for user input before going back to parent menu.
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

// Deletes an export from the current system.
void CppSamples::Exports::DeleteExport::DeleteSingleExport(IVxSystem* vxSystem) {
    // Get all exports from the system
    VxCollection<IVxExport**> exports = GetExports(vxSystem);
    DisplayExportDetailsOnScreen(exports);

    // Validate Collection
    if (exports.collectionSize <= 0)
        return;

    // User selects an export
    int exportIndex;
    cout << "\n" << "Enter index of export to delete [1-" << exports.collectionSize << "] : ";
    cin >> exportIndex;

    // Validate user input
    if (exportIndex < 1 || exportIndex >= exports.collectionSize)
        return;

    // Print details of selected export to delete
    IVxExport* vxExport = exports.collection[exportIndex - 1];
    cout << "\n" << "Name of the export you selected for delete : " << vxExport->name;

    // Delete the export
    VxResult::Value result = vxExport->DeleteExport();
    if (result == VxResult::kOK)
        cout << "\n" << "Export deleted succesfully.\n";
    else
        cout << "\n" << "Failed to delete export!!\n";

    // Remove the memory allocated to the collection.
    delete[] exports.collection;
}

// Prints the given collection of exports to the screen.
void CppSamples::Exports::DeleteExport::DisplayExportDetailsOnScreen(VxCollection<IVxExport**> exportCollection) {
    cout << "\n" << exportCollection.collectionSize << " exports found.";
    if (exportCollection.collectionSize == 0)
        return;

    // Header Line
    cout << "\n-----------------------------------------------------------------";
    for (int i = 0; i < exportCollection.collectionSize; i++) {
        IVxExport* vxExport = exportCollection.collection[i];

        // Status to string value
        VxExportStatus::Value expStatus = vxExport->status;
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
VxCollection<IVxExport**> CppSamples::Exports::DeleteExport::GetExports(IVxSystem* vxSystem) {
    cout << "\n\n" << "Fetching exports from system. Please wait...\n";
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
