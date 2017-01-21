#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Schedules {

        /// <summary>
        /// This plugin sample adds a schedule to the current system.
        /// </summary>
        class AddSchedule : public CppSamples::Common::Plugin {
        public:
            AddSchedule(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~AddSchedule() {}

            /// <summary>
            /// Adds a schedule to the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;
        };
    }
}
