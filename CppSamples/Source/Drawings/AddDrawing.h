#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Drawings {

        /// <summary>
        /// This plugin sample adds a drawing to the current system.
        /// </summary>
        class AddDrawing : public CppSamples::Common::Plugin {
        public:
            AddDrawing(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~AddDrawing() {}

            /// <summary>
            /// Adds a drawing to the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;
        };
    }
}
