#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Tags {

        /// <summary>
        /// This plugin sample delete a selected tag from the current system.
        /// </summary>
        class DeleteTag : public CppSamples::Common::Plugin {
        public:
            DeleteTag(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~DeleteTag() { }

            /// <summary>
            /// Delete a selected tag from the current system.
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

            /// <summary>
            /// Select a tag from the given collection by user input.
            /// </summary>
            /// <param name="tags">Collection of tag.</param>
            /// <returns>Index of the selected tag in the given collection.</returns>
            int SelectTagIndex(VxSdk::VxCollection<VxSdk::IVxTag**> &tags);
        };
    }
}
