// Declares the new quick report filter class.
#ifndef NewQuickReport_h__
#define NewQuickReport_h__

#include "VxSdk.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The NewQuickReport class represents a new quick report.
    /// </summary>
    public ref class NewQuickReport {
    public:

        /// <summary>
        /// Values that represent types of content for quick reports.
        /// </summary>
        enum class ReportContent {
            /// <summary>Snapshot of camera configuration.</summary>
            CameraConfig,
            /// <summary>Snapshot of all system device information.</summary>
            DeviceInfo,
            /// <summary>System event history.</summary>
            EventHistory,
            /// <summary>Device online/offline history.</summary>
            OnlineOffline,
            /// <summary>Snapshot of recorder configuration.</summary>
            RecorderConfig,
            /// <summary>Snapshot of recorder diagnostics.</summary>
            RecorderDiagnostics,
            /// <summary>User action history.</summary>
            UserActions,
            /// <summary>Snapshot of Vx cluster configuration.</summary>
            VxClusterConfig
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        NewQuickReport() {
            Clear();
        }

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~NewQuickReport() {
            this->!NewQuickReport();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !NewQuickReport(){
            Clear();
        }

        /// <summary>
        /// Gets or sets the DateTime at which to end the contents of the report.
        /// Defaults to the earliest content available.
        /// </summary>
        /// <value>The end time.</value>
        property System::DateTime EndTime {
        public:
            System::DateTime get() { return *_endTime; }
            void set(System::DateTime value) { _endTime = value; }
        }

        /// <summary>
        /// Gets or sets the DateTime at which to start the contents of the report.
        /// Defaults to the oldest content available.
        /// </summary>
        /// <value>The start time.</value>
        property System::DateTime StartTime {
        public:
            System::DateTime get() { return *_startTime; }
            void set(System::DateTime value) { _startTime = value; }
        }

        /// <summary>
        /// The report content types to include in the report.
        /// Reports will include all types if not set.
        /// </summary>
        /// <value>A <c>List</c> of content types to generate in the report.</value>
        property System::Collections::Generic::List<ReportContent>^ Contents {
        public:
            System::Collections::Generic::List<ReportContent>^ get() { return _reportContents; }
            void set(System::Collections::Generic::List<ReportContent>^ value) { _reportContents = value; }
        }

    internal:
        System::DateTime^ _endTime;
        System::DateTime^ _startTime;
        System::Collections::Generic::List<ReportContent>^ _reportContents;

        /// <summary>
        /// Finaliser.
        /// </summary>
        void Clear() {
            _endTime = gcnew System::DateTime();
            _startTime = gcnew System::DateTime();
            _reportContents = gcnew System::Collections::Generic::List<ReportContent>();
        }
    };
}
#endif // QuickReportFilter_h__