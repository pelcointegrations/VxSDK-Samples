/// <summary>
/// Implements the data object class.
/// </summary>

#include "DataObject.h"

using namespace System::Collections::Generic;

CPPCli::DataObject::DataObject(VxSdk::IVxDataObject* vxDataObject) {
    _dataObject = vxDataObject;
}

CPPCli::DataObject::!DataObject() {
    _dataObject->Delete();
    _dataObject = nullptr;
}

System::String^ CPPCli::DataObject::_GetData() {
    char* data = nullptr;
    int size = 0;

    // If the data is not available on the data object the result will return VxSdk::VxResult::kActionUnavailable,
    // otherwise VxSdk::VxResult::kInsufficientSize
    VxSdk::VxResult::Value result = _dataObject->GetData(data, size);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for the data
        data = new char[size];
        // The result should now be kOK since we have allocated enough space
        _dataObject->GetData(data, size);
    }
    return gcnew System::String(data);
}
