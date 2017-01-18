#ifndef IVxExport_h__
#define IVxExport_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxExportClip.h"

namespace VxSdk {
    /// <summary>
    /// Represents an exported data set that is archived within the system.
    /// </summary>
    struct IVxExport {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this export from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the export.</returns>
        virtual VxResult::Value DeleteExport() const = 0;
        /// <summary>
        /// Gets the <see cref="IVxUser"/> that owns this export, if any.
        /// </summary>
        /// <param name="user">The <see cref="IVxUser"/> that owns this export.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetOwner(IVxUser*& user) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;

    public:
        /// <summary>
        /// Indicates whether the export data is signed and encrypted.
        /// </summary>
        bool isProtected;
        /// <summary>
        /// The date and time at which the triggered export completed the export operation.
        /// </summary>
        char completedTime[64];
        /// <summary>
        /// The URI to the exported data.  It will only be present if the exported data is completed and available for download.
        /// </summary>
        char dataUri[512];
        /// <summary>
        /// The unique identifier of the export.
        /// </summary>
        char id[64];
        /// <summary>
        /// The date and time at which the export was requested.
        /// </summary>
        char initiatedTime[64];
        /// <summary>
        /// The friendly name of the export.
        /// </summary>
        char name[64];
        /// <summary>
        /// The name of the user that has created this export, if any.
        /// </summary>
        char owner[64];
        /// <summary>
        /// The percent complete value from 0 to 100. This specifies how close the export is to completion. 0 indicates that the
        /// export has not been triggered; 100 indicates that the export is complete.
        /// </summary>
        float percentComplete;
        /// <summary>
        /// The size of <see cref="exportClips"/>.
        /// </summary>
        int exportClipSize;
        /// <summary>
        /// The file size of the exported data in kilobytes (kB).
        /// </summary>
        int fileSizeKb;
        /// <summary>
        /// The estimated time remaining, in seconds, until the export is 100 percent complete.
        /// </summary>
        int secondsRemaining;
        /// <summary>
        /// The clips associated with this export.
        /// </summary>
        IVxExportClip** exportClips;
        /// <summary>
        /// The format of the export data.
        /// </summary>
        VxExportFormat::Value format;
        /// <summary>
        /// The current status of the export.
        /// </summary>
        VxExportStatus::Value status;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isProtected = false;
            VxZeroArray(this->completedTime);
            VxZeroArray(this->dataUri);
            VxZeroArray(this->id);
            VxZeroArray(this->initiatedTime);
            VxZeroArray(this->name);
            VxZeroArray(this->owner);
            this->exportClipSize = 0;
            this->percentComplete = 0;
            this->fileSizeKb = 0;
            this->secondsRemaining = 0;
            this->exportClips = nullptr;
            this->format = VxExportFormat::kUnknown;
            this->status = VxExportStatus::kUnknown;
        }
    };
}
#endif // IVxExport_h__
