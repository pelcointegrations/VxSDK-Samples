#ifndef VxNewQuickReport_h__
#define VxNewQuickReport_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new quick report.
    /// </summary>
    struct VxNewQuickReport {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewQuickReport"/> struct.
        /// </summary>
        VxNewQuickReport() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewQuickReport"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewQuickReport(const VxNewQuickReport& ref) {
            Utilities::StrCopySafe(this->endTime, ref.endTime);
            Utilities::StrCopySafe(this->startTime, ref.startTime);
            this->contentsSize = ref.contentsSize;
            this->contents = ref.contents;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewQuickReport"/> class.
        /// </summary>
        ~VxNewQuickReport() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
            this->contentsSize = 0;
            this->contents = nullptr;
        }

    public:
        /// <summary>
        /// The time (RFC 3339 format) at which to end the contents of the report.
        /// Defaults to the earliest content available.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The time (RFC 3339 format) at which to start the contents of the report.
        /// Defaults to the oldest content available.
        /// </summary>
        char startTime[64];
        /// <summary>
        /// The size of <see cref="contents"/>.
        /// </summary>
        int contentsSize;
        /// <summary>
        /// The report content types to include in the report.
        /// Reports will include all types if not set.
        /// </summary>
        VxReportContent::Value* contents;
    };
}

#endif // VxNewQuickReport_h__
