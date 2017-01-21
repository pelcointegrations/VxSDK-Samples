#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Exports {

        /// <summary>
        /// This plugin sample creates an export and adds to the current system.
        /// </summary>
        class CreateExport : public CppSamples::Common::Plugin {
        public:
            CreateExport(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~CreateExport() {}

            /// <summary>
            /// Creates an export and adds to the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Creates an export using the given system.
            /// </summary>
            /// <param name="dataSources">Collection of data source.</param>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            void CreateNewExportOption(VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources, VxSdk::IVxSystem* vxSystem) const;

            /// <summary>
            /// Get a collection of clips from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of clips.</returns>
            static VxSdk::VxCollection<VxSdk::IVxClip**> GetClips(VxSdk::IVxDataSource* dataSource);

            /// <summary>
            /// Get a collection of data source from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of data source.</returns>
            static VxSdk::VxCollection<VxSdk::IVxDataSource**> GetDataSources(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Get an export from the VideoExpert system with given name and ID.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <param name="expName">Name of the export.</param>
            /// <param name="id">ID of the export.</param>
            /// <returns>Export with given name and ID.</returns>
            VxSdk::IVxExport* GetExport(VxSdk::IVxSystem* vxSystem, const char* expName, const char* id) const;
        };
    }
}
