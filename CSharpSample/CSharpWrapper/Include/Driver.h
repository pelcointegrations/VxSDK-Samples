// Declares the driver class.
#ifndef Driver_h__
#define Driver_h__

#include "VxSdk.h"

namespace CPPCli {
    ref class DataStorage;

    /// <summary>
    /// The Driver class represents a device communication driver.
    /// </summary>
    public ref class Driver {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxDriver">The vx driver.</param>
        Driver(VxSdk::IVxDriver* vxDriver);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Driver() {
            this->!Driver();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Driver();

        /// <summary>
        /// Gets the data storage that hosts this driver.
        /// </summary>
        /// <value>The data storage.</value>
        property CPPCli::DataStorage^ DataStorage {
        public:
            CPPCli::DataStorage^ get() { return _GetDataStorage(); }
        }

        /// <summary>
        /// Gets the friendly name of the driver.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_driver->name); }
        }

        /// <summary>
        /// Gets the driver type identifier.
        /// </summary>
        /// <value>The driver type identifier.</value>
        property System::String^ Type {
        public:
            System::String^ get() { return gcnew System::String(_driver->type); }
        }

        /// <summary>
        /// Gets the name of the vendor that manufactured the device that the driver is for.
        /// </summary>
        /// <value>The name of the vendor.</value>
        property System::String^ Vendor {
        public:
            System::String^ get() { return gcnew System::String(_driver->vendor); }
        }

        /// <summary>
        /// Gets the driver version number.
        /// </summary>
        /// <value>The version number.</value>
        property System::String^ Version {
        public:
            System::String^ get() { return gcnew System::String(_driver->version); }
        }

    internal:
        VxSdk::IVxDriver* _driver;
        CPPCli::DataStorage^ _GetDataStorage();
    };
}
#endif // Driver_h__
