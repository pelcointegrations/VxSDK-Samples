/// <summary>
/// Implements the data source class.
/// </summary>
#include "Device.h"
#include "DataSource.h"

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

bool CPPCli::DataSource::_CanPtz() {
    bool result;
    _dataSource->CanPtz(result);
    return result;
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

CPPCli::Device^ CPPCli::DataSource::_GetHostDevice() {
    // Get the device which hosts this data source
    VxSdk::IVxDevice* device = nullptr;
    VxSdk::VxResult::Value result = _dataSource->GetHostDevice(device);

    // Return the device if GetHostDevice was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew Device(device);

    return nullptr;
}
