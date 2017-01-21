#pragma once

#include "Plugin.h"
#include "VxSdk.h"
#include <list>
#include <vector>

namespace CppSamples {
    namespace Notifications {

        /// <summary>
        /// This plugin sample adds a notification to the current system.
        /// </summary>
        class AddNotification : public CppSamples::Common::Plugin {
        public:
            AddNotification(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~AddNotification() {}

            /// <summary>
            /// Adds a notification to the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        private:
            /// <summary>
            /// Get a list of selected roles from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A list of selected roles.</returns>
            std::vector<std::string>  GetSelectedRoles(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Get a collection of roles from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of roles.</returns>
            VxSdk::VxCollection<VxSdk::IVxRole**> GetRoles(VxSdk::IVxSystem* vxSystem);
        };
    }
}
