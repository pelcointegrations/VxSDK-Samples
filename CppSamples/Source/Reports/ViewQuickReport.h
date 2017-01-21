#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Reports {

        /// <summary>
        /// This plugin sample print a quick report on screen.
        /// </summary>
        class ViewQuickReport : public CppSamples::Common::Plugin {
        public:
            ViewQuickReport(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~ViewQuickReport() { }

            /// <summary>
            /// Print a quick report on screen.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        private:
            /// <summary>
            /// Read the end point of the report.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <param name="vxQuickReportFilter">Instance of VxNewQuickReport.</param>
            /// <returns>End point of the report.</returns>
            std::string ReadReportUrl(VxSdk::IVxSystem* vxSystem, VxSdk::VxNewQuickReport vxQuickReportFilter);

            /// <summary>
            /// Read a web page content from the given URL.
            /// </summary>
            /// <param name="reportUrl">URL of report.</param>
            /// <returns>Report content.</returns>
            std::string ReadWebPageConent(std::string reportUrl);

            /// <summary>
            /// This callback function gets called by libcurl as soon as there is data received that needs to be saved.
            /// It will append the data from the page to given variable at CURLOPT_WRITEDATA.
            /// </summary>
            /// <param name="pageContent">This pointer points to the delivered data.</param>
            /// <param name="sz">The size of that data is sz multiplied with nmemb.</param>
            /// <param name="nmemb">The size of that data is sz multiplied with nmemb.</param>
            /// <param name="reportContentPtr">Pointer to the variable given at CURLOPT_WRITEDATA.</param>
            /// <returns>The size of the string.</returns>
            static size_t AppendDataCurlCallback(void *pageContent, size_t sz, size_t nmemb, void *reportContentPtr);
        };
    }
}
