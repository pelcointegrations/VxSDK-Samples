// Declares the ResourceLock class.
#ifndef ResourceLock_h__
#define ResourceLock_h__

#include "VxSdk.h"
#include "DataSource.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The ResourceLock class represents a lock upon a resource. A resource that has been locked shall
    /// permit only the owner of the lock access to modify the resource.
    /// </summary>
    public ref class ResourceLock {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxResourceLock">The vx resource lock.</param>
        ResourceLock(VxSdk::IVxResourceLock* vxResourceLock) {
            _resourceLock = vxResourceLock;
        }

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~ResourceLock() {
            this->!ResourceLock();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !ResourceLock() {
            _resourceLock->Delete();
            _resourceLock = nullptr;
        }

        /// <summary>
        /// Gets the unique resource lock identifier.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_resourceLock->id); }
        }

        /// <summary>
        /// Gets the owner.
        /// </summary>
        /// <value>The owner.</value>
        property System::String^ Owner {
        public:
            System::String^ get() { return gcnew System::String(_resourceLock->owner); }
        }

    internal:
        VxSdk::IVxResourceLock* _resourceLock;
    };
}
#endif // ResourceLock_h__
