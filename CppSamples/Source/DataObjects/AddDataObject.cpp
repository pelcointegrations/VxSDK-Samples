#include "stdafx.h"
#include "AddDataObject.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Adds a dataObject to the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::DataObjects::AddDataObject::Run(DataModel* dataModel) {

    // Read clientType from input
    cout << "\n\n" << "Enter dataObject client type: ";
    string clientType = "";
    cin >> clientType;

    // Add DataObject
    VxNewDataObject dataObject;
    Utilities::StrCopySafe(dataObject.data, clientType.c_str(), clientType.size());

    // Make the call to add the dataObject into VideoXpert
    VxResult::Value result = dataModel->VxSystem->AddDataObject(dataObject);
    if (result == VxResult::kOK)
        cout << "\n" << "DataObject added succesfully.\n";
    else
        cout << "\n" << "Failed to add dataObject.\n";

    // Pause for user input before going back to parent menu.
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}
