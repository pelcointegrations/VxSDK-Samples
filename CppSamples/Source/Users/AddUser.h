#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Users {

        /// <summary>
        /// This plugin sample adds a user to the current system.
        /// </summary>
        class AddUser : public CppSamples::Common::Plugin {
        public:
            AddUser(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~AddUser() {}

            /// <summary>
            /// Adds a user to the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;
        };
    }
}
