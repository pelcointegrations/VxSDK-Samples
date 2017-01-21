#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Tags {

        /// <summary>
        /// This plugin sample print all tags available in the current system.
        /// </summary>
        class ViewAllTags : public CppSamples::Common::Plugin {
        public:
            ViewAllTags(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~ViewAllTags() { }

            /// <summary>
            /// Print all tags available in the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Get a collection of tags from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of tags.</returns>
            static VxSdk::VxCollection<VxSdk::IVxTag**> GetTags(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Prints the given collection of tags to the screen.
            /// </summary>
            /// <param name="tagCollection">Collection of tags.</param>
            static void PrintTags(VxSdk::VxCollection<VxSdk::IVxTag**> tagCollection);
        };
    }
}
