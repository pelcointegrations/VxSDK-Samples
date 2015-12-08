#include "stdafx.h"
#include "string.h"
#include "System.h"
#include <fstream>
#include <Constants.h>

using namespace std;

CPPConsole::System::System() {
    _system = nullptr;
    _deviceList = nullptr;
}

bool CPPConsole::System::Login(const char* ip, int port, const char* user, const char* passwd) {
    ifstream filein("PelcoKey.txt");
    if (filein.is_open()) {
        string key;
        getline(filein, key);
        VxSdk::VxInit(key.c_str());
        filein.close();
    }

    VxSdk::VxLoginInfo loginInfo;
    loginInfo.port = Constants::kPortnum;
    loginInfo.useSsl = true;
    VxSdk::Utilities::StrCopySafe(loginInfo.ipAddress, ip);
    VxSdk::Utilities::StrCopySafe(loginInfo.username, user);
    VxSdk::Utilities::StrCopySafe(loginInfo.password, passwd);

    VxSdk::IVxSystem* system = nullptr;
    VxSystemLogin(loginInfo, system);
    _system = system;
    return _system != nullptr;
}

list<CPPConsole::Device*>* CPPConsole::System::GetDevices() {
    if (_deviceList != nullptr) {
        for (list<CPPConsole::Device*>::const_iterator iterator = _deviceList->begin(), end = _deviceList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _deviceList;
    }

    _deviceList = new list<CPPConsole::Device*>();
    VxSdk::VxCollection<VxSdk::IVxDevice**> devices;
    VxSdk::VxResult::Value result = _system->GetDevices(devices);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        devices.collection = new VxSdk::IVxDevice*[devices.collectionSize];
        result = _system->GetDevices(devices);
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < devices.collectionSize; i++)
                _deviceList->push_back(new CPPConsole::Device(devices.collection[i]));
        }
        delete[] devices.collection;
    }
    return _deviceList;
}

list<CPPConsole::Device*>* CPPConsole::System::GetDevices(int pageIndex, int count, int& totalItems) {
    list<CPPConsole::Device*>* deviceList = new list<CPPConsole::Device*>();

    VxSdk::VxCollection<VxSdk::IVxDevice**> devices;

    devices.filterSize = 2;
    VxSdk::VxCollectionFilter filters[2];
    filters[0].key = VxSdk::VxCollectionFilterItem::kStart;
    filters[1].key = VxSdk::VxCollectionFilterItem::kCount;
    VxSdk::Utilities::StrCopySafe(filters[0].value, to_string(pageIndex).c_str());
    VxSdk::Utilities::StrCopySafe(filters[1].value, to_string(count).c_str());
    devices.filters = filters;

    VxSdk::VxResult::Value result = _system->GetDevices(devices);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        devices.collection = new VxSdk::IVxDevice*[devices.collectionSize];
        totalItems = devices.collectionSize;
        result = _system->GetDevices(devices);
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < devices.collectionSize; i++)
                deviceList->push_back(new CPPConsole::Device(devices.collection[i]));
        }
        delete[] devices.collection;
    }
    return deviceList;
}

CPPConsole::Export* CPPConsole::System::CreateExport(CPPConsole::NewExport* newExport) {
    Export* exporter = nullptr;
    int size = newExport->GetClips()->size();
    VxSdk::VxNewExport vxExport;
    vxExport.clips = new VxSdk::VxNewExportClip[size];
    vxExport.clipSize = size;

    vxExport.format = VxSdk::VxExportFormat::Value(newExport->GetFormat());
    VxSdk::Utilities::StrCopySafe(vxExport.name, newExport->GetExportName());
    VxSdk::Utilities::StrCopySafe(vxExport.password, newExport->GetExportPassword());
    for (int i = 0; i < size; i++) {
        VxSdk::VxNewExportClip clip;
        VxSdk::Utilities::StrCopySafe(clip.dataSourceId, newExport->GetClips()->at(i)->GetDataSourceId());
        VxSdk::Utilities::StrCopySafe(clip.startTime, newExport->GetClips()->at(i)->GetStartTime());
        VxSdk::Utilities::StrCopySafe(clip.endTime, newExport->GetClips()->at(i)->GetEndTime());
        vxExport.clips[i] = clip;
    }

    VxSdk::IVxExport* exportItem = nullptr;
    VxSdk::VxResult::Value result = _system->CreateExport(vxExport, exportItem);

    if (result == VxSdk::VxResult::kOK)
        exporter = new Export(exportItem);

    delete[] vxExport.clips;

    return exporter;
}

list<CPPConsole::Export*>* CPPConsole::System::GetExports() {
    list<Export*>* exportsList = new list<CPPConsole::Export*>();
    VxSdk::VxCollection<VxSdk::IVxExport**> exports;

    VxSdk::VxResult::Value result = _system->GetExports(exports);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        exports.collection = new VxSdk::IVxExport*[exports.collectionSize];
        result = _system->GetExports(exports);
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < exports.collectionSize; i++)
                exportsList->push_back(new CPPConsole::Export(exports.collection[i]));
        }
        delete[] exports.collection;
    }
    return exportsList;
}

CPPConsole::Export* CPPConsole::System::GetExportDetails(const char* expName, const char* id) {
    VxSdk::VxCollection<VxSdk::IVxExport**> exports;
    CPPConsole::Export* expToRet = nullptr;

    exports.filterSize = 1;
    VxSdk::VxCollectionFilter filters[1];
    filters->key = VxSdk::VxCollectionFilterItem::kName;
    VxSdk::Utilities::StrCopySafe(filters->value, expName);
    exports.filters = filters;

    VxSdk::VxResult::Value result = _system->GetExports(exports);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        exports.collection = new VxSdk::IVxExport*[exports.collectionSize];
        result = _system->GetExports(exports);
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < exports.collectionSize; i++) {
                VxSdk::IVxExport* exportObj = exports.collection[i];
                if (strcmp(exportObj->id, id) == 0)
                    expToRet = new CPPConsole::Export(exports.collection[i]);
            }
        }
        delete[] exports.collection;
    }
    return expToRet;
}

bool CPPConsole::System::DeleteExport(CPPConsole::Export* exportToDelete) {
    VxSdk::IVxExport* delExport = exportToDelete->GetExportPtr();
    VxSdk::VxResult::Value result = delExport->DeleteExport();
    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}

bool CPPConsole::System::SubscribeSystemEvents(VxSdk::VxEventCallback callBack) {
    VxSdk::VxResult::Value result = _system->StartNotifications(callBack);
    return result == VxSdk::VxResult::kOK;
}

bool CPPConsole::System::UnSubscribeSystemEvents() {
    VxSdk::VxResult::Value result = _system->StopNotifications();
    return result == VxSdk::VxResult::kOK;
}

bool CPPConsole::System::InjectNewEvent(Situation* situation, string genDeviceId, string srcDeviceId, string eventTime) {
    VxSdk::VxNewEvent newEvent;
    VxSdk::Utilities::StrCopySafe(newEvent.situationType, situation->GetSituationType());
    VxSdk::Utilities::StrCopySafe(newEvent.generatorDeviceId, genDeviceId.c_str());
    VxSdk::Utilities::StrCopySafe(newEvent.sourceDeviceId, srcDeviceId.c_str());
    VxSdk::Utilities::StrCopySafe(newEvent.time, eventTime.c_str());

    VxSdk::VxResult::Value result = _system->InsertEvent(newEvent);
    return result == VxSdk::VxResult::kOK;
}

list<CPPConsole::Situation*>* CPPConsole::System::GetSituations() {
    list<Situation*>* situationsList = new list<CPPConsole::Situation*>();
    VxSdk::VxCollection<VxSdk::IVxSituation**> situations;

    VxSdk::VxResult::Value result = _system->GetSituations(situations);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        situations.collection = new VxSdk::IVxSituation*[situations.collectionSize];
        result = _system->GetSituations(situations);
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < situations.collectionSize; i++)
                situationsList->push_back(new CPPConsole::Situation(situations.collection[i]));
        }
        delete[] situations.collection;
    }
    return situationsList;
}

bool CPPConsole::System::AddNewSituation(const char* name, const char* type) {
    bool res = false;

    VxSdk::VxNewSituation situation;
    situation.Default();

    strncpy_s(situation.name, name, sizeof(situation.name));
    strncpy_s(situation.type, type, sizeof(situation.type));

    VxSdk::VxResult::Value result = _system->AddSituation(situation);
    if (result == VxSdk::VxResult::kOK)
        res = true;

    // Delete the memory allocated in the Default method
    delete[] situation.snoozeIntervals;

    return res;
}

bool CPPConsole::System::DeleteSituation(CPPConsole::Situation* situationToDelete) {
    VxSdk::VxResult::Value result = situationToDelete->Self()->DeleteSituation();
    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}

CPPConsole::System::~System() {
    if (_deviceList != nullptr) {
        for (list<CPPConsole::Device*>::const_iterator iterator = _deviceList->begin(), end = _deviceList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _deviceList;
    }

    _system->Delete();
    _system = nullptr;
}
