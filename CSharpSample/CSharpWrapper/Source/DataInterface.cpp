/// <summary>
/// Implements the data interface class.
/// </summary>
#include "DataInterface.h"

CPPCli::DataInterface::DataInterface(VxSdk::IVxDataInterface* vxDataInterface) {
    _dataInterface = vxDataInterface;
}
