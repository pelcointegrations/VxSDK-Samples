/// <summary>
/// Implements the schedule trigger class.
/// </summary>
#include "ScheduleTrigger.h"

using namespace System;
using namespace System::Collections::Generic;

CPPCli::ScheduleTrigger::ScheduleTrigger(VxSdk::IVxScheduleTrigger* vxScheduleTrigger) {
    _scheduleTrigger = vxScheduleTrigger;
}

CPPCli::ScheduleTrigger::!ScheduleTrigger() {
    _scheduleTrigger->Delete();
    _scheduleTrigger = nullptr;
}

CPPCli::Results::Value CPPCli::ScheduleTrigger::Refresh() {
    return (CPPCli::Results::Value)_scheduleTrigger->Refresh();
}
