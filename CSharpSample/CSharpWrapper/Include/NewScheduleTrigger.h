// Declares the new schedule trigger class.
#ifndef NewScheduleTrigger_h__
#define NewScheduleTrigger_h__

#include "Utils.h"
#include "Clip.h"
#include "ScheduleTrigger.h"

namespace CPPCli {

    /// <summary>
    /// The NewScheduleTrigger class represents a new schedule trigger configuration that specifies a time
    /// range and an optional event that together act as a trigger to activate a schedule.
    /// </summary>
    public ref class NewScheduleTrigger {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewScheduleTrigger() {
            _newScheduleTrigger = new VxSdk::VxNewScheduleTrigger();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewScheduleTrigger">The new schedule trigger.</param>
        NewScheduleTrigger(VxSdk::VxNewScheduleTrigger* vxNewScheduleTrigger) {
            _newScheduleTrigger = vxNewScheduleTrigger;
        }

        /// <summary>
        /// Gets or sets the time at which the schedule trigger ends. A schedule trigger is active each day, only from
        /// <see cref="DailyStartTime"/> to <see cref="DailyEndTime"/>. If the <see cref="DailyEndTime"/> is less than the
        /// <see cref="DailyStartTime"/>, it is to be considered as occurring later (the following day). If these values
        /// are equal, the schedule trigger is not restricted by time.
        /// </summary>
        /// <value>The daily end time.</value>
        property System::DateTime DailyEndTime {
        public:
            System::DateTime get() { return Utils::ConvertTimeCharToDateTime(_newScheduleTrigger->dailyEndTime); }
            void set(System::DateTime value) { VxSdk::Utilities::StrCopySafe(_newScheduleTrigger->dailyEndTime, Utils::ConvertDateTimeToTimeChar(value)); }
        }

        /// <summary>
        /// Gets or sets the time at which the schedule trigger begins. A schedule trigger is active each day, only from
        /// <see cref="DailyStartTime"/> to <see cref="DailyEndTime"/>. If these values are equal, the schedule trigger is
        /// not restricted by time.
        /// </summary>
        /// <value>The daily start time.</value>
        property System::DateTime DailyStartTime {
        public:
            System::DateTime get() { return Utils::ConvertTimeCharToDateTime(_newScheduleTrigger->dailyStartTime); }
            void set(System::DateTime value) { VxSdk::Utilities::StrCopySafe(_newScheduleTrigger->dailyStartTime, Utils::ConvertDateTimeToTimeChar(value)); }
        }

        /// <summary>
        /// Gets or sets the date at which the schedule trigger ends. A schedule trigger is active, only from <see cref="StartDate"/>
        /// to <see cref="EndDate"/>. If the <see cref="EndDate"/> is prior or equal to the <see cref="StartDate"/>, the
        /// schedule trigger is not limited by date.
        /// </summary>
        /// <value>The end date.</value>
        property System::DateTime EndDate {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_newScheduleTrigger->endDate); }
            void set(System::DateTime value) { VxSdk::Utilities::StrCopySafe(_newScheduleTrigger->endDate, Utils::ConvertDateTimeToChar(value)); }
        }

        /// <summary>
        /// Gets or sets the event situation type. If set, the schedule trigger only activates when this type of
        /// <see cref="ScheduleTrigger::SituationTypes">SituationType</see> occurs. The schedule trigger event state shall be considered
        /// active until the event becomes inactive.
        /// </summary>
        /// <value>The event situation type.</value>
        property ScheduleTrigger::SituationTypes Event {
        public:
            ScheduleTrigger::SituationTypes get() { return ScheduleTrigger::SituationTypes(_newScheduleTrigger->event); }
            void set(ScheduleTrigger::SituationTypes value) { _newScheduleTrigger->event = VxSdk::VxSituationType::Value(value); }
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

                for (int i = 0; i < _newScheduleTrigger->eventPropertySize; i++)
                {
                    System::Collections::Generic::KeyValuePair<System::String^, System::String^> kvPair(
                        gcnew System::String(_newScheduleTrigger->eventProperties[i].key),
                        gcnew System::String(_newScheduleTrigger->eventProperties[i].value));

                    mList->Add(kvPair);
                }

                return mList;
            }
            void set(System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ value) {
                _newScheduleTrigger->eventPropertySize = value->Count;
                VxSdk::VxKvObject *kvObj = new VxSdk::VxKvObject[_newScheduleTrigger->eventPropertySize];
                _newScheduleTrigger->eventProperties = kvObj;

                for (int i = 0; i < _newScheduleTrigger->eventPropertySize; i++)
                {
                    strncpy_s(_newScheduleTrigger->eventProperties[i].key, Utils::ConvertSysString(value[i].Key),
                        sizeof(_newScheduleTrigger->eventProperties[i].key));
                    strncpy_s(_newScheduleTrigger->eventProperties[i].value, Utils::ConvertSysString(value[i].Value),
                        sizeof(_newScheduleTrigger->eventProperties[i].value));
                }
            }
        }

        /// <summary>
        /// Gets or sets the unique identifier of a device.  If set, the <see cref="Event"/> will activate the schedule trigger only
        /// when it occurs on this device.
        /// </summary>
        /// <value>The unique device identifier.</value>
        property System::String^ EventSource {
        public:
            System::String^ get() { return gcnew System::String(_newScheduleTrigger->eventSourceDevice); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newScheduleTrigger->eventSourceDevice, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the recording framerate level.
        /// </summary>
        /// <value>The framerate level.</value>
        property Clip::RecordingFramerates Framerate {
        public:
            Clip::RecordingFramerates get() { return Clip::RecordingFramerates(_newScheduleTrigger->framerate); }
            void set(Clip::RecordingFramerates value) { _newScheduleTrigger->framerate = (VxSdk::VxRecordingFramerate::Value)value; }
        }

        /// <summary>
        /// Gets or sets the unique identifier of the schedule trigger.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_newScheduleTrigger->id); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newScheduleTrigger->id, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the amount of time, from 0 to 300 seconds, to continue to consider the schedule trigger active when it becomes
        /// inactive ("post alarm").
        /// </summary>
        /// <value>The post trigger time in seconds.</value>
        property int PostTrigger {
        public:
            int get() { return _newScheduleTrigger->postTrigger; }
            void set(int value) { _newScheduleTrigger->postTrigger = value; }
        }

        /// <summary>
        /// Gets or sets the amount of time, from 0 to 30 seconds, to consider the schedule trigger active prior to when it becomes active
        /// ("pre alarm").
        /// </summary>
        /// <value>The pre trigger time in seconds.</value>
        property int PreTrigger {
        public:
            int get() { return _newScheduleTrigger->preTrigger; }
            void set(int value) { _newScheduleTrigger->preTrigger = value; }
        }

        /// <summary>
        /// Gets or sets the interval at which the schedule trigger repeats.
        /// </summary>
        /// <value>The trigger interval.</value>
        property ScheduleTrigger::RecurrenceTypes RecurrenceType {
        public:
            ScheduleTrigger::RecurrenceTypes get() { return ScheduleTrigger::RecurrenceTypes(_newScheduleTrigger->recurrence); }
            void set(ScheduleTrigger::RecurrenceTypes value) { _newScheduleTrigger->recurrence = (VxSdk::VxRecurrenceType::Value)value; }
        }

        /// <summary>
        /// Gets or sets the days of the month, from 1 to 31, that the schedule trigger shall only be active on.
        /// </summary>
        /// <value>A <c>List</c> of the active days.</value>
        property System::Collections::Generic::List<int>^ RecurMonthly {
        public:
            System::Collections::Generic::List<int>^ get() {
                System::Collections::Generic::List<int>^ mlist = gcnew System::Collections::Generic::List<int>();

                for (int i = 0; i < _newScheduleTrigger->recurMonthlySize; i++)
                    mlist->Add(_newScheduleTrigger->recurMonthly[i]);

                return mlist;
            }
            void set(System::Collections::Generic::List<int>^ value) {
                _newScheduleTrigger->recurMonthlySize = value->Count;
                int *intervals = new int[_newScheduleTrigger->recurMonthlySize];

                for (int i = 0; i < _newScheduleTrigger->recurMonthlySize; i++)
                    intervals[i] = value[i];

                _newScheduleTrigger->recurMonthly = intervals;
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

                for (int i = 0; i < _newScheduleTrigger->recurWeeklySize; i++)
                    mlist->Add(_newScheduleTrigger->recurWeekly[i]);

                return mlist;
            }
            void set(System::Collections::Generic::List<int>^ value) {
                _newScheduleTrigger->recurWeeklySize = value->Count;
                int *intervals = new int[_newScheduleTrigger->recurWeeklySize];

                for (int i = 0; i < _newScheduleTrigger->recurWeeklySize; i++)
                    intervals[i] = value[i];

                _newScheduleTrigger->recurWeekly = intervals;
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

                for (int i = 0; i < _newScheduleTrigger->recurYearlySize; i++)
                    mlist->Add(_newScheduleTrigger->recurYearly[i]);

                return mlist;
            }
            void set(System::Collections::Generic::List<int>^ value) {
                _newScheduleTrigger->recurYearlySize = value->Count;
                int *intervals = new int[_newScheduleTrigger->recurYearlySize];

                for (int i = 0; i < _newScheduleTrigger->recurYearlySize; i++)
                    intervals[i] = value[i];

                _newScheduleTrigger->recurYearly = intervals;
            }
        }

        /// <summary>
        /// Gets or sets the date at which the schedule trigger begins. A schedule trigger is active, only from <see cref="StartDate"/>
        /// to <see cref="EndDate"/>. If the <see cref="EndDate"/> is prior or equal to the <see cref="StartDate"/>, the
        /// schedule trigger is not limited by date.
        /// </summary>
        /// <value>The start date.</value>
        property System::DateTime StartDate {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_newScheduleTrigger->startDate); }
            void set(System::DateTime value) { VxSdk::Utilities::StrCopySafe(_newScheduleTrigger->startDate, Utils::ConvertDateTimeToChar(value)); }
        }

        /// <summary>
        /// Gets or sets the amount of time, from 1 to 300 seconds, to consider the schedule trigger active immediately after it becomes
        /// active ("duration recording").
        /// </summary>
        /// <value>The timeout in seconds.</value>
        property int Timeout {
        public:
            int get() { return _newScheduleTrigger->timeout; }
            void set(int value) { _newScheduleTrigger->timeout = value; }
        }

    internal:
        VxSdk::VxNewScheduleTrigger* _newScheduleTrigger;
    };
}
#endif // NewScheduleTrigger_h__
