/// <summary>
/// Implements the resourceRel class.
/// </summary>

#include "ResourceRel.h"

using namespace System::Collections::Generic;

CPPCli::ResourceRel::ResourceRel(VxSdk::IVxResourceRel* vxResourceRel) {
    _resourceRel = vxResourceRel;
}

CPPCli::ResourceRel::!ResourceRel() {
    _resourceRel->Delete();
    _resourceRel = nullptr;
}


CPPCli::Results::Value CPPCli::ResourceRel::Refresh() {
    return (CPPCli::Results::Value)_resourceRel->Refresh();
}

CPPCli::DataSource^ CPPCli::ResourceRel::_GetResource() {
    // Get the data source object
    VxSdk::IVxDataSource* dataSource = nullptr;
    VxSdk::VxResult::Value result = _resourceRel->GetResource(dataSource);

    // Return the data source if GetResource was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::DataSource(dataSource);

    return nullptr;
}
