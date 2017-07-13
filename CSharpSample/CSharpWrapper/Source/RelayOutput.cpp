/// <summary>
/// Implements the relay output class.
/// </summary>
#include "Device.h"
#include "RelayOutput.h"

using namespace System::Collections::Generic;

CPPCli::RelayOutput::RelayOutput(VxSdk::IVxRelayOutput* vxRelayOutput) {
    _relayOutput = vxRelayOutput;
}

CPPCli::RelayOutput::!RelayOutput() {
    _relayOutput->Delete();
    _relayOutput = nullptr;
}

CPPCli::Results::Value CPPCli::RelayOutput::Refresh() {
    return (CPPCli::Results::Value)_relayOutput->Refresh();
}

CPPCli::Device^ CPPCli::RelayOutput::_GetHostDevice() {
    // Get the host device
    VxSdk::IVxDevice* device = nullptr;
    VxSdk::VxResult::Value result = _relayOutput->GetHostDevice(device);

    // Return the host device if GetHostDevice was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::Device(device);

    return nullptr;
}

void CPPCli::RelayOutput::_SetRelayState(RelayStates state) {
    switch(state) {
        case RelayStates::Active:
            _relayOutput->Activate();
            return;
        case RelayStates::Inactive:
            _relayOutput->Deactivate();
            return;
        case RelayStates::Unknown:
            return;
    }
}
