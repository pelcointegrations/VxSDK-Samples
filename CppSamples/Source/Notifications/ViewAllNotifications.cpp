#include "stdafx.h"
#include "ViewAllNotifications.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Print all notifications available in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Notifications::ViewAllNotifications::Run(DataModel* dataModel) {
    Utility::ClearScreen();

    VxCollection<IVxNotification**> notifications = GetNotifications(dataModel->VxSystem);
    PrintNotifications(notifications);

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Remove the memory allocated to the collection.
    delete[] notifications.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of notifications from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of notifications.</returns>
VxCollection<IVxNotification**> CppSamples::Notifications::ViewAllNotifications::GetNotifications(IVxSystem* vxSystem) {
    VxCollection<IVxNotification**> notifications;
    VxResult::Value result = vxSystem->GetNotifications(notifications);
    if (result == VxResult::kInsufficientSize) {
        notifications.collection = new IVxNotification*[notifications.collectionSize];
        vxSystem->GetNotifications(notifications);
    }
    return notifications;
}

/// <summary>
/// Prints the given collection of notifications to the screen.
/// </summary>
/// <param name="notificationCollection">Collection of notifications.</param>
void CppSamples::Notifications::ViewAllNotifications::PrintNotifications(VxCollection<IVxNotification**> notificationCollection) {

    cout << notificationCollection.collectionSize << " notifications found." << "\n";
    if (notificationCollection.collectionSize == 0)
        return;

    cout << "---------------------------------------------------------------------------------------------";
    for (int i = 0; i < notificationCollection.collectionSize; i++) {
        IVxNotification* notification = notificationCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << notification->id;

        VxCollection<IVxRole**> roles;
        VxResult::Value result = notification->GetRoles(roles);
        if (result == VxResult::kInsufficientSize) {
            roles.collection = new IVxRole*[roles.collectionSize];
            notification->GetRoles(roles);
        }
        cout << "\t" << roles.collectionSize << " role(s) associated with this.";
        for (int j = 0; j < roles.collectionSize; j++)
            cout << "\n\t\t" << (i + 1) << "." << (j + 1) << "\t" << roles.collection[j]->name;
    }
    cout << "\n---------------------------------------------------------------------------------------------\n";
}
