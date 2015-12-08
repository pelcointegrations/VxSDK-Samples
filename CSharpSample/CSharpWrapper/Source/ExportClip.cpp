/// <summary>
/// Implements the export clip class.
/// </summary>
#include "ExportClip.h"

CPPCli::ExportClip::ExportClip(VxSdk::IVxExportClip* vxExportClip) {
    _exportClip = vxExportClip;
}
