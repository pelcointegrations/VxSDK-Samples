#ifndef VxNewDrawing_h__
#define VxNewDrawing_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new drawing to be created.
    /// </summary>
    struct VxNewDrawing {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDrawing"/> struct.
        /// </summary>
        VxNewDrawing() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDrawing"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewDrawing(const VxNewDrawing& ref) {
            Utilities::StrCopySafe(this->name, ref.name);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewDrawing"/> class.
        /// </summary>
        ~VxNewDrawing() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->name);
        }

    public:
        /// <summary>
        /// The friendly name of the drawing.
        /// </summary>
        char name[64];
    };
}

#endif // VxNewDrawing_h__