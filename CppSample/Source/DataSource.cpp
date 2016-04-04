#include "stdafx.h"
#include "DataSource.h"

using namespace std;

CPPConsole::DataSource::DataSource(VxSdk::IVxDataSource* vxDataSource) {
    _dataSource = vxDataSource;
    _clipsList = nullptr;
    _dataInterfaceList = nullptr;
}

list<CPPConsole::Clip*>* CPPConsole::DataSource::GetClips() {
    if (_clipsList != nullptr) {
        for (list<Clip*>::const_iterator iterator = _clipsList->begin(), end = _clipsList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _clipsList;
    }
    _clipsList = new list<Clip*>();
    VxSdk::VxCollection<VxSdk::IVxClip**> clips;
    VxSdk::VxResult::Value result = _dataSource->GetClips(clips);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        clips.collection = new VxSdk::IVxClip*[clips.collectionSize];
        result = _dataSource->GetClips(clips);
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < clips.collectionSize; i++)
                _clipsList->push_back(new Clip(clips.collection[i]));
        }
        delete[] clips.collection;
    }
    return _clipsList;
}

list<CPPConsole::DataInterface*>* CPPConsole::DataSource::GetDataInterfaces() {
    if (_dataInterfaceList != nullptr) {
        for (list<DataInterface*>::const_iterator iterator = _dataInterfaceList->begin(), end = _dataInterfaceList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _dataInterfaceList;
    }

    _dataInterfaceList = new list<DataInterface*>();
    int size = _dataSource->dataInterfaceSize;
    for (int i = 0; i < size; i++)
        _dataInterfaceList->push_back(new DataInterface(_dataSource->dataInterfaces[i]));
        
    return _dataInterfaceList;
}

char* CPPConsole::DataSource::GetRtspEndpoint() {
    char* rtspEndpoint = nullptr;
    int size = 0;
    VxSdk::VxResult::Value result = _dataSource->GetRtspEndpoint(rtspEndpoint, size);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        rtspEndpoint = new char[size];
        _dataSource->GetRtspEndpoint(rtspEndpoint, size);
    }
    return rtspEndpoint;
}

CPPConsole::DataSession* CPPConsole::DataSource::CreateMJPEGSession() {
    VxSdk::IVxDataSession* dataSession = nullptr;

    VxSdk::VxResult::Value result = _dataSource->CreateMjpegDataSession(dataSession);
    if (result == VxSdk::VxResult::kOK) {
        return new DataSession(dataSession);
    }
    return nullptr;
}

CPPConsole::DataSource::~DataSource() {
    if (_clipsList != nullptr){
        for (list<Clip*>::const_iterator iterator = _clipsList->begin(), end = _clipsList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _clipsList;
    }

    if (_dataInterfaceList != nullptr) {
        for (list<DataInterface*>::const_iterator iterator = _dataInterfaceList->begin(), end = _dataInterfaceList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _dataInterfaceList;
    }

    _dataSource->Delete();
    _dataSource = nullptr;
}
