#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Schedules {

        /// <summary>
        /// This plugin sample print all schedules available in the current system.
        /// </summary>
        class ViewAllSchedules : public CppSamples::Common::Plugin {
        public:
            ViewAllSchedules(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~ViewAllSchedules() { }

            /// <summary>
            /// Print all schedules available in the current system.
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
        };
    }
}
