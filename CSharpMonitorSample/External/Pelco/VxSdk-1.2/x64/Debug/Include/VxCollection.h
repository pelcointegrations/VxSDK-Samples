#ifndef VxCollection_h__
#define VxCollection_h__

#include "VxCollectionFilter.h"
#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a collection of resources.
    /// </summary>
    template<typename T>
    struct VxCollection {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxCollection{T}"/> struct.
        /// </summary>
        VxCollection() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxCollection{T}"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxCollection(const VxCollection& ref) {
            this->collectionSize = ref.collectionSize;
            this->filterSize = ref.filterSize;
            this->startIndex = ref.startIndex;
            this->totalItems = ref.totalItems;
            this->collection = ref.collection;
            this->filters = ref.filters;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxCollection{T}"/> class.
        /// </summary>
        ~VxCollection() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->collectionSize = 0;
            this->filterSize = 0;
            this->startIndex = 0;
            this->totalItems = 0;
            this->collection = T();
            this->filters = nullptr;
        }

    public:
        /// <summary>
        /// The size of <see cref="collection"/>.
        /// </summary>
        int collectionSize;
        /// <summary>
        /// The size of <see cref="filters"/>.
        /// </summary>
        int filterSize;
        /// <summary>
        /// The start index.
        /// </summary>
        int startIndex;
        /// <summary>
        /// The total amount of items.
        /// </summary>
        int totalItems;
        /// <summary>
        /// The collection of resources.
        /// </summary>
        T collection;
        /// <summary>
        /// The filters to be applied to the collection request.
        /// </summary>
        VxCollectionFilter* filters;
    };
}

#endif // VxCollection_h__
