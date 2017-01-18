#ifndef IVxDevice_h__
#define IVxDevice_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDataSource.h"
#include "IVxMonitor.h"
#include "VxCollection.h"

namespace VxSdk {
    struct IVxDeviceAssignment;

    /// <summary>
    /// Represents a particular physical device in the system.
    /// </summary>
    struct IVxDevice {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Remove the device and its hosted data sources and data storages.  If the device is assigned to a data
        /// storage, it shall be unassigned.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value DeleteDevice() const = 0;
        /// <summary>
        /// Gets the data sources hosted by this device.
        /// <para>Available filters: kAllTags, kCapturing, kId, kIp, kModifiedSince, kName, kNumber, kRecording, kState, kType, kUnassigned.</para>
        /// </summary>
        /// <param name="dataSourceCollection">A <see cref="VxCollection"/> of the associated data sources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSources(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the assignments to a data storage for this device.
        /// <para>Available filters: kDataSourceId, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceAssignmentCollection">A <see cref="VxCollection"/> of the device assignments.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDeviceAssignments(VxCollection<IVxDeviceAssignment**>& deviceAssignmentCollection) const = 0;
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
        /// Sets the password property.
        /// </summary>
        /// <param name="password">The new password value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPassword(char password[64]) = 0;
        /// <summary>
        /// Sets the username property.
        /// </summary>
        /// <param name="username">The new username value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetUsername(char username[64]) = 0;
        /// <summary>
        /// Gets the monitors residing on the device.
        /// </summary>
        /// <param name="monitorCollection">A <see cref="VxCollection"/> of the monitors residing on the device.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMonitors(VxCollection<IVxMonitor**>& monitorCollection) const = 0;

    public:
        /// <summary>
        /// Indicates whether the device is commissioned.
        /// </summary>
        bool isCommissioned;
        /// <summary>
        /// Indicates whether a license is required for commissioning the device.
        /// </summary>
        bool isLicenseRequired;
        /// <summary>
        /// Indicates whether the device is running on Pelco hardware.
        /// </summary>
        bool isPelcoHardware;
        /// <summary>
        /// The unique identifier of the device.
        /// </summary>
        char id[64];
        /// <summary>
        /// The IP of the device.
        /// </summary>
        char ip[64];
        /// <summary>
        /// The device model name.
        /// </summary>
        char model[64];
        /// <summary>
        /// The friendly name of the device.
        /// </summary>
        char name[64];
        /// <summary>
        /// The serial number of the device.
        /// </summary>
        char serial[64];
        /// <summary>
        /// The account username used to communicate with the device, if any.
        /// </summary>
        char username[64];
        /// <summary>
        /// The device vendor, if any.
        /// </summary>
        char vendor[64];
        /// <summary>
        /// The current version of software running on the device.
        /// </summary>
        char version[64];
        /// <summary>
        /// The virtual IP of the device, if any.
        /// </summary>
        char virtualIp[64];
        /// <summary>
        /// The current operational state of the device.
        /// </summary>
        VxDeviceState::Value state;
        /// <summary>
        /// The type of device.
        /// </summary>
        VxDeviceType::Value type;

    public:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isCommissioned = false;
            this->isLicenseRequired = false;
            this->isPelcoHardware = false;
            VxZeroArray(this->id);
            VxZeroArray(this->ip);
            VxZeroArray(this->model);
            VxZeroArray(this->name);
            VxZeroArray(this->serial);
            VxZeroArray(this->username);
            VxZeroArray(this->vendor);
            VxZeroArray(this->version);
            VxZeroArray(this->virtualIp);
            this->state = VxDeviceState::kUnknown;
            this->type = VxDeviceType::kUnknown;
        }
    };
}

#endif // IVxDevice_h__