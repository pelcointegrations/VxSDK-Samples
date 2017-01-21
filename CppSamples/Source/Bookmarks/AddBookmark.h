#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Bookmarks {

        /// <summary>
        /// This plugin sample adds a bookmark to the current system.
        /// </summary>
        class AddBookmark :
            public CppSamples::Common::Plugin
        {
        public:
            AddBookmark(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~AddBookmark() {}

            /// <summary>
            /// Adds a bookmark to the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        private:
            /// <summary>
            /// Add a new bookmark to server.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            void AddNew(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Get a collection of data source from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of data source.</returns>
            VxSdk::VxCollection<VxSdk::IVxDataSource**> GetDataSources(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Select a data source from the given collection by user input.
            /// </summary>
            /// <param name="dataSources">Collection of data source.</param>
            /// <returns>Index of the selected data source in the given collection.</returns>
            int SelectDataSourceIndex(VxSdk::VxCollection<VxSdk::IVxDataSource**> &dataSources);
        };
    }
}
