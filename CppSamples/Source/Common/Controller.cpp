#include "stdafx.h"
#include "Controller.h"
#include <iostream>
#include "Utility.h"
#include "Constants.h"
#ifdef WIN32
#include <conio.h>
#else
#include <curses.h>
#endif

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Run the selected plugin continously untill it gets a null reference from any plugin.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
void Controller::Run() {

    DataModel* dataModel = Initialize();
    if (dataModel == nullptr)
        return;

    // Set root as the default plugin
    _selectedPlugin = _root;

    // The main loop of the application.
    // Current plugin desides which should be the next plugin to execute.
    while (true) {

        _selectedPlugin = _selectedPlugin->Run(dataModel);

        // If any plugin returns null, the application exits.
        if (_selectedPlugin == nullptr)
            break;
    }

    cout << "\n\n";
#ifdef WIN32
    _getch();
#else
    getch();
#endif
}

// This method initialize the VideoExpert system and
// Creates a new instance of DataModel.
DataModel* Controller::Initialize() {
    // Create Login information structure .
    VxLoginInfo loginInfo;
    loginInfo.port = Constants::kPortnum;
    loginInfo.useSsl = true;
    cout << "\n" << "Enter system IP        : ";
    Utilities::StrCopySafe(loginInfo.ipAddress, Utility::ReadString().c_str());
    cout << "Enter system user name : ";
    Utilities::StrCopySafe(loginInfo.username, Utility::ReadString().c_str());
    cout << "Enter system password  : ";
    Utilities::StrCopySafe(loginInfo.password, Utility::ReadString().c_str());

    IVxSystem* vxSystem = Utility::Login(loginInfo);
    if (vxSystem == nullptr) {
        cout << "Failed to login!!\n";
        return nullptr;
    }

    cout << "Login to VxSDK successfully.\n";

    // Create an instance of DataModel
    DataModel* dataModel = new DataModel();
    dataModel->VxSystem = vxSystem;
    dataModel->username = loginInfo.username;
    dataModel->password = loginInfo.password;

    return dataModel;
}
