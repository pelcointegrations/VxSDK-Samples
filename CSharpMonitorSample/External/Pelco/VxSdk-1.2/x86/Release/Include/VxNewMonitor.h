#ifndef VxNewMonitor_h__
#define VxNewMonitor_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new monitor to be created.
    /// </summary>
    struct VxNewMonitor {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewMonitor"/> struct.
        /// </summary>
        VxNewMonitor() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewMonitor"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewMonitor(const VxNewMonitor& ref) {
            Utilities::StrCopySafe(this->hostDeviceId, ref.hostDeviceId);
            Utilities::StrCopySafe(this->name, ref.name);
            this->number = ref.number;
            layout = ref.layout;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewMonitor"/> class.
        /// </summary>
        ~VxNewMonitor() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->hostDeviceId);
            VxZeroArray(this->name);
            number = 0;
            layout = VxCellLayout::k1x1;
        }


    public:
        /// <summary>
        /// The unique identifier of the monitor host device.
        /// </summary>
        char hostDeviceId[64];
        /// <summary>
        /// The friendly name of the monitor.
        /// </summary>
        char name[64];
        /// <summary>
        /// The unique number of the monitor.
        /// </summary>
        int number;
        /// <summary>
        /// The cell grid layout of the monitor.
        /// </summary>
        VxCellLayout::Value layout;
    };
}

#endif // VxNewMonitor_h__