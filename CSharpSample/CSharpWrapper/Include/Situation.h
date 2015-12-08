// Declares the situation class.
#ifndef Situation_h__
#define Situation_h__

#include "VxSdk.h"
#include "Device.h"

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
        /// Associate a device with this situation.
        /// </summary>
        /// <param name="device">The device to associate the situation with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of linking the device.</returns>
        Results::Value Link(Device^ device);

        /// <summary>
        /// Associate a data source with this situation.
        /// </summary>
        /// <param name="dataSource">The data source to associate the situation with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of linking the data source.</returns>
        Results::Value Link(DataSource^ dataSource);

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
        /// Gets the situation type.
        /// </summary>
        /// <value>The situation type.</value>
        property System::String^ Type {
        public:
            System::String^ get() { return gcnew System::String(_situation->type); }
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
        /// Gets the situation friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
        System::String^ get() { return gcnew System::String(_situation->name); }
        }

        /// <summary>
        /// Gets whether an event generated from the situation shall generate notifications.
        /// </summary>
        /// <value><c>true</c> if notifications will be sent, <c>false</c> if not.</value>
        property bool ShouldNotify {
        public:
        bool get() { return _situation->shouldNotify; }
        }

        /// <summary>
        /// Gets whether events generated from this situation shall be persisted or immediately be discarded.
        /// </summary>
        /// <value><c>true</c> if events will be logged, <c>false</c> if not.</value>
        property bool ShouldLog {
        public:
            bool get() { return _situation->shouldLog; }
        }

        /// <summary>
        /// Gets whether the notification banner on clients should be expanded by default.
        /// </summary>
        /// <value><c>true</c> if the banner should be expanded, <c>false</c> if not.</value>
        property bool ShouldExpandBanner {
        public:
            bool get() { return _situation->shouldExpandBanner; }
        }

        /// <summary>
        /// Gets whether the generated events shall have an initial state of AckNeeded or NoAckNeeded.
        /// </summary>
        /// <value><c>true</c> if events will require acknowledgement, <c>false</c> if not.</value>
        property bool IsAckNeeded {
        public:
            bool get() { return _situation->isAckNeeded; }
        }

        /// <summary>
        /// Gets whether a notification sound should play on supporting clients when an event is received.
        /// </summary>
        /// <value><c>true</c> if audio should play on event notification, <c>false</c> if not.</value>
        property bool UseAudibleNotification {
        public:
            bool get() { return _situation->shouldAudiblyNotify; }
        }

        /// <summary>
        /// Gets the number of seconds after which a generated event state will be set to AutoAcked.
        /// </summary>
        /// <value>The number of seconds before auto-acknowledgement.</value>
        property int AutoAcknowledge {
        public:
            int get() { return _situation->autoAcknowledgeTime; }
        }

        /// <summary>
        /// Gets the seconds to wait between audible notifications.
        /// </summary>
        /// <value>The seconds between audible notifications.</value>
        property int AudibleLoopDelay {
        public:
            int get() { return _situation->audibleLoopDelay; }
        }

        /// <summary>
        /// Gets the amount of times to play audible notifications.
        /// </summary>
        /// <value>The amount of times to play audible notifications.</value>
        property int AudiblePlayCount {
        public:
            int get() { return _situation->audiblePlayCount; }
        }

        /// <summary>
        /// Gets the severity of the generated event, from 1 (highest) to 10 (lowest).
        /// </summary>
        /// <value>The event severity.</value>
        property int Severity {
        public:
            int get() { return _situation->severity; }
        }

        /// <summary>
        /// Gets the default snooze intervals, in seconds, for a generated event.
        /// </summary>
        /// <value>A list of snooze intervals in seconds.</value>
        property System::Collections::Generic::List<int>^ SnoozeIntervals {
        public:
            System::Collections::Generic::List<int>^ get() { return _GetSnoozeIntervals(); }
        }

        /// <summary>
        /// Gets the IDs of the notifications configured for this situation.
        /// </summary>
        /// <value>A list of notification IDs.</value>
        property System::Collections::Generic::List<System::String^>^ NotificationIds {
        public:
            System::Collections::Generic::List<System::String^>^ get() { return _GetNotificationIds(); }
        }

    internal:
        VxSdk::IVxSituation* _situation;
        System::Collections::Generic::List<int>^ _GetSnoozeIntervals();
        System::Collections::Generic::List<System::String^>^ _GetNotificationIds();
    };
}
#endif // Situation_h__
