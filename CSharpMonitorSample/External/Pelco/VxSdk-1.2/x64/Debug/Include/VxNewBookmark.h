#ifndef VxNewBookmark_h__
#define VxNewBookmark_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new bookmark to be created.
    /// </summary>
    struct VxNewBookmark {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewBookmark"/> struct.
        /// </summary>
        VxNewBookmark() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewBookmark"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewBookmark(const VxNewBookmark& ref) {
            Utilities::StrCopySafe(this->dataSourceId, ref.dataSourceId);
            Utilities::StrCopySafe(this->description, ref.description);
            Utilities::StrCopySafe(this->time, ref.time);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewBookmark"/> class.
        /// </summary>
        ~VxNewBookmark() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->description);
            VxZeroArray(this->time);
        }

    public:
        /// <summary>
        /// The unique identifier of the data source to associate with the bookmark.
        /// </summary>
        char dataSourceId[64];
        /// <summary>
        /// The friendly description of the bookmark.
        /// </summary>
        char description[64];
        /// <summary>
        /// The time at which the point of interest occurred.
        /// </summary>
        char time[64];
    };
}

#endif // VxNewBookmark_h__