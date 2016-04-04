/// <summary>
/// Implements the schedule class.
/// </summary>
#include "Schedule.h"

using namespace System::Collections::Generic;

CPPCli::Schedule::Schedule(VxSdk::IVxSchedule* vxSchedule) {
    _schedule = vxSchedule;
}

CPPCli::Schedule::!Schedule() {
    _schedule->Delete();
    _schedule = nullptr;
}

List<CPPCli::DataSource^>^ CPPCli::Schedule::GetLinks() {
    // Create a list of managed data source objects
    List<CPPCli::DataSource^>^ mlist = gcnew List<CPPCli::DataSource^>();
    // Create a collection of unmanaged data source objects
    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;

    // Make the GetLinks call, which will return with the total data source count, this allows the client to allocate memory
    VxSdk::VxResult::Value result = _schedule->GetLinks(dataSources);
    // The result should be kInsufficientSize if the number of data sources on the system are greater than 0
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxDataSource collection
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = _schedule->GetLinks(dataSources);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < dataSources.collectionSize; i++) {
                mlist->Add(gcnew CPPCli::DataSource(dataSources.collection[i]));
            }
        }
        // Remove the memory we previously allocated to the collection
        delete[] dataSources.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::Schedule::Link(List<CPPCli::DataSource^>^ dataSources) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of data sources
    for (int i = 0; i < dataSources->Count; i++) {
        // Link the data sources to the schedule
        result = _schedule->Link(*dataSources[i]->_dataSource);
    }

    // Unless there was an issue linking the data sources the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::Schedule::Unlink(List<CPPCli::DataSource^>^ dataSources) {
    VxSdk::VxResult::Value result = VxSdk::VxResult::kUnknownError;

    // Iterate the managed list of data sources
    for (int i = 0; i < dataSources->Count; i++) {
        // UnLink the data sources to the schedule
        result = _schedule->UnLink(*dataSources[i]->_dataSource);
    }

    // Unless there was an issue unlinking the data sources the result should be VxSdk::VxResult::kOK
    return CPPCli::Results::Value(result);
}

List<CPPCli::ScheduleTrigger^>^ CPPCli::Schedule::_GetScheduleTriggers() {
    // Create a list of managed trigger objects
    List<CPPCli::ScheduleTrigger^>^ mlist = gcnew List<CPPCli::ScheduleTrigger^>();
    // Create a collection of unmanaged trigger objects
    VxSdk::VxCollection<VxSdk::IVxScheduleTrigger**> scheduleTriggers;

    // Make the GetScheduleTriggers call, which will return with the total trigger count,
    // this allows the client to allocate memory
    VxSdk::VxResult::Value result = _schedule->GetScheduleTriggers(scheduleTriggers);
    // Unless there are no triggers associated with the schedule, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the IVxScheduleTrigger collection
        scheduleTriggers.collection = new VxSdk::IVxScheduleTrigger*[scheduleTriggers.collectionSize];
        result = _schedule->GetScheduleTriggers(scheduleTriggers);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < scheduleTriggers.collectionSize; i++)
                mlist->Add(gcnew CPPCli::ScheduleTrigger(scheduleTriggers.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] scheduleTriggers.collection;
    }
    return mlist;
}
