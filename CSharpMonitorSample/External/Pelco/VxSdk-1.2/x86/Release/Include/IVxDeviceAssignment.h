#ifndef IVxDeviceAssignment_h__
#define IVxDeviceAssignment_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDriver.h"

namespace VxSdk {
    struct IVxDataStorage;

    /// <summary>
    /// Represents a device assignment on a data storage.
    /// </summary>
    struct IVxDeviceAssignment {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the data sources assigned by this device assignment.
        /// <para>Available filters: kAllTags, kCapturing, kId, kIp, kModifiedSince, kName, kNumber, kRecording, kState, kType, kUnassigned.</para>
        /// </summary>
        /// <param name="dataSourceCollection">A <see cref="VxCollection"/> of the associated data sources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSources(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDataStorage"/> that this device assignment is for.
        /// </summary>
        /// <param name="dataStorage">The <see cref="IVxDataStorage"/> for this device assignment.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataStorage(IVxDataStorage*& dataStorage) const = 0;
        /// <summary>
        /// Gets the assigned <see cref="IVxDevice"/>.
        /// </summary>
        /// <param name="device">The assigned <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDevice(IVxDevice*& device) const = 0;
        /// <summary>
        /// Gets the assigned <see cref="IVxDriver"/>.
        /// </summary>
        /// <param name="driver">The assigned <see cref="IVxDriver"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDriver(IVxDriver*& driver) const = 0;
        /// <summary>
        /// Sets the data sources assigned by this device assignment.
        /// </summary>
        /// <param name="dataSourceIds">The data sources to assign.</param>
        /// <param name="dataSourceIdSize">The size of dataSourceIds.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetDataSources(char** dataSourceIds, int dataSourceIdSize) = 0;
        /// <summary>
        /// Sets the driver type property.
        /// </summary>
        /// <param name="driverType">The new driver type value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDriverType(char driverType[64]) = 0;

    public:
        /// <summary>
        /// The driver type.
        /// </summary>
        char driverType[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->driverType);
        }
    };
}

#endif // IVxDeviceAssignment_h__
