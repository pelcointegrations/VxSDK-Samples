#ifndef VxKvObject_h__
#define VxKvObject_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a key/value pair object.
    /// </summary>
    struct VxKvObject {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxKvObject"/> struct.
        /// </summary>
        VxKvObject() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxKvObject"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxKvObject(const VxKvObject& ref) {
            Utilities::StrCopySafe(this->key, ref.key);
            Utilities::StrCopySafe(this->value, ref.value);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxKvObject"/> class.
        /// </summary>
        ~VxKvObject() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->key);
            VxZeroArray(this->value);
        }

    public:
        /// <summary>
        /// The object key.
        /// </summary>
        char key[64];
        /// <summary>
        /// The object value.
        /// </summary>
        char value[2048];
    };
}

#endif // VxKvObject_h__