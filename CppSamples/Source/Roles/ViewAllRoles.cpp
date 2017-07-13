#include "stdafx.h"
#include "ViewAllRoles.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Print all roles available in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Roles::ViewAllRoles::Run(DataModel* dataModel) {
    Utility::ClearScreen();

    VxCollection<IVxRole**> roles = GetRoles(dataModel->VxSystem);
    PrintRoles(roles);

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Remove the memory allocated to the collection.
    delete[] roles.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of roles from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of roles.</returns>
VxCollection<IVxRole**> CppSamples::Roles::ViewAllRoles::GetRoles(IVxSystem* vxSystem) {
    VxCollection<IVxRole**> roles;
    VxResult::Value result = vxSystem->GetRoles(roles);
    if (result == VxResult::kInsufficientSize) {
        roles.collection = new IVxRole*[roles.collectionSize];
        vxSystem->GetRoles(roles);
    }
    return roles;
}

/// <summary>
/// Prints the given collection of roles to the screen.
/// </summary>
/// <param name="roleCollection">Collection of roles.</param>
void CppSamples::Roles::ViewAllRoles::PrintRoles(VxCollection<IVxRole**> roleCollection) {
    cout << roleCollection.collectionSize << " roles found." << "\n";
    if (roleCollection.collectionSize == 0)
        return;

    cout << "---------------------------------------------------------------------------------------------";
    for (int i = 0; i < roleCollection.collectionSize; i++) {
        IVxRole* role = roleCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << role->id;
        cout << "\t" << role->name;
    }
    cout << "\n---------------------------------------------------------------------------------------------\n";
}
