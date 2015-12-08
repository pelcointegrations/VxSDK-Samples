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

List<CPPCli::ExportClip^>^ CPPCli::Export::_GetClips() {
    // Create a list of managed export objects
    List<CPPCli::ExportClip^>^ mlist = gcnew List<CPPCli::ExportClip^>();
    // Add each clip in the export to the list
    for (int i = 0; i < _export->exportClipSize; i++)
        mlist->Add(gcnew CPPCli::ExportClip(_export->exportClips[i]));

    return mlist;
}
