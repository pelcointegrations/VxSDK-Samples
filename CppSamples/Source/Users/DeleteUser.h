#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Users {

        /// <summary>
        /// This plugin sample delete a selected user from the current system.
        /// </summary>
        class DeleteUser : public CppSamples::Common::Plugin {
        public:
            DeleteUser(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~DeleteUser() { }

            /// <summary>
            /// Delete a selected user from the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Get a collection of users from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of users.</returns>
            static VxSdk::VxCollection<VxSdk::IVxUser**> GetUsers(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Prints the given collection of users to the screen.
            /// </summary>
            /// <param name="userCollection">Collection of users.</param>
            static void PrintUsers(VxSdk::VxCollection<VxSdk::IVxUser**> userCollection);

            /// <summary>
            /// Select a user from the given collection by user input.
            /// </summary>
            /// <param name="users">Collection of user.</param>
            /// <returns>Index of the selected user in the given collection.</returns>
            int SelectUserIndex(VxSdk::VxCollection<VxSdk::IVxUser**> &users);
        };
    }
}
