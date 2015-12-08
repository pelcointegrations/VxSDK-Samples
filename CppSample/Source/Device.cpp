#include "stdafx.h"
#include "Device.h"

using namespace std;

CPPConsole::Device::Device(VxSdk::IVxDevice* vxDevice){
    _device = vxDevice;
    _dataSourceList = nullptr;
}

std::list<CPPConsole::DataSource*>* CPPConsole::Device::GetDatasources()
{
    if (_dataSourceList != nullptr){
        return _dataSourceList;
    }

    _dataSourceList = new list<CPPConsole::DataSource*>();
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;
    VxSdk::VxResult::Value result = _device->GetDataSources(dataSources);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _device->GetDataSources(dataSources);
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataSources.collectionSize; i++)
                _dataSourceList->push_back(new CPPConsole::DataSource(dataSources.collection[i]));
        }
        delete[] dataSources.collection;
    }
    return _dataSourceList;
}

CPPConsole::Device::~Device() {
    if (_dataSourceList != nullptr) {
        for (list<DataSource*>::const_iterator iterator = _dataSourceList->begin(), end = _dataSourceList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _dataSourceList;
    }

    _device->Delete();
    _device = nullptr;
}
