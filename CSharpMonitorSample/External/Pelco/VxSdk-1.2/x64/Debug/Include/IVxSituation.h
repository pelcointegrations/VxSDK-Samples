#ifndef IVxSituation_h__
#define IVxSituation_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a particular situation configuration that specifies how corresponding events shall be generated and handled
    /// when the situation is detected.
    /// </summary>
    struct IVxSituation {
    public:
        /// <summary>
        /// Adds a notification to the list of notifications that this situation serves.
        /// </summary>
        /// <param name="notification">The notification to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddNotification(IVxNotification& notification) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this situation from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the situation.</returns>
        virtual VxResult::Value DeleteSituation() const = 0;
        /// <summary>
        /// Gets the data sources associated with this situation.
        /// <para>Available filters: kAllTags, kCapturing, kId, kIp, kModifiedSince, kName, kNumber, kRecording, kState, kType, kUnassigned.</para>
        /// </summary>
        /// <param name="dataSourceCollection">The data sources associated with this situation.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the devices associated with this situation.
        /// <para>Available filters: kAllTags, kCommissioned, kId, kIp, kModel, kModifiedSince, kName, kSerial, kState, kType, kVendor, kVersion.</para>
        /// </summary>
        /// <param name="deviceCollection">The devices associated with this situation.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDevice**>& deviceCollection) const = 0;
        /// <summary>
        /// Gets the notifications associated with this situation.
        /// <para>Available filters: kModifiedSince.</para>
        /// </summary>
        /// <param name="notificationCollection">A <see cref="VxCollection"/> of notifications associated with this situation.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetNotifications(VxCollection<IVxNotification**>& notificationCollection) const = 0;
        /// <summary>
        /// Associates a data source with this situation.
        /// </summary>
        /// <param name="dataSource">The data source to associate the situation with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDataSource& dataSource) const = 0;
        /// <summary>
        /// Associates a device with this situation.
        /// </summary>
        /// <param name="device">The device to associate the situation with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDevice& device) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Removes a notification from the list of notifications that this situation serves.
        /// </summary>
        /// <param name="notification">The notification to be removed.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value RemoveNotification(IVxNotification& notification) const = 0;
        /// <summary>
        /// Sets whether the generated events shall have an initial state of AckNeeded or NoAckNeeded.
        /// </summary>
        /// <param name="isAckNeeded">True to set initial state to AckNeeded.  False for NoAckNeeded.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAckNeeded(bool isAckNeeded) = 0;
        /// <summary>
        /// Sets the audible loop delay property.
        /// </summary>
        /// <param name="audibleLoopDelay">The audible loop delay value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAudibleLoopDelay(int audibleLoopDelay) = 0;
        /// <summary>
        /// Sets the audible play count property.
        /// </summary>
        /// <param name="audiblePlayCount">The audible play count value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAudiblePlayCount(int audiblePlayCount) = 0;
        /// <summary>
        /// Sets whether a notification sound should play on supporting clients when an event is received.
        /// </summary>
        /// <param name="shouldAudiblyNotify">True to audibly notify, otherwise false.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAudiblyNotify(bool shouldAudiblyNotify) = 0;
        /// <summary>
        /// Sets the auto acknowledge time property.
        /// </summary>
        /// <param name="autoAcknowledgeTime">The auto acknowledge time value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAutoAcknowledgeTime(int autoAcknowledgeTime) = 0;
        /// <summary>
        /// Sets whether the notification banner on clients should be expanded by default.
        /// </summary>
        /// <param name="shouldExpandBanner">True to expand banner, otherwise false.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetExpandBanner(bool shouldExpandBanner) = 0;
        /// <summary>
        /// Sets whether events generated from this situation shall be persisted or immediately be discarded.
        /// </summary>
        /// <param name="shouldLog">True to log events, otherwise false.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetLog(bool shouldLog) = 0;
        /// <summary>
        /// Sets whether an event generated from the situation will generate notifications.
        /// </summary>
        /// <param name="shouldNotify">True to send notifications, otherwise false.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetNotify(bool shouldNotify) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the severity property.
        /// </summary>
        /// <param name="severity">The new severity value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSeverity(int severity) = 0;
        /// <summary>
        /// Sets the snooze intervals for a generated event.
        /// </summary>
        /// <param name="snoozeIntervals">The snooze intervals, in seconds.</param>
        /// <param name="snoozeIntervalSize">The size of <see cref="snoozeIntervals"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSnoozeIntervals(int* snoozeIntervals, int snoozeIntervalSize) = 0;
        /// <summary>
        /// Removes a data source association from this situation.
        /// </summary>
        /// <param name="dataSource">The data source to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDataSource& dataSource) const = 0;
        /// <summary>
        /// Removes a device association from this situation.
        /// </summary>
        /// <param name="device">The device to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDevice& device) const = 0;

    public:
        /// <summary>
        /// Indicates whether the generated events shall have an initial state of AckNeeded or NoAckNeeded.
        /// </summary>
        bool isAckNeeded;
        /// <summary>
        /// Indicates whether a notification sound should play on supporting clients when an event is received.
        /// </summary>
        bool shouldAudiblyNotify;
        /// <summary>
        /// Indicates whether the notification banner on clients should be expanded by default.
        /// </summary>
        bool shouldExpandBanner;
        /// <summary>
        /// Indicates whether events generated from this situation shall be persisted or immediately be discarded.
        /// </summary>
        bool shouldLog;
        /// <summary>
        /// Indicates whether an event generated from the situation shall generate notifications.
        /// </summary>
        bool shouldNotify;
        /// <summary>
        /// The friendly name of the situation.
        /// </summary>
        char name[64];
        /// <summary>
        /// The unique identifier of the source device.
        /// </summary>
        char sourceDeviceId[64];
        /// <summary>
        /// The situation type.
        /// </summary>
        char type[128];
        /// <summary>
        /// The unique identifiers of the notifications configured for this situation.
        /// </summary>
        char** notificationIds;
        /// <summary>
        /// The number of seconds after which a generated event state will be set to AutoAcked.
        /// </summary>
        int autoAcknowledgeTime;
        /// <summary>
        /// The seconds to wait between audible notifications.
        /// </summary>
        int audibleLoopDelay;
        /// <summary>
        /// The amount of times to play audible notifications.
        /// </summary>
        int audiblePlayCount;
        /// <summary>
        /// The size of <see cref="notificationIds"/>.
        /// </summary>
        int notificationIdSize;
        /// <summary>
        /// The severity of the generated event, from 1 (highest) to 10 (lowest).
        /// </summary>
        int severity;
        /// <summary>
        /// The size of <see cref="snoozeIntervals"/>.
        /// </summary>
        int snoozeIntervalSize;
        /// <summary>
        /// The default snooze intervals, in seconds, for a generated event.
        /// </summary>
        int* snoozeIntervals;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isAckNeeded = false;
            this->shouldAudiblyNotify = false;
            this->shouldExpandBanner = false;
            this->shouldLog = false;
            this->shouldNotify = false;
            VxZeroArray(this->name);
            VxZeroArray(this->sourceDeviceId);
            VxZeroArray(this->type);
            this->notificationIds = nullptr;
            this->autoAcknowledgeTime = 0;
            this->audibleLoopDelay = 0;
            this->audiblePlayCount = 0;
            this->notificationIdSize = 0;
            this->severity = 0;
            this->snoozeIntervalSize = 0;
            this->snoozeIntervals = nullptr;
        }
    };
}

#endif // IVxSituation_h__
