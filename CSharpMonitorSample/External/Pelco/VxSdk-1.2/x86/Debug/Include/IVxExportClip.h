#ifndef IVxExportClip_h__
#define IVxExportClip_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents an individual range of media data belonging to an export. This data shall be exported when the export is triggered.
    /// </summary>
    struct IVxExportClip {
    public:
        /// <summary>
        /// The unique identifier of the export clips data source.
        /// </summary>
        char dataSourceId[64];
        /// <summary>
        /// The time at which the export media ends.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The unique identifier of the export clip.
        /// </summary>
        char id[64];
        /// <summary>
        /// The time at which the export media begins.
        /// </summary>
        char startTime[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->endTime);
            VxZeroArray(this->id);
            VxZeroArray(this->startTime);
        }
    };
}

#endif // IVxExportClip_h__
