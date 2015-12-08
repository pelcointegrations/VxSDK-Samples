#pragma once
#include "VxSdk.h"

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxExport
    /// </summary>
    class Export {
    public:

        /// <summary>
        /// Defines the format of export
        /// </summary>
        enum class ExportFormat {
            Unknown,
            MkvZip,
            Mp4
        };

        /// <summary>
        /// Defines the status of export
        /// </summary>
        enum class ExportStatus {
            Unknown,
            Exporting,
            Failed,
            Pending,
            Successful
        };

        /// <summary>
        /// Constructor - copies the VxSDK export pointer
        /// </summary>
        /// <param name="vxExport">The export pointer</param>
        Export(VxSdk::IVxExport* vxExport);
        
        /// <summary>
        /// Destructor
        /// </summary>
        ~Export();

        /// <summary>
        /// Returns the status of the export
        /// </summary>
        ExportStatus GetExportStatus() { return static_cast<ExportStatus>(_export->status); }

        /// <summary>
        /// Returns the format of the export
        /// </summary>

        ExportFormat GetExportFormat() { return static_cast<ExportFormat>(_export->format); }

        /// <summary>
        /// Returns the status of the export in string
        /// </summary>
        const char* GetExportStatusInString(bool shortStr) {
            ExportStatus expStatus = static_cast<ExportStatus>(_export->status);
            const char* expStatusInString = "U";
            if (expStatus == ExportStatus::Exporting) {
                if (shortStr) expStatusInString = "E";
                else expStatusInString = "Exporting";
            }
            else if (expStatus == ExportStatus::Successful) {
                if (shortStr) expStatusInString = "S";
                else expStatusInString = "Successful";
            }
            else if (expStatus == ExportStatus::Failed) {
                if (shortStr) expStatusInString = "F";
                else expStatusInString = "Failed";
            }
            else if (expStatus == ExportStatus::Pending) {
                if (shortStr) expStatusInString = "P";
                else expStatusInString = "Pending";
            }
            return expStatusInString;
        }

        /// <summary>
        /// Returns the export format in string
        /// </summary>
        const char* GetExportFormatInString() {
            ExportFormat expFmt = static_cast<ExportFormat>(_export->format);
            const char* expFormatInString = "Unknown";
            if (expFmt == ExportFormat::MkvZip) {
                expFormatInString = "MkvZip";
            }
            else if (expFmt == ExportFormat::Mp4) {
                expFormatInString = "Mp4";
            }
            return expFormatInString;
        }

        /// <summary>
        /// Returns seconds remaining value for this export
        /// </summary>
        int GetSecondsRemaining() { return _export->secondsRemaining; }

        /// <summary>
        /// Returns the percent complete value for this export
        /// </summary>
        float GetPercentComplete() { return _export->percentComplete; }

        /// <summary>
        /// Returns size of this export
        /// </summary>
        int GetFileSizeinKb() { return _export->fileSizeKb; }

        /// <summary>
        /// Returns name of this export
        /// </summary>
        const char* GetExportName() { return _export->name; }

        /// <summary>
        /// Returns id of this export
        /// </summary>
        const char* GetExportId() { return _export->id; }

        /// <summary>
        /// Returns the uri for downloading the export
        /// </summary>
        const char* GetExportDataUri() { return _export->dataUri; }

        /// <summary>
        /// Returns the VxSDK export pointer
        /// </summary>
        VxSdk::IVxExport* GetExportPtr() { return _export; }

    private:
        VxSdk::IVxExport* _export;
    };
}
