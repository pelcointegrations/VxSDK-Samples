/// <summary>
/// Implements the data source class.
/// </summary>
#include "DataStorage.h"
#include "ResourceRel.h"
#include "UserInfo.h"

using namespace System::Collections::Generic;

CPPCli::DataSource::DataSource(VxSdk::IVxDataSource* vxDataSource) {
    _dataSource = vxDataSource;
}

CPPCli::DataSource::!DataSource() {
    _dataSource->Delete();
    _dataSource = nullptr;
}

CPPCli::DataSession^ CPPCli::DataSource::CreateMjpegStream() {
    // Create a data session object
    VxSdk::IVxDataSession* dataSession;

    // If the mjpeg protocol is not available on the datasource the result will return VxSdk::VxResult::kActionUnavailable,
    // otherwise VxSdk::VxResult::kOK
    VxSdk::VxResult::Value result = _dataSource->CreateMjpegDataSession(dataSession);
    if (result == VxSdk::VxResult::kOK)
        return gcnew DataSession(dataSession);

    return nullptr;
}

CPPCli::Results::Value CPPCli::DataSource::Refresh() {
    return (CPPCli::Results::Value)_dataSource->Refresh();
}

bool CPPCli::DataSource::_CanPtz() {
    bool result;
    _dataSource->CanPtz(result);
    return result;
}

List<CPPCli::DataStorage^>^ CPPCli::DataSource::_GetAllDataStorages() {
    // Create a list of managed data storages
    List<DataStorage^>^ mlist = gcnew List<DataStorage^>();
    // Create a collection of unmanaged data storages
    VxSdk::VxCollection<VxSdk::IVxDataStorage**> dataStorages;

    // Make the GetAllDataStorages call, which will return with the total data storage count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataSource->GetAllDataStorages(dataStorages);
    // As long as there are data storages from this datasource the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataStorage collection
        dataStorages.collection = new VxSdk::IVxDataStorage*[dataStorages.collectionSize];
        result = _dataSource->GetAllDataStorages(dataStorages);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataStorages.collectionSize; i++)
                mlist->Add(gcnew CPPCli::DataStorage(dataStorages.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataStorages.collection;
    }
    return mlist;
}

List<CPPCli::ResourceRel^>^ CPPCli::DataSource::_GetAudioRelations() {
    // Create a list of managed related resources
    List<ResourceRel^>^ mlist = gcnew List<ResourceRel^>();
    // Create a collection of unmanaged related resources
    VxSdk::VxCollection<VxSdk::IVxResourceRel**> resourceRels;

    // Make the GetAudioRelations call, which will return with the total resource count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataSource->GetAudioRelations(resourceRels);
    // As long as there are related resources for this datasource the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxResourceRel collection
        resourceRels.collection = new VxSdk::IVxResourceRel*[resourceRels.collectionSize];
        result = _dataSource->GetAudioRelations(resourceRels);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < resourceRels.collectionSize; i++)
                mlist->Add(gcnew CPPCli::ResourceRel(resourceRels.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] resourceRels.collection;
    }
    return mlist;
}

List<CPPCli::Clip^>^ CPPCli::DataSource::_GetClips() {
    // Create a list of managed clips
    List<Clip^>^ mlist = gcnew List<Clip^>();
    // Create a collection of unmanaged clips
    VxSdk::VxCollection<VxSdk::IVxClip**> clips;

    // Make the GetClips call, which will return with the total clip count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataSource->GetClips(clips);
    // As long as there are clips from this datasource the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxClip collection
        clips.collection = new VxSdk::IVxClip*[clips.collectionSize];
        result = _dataSource->GetClips(clips);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < clips.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Clip(clips.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] clips.collection;
    }
    return mlist;
}

List<CPPCli::DataInterface^>^ CPPCli::DataSource::_GetDataInterfaces() {
    // Create a list of managed export objects
    List<DataInterface^>^ mlist = gcnew List<DataInterface^>();
    for (int i = 0; i < _dataSource->dataInterfaceSize; i++)
        mlist->Add(gcnew DataInterface(_dataSource->dataInterfaces[i]));

    return mlist;
}

List<CPPCli::DataStorage^>^ CPPCli::DataSource::_GetDataStorages() {
    // Create a list of managed data storages
    List<DataStorage^>^ mlist = gcnew List<DataStorage^>();
    // Create a collection of unmanaged data storages
    VxSdk::VxCollection<VxSdk::IVxDataStorage**> dataStorages;

    // Make the GetDataStorages call, which will return with the total data storage count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataSource->GetDataStorages(dataStorages);
    // As long as there are data storages from this datasource the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataStorage collection
        dataStorages.collection = new VxSdk::IVxDataStorage*[dataStorages.collectionSize];
        result = _dataSource->GetDataStorages(dataStorages);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataStorages.collectionSize; i++)
                mlist->Add(gcnew CPPCli::DataStorage(dataStorages.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataStorages.collection;
    }
    return mlist;
}

List<CPPCli::Clip^>^ CPPCli::DataSource::_GetEdgeClips() {
    // Create a list of managed clips
    List<Clip^>^ mlist = gcnew List<Clip^>();
    // Create a collection of unmanaged clips
    VxSdk::VxCollection<VxSdk::IVxClip**> clips;

    // Make the GetEdgeClips call, which will return with the total clip count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataSource->GetEdgeClips(clips);
    // As long as there are clips from this datasource the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxClip collection
        clips.collection = new VxSdk::IVxClip*[clips.collectionSize];
        result = _dataSource->GetEdgeClips(clips);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < clips.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Clip(clips.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] clips.collection;
    }
    return mlist;
}

CPPCli::Device^ CPPCli::DataSource::_GetHostDevice() {
    // Get the device which hosts this data source
    VxSdk::IVxDevice* device = nullptr;
    VxSdk::VxResult::Value result = _dataSource->GetHostDevice(device);

    // Return the device if GetHostDevice was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew Device(device);

    return nullptr;
}

CPPCli::ResourceRel^ CPPCli::DataSource::_GetLinkedAudioRelation() {
    // Create a managed ResourceRel object
    CPPCli::ResourceRel^ resourceRel = nullptr;
    // Create a collection of unmanaged related resources
    VxSdk::VxCollection<VxSdk::IVxResourceRel**> resourceRels;
    resourceRels.filterSize = 1;
    VxSdk::VxCollectionFilter filters[1];
    resourceRels.filters = filters;
    resourceRels.filters[0].key = VxSdk::VxCollectionFilterItem::kLinked;
    VxSdk::Utilities::StrCopySafe(resourceRels.filters[0].value, Utils::ConvertSysString("true"));

    // Make the GetAudioRelations call, which will return with the total resource count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataSource->GetAudioRelations(resourceRels);
    // As long as there are related resources for this datasource the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxResourceRel collection
        resourceRels.collection = new VxSdk::IVxResourceRel*[resourceRels.collectionSize];
        result = _dataSource->GetAudioRelations(resourceRels);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            if (resourceRels.collectionSize > 0)
                resourceRel = gcnew CPPCli::ResourceRel(resourceRels.collection[0]);
        }

        // Remove the memory we previously allocated to the collection
        delete[] resourceRels.collection;
    }
    return resourceRel;
}

System::Collections::Generic::List<CPPCli::UserInfo^>^ CPPCli::DataSource::_GetMultiviewInfo() {
    // Create a list of managed user info objects
    List<UserInfo^>^ mlist = gcnew List<UserInfo^>();
    // Create a collection of unmanaged user info objects
    VxSdk::VxCollection<VxSdk::IVxUserInfo**> userInfos;

    // Make the GetMultiviewInfo call, which will return with the total user info object count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataSource->GetMultiviewInfo(userInfos);
    // As long as there are user info objects for this datasource the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxUserInfo collection
        userInfos.collection = new VxSdk::IVxUserInfo*[userInfos.collectionSize];
        result = _dataSource->GetMultiviewInfo(userInfos);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < userInfos.collectionSize; i++)
                mlist->Add(gcnew CPPCli::UserInfo(userInfos.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] userInfos.collection;
    }
    return mlist;
}

CPPCli::PtzController^ CPPCli::DataSource::_GetPtzController() {
    // Check to ensure this datasource is a ptz camera
    bool isPtz;
    VxSdk::VxResult::Value result = _dataSource->CanPtz(isPtz);

    if (isPtz) {
        // Get the ptz controller which allows the client to make ptz calls
        VxSdk::IVxPtzController* ptzController = nullptr;
        result = _dataSource->GetPtzController(ptzController);

        // Return the ptz controller if GetPtzController was successful
        if (result == VxSdk::VxResult::kOK)
            return gcnew PtzController(ptzController);
    }
    return nullptr;
}

System::String^ CPPCli::DataSource::_GetRtspEndpoint() {
    char* rtspEndpoint = nullptr;
    int size = 0;

    // If the rtsp uri is not available on the datasource the result will return VxSdk::VxResult::kActionUnavailable,
    // otherwise VxSdk::VxResult::kInsufficientSize
    VxSdk::VxResult::Value result = _dataSource->GetRtspEndpoint(rtspEndpoint, size);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for rtspEndpoint
        rtspEndpoint = new char[size];
        // The result should now be kOK since we have allocated enough space
        _dataSource->GetRtspEndpoint(rtspEndpoint, size);
    }
    return gcnew System::String(rtspEndpoint);
}

List<CPPCli::ResourceRel^>^ CPPCli::DataSource::_GetVideoRelations() {
    // Create a list of managed related resources
    List<ResourceRel^>^ mlist = gcnew List<ResourceRel^>();
    // Create a collection of unmanaged related resources
    VxSdk::VxCollection<VxSdk::IVxResourceRel**> resourceRels;

    // Make the GetVideoRelations call, which will return with the total resource count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _dataSource->GetVideoRelations(resourceRels);
    // As long as there are related resources for this datasource the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxResourceRel collection
        resourceRels.collection = new VxSdk::IVxResourceRel*[resourceRels.collectionSize];
        result = _dataSource->GetVideoRelations(resourceRels);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < resourceRels.collectionSize; i++)
                mlist->Add(gcnew CPPCli::ResourceRel(resourceRels.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] resourceRels.collection;
    }
    return mlist;
}
