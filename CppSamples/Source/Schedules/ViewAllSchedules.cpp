#include "stdafx.h"
#include "ViewAllSchedules.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Print all schedules available in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Schedules::ViewAllSchedules::Run(DataModel* dataModel) {
    Utility::ClearScreen();

    VxCollection<IVxSchedule**> schedules = GetSchedules(dataModel->VxSystem);
    PrintSchedules(schedules);

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Remove the memory allocated to the collection.
    delete[] schedules.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of schedules from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of schedules.</returns>
VxCollection<IVxSchedule**> CppSamples::Schedules::ViewAllSchedules::GetSchedules(IVxSystem* vxSystem) {
    VxCollection<IVxSchedule**> schedules;
    VxResult::Value result = vxSystem->GetSchedules(schedules);
    if (result == VxResult::kInsufficientSize) {
        schedules.collection = new IVxSchedule*[schedules.collectionSize];
        vxSystem->GetSchedules(schedules);
    }
    return schedules;
}

/// <summary>
/// Prints the given collection of schedules to the screen.
/// </summary>
/// <param name="scheduleCollection">Collection of schedules.</param>
void CppSamples::Schedules::ViewAllSchedules::PrintSchedules(VxCollection<IVxSchedule**> scheduleCollection) {

    cout << scheduleCollection.collectionSize << " schedules found." << "\n";
    if (scheduleCollection.collectionSize == 0)
        return;

    cout << "------------------------------------------------------\n";
    cout << "Number\tAction\tTrigger\tName\n";
    cout << "\t\tCount\n";
    cout << "------------------------------------------------------";
    for (int i = 0; i < scheduleCollection.collectionSize; i++) {
        IVxSchedule* schedule = scheduleCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << schedule->action;
        VxCollection<IVxScheduleTrigger**> triggers;
        schedule->GetScheduleTriggers(triggers);
        cout << "\t" << triggers.collectionSize;
        cout << "\t" << schedule->name;
    }
    cout << "\n------------------------------------------------------\n";
}
