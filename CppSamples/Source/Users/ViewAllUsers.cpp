#include "stdafx.h"
#include "ViewAllUsers.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Print all users available in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Users::ViewAllUsers::Run(DataModel* dataModel) {
    system("cls");

    VxCollection<IVxUser**> users = GetUsers(dataModel->VxSystem);
    PrintUsers(users);

    system("pause");
    // Remove the memory allocated to the collection.
    delete[] users.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of users from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of users.</returns>
VxCollection<IVxUser**> CppSamples::Users::ViewAllUsers::GetUsers(IVxSystem* vxSystem) {
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
void CppSamples::Users::ViewAllUsers::PrintUsers(VxCollection<IVxUser**> userCollection) {

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
