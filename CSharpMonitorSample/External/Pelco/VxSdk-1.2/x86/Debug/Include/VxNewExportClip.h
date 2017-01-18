#ifndef VxNewExportClip_h__
#define VxNewExportClip_h__

#include "IVxDataSource.h"
#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a clip that will be exported as part of a new export.
    /// </summary>
    struct VxNewExportClip {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewExportClip"/> struct.
        /// </summary>
        VxNewExportClip() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewExportClip"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewExportClip(const VxNewExportClip& ref) {
            Utilities::StrCopySafe(this->dataSourceId, ref.dataSourceId);
            Utilities::StrCopySafe(this->endTime, ref.endTime);
            Utilities::StrCopySafe(this->startTime, ref.startTime);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewExportClip"/> class.
        /// </summary>
        ~VxNewExportClip() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
        }

    public:
        /// <summary>
        /// The unique identifier of the data source.
        /// </summary>
        char dataSourceId[64];
        /// <summary>
        /// The time at which the clip ends.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The time at which the clip begins.
        /// </summary>
        char startTime[64];
    };
}

#endif // VxNewExportClip_h__
