// Declares the new privilege class.
#ifndef NewPrivilege_h__
#define NewPrivilege_h__

#include "Privilege.h"

namespace CPPCli {

    /// <summary>
    /// The NewTag class represents a new privilege.
    /// </summary>
    public ref class NewPrivilege {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewPrivilege() {
            _newPrivilege = new VxSdk::VxNewPrivilege();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewPrivilege">The new privilege.</param>
        NewPrivilege(VxSdk::VxNewPrivilege* vxNewPrivilege) {
            _newPrivilege = vxNewPrivilege;
        }

        /// <summary>
        /// Gets or sets the identifier of the permission being granted by this privilege.
        /// </summary>
        /// <value>The permission identifier.</value>
        property Privilege::PermissionIds PermissionId {
        public:
            Privilege::PermissionIds get() { return (Privilege::PermissionIds)_newPrivilege->permissionId; }
            void set(Privilege::PermissionIds value) { _newPrivilege->permissionId = (VxSdk::VxPermissionId::Value)value; }
        }

        /// <summary>
        /// Gets or sets the relative priority for the privilege, from 1 to 250. Smaller numbers have higher
        /// priority than larger numbers (e.g. 1 is the highest priority).
        /// </summary>
        /// <value>The priority.</value>
        property int Priority {
        public:
            int get() { return _newPrivilege->priority; }
            void set(int value) { _newPrivilege->priority = value; }
        }

    internal:
        VxSdk::VxNewPrivilege* _newPrivilege;
    };
}
#endif // NewPrivilege_h__
