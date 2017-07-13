#include "stdafx.h"
#include "AddRole.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Adds a role to the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Roles::AddRole::Run(DataModel* dataModel) {

    // Read name from input
    cout << "\n\n" << "Enter role name: ";
    string name = Utility::ReadString();

    // Add Role
    VxResult::Value result = dataModel->VxSystem->AddRole(name.c_str());
    if (result == VxResult::kOK)
        cout << "\n" << "Role added succesfully.\n";
    else
        cout << "\n" << "Failed to add role.\n";

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}
