#pragma once

#include "Plugin.h"
#include "VxSdk.h"

namespace CppSamples {
    namespace Exports {

        /// <summary>
        /// This plugin sample downloads an export from the current system and saves as a file.
        /// </summary>
        class DownloadExport : public CppSamples::Common::Plugin {
        public:
            DownloadExport(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~DownloadExport() { }

            /// <summary>
            /// Downloads an export from the current system and saves as a file.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

            /// <summary>
            /// The user name used to log in to the VideoXpert system.
            /// </summary>
            std::string username;

            /// <summary>
            /// The password used to log in to the VideoXpert system.
            /// </summary>
            std::string password;

        protected:
            /// <summary>
            /// Prints the given collection of exports to the screen.
            /// </summary>
            /// <param name="exportCollection">Collection of exports.</param>
            static void DisplayExportDetailsOnScreen(VxSdk::VxCollection<VxSdk::IVxExport**> exportCollection);

            /// <summary>
            /// Downloads an export from the current system and saves as a file.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>True if downloaded successfully; False otherwise.</returns>
            bool Download(VxSdk::IVxSystem* vxSystem) const;

            /// <summary>
            /// Convert the value of export format to string.
            /// </summary>
            static std::string GetExportFormatInString(VxSdk::VxExportFormat::Value expFormat);

            /// <summary>
            /// Get a collection of exports from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of exports.</returns>
            static VxSdk::VxCollection<VxSdk::IVxExport**> GetExports(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Returns the status of the export in string
            /// </summary>
            /// <param name="expStatus">VxExportStatus::Value to be exported.</param>
            /// <param name="shortStr">Specifies whether short or long name.</param>
            /// <returns>The status of the export in string</returns>
            static std::string GetExportStatusInString(VxSdk::VxExportStatus::Value expStatus, bool shortStr);

            /// <summary>
            /// Callback method to get the download progress
            /// </summary>
            /// <param name="ptr">Custom data assigned to curl.</param>
            /// <param name="dltotal">Total bytes to be downloaded (not used).</param>
            /// <param name="dlnow">Number of bytes downloaded.</param>
            static int ProgressFunc(void* ptr, double dltotal, double dlnow);

            /// <summary>
            /// Print the details of given export.
            /// </summary>
            /// <param name="vxExport">Instance of IVxExport.</param>
            static void ShowExportDetails(VxSdk::IVxExport* vxExport);

            /// <summary>
            /// Callback method for writing export data to file
            /// </summary>
            /// <param name="ptr">stream data</param>
            /// <param name="size">size of the data</param>
            /// <param name="nmemb">count of the data</param>
            /// <param name="stream">file pointer to which data is being written</param>
            static size_t WriteData(void *ptr, size_t size, size_t nmemb, FILE *stream);
        };
    }
}
