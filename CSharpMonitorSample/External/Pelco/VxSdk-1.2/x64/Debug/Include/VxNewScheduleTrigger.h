#ifndef VxNewScheduleTrigger_h__
#define VxNewScheduleTrigger_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxKvObject.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new schedule trigger to be created.  A schedule trigger is a time range and an optional event that
    /// together act as a trigger to activate a schedule and cause it to perform its configured action.
    /// </summary>
    struct VxNewScheduleTrigger {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewScheduleTrigger"/> struct.
        /// </summary>
        VxNewScheduleTrigger() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewScheduleTrigger"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewScheduleTrigger(const VxNewScheduleTrigger& ref) {
            Utilities::StrCopySafe(this->dailyEndTime, ref.dailyEndTime);
            Utilities::StrCopySafe(this->dailyStartTime, ref.dailyStartTime);
            Utilities::StrCopySafe(this->endDate, ref.endDate);
            Utilities::StrCopySafe(this->eventSourceDevice, ref.eventSourceDevice);
            Utilities::StrCopySafe(this->id, ref.id);
            Utilities::StrCopySafe(this->startDate, ref.startDate);
            this->eventPropertySize = ref.eventPropertySize;
            this->postTrigger = ref.postTrigger;
            this->preTrigger = ref.preTrigger;
            this->recurMonthlySize = ref.recurMonthlySize;
            this->recurWeeklySize = ref.recurWeeklySize;
            this->recurYearlySize = ref.recurYearlySize;
            this->timeout = ref.timeout;
            this->recurMonthly = ref.recurMonthly;
            this->recurWeekly = ref.recurWeekly;
            this->recurYearly = ref.recurYearly;
            this->eventProperties = ref.eventProperties;
            this->framerate = ref.framerate;
            this->recurrence = ref.recurrence;
            this->event = ref.event;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewScheduleTrigger"/> class.
        /// </summary>
        ~VxNewScheduleTrigger() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dailyEndTime);
            VxZeroArray(this->dailyStartTime);
            VxZeroArray(this->endDate);
            VxZeroArray(this->eventSourceDevice);
            VxZeroArray(this->id);
            VxZeroArray(this->startDate);
            this->eventPropertySize = 0;
            this->postTrigger = 0;
            this->preTrigger = 0;
            this->recurMonthlySize = 0;
            this->recurWeeklySize = 0;
            this->recurYearlySize = 0;
            this->timeout = 0;
            this->recurMonthly = nullptr;
            this->recurWeekly = nullptr;
            this->recurYearly = nullptr;
            this->eventProperties = nullptr;
            this->framerate = VxRecordingFramerate::kUnknown;
            this->recurrence = VxRecurrenceType::kUnknown;
            this->event = VxSituationType::kUnknown;
        }

    public:
        /// <summary>
        /// The time at which the schedule trigger ends. A schedule trigger is active each day, only from
        /// <see cref="dailyStartTime"/> to <see cref="dailyEndTime"/>. If the <see cref="dailyEndTime"/> is less than the
        /// <see cref="dailyStartTime"/>, it is to be considered as occurring later (the following day). If these values
        /// are equal, the schedule trigger is not restricted by time. Defaults to 00:00:00.
        /// </summary>
        char dailyEndTime[64];
        /// <summary>
        /// The time at which the schedule trigger begins. A schedule trigger is active each day, only from
        /// <see cref="dailyStartTime"/> to <see cref="dailyEndTime"/>. If these values are equal, the schedule trigger is
        /// not restricted by time. Defaults to 00:00:00.
        /// </summary>
        char dailyStartTime[64];
        /// <summary>
        /// The date at which the schedule trigger ends. A schedule trigger is active, only from <see cref="startDate"/>
        /// to <see cref="endDate"/>. If the <see cref="endDate"/> is prior or equal to the <see cref="startDate"/>, the
        /// schedule trigger is not limited by date. Defaults to the value of <see cref="startDate"/>.
        /// </summary>
        char endDate[64];
        /// <summary>
        /// The unique identifier of a device. If set, the <see cref="event"/> will activate the schedule trigger only
        /// when it occurs on this device. Ignored if no <see cref="event"/> is set.
        /// </summary>
        char eventSourceDevice[64];
        /// <summary>
        /// The unique identifier of the schedule trigger. If not supplied, the system will create the identifier.
        /// </summary>
        char id[64];
        /// <summary>
        /// The date at which the schedule trigger begins. A schedule trigger is active, only from <see cref="startDate"/>
        /// to <see cref="endDate"/>. If the <see cref="endDate"/> is prior or equal to the <see cref="startDate"/>, the
        /// schedule trigger is not limited by date. Defaults to the current date.
        /// </summary>
        char startDate[64];
        /// <summary>
        /// The size of <see cref="eventProperties"/>.
        /// </summary>
        int eventPropertySize;
        /// <summary>
        /// Amount of time, from 0 to 300 seconds, to continue to consider the schedule trigger active when it becomes
        /// inactive ("post alarm"). Defaults to 0.
        /// </summary>
        int postTrigger;
        /// <summary>
        /// Amount of time, from 0 to 30 seconds, to consider the schedule trigger active prior to when it becomes active
        /// ("pre alarm"). Defaults to 0.
        /// </summary>
        int preTrigger;
        /// <summary>
        /// The size of <see cref="recurMonthly"/>.
        /// </summary>
        int recurMonthlySize;
        /// <summary>
        /// The size of <see cref="recurWeekly"/>.
        /// </summary>
        int recurWeeklySize;
        /// <summary>
        /// The size of <see cref="recurYearly"/>.
        /// </summary>
        int recurYearlySize;
        /// <summary>
        /// Amount of time, from 1 to 300 seconds, to consider the schedule trigger active immediately after it becomes
        /// active ("duration recording"). Defaults to 0.
        /// </summary>
        int timeout;
        /// <summary>
        /// Days of the month, from 1 to 31, that the schedule trigger shall only be active on. Defaults to every day of the
        /// month. Ignored if <see cref="recurrence"/> is not set to <see cref="VxRecurrenceType::kMonthly"/>.
        /// </summary>
        int* recurMonthly;
        /// <summary>
        /// Days of the week, from 1 (Monday) to 7 (Sunday), that the schedule trigger shall only be active on. Defaults to
        /// every day of the week. Ignored if <see cref="recurrence"/> is not set to <see cref="VxRecurrenceType::kWeekly"/>.
        /// </summary>
        int* recurWeekly;
        /// <summary>
        /// Months of the year, from 1 (January) to 12 (December), that the schedule trigger shall only be active on. Defaults
        /// to every month of the year. Ignored if <see cref="recurrence"/> is not set to <see cref="VxRecurrenceType::kYearly"/>.
        /// </summary>
        int* recurYearly;
        /// <summary>
        /// If set, the event only activates when it occurs with these properties. Ignored if no <see cref="event"/> is set.
        /// </summary>
        VxKvObject* eventProperties;
        /// <summary>
        /// The framerate level to record at. Defaults to <see cref="VxRecordingFramerate::kNormal"/>.
        /// </summary>
        VxRecordingFramerate::Value framerate;
        /// <summary>
        /// Interval at which the schedule trigger repeats. Defaults to <see cref="VxRecurrenceType::kDaily"/>.
        /// </summary>
        VxRecurrenceType::Value recurrence;
        /// <summary>
        /// If set, the schedule trigger only activates when this type of <see cref="VxSituationType::Value">VxSituationType</see>
        /// occurs. The schedule trigger event state shall be considered active until the event becomes inactive.
        /// </summary>
        VxSituationType::Value event;
    };
}

#endif // VxNewScheduleTrigger_h__
