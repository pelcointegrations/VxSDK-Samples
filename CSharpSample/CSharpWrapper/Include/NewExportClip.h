// Declares the new export clip class.
#ifndef NewExportClip_h__
#define NewExportClip_h__

#include "Utils.h"
#include "Export.h"

namespace CPPCli {

    /// <summary>
    /// The NewExportClip class represents a new export clip.
    /// </summary>
    public ref class NewExportClip {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewExportClip() {
            _newExportClip = new VxSdk::VxNewExportClip();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewExportClip">The new export clip.</param>
        NewExportClip(VxSdk::VxNewExportClip* vxNewExportClip) {
            _newExportClip = vxNewExportClip;
        }

        /// <summary>
        /// Gets or sets the specific data encoding to export (quality, framerate, and resolution). This can be obtained from the desired data interface of
        /// the clip. If not specified, the server shall select the data encoding.
        /// </summary>
        /// <value>The specific data encoding to export.</value>
        property System::String^ DataEncodingId {
        public:
            System::String^ get() { return gcnew System::String(_newExportClip->dataEncodingId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newExportClip->dataEncodingId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the unique identifier of the data source.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ DataSourceId {
        public:
            System::String^ get() { return gcnew System::String(_newExportClip->dataSourceId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newExportClip->dataSourceId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the time at which the clip ends.
        /// </summary>
        /// <value>The end time.</value>
        property System::DateTime EndTime {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_newExportClip->endTime); }
            void set(System::DateTime value) { VxSdk::Utilities::StrCopySafe(_newExportClip->endTime, Utils::ConvertDateTimeToChar(value)); }
        }

        /// <summary>
        /// Gets or sets the time at which the clip begins.
        /// </summary>
        /// <value>The start time.</value>
        property System::DateTime StartTime {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_newExportClip->startTime); }
            void set(System::DateTime value) { VxSdk::Utilities::StrCopySafe(_newExportClip->startTime, Utils::ConvertDateTimeToChar(value)); }
        }

    internal:
        VxSdk::VxNewExportClip* _newExportClip;
    };
}
#endif // NewExportClip_h__
