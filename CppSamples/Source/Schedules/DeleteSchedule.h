#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Schedules {

        /// <summary>
        /// This plugin sample delete a selected schedule from the current system.
        /// </summary>
        class DeleteSchedule : public CppSamples::Common::Plugin {
        public:
            DeleteSchedule(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~DeleteSchedule() { }

            /// <summary>
            /// Delete a selected schedule from the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Get a collection of schedules from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of schedules.</returns>
            static VxSdk::VxCollection<VxSdk::IVxSchedule**> GetSchedules(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Prints the given collection of schedules to the screen.
            /// </summary>
            /// <param name="scheduleCollection">Collection of schedules.</param>
            static void PrintSchedules(VxSdk::VxCollection<VxSdk::IVxSchedule**> scheduleCollection);

            /// <summary>
            /// Select a schedule from the given collection by user input.
            /// </summary>
            /// <param name="schedules">Collection of schedule.</param>
            /// <returns>Index of the selected schedule in the given collection.</returns>
            int SelectScheduleIndex(VxSdk::VxCollection<VxSdk::IVxSchedule**> &schedules);
        };
    }
}
