#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Roles {

        /// <summary>
        /// This plugin sample print all roles available in the current system.
        /// </summary>
        class ViewAllRoles : public CppSamples::Common::Plugin {
        public:
            ViewAllRoles(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~ViewAllRoles() { }

            /// <summary>
            /// Print all roles available in the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Get a collection of roles from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of roles.</returns>
            static VxSdk::VxCollection<VxSdk::IVxRole**> GetRoles(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Prints the given collection of roles to the screen.
            /// </summary>
            /// <param name="roleCollection">Collection of roles.</param>
            static void PrintRoles(VxSdk::VxCollection<VxSdk::IVxRole**> roleCollection);
        };
    }
}
