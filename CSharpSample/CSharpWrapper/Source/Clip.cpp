/// <summary>
/// Implements the clip class.
/// </summary>
#include "Clip.h"

using namespace System::Collections::Generic;

CPPCli::Clip::Clip(VxSdk::IVxClip* vxClip) {
    _clip = vxClip;
}

CPPCli::Clip::!Clip() {
    _clip->Delete();
    _clip = nullptr;
}

List<CPPCli::DataInterface^>^ CPPCli::Clip::_GetDataInterfaces() {
    // Create a list of managed export objects
    List<DataInterface^>^ mlist = gcnew List<DataInterface^>();
    for (int i = 0; i < _clip->dataInterfaceSize; i++)
        mlist->Add(gcnew DataInterface(_clip->dataInterfaces[i]));

    return mlist;
}

int GetFilterSize(CPPCli::SnapshotFilter^ filter) {
    int filterSize = 0;

    // Increment the filter size for each filter present
    if (filter->EndTime != System::DateTime::MinValue)
        filterSize++;

    if (filter->StartTime != System::DateTime::MinValue)
        filterSize++;

    if (filter->Offset != NULL)
        filterSize++;

    if (filter->Width != NULL)
        filterSize++;

    return filterSize;
}

System::String^ CPPCli::Clip::GetSnapshotEndpoint(SnapshotFilter^ filter) {
    // Get the filter count
    const int filterSize = GetFilterSize(filter);
    // Create a VxSnapshotFilter object
    VxSdk::VxSnapshotFilter* vxFilter;

    // If there are filters present add them to vxFilter, otherwise set it to nullptr
    if (filterSize > 0) {
        vxFilter = new VxSdk::VxSnapshotFilter[filterSize];

        // If a filter has been set, add the the filter item with its value
        int filterPosition = 0;
        if (filter->EndTime != System::DateTime::MinValue) {
            vxFilter[filterPosition].key = VxSdk::VxSnapshotFilterItem::kEndTime;
            VxSdk::Utilities::StrCopySafe(vxFilter[filterPosition].value, Utils::ConvertDateTimeToChar(filter->EndTime));
            filterPosition++;
        }
        if (filter->StartTime != System::DateTime::MinValue) {
            vxFilter[filterPosition].key = VxSdk::VxSnapshotFilterItem::kStartTime;
            VxSdk::Utilities::StrCopySafe(vxFilter[filterPosition].value, Utils::ConvertDateTimeToChar(filter->StartTime));
            filterPosition++;
        }
        if (filter->Offset != NULL) {
            vxFilter[filterPosition].key = VxSdk::VxSnapshotFilterItem::kOffset;
            VxSdk::Utilities::StrCopySafe(vxFilter[filterPosition].value, Utils::ConvertSysString(filter->Offset.ToString()));
            filterPosition++;
        }
        if (filter->Width != NULL) {
            vxFilter[filterPosition].key = VxSdk::VxSnapshotFilterItem::kWidth;
            VxSdk::Utilities::StrCopySafe(vxFilter[filterPosition].value, Utils::ConvertSysString(filter->Width.ToString()));
        }
    }
    else {
        vxFilter = nullptr;
    }

    char* snapshotEndpoint = nullptr;
    int size = 0;

    // If the rtsp uri is not available on the datasource the result will return VxSdk::VxResult::kActionUnavailable,
    // otherwise VxSdk::VxResult::kInsufficientSize
    VxSdk::VxResult::Value result = _clip->GetSnapshotEndpoint(vxFilter, filterSize, snapshotEndpoint, size);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for rtspEndpoint
        snapshotEndpoint = new char[size];
        // The result should now be kOK since we have allocated enough space
        _clip->GetSnapshotEndpoint(vxFilter, filterSize, snapshotEndpoint, size);
    }
    return gcnew System::String(snapshotEndpoint);
}
