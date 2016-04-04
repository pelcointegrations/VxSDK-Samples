// Declares the new schedule class.
#ifndef NewSchedule_h__
#define NewSchedule_h__

#include "Schedule.h"
#include "NewScheduleTrigger.h"

namespace CPPCli {

    /// <summary>
    /// The NewSchedule class represents a new schedule.
    /// </summary>
    public ref class NewSchedule {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewSchedule() {
            _newSchedule = new VxSdk::VxNewSchedule();
            _scheduleTriggers = gcnew System::Collections::Generic::List<CPPCli::NewScheduleTrigger^>();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewSchedule">The new schedule.</param>
        NewSchedule(VxSdk::VxNewSchedule* vxNewSchedule);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~NewSchedule() {
            this->!NewSchedule();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !NewSchedule();

        /// <summary>
        /// Gets the triggers that shall be included in this schedule.
        /// </summary>
        /// <value>A <c>List</c> of triggers included in the schedule.</value>
        property System::Collections::Generic::List<NewScheduleTrigger^>^ ScheduleTriggers {
        public:
            System::Collections::Generic::List<NewScheduleTrigger^>^ get() { return _scheduleTriggers; }
        }

        /// <summary>
        /// Gets or sets the event action to use for the schedule.
        /// </summary>
        /// <value>The event <see cref="Schedule::Actions">Action</see>.</value>
        property Schedule::Actions Action {
        public:
            Schedule::Actions get() { return (Schedule::Actions)_newSchedule->action; }
            void set(Schedule::Actions value) { _newSchedule->action = (VxSdk::VxScheduleAction::Value)value; }
        }

        /// <summary>
        /// Gets or sets the friendly name of the schedule.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_newSchedule->name); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newSchedule->name, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the unique schedule identifier.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_newSchedule->id); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newSchedule->id, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets whether the schedule will apply to all data sources regardless of what data sources are linked to
        /// the schedule.
        /// </summary>
        /// <value><c>true</c> if the schedule will apply to all data sources, <c>false</c> if not.</value>
        property bool UseAllDataSources {
        public:
            bool get() { return _newSchedule->useAllDataSources; }
            void set(bool value) { _newSchedule->useAllDataSources = value; }
        }

    internal:
        VxSdk::VxNewSchedule* _newSchedule;
        System::Collections::Generic::List<NewScheduleTrigger^>^ _scheduleTriggers;
    };
}
#endif // NewSchedule_h__
