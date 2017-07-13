#include "stdafx.h"
#include "InjectEvents.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

Plugin* CppSamples::Events::InjectEvents::Run(DataModel* dataModel) {

    Inject(dataModel->VxSystem);

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Menu function for deleting situation from server
/// </summary>
/// <param name="vxSystem">system pointer</param>
void CppSamples::Events::InjectEvents::Inject(IVxSystem* vxSystem) {

    // Get all situations from the system
    cout << "\n\n" << "Fetching situations from system..Please wait..\n";
    VxCollection<IVxSituation**> situations = GetSituations(vxSystem);
    DisplaySituationDetailsOnScreen(situations);

    // User selects a situation
    cout << "\n" << "Enter the id of the situation to be associated with the event [1-" << situations.collectionSize << "] : ";
    int situationId = Utility::ReadInt();

    if (situationId < 1 || situationId > situations.collectionSize) {
        cout << "\n" << "Invalid option is given.";
        return;
    }

    // Print details of selected situation
    IVxSituation* situation = situations.collection[situationId - 1];
    cout << "\n" << "Situation selected to insert is:" << situation->type << "\n";

    // Read generator Device ID
    cout << "\n" << "Enter generator device id: ";
    string generatorDeviceId = Utility::ReadString();

    // Read source Device ID
    cout << "\n" << "Enter source device id: ";
    string sourceDeviceId = Utility::ReadString();

    // Read event time
    cout << "\n" << "Enter event time(yyyy-mm-dd hh:mm:ss): ";
    struct tm strtTime = Utility::GetDateAndTimeFromUser();
    string startTimeInUTC = Utility::ConvertLocalTimetoUTC(strtTime);

    // Create new instance of event structure and set the user inputs to it.
    VxNewEvent newEvent;
    Utilities::StrCopySafe(newEvent.situationType, situation->type);
    Utilities::StrCopySafe(newEvent.generatorDeviceId, generatorDeviceId.c_str());
    Utilities::StrCopySafe(newEvent.sourceDeviceId, sourceDeviceId.c_str());
    Utilities::StrCopySafe(newEvent.time, startTimeInUTC.c_str());

    // Insert the new event to the system.
    VxResult::Value result = vxSystem->InsertEvent(newEvent);
    if (result == VxResult::kOK)
        cout << "\n" << "Succesfully injected new event.\n";
    else
        cout << "\n" << "Failed to inject event.\n";
}

// Get a collection of situations from the given VideoExpert system.
VxCollection<IVxSituation**> CppSamples::Events::InjectEvents::GetSituations(IVxSystem* vxSystem) {

    // Read the size of collection from system.
    VxCollection<IVxSituation**> situations;
    VxResult::Value result = vxSystem->GetSituations(situations);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        situations.collection = new IVxSituation*[situations.collectionSize];
        // Read the collection from system.
        result = vxSystem->GetSituations(situations);
    }

    return situations;
}

/// <summary>
/// Method for displaying situation details
/// </summary>
/// <param name="situations">Situations list to iterate</param>
void CppSamples::Events::InjectEvents::DisplaySituationDetailsOnScreen(VxCollection<IVxSituation**> situations) {

    if (situations.collectionSize > 0) {
        cout << situations.collectionSize << " situations found.\n";

        cout << "\n\n";
        cout << setfill(' ') << "  INDEX         " << setw(60) << left << "  TYPE" << "\n";
        cout << "\n--------------------------------------------------\n";

        int index = 0;
        for (int i = 0; i < situations.collectionSize; i++) {
            IVxSituation* situation = situations.collection[i];
            cout << setfill(' ') << "\n\t" << index + 1 << "\t" << left << setw(60) << left << situation->type;
            index++;
        }
        cout << "\n--------------------------------------------------\n";
    }
    else
        cout << "No situations found!!\n";
}
