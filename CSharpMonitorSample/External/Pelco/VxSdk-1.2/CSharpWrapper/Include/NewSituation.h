// Declares the new situation class.
#ifndef NewSituation_h__
#define NewSituation_h__

#include "Utils.h"
#include "Situation.h"

namespace CPPCli {

    /// <summary>
    /// The NewSituation class represents a new situation configuration that specifies how
    /// corresponding events shall be generated and handled when the situation is detected.
    /// </summary>
    public ref class NewSituation {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewSituation() {
            _newSituation = new VxSdk::VxNewSituation();
            _newSituation->Default();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewSituation">The new situation.</param>
        NewSituation(VxSdk::VxNewSituation* vxNewSituation) {
            _newSituation = vxNewSituation;
        }

        /// <summary>
        /// Gets or sets the seconds to wait between audible notifications.
        /// </summary>
        /// <value>The seconds between audible notifications.</value>
        property int AudibleLoopDelay {
        public:
            int get() { return _newSituation->audibleLoopDelay; }
            void set(int value) { _newSituation->audibleLoopDelay = value; }
        }

        /// <summary>
        /// Gets or sets the amount of times to play audible notifications.
        /// </summary>
        /// <value>The amount of times to play audible notifications.</value>
        property int AudiblePlayCount {
        public:
            int get() { return _newSituation->audiblePlayCount; }
            void set(int value) { _newSituation->audiblePlayCount = value; }
        }

        /// <summary>
        /// Gets or sets the number of seconds after which a generated event state will be set to AutoAcked. If less
        /// than 0, a generated event must be manually acknowledged. If 0, a generated event is set to AutoAcked immediately.
        /// </summary>
        /// <value>The number of seconds before auto-acknowledgement.</value>
        property int AutoAcknowledge {
        public:
            int get() { return _newSituation->autoAcknowledge; }
            void set(int value) { _newSituation->autoAcknowledge = value; }
        }

        /// <summary>
        /// Gets or sets whether the generated events shall have an initial state of AckNeeded or NoAckNeeded.
        /// </summary>
        /// <value><c>true</c> if events will require acknowledgement, <c>false</c> if not.</value>
        property bool IsAckNeeded {
        public:
            bool get() { return _newSituation->isAckNeeded; }
            void set(bool value) { _newSituation->isAckNeeded = value; }
        }

        /// <summary>
        /// Gets or sets the situation friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_newSituation->name); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newSituation->name, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the severity of the generated event, from 1 (highest) to 10 (lowest).
        /// </summary>
        /// <value>The event severity.</value>
        property int Severity {
        public:
            int get() { return _newSituation->severity; }
            void set(int value) { _newSituation->severity = value; }
        }

        /// <summary>
        /// Gets or sets whether the notification banner on clients should be expanded by default.
        /// </summary>
        /// <value><c>true</c> if the banner should be expanded, <c>false</c> if not.</value>
        property bool ShouldExpandBanner {
        public:
            bool get() { return _newSituation->shouldExpandBanner; }
            void set(bool value) { _newSituation->shouldExpandBanner = value; }
        }

        /// <summary>
        /// Gets or sets whether events generated from this situation shall be persisted or immediately be discarded.
        /// </summary>
        /// <value><c>true</c> if events will be logged, <c>false</c> if not.</value>
        property bool ShouldLog {
        public:
            bool get() { return _newSituation->shouldLog; }
            void set(bool value) { _newSituation->shouldLog = value; }
        }

        /// <summary>
        /// Gets or sets whether an event generated from the situation shall generate notifications.
        /// </summary>
        /// <value><c>true</c> if notifications will be sent, <c>false</c> if not.</value>
        property bool ShouldNotify {
        public:
            bool get() { return _newSituation->shouldNotify; }
            void set(bool value) { _newSituation->shouldNotify = value; }
        }

        /// <summary>
        /// Gets or sets the default snooze intervals, in seconds, for a generated event.
        /// </summary>
        /// <value>A <c>List</c> of snooze intervals in seconds.</value>
        property System::Collections::Generic::List<int>^ SnoozeIntervals {
        public:
            System::Collections::Generic::List<int>^ get() {
                System::Collections::Generic::List<int>^ mlist = gcnew System::Collections::Generic::List<int>();

                for (int i = 0; i < _newSituation->snoozeIntervalSize; i++)
                    mlist->Add(_newSituation->snoozeIntervals[i]);

                return mlist;
            }
            void set(System::Collections::Generic::List<int>^ value) {
                _newSituation->snoozeIntervalSize = value->Count;
                int *intervals = new int[_newSituation->snoozeIntervalSize];

                for (int i = 0; i < _newSituation->snoozeIntervalSize; i++)
                    intervals[i] = value[i];

                _newSituation->snoozeIntervals = intervals;
            }
        }

        /// <summary>
        /// Gets or sets the unique source identifier. This field acts an optional constraint on the source of
        /// events for this situation. If specified, any events matching the situation type must also match
        /// this SourceDeviceId in order for the situation to apply.
        /// </summary>
        /// <value>The unique source identifier.</value>
        property System::String^ SourceDeviceId {
        public:
            System::String^ get() { return gcnew System::String(_newSituation->sourceDeviceId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newSituation->sourceDeviceId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets situation type.  The type must be of the form external/&lt;company&gt;/&lt;event&gt; where &lt;company&gt;
        /// and &lt;event&gt; are strings no greater than 64 characters each; forward slashes are not allowed. These strings
        /// describe the &lt;company&gt; that manufactured the device that was the source of the &lt;event&gt;.
        /// </summary>
        /// <value>The situation type.</value>
        property System::String^ Type {
        public:
            System::String^ get() { return gcnew System::String(_newSituation->type); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newSituation->type, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets whether a notification sound should play on supporting clients when an event is received.
        /// </summary>
        /// <value><c>true</c> if audio should play on event notification, <c>false</c> if not.</value>
        property bool UseAudibleNotification {
        public:
            bool get() { return _newSituation->shouldAudiblyNotify; }
            void set(bool value) { _newSituation->shouldAudiblyNotify = value; }
        }

    internal:
        VxSdk::VxNewSituation* _newSituation;
    };
}
#endif // NewSituation_h__
