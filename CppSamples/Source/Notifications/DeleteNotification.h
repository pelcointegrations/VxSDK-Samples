#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Notifications {

        /// <summary>
        /// This plugin sample delete a selected notification from the current system.
        /// </summary>
        class DeleteNotification : public CppSamples::Common::Plugin {
        public:
            DeleteNotification(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~DeleteNotification() { }

            /// <summary>
            /// Delete a selected notification from the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Get a collection of notifications from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of notifications.</returns>
            static VxSdk::VxCollection<VxSdk::IVxNotification**> GetNotifications(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Prints the given collection of notifications to the screen.
            /// </summary>
            /// <param name="notificationCollection">Collection of notifications.</param>
            static void PrintNotifications(VxSdk::VxCollection<VxSdk::IVxNotification**> notificationCollection);

            /// <summary>
            /// Select a notification from the given collection by user input.
            /// </summary>
            /// <param name="notifications">Collection of notification.</param>
            /// <returns>Index of the selected notification in the given collection.</returns>
            int SelectNotificationIndex(VxSdk::VxCollection<VxSdk::IVxNotification**> &notifications);
        };
    }
}
