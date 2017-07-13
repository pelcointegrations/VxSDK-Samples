#include "stdafx.h"
#include <iomanip>
#include "AddTriggerToSchedule.h"
#include "Utility.h"
#include "OptionSelector.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Creates a trigger and add it to a selected schedule in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Schedules::AddTriggerToSchedule::Run(DataModel* dataModel) {
    cout << "\n";
    VxCollection<IVxSchedule**> schedules = GetSchedules(dataModel->VxSystem);
    OptionSelector<IVxSchedule*> optionSelector;
    optionSelector.Heading = "Select a schedule to add trigger";
    for (int i = 0; i < schedules.collectionSize; i++) {
        IVxSchedule* schedule = schedules.collection[i];
        string name = schedule->id + string("\t") + schedule->name;
        optionSelector.AddItem(name, schedule);
    }

    IVxSchedule* selectedSchedule = nullptr;
    if (optionSelector.SelectOption(&selectedSchedule)) {

        // Create a new schedule trigger
        VxNewScheduleTrigger scheduleTrigger;
        string newGuid = Utility::GetNewGuid();
        Utilities::StrCopySafe(scheduleTrigger.id, newGuid.c_str());

        cout << "\n";

        // Start Time
        VxSdk::Utilities::StrCopySafe(scheduleTrigger.dailyStartTime, ReadTime("Enter Start Time ").c_str());

        // End Time
        VxSdk::Utilities::StrCopySafe(scheduleTrigger.dailyEndTime, ReadTime("Enter End Time   ").c_str());

        // Start Date
        VxSdk::Utilities::StrCopySafe(scheduleTrigger.startDate, ReadDate("Enter Start Date ").c_str());

        // End Date
        VxSdk::Utilities::StrCopySafe(scheduleTrigger.endDate, ReadDate("Enter End Date   ").c_str());

        // Framerate
        OptionSelector<VxRecordingFramerate::Value> framerateSelector;
        framerateSelector.Heading = "Select a type of frame rate";
        framerateSelector.AddItem("Log", VxRecordingFramerate::kLow);
        framerateSelector.AddItem("Normal", VxRecordingFramerate::kNormal);
        if (!framerateSelector.SelectOption(&scheduleTrigger.framerate))
            scheduleTrigger.framerate = VxRecordingFramerate::kUnknown;

        // Event 
        cout << "\n";
        OptionSelector<VxSituationType::Value> eventSelector;
        eventSelector.Heading = "\nSelect a type of event";
        eventSelector.AddItem("AlarmActive", VxSituationType::kAlarmActive);
        eventSelector.AddItem("AlarmInactive", VxSituationType::kAlarmInactive);
        eventSelector.AddItem("Motion", VxSituationType::kMotion);
        eventSelector.AddItem("NoMotion", VxSituationType::kNoMotion);
        if (!eventSelector.SelectOption(&scheduleTrigger.event))
            scheduleTrigger.event = VxSituationType::kUnknown;

        // Recurrence
        cout << "\n";
        OptionSelector<VxRecurrenceType::Value> recurrenceSelector;
        recurrenceSelector.Heading = "\nSelect a type of recurrence";
        recurrenceSelector.AddItem("Daily", VxRecurrenceType::kDaily);
        recurrenceSelector.AddItem("Monthly", VxRecurrenceType::kMonthly);
        recurrenceSelector.AddItem("Weekly", VxRecurrenceType::kWeekly);
        recurrenceSelector.AddItem("Yearly", VxRecurrenceType::kYearly);
        if (!recurrenceSelector.SelectOption(&scheduleTrigger.recurrence))
            scheduleTrigger.recurrence = VxRecurrenceType::kUnknown;

        // PreTrigger
        cout << "\n" << "Enter PreTrigger value      : ";
        scheduleTrigger.preTrigger = Utility::ReadInt();

        // PostTrigger
        cout << "Enter PostTrigger value     : ";
        scheduleTrigger.postTrigger = Utility::ReadInt();

        // Timeout
        cout << "Enter Timeout Duration      : ";
        scheduleTrigger.timeout = Utility::ReadInt();

        // Make the call to add the schedule into VideoXpert
        VxResult::Value result = selectedSchedule->AddScheduleTrigger(scheduleTrigger);
        if (result == VxResult::kOK)
            cout << "\n" << "Schedule added succesfully.\n";
        else
            cout << "\n" << "Failed to add schedule.\n";
    }

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of schedules from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of schedules.</returns>
VxCollection<IVxSchedule**> CppSamples::Schedules::AddTriggerToSchedule::GetSchedules(IVxSystem* vxSystem) {
    VxCollection<IVxSchedule**> schedules;
    VxResult::Value result = vxSystem->GetSchedules(schedules);
    if (result == VxResult::kInsufficientSize) {
        schedules.collection = new IVxSchedule*[schedules.collectionSize];
        vxSystem->GetSchedules(schedules);
    }
    return schedules;
}

/// <summary>
/// Reads a time from user input
/// </summary>
/// <param name="message">Message to be printed while before reading time</param>
string CppSamples::Schedules::AddTriggerToSchedule::ReadTime(string message) {
    cout << message << "(HH:MM:SS) : ";
    string utcFormat = Utility::ReadString();

    std::stringstream dateStream(utcFormat);
    struct tm parseTime;
    //Here parse time string value to time structure
    dateStream >> std::get_time(&parseTime, "%H:%M:%S");

    parseTime.tm_mday = 1;
    parseTime.tm_mon = 0;
    parseTime.tm_year = 0;

    char buffer[9];
    strftime(buffer, 9, "%X", &parseTime);

    return string(buffer);
}

/// <summary>
/// Reads a date from user input in DD-MM-YY format.
/// </summary>
/// <param name="message">Message to be printed while before reading date</param>
string CppSamples::Schedules::AddTriggerToSchedule::ReadDate(string message) {
    cout << message << "(dd-mm-yy) : ";
    string utcFormat = Utility::ReadString();

    std::stringstream dateStream(utcFormat);
    struct tm parseDate;
    //Here parse date string value to date structure
    dateStream >> std::get_time(&parseDate, "%d-%m-%Y");

    parseDate.tm_hour = 0;
    parseDate.tm_min = 0;
    parseDate.tm_sec = 0;

    char buffer[9];
    strftime(buffer, 9, "%x", &parseDate);

    return string(buffer);
}
