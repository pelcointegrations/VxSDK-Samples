#ifndef IVxSchedule_h__
#define IVxSchedule_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxScheduleTrigger.h"

namespace VxSdk {
    /// <summary>
    /// Represents a recording schedule. A schedule is a group of 0 or more resources associated with a set of time and/or event based
    /// schedule triggers that, when any are active, cause the scheduled action to be performed.
    /// </summary>
    struct IVxSchedule {
    public:
        /// <summary>
        /// Adds a schedule trigger to this schedule.
        /// </summary>
        /// <param name="newTrigger">The new schedule trigger to add.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddScheduleTrigger(VxNewScheduleTrigger& newTrigger) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this schedule from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the situation.</returns>
        virtual VxResult::Value DeleteSchedule() const = 0;
        /// <summary>
        /// Gets the data sources associated with this schedule.
        /// <para>Available filters: kAllTags, kCapturing, kId, kIp, kModifiedSince, kName, kNumber, kRecording, kState, kType, kUnassigned.</para>
        /// </summary>
        /// <param name="dataSourceCollection">The data sources associated with this schedule.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the schedule triggers associated with this schedule.
        /// </summary>
        /// <param name="triggerCollection">A <see cref="VxCollection"/> of the associated schedule triggers.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetScheduleTriggers(VxCollection<IVxScheduleTrigger**>& triggerCollection) const = 0;
        /// <summary>
        /// Associates a data source with this schedule.
        /// </summary>
        /// <param name="dataSource">The data source to associate the schedule with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDataSource& dataSource) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the action property.
        /// </summary>
        /// <param name="action">The new action value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAction(VxScheduleAction::Value action) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets whether the schedule applies to all data sources.
        /// </summary>
        /// <param name="useAllDataSources">True to use all data sources, otherwise false.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetUseAllDataSources(bool useAllDataSources) = 0;
        /// <summary>
        /// Removes a data source association from this schedule.
        /// </summary>
        /// <param name="dataSource">The data source to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDataSource& dataSource) const = 0;

    public:
        /// <summary>
        /// Indicates whether the schedule applies to all data sources.
        /// </summary>
        bool useAllDataSources;
        /// <summary>
        /// The unique identifier of the schedule.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the schedule.
        /// </summary>
        char name[64];
        /// <summary>
        /// The action performed when the schedule is active.
        /// </summary>
        VxScheduleAction::Value action;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->useAllDataSources = false;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->action = VxScheduleAction::kUnknown;
        }
    };
}

#endif // IVxSchedule_h__
