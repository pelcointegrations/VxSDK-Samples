/// <summary>
/// Implements the license feature class.
/// </summary>
#include "LicenseFeature.h"

using namespace System::Collections::Generic;

CPPCli::LicenseFeature::LicenseFeature(VxSdk::IVxLicenseFeature* vxLicenseFeature) {
    _licenseFeature = vxLicenseFeature;
}

CPPCli::LicenseFeature::!LicenseFeature() {
    _licenseFeature->Delete();
    _licenseFeature = nullptr;
}

CPPCli::Results::Value CPPCli::LicenseFeature::Refresh() {
    return (CPPCli::Results::Value)_licenseFeature->Refresh();
}

List<CPPCli::Device^>^ CPPCli::LicenseFeature::_GetCommissionedDevices() {
    // Create a list of managed device objects
    List<CPPCli::Device^>^ mlist = gcnew List<CPPCli::Device^>();
    // Create a collection of unmanaged device objects
    VxSdk::VxCollection<VxSdk::IVxDevice**> devices;

    // Make the GetCommissionedDevices call, which will return with the total count of devices, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _licenseFeature->GetCommissionedDevices(devices);
    // Unless there are no devices on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetCommissionedDevices call
        devices.collection = new VxSdk::IVxDevice*[devices.collectionSize];
        result = _licenseFeature->GetCommissionedDevices(devices);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < devices.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Device(devices.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] devices.collection;
    }
    return mlist;
}
