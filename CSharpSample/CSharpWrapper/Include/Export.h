// Declares the export class.
#ifndef Export_h__
#define Export_h__

#include "VxSdk.h"
#include "ExportClip.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The Export class represents an exported data set that is archived within the system.
    /// </summary>
    public ref class Export {
    public:

        /// <summary>
        /// Values that represent the format of exported data.
        /// </summary>
        enum class Formats {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>MKV file(s) contained withing a zip file.</summary>
            MkvZip,

            /// <summary>An MP4 file.</summary>
            Mp4
        };

        /// <summary>
        /// Values that represent status of an export.
        /// </summary>
        enum class States {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>The export is in progress.</summary>
            Exporting,

            /// <summary>The export has failed.</summary>
            Failed,

            /// <summary>The export is queued to start.</summary>
            Pending,

            /// <summary>The export has completed successfully.</summary>
            Successful
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxExport">The vx export.</param>
        Export(VxSdk::IVxExport* vxExport);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Export() {
            this->!Export();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Export();

        /// <summary>
        /// Gets the date and time at which the triggered export completed the export operation.
        /// </summary>
        /// <value>A default <c>DateTime</c> if it fails, else the <c>DateTime</c> when the export completed.</value>
        property System::DateTime Completed {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_export->completedTime); }
        }

        /// <summary>
        /// Gets the clips associated with this export.
        /// </summary>
        /// <value>The <c>List</c> of clips contained in the export.</value>
        property System::Collections::Generic::List<ExportClip^>^ ExportClips {
        public:
            System::Collections::Generic::List<ExportClip^>^ get() { return _GetClips(); }
        }

        /// <summary>
        /// Gets the format of the export data.
        /// </summary>
        /// <value>The export <see cref="Formats">Format</see>.</value>
        property Formats Format {
        public:
            Formats get() { return (Formats)_export->format; }
        }

        /// <summary>
        /// Gets the unique export identifier.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_export->id); }
        }

        /// <summary>
        /// Gets the date and time at which the Export was requested.
        /// </summary>
        /// <value>The <c>DateTime</c> when the export was initiated.</value>
        property System::DateTime Initiated {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_export->initiatedTime); }
        }

        /// <summary>
        /// Gets the friendly name of the export.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_export->name); }
        }

        /// <summary>
        /// Gets the name of the user that has created this export, if any.
        /// </summary>
        /// <value>The owner name.</value>
        property System::String^ Owner {
        public:
            System::String^ get() { return gcnew System::String(_export->owner); }
        }

        /// <summary>
        /// Gets a value from 0 to 100. This specifies how close the export is to
        /// completion. 0 indicates that the export has not been triggered; 100 indicates
        /// that the export is complete.
        /// </summary>
        /// <value>The percent complete.</value>
        property float PercentComplete {
        public:
            float get() { return _export->percentComplete; }
        }

        /// <summary>
        /// Gets a value indicating whether the export data is signed and encrypted.
        /// </summary>
        /// <value><c>true</c> if this export is protected, <c>false</c> if not.</value>
        property bool IsProtected {
        public:
            bool get() { return _export->isProtected; }
        }

        /// <summary>
        /// Gets the estimated time remaining, in seconds, until the export is 100
        /// percent complete.  If the export is complete this value will be 0.
        /// </summary>
        /// <value>The seconds remaining.</value>
        property int SecondsRemaining {
        public:
            int get() { return _export->secondsRemaining; }
        }

        /// <summary>
        /// Gets the file size of the exported data in kilobytes (kB).
        /// </summary>
        /// <value>The file size.</value>
        property int FileSizeKb {
        public:
            int get() { return _export->fileSizeKb; }
        }

        /// <summary>
        /// Gets the current status of the export.
        /// </summary>
        /// <value>The current export status.</value>
        property States Status {
        public:
            States get() { return (States)_export->status; }
        }

        /// <summary>
        /// Gets the URI to the exported data.  It will only be present if
        /// the exported data is completed and available for download.
        /// </summary>
        /// <value>The data URI.</value>
        property System::String^ DataUri {
        public:
            System::String^ get() { return gcnew System::String(_export->dataUri); }
        }

    internal:
        VxSdk::IVxExport* _export;
        System::Collections::Generic::List<ExportClip^>^ _GetClips();
    };
}
#endif // Export_h__
