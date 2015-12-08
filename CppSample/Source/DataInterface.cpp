#include "stdafx.h"
#include "DataInterface.h"

CPPConsole::DataInterface::DataInterface(VxSdk::IVxDataInterface* vxDataInterface) {
    _dataInterface = vxDataInterface;
}


CPPConsole::DataInterface::~DataInterface() {
}
