#include "stdafx.h"
#include "DeleteRole.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Delete a selected role from the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Roles::DeleteRole::Run(DataModel* dataModel) {
    system("cls");

    VxCollection<IVxRole**> roles = GetRoles(dataModel->VxSystem);
    PrintRoles(roles);

    if (roles.collectionSize > 0) {
        int index = SelectRoleIndex(roles);
        if (index >= 0) {
            IVxRole* role = roles.collection[index];
            VxResult::Value result = role->DeleteRole();
            if (result == VxResult::kOK)
                cout << "\n" << "Role deleted succesfully.\n";
            else
                cout << "\n" << "Failed to delete role!!\n";
        }
    }

    // Remove the memory allocated to the collection.
    delete[] roles.collection;
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of roles from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of roles.</returns>
VxCollection<IVxRole**> CppSamples::Roles::DeleteRole::GetRoles(IVxSystem* vxSystem) {
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
void CppSamples::Roles::DeleteRole::PrintRoles(VxCollection<IVxRole**> roleCollection) {

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

/// <summary>
/// Select a role from the given collection by user input.
/// </summary>
/// <param name="roles">Collection of role.</param>
/// <returns>Index of the selected role in the given collection.</returns>
int CppSamples::Roles::DeleteRole::SelectRoleIndex(VxCollection<IVxRole**> &roles) {
    while (true) {
        int index = 0;
        cout << "\n" << "Enter role number [1-" << roles.collectionSize << "] : ";
        cin >> index;
        if (index == 0)
            break;
        if (index > 0 && index <= roles.collectionSize)
            return index - 1;
        else
            cout << "\n" << "Invalid Option !!!";

        cout << "\n" << "Enter 0 to go back.";
    }

    return -1;
}
