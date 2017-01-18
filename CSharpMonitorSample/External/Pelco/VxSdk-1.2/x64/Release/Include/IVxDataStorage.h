#ifndef IVxDataStorage_h__
#define IVxDataStorage_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxNewDeviceAssignment.h"
#include "IVxDevice.h"
#include "IVxDeviceAssignment.h"
#include "IVxDriver.h"

namespace VxSdk {
    /// <summary>
    /// Represents a data storage provider in the system (e.g. NSM5200 storage pool or VideoXpert Storage) hosted by a system
    /// device. The data storage can be directed to store media produced by a device by assigning the device to it.
    /// </summary>
    struct IVxDataStorage {
    public:
        /// <summary>
        /// Assign a device to this data storage to be managed and recorded based on its configuration.
        /// </summary>
        /// <param name="newDeviceAssignment">The device assignment to add to the data storage.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AssignDevice(VxNewDeviceAssignment& newDeviceAssignment) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the data sources assigned to this data storage.
        /// <para>Available filters: kAllTags, kCapturing, kId, kIp, kModifiedSince, kName, kNumber, kRecording, kState, kType, kUnassigned.</para>
        /// </summary>
        /// <param name="dataSourceCollection">A <see cref="VxCollection"/> of the assigned data sources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSources(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the devices assigned to this data storage.
        /// <para>Available filters: kDataSourceId, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceAssignmentCollection">A <see cref="VxCollection"/> of the assigned devices.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDeviceAssignments(VxCollection<IVxDeviceAssignment**>& deviceAssignmentCollection) const = 0;
        /// <summary>
        /// Gets all of the available device drivers that this data storage provides.
        /// <para>Available filters: kModifiedSince, kName, kVendor, kVersion.</para>
        /// </summary>
        /// <param name="driverCollection">A <see cref="VxCollection"/> of available drivers.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDrivers(VxCollection<IVxDriver**>& driverCollection) const = 0;
        /// <summary>
        /// Gets the host device of this data storage.
        /// </summary>
        /// <param name="hostDevice">The host device of this data storage.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Gets the storage configuration.
        /// </summary>
        /// <param name="storageConfig">The storage configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetStorageConfiguration(IVxConfiguration::Storage*& storageConfig) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Unassign a device from this data storage.
        /// </summary>
        /// <param name="device">The device to remove from the data storage.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnassignDevice(IVxDevice& device) const = 0;

    public:
        /// <summary>
        /// The unique identifier of the data storage.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the data storage.
        /// </summary>
        char name[64];
        /// <summary>
        /// The data storage type.
        /// </summary>
        VxDataStorageType::Value type;

    public:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->type = VxDataStorageType::kUnknown;
        }
    };
}

#endif // IVxDataStorage_h__