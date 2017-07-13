/// <summary>
/// Implements the manual recording class.
/// </summary>
#include "ManualRecording.h"

using namespace System::Collections::Generic;

CPPCli::ManualRecording::ManualRecording(VxSdk::IVxManualRecording* vxManualRecording) {
    _manualRecording = vxManualRecording;
}

CPPCli::ManualRecording::!ManualRecording() {
    _manualRecording->Delete();
    _manualRecording = nullptr;
}

CPPCli::Results::Value CPPCli::ManualRecording::Refresh() {
    return (CPPCli::Results::Value)_manualRecording->Refresh();
}

CPPCli::DataSource^ CPPCli::ManualRecording::_GetDataSource() {
    // Get the data source
    VxSdk::IVxDataSource* dataSource = nullptr;
    VxSdk::VxResult::Value result = _manualRecording->GetDataSource(dataSource);

    // Return the data source if GetDataSource was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::DataSource(dataSource);

    return nullptr;
}
