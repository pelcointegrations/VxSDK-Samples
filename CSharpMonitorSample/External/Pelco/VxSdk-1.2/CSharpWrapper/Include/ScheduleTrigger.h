// Declares the schedule trigger class.
#ifndef ScheduleTrigger_h__
#define ScheduleTrigger_h__

#include "VxSdk.h"
#include "Clip.h"

namespace CPPCli {

    /// <summary>
    /// The Situation class represents a schedule trigger. A schedule trigger is a time range and an optional
    /// event that together act as a trigger to activate a schedule and cause it to perform its configured action.
    /// </summary>
    public ref class ScheduleTrigger {
    public:

        /// <summary>
        /// Values that represent the interval at which triggers repeat.
        /// </summary>
        enum class RecurrenceTypes {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>Repeat daily.</summary>
            Daily,

            /// <summary>Repeat weekly.</summary>
            Weekly,

            /// <summary>Repeat monthly.</summary>
            Monthly,

            /// <summary>Repeat yearly.</summary>
            Yearly
        };

        /// <summary>
        /// Values that represent the available situation types for triggering a schedule.
        /// </summary>
        enum class SituationTypes  {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>Hardware or software alarm active (system/alarm_active).</summary>
            AlarmActive,

            /// <summary>Hardware or software alarm inactive (system/alarm_inactive).</summary>
            AlarmInactive,

            /// <summary>Motion anayltic alarm active (analytic/motion).</summary>
            Motion,

            /// <summary>Motion anayltic alarm inactive (analytic/no_motion).</summary>
            NoMotion
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxScheduleTrigger">The schedule trigger.</param>
        ScheduleTrigger(VxSdk::IVxScheduleTrigger* vxScheduleTrigger);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~ScheduleTrigger() {
            this->!ScheduleTrigger();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !ScheduleTrigger();

        /// <summary>
        /// Update this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Gets or sets the time at which the schedule trigger ends.
        /// </summary>
        /// <value>The time at which the schedule trigger ends.</value>
        property System::DateTime DailyEndTime {
        public:
            System::DateTime get() { return Utils::ConvertTimeCharToDateTime(_scheduleTrigger->dailyEndTime); }
            void set(System::DateTime value) { _scheduleTrigger->SetDailyEndTime(Utils::ConvertDateTimeToTimeCharNonConst(value)); }
        }

        /// <summary>
        /// Gets or sets the time at which the schedule trigger begins.
        /// </summary>
        /// <value>The time at which the schedule trigger begins.</value>
        property System::DateTime DailyStartTime {
        public:
            System::DateTime get() { return Utils::ConvertTimeCharToDateTime(_scheduleTrigger->dailyStartTime); }
            void set(System::DateTime value) { _scheduleTrigger->SetDailyStartTime(Utils::ConvertDateTimeToTimeCharNonConst(value)); }
        }

        /// <summary>
        /// Gets or sets the date at which the schedule trigger ends.
        /// </summary>
        /// <value>The date at which the schedule trigger ends.</value>
        property System::DateTime EndDate {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_scheduleTrigger->endDate); }
            void set(System::DateTime value) { _scheduleTrigger->SetEndDate(Utils::ConvertDateTimeToCharNonConst(value)); }
        }

        /// <summary>
        /// Gets or sets the event situation type. If set, the schedule trigger only activates when this type of
        /// <see cref="SituationTypes">SituationType</see> occurs. The schedule trigger event state shall be considered
        /// active until the event becomes inactive.
        /// </summary>
        /// <value>The event situation type.</value>
        property SituationTypes Event {
        public:
            SituationTypes get() { return SituationTypes(_scheduleTrigger->event); }
            void set(SituationTypes value) { _scheduleTrigger->SetEventType((VxSdk::VxSituationType::Value)value); }
        }

        /// <summary>
        /// Gets or sets the event properties that will activate the schedule.
        /// </summary>
        /// <value>A <c>List</c> containing the event properties.</value>
        property System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ EventProperties {
        public:
            System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ get() {
                System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ mList =
                    gcnew System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>();

                for (int i = 0; i < _scheduleTrigger->eventPropertySize; i++)
                {
                    auto eventProperty = _scheduleTrigger->eventProperties[i];
                    System::Collections::Generic::KeyValuePair<System::String^, System::String^> kvPair(gcnew System::String(eventProperty->key),
                        gcnew System::String(eventProperty->value));

                    mList->Add(kvPair);
                }

                return mList;
            }
            void set(System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ value) {
                int size = value->Count;
                VxSdk::VxKvObject *kvObj = new VxSdk::VxKvObject[size];
                for (int i = 0; i < size; i++) {
                    VxSdk::Utilities::StrCopySafe(kvObj[i].key, Utils::ConvertSysString(value[i].Key));
                    VxSdk::Utilities::StrCopySafe(kvObj[i].value, Utils::ConvertSysString(value[i].Value));
                }

                _scheduleTrigger->SetEventProperties(kvObj, size);
            }
        }

        /// <summary>
        /// Gets or sets the unique identifier of a device.  If set, the <see cref="Event"/> will activate the schedule trigger only
        /// when it occurs on this device.
        /// </summary>
        /// <value>The unique device identifier.</value>
        property System::String^ EventSource {
        public:
            System::String^ get() { return gcnew System::String(_scheduleTrigger->eventSourceDevice); }
            void set(System::String^ value) {
                char deviceId[64];
                strncpy_s(deviceId, Utils::ConvertSysStringNonConst(value), sizeof(deviceId));
                _scheduleTrigger->SetEventSourceDevice(deviceId);
            }
        }

        /// <summary>
        /// Gets or sets the recording framerate level.
        /// </summary>
        /// <value>The framerate level.</value>
        property Clip::RecordingFramerates Framerate {
        public:
            Clip::RecordingFramerates get() { return Clip::RecordingFramerates(_scheduleTrigger->framerate); }
            void set(Clip::RecordingFramerates value) { _scheduleTrigger->SetFramerate((VxSdk::VxRecordingFramerate::Value)value); }
        }

        /// <summary>
        /// Gets the unique identifier of the schedule trigger.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_scheduleTrigger->id); }
        }

        /// <summary>
        /// Gets or sets the amount of time, from 0 to 300 seconds, to continue to consider the schedule trigger active when it becomes
        /// inactive ("post alarm").
        /// </summary>
        /// <value>The post trigger time in seconds.</value>
        property int PostTrigger {
        public:
            int get() { return _scheduleTrigger->postTrigger; }
            void set(int value) { _scheduleTrigger->SetPostTrigger(value); }
        }

        /// <summary>
        /// Gets or sets the amount of time, from 0 to 30 seconds, to consider the schedule trigger active prior to when it becomes active
        /// ("pre alarm").
        /// </summary>
        /// <value>The pre trigger time in seconds.</value>
        property int PreTrigger {
        public:
            int get() { return _scheduleTrigger->preTrigger; }
            void set(int value) { _scheduleTrigger->SetPreTrigger(value); }
        }

        /// <summary>
        /// Gets or sets the interval at which the schedule trigger repeats.
        /// </summary>
        /// <value>The trigger interval.</value>
        property RecurrenceTypes RecurrenceType {
        public:
            RecurrenceTypes get() { return RecurrenceTypes(_scheduleTrigger->recurrence); }
            void set(RecurrenceTypes value) { _scheduleTrigger->SetRecurrence((VxSdk::VxRecurrenceType::Value)value); }
        }

        /// <summary>
        /// Gets or sets the days of the month, from 1 to 31, that the schedule trigger shall only be active on.
        /// </summary>
        /// <value>A <c>List</c> of the active days.</value>
        property System::Collections::Generic::List<int>^ RecurMonthly {
        public:
            System::Collections::Generic::List<int>^ get() {
                System::Collections::Generic::List<int>^ mlist = gcnew System::Collections::Generic::List<int>();

                for (int i = 0; i < _scheduleTrigger->recurMonthlySize; i++)
                    mlist->Add(_scheduleTrigger->recurMonthly[i]);

                return mlist;
            }
            void set(System::Collections::Generic::List<int>^ value) {
                int daysOfMonthSize = value->Count;
                int* daysOfMonth = new int[daysOfMonthSize];
                for (int i = 0; i < daysOfMonthSize; i++)
                    daysOfMonth[i] = value[i];

                _scheduleTrigger->SetMonthlyRecurrence(daysOfMonth, daysOfMonthSize);
            }
        }

        /// <summary>
        /// Gets or sets the days of the week, from 1 (Monday) to 7 (Sunday), that the schedule trigger shall only be active on.
        /// </summary>
        /// <value>A <c>List</c> of the active days.</value>
        property System::Collections::Generic::List<int>^ RecurWeekly {
        public:
            System::Collections::Generic::List<int>^ get() {
                System::Collections::Generic::List<int>^ mlist = gcnew System::Collections::Generic::List<int>();

                for (int i = 0; i < _scheduleTrigger->recurWeeklySize; i++)
                    mlist->Add(_scheduleTrigger->recurWeekly[i]);

                return mlist;
            }
            void set(System::Collections::Generic::List<int>^ value) {
                int daysOfWeekSize = value->Count;
                int* daysOfWeek = new int[daysOfWeekSize];
                for (int i = 0; i < daysOfWeekSize; i++)
                    daysOfWeek[i] = value[i];

                _scheduleTrigger->SetWeeklyRecurrence(daysOfWeek, daysOfWeekSize);
            }
        }

        /// <summary>
        /// Gets or sets the months of the year, from 1 (January) to 12 (December), that the schedule trigger shall only be active on.
        /// </summary>
        /// <value>A <c>List</c> of the active months.</value>
        property System::Collections::Generic::List<int>^ RecurYearly {
        public:
            System::Collections::Generic::List<int>^ get() {
                System::Collections::Generic::List<int>^ mlist = gcnew System::Collections::Generic::List<int>();

                for (int i = 0; i < _scheduleTrigger->recurYearlySize; i++)
                    mlist->Add(_scheduleTrigger->recurYearly[i]);

                return mlist;
            }
            void set(System::Collections::Generic::List<int>^ value) {
                int monthsOfYearSize = value->Count;
                int* monthsOfYear = new int[monthsOfYearSize];
                for (int i = 0; i < monthsOfYearSize; i++)
                    monthsOfYear[i] = value[i];

                _scheduleTrigger->SetYearlyRecurrence(monthsOfYear, monthsOfYearSize);
            }
        }

        /// <summary>
        /// Gets or sets the date at which the schedule trigger begins.
        /// </summary>
        /// <value>The date at which the schedule trigger begins.</value>
        property System::DateTime StartDate {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_scheduleTrigger->startDate); }
            void set(System::DateTime value) { _scheduleTrigger->SetStartDate(Utils::ConvertDateTimeToCharNonConst(value)); }
        }

        /// <summary>
        /// Gets or sets the amount of time, from 1 to 300 seconds, to consider the schedule trigger active immediately after it becomes
        /// active ("duration recording").
        /// </summary>
        /// <value>The timeout in seconds.</value>
        property int Timeout {
        public:
            int get() { return _scheduleTrigger->timeout; }
            void set(int value) { _scheduleTrigger->SetTimeout(value); }
        }

    internal:
        VxSdk::IVxScheduleTrigger* _scheduleTrigger;
    };
}
#endif // ScheduleTrigger_h__
