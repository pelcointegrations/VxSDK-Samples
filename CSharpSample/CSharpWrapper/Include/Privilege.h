// Declares the privilege class.
#ifndef Privilege_h__
#define Privilege_h__

#include "VxSdk.h"
#include "Utils.h"
#include "Device.h"

namespace CPPCli {
    ref class User;

    /// <summary>
    /// The Privilege class represents a specific permission that is given to a role.
    /// </summary>
    public ref class Privilege {
    public:
        enum class PermissionIds  {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>View video sources.</summary>
            ViewVideoSources,

            /// <summary>Use PTZ mode.</summary>
            UsePtzMode,

            /// <summary>Lock PTZ mode.</summary>
            LockPtzMode,

            /// <summary>Create system bookmarks.</summary>
            CreateSystemBookmarks,

            /// <summary>Delete system bookmarks.</summary>
            DeleteSystemBookmarks,

            /// <summary>Launch saved views remotely.</summary>
            LaunchSavedViewsRemotely,

            /// <summary>View recorded video.</summary>
            ViewRecordedVideo,

            /// <summary>Export media clips.</summary>
            ExportMediaClips,

            /// <summary>Delete exports.</summary>
            DeleteExports,

            /// <summary>Use map.</summary>
            UseMap,

            /// <summary>View maps.</summary>
            ViewMaps,

            /// <summary>Place cameras on map.</summary>
            PlaceCamerasOnMap,

            /// <summary>Manage map files.</summary>
            ManageMapFiles,

            /// <summary>Access user views.</summary>
            AccessUserViews,

            /// <summary>Manage system views.</summary>
            ManageSystemViews,

            /// <summary>Audit user activity.</summary>
            AuditUserActivity,

            /// <summary>View event history.</summary>
            ViewEventHistory,

            /// <summary>Handle events.</summary>
            HandleEvents,

            /// <summary>Configure events.</summary>
            ConfigureEvents,

            /// <summary>Manage user accounts.</summary>
            ManageUserAccounts,

            /// <summary>Manage aggregator account.</summary>
            ManageAggregatorAccount,

            /// <summary>Assign roles to users.</summary>
            AssignRolesToUsers,

            /// <summary>Manage roles.</summary>
            ManageRoles,

            /// <summary>Manage system tags.</summary>
            ManageSystemTags,

            /// <summary>Setup edge devices.</summary>
            SetupEdgeDevices,

            /// <summary>Configure monitor wall decoders.</summary>
            ConfigureMonitorWallDecoders,

            /// <summary>Configure recording.</summary>
            ConfigureRecording
        };

        /// <summary>
        /// Values that represent a type of resource.
        /// </summary>
        enum class ResourceTypes {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,
            /// <summary>A data source.</summary>
            DataSource,
            /// <summary>A device.</summary>
            Device,
            /// <summary>A user.</summary>
            User
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxPrivilege">The vx privilege.</param>
        Privilege(VxSdk::IVxPrivilege* vxPrivilege);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Privilege() {
            this->!Privilege();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Privilege();

        /// <summary>
        /// Associate devices with this privilege.
        /// </summary>
        /// <param name="devices">A <c>List</c> containing the devices to be added.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the devices.</returns>
        CPPCli::Results::Value Link(System::Collections::Generic::List<Device^>^ devices);

        /// <summary>
        /// Associate data sources with this privilege.
        /// </summary>
        /// <param name="dataSources">A <c>List</c> containing the data sources to be added.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the data sources.</returns>
        CPPCli::Results::Value Link(System::Collections::Generic::List<DataSource^>^ dataSources);

        /// <summary>
        /// Associate users with this privilege.
        /// </summary>
        /// <param name="users">A <c>List</c> containing the data sources to be added.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the data sources.</returns>
        CPPCli::Results::Value Link(System::Collections::Generic::List<User^>^ users);

        /// <summary>
        /// Remove device associations from this privilege.
        /// </summary>
        /// <param name="devices">A <c>List</c> containing the devices to be removed.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the devices.</returns>
        CPPCli::Results::Value Unlink(System::Collections::Generic::List<Device^>^ devices);

        /// <summary>
        /// Remove data source associations from this privilege.
        /// </summary>
        /// <param name="dataSources">A <c>List</c> containing the data sources to be removed.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the data sources.</returns>
        CPPCli::Results::Value Unlink(System::Collections::Generic::List<DataSource^>^ dataSources);

        /// <summary>
        /// Remove user associations from this privilege.
        /// </summary>
        /// <param name="users">A <c>List</c> containing the users to be removed.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the users.</returns>
        CPPCli::Results::Value Unlink(System::Collections::Generic::List<User^>^ users);

        /// <summary>
        /// Gets the devices associated with this privilege.
        /// </summary>
        /// <value>A list of devices.</value>
        property System::Collections::Generic::List<Device^>^ LinkedDevices {
        public:
            System::Collections::Generic::List<Device^>^ get() { return _GetLinkedDevices(); }
        }

        /// <summary>
        /// Gets the data sources associated with this privilege.
        /// </summary>
        /// <value>A list of data sources.</value>
        property System::Collections::Generic::List<DataSource^>^ LinkedDataSources {
        public:
            System::Collections::Generic::List<DataSource^>^ get() { return _GetLinkedDataSources(); }
        }

        /// <summary>
        /// Gets the users associated with this privilege.
        /// </summary>
        /// <value>A list of users.</value>
        property System::Collections::Generic::List<User^>^ LinkedUsers {
        public:
            System::Collections::Generic::List<User^>^ get() { return _GetLinkedUsers(); }
        }

        /// <summary>
        /// Gets the devices not associated with this privilege.
        /// </summary>
        /// <value>A list of devices.</value>
        property System::Collections::Generic::List<Device^>^ UnLinkedDevices {
        public:
            System::Collections::Generic::List<Device^>^ get() { return _GetUnLinkedDevices(); }
        }

        /// <summary>
        /// Gets the data sources not associated with this privilege.
        /// </summary>
        /// <value>A list of data sources.</value>
        property System::Collections::Generic::List<DataSource^>^ UnLinkedDataSources {
        public:
            System::Collections::Generic::List<DataSource^>^ get() { return _GetUnLinkedDataSources(); }
        }

        /// <summary>
        /// Gets the users not associated with this privilege.
        /// </summary>
        /// <value>A list of users.</value>
        property System::Collections::Generic::List<User^>^ UnLinkedUsers {
        public:
            System::Collections::Generic::List<User^>^ get() { return _GetUnLinkedUsers(); }
        }

        /// <summary>
        /// Gets the unique identifier for this privilege.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_privilege->id); }
        }

        /// <summary>
        /// Gets the identifier of the permission being granted by this privilege.
        /// </summary>
        /// <value>The permission identifier.</value>
        property PermissionIds PermissionId {
        public:
            PermissionIds get() { return (PermissionIds)_privilege->permissionId; }
        }

        /// <summary>
        /// Gets or sets the relative priority for the privilege, from 1 to 250. Smaller numbers have higher
        /// priority than larger numbers (e.g. 1 is the highest priority).
        /// </summary>
        /// <value>The priority.</value>
        property int Priority {
        public:
            int get() { return _GetPriority(); }
            void set(int value) { _privilege->SetPriority(value); }
        }

        /// <summary>
        /// Gets the resource type, if any, that can be linked to this privilege.
        /// </summary>
        /// <value>The resource type.</value>
        property ResourceTypes ResourceType {
        public:
            ResourceTypes get() { return (ResourceTypes)_privilege->resourceType; }
        }

        /// <summary>
        /// Gets whether the privilege is restricted to the associated resources.
        /// </summary>
        /// <value><c>true</c> if restricted, <c>false</c> if not.</value>
        property bool IsRestricted {
        public:
            bool get() { return _GetRestricted(); }
            void set(bool value) { _privilege->SetRestricted(value); }
        }

    internal:
        VxSdk::IVxPrivilege* _privilege;
        int _GetPriority();
        bool _GetRestricted();
        System::Collections::Generic::List<Device^>^ _GetLinkedDevices();
        System::Collections::Generic::List<DataSource^>^ _GetLinkedDataSources();
        System::Collections::Generic::List<User^>^ _GetLinkedUsers();
        System::Collections::Generic::List<Device^>^ _GetUnLinkedDevices();
        System::Collections::Generic::List<DataSource^>^ _GetUnLinkedDataSources();
        System::Collections::Generic::List<User^>^ _GetUnLinkedUsers();
    };
}
#endif // Privilege_h__
