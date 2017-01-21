#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Schedules {

        /// <summary>
        /// This plugin sample creates a trigger and add it to a selected schedule in the current system.
        /// </summary>
        class AddTriggerToSchedule : public CppSamples::Common::Plugin {
        public:
            AddTriggerToSchedule(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~AddTriggerToSchedule() {}

            /// <summary>
            /// Creates a trigger and add it to a selected schedule in the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        private:
            /// <summary>
            /// Get a collection of schedules from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of schedules.</returns>
            VxSdk::VxCollection<VxSdk::IVxSchedule**> GetSchedules(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Reads a time from user input
            /// </summary>
            /// <param name="message">Message to be printed while before reading time</param>
            static std::string ReadTime(std::string message);

            /// <summary>
            /// Reads a date from user input in DD-MM-YY format.
            /// </summary>
            /// <param name="message">Message to be printed while before reading date</param>
            static std::string ReadDate(std::string message);
        };
    }
}
