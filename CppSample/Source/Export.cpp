#include "stdafx.h"
#include "Export.h"

CPPConsole::Export::Export(VxSdk::IVxExport* vxExport) {
    _export = vxExport;
}

CPPConsole::Export::~Export() {
    _export->Delete();
    _export = nullptr;
}
