/// <summary>
/// Implements the Marker class.
/// </summary>
#include "Marker.h"
#include "Drawing.h"

using namespace System::Collections::Generic;

CPPCli::Marker::Marker(VxSdk::IVxMarker* vxMarker) {
    _marker = vxMarker;
}

CPPCli::Marker::!Marker() {
    _marker->Delete();
    _marker = nullptr;
}

CPPCli::Results::Value CPPCli::Marker::DeleteAssociation() {
    return (CPPCli::Results::Value)_marker->DeleteAssociation();
}

CPPCli::DataSource^ CPPCli::Marker::GetAssociation() {
    // Get the data source
    VxSdk::IVxDataSource* dataSource = nullptr;
    VxSdk::VxResult::Value result = _marker->GetAssociation(dataSource);

    // Return the data source if GetAssociation was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::DataSource(dataSource);

    return nullptr;
}

CPPCli::Results::Value CPPCli::Marker::Refresh() {
    return (CPPCli::Results::Value)_marker->Refresh();
}

CPPCli::Results::Value CPPCli::Marker::SetAssociation(DataSource^ dataSource) {
    // Make the call to set the associated data source
    VxSdk::VxResult::Value result = _marker->SetAssociation(*dataSource->_dataSource);
    // Unless there was an issue associating the data source the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Marker::SetCoordinates(float x, float y) {
    return (CPPCli::Results::Value)_marker->SetCoordinates(x, y);
}

CPPCli::Drawing^ CPPCli::Marker::_GetDrawing() {
    // Get the drawing
    VxSdk::IVxDrawing* drawing = nullptr;
    VxSdk::VxResult::Value result = _marker->GetDrawing(drawing);

    // Return the drawing if GetDrawing was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::Drawing(drawing);

    return nullptr;
}
