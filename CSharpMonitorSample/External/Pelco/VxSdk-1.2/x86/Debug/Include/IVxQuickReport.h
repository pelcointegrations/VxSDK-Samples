#ifndef IVxQuickReport_h__
#define IVxQuickReport_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a quick system health report.
    /// </summary>
    struct IVxQuickReport {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the URI to the download location of the quick report.  The endpoint will only be available if the VideoXpert
        /// system has completed generating the report.
        /// </summary>
        /// <param name="endpoint">The quick report endpoint, if available.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetQuickReportEndpoint(char* endpoint, int& size) = 0;
        /// <summary>
        /// Gets the current status of creating the report.
        /// </summary>
        /// <param name="status">The current status of creating the report.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetStatus(VxReportCreationStatus::Value& status) = 0;
    };
}
#endif // IVxQuickReport_h__
