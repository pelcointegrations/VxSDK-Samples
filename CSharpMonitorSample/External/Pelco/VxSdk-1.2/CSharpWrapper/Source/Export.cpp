/// <summary>
/// Implements the export class.
/// </summary>
#include "Export.h"

using namespace System::Collections::Generic;

CPPCli::Export::Export(VxSdk::IVxExport* vxExport) {
    _export = vxExport;
}

CPPCli::Export::!Export() {
    _export->Delete();
    _export = nullptr;
}

CPPCli::Results::Value CPPCli::Export::Refresh() {
    return (CPPCli::Results::Value)_export->Refresh();
}

List<CPPCli::ExportClip^>^ CPPCli::Export::_GetClips() {
    // Create a list of managed export objects
    List<CPPCli::ExportClip^>^ mlist = gcnew List<CPPCli::ExportClip^>();
    // Add each clip in the export to the list
    for (int i = 0; i < _export->exportClipSize; i++)
        mlist->Add(gcnew CPPCli::ExportClip(_export->exportClips[i]));

    return mlist;
}

CPPCli::User^ CPPCli::Export::_GetOwner() {
    // Get the user that owns this export
    VxSdk::IVxUser* user = nullptr;
    VxSdk::VxResult::Value result = _export->GetOwner(user);

    // Return the user if GetOwner was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::User(user);

    return nullptr;
}
