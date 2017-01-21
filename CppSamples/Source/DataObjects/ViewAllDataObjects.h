#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace DataObjects {

        /// <summary>
        /// This plugin sample print all dataObjects available in the current system.
        /// </summary>
        class ViewAllDataObjects : public CppSamples::Common::Plugin {
        public:
            ViewAllDataObjects(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~ViewAllDataObjects() { }

            /// <summary>
            /// Print all dataObjects available in the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Get a collection of dataObjects from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of dataObjects.</returns>
            static VxSdk::VxCollection<VxSdk::IVxDataObject**> GetDataObjects(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Prints the given collection of dataObjects to the screen.
            /// </summary>
            /// <param name="dataObjectCollection">Collection of dataObjects.</param>
            static void PrintDataObjects(VxSdk::VxCollection<VxSdk::IVxDataObject**> dataObjectCollection);
        };
    }
}
