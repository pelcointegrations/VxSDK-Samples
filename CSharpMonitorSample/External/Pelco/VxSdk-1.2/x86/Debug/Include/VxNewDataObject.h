#ifndef VxNewDataObject_h__
#define VxNewDataObject_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new data object to be created.
    /// </summary>
    struct VxNewDataObject {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDataObject"/> struct.
        /// </summary>
        VxNewDataObject() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDataObject"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewDataObject(const VxNewDataObject& ref) {
            this->isPrivate = ref.isPrivate;
            Utilities::StrCopySafe(this->clientType, ref.clientType);
            this->data = ref.data;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewDataObject"/> class.
        /// </summary>
        ~VxNewDataObject() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isPrivate = false;
            VxZeroArray(this->clientType);
            this->data = nullptr;
        }

    public:
        /// <summary>
        /// Indicates whether this resource is owned by a user.  If true, the data object will be owned by the user submitting the request.
        /// </summary>
        bool isPrivate;
        /// <summary>
        /// The client type identifier. Recommend using the Java package naming convention.
        /// </summary>
        char clientType[64];
        /// <summary>
        /// The data to add to the data object.
        /// </summary>
        char* data;
    };
}

#endif // VxNewDataObject_h__