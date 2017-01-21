#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Bookmarks {

        /// <summary>
        /// This plugin sample delete a selected bookmark from the current system.
        /// </summary>
        class DeleteBookmark : public CppSamples::Common::Plugin {
        public:
            DeleteBookmark(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~DeleteBookmark() { }

            /// <summary>
            /// Delete a selected bookmark from the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Get a collection of bookmarks from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of bookmarks.</returns>
            static VxSdk::VxCollection<VxSdk::IVxBookmark**> GetBookmarks(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Prints the given collection of bookmarks to the screen.
            /// </summary>
            /// <param name="bookmarkCollection">Collection of bookmarks.</param>
            static void PrintBookmarks(VxSdk::VxCollection<VxSdk::IVxBookmark**> bookmarkCollection);

            /// <summary>
            /// Select a bookmark from the given collection by user input.
            /// </summary>
            /// <param name="bookmarks">Collection of bookmark.</param>
            /// <returns>Index of the selected bookmark in the given collection.</returns>
            int SelectBookmarkIndex(VxSdk::VxCollection<VxSdk::IVxBookmark**> &bookmarks);
        };
    }
}
