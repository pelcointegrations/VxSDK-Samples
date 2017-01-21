#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Drawings {

        /// <summary>
        /// This plugin sample delete a selected drawing from the current system.
        /// </summary>
        class DeleteDrawing : public CppSamples::Common::Plugin {
        public:
            DeleteDrawing(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~DeleteDrawing() { }

            /// <summary>
            /// Delete a selected drawing from the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Get a collection of drawings from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of drawings.</returns>
            static VxSdk::VxCollection<VxSdk::IVxDrawing**> GetDrawings(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Prints the given collection of drawings to the screen.
            /// </summary>
            /// <param name="drawingCollection">Collection of drawings.</param>
            static void PrintDrawings(VxSdk::VxCollection<VxSdk::IVxDrawing**> drawingCollection);

            /// <summary>
            /// Select a drawing from the given collection by user input.
            /// </summary>
            /// <param name="drawings">Collection of drawing.</param>
            /// <returns>Index of the selected drawing in the given collection.</returns>
            int SelectDrawingIndex(VxSdk::VxCollection<VxSdk::IVxDrawing**> &drawings);
        };
    }
}
