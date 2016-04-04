// Declares the data storage class.
#ifndef DataStorage_h__
#define DataStorage_h__

#include "Device.h"
#include "DeviceAssignment.h"
#include "NewDeviceAssignment.h"
#include "Driver.h"

namespace CPPCli {

    /// <summary>
    /// The DataStorage class represents a data storage provider in the system (e.g. an NSM5200 
    /// storage pool or a VxRecorder) hosted by a system device. The DataStorage can be directed
    /// to store media produced by a device by assigning the device to it.
    /// </summary>
    public ref class DataStorage {
    public:

        /// <summary>
        /// Values that represent data storage hardware types.
        /// </summary>
        enum class DataStorageTypes {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>A Digital Sentry device.</summary>
            DigitalSentry,

            /// <summary>An NSM network video recorder device.</summary>
            NSM,

            /// <summary>A VideoXpert storage device.</summary>
            VideoXpertStorage,
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxDataStorage">The vx data storage.</param>
        DataStorage(VxSdk::IVxDataStorage* vxDataStorage);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~DataStorage() {
            this->!DataStorage();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !DataStorage();

        /// <summary>
        /// Assign a device to this data storage to be managed and recorded based on its configuration.
        /// </summary>
        /// <param name="newDeviceAssignment">The new device assignment to be added to the data storage.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of assigning the device.</returns>
        Results::Value AssignDevice(NewDeviceAssignment^ newDeviceAssignment);

        /// <summary>
        /// Unassign a device from this data storage.
        /// </summary>
        /// <param name="device">The device to be unassigned from the data storage.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of unassigning the device.</returns>
        Results::Value UnassignDevice(Device^ device);

        /// <summary>
        /// Gets the device assignments for this data storage.
        /// </summary>
        /// <value>A <c>List</c> of device assignments.</value>
        property System::Collections::Generic::List<CPPCli::DeviceAssignment^>^ DeviceAssignments {
        public:
            System::Collections::Generic::List<CPPCli::DeviceAssignment^>^ get() { return _GetDeviceAssignments(); }
        }

        /// <summary>
        /// Gets the data sources assigned to this data storage.
        /// </summary>
        /// <value>A <c>List</c> of data sources.</value>
        property System::Collections::Generic::List<CPPCli::DataSource^>^ DataSources {
        public:
            System::Collections::Generic::List<CPPCli::DataSource^>^ get() { return _GetDataSources(); }
        }

        /// <summary>
        /// Gets the device that hosts this data storage.
        /// </summary>
        /// <value>The host device.</value>
        property CPPCli::Device^ HostDevice {
        public:
            CPPCli::Device^ get() { return _GetHostDevice(); }
        }

        /// <summary>
        /// Gets the drivers provided by this data storage.
        /// </summary>
        /// <value>A <c>List</c> of drivers.</value>
        property System::Collections::Generic::List<CPPCli::Driver^>^ Drivers {
        public:
            System::Collections::Generic::List<CPPCli::Driver^>^ get() { return _GetDrivers(); }
        }

        /// <summary>
        /// Gets the unique identifier of the device.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_dataStorage->id); }
        }

        /// <summary>
        /// Gets the friendly name of the data storage.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_dataStorage->name); }
        }

        /// <summary>
        /// Gets the type of data storage.
        /// </summary>
        /// <value>The data storage <see cref="DataStorageTypes">type</see>.</value>
        property DataStorageTypes Type {
        public:
            DataStorageTypes get() { return DataStorageTypes(_dataStorage->type); }
        }

    internal:
        VxSdk::IVxDataStorage* _dataStorage;
        System::Collections::Generic::List<CPPCli::DeviceAssignment^>^ _GetDeviceAssignments();
        System::Collections::Generic::List<CPPCli::DataSource^>^ _GetDataSources();
        CPPCli::Device^ _GetHostDevice();
        System::Collections::Generic::List<CPPCli::Driver^>^ _GetDrivers();
    };
}
#endif // DataStorage_h__
