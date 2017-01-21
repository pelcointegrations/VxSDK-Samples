// Declares the new device class.
#ifndef NewDevice_h__
#define NewDevice_h__

#include "Device.h"

namespace CPPCli {

    /// <summary>
    /// The NewDevice class represents a new device.
    /// </summary>
    public ref class NewDevice {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewDevice() {
            _newDevice = new VxSdk::VxNewDevice();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewDevice">The new device.</param>
        NewDevice(VxSdk::VxNewDevice* vxNewDevice) {
            _newDevice = vxNewDevice;
        }

        /// <summary>
        /// Gets or sets the unique identifier of the associated data storage.
        /// </summary>
        /// <value>The associated data storage unique identifier.</value>
        property System::String^ DataStorageId {
        public:
            System::String^ get() { return gcnew System::String(_newDevice->dataStorageId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDevice->dataStorageId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the associated driver type identifier.
        /// </summary>
        /// <value>The associated driver type identifier.</value>
        property System::String^ DriverType {
        public:
            System::String^ get() { return gcnew System::String(_newDevice->driverType); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDevice->driverType, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the ID of the device.
        /// </summary>
        /// <value>The ID.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_newDevice->id); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDevice->id, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the IP of the device.
        /// </summary>
        /// <value>The IP.</value>
        property System::String^ Ip {
        public:
            System::String^ get() { return gcnew System::String(_newDevice->ip); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDevice->ip, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the friendly name of the device.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_newDevice->name); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDevice->name, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the account password used to communicate with the device, if any.
        /// </summary>
        /// <value>The password.</value>
        property System::String^ Password {
        public:
            System::String^ get() { return gcnew System::String(_newDevice->password); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDevice->password, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets whether to have this device automatically commissioned when created.
        /// </summary>
        /// <value><c>true</c> to automatically commissioned the device, otherwise <c>false</c>.</value>
        property bool ShouldAutoCommission {
        public:
            bool get() { return _newDevice->shouldAutoCommission; }
            void set(bool value) { _newDevice->shouldAutoCommission = value; }
        }

        /// <summary>
        /// Gets or sets the type of device.
        /// </summary>
        /// <value>The device <see cref="Device::Types">Type</see>.</value>
        property Device::Types Type {
        public:
            Device::Types get() { return (Device::Types)_newDevice->type; }
            void set(Device::Types value) { _newDevice->type = (VxSdk::VxDeviceType::Value)value; }
        }

        /// <summary>
        /// Gets or sets the account username used to communicate with the device, if any.
        /// </summary>
        /// <value>The username.</value>
        property System::String^ Username {
        public:
            System::String^ get() { return gcnew System::String(_newDevice->username); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDevice->username, Utils::ConvertSysString(value)); }
        }

    internal:
        VxSdk::VxNewDevice* _newDevice;
    };
}
#endif // NewDevice_h__
