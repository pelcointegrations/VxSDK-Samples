// Declares the VX System class.
#ifndef VXSystem_h__
#define VXSystem_h__

#include "Device.h"
#include "DataStorage.h"
#include "NewBookmark.h"
#include "NewEvent.h"
#include "NewExport.h"
#include "NewSchedule.h"
#include "NewSituation.h"
#include "NewTag.h"
#include "NewUser.h"
#include "NewDataObject.h"

namespace CPPCli {

    /// <summary>
    /// The VXSystem class represents a VideoXpert system.  It is the entry point of the VideoXpert SDK
    /// and allows the user to manage the system and devices.
    /// </summary>
    public ref class VXSystem {
    public:

        /// <summary>
        /// Constructor that takes an IP as a parameter.
        /// </summary>
        /// <param name="ip">The IP address of the VideoXpert system.</param>
        VXSystem(System::String^ ip);

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~VXSystem() {
            this->!VXSystem();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !VXSystem();

        /// <summary>
        /// Initialize the VideoXpert SDK.
        /// </summary>
        /// <param name="key">The key to initialize the SDK with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the initialization process.</returns>
        Results::Value InitializeSdk(System::String^ key);

        /// <summary>
        /// Log in to the VideoXpert system.
        /// </summary>
        /// <param name="username">The user name to log in with.</param>
        /// <param name="password">The password to log in with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the log in process.</returns>
        Results::Value Login(System::String^ username, System::String^ password);

        /// <summary>
        /// Create a new export on the VideoXpert system.
        /// </summary>
        /// <param name="newExport">The new export to be added to the system.</param>
        /// <returns><c>nullptr</c> if it fails, else the new export.</returns>
        Export^ CreateExport(NewExport^ newExport);

        /// <summary>
        /// Delete an export from the VideoXpert system.
        /// </summary>
        /// <param name="exportItem">The export to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the export.</returns>
        Results::Value DeleteExport(Export^ exportItem);

        /// <summary>
        /// Get the devices from the VideoXpert system.
        /// </summary>
        /// <returns>A <c>List</c> containing the devices on the system.</returns>
        System::Collections::Generic::List<Device^>^ GetDevices();

        /// <summary>
        /// Get the data sources from the VideoXpert system.
        /// </summary>
        /// <returns>A <c>List</c> containing the data sources on the system.</returns>
        System::Collections::Generic::List<DataSource^>^ GetDataSources();

        /// <summary>
        /// Get the exports residing on the system.
        /// </summary>
        /// <returns>A <c>List</c> containing the exports on the system.</returns>
        System::Collections::Generic::List<Export^>^ GetExports();

        /// <summary>
        /// Get the situations residing on the system.
        /// </summary>
        /// <returns>A <c>List</c> containing the situations on the system.</returns>
        System::Collections::Generic::List<Situation^>^ GetSituations();

        /// <summary>
        /// Add a new situation to the system.
        /// </summary>
        /// <param name="newSituation">The new situation to be added to the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the situation.</returns>
        Results::Value AddSituation(NewSituation^ newSituation);

        /// <summary>
        /// Delete an existing situation from the system.
        /// </summary>
        /// <param name="situationItem">The situation to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the situation.</returns>
        Results::Value DeleteSituation(Situation^ situationItem);

        /// <summary>
        /// Search for events on the system.
        /// </summary>
        /// <param name="situationType">The situation type to search for.</param>
        /// <param name="startTime">The search start time.</param>
        /// <param name="endTime">The search end time.</param>
        /// <returns>A <c>List</c> containing matching events on the system.</returns>
        System::Collections::Generic::List<Event^>^ SearchEvents(System::String^ situationType, System::DateTime^ startTime, System::DateTime^ endTime);

        /// <summary>
        /// Insert a new event into the system.
        /// </summary>
        /// <param name="newEvent">The new event to be injected into the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of injecting the event.</returns>
        Results::Value InjectEvent(NewEvent^ newEvent);

        /// <summary>
        /// Get the bookmarks from the VideoXpert system.
        /// </summary>
        /// <returns>A <c>List</c> containing the bookmarks on the system.</returns>
        System::Collections::Generic::List<Bookmark^>^ GetBookmarks();

        /// <summary>
        /// Create a new bookmark on the VideoXpert system.
        /// </summary>
        /// <param name="newBookmark">The new bookmark to be added to the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the bookmark.</returns>
        Results::Value CreateBookmark(NewBookmark^ newBookmark);

        /// <summary>
        /// Delete a bookmark from the VideoXpert system.
        /// </summary>
        /// <param name="bookmarkItem">The bookmark to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the bookmark.</returns>
        Results::Value DeleteBookmark(Bookmark^ bookmarkItem);

        /// <summary>
        /// Get the schedules from the VideoXpert system.
        /// </summary>
        /// <returns>A <c>List</c> containing the schedules on the system.</returns>
        System::Collections::Generic::List<Schedule^>^ GetSchedules();

        /// <summary>
        /// Add a new schedule on the VideoXpert system.
        /// </summary>
        /// <param name="newSchedule">The new schedule to be added to the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the schedule.</returns>
        Results::Value AddSchedule(NewSchedule^ newSchedule);

        /// <summary>
        /// Delete a schedule from the VideoXpert system.
        /// </summary>
        /// <param name="scheduleItem">The schedule to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the schedule.</returns>
        Results::Value DeleteSchedule(Schedule^ scheduleItem);

        /// <summary>
        /// Get the data storages residing on the system.
        /// </summary>
        /// <returns>A <c>List</c> containing the data storages.</returns>
        System::Collections::Generic::List<DataStorage^>^ GetDataStorages();

        /// <summary>
        /// Get the tags from the VideoXpert system.
        /// </summary>
        /// <returns>A <c>List</c> containing the tags on the system.</returns>
        System::Collections::Generic::List<Tag^>^ GetTags();

        /// <summary>
        /// Create a new tag on the VideoXpert system.
        /// </summary>
        /// <param name="newTag">The new tag to be added to the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the tag.</returns>
        Results::Value CreateTag(NewTag^ newTag);

        /// <summary>
        /// Delete a tag from the VideoXpert system.
        /// </summary>
        /// <param name="tagItem">The tag to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the tag.</returns>
        Results::Value DeleteTag(Tag^ tagItem);

        /// <summary>
        /// Get the users from the VideoXpert system.
        /// </summary>
        /// <returns>A <c>List</c> containing the users on the system.</returns>
        System::Collections::Generic::List<User^>^ GetUsers();

        /// <summary>
        /// Create a new user on the VideoXpert system.
        /// </summary>
        /// <param name="newUser">The new user to be added to the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the user.</returns>
        Results::Value AddUser(NewUser^ newUser);

        /// <summary>
        /// Delete a user from the VideoXpert system.
        /// </summary>
        /// <param name="user">The user to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the user.</returns>
        Results::Value DeleteUser(User^ user);

        /// <summary>
        /// Get the roles from the VideoXpert system.
        /// </summary>
        /// <returns>A <c>List</c> containing the roles on the system.</returns>
        System::Collections::Generic::List<Role^>^ GetRoles();

        /// <summary>
        /// Create a new role on the VideoXpert system.
        /// </summary>
        /// <param name="roleName">The new role to be added to the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the role.</returns>
        Results::Value AddRole(System::String^ roleName);

        /// <summary>
        /// Delete a role from the VideoXpert system.
        /// </summary>
        /// <param name="role">The role to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the role.</returns>
        Results::Value DeleteRole(Role^ role);

        /// <summary>
        /// Get the data objects from the VideoXpert system.
        /// </summary>
        /// <returns>A <c>List</c> containing the data objects on the system.</returns>
        System::Collections::Generic::List<DataObject^>^ GetDataObjects();

        /// <summary>
        /// Create a new data object on the VideoXpert system.
        /// </summary>
        /// <param name="newDataObject">The new data object to be added to the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the data object.</returns>
        Results::Value AddDataObject(NewDataObject^ newDataObject);

        /// <summary>
        /// Delete a data object from the VideoXpert system.
        /// </summary>
        /// <param name="dataObject">The data object to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the data object.</returns>
        Results::Value DeleteDataObject(DataObject^ dataObject);

        /// <summary>
        /// Gets the user currently accessing the VideoXpert system.
        /// </summary>
        /// <value>The current user.</value>
        property User^ Currentuser {
            User^ get() { return _GetCurrentUser(); }
        }

        /// <summary>
        /// Gets the unique identifier of the VideoXpert system.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
            System::String^ get() { return gcnew System::String(_system->id); }
        }

        /// <summary>
        /// Gets the friendly name of the VideoXpert system.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
            System::String^ get() { return gcnew System::String(_system->name); }
        }

        /// <summary>
        /// The native event callback delegate.
        /// </summary>
        /// <param name="vxEvent">The event sent from system.</param>
        [System::Runtime::InteropServices::UnmanagedFunctionPointer(
            System::Runtime::InteropServices::CallingConvention::Cdecl)]
        delegate void EventCallbackDelegate(VxSdk::IVxEvent* vxEvent);

        /// <summary>
        /// The managed event delegate.
        /// </summary>
        /// <param name="vxEvent">The event sent from the system as a managed type.</param>
        delegate void EventDelegate(Event^ vxEvent);

        /// <summary>
        /// Subscribe to system events by situation type, regardless of its notification setting.
        /// </summary>
        /// <param name="eventDelegate">The event delegate to be used when an event is received.</param>
        /// <param name="situations">A <c>List</c> of situations to subscribe to.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of subscribing.</returns>
        Results::Value SubscribeToEventsByType(EventDelegate^ eventDelegate, System::Collections::Generic::List<Situation^>^ situations);

        /// <summary>
        /// SystemEvent is raised whenever a new event is created on the system.
        /// </summary>
        event EventDelegate ^ SystemEvent {
            void add(EventDelegate ^eventDelegate);
            void remove(EventDelegate ^eventDelegate);
        }

    internal:
        static void _FireEvent(VxSdk::IVxEvent* vxEvent);
        VxSdk::IVxSystem* _system;
        VxSdk::VxLoginInfo* _loginInfo;
        EventCallbackDelegate ^ _callback;
        static EventDelegate ^ _systemEvent;
        CPPCli::User^ _GetCurrentUser();
    };
}
#endif // VXSystem_h__
