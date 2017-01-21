#include "stdafx.h"
#include "DeleteSchedule.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Delete a selected schedule from the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Schedules::DeleteSchedule::Run(DataModel* dataModel) {
    system("cls");

    VxCollection<IVxSchedule**> schedules = GetSchedules(dataModel->VxSystem);
    PrintSchedules(schedules);

    if (schedules.collectionSize > 0) {
        int index = SelectScheduleIndex(schedules);
        if (index >= 0) {
            IVxSchedule* schedule = schedules.collection[index];
            VxResult::Value result = schedule->DeleteSchedule();
            if (result == VxResult::kOK)
                cout << "\n" << "Schedule deleted succesfully.\n";
            else
                cout << "\n" << "Failed to delete schedule!!\n";
        }
    }

    // Remove the memory allocated to the collection.
    delete[] schedules.collection;
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of schedules from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of schedules.</returns>
VxCollection<IVxSchedule**> CppSamples::Schedules::DeleteSchedule::GetSchedules(IVxSystem* vxSystem) {
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
void CppSamples::Schedules::DeleteSchedule::PrintSchedules(VxCollection<IVxSchedule**> scheduleCollection) {

    cout << scheduleCollection.collectionSize << " schedules found." << "\n";
    if (scheduleCollection.collectionSize == 0)
        return;

    cout << "---------------------------------------------------------------------------------------------";
    for (int i = 0; i < scheduleCollection.collectionSize; i++) {
        IVxSchedule* schedule = scheduleCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << schedule->id;
        cout << "\t" << schedule->name;
    }
    cout << "\n---------------------------------------------------------------------------------------------\n";
}

/// <summary>
/// Select a schedule from the given collection by user input.
/// </summary>
/// <param name="schedules">Collection of schedule.</param>
/// <returns>Index of the selected schedule in the given collection.</returns>
int CppSamples::Schedules::DeleteSchedule::SelectScheduleIndex(VxCollection<IVxSchedule**> &schedules) {
    while (true) {
        int index = 0;
        cout << "\n" << "Enter schedule number [1-" << schedules.collectionSize << "] : ";
        cin >> index;
        if (index == 0)
            break;
        if (index > 0 && index <= schedules.collectionSize)
            return index - 1;
        else
            cout << "\n" << "Invalid Option !!!";

        cout << "\n" << "Enter 0 to go back.";
    }

    return -1;
}
