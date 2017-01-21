#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Roles {

        /// <summary>
        /// This plugin sample adds a role to the current system.
        /// </summary>
        class AddRole : public CppSamples::Common::Plugin {
        public:
            AddRole(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~AddRole() {}

            /// <summary>
            /// Adds a role to the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;
        };
    }
}
