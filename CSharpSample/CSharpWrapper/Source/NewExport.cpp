/// <summary>
/// Implements the new export class.
/// </summary>
#include "NewExport.h"

CPPCli::NewExport::NewExport(VxSdk::VxNewExport* vxNewExport) {
    _newExport = vxNewExport;
}

CPPCli::NewExport::!NewExport() {
    delete _newExport;
}
