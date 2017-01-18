#ifndef IVxScheduleTrigger_h__
#define IVxScheduleTrigger_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a schedule trigger. A schedule trigger is a time range and an optional event that together act as a trigger to
    /// activate a schedule and cause it to perform its configured action.
    /// </summary>
    struct IVxScheduleTrigger {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this schedule trigger from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the schedule trigger.</returns>
        virtual VxResult::Value DeleteScheduleTrigger() const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the time at which the schedule trigger ends.
        /// </summary>
        /// <param name="dailyEndTime">A time value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDailyEndTime(char dailyEndTime[64]) = 0;
        /// <summary>
        /// Sets the time at which the schedule trigger starts.
        /// </summary>
        /// <param name="dailyStartTime">A time value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDailyStartTime(char dailyStartTime[64]) = 0;
        /// <summary>
        /// Sets the date at which the schedule trigger ends.
        /// </summary>
        /// <param name="endDate">A date value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEndDate(char endDate[64]) = 0;
        /// <summary>
        /// Sets the event source device.  Events will activate the schedule trigger only when they
        /// occur on this device.
        /// </summary>
        /// <param name="eventSourceDevice">The unique identifier of a device.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEventSourceDevice(char eventSourceDevice[64]) = 0;
        /// <summary>
        /// Sets the date at which the schedule trigger starts.
        /// </summary>
        /// <param name="startDate">A date value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetStartDate(char startDate[64]) = 0;
        /// <summary>
        /// Sets the amount of time to continue to consider the schedule trigger active when it becomes
        /// inactive ("post alarm").
        /// </summary>
        /// <param name="postTrigger">The post trigger time in seconds, from 0 to 300.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPostTrigger(int postTrigger) = 0;
        /// <summary>
        /// Sets the amount of time to consider the schedule trigger active prior to when it becomes active
        /// ("pre alarm").
        /// </summary>
        /// <param name="preTrigger">The pre trigger time in seconds, from 0 to 30.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPreTrigger(int preTrigger) = 0;
        /// <summary>
        /// Sets the amount of time to consider the schedule trigger active immediately after it becomes
        /// active ("duration recording").
        /// </summary>
        /// <param name="timeout">The timeout time in seconds, from 0 to 300.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetTimeout(int timeout) = 0;
        /// <summary>
        /// Sets the days of the month that the schedule trigger shall only be active on.
        /// </summary>
        /// <param name="daysOfMonth">The days of the month, from 1 to 31.</param>
        /// <param name="daysOfMonthSize">The size of daysOfMonth.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetMonthlyRecurrence(int* daysOfMonth, int daysOfMonthSize) = 0;
        /// <summary>
        /// Sets the days of the week that the schedule trigger shall only be active on.
        /// </summary>
        /// <param name="daysOfWeek">The days of the week, from 1 (Monday) to 7 (Sunday).</param>
        /// <param name="daysOfWeekSize">The size of daysOfWeek.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetWeeklyRecurrence(int* daysOfWeek, int daysOfWeekSize) = 0;
        /// <summary>
        /// Sets the months of the year that the schedule trigger shall only be active on.
        /// </summary>
        /// <param name="monthsOfYear">The months of the year, from 1 (January) to 12 (December).</param>
        /// <param name="monthsOfYearSize">The size of monthsOfYear.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetYearlyRecurrence(int* monthsOfYear, int monthsOfYearSize) = 0;
        /// <summary>
        /// Sets the event properties that must be present to activate the schedule trigger.
        /// </summary>
        /// <param name="eventProperties">The event properties.</param>
        /// <param name="eventPropertySize">The size of <see cref="eventProperties"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEventProperties(VxKvObject* eventProperties, int eventPropertySize) = 0;
        /// <summary>
        /// Sets the framerate level to record at.
        /// </summary>
        /// <param name="framerate">The framerate level.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetFramerate(VxRecordingFramerate::Value framerate) = 0;
        /// <summary>
        /// Sets the interval at which the schedule trigger repeats.
        /// </summary>
        /// <param name="recurrence">The recurrence interval.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetRecurrence(VxRecurrenceType::Value recurrence) = 0;
        /// <summary>
        /// Sets the <see cref="VxSituationType::Value">VxSituationType</see> that will activate the schedule trigger.
        /// </summary>
        /// <param name="eventType">The event type.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEventType(VxSituationType::Value eventType) = 0;

    public:
        /// <summary>
        /// The time at which the schedule trigger ends. A schedule trigger is active each day, only from <see cref="dailyStartTime"/>
        /// to <see cref="dailyEndTime"/>. If the <see cref="dailyEndTime"/> is less than the <see cref="dailyStartTime"/>, it is to be
        /// considered as occurring later (the following day). If these values are equal, the schedule trigger is not restricted by time.
        /// </summary>
        char dailyEndTime[64];
        /// <summary>
        /// The time at which the schedule trigger begins. A schedule trigger is active each day, only from <see cref="dailyStartTime"/>
        /// to <see cref="dailyEndTime"/>. If these values are equal, the schedule trigger is not restricted by time.
        /// </summary>
        char dailyStartTime[64];
        /// <summary>
        /// The date at which the schedule trigger ends. A schedule trigger is active, only from <see cref="startDate"/> to
        /// <see cref="endDate"/>. If the <see cref="endDate"/> is prior or equal to the <see cref="startDate"/>, the schedule trigger
        /// is not limited by date.
        /// </summary>
        char endDate[64];
        /// <summary>
        /// The unique identifier of a device. If set, the <see cref="event"/> will activate the schedule trigger only when it occurs
        /// on this device.
        /// </summary>
        char eventSourceDevice[64];
        /// <summary>
        /// The unique identifier of the schedule trigger.
        /// </summary>
        char id[64];
        /// <summary>
        /// The date at which the schedule trigger begins. A schedule trigger is active, only from <see cref="startDate"/> to
        /// <see cref="endDate"/>. If the <see cref="endDate"/> is prior or equal to the <see cref="startDate"/>, the schedule trigger is
        /// not limited by date.
        /// </summary>
        char startDate[64];
        /// <summary>
        /// The size of <see cref="eventProperties"/>.
        /// </summary>
        int eventPropertySize;
        /// <summary>
        /// Amount of time, from 0 to 300 seconds, to continue to consider the schedule trigger active when it becomes inactive (post-alarm).
        /// </summary>
        int postTrigger;
        /// <summary>
        /// Amount of time, from 0 to 30 seconds, to consider the schedule trigger active prior to when it becomes active (pre-alarm).
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
        /// Amount of time, from 1 to 300 seconds, to consider the schedule trigger active immediately after it becomes active (duration).
        /// </summary>
        int timeout;
        /// <summary>
        /// Days of the month, from 1 to 31, that the schedule trigger shall only be active on.
        /// </summary>
        int* recurMonthly;
        /// <summary>
        /// Days of the week, from 1 (Monday) to 7 (Sunday), that the schedule trigger shall only be active on.
        /// </summary>
        int* recurWeekly;
        /// <summary>
        /// Months of the year, from 1 (January) to 12 (December), that the schedule trigger shall only be active on.
        /// </summary>
        int* recurYearly;
        /// <summary>
        /// If set, the event only activates when it occurs with these <see cref="IVxEvent::properties"/>. Ignored if no event is set.
        /// </summary>
        VxKvObject** eventProperties;
        /// <summary>
        /// The framerate level to record at.
        /// </summary>
        VxRecordingFramerate::Value framerate;
        /// <summary>
        /// Interval at which the schedule trigger repeats.
        /// </summary>
        VxRecurrenceType::Value recurrence;
        /// <summary>
        /// If set, the schedule trigger only activates when this type of <see cref="VxSituationType::Value">VxSituationType</see>
        /// occurs. The schedule trigger event state shall be considered active until the event becomes inactive.
        /// </summary>
        VxSituationType::Value event;

    protected:
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
    };
}

#endif // IVxScheduleTrigger_h__
