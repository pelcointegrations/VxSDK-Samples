#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Notifications {

        /// <summary>
        /// This plugin sample print all notifications available in the current system.
        /// </summary>
        class ViewAllNotifications : public CppSamples::Common::Plugin {
        public:
            ViewAllNotifications(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~ViewAllNotifications() { }

            /// <summary>
            /// Print all notifications available in the current system.
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
        };
    }
}
