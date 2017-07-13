#include "stdafx.h"
#include "ViewAllDataObjects.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Print all dataObjects available in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::DataObjects::ViewAllDataObjects::Run(DataModel* dataModel) {
    Utility::ClearScreen();

    VxCollection<IVxDataObject**> dataObjects = GetDataObjects(dataModel->VxSystem);
    PrintDataObjects(dataObjects);

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Remove the memory allocated to the collection.
    delete[] dataObjects.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of dataObjects from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of dataObjects.</returns>
VxCollection<IVxDataObject**> CppSamples::DataObjects::ViewAllDataObjects::GetDataObjects(IVxSystem* vxSystem) {
    VxCollection<IVxDataObject**> dataObjects;
    VxResult::Value result = vxSystem->GetDataObjects(dataObjects);
    if (result == VxResult::kInsufficientSize) {
        dataObjects.collection = new IVxDataObject*[dataObjects.collectionSize];
        vxSystem->GetDataObjects(dataObjects);
    }
    return dataObjects;
}

/// <summary>
/// Prints the given collection of dataObjects to the screen.
/// </summary>
/// <param name="dataObjectCollection">Collection of dataObjects.</param>
void CppSamples::DataObjects::ViewAllDataObjects::PrintDataObjects(VxCollection<IVxDataObject**> dataObjectCollection) {
    cout << dataObjectCollection.collectionSize << " dataObjects found." << "\n";
    if (dataObjectCollection.collectionSize == 0)
        return;

    cout << "---------------------------------------------------------------------------------------------";
    for (int i = 0; i < dataObjectCollection.collectionSize; i++) {
        IVxDataObject* dataObject = dataObjectCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << dataObject->id;
        cout << "\t" << dataObject->owner;
        cout << "\t" << dataObject->clientType;
    }
    cout << "\n---------------------------------------------------------------------------------------------\n";
}
