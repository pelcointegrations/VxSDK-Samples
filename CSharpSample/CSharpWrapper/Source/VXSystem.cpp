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
        // Internally subscribe to the system events.  The client still needs to subscribe to the SystemEvent
        // delegate in order to receive the events.
        _system->StartNotifications(VxSdk::VxEventCallback(Marshal::GetFunctionPointerForDelegate(_callback).ToPointer()));
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

String^ CPPCli::VXSystem::CreateExport(CPPCli::NewExport^ newExport) {
    String^ exportId;
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

    // Attempt to create the export
    VxSdk::IVxExport* exportItem = nullptr;
    VxSdk::VxResult::Value result = _system->CreateExport(vxExport, exportItem);

    // Unless there was an issue initiating the export the result should be VxSdk::VxResult::kOK
    if (result == VxSdk::VxResult::kOK) {
        // The exportItem returned from the system is the export initiated on the server and contains a lot of
        // helpful information about the export.
        exportId = gcnew String(exportItem->id);

        // This export item must still be deleted from memory
        exportItem->Delete();
        exportItem = nullptr;
    }
    return exportId;
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

CPPCli::Results::Value CPPCli::VXSystem::InjectEvent(CPPCli::NewEvent^ newEvent) {
    // Create a new VxNewEvent object using the information contained in newEvent
    VxSdk::VxNewEvent vxEvent;
    VxSdk::Utilities::StrCopySafe(vxEvent.generatorDeviceId, Utils::ConvertSysString(newEvent->GeneratorDeviceId));
    VxSdk::Utilities::StrCopySafe(vxEvent.situationType, Utils::ConvertSysString(newEvent->SituationType));
    VxSdk::Utilities::StrCopySafe(vxEvent.sourceDeviceId, Utils::ConvertSysString(newEvent->SourceDeviceId));
    VxSdk::Utilities::StrCopySafe(vxEvent.time, Utils::ConvertDateTimeToChar(newEvent->Time));
    int size = newEvent->Properties->Count;
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

void CPPCli::VXSystem::SystemEvent::add(EventDelegate ^eventDelegate) {
    // Add a new subscription to the EventDelegate
    _systemEvent += eventDelegate;
};

void CPPCli::VXSystem::SystemEvent::remove(EventDelegate ^eventDelegate) {
    // Remove the EventDelegate subscription
    _systemEvent -= eventDelegate;
};

void CPPCli::VXSystem::_FireEvent(VxSdk::IVxEvent* vxEvent) {
    // Fire the notification if there is a subscription to the system events
    if (_systemEvent != nullptr)
        return _systemEvent(gcnew Event(vxEvent));
}
