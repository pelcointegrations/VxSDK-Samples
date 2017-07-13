/// <summary>
/// Implements the alarm input class.
/// </summary>
#include "AlarmInput.h"
#include "Device.h"

using namespace System::Collections::Generic;

CPPCli::AlarmInput::AlarmInput(VxSdk::IVxAlarmInput* vxAlarmInput) {
    _alarmInput = vxAlarmInput;
}

CPPCli::AlarmInput::!AlarmInput() {
    _alarmInput->Delete();
    _alarmInput = nullptr;
}

CPPCli::Results::Value CPPCli::AlarmInput::Refresh() {
    return (CPPCli::Results::Value)_alarmInput->Refresh();
}

CPPCli::Device^ CPPCli::AlarmInput::_GetHostDevice() {
    // Get the host device
    VxSdk::IVxDevice* device = nullptr;
    VxSdk::VxResult::Value result = _alarmInput->GetHostDevice(device);

    // Return the host device if GetHostDevice was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::Device(device);

    return nullptr;
}
