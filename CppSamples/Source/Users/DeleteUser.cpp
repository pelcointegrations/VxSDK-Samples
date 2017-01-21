#include "stdafx.h"
#include "DeleteUser.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Delete a selected user from the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Users::DeleteUser::Run(DataModel* dataModel) {
    system("cls");

    VxCollection<IVxUser**> users = GetUsers(dataModel->VxSystem);
    PrintUsers(users);

    if (users.collectionSize > 0) {
        int index = SelectUserIndex(users);
        if (index >= 0) {
            IVxUser* user = users.collection[index];
            VxResult::Value result = user->DeleteUser();
            if (result == VxResult::kOK)
                cout << "\n" << "User deleted succesfully.\n";
            else
                cout << "\n" << "Failed to delete user!!\n";
        }
    }

    // Remove the memory allocated to the collection.
    delete[] users.collection;
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of users from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of users.</returns>
VxCollection<IVxUser**> CppSamples::Users::DeleteUser::GetUsers(IVxSystem* vxSystem) {
    VxCollection<IVxUser**> users;
    VxResult::Value result = vxSystem->GetUsers(users);
    if (result == VxResult::kInsufficientSize) {
        users.collection = new IVxUser*[users.collectionSize];
        vxSystem->GetUsers(users);
    }
    return users;
}

/// <summary>
/// Prints the given collection of users to the screen.
/// </summary>
/// <param name="userCollection">Collection of users.</param>
void CppSamples::Users::DeleteUser::PrintUsers(VxCollection<IVxUser**> userCollection) {

    cout << userCollection.collectionSize << " users found." << "\n";
    if (userCollection.collectionSize == 0)
        return;

    cout << "---------------------------------------------------------------------------------------------";
    for (int i = 0; i < userCollection.collectionSize; i++) {
        IVxUser* user = userCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << user->id;
        cout << "\t" << user->name;
        cout << "\t" << user->domain;
    }
    cout << "\n---------------------------------------------------------------------------------------------\n";
}

/// <summary>
/// Select a user from the given collection by user input.
/// </summary>
/// <param name="users">Collection of user.</param>
/// <returns>Index of the selected user in the given collection.</returns>
int CppSamples::Users::DeleteUser::SelectUserIndex(VxCollection<IVxUser**> &users) {
    while (true) {
        int index = 0;
        cout << "\n" << "Enter user number [1-" << users.collectionSize << "] : ";
        cin >> index;
        if (index == 0)
            break;
        if (index > 0 && index <= users.collectionSize)
            return index - 1;
        else
            cout << "\n" << "Invalid Option !!!";

        cout << "\n" << "Enter 0 to go back.";
    }

    return -1;
}
