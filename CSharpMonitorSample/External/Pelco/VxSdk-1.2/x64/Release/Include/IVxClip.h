#ifndef IVxClip_h__
#define IVxClip_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxSnapshotFilter.h"
#include "IVxConfiguration.h"

namespace VxSdk {
    /// <summary>
    /// Represents a contiguous duration of stored media originating from a single data source.
    /// </summary>
    struct IVxClip {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the endpoint URI for snapshots.
        /// </summary>
        /// <param name="filter">The filter(s) to use to generate the snapshot endpoint.</param>
        /// <param name="filterSize">The size of <paramref name="filter"/>.</param>
        /// <param name="endpoint">The snapshots endpoint.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSnapshotEndpoint(VxSnapshotFilter* filter, int filterSize, char* endpoint, int& size) const = 0;

    public:
        /// <summary>
        /// The unique identifier of the clips data source.
        /// </summary>
        char dataSourceId[64];
        /// <summary>
        /// The friendly name of the clips data source.
        /// </summary>
        char dataSourceName[64];
        /// <summary>
        /// The end time of the clip.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The start time of the clip.
        /// </summary>
        char startTime[64];
        /// <summary>
        /// The type of media contained in the clip.
        /// </summary>
        char type[64];
        /// <summary>
        /// The framerate of the clip.
        /// </summary>
        VxRecordingFramerate::Value framerate;
        /// <summary>
        /// The recording retention priority of the clip.
        /// </summary>
        VxRetentionPriority::Value priority;
        /// <summary>
        /// The event type that triggered the recording of the clip.
        /// </summary>
        VxRecordingType::Value recordingType;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->dataSourceName);
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
            VxZeroArray(this->type);
            this->framerate = VxRecordingFramerate::kUnknown;
            this->priority = VxRetentionPriority::kUnknown;
            this->recordingType = VxRecordingType::kUnknown;
        }
    };
}

#endif // IVxClip_h__
