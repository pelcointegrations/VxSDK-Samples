// Declares the situation class.
#ifndef Situation_h__
#define Situation_h__

#include "VxSdk.h"
#include "Device.h"
#include "Notification.h"

namespace CPPCli {

    /// <summary>
    /// The Situation class represents a particular situation configuration that specifies
    /// how corresponding events shall be generated and handled when the situation is detected.
    /// </summary>
    public ref class Situation {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxSituation">The situation.</param>
        Situation(VxSdk::IVxSituation* vxSituation);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Situation() {
            this->!Situation();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Situation();

        /// <summary>
        /// Adds a notification to the list of notifications that this situation serves.
        /// </summary>
        /// <param name="notification">The notification to be added.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the notification.</returns>
        Results::Value AddNotification(Notification^ notification);

        /// <summary>
        /// Associate a data source with this situation.
        /// </summary>
        /// <param name="dataSource">The data source to associate the situation with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of linking the data source.</returns>
        Results::Value Link(DataSource^ dataSource);

        /// <summary>
        /// Associate a device with this situation.
        /// </summary>
        /// <param name="device">The device to associate the situation with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of linking the device.</returns>
        Results::Value Link(Device^ device);

        /// <summary>
        /// Update this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Removes a notification from the list of notifications that this situation serves.
        /// </summary>
        /// <param name="notification">The notification to be removed.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the notification.</returns>
        Results::Value RemoveNotification(Notification^ notification);

        /// <summary>
        /// Remove device association from this situation.
        /// </summary>
        /// <param name="device">The device to remove association with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of unlinking the device.</returns>
        Results::Value UnLink(Device^ device);

        /// <summary>
        /// Remove data source association from this situation.
        /// </summary>
        /// <param name="dataSource">The data source to remove association with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of unlinking the data source.</returns>
        Results::Value UnLink(DataSource^ dataSource);

        /// <summary>
        /// Gets or sets the seconds to wait between audible notifications.
        /// </summary>
        /// <value>The seconds between audible notifications.</value>
        property int AudibleLoopDelay {
        public:
            int get() { return _situation->audibleLoopDelay; }
            void set(int value) { _situation->SetAudibleLoopDelay(value); }
        }

        /// <summary>
        /// Gets or sets the amount of times to play audible notifications.
        /// </summary>
        /// <value>The amount of times to play audible notifications.</value>
        property int AudiblePlayCount {
        public:
            int get() { return _situation->audiblePlayCount; }
            void set(int value) { _situation->SetAudiblePlayCount(value); }
        }

        /// <summary>
        /// Gets or sets the number of seconds after which a generated event state will be set to AutoAcked.
        /// </summary>
        /// <value>The number of seconds before auto-acknowledgement.</value>
        property int AutoAcknowledge {
        public:
            int get() { return _situation->autoAcknowledgeTime; }
            void set(int value) { _situation->SetAutoAcknowledgeTime(value); }
        }

        /// <summary>
        /// Gets or sets whether the generated events shall have an initial state of AckNeeded or NoAckNeeded.
        /// </summary>
        /// <value><c>true</c> if events will require acknowledgement, <c>false</c> if not.</value>
        property bool IsAckNeeded {
        public:
            bool get() { return _situation->isAckNeeded; }
            void set(bool value) { _situation->SetAckNeeded(value); }
        }

        /// <summary>
        /// Gets the data sources associated with this situation.
        /// </summary>
        /// <value>A list of data sources.</value>
        property System::Collections::Generic::List<DataSource^>^ LinkedDataSources {
        public:
            System::Collections::Generic::List<DataSource^>^ get() { return _GetLinkedDataSources(); }
        }

        /// <summary>
        /// Gets the devices associated with this situation.
        /// </summary>
        /// <value>A list of devices.</value>
        property System::Collections::Generic::List<Device^>^ LinkedDevices {
        public:
            System::Collections::Generic::List<Device^>^ get() { return _GetLinkedDevices(); }
        }

        /// <summary>
        /// Gets or sets the situation friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_situation->name); }
            void set(System::String^ value) {
                char name[64];
                strncpy_s(name, Utils::ConvertSysStringNonConst(value), sizeof(name));
                _situation->SetName(name);
            }
        }

        /// <summary>
        /// Gets the notifications configured for this situation.
        /// </summary>
        /// <value>A list of notifications.</value>
        property System::Collections::Generic::List<Notification^>^ Notifications {
        public:
            System::Collections::Generic::List<Notification^>^ get() { return _GetNotifications(); }
        }

        /// <summary>
        /// Gets or sets the severity of the generated event, from 1 (highest) to 10 (lowest).
        /// </summary>
        /// <value>The event severity.</value>
        property int Severity {
        public:
            int get() { return _situation->severity; }
            void set(int value) { _situation->SetSeverity(value); }
        }

        /// <summary>
        /// Gets or sets whether the notification banner on clients should be expanded by default.
        /// </summary>
        /// <value><c>true</c> if the banner should be expanded, <c>false</c> if not.</value>
        property bool ShouldExpandBanner {
        public:
            bool get() { return _situation->shouldExpandBanner; }
            void set(bool value) { _situation->SetExpandBanner(value); }
        }

        /// <summary>
        /// Gets or sets whether events generated from this situation shall be persisted or immediately be discarded.
        /// </summary>
        /// <value><c>true</c> if events will be logged, <c>false</c> if not.</value>
        property bool ShouldLog {
        public:
            bool get() { return _situation->shouldLog; }
            void set(bool value) { _situation->SetLog(value); }
        }

        /// <summary>
        /// Gets or sets whether an event generated from the situation shall generate notifications.
        /// </summary>
        /// <value><c>true</c> if notifications will be sent, <c>false</c> if not.</value>
        property bool ShouldNotify {
        public:
            bool get() { return _situation->shouldNotify; }
            void set(bool value) { _situation->SetNotify(value); }
        }

        /// <summary>
        /// Gets or sets the default snooze intervals, in seconds, for a generated event.
        /// </summary>
        /// <value>A list of snooze intervals in seconds.</value>
        property System::Collections::Generic::List<int>^ SnoozeIntervals {
        public:
            System::Collections::Generic::List<int>^ get() { return _GetSnoozeIntervals(); }
            void set(System::Collections::Generic::List<int>^ value) {
                int snoozeIntervalSize = value->Count;
                int* snoozeIntervals = new int[snoozeIntervalSize];
                for (int i = 0; i < snoozeIntervalSize; i++)
                    snoozeIntervals[i] = value[i];

                _situation->SetSnoozeIntervals(snoozeIntervals, snoozeIntervalSize);
            }
        }

        /// <summary>
        /// Gets the unique source identifier.
        /// </summary>
        /// <value>The unique source identifier.</value>
        property System::String^ SourceDeviceId {
        public:
            System::String^ get() { return gcnew System::String(_situation->sourceDeviceId); }
        }

        /// <summary>
        /// Gets the situation type.
        /// </summary>
        /// <value>The situation type.</value>
        property System::String^ Type {
        public:
            System::String^ get() { return gcnew System::String(_situation->type); }
        }

        /// <summary>
        /// Gets or sets whether a notification sound should play on supporting clients when an event is received.
        /// </summary>
        /// <value><c>true</c> if audio should play on event notification, <c>false</c> if not.</value>
        property bool UseAudibleNotification {
        public:
            bool get() { return _situation->shouldAudiblyNotify; }
            void set(bool value) { _situation->SetAudiblyNotify(value); }
        }

    internal:
        VxSdk::IVxSituation* _situation;
        System::Collections::Generic::List<DataSource^>^ _GetLinkedDataSources();
        System::Collections::Generic::List<Device^>^ _GetLinkedDevices();
        System::Collections::Generic::List<Notification^>^ _GetNotifications();
        System::Collections::Generic::List<int>^ _GetSnoozeIntervals();
    };
}
#endif // Situation_h__
