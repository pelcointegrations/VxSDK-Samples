#ifndef VxNewSchedule_h__
#define VxNewSchedule_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxNewScheduleTrigger.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new schedule to be created. A schedule is a group of 0 or more resources associated with a set of time
    /// and/or event based schedule triggers that, when any are active, cause the scheduled action to be performed.
    /// </summary>
    struct VxNewSchedule {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewSchedule"/> struct.
        /// </summary>
        VxNewSchedule() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewSchedule"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewSchedule(const VxNewSchedule& ref) {
            Utilities::StrCopySafe(this->id, ref.id);
            Utilities::StrCopySafe(this->name, ref.name);
            this->useAllDataSources = ref.useAllDataSources;
            this->scheduleTriggerSize = ref.scheduleTriggerSize;
            this->scheduleTriggers = ref.scheduleTriggers;
            this->action = ref.action;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewSchedule"/> class.
        /// </summary>
        ~VxNewSchedule() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->useAllDataSources = false;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->scheduleTriggerSize = 0;
            this->scheduleTriggers = nullptr;
            this->action = VxScheduleAction::kUnknown;
        }

    public:
        /// <summary>
        /// Indicates whether the schedule shall apply to all data sources regardless of what data sources are linked to the schedule.
        /// </summary>
        bool useAllDataSources;
        /// <summary>
        /// The unique identifier of the schedule. If not supplied, the system will create the identifier.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the schedule.
        /// </summary>
        char name[64];
        /// <summary>
        /// The size of <see cref="scheduleTriggers"/>.
        /// </summary>
        int scheduleTriggerSize;
        /// <summary>
        /// The <see cref="VxNewScheduleTrigger">VxNewScheduleTriggers</see> to create for the new schedule. Maximum of 16 triggers
        /// may be created.
        /// </summary>
        VxNewScheduleTrigger* scheduleTriggers;
        /// <summary>
        /// The action to perform when the schedule is active.
        /// </summary>
        VxScheduleAction::Value action;
    };
}

#endif // VxNewSchedule_h__
