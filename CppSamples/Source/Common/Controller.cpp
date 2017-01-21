#include "stdafx.h"
#include "Controller.h"
#include <iostream>
#include <conio.h>
#include "Utility.h"

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

    cout << "\n\n" << "Have a nice day...";
    _getch();
}

// This method initialize the VideoExpert system and
// Creates a new instance of DataModel.
DataModel* Controller::Initialize() {
    // Initialize VxSDK
    cout << "Initializing VxSDK...\n";
    if (!Utility::Init()) {
        cout << "Failed to initialize the VxSDK. Verify the SDK key.\n";
        return nullptr;
    }

    // Login to Server and create an instance of VxSystem
    cout << "Connecting to system...\n";
    IVxSystem* vxSystem = Utility::Login();
    if (vxSystem == nullptr) {
        cout << "Failed to login!!\n";
        return nullptr;
    }

    cout << "Login to VxSDK successfully.";

    // Create an instance of DataModel
    DataModel* dataModel = new DataModel();
    dataModel->VxSystem = vxSystem;

    return dataModel;
}
