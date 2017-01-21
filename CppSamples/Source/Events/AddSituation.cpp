#include "stdafx.h"
#include "AddSituation.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Adds a situation to the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Events::AddSituation::Run(DataModel* dataModel) {

    AddNewSituation(dataModel->VxSystem);

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Add a new situation to server.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
void CppSamples::Events::AddSituation::AddNewSituation(IVxSystem* vxSystem) {

    string sitName = "";
    string sitType = "";

    cout << "\n\n" << "Enter name for situation: ";
    cin >> sitName;

    cout << "\n" << "Enter type for situation (in format: 'external/{company_name}/{situation_type}'): ";
    cin >> sitType;

    VxNewSituation situation;
    situation.Default();
    strncpy_s(situation.name, sitName.c_str(), sizeof situation.name);
    strncpy_s(situation.type, sitType.c_str(), sizeof situation.type);

    VxResult::Value result = vxSystem->AddSituation(situation);
    if (result == VxResult::kOK)
        cout << "\n" << "Situation added succesfully.\n";
    else
        cout << "\n" << "Failed to add situation.\n";

    // Remove the memory allocated to the collection.
    delete[] situation.snoozeIntervals;

    system("pause");
}
