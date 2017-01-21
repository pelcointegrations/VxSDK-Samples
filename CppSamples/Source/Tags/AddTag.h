#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Tags {

        /// <summary>
        /// This plugin sample adds a tag to the current system.
        /// </summary>
        class AddTag : public CppSamples::Common::Plugin {
        public:
            AddTag(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~AddTag() {}

            /// <summary>
            /// Adds a tag to the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;
        };
    }
}
