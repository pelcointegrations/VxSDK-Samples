#ifndef VxCollectionFilter_h__
#define VxCollectionFilter_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a filter to be used when creating a VxCollection.
    /// </summary>
    struct VxCollectionFilter {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxCollectionFilter"/> struct.
        /// </summary>
        VxCollectionFilter() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxCollectionFilter"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxCollectionFilter(const VxCollectionFilter& ref) {
            Utilities::StrCopySafe(this->value, ref.value);
            this->key = ref.key;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxCollectionFilter"/> class.
        /// </summary>
        ~VxCollectionFilter() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->value);
            this->key = VxCollectionFilterItem::kNone;
        }

    public:
        /// <summary>
        /// The filter value.
        /// </summary>
        char value[64];
        /// <summary>
        /// The filter key.
        /// </summary>
        VxCollectionFilterItem::Value key;
    };
}

#endif // VxCollectionFilter_h__
