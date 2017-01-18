#ifndef IVxResourceLock_h__
#define IVxResourceLock_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a lock upon a resource. A resource that has been locked shall permit only the owner of the lock
    /// access to modify the resource.
    /// </summary>
    struct IVxResourceLock {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this lock from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the ResourceLock.</returns>
        virtual VxResult::Value DeleteResourceLock() const = 0;

    public:
        /// <summary>
        /// The unique identifier of the lock.
        /// </summary>
        char id[64];
        /// <summary>
        /// The name of the user that owns the lock.  Only this user is authorized to modify the resource
        /// that owns this lock.
        /// </summary>
        char owner[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->owner);
        }
    };
}
#endif // IVxResourceLock_h__
