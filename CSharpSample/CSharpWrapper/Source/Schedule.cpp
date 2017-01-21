/// <summary>
/// Implements the schedule class.
/// </summary>
#include "Schedule.h"

using namespace System::Collections::Generic;

CPPCli::Schedule::Schedule(VxSdk::IVxSchedule* vxSchedule) {
    _schedule = vxSchedule;
}

CPPCli::Schedule::!Schedule() {
    _schedule->Delete();
    _schedule = nullptr;
}

CPPCli::Results::Value CPPCli::Schedule::AddScheduleTrigger(CPPCli::NewScheduleTrigger^ newScheduleTrigger) {
    // Create a new schedule trigger object
    VxSdk::VxNewScheduleTrigger newTrigger;
    VxSdk::Utilities::StrCopySafe(newTrigger.dailyEndTime, Utils::ConvertDateTimeToTimeChar(newScheduleTrigger->DailyEndTime));
    VxSdk::Utilities::StrCopySafe(newTrigger.dailyStartTime, Utils::ConvertDateTimeToTimeChar(newScheduleTrigger->DailyStartTime));
    VxSdk::Utilities::StrCopySafe(newTrigger.endDate, Utils::ConvertDateTimeToChar(newScheduleTrigger->EndDate));
    VxSdk::Utilities::StrCopySafe(newTrigger.startDate, Utils::ConvertDateTimeToChar(newScheduleTrigger->StartDate));
    VxSdk::Utilities::StrCopySafe(newTrigger.id, Utils::ConvertSysString(newScheduleTrigger->Id));
    VxSdk::Utilities::StrCopySafe(newTrigger.eventSourceDevice, Utils::ConvertSysString(newScheduleTrigger->EventSource));
    newTrigger.postTrigger = newScheduleTrigger->PostTrigger;
    newTrigger.preTrigger = newScheduleTrigger->PreTrigger;
    newTrigger.timeout = newScheduleTrigger->Timeout;
    newTrigger.event = VxSdk::VxSituationType::Value(newScheduleTrigger->Event);
    newTrigger.recurrence = VxSdk::VxRecurrenceType::Value(newScheduleTrigger->RecurrenceType);
    newTrigger.framerate = VxSdk::VxRecordingFramerate::Value(newScheduleTrigger->Framerate);

    // Get the weekly interval values
    int weeklySize = newScheduleTrigger->RecurWeekly->Count;
    int *weekIntervals = new int[weeklySize];
    for (int iW = 0; iW < weeklySize; iW++) {
        weekIntervals[iW] = newScheduleTrigger->RecurWeekly[iW];
    }
    // Add any weekly interval values to the new schedule trigger
    newTrigger.recurWeekly = weekIntervals;
    newTrigger.recurWeeklySize = weeklySize;

    // Get the monthly interval values
    int monthlySize = newScheduleTrigger->RecurMonthly->Count;
    int *monthIntervals = new int[monthlySize];
    for (int iM = 0; iM < monthlySize; iM++) {
        monthIntervals[iM] = newScheduleTrigger->RecurMonthly[iM];
    }
    // Add any monthly interval values to the new schedule trigger
    newTrigger.recurMonthly = monthIntervals;
    newTrigger.recurMonthlySize = monthlySize;

    // Get the yearly interval values
    int yearlySize = newScheduleTrigger->RecurYearly->Count;
    int *yearIntervals = new int[yearlySize];
    for (int iY = 0; iY < yearlySize; iY++) {
        yearIntervals[iY] = newScheduleTrigger->RecurYearly[iY];
    }
    // Add any yearly interval values to the new schedule trigger
    newTrigger.recurYearly = yearIntervals;
    newTrigger.recurYearlySize = yearlySize;

    // Add any event properties to the new schedule trigger
    int size = newScheduleTrigger->EventProperties->Count;
    VxSdk::VxKvObject *kvObj = new VxSdk::VxKvObject[size];
    newTrigger.eventPropertySize = size;
    newTrigger.eventProperties = kvObj;
    for (int ii = 0; ii < size; ii++) {
        VxSdk::Utilities::StrCopySafe(newTrigger.eventProperties[ii].key,
            Utils::ConvertSysString(newScheduleTrigger->EventProperties[ii].Key));
        VxSdk::Utilities::StrCopySafe(newTrigger.eventProperties[ii].value,
            Utils::ConvertSysString(newScheduleTrigger->EventProperties[ii].Value));
    }

    // Add the schedule trigger to the schedule
    return CPPCli::Results::Value(_schedule->AddScheduleTrigger(newTrigger));
}

CPPCli::Results::Value CPPCli::Schedule::DeleteScheduleTrigger(CPPCli::ScheduleTrigger^ scheduleTrigger) {
    // Delete the schedule trigger
    return CPPCli::Results::Value(scheduleTrigger->_scheduleTrigger->DeleteScheduleTrigger());
}

List<CPPCli::DataSource^>^ CPPCli::Schedule::GetLinks() {
    // Create a list of managed data source objects
    List<CPPCli::DataSource^>^ mlist = gcnew List<CPPCli::DataSource^>();
    // Create a collection of unmanaged data source objects
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetLinks call, which will return with the total data source count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _schedule->GetLinks(dataSources);
    // The result should be kInsufficientSize if the number of data sources on the system are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataSource collection
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _schedule->GetLinks(dataSources);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataSources.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::DataSource(dataSources.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataSources.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::Schedule::Link(List<CPPCli::DataSource^>^ dataSources) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of data sources
    for (int i = 0; i < dataSources->Count; i++) {
        // Link the data sources to the schedule
        result = _schedule->Link(*dataSources[i]->_dataSource);
    }

    // Unless there was an issue linking the data sources the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}


CPPCli::Results::Value CPPCli::Schedule::Refresh() {
    return (CPPCli::Results::Value)_schedule->Refresh();
}

CPPCli::Results::Value CPPCli::Schedule::Unlink(List<CPPCli::DataSource^>^ dataSources) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of data sources
    for (int i = 0; i < dataSources->Count; i++) {
        // UnLink the data sources to the schedule
        result = _schedule->UnLink(*dataSources[i]->_dataSource);
    }

    // Unless there was an issue unlinking the data sources the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<CPPCli::ScheduleTrigger^>^ CPPCli::Schedule::_GetScheduleTriggers() {
    // Create a list of managed trigger objects
    List<CPPCli::ScheduleTrigger^>^ mlist = gcnew List<CPPCli::ScheduleTrigger^>();
    // Create a collection of unmanaged trigger objects
    VxSdk::VxCollection<VxSdk::IVxScheduleTrigger**> scheduleTriggers;

    // Make the GetScheduleTriggers call, which will return with the total trigger count,
    // this allows the client to allocate memory
    VxSdk::VxResult::Value result = _schedule->GetScheduleTriggers(scheduleTriggers);
    // Unless there are no triggers associated with the schedule, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxScheduleTrigger collection
        scheduleTriggers.collection = new VxSdk::IVxScheduleTrigger*[scheduleTriggers.collectionSize];
        result = _schedule->GetScheduleTriggers(scheduleTriggers);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < scheduleTriggers.collectionSize; i++)
                mlist->Add(gcnew CPPCli::ScheduleTrigger(scheduleTriggers.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] scheduleTriggers.collection;
    }
    return mlist;
}
