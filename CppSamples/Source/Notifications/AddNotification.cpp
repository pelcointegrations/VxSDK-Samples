#include "stdafx.h"
#include "AddNotification.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Adds a notification to the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Notifications::AddNotification::Run(DataModel* dataModel) {
    // Get a list of selected roles from the system
    vector<string> roleIds = GetSelectedRoles(dataModel->VxSystem);

    // Create a notification object and populate its fields using newNotification
    VxNewNotification vxNotification;
    vxNotification.roleIdSize = static_cast<int>(roleIds.size());
    if (vxNotification.roleIdSize > 0) {
        // Allocate memory for the role Ids.
        vxNotification.roleIds = new char*[vxNotification.roleIdSize];
        for (int i = 0; i < vxNotification.roleIdSize; i++) {
            string roleId = roleIds[i];
            vxNotification.roleIds[i] = new char[roleId.size() + 1];
            Utilities::StrCopySafe(vxNotification.roleIds[i], roleId.c_str(), roleId.size() + 1);
        }
    }

    // Make the call to add the notification into VideoXpert
    IVxNotification* notificationItem = nullptr;
    VxResult::Value result = dataModel->VxSystem->AddNotification(vxNotification, notificationItem);
    if (result == VxResult::kOK)
        cout << "\n" << "Notification added succesfully.\n";
    else
        cout << "\n" << "Failed to add notification.\n";

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a list of selected roles from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A list of selected roles.</returns>
vector<string> CppSamples::Notifications::AddNotification::GetSelectedRoles(IVxSystem* vxSystem) {

    vector<string> selectedRoles;

    VxCollection<IVxRole**> allRoles = GetRoles(vxSystem);
    for (int i = 0; i < allRoles.collectionSize; i++) {
        IVxRole* role = allRoles.collection[i];

        if (role->isReadOnly && (strcmp(role->name, "administrator") != 0))
            continue;

        cout << "\n" << "Select role (" << role->name<< ") y/n : ";
        string option = Utility::ReadString();
        if (option.size() > 0 && (option[0] == 'y' || option[0] == 'Y')) {
            selectedRoles.push_back(string(role->id));
            cout << role->name << " is selected. \n";
        }
        else
            cout << role->name << " is NOT selected. \n";
    }
    return selectedRoles;
}

/// <summary>
/// Get a collection of roles from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of roles.</returns>
VxCollection<IVxRole**> CppSamples::Notifications::AddNotification::GetRoles(IVxSystem* vxSystem) {
    VxCollection<IVxRole**> roles;
    // Read the size of collection from system.
    VxResult::Value result = vxSystem->GetRoles(roles);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        roles.collection = new IVxRole*[roles.collectionSize];
        // Read the collection from system.
        vxSystem->GetRoles(roles);
    }
    return roles;
}
