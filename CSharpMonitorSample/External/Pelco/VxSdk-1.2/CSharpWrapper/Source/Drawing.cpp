/// <summary>
/// Implements the Drawing class.
/// </summary>
#include "Drawing.h"

using namespace System::Collections::Generic;

CPPCli::Drawing::Drawing(VxSdk::IVxDrawing* vxDrawing) {
    _drawing = vxDrawing;
}

CPPCli::Drawing::!Drawing() {
    _drawing->Delete();
    _drawing = nullptr;
}

CPPCli::Results::Value CPPCli::Drawing::AddMarker(NewMarker^ newMarker) {
    // Create a new marker object and populate its fields using newMarker
    VxSdk::VxNewMarker vxNewMarker;
    VxSdk::Utilities::StrCopySafe(vxNewMarker.associatedDataSourceId, Utils::ConvertSysString(newMarker->AssociatedDataSourceId));
    VxSdk::Utilities::StrCopySafe(vxNewMarker.name, Utils::ConvertSysString(newMarker->Name));
    vxNewMarker.direction = newMarker->Direction;
    vxNewMarker.x = newMarker->X;
    vxNewMarker.y = newMarker->Y;

    // Make the call to add the marker to the drawing
    VxSdk::VxResult::Value result = _drawing->AddMarker(vxNewMarker);
    // Unless there was an issue creating the marker the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Drawing::DeleteImage() {
    return (CPPCli::Results::Value)_drawing->DeleteImage();
}

CPPCli::Results::Value CPPCli::Drawing::DeleteLock() {
    // Get the lock for this drawing
    VxSdk::IVxResourceLock* lock = nullptr;
    VxSdk::VxResult::Value result = _drawing->GetLock(lock);

    // Delete the lock if present
    if (result == VxSdk::VxResult::kOK && lock != nullptr)
        return (CPPCli::Results::Value)lock->DeleteResourceLock();

    return (CPPCli::Results::Value)result;
}

CPPCli::Results::Value CPPCli::Drawing::DeleteMarker(Marker^ marker) {
    return (CPPCli::Results::Value)marker->_marker->DeleteMarker();
}

System::String^ CPPCli::Drawing::GetImageUri() {
    char* imageEndpoint = nullptr;
    int size = 0;

    // If the rtsp uri is not available on the datasource the result will return VxSdk::VxResult::kActionUnavailable,
    // otherwise VxSdk::VxResult::kInsufficientSize
    VxSdk::VxResult::Value result = _drawing->GetImage(imageEndpoint, size);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for rtspEndpoint
        imageEndpoint = new char[size];
        // The result should now be kOK since we have allocated enough space
        _drawing->GetImage(imageEndpoint, size);
    }
    return gcnew System::String(imageEndpoint);
}

CPPCli::ResourceLock^ CPPCli::Drawing::GetLock() {
    // Get the lock for this drawing
    VxSdk::IVxResourceLock* lock = nullptr;
    VxSdk::VxResult::Value result = _drawing->GetLock(lock);

    // Return the lock if present
    if (result == VxSdk::VxResult::kOK && lock != nullptr)
        return gcnew CPPCli::ResourceLock(lock);

    return nullptr;
}

CPPCli::Results::Value CPPCli::Drawing::Refresh() {
    return (CPPCli::Results::Value)_drawing->Refresh();
}

CPPCli::Results::Value CPPCli::Drawing::SetImage(System::String^ imagePath) {
    // Copy the image path to a new char
    int len = imagePath->Length + 1;
    char* image = new char[len];
    VxSdk::Utilities::StrCopySafe(image, Utils::ConvertSysString(imagePath), len);

    // Set the image path
    return (CPPCli::Results::Value)_drawing->SetImage(image);
}

CPPCli::Results::Value CPPCli::Drawing::SetLock() {
    return (CPPCli::Results::Value)_drawing->SetLock();
}

System::Collections::Generic::List<CPPCli::Marker^>^ CPPCli::Drawing::_GetMarkers() {
    // Create a list of managed marker objects
    List<CPPCli::Marker^>^ mlist = gcnew List<CPPCli::Marker^>();
    // Create a collection of unmanaged marker objects
    VxSdk::VxCollection<VxSdk::IVxMarker**> markers;

    // Make the GetMarkers call, which will return with the total marker count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _drawing->GetMarkers(markers);
    // Unless there are no markers on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxMarker collection
        markers.collection = new VxSdk::IVxMarker*[markers.collectionSize];
        result = _drawing->GetMarkers(markers);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < markers.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Marker(markers.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] markers.collection;
    }
    return mlist;
}
