#ifndef VxNewSituation_h__
#define VxNewSituation_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new situation configuration that specifies how corresponding events shall be generated and handled
    /// when the situation is detected.
    /// </summary>
    struct VxNewSituation {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewSituation"/> struct.
        /// </summary>
        VxNewSituation() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewSituation"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewSituation(const VxNewSituation& ref) {
            this->isAckNeeded = ref.isAckNeeded;
            this->shouldAudiblyNotify = ref.shouldAudiblyNotify;
            this->shouldExpandBanner = ref.shouldExpandBanner;
            this->shouldLog = ref.shouldLog;
            this->shouldNotify = ref.shouldNotify;
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->sourceDeviceId, ref.sourceDeviceId);
            Utilities::StrCopySafe(this->type, ref.type);
            this->audibleLoopDelay = ref.audibleLoopDelay;
            this->audiblePlayCount = ref.audiblePlayCount;
            this->autoAcknowledge = ref.autoAcknowledge;
            this->severity = ref.severity;
            this->snoozeIntervalSize = ref.snoozeIntervalSize;
            this->snoozeIntervals = ref.snoozeIntervals;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewSituation"/> class.
        /// </summary>
        ~VxNewSituation() {
            Clear();
        }

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
            this->audibleLoopDelay = 0;
            this->audiblePlayCount = 0;
            this->autoAcknowledge = 0;
            this->severity = 0;
            this->snoozeIntervalSize = 0;
            this->snoozeIntervals = nullptr;
        }

        /// <summary>
        /// Defaults this instance.
        /// </summary>
        /// <remarks>Careful, this allocates snoozeIntervals so ensure to manage the memory</remarks>
        void Default() {
            this->isAckNeeded = false;
            this->shouldAudiblyNotify = false;
            this->shouldExpandBanner = true;
            this->shouldLog = true;
            this->shouldNotify = false;
            VxZeroArray(this->name);
            VxZeroArray(this->sourceDeviceId);
            VxZeroArray(this->type);
            this->audibleLoopDelay = 0;
            this->audiblePlayCount = 1;
            this->autoAcknowledge = -1;
            this->severity = 5;
            this->snoozeIntervalSize = 3;
            this->snoozeIntervals = new int[3];
            this->snoozeIntervals[0] = 60;
            this->snoozeIntervals[1] = 300;
            this->snoozeIntervals[2] = 600;
        }

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
        /// The situation friendly name.
        /// </summary>
        char name[64];
        /// <summary>
        /// The unique source identifier. This field acts an optional constraint on the source of
        /// events for this situation. If specified, any events matching the situation type must also match
        /// this SourceDeviceId in order for the situation to apply.
        /// </summary>
        char sourceDeviceId[64];
        /// <summary>
        /// The situation type. The type must be of the form external/&lt;company&gt;/&lt;event&gt; where &lt;company&gt;
        /// and &lt;event&gt; are strings no greater than 64 characters each; forward slashes are not allowed. These strings
        /// describe the &lt;company&gt; that manufactured the device that was the source of the &lt;event&gt;.
        /// </summary>
        char type[128];
        /// <summary>
        /// The seconds to wait between audible notifications.
        /// </summary>
        int audibleLoopDelay;
        /// <summary>
        /// The amount of times to play audible notifications.
        /// </summary>
        int audiblePlayCount;
        /// <summary>
        /// The number of seconds after which a generated event state will be set to AutoAcked. If less than 0, a generated
        /// event must be manually acknowledged. If 0, a generated event is set to AutoAcked immediately.
        /// </summary>
        int autoAcknowledge;
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
    };
}

#endif // VxNewSituation_h__