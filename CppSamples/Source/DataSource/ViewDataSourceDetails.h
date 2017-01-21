#pragma once

#include "Plugin.h"

namespace CppSamples {
    namespace DataSource {

        /// <summary>
        /// This plugin sample print the details of a particular data source specified by user in the current system.
        /// </summary>
        class ViewDataSourceDetails : public CppSamples::Common::Plugin {
        public:
            ViewDataSourceDetails(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~ViewDataSourceDetails() { }

            /// <summary>
            /// Print the details of a particular data source specified by user in the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Get a collection of data source from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of data source.</returns>
            static VxSdk::VxCollection<VxSdk::IVxDataSource**> GetDataSources(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Print the given collection of data source to the screen.
            /// </summary>
            /// <param name="vxSystem">Collection of data source to be printed.</param>
            static void PrintDataSourceCollection(VxSdk::VxCollection<VxSdk::IVxDataSource**> collection);

            /// <summary>
            /// Print the details of the given data source to the screen.
            /// </summary>
            /// <param name="dataSource">The data source to be printed.</param>
            static void ShowDataSourceDetails(VxSdk::IVxDataSource* dataSource);
        };
    }
}
