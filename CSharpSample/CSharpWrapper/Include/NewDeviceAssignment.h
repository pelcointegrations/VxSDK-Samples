// Declares the new device assignment class.
#ifndef NewDeviceAssignment_h__
#define NewDeviceAssignment_h__

#include "Utils.h"
#include "VxNewDeviceAssignment.h"

namespace CPPCli {

    /// <summary>
    /// The NewDeviceAssignment class represents a new device assignment.
    /// </summary>
    public ref class NewDeviceAssignment {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewDeviceAssignment() {
            _newDeviceAssignment = new VxSdk::VxNewDeviceAssignment();
            _dataSources = gcnew System::Collections::Generic::List<System::String^>();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewDeviceAssignment">The new device assignment.</param>
        NewDeviceAssignment(VxSdk::VxNewDeviceAssignment* vxNewDeviceAssignment) {
            _newDeviceAssignment = vxNewDeviceAssignment;
        }

        /// <summary>
        /// Gets or sets the unique ID of the device to assign.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ DeviceId {
        public:
            System::String^ get() { return gcnew System::String(_newDeviceAssignment->deviceId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDeviceAssignment->deviceId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the type identifier of the driver to use for this device.
        /// </summary>
        /// <value>The driver type.</value>
        property System::String^ DriverType {
        public:
            System::String^ get() { return gcnew System::String(_newDeviceAssignment->driverType); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDeviceAssignment->driverType, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets the data sources that will be included in this device assignment.
        /// </summary>
        /// <value>A <c>List</c> of data sources.</value>
        property System::Collections::Generic::List<System::String^>^ DataSourceIds {
        public:
            System::Collections::Generic::List<System::String^>^ get() { return _dataSources; }
        }

    internal:
        VxSdk::VxNewDeviceAssignment* _newDeviceAssignment;
        System::Collections::Generic::List<System::String^>^ _dataSources;
    };
}
#endif // NewDeviceAssignment_h__
