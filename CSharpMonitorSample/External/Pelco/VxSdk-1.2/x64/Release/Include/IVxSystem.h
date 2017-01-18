#ifndef IVxSystem_h__
#define IVxSystem_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxBookmark.h"
#include "IVxDataObject.h"
#include "IVxDevice.h"
#include "IVxEvent.h"
#include "IVxExport.h"
#include "IVxLicense.h"
#include "IVxRole.h"
#include "IVxSituation.h"
#include "IVxTag.h"
#include "VxCollection.h"
#include "VxNewBookmark.h"
#include "VxNewDataObject.h"
#include "VxNewEvent.h"
#include "VxNewExport.h"
#include "VxNewSituation.h"
#include "VxNewTag.h"
#include "VxNewUser.h"
#include "IVxMonitor.h"

namespace VxSdk {
    struct VxNewDevice;
    struct VxQuickReportFilter;

    /// <summary>
    /// Represents a VideoXpert system and allows the user to manage the system and devices.
    /// </summary>
    struct IVxSystem {
    public:
        /// <summary>
        /// Adds a new bookmark on the VideoXpert system.
        /// </summary>
        /// <param name="newBookmark">The new bookmark to be added to the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddBookmark(VxNewBookmark& newBookmark) const = 0;
        /// <summary>
        /// Creates a new data object.
        /// </summary>
        /// <param name="newDataObject">The new data object to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddDataObject(VxNewDataObject& newDataObject) const = 0;
        /// <summary>
        /// Adds a device to the VideoXpert system.
        /// </summary>
        /// <param name="newDevice">The new device to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddDevice(VxNewDevice& newDevice) const = 0;
        /// <summary>
        /// Creates a new drawing.
        /// </summary>
        /// <param name="newDrawing">The new drawing to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddDrawing(VxNewDrawing& newDrawing) const = 0;
        /// <summary>
        /// Creates a new notification.
        /// </summary>
        /// <param name="newNotification">The new notification to be added.</param>
        /// <param name="notificationItem"><c>nullptr</c> if it fails, else the new <see cref="IVxNotification"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddNotification(VxNewNotification& newNotification, IVxNotification*& notificationItem) const = 0;
        /// <summary>
        /// Adds a new role to the system.
        /// </summary>
        /// <param name="roleName">The new role to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddRole(const char* roleName) const = 0;
        /// <summary>
        /// Adds a new schedule to the system.
        /// </summary>
        /// <param name="newSchedule">The new schedule to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddSchedule(VxNewSchedule& newSchedule) const = 0;
        /// <summary>
        /// Adds a new situation to the system.
        /// </summary>
        /// <param name="newSituation">The new situation to be added to the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddSituation(VxNewSituation& newSituation) const = 0;
        /// <summary>
        /// Adds a new tag to the system.
        /// </summary>
        /// <param name="newTag">The new tag to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddTag(VxNewTag& newTag) const = 0;
        /// <summary>
        /// Adds a new user to the system.
        /// </summary>
        /// <param name="newUser">The new user to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddUser(VxNewUser& newUser) const = 0;
        /// <summary>
        /// Initiates a network search on the VideoXpert system which automatically adds any new Pelco devices discovered.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AutoAddDevices() const = 0;
        /// <summary>
        /// Creates a new export on the VideoXpert system.
        /// </summary>
        /// <param name="newExport">The new export to be added to the system.</param>
        /// <param name="exportItem"><c>nullptr</c> if it fails, else the new <see cref="IVxExport"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreateExport(VxNewExport& newExport, IVxExport*& exportItem) const = 0;
        /// <summary>
        /// Adds a new monitor to the system.
        /// </summary>
        /// <param name="newMonitor">The new monitor to be added to the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreateMonitor(VxNewMonitor& newMonitor) const = 0;
        /// <summary>
        /// Creates a quick system health report on the VideoXpert system.
        /// </summary>
        /// <param name="newQuickReport">The new quick report to be generated on the system.</param>
        /// <param name="quickReport"><c>nullptr</c> if it fails, else the new <see cref="IVxQuickReport"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreateQuickReport(VxNewQuickReport& newQuickReport, IVxQuickReport*& quickReport) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the bookmarks residing on the system.
        /// <para>Available filters: kDataSourceId, kDataSourceNumber, kDescription, kModifiedSince, kSearchEndTime, kSearchStartTime, kTime.</para>
        /// </summary>
        /// <param name="bookmarkCollection">A <see cref="VxCollection"/> of the bookmarks residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetBookmarks(VxCollection<IVxBookmark**>& bookmarkCollection) const = 0;
        /// <summary>
        /// Gets the cluster configuration.
        /// </summary>
        /// <param name="clusterConfig">The cluster configuration..</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetClusterConfiguration(IVxConfiguration::Cluster*& clusterConfig) const = 0;
        /// <summary>
        /// Gets the user currently accessing the system.
        /// </summary>
        /// <param name="user">The user currently accessing the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetCurrentUser(IVxUser*& user) const = 0;
        /// <summary>
        /// Gets the data objects residing on the system.
        /// <para>Available filters: kClientType, kModifiedSince, kOwned, kOwner.</para>
        /// </summary>
        /// <param name="dataObjectCollection">A <see cref="VxCollection"/> of data objects residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataObjects(VxCollection<IVxDataObject**>& dataObjectCollection) const = 0;
        /// <summary>
        /// Gets the data sources from the VideoXpert system.
        /// <para>Available filters: kAllTags, kCapturing, kId, kIp, kModifiedSince, kName, kNumber, kRecording, kState, kType, kUnassigned.</para>
        /// </summary>
        /// <param name="dataSourceCollection">A <see cref="VxCollection"/> of the data sources associated with the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSources(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the data storages residing on the system.
        /// <para>Available filters: kId, kModifiedSince, kName, kType.</para>
        /// </summary>
        /// <param name="dataStorageCollection">A <see cref="VxCollection"/> of data storages residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataStorages(VxCollection<IVxDataStorage**>& dataStorageCollection) const = 0;
        /// <summary>
        /// Gets the devices from the VideoXpert system.
        /// <para>Available filters: kAllTags, kCommissioned, kId, kIp, kModel, kModifiedSince, kName, kSerial, kState, kType, kVendor, kVersion.</para>
        /// </summary>
        /// <param name="deviceCollection">A <see cref="VxCollection"/> of the devices associated with the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDevices(VxCollection<IVxDevice**>& deviceCollection) const = 0;
        /// <summary>
        /// Gets the drawings from the VideoXpert system.
        /// <para>Available filters: kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="drawingCollection">A <see cref="VxCollection"/> of the drawings associated with the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDrawings(VxCollection<IVxDrawing**>& drawingCollection) const = 0;
        /// <summary>
        /// Gets the events residing on the system.
        /// <para>Available filters: kAckState, kAckUser, kGeneratorDeviceId, kId, kModifiedSince, kNotifies, kSearchEndTime, kSearchStartTime, kSeverity,
        /// kSituationType, kSourceDeviceId, kSourceUserName, kTime.</para>
        /// </summary>
        /// <param name="eventCollection">A <see cref="VxCollection"/> of the events residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetEvents(VxCollection<IVxEvent**>& eventCollection) const = 0;
        /// <summary>
        /// Gets the exports residing on the system.
        /// <para>Available filters: kModifiedSince, kName, kPercentComplete, kSize, kStatus.</para>
        /// </summary>
        /// <param name="exportCollection">A <see cref="VxCollection"/> of the exports residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetExports(VxCollection<IVxExport**>& exportCollection) const = 0;
        /// <summary>
        /// Gets the license for the system.
        /// </summary>
        /// <param name="license">The license for the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLicense(IVxLicense*& license) const = 0;
        /// <summary>
        /// Gets the monitors residing on the system.
        /// <para>Available filters: kModifiedSince, kName, kNumber.</para>
        /// </summary>
        /// <param name="monitorCollection">A <see cref="VxCollection"/> of the monitors residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMonitors(VxCollection<IVxMonitor**>& monitorCollection) const = 0;
        /// <summary>
        /// Gets the notifications residing on the system.
        /// <para>Available filters: kModifiedSince.</para>
        /// </summary>
        /// <param name="notificationCollection">A <see cref="VxCollection"/> of the notifications residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetNotifications(VxCollection<IVxNotification**>& notificationCollection) const = 0;
        /// <summary>
        /// Gets the roles residing on the system.
        /// <para>Available filters: kId, kInternal, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="roleCollection">A <see cref="VxCollection"/> of roles residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRoles(VxCollection<IVxRole**>& roleCollection) const = 0;
        /// <summary>
        /// Gets the schedules residing on the system.
        /// <para>Available filters: kAction, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="scheduleCollection">A <see cref="VxCollection"/> of schedules residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSchedules(VxCollection<IVxSchedule**>& scheduleCollection) const = 0;
        /// <summary>
        /// Gets the situations residing on the system.
        /// <para>Available filters: kAudibleNotify, kLog, kModifiedSince, kNotify, kSeverity, kSourceDeviceId, kType.</para>
        /// </summary>
        /// <param name="situationCollection">A <see cref="VxCollection"/> of the situations residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSituations(VxCollection<IVxSituation**>& situationCollection) const = 0;
        /// <summary>
        /// Gets the tags residing on the system.
        /// <para>Available filters: kModifiedSince, kName, kOwned, kOwner, kResourceId, kResourceType.</para>
        /// </summary>
        /// <param name="tagCollection">A <see cref="VxCollection"/> of tags residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetTags(VxCollection<IVxTag**>& tagCollection) const = 0;
        /// <summary>
        /// Gets the users residing on the system.
        /// <para>Available filters: kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="userCollection">A <see cref="VxCollection"/> of users residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUsers(VxCollection<IVxUser**>& userCollection) const = 0;
        /// <summary>
        /// Inserts a new event into the system.
        /// </summary>
        /// <param name="newEvent">The new event to be injected into the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value InsertEvent(VxNewEvent& newEvent) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Start receiving event notifications using the settings for the current user.
        /// </summary>
        /// <param name="callback">The callback to be used when an event is received.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value StartNotifications(VxEventCallback callback) const = 0;
        /// <summary>
        /// Start receiving event notifications by situation type, regardless of user settings.
        /// </summary>
        /// <param name="callback">The callback to be used when an event is received.</param>
        /// <param name="situationCollection">The situations to subscribe to.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value StartNotifications(VxEventCallback callback, VxCollection<IVxSituation**>& situationCollection) const = 0;
        /// <summary>
        /// Stop receiving all event notifications.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value StopNotifications() const = 0;

    public:
        /// <summary>
        /// The unique identifier of the VideoXpert system.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the VideoXpert system.
        /// </summary>
        char name[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->name);
        }
    };
}

#endif // IVxSystem_h__
