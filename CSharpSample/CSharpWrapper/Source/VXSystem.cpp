/// <summary>
/// Implements the VX System class.
/// </summary>
#include "VxSystem.h"
#include "VxSdk.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

CPPCli::VXSystem::VXSystem(String^ ip) : _loginInfo(new VxSdk::VxLoginInfo()) {
    // Enter the VideoXpert IP information
    VxSdk::Utilities::StrCopySafe(_loginInfo->ipAddress, Utils::ConvertSysString(ip));
}

CPPCli::Results::Value CPPCli::VXSystem::InitializeSdk(System::String^ key) {
    // Init the sdk with your key generated using VxSdkKeyGen.exe
    VxSdk::VxResult::Value result = VxSdk::VxInit(Utils::ConvertSysString(key));

    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::VXSystem::Login(String^ username, String^ password) {
    // Enter the VideoXpert login information
    VxSdk::Utilities::StrCopySafe(_loginInfo->username, Utils::ConvertSysString(username));
    VxSdk::Utilities::StrCopySafe(_loginInfo->password, Utils::ConvertSysString(password));
    const int kSslPort = 443;
    _loginInfo->port = kSslPort;
    _loginInfo->useSsl = true;

    // Attempt to login to the system
    VxSdk::IVxSystem* system = nullptr;
    VxSdk::VxResult::Value result = VxSdk::VxSystemLogin(*_loginInfo, system);
    if (result == VxSdk::VxResult::kOK) {
        _system = system;
        // Create a new callback delegate
        _callback = gcnew EventCallbackDelegate(&_FireEvent);
    }
    return CPPCli::Results::Value(result);
}

CPPCli::VXSystem::!VXSystem() {
    // Delete system object
    if (_system != nullptr) {
        // Unsubscribe to the system events
        _system->StopNotifications();
        delete _callback;
        _system->Delete();
        _system = nullptr;
    }

    // Delete loginInfo object
    if (_loginInfo != nullptr) {
        delete _loginInfo;
    }
}

CPPCli::Export^ CPPCli::VXSystem::CreateExport(CPPCli::NewExport^ newExport) {
    // Create a new VxNewExportClip object using the clip info contained in newExport
    const int clipSize = newExport->Clips->Count;
    VxSdk::VxNewExportClip* clips = new VxSdk::VxNewExportClip[clipSize];
    for (int i = 0; i < clipSize; i++) {
        VxSdk::Utilities::StrCopySafe(clips[i].dataSourceId, Utils::ConvertSysString(newExport->Clips[i]->DataSourceId));
        VxSdk::Utilities::StrCopySafe(clips[i].startTime, Utils::ConvertDateTimeToChar(newExport->Clips[i]->StartTime));
        VxSdk::Utilities::StrCopySafe(clips[i].endTime, Utils::ConvertDateTimeToChar(newExport->Clips[i]->EndTime));
    }

    // Create a VxNewExport object using the settings contained in newExport and the VxNewExportClip that
    // was just created.
    VxSdk::VxNewExport vxExport;
    vxExport.format = (VxSdk::VxExportFormat::Value)newExport->Format;
    vxExport.clips = clips;
    vxExport.clipSize = clipSize;
    VxSdk::Utilities::StrCopySafe(vxExport.name, Utils::ConvertSysString(newExport->Name));
    // If the password field has a password set then the export will be password protected, if the password is not
    // set, the export will be public
    VxSdk::Utilities::StrCopySafe(vxExport.password, Utils::ConvertSysString(newExport->Password));

    CPPCli::Export^ retExport = nullptr;
    // Attempt to create the export
    VxSdk::IVxExport* exportItem = nullptr;
    VxSdk::VxResult::Value result = _system->CreateExport(vxExport, exportItem);

    // Unless there was an issue initiating the export the result should be VxSdk::VxResult::kOK
    if (result == VxSdk::VxResult::kOK) {
        // The exportItem returned from the system is the export initiated on the server and contains a lot of
        // helpful information about the export.
        retExport = gcnew CPPCli::Export(exportItem);
    }
    return retExport;
}

CPPCli::Results::Value CPPCli::VXSystem::DeleteExport(CPPCli::Export^ exportItem) {
    // Create an export object using the exportItem
    VxSdk::IVxExport* delExport = exportItem->_export;

    // To delete an export simply make a DeleteExport call
    VxSdk::VxResult::Value result = delExport->DeleteExport();
    // Unless there was an issue deleting the export the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

Collections::Generic::List<CPPCli::Device^>^ CPPCli::VXSystem::GetDevices() {
    // Create a list of managed device objects
    List<CPPCli::Device^>^ mlist = gcnew List<CPPCli::Device^>();
    // Create a collection of unmanaged device objects
    VxSdk::VxCollection<VxSdk::IVxDevice**> devices;

    // Make the GetDevices call, which will return with the total device count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _system->GetDevices(devices);
    // Unless there are no devices on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDevice collection
        devices.collection = new VxSdk::IVxDevice*[devices.collectionSize];
        result = _system->GetDevices(devices);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < devices.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Device(devices.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] devices.collection;
    }
    return mlist;
}

Collections::Generic::List<CPPCli::DataSource^>^ CPPCli::VXSystem::GetDataSources() {
    // Create a list of managed data source objects
    List<CPPCli::DataSource^>^ mlist = gcnew List<CPPCli::DataSource^>();
    // Create a collection of unmanaged data source objects
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetDataSources call, which will return with the total data source count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _system->GetDataSources(dataSources);
    // Unless there are no data sources on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataSource collection
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _system->GetDataSources(dataSources);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataSources.collectionSize; i++)
                mlist->Add(gcnew CPPCli::DataSource(dataSources.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataSources.collection;
    }
    return mlist;
}

List<CPPCli::Export^>^ CPPCli::VXSystem::GetExports() {
    // Create a list of managed export objects
    List<CPPCli::Export^>^ mlist = gcnew List<CPPCli::Export^>();
    // Create a collection of unmanaged export objects
    VxSdk::VxCollection<VxSdk::IVxExport**> exports;

    // Make the GetExports call, which will return with the total export count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _system->GetExports(exports);
    // Unless there are no exports on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxExport collection
        exports.collection = new VxSdk::IVxExport*[exports.collectionSize];
        result = _system->GetExports(exports);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < exports.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Export(exports.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] exports.collection;
    }
    return mlist;
}

List<CPPCli::Situation^>^ CPPCli::VXSystem::GetSituations() {
    // Create a list of managed situation objects
    List<CPPCli::Situation^>^ mlist = gcnew List<CPPCli::Situation^>();
    // Create a collection of unmanaged situation objects
    VxSdk::VxCollection<VxSdk::IVxSituation**> situations;

    // Make the GetSituations call, which will return with the total situation count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _system->GetSituations(situations);
    // The result should be kInsufficientSize if the number of situations on the system are greater than 0 (always)
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxSituation collection
        situations.collection = new VxSdk::IVxSituation*[situations.collectionSize];
        result = _system->GetSituations(situations);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < situations.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::Situation(situations.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] situations.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::VXSystem::AddSituation(CPPCli::NewSituation^ newSituation) {
    // Create a situation object and populate its fields using newSituation
    VxSdk::VxNewSituation vxSituation;
    VxSdk::Utilities::StrCopySafe(vxSituation.name, Utils::ConvertSysString(newSituation->Name));
    VxSdk::Utilities::StrCopySafe(vxSituation.sourceDeviceId, Utils::ConvertSysString(newSituation->SourceDeviceId));
    VxSdk::Utilities::StrCopySafe(vxSituation.type, Utils::ConvertSysString(newSituation->Type));
    vxSituation.isAckNeeded = newSituation->IsAckNeeded;
    vxSituation.audibleLoopDelay = newSituation->AudibleLoopDelay;
    vxSituation.shouldAudiblyNotify = newSituation->UseAudibleNotification;
    vxSituation.audiblePlayCount = newSituation->AudiblePlayCount;
    vxSituation.autoAcknowledge = newSituation->AutoAcknowledge;
    vxSituation.shouldExpandBanner = newSituation->ShouldExpandBanner;
    vxSituation.shouldLog = newSituation->ShouldLog;
    vxSituation.shouldNotify = newSituation->ShouldNotify;
    vxSituation.severity = newSituation->Severity;
    int size = newSituation->SnoozeIntervals->Count;
    int *intervals = new int[size];
    for (int i = 0; i < size; i++) {
        intervals[i] = newSituation->SnoozeIntervals[i];
    }
    vxSituation.snoozeIntervals = intervals;

    // Make the call to add the situation into VideoXpert
    VxSdk::VxResult::Value result = _system->AddSituation(vxSituation);
    // Unless there was an issue adding the situation the result should be VxSdk::VxResult::kOK
    if (result == VxSdk::VxResult::kOK) {
        // Remove the memory we previously allocated
        delete[] vxSituation.snoozeIntervals;
    }
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::VXSystem::DeleteSituation(CPPCli::Situation^ situationItem) {
    // Create a situation object using the situationItem
    VxSdk::IVxSituation* delSituation = situationItem->_situation;

    // To delete a situation simply make a DeleteSituation call
    VxSdk::VxResult::Value result = delSituation->DeleteSituation();
    // Unless there was an issue deleting the situation the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<CPPCli::Event^>^ CPPCli::VXSystem::SearchEvents(System::String^ situationType, System::DateTime^ searchStartTime, System::DateTime^ searchEndTime) {
    // Create a list of managed event objects
    List<CPPCli::Event^>^ mlist = gcnew List<CPPCli::Event^>();
    // Create a collection of unmanaged event objects
    VxSdk::VxCollection<VxSdk::IVxEvent**> events;

    events.filterSize = 3;
    VxSdk::VxCollectionFilter filters[3];
    events.filters = filters;
    events.filters[0].key = VxSdk::VxCollectionFilterItem::kSituationType;
    VxSdk::Utilities::StrCopySafe(events.filters[0].value, Utils::ConvertSysString(situationType));
    events.filters[1].key = VxSdk::VxCollectionFilterItem::kSearchStartTime;
    VxSdk::Utilities::StrCopySafe(events.filters[1].value, CPPCli::Utils::ConvertDateTimeToChar(*searchStartTime));
    events.filters[2].key = VxSdk::VxCollectionFilterItem::kSearchEndTime;
    VxSdk::Utilities::StrCopySafe(events.filters[2].value, CPPCli::Utils::ConvertDateTimeToChar(*searchEndTime));

    // Make the GetEvents call, which will return with the total event count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _system->GetEvents(events);
    // The result should be kInsufficientSize if the number of events on the system are greater than 0 (always)
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxEvent collection
        events.collection = new VxSdk::IVxEvent*[events.collectionSize];
        result = _system->GetEvents(events);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < events.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::Event(events.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] events.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::VXSystem::InjectEvent(CPPCli::NewEvent^ newEvent) {
    // Create a new VxNewEvent object using the information contained in newEvent
    VxSdk::VxNewEvent vxEvent;
    VxSdk::Utilities::StrCopySafe(vxEvent.generatorDeviceId, Utils::ConvertSysString(newEvent->GeneratorDeviceId));
    VxSdk::Utilities::StrCopySafe(vxEvent.situationType, Utils::ConvertSysString(newEvent->SituationType));
    VxSdk::Utilities::StrCopySafe(vxEvent.sourceDeviceId, Utils::ConvertSysString(newEvent->SourceDeviceId));
    VxSdk::Utilities::StrCopySafe(vxEvent.time, Utils::ConvertDateTimeToChar(newEvent->Time));
    int size = vxEvent.propertySize = newEvent->Properties->Count;
    VxSdk::VxKvObject *kvObj = new VxSdk::VxKvObject[size];
    vxEvent.properties = kvObj;
    for (int i = 0; i < size; i++) {
        VxSdk::Utilities::StrCopySafe(vxEvent.properties[i].key, Utils::ConvertSysString(newEvent->Properties[i].Key));
        VxSdk::Utilities::StrCopySafe(vxEvent.properties[i].value, Utils::ConvertSysString(newEvent->Properties[i].Value));
    }

    // Make the call to insert the event into VideoXpert
    VxSdk::VxResult::Value result = _system->InsertEvent(vxEvent);
    // Unless there was an issue inserting the event the result should be VxSdk::VxResult::kOK
    if (result == VxSdk::VxResult::kOK) {
        // Remove the memory we previously allocated
        delete[] vxEvent.properties;
    }
    return CPPCli::Results::Value(result);
}

List<CPPCli::Bookmark^>^ CPPCli::VXSystem::GetBookmarks() {
    // Create a list of managed bookmark objects
    List<CPPCli::Bookmark^>^ mlist = gcnew List<CPPCli::Bookmark^>();
    // Create a collection of unmanaged bookmark objects
    VxSdk::VxCollection<VxSdk::IVxBookmark**> bookmarks;

    // Make the GetBookmarks call, which will return with the total bookmark count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _system->GetBookmarks(bookmarks);
    // The result should be kInsufficientSize if the number of bookmarks on the system are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxBookmark collection
        bookmarks.collection = new VxSdk::IVxBookmark*[bookmarks.collectionSize];
        result = _system->GetBookmarks(bookmarks);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < bookmarks.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::Bookmark(bookmarks.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] bookmarks.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::VXSystem::CreateBookmark(CPPCli::NewBookmark^ newBookmark) {
    // Create a bookmark object and populate its fields using newBookmark
    VxSdk::VxNewBookmark vxBookmark;
    VxSdk::Utilities::StrCopySafe(vxBookmark.dataSourceId, Utils::ConvertSysString(newBookmark->DataSourceId));
    VxSdk::Utilities::StrCopySafe(vxBookmark.description, Utils::ConvertSysString(newBookmark->Description));
    VxSdk::Utilities::StrCopySafe(vxBookmark.time, Utils::ConvertDateTimeToChar(newBookmark->Time));

    // Make the call to add the bookmark into VideoXpert
    VxSdk::VxResult::Value result = _system->AddBookmark(vxBookmark);
    // Unless there was an issue creating the bookmark the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::VXSystem::DeleteBookmark(CPPCli::Bookmark^ bookmarkItem) {
    // Create a bookmark object using the bookmarkItem
    VxSdk::IVxBookmark* delBookmark = bookmarkItem->_bookmark;

    // To delete a bookmark simply make a DeleteBookmark call
    VxSdk::VxResult::Value result = delBookmark->DeleteBookmark();
    // Unless there was an issue deleting the bookmark the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<CPPCli::Schedule^>^ CPPCli::VXSystem::GetSchedules() {
    // Create a list of managed schedule objects
    List<CPPCli::Schedule^>^ mlist = gcnew List<CPPCli::Schedule^>();
    // Create a collection of unmanaged schedule objects
    VxSdk::VxCollection<VxSdk::IVxSchedule**> schedules;

    // Make the GetSchedules call, which will return with the total schedule count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _system->GetSchedules(schedules);
    // The result should be kInsufficientSize if the number of schedules on the system are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxSchedule collection
        schedules.collection = new VxSdk::IVxSchedule*[schedules.collectionSize];
        result = _system->GetSchedules(schedules);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < schedules.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::Schedule(schedules.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] schedules.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::VXSystem::AddSchedule(CPPCli::NewSchedule^ newSchedule) {
    // Create a schedule object and populate its fields using newSchedule
    VxSdk::VxNewSchedule vxSchedule;
    VxSdk::Utilities::StrCopySafe(vxSchedule.id, Utils::ConvertSysString(newSchedule->Id));
    VxSdk::Utilities::StrCopySafe(vxSchedule.name, Utils::ConvertSysString(newSchedule->Name));
    vxSchedule.action = (VxSdk::VxScheduleAction::Value)newSchedule->Action;
    vxSchedule.useAllDataSources = newSchedule->UseAllDataSources;

    // Create new VxNewScheduleTrigger objects using the ScheduleTrigger info contained in newSchedule
    const int triggerSize = newSchedule->ScheduleTriggers->Count;
    VxSdk::VxNewScheduleTrigger* newTriggers = new VxSdk::VxNewScheduleTrigger[triggerSize];
    for (int i = 0; i < triggerSize; i++) {
        VxSdk::Utilities::StrCopySafe(newTriggers[i].dailyEndTime, Utils::ConvertDateTimeToTimeChar(newSchedule->ScheduleTriggers[i]->DailyEndTime));
        VxSdk::Utilities::StrCopySafe(newTriggers[i].dailyStartTime, Utils::ConvertDateTimeToTimeChar(newSchedule->ScheduleTriggers[i]->DailyStartTime));
        VxSdk::Utilities::StrCopySafe(newTriggers[i].endDate, Utils::ConvertDateTimeToChar(newSchedule->ScheduleTriggers[i]->EndDate));
        VxSdk::Utilities::StrCopySafe(newTriggers[i].startDate, Utils::ConvertDateTimeToChar(newSchedule->ScheduleTriggers[i]->StartDate));
        VxSdk::Utilities::StrCopySafe(newTriggers[i].id, Utils::ConvertSysString(newSchedule->ScheduleTriggers[i]->Id));
        VxSdk::Utilities::StrCopySafe(newTriggers[i].eventSourceDevice, Utils::ConvertSysString(newSchedule->ScheduleTriggers[i]->EventSource));
        newTriggers[i].postTrigger = newSchedule->ScheduleTriggers[i]->PostTrigger;
        newTriggers[i].preTrigger = newSchedule->ScheduleTriggers[i]->PreTrigger;
        newTriggers[i].timeout = newSchedule->ScheduleTriggers[i]->Timeout;
        newTriggers[i].event = VxSdk::VxSituationType::Value(newSchedule->ScheduleTriggers[i]->Event);
        newTriggers[i].recurrence = VxSdk::VxRecurrenceType::Value(newSchedule->ScheduleTriggers[i]->RecurrenceType);
        newTriggers[i].framerate = VxSdk::VxRecordingFramerate::Value(newSchedule->ScheduleTriggers[i]->Framerate);

        // Add any weekly interval values to the new schedule trigger
        int weeklySize = newSchedule->ScheduleTriggers[i]->RecurWeekly->Count;
        int *weekIntervals = new int[weeklySize];
        for (int iW = 0; iW < weeklySize; iW++) {
            weekIntervals[iW] = newSchedule->ScheduleTriggers[i]->RecurWeekly[iW];
        }
        newTriggers[i].recurWeekly = weekIntervals;
        newTriggers[i].recurWeeklySize = weeklySize;

        // Add any monthly interval values to the new schedule trigger
        int monthlySize = newSchedule->ScheduleTriggers[i]->RecurMonthly->Count;
        int *monthIntervals = new int[monthlySize];
        for (int iM = 0; iM < monthlySize; iM++) {
            monthIntervals[iM] = newSchedule->ScheduleTriggers[i]->RecurMonthly[iM];
        }
        newTriggers[i].recurMonthly = monthIntervals;
        newTriggers[i].recurMonthlySize = monthlySize;

        // Add any yearly interval values to the new schedule trigger
        int yearlySize = newSchedule->ScheduleTriggers[i]->RecurYearly->Count;
        int *yearIntervals = new int[yearlySize];
        for (int iY = 0; iY < yearlySize; iY++) {
            yearIntervals[iY] = newSchedule->ScheduleTriggers[i]->RecurYearly[iY];
        }
        newTriggers[i].recurYearly = yearIntervals;
        newTriggers[i].recurYearlySize = yearlySize;

        // Add any event properties to the new schedule trigger
        int size = newSchedule->ScheduleTriggers[i]->EventProperties->Count;
        VxSdk::VxKvObject *kvObj = new VxSdk::VxKvObject[size];
        newTriggers[i].eventPropertySize = size;
        newTriggers[i].eventProperties = kvObj;
        for (int ii = 0; ii < size; ii++) {
            VxSdk::Utilities::StrCopySafe(newTriggers[i].eventProperties[ii].key,
                Utils::ConvertSysString(newSchedule->ScheduleTriggers[i]->EventProperties[ii].Key));
            VxSdk::Utilities::StrCopySafe(newTriggers[i].eventProperties[ii].value,
                Utils::ConvertSysString(newSchedule->ScheduleTriggers[i]->EventProperties[ii].Value));
        }
    }
    // Add the schedule triggers to the new schedule
    vxSchedule.scheduleTriggers = newTriggers;
    vxSchedule.scheduleTriggerSize = triggerSize;

    // Make the call to add the schedule into VideoXpert
    VxSdk::VxResult::Value result = _system->AddSchedule(vxSchedule);
    // Unless there was an issue adding the schedule the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::VXSystem::DeleteSchedule(CPPCli::Schedule^ scheduleItem) {
    // Create a schedule object using the scheduleItem
    VxSdk::IVxSchedule* delSchedule = scheduleItem->_schedule;

    // To delete a schedule simply make a DeleteSchedule call
    VxSdk::VxResult::Value result = delSchedule->DeleteSchedule();
    // Unless there was an issue deleting the schedule the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<CPPCli::DataStorage^>^ CPPCli::VXSystem::GetDataStorages() {
    // Create a list of managed data storage objects
    List<CPPCli::DataStorage^>^ mlist = gcnew List<CPPCli::DataStorage^>();
    // Create a collection of unmanaged data storage objects
    VxSdk::VxCollection<VxSdk::IVxDataStorage**> dataStorages;

    // Make the GetDataStorages call, which will return with the total storage count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _system->GetDataStorages(dataStorages);
    // The result should be kInsufficientSize if the number of data storages on the system are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataStorage collection
        dataStorages.collection = new VxSdk::IVxDataStorage*[dataStorages.collectionSize];
        result = _system->GetDataStorages(dataStorages);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataStorages.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::DataStorage(dataStorages.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataStorages.collection;
    }
    return mlist;
}

List<CPPCli::Tag^>^ CPPCli::VXSystem::GetTags() {
    // Create a list of managed tag objects
    List<CPPCli::Tag^>^ mlist = gcnew List<CPPCli::Tag^>();
    // Create a collection of unmanaged tag objects
    VxSdk::VxCollection<VxSdk::IVxTag**> tags;

    // Make the GetTags call, which will return with the total tag count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _system->GetTags(tags);
    // The result should be kInsufficientSize if the number of tags on the system are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxTag collection
        tags.collection = new VxSdk::IVxTag*[tags.collectionSize];
        result = _system->GetTags(tags);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < tags.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::Tag(tags.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] tags.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::VXSystem::CreateTag(CPPCli::NewTag^ newTag) {
    // Create a new tag object and populate its fields using newTag
    VxSdk::VxNewTag vxTag;
    VxSdk::Utilities::StrCopySafe(vxTag.name, Utils::ConvertSysString(newTag->Name));
    vxTag.isPublic = newTag->IsPublic;

    // Make the call to add the tag into VideoXpert
    VxSdk::VxResult::Value result = _system->AddTag(vxTag);
    // Unless there was an issue creating the tag the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::VXSystem::DeleteTag(CPPCli::Tag^ tagItem) {
    // Create a tag object using the tagItem
    VxSdk::IVxTag* delTag = tagItem->_tag;

    // To delete a tag simply make a DeleteTag call
    VxSdk::VxResult::Value result = delTag->DeleteTag();
    // Unless there was an issue deleting the tag the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<CPPCli::User^>^ CPPCli::VXSystem::GetUsers() {
    // Create a list of managed tag objects
    List<CPPCli::User^>^ mlist = gcnew List<CPPCli::User^>();
    // Create a collection of unmanaged tag objects
    VxSdk::VxCollection<VxSdk::IVxUser**> users;

    // Make the GetTags call, which will return with the total tag count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _system->GetUsers(users);
    // The result should be kInsufficientSize if the number of tags on the system are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxTag collection
        users.collection = new VxSdk::IVxUser*[users.collectionSize];
        result = _system->GetUsers(users);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < users.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::User(users.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] users.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::VXSystem::AddUser(CPPCli::NewUser^ newUser) {
    // Create a new user object and populate its fields using newUser
    VxSdk::VxNewUser vxNewUser;
    VxSdk::Utilities::StrCopySafe(vxNewUser.domain, Utils::ConvertSysString(newUser->Domain));
    VxSdk::Utilities::StrCopySafe(vxNewUser.name, Utils::ConvertSysString(newUser->Name));
    VxSdk::Utilities::StrCopySafe(vxNewUser.password, Utils::ConvertSysString(newUser->Password));
    vxNewUser.mustChangePassword = newUser->MustChangePassword;

    // Make the call to add the user into VideoXpert
    VxSdk::VxResult::Value result = _system->AddUser(vxNewUser);
    // Unless there was an issue creating the user the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::VXSystem::DeleteUser(CPPCli::User^ userItem) {
    // Create a user object using the tagItem
    VxSdk::IVxUser* delUser = userItem->_user;

    // To delete a user simply make a DeleteUser call
    VxSdk::VxResult::Value result = delUser->DeleteUser();
    // Unless there was an issue deleting the user the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<CPPCli::Role^>^ CPPCli::VXSystem::GetRoles() {
    // Create a list of managed role objects
    List<CPPCli::Role^>^ mlist = gcnew List<CPPCli::Role^>();
    // Create a collection of unmanaged role objects
    VxSdk::VxCollection<VxSdk::IVxRole**> roles;

    // Make the GetRoles call, which will return with the total role count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _system->GetRoles(roles);
    // The result should be kInsufficientSize if the number of roles on the system are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxRole collection
        roles.collection = new VxSdk::IVxRole*[roles.collectionSize];
        result = _system->GetRoles(roles);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < roles.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::Role(roles.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] roles.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::VXSystem::AddRole(System::String^ roleName) {
    // Make the call to add the role into VideoXpert
    VxSdk::VxResult::Value result = _system->AddRole(Utils::ConvertSysString(roleName));
    // Unless there was an issue creating the role the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::VXSystem::DeleteRole(CPPCli::Role^ roleItem) {
    // Create a role object using the roleItem
    VxSdk::IVxRole* delRole = roleItem->_role;

    // To delete a role simply make a DeleteRole call
    VxSdk::VxResult::Value result = delRole->DeleteRole();
    // Unless there was an issue deleting the role the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<CPPCli::DataObject^>^ CPPCli::VXSystem::GetDataObjects() {
    // Create a list of managed data objects
    List<CPPCli::DataObject^>^ mlist = gcnew List<CPPCli::DataObject^>();
    // Create a collection of unmanaged data objects
    VxSdk::VxCollection<VxSdk::IVxDataObject**> dataObjects;

    // Make the GetDataObjects call, which will return with the total data object count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _system->GetDataObjects(dataObjects);
    // The result should be kInsufficientSize if the number of data objects on the system are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataObject collection
        dataObjects.collection = new VxSdk::IVxDataObject*[dataObjects.collectionSize];
        result = _system->GetDataObjects(dataObjects);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataObjects.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::DataObject(dataObjects.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataObjects.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::VXSystem::AddDataObject(CPPCli::NewDataObject^ newDataObject) {
    // Create a new data object and populate its fields using newDataObject
    VxSdk::VxNewDataObject vxDataObject;
    VxSdk::Utilities::StrCopySafe(vxDataObject.clientType, Utils::ConvertSysString(newDataObject->ClientType));
    vxDataObject.data = Utils::ConvertSysStringNonConst(newDataObject->Data);
    vxDataObject.isPrivate = newDataObject->IsPrivate;

    // Make the call to add the data object into VideoXpert
    VxSdk::VxResult::Value result = _system->AddDataObject(vxDataObject);
    // Unless there was an issue creating the data object the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::VXSystem::DeleteDataObject(CPPCli::DataObject^ dataObjectItem) {
    // Create a data object object using the dataObjectItem
    VxSdk::IVxDataObject* delDataObject = dataObjectItem->_dataObject;

    // To delete a data object simply make a DeleteTag call
    VxSdk::VxResult::Value result = delDataObject->DeleteDataObject();
    // Unless there was an issue deleting the data object the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::User^ CPPCli::VXSystem::_GetCurrentUser() {
    // Get the user object
    VxSdk::IVxUser* user = nullptr;
    VxSdk::VxResult::Value result = _system->GetCurrentUser(user);

    // Return the user if GetCurrentUser was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::User(user);

    return nullptr;
}

CPPCli::Results::Value CPPCli::VXSystem::SubscribeToEventsByType(CPPCli::VXSystem::EventDelegate^ eventDelegate, List<Situation^>^ situations) {
    VxSdk::VxCollection<VxSdk::IVxSituation**> situationCollection;
    situationCollection.collectionSize = situations->Count;
    situationCollection.collection = new VxSdk::IVxSituation*[situationCollection.collectionSize];

    // Add the situations to subscribe to
    for (int i = 0; i < situations->Count; i++)
        situationCollection.collection[i] = situations[i]->_situation;

    // Subscribe to the system events using the situation types
    VxSdk::VxResult::Value result = _system->StartNotifications(
        VxSdk::VxEventCallback(Marshal::GetFunctionPointerForDelegate(_callback).ToPointer()), situationCollection);

    // Add a new subscription to the EventDelegate
    _systemEvent += eventDelegate;
    // Unless there was an issue subscribing the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

void CPPCli::VXSystem::SystemEvent::add(EventDelegate ^eventDelegate) {
    // Subscribe to the system events
    _system->StartNotifications(VxSdk::VxEventCallback(Marshal::GetFunctionPointerForDelegate(_callback).ToPointer()));
    // Add a new subscription to the EventDelegate
    _systemEvent += eventDelegate;
};

void CPPCli::VXSystem::SystemEvent::remove(EventDelegate ^eventDelegate) {
    // Unsubscribe to the system events
    _system->StopNotifications();
    // Remove the EventDelegate subscription
    _systemEvent -= eventDelegate;
};

void CPPCli::VXSystem::_FireEvent(VxSdk::IVxEvent* vxEvent) {
    // Fire the notification if there is a subscription to the system events
    if (_systemEvent != nullptr)
        return _systemEvent(gcnew Event(vxEvent));
}
