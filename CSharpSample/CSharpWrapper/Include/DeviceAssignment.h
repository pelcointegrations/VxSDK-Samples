// Declares the device assignment class.
#ifndef DeviceAssignment_h__
#define DeviceAssignment_h__

#include "VxSdk.h"
#include "DataSource.h"

namespace CPPCli {
    ref class DataStorage;
    ref class Driver;

    /// <summary>
    /// The DeviceAssignment class represents a device assignment.
    /// </summary>
    public ref class DeviceAssignment {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxDeviceAssignment">The vx device assignment.</param>
        DeviceAssignment(VxSdk::IVxDeviceAssignment* vxDeviceAssignment);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~DeviceAssignment() {
            this->!DeviceAssignment();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !DeviceAssignment();

        /// <summary>
        /// Gets or sets the data sources assigned by this device assignment.
        /// </summary>
        /// <value>A <c>List</c> of data sources.</value>
        property System::Collections::Generic::List<CPPCli::DataSource^>^ DataSources {
        public:
            System::Collections::Generic::List<CPPCli::DataSource^>^ get() { return _GetDataSources(); }
            void set(System::Collections::Generic::List<CPPCli::DataSource^>^ value) { _SetDataSources(value); }
        }

        /// <summary>
        /// Gets the data storage that this device assignment is for.
        /// </summary>
        /// <value>The <see cref="DataStorage"/> for this assignment.</value>
        property CPPCli::DataStorage^ DataStorage {
        public:
            CPPCli::DataStorage^ get() { return _GetDataStorage(); }
        }

        /// <summary>
        /// Gets the assigned device.
        /// </summary>
        /// <value>The assigned <see cref="Device"/>.</value>
        property CPPCli::Device^ Device {
        public:
            CPPCli::Device^ get() { return _GetDevice(); }
        }

        /// <summary>
        /// Gets the assigned driver.
        /// </summary>
        /// <value>The assigned <see cref="Driver"/>.</value>
        property CPPCli::Driver^ Driver {
        public:
            CPPCli::Driver^ get() { return _GetDriver(); }
        }

        /// <summary>
        /// Gets or sets the driver type.
        /// </summary>
        /// <value>The driver type.</value>
        property System::String^ DriverType {
        public:
            System::String^ get() { return gcnew System::String(_deviceAssignment->driverType); }
            void set(System::String^ value) {
                char driverType[64];
                VxSdk::Utilities::StrCopySafe(driverType, Utils::ConvertSysStringNonConst(value));
                _deviceAssignment->SetDriverType(driverType);
            }
        }

        /// <summary>
        /// Gets the unique identifier of the device assignment.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_deviceAssignment->id); }
        }

    internal:
        VxSdk::IVxDeviceAssignment* _deviceAssignment;
        System::Collections::Generic::List<CPPCli::DataSource^>^ _GetDataSources();
        CPPCli::DataStorage^ _GetDataStorage();
        CPPCli::Device^ _GetDevice();
        CPPCli::Driver^ _GetDriver();
        void _SetDataSources(System::Collections::Generic::List<CPPCli::DataSource^>^ dataSources);
    };
}
#endif // DeviceAssignment_h__
