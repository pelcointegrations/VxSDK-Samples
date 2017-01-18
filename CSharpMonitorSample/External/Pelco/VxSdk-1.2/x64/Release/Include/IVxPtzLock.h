#ifndef IVxPtzLock_h__
#define IVxPtzLock_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a lock for a PTZ controller.
    /// </summary>
    struct IVxPtzLock {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the amount of time (in seconds) that the PTZ lock will be held.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetExpireTime(int& expireTime) const = 0;
        /// <summary>
        /// Gets the current state of the PTZ lock.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLockState(bool& isLocked) const = 0;
        /// <summary>
        /// Gets the name of the user that has locked the PTZ controller, if any.
        /// </summary>
        /// <param name="owner">The PTZ lock owner.</param>
        /// <param name="size">The size of <paramref name="owner"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetOwner(char* owner, int& size) const = 0;
        /// <summary>
        /// Locks the PTZ control.
        /// </summary>
        /// <param name="expireTime">The amount of time (in seconds) that the PTZ lock will be held. The
        /// lock will not expire until it is explicitly unlocked if set to 0.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Lock(int expireTime) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Unlocks the PTZ control.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Unlock() const = 0;

    public:
        /// <summary>
        /// The unique identifier of the PTZ lock.
        /// </summary>
        char id[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
        }
    };
}

#endif // IVxPtzLock_h__
