/// <summary>
/// Implements the data object class.
/// </summary>

#include "DataObject.h"
#include "User.h"

using namespace System::Collections::Generic;

CPPCli::DataObject::DataObject(VxSdk::IVxDataObject* vxDataObject) {
    _dataObject = vxDataObject;
}

CPPCli::DataObject::!DataObject() {
    _dataObject->Delete();
    _dataObject = nullptr;
}

CPPCli::Results::Value CPPCli::DataObject::Refresh() {
    return (CPPCli::Results::Value)_dataObject->Refresh();
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

CPPCli::User^ CPPCli::DataObject::_GetOwner() {
    // Get the user object
    VxSdk::IVxUser* user = nullptr;
    VxSdk::VxResult::Value result = _dataObject->GetOwner(user);

    // Return the user if GetOwner was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::User(user);

    // Return nullptr if GetOwner is unsuccessful
    return nullptr;
}

void CPPCli::DataObject::_SetData(System::String^ data) {
    // Copy the data string to a new char
    int dataSize = data->Length + 1;
    char* newData = new char[dataSize];
    VxSdk::Utilities::StrCopySafe(newData, Utils::ConvertSysString(data), dataSize);

    // Set the data value for the data object
    _dataObject->SetData(newData);
}
