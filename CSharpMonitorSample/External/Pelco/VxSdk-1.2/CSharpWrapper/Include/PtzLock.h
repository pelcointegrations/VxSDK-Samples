// Declares the ptz lock class.
#ifndef PtzLock_h__
#define PtzLock_h__

#include "VxSdk.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The PtzLock class represents a lock for a ptz controller.
    /// </summary>
    public ref class PtzLock {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxPtzLock">The ptz lock.</param>
        PtzLock(VxSdk::IVxPtzLock* vxPtzLock);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~PtzLock() {
            this->!PtzLock();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !PtzLock();

        /// <summary>
        /// Lock the ptz control.
        /// </summary>
        /// <param name="expireTime">The amount of time (in seconds) that the ptz lock will be
        /// held. The lock will not expire until it is explicitly unlocked if set to 0.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the request.</returns>
        Results::Value Lock(int expireTime);

        /// <summary>
        /// Update this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Unlock the ptz control.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of the request.</returns>
        Results::Value Unlock();

        /// <summary>
        /// Gets the amount of time (in seconds) that the ptz lock will be held.
        /// </summary>
        /// <value>The lock expire time in seconds.</value>
        property int ExpireTime {
        public:
            int get() { return _GetExpireTime(); }
        }

        /// <summary>
        /// Gets the unique identifier of the ptz lock.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_ptzLock->id); }
        }

        /// <summary>
        /// Gets a value indicating whether the lock is active.
        /// </summary>
        /// <value><c>true</c> if locked, <c>false</c> if not.</value>
        property bool IsLocked {
        public:
            bool get() { return _GetLockState(); }
        }

        /// <summary>
        /// Gets the name of the user that has locked the ptz controller, if any.
        /// </summary>
        /// <value>The owner if it is set, else <c>nullptr</c>.</value>
        property System::String^ Owner {
        public:
            System::String^ get() { return _GetOwner(); }
        }

    internal:
        VxSdk::IVxPtzLock* _ptzLock;
        int _GetExpireTime();
        bool _GetLockState();
        System::String^ _GetOwner();
    };
}
#endif // PtzLock_h__
