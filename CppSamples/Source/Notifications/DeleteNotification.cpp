#include "stdafx.h"
#include "DeleteNotification.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Delete a selected notification from the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Notifications::DeleteNotification::Run(DataModel* dataModel) {
    system("cls");

    VxCollection<IVxNotification**> notifications = GetNotifications(dataModel->VxSystem);
    PrintNotifications(notifications);

    if (notifications.collectionSize > 0) {
        int index = SelectNotificationIndex(notifications);
        if (index >= 0) {
            IVxNotification* notification = notifications.collection[index];
            VxResult::Value result = notification->DeleteNotification();
            if (result == VxResult::kOK)
                cout << "\n" << "Notification deleted succesfully.\n";
            else
                cout << "\n" << "Failed to delete notification!!\n";
        }
    }

    // Remove the memory allocated to the collection.
    delete[] notifications.collection;
    // Pause for user input before going back to parent menu.
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of notifications from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of notifications.</returns>
VxCollection<IVxNotification**> CppSamples::Notifications::DeleteNotification::GetNotifications(IVxSystem* vxSystem) {
    VxCollection<IVxNotification**> notifications;
    // Read the size of collection from system.
    VxResult::Value result = vxSystem->GetNotifications(notifications);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        notifications.collection = new IVxNotification*[notifications.collectionSize];
        // Read the collection from system.
        vxSystem->GetNotifications(notifications);
    }
    return notifications;
}

/// <summary>
/// Prints the given collection of notifications to the screen.
/// </summary>
/// <param name="notificationCollection">Collection of notifications.</param>
void CppSamples::Notifications::DeleteNotification::PrintNotifications(VxCollection<IVxNotification**> notificationCollection) {

    cout << notificationCollection.collectionSize << " notifications found." << "\n";
    if (notificationCollection.collectionSize == 0)
        return;

    cout << "---------------------------------------------------------------------------------------------";
    for (int i = 0; i < notificationCollection.collectionSize; i++) {
        IVxNotification* notification = notificationCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << notification->id;

        // Print Role info associated with notification
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

/// <summary>
/// Select a notification from the given collection by user input.
/// </summary>
/// <param name="notifications">Collection of notification.</param>
/// <returns>Index of the selected notification in the given collection.</returns>
int CppSamples::Notifications::DeleteNotification::SelectNotificationIndex(VxCollection<IVxNotification**> &notifications) {
    while (true) {
        // Select notification number
        int index = 0;
        cout << "\n" << "Enter notification number [1-" << notifications.collectionSize << "] : ";
        cin >> index;
        if (index == 0)
            break;
        // Verify user input
        if (index > 0 && index <= notifications.collectionSize)
            return index - 1;
        else
            cout << "\n" << "Invalid Option !!!";

        cout << "\n" << "Enter 0 to go back.";
    }
    return -1;
}
