#include "stdafx.h"
#include <iomanip>
#include "AddSchedule.h"
#include "Utility.h"
#include "OptionSelector.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Adds a schedule to the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Schedules::AddSchedule::Run(DataModel* dataModel) {

    // Create a schedule object and populate its fields using newSchedule
    VxNewSchedule vxSchedule;
    string newGuid = Utility::GetNewGuid();
    Utilities::StrCopySafe(vxSchedule.id, newGuid.c_str());

    // Read name from input
    cout << "\n\n" << "Enter schedule name: ";
    string name = Utility::ReadString();
    Utilities::StrCopySafe(vxSchedule.name, name.c_str());

    // Create instance of OptionSelector and add options to it
    OptionSelector<VxScheduleAction::Value> optionSelector;
    optionSelector.AddItem("Unknown", VxScheduleAction::kUnknown);
    optionSelector.AddItem("Event Source Record", VxScheduleAction::kEventSourceRecord);
    optionSelector.AddItem("Record", VxScheduleAction::kRecord);
    if (!optionSelector.SelectOption(&vxSchedule.action))
        vxSchedule.action = VxScheduleAction::kUnknown;

    vxSchedule.useAllDataSources = true;

    // Make the call to add the schedule into VideoXpert
    VxResult::Value result = dataModel->VxSystem->AddSchedule(vxSchedule);
    // Display result
    if (result == VxResult::kOK)
        cout << "\n" << "Schedule added succesfully.\n";
    else
        cout << "\n" << "Failed to add schedule.\n";

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}
