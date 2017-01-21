#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Roles {

        /// <summary>
        /// This plugin sample delete a selected role from the current system.
        /// </summary>
        class DeleteRole : public CppSamples::Common::Plugin {
        public:
            DeleteRole(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~DeleteRole() { }

            /// <summary>
            /// Delete a selected role from the current system.
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

            /// <summary>
            /// Select a role from the given collection by user input.
            /// </summary>
            /// <param name="roles">Collection of role.</param>
            /// <returns>Index of the selected role in the given collection.</returns>
            int SelectRoleIndex(VxSdk::VxCollection<VxSdk::IVxRole**> &roles);
        };
    }
}
