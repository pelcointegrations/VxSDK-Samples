#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace DataSource {

        /// <summary>
        /// This plugin sample print all available data sources in the current system page by page.
        /// </summary>
        class ViewDataSourceByPage : public CppSamples::Common::Plugin {
        public:
            ViewDataSourceByPage(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~ViewDataSourceByPage() { }

            /// <summary>
            /// Print all available data sources in the current system page by page.
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
            /// Print the details of the given data source to the screen.
            /// </summary>
            /// <param name="number">Number of data source.</param>
            /// <param name="dataSource">The data source to be printed.</param>
            static void PrintDataSource(int number, VxSdk::IVxDataSource* dataSource);

            /// <summary>
            /// Print the given collection of data source to the screen.
            /// </summary>
            /// <param name="vxSystem">Collection of data source to be printed.</param>
            static void PrintDataSourceCollection(VxSdk::VxCollection<VxSdk::IVxDataSource**> collection);
        };
    }
}
