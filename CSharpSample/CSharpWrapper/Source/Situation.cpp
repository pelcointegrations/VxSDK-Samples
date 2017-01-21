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

CPPCli::Results::Value CPPCli::Situation::AddNotification(CPPCli::Notification^ notification) {
    // Add the notification to the situation
    VxSdk::VxResult::Value result = _situation->AddNotification(*notification->_notification);
    // Unless there was an issue adding the notification the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Situation::Link(CPPCli::DataSource^ dataSource) {
    // Link a data source to a situation
    VxSdk::VxResult::Value result = _situation->Link(*dataSource->_dataSource);
    // Unless there was an issue linking the data source the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Situation::Link(CPPCli::Device^ device) {
    // Link a device to a situation
    VxSdk::VxResult::Value result = _situation->Link(*device->_device);
    // Unless there was an issue linking the device the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Situation::Refresh() {
    return (CPPCli::Results::Value)_situation->Refresh();
}

CPPCli::Results::Value CPPCli::Situation::RemoveNotification(CPPCli::Notification^ notification) {
    // Remove the notification to the situation
    VxSdk::VxResult::Value result = _situation->RemoveNotification(*notification->_notification);
    // Unless there was an issue removing the notification the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Situation::UnLink(CPPCli::DataSource^ dataSource) {
    // Unlink a data source from a situation
    VxSdk::VxResult::Value result = _situation->UnLink(*dataSource->_dataSource);
    // Unless there was an issue unlinking the data source the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Situation::UnLink(CPPCli::Device^ device) {
    // Unlink a device from a situation
    VxSdk::VxResult::Value result = _situation->UnLink(*device->_device);
    // Unless there was an issue unlinking the device the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

System::Collections::Generic::List<CPPCli::DataSource^>^ CPPCli::Situation::_GetLinkedDataSources() {
    // Create a list of managed data sources
    List<CPPCli::DataSource^>^ mlist = gcnew List<CPPCli::DataSource^>();
    // Create a collection of unmanaged data sources
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetLinks call, which will return with the total data source count, this
    // allows the client to allocate memory.
    VxSdk::VxResult::Value result = _situation->GetLinks(dataSources);
    // As long as there are data sources linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataSource collection
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _situation->GetLinks(dataSources);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataSources.collectionSize; i++)
                mlist->Add(gcnew CPPCli::DataSource(dataSources.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataSources.collection;
    }
    return mlist;
}

System::Collections::Generic::List<CPPCli::Device^>^ CPPCli::Situation::_GetLinkedDevices() {
    // Create a list of managed devices
    List<CPPCli::Device^>^ mlist = gcnew List<CPPCli::Device^>();
    // Create a collection of unmanaged devices
    VxSdk::VxCollection<VxSdk::IVxDevice**> devices;

    // Make the GetLinks call, which will return with the total device count, this allows the
    // client to allocate memory.
    VxSdk::VxResult::Value result = _situation->GetLinks(devices);
    // As long as there are devices linked the result should be VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDevice collection
        devices.collection = new VxSdk::IVxDevice*[devices.collectionSize];
        result = _situation->GetLinks(devices);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < devices.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Device(devices.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] devices.collection;
    }
    return mlist;
}

List<CPPCli::Notification^>^ CPPCli::Situation::_GetNotifications() {
    // Create a list of managed notification objects
    List<CPPCli::Notification^>^ mlist = gcnew List<CPPCli::Notification^>();
    // Create a collection of unmanaged notification objects
    VxSdk::VxCollection<VxSdk::IVxNotification**> notifications;

    // Make the GetNotifications call, which will return with the total notification count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _situation->GetNotifications(notifications);
    // The result should be kInsufficientSize if the number of notifications assigned to the situation are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxNotification collection
        notifications.collection = new VxSdk::IVxNotification*[notifications.collectionSize];
        result = _situation->GetNotifications(notifications);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < notifications.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::Notification(notifications.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] notifications.collection;
    }
    return mlist;
}

List<int>^ CPPCli::Situation::_GetSnoozeIntervals() {
    // Create a managed list of integers
    List<int>^ mlist = gcnew List<int>();
    // Add each snooze interval to the list
    for (int i = 0; i < _situation->snoozeIntervalSize; i++)
        mlist->Add(_situation->snoozeIntervals[i]);

    return mlist;
}
