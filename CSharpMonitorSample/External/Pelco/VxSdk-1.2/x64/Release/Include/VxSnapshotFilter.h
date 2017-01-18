#ifndef VxSnapshotFilter_h__
#define VxSnapshotFilter_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a snapshot filter to be used when taking a snapshot.
    /// </summary>
    struct VxSnapshotFilter {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxSnapshotFilter"/> struct.
        /// </summary>
        VxSnapshotFilter() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxSnapshotFilter"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxSnapshotFilter(const VxSnapshotFilter& ref) {
            Utilities::StrCopySafe(this->value, ref.value);
            this->key = ref.key;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxSnapshotFilter"/> class.
        /// </summary>
        ~VxSnapshotFilter() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->value);
            this->key = VxSnapshotFilterItem::kNone;
        }

    public:
        /// <summary>
        /// The filter value.
        /// </summary>
        char value[64];
        /// <summary>
        /// The filter key.
        /// </summary>
        VxSnapshotFilterItem::Value key;
    };
}

#endif // VxSnapshotFilter_h__
