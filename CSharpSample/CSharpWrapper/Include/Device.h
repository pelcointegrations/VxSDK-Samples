// Declares the device class.
#ifndef Device_h__
#define Device_h__

#include "DataSource.h"

namespace CPPCli {

    /// <summary>
    /// The Device class represents a particular physical device in the system.
    /// </summary>
    public ref class Device {
    public:

        /// <summary>
        /// Values that represent device types.
        /// </summary>
        enum class Types {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>A camera device.</summary>
            Camera,

            /// <summary>A VideoXpert Core device.</summary>
            Core,
            
            /// <summary>A VideoXpert Core/MediaGateway device.</summary>
            CoreMg,

            /// <summary>A decoder device.</summary>
            Decoder,

            /// <summary>An encoder device.</summary>
            Encoder,

            /// <summary>A system manager device.</summary>
            Manager,

            /// <summary>A VideoXpert MediaGateway device.</summary>
            Mg,

            /// <summary>A monitor device.</summary>
            Monitor,

            /// <summary>A network storage device.</summary>
            Recorder,
            
            /// <summary>A UDI device.</summary>
            Udi,
            
            /// <summary>A UI device.</summary>
            Ui,
            
            /// <summary>A VCD device.</summary>
            Vcd
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxDevice">The vx device.</param>
        Device(VxSdk::IVxDevice* vxDevice);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Device() {
            this->!Device();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Device();

        /// <summary>
        /// Gets the data sources hosted by this device.
        /// </summary>
        /// <value>A <c>List</c> of data sources.</value>
        property System::Collections::Generic::List<DataSource^>^ DataSources {
        public:
            System::Collections::Generic::List<DataSource^>^ get() { return _GetDataSources(); }
        }

        /// <summary>
        /// Gets a value indicating whether the device is commissioned.
        /// </summary>
        /// <value><c>true</c> if commissioned, <c>false</c> if not.</value>
        property bool IsCommissioned {
        public:
            bool get() { return _device->isCommissioned; }
        }

        /// <summary>
        /// Gets the unique identifier of the device.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_device->id); }
        }

        /// <summary>
        /// Gets the IP of the device.
        /// </summary>
        /// <value>The IP.</value>
        property System::String^ Ip {
        public:
            System::String^ get() { return gcnew System::String(_device->ip); }
        }

        /// <summary>
        /// Gets a value indicating whether a license is required for commissioning the device.
        /// </summary>
        /// <value><c>true</c> if license required, <c>false</c> if not.</value>
        property bool IsLicenseRequired {
        public:
            bool get() { return _device->isLicenseRequired; }
        }

        /// <summary>
        /// Gets the device model.
        /// </summary>
        /// <value>The model name.</value>
        property System::String^ Model {
        public:
            System::String^ get() { return gcnew System::String(_device->model); }
        }

        /// <summary>
        /// Gets the friendly name of the device.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_device->name); }
        }

        /// <summary>
        /// Gets the account password used to communicate with the device, if any.
        /// </summary>
        /// <value>The password.</value>
        property System::String^ Password {
        public:
            System::String^ get() { return gcnew System::String(_device->password); }
        }

        /// <summary>
        /// Gets a value indicating whether the device is running on Pelco hardware.
        /// </summary>
        /// <value><c>true</c> if a Pelco device, <c>false</c> if not.</value>
        property bool IsPelcoHardware {
        public:
            bool get() { return _device->isPelcoHardware; }
        }

        /// <summary>
        /// Gets the serial number.
        /// </summary>
        /// <value>The serial number.</value>
        property System::String^ Serial {
        public:
            System::String^ get() { return gcnew System::String(_device->serial); }
        }

        /// <summary>
        /// Gets the current operational state of the device.
        /// </summary>
        /// <value>The current state of the device.</value>
        property DataSource::States State {
        public:
            DataSource::States get() { return DataSource::States(_device->state); }
        }

        /// <summary>
        /// Gets the type of device.
        /// </summary>
        /// <value>The device <see cref="Types">Type</see>.</value>
        property Types Type {
        public:
            Types get() { return Types(_device->type); }
        }

        /// <summary>
        /// Gets the account username used to communicate with the device, if any.
        /// </summary>
        /// <value>The username.</value>
        property System::String^ Username {
        public:
            System::String^ get() { return gcnew System::String(_device->username); }
        }

        /// <summary>
        /// Gets the device vendor, if any.
        /// </summary>
        /// <value>The name of the devices vendor.</value>
        property System::String^ Vendor {
        public:
            System::String^ get() { return gcnew System::String(_device->vendor); }
        }

        /// <summary>
        /// Gets the current version of software running on the device.
        /// </summary>
        /// <value>The software version.</value>
        property System::String^ Version {
        public:
            System::String^ get() { return gcnew System::String(_device->version); }
        }

        /// <summary>
        /// Gets the virtual IP of the device, if any.
        /// </summary>
        /// <value>The virtual IP.</value>
        property System::String^ VirtualIp {
        public:
            System::String^ get() { return gcnew System::String(_device->virtualIp); }
        }

    internal:
        VxSdk::IVxDevice* _device;
        System::Collections::Generic::List<DataSource^>^ _GetDataSources();
    };
}
#endif // Device_h__
