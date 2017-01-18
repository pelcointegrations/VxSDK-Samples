#ifndef VxNewDeviceAssignment_h__
#define VxNewDeviceAssignment_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new device assignment to be created.
    /// </summary>
    struct VxNewDeviceAssignment {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDeviceAssignment"/> struct.
        /// </summary>
        VxNewDeviceAssignment() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDeviceAssignment"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewDeviceAssignment(const VxNewDeviceAssignment& ref) {
            Utilities::StrCopySafe(this->deviceId, ref.deviceId);
            Utilities::StrCopySafe(this->driverType, ref.driverType);
            this->dataSourceIds = ref.dataSourceIds;
            this->dataSourceIdSize = ref.dataSourceIdSize;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewDeviceAssignment"/> class.
        /// </summary>
        ~VxNewDeviceAssignment() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->deviceId);
            VxZeroArray(this->driverType);
            this->dataSourceIds = nullptr;
            this->dataSourceIdSize = 0;
        }

    public:
        /// <summary>
        /// The unique identifier of the device to assign.
        /// </summary>
        char deviceId[64];
        /// <summary>
        /// The type identifier of the driver to use for this device. If no type is provided, a driver will be selected automatically.
        /// </summary>
        char driverType[64];
        /// <summary>
        /// The data sources to assign.
        /// </summary>
        char** dataSourceIds;
        /// <summary>
        /// The size of <see cref="dataSourceIds"/>.
        /// </summary>
        int dataSourceIdSize;
    };
}

#endif // VxNewDeviceAssignment_h__