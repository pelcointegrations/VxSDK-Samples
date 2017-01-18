// Declares the quick report class.
#ifndef QuickReport_h__
#define QuickReport_h__

#include "NewQuickReport.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The QuickReport class represents a quick system health report.
    /// </summary>
    public ref class QuickReport {
    public:

        /// <summary>
        /// Values that represent status of creating a quick report.
        /// </summary>
        enum class ReportCreationStatus {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,
            /// <summary>The report creation is in progress.</summary>
            InProgress,
            /// <summary>The report failed to be created.</summary>
            Failed,
            /// <summary>The report has successfully been created.</summary>
            Successful
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxQuickReport">The vx quick report.</param>
        QuickReport(VxSdk::IVxQuickReport* vxQuickReport);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~QuickReport() {
            this->!QuickReport();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !QuickReport();

        /// <summary>
        /// Gets the URI to the download location of the quick report.  The endpoint will only be available if the VideoXpert
        /// system has completed generating the report.
        /// </summary>
        /// <returns>The quick report endpoint, if available.</returns>
        property System::String^ QuickReportEndpoint {
        public:
            System::String^ get() { return _GetQuickReportEndpoint(); }
        }

        /// <summary>
        /// Gets the current status of generating the quick report.
        /// </summary>
        /// <value>The current quick report creation status.</value>
        property ReportCreationStatus Status {
        public:
            ReportCreationStatus get() { return _GetStatus(); }
        }

    internal:
        VxSdk::IVxQuickReport* _report;
        System::String^ _GetQuickReportEndpoint();
        ReportCreationStatus _GetStatus();
    };
}
#endif // QuickReport_h__
