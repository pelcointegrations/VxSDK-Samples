/// <summary>
/// Implements the situation class.
/// </summary>
#include "Situation.h"

using namespace System;
using namespace System::Collections::Generic;

CPPCli::Situation::Situation(VxSdk::IVxSituation* vxSituation) {
    _situation = vxSituation;
}

CPPCli::Situation::!Situation() {
    _situation->Delete();
    _situation = nullptr;
}

CPPCli::Results::Value CPPCli::Situation::Link(CPPCli::Device^ device) {
    // Link a device to a situation
    VxSdk::VxResult::Value result = _situation->Link(*device->_device);
    // Unless there was an issue linking the device the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Situation::Link(CPPCli::DataSource^ dataSource) {
    // Link a data source to a situation
    VxSdk::VxResult::Value result = _situation->Link(*dataSource->_dataSource);
    // Unless there was an issue linking the data source the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Situation::UnLink(CPPCli::Device^ device) {
    // Unlink a device from a situation
    VxSdk::VxResult::Value result = _situation->UnLink(*device->_device);
    // Unless there was an issue unlinking the device the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Situation::UnLink(CPPCli::DataSource^ dataSource) {
    // Unlink a data source from a situation
    VxSdk::VxResult::Value result = _situation->UnLink(*dataSource->_dataSource);
    // Unless there was an issue unlinking the data source the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<int>^ CPPCli::Situation::_GetSnoozeIntervals() {
    // Create a managed list of integers
    List<int>^ mlist = gcnew List<int>();
    // Add each snooze interval to the list
    for (int i = 0; i < _situation->snoozeIntervalSize; i++)
        mlist->Add(_situation->snoozeIntervals[i]);

    return mlist;
}

List<String^>^ CPPCli::Situation::_GetNotificationIds() {
    // Create a managed list of strings
    List<String^>^ mlist = gcnew List<String^>();
    // Add each notification id to the list
    for (int i = 0; i < _situation->notificationIdSize; i++)
        mlist->Add(gcnew String(_situation->notificationIds[i]));

    return mlist;
}
