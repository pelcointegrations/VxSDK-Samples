#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace DataObjects {

        /// <summary>
        /// This plugin sample adds a dataObject to the current system.
        /// </summary>
        class AddDataObject : public CppSamples::Common::Plugin {
        public:
            AddDataObject(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~AddDataObject() {}

            /// <summary>
            /// Adds a dataObject to the current system.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;
        };
    }
}
