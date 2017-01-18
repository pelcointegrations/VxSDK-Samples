#ifndef VxNewMarker_h__
#define VxNewMarker_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new marker to be created.
    /// </summary>
    struct VxNewMarker {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewMarker"/> struct.
        /// </summary>
        VxNewMarker() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewMarker"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewMarker(const VxNewMarker& ref) {
            Utilities::StrCopySafe(this->associatedDataSourceId, ref.associatedDataSourceId);
            Utilities::StrCopySafe(this->name, ref.name);
            this->direction = ref.direction;
            this->x = ref.x;
            this->y = ref.y;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewMarker"/> class.
        /// </summary>
        ~VxNewMarker() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->associatedDataSourceId);
            VxZeroArray(this->name);
            this->direction = 0;
            this->x = 0;
            this->y = 0;
        }

    public:
        /// <summary>
        /// The unique identifier of the data source to associate with the marker.
        /// </summary>
        char associatedDataSourceId[64];
        /// <summary>
        /// The friendly name of the marker.
        /// </summary>
        char name[64];
        /// <summary>
        /// The angular coordinate indicating the direction that the marker is facing on a polar grid.
        /// (e.g.: 0[right], 90[up], 180[left], 270[down]).
        /// </summary>
        float direction;
        /// <summary>
        /// The X cartesian coordinate.
        /// </summary>
        float x;
        /// <summary>
        /// The Y cartesian coordinate.
        /// </summary>
        float y;
    };
}

#endif // VxNewMarker_h__