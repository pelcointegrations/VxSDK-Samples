// Declares the new manual recording class.
#ifndef NewManualRecording_h__
#define NewManualRecording_h__

#include "ManualRecording.h"

namespace CPPCli {

    /// <summary>
    /// The NewManualRecording class represents a request for a new manual recording to be generated.
    /// </summary>
    public ref class NewManualRecording {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewManualRecording() {
            _newManualRecording = new VxSdk::VxNewManualRecording();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewManualRecording">The new manual recording.</param>
        NewManualRecording(VxSdk::VxNewManualRecording* vxNewManualRecording) {
            _newManualRecording = vxNewManualRecording;
        }

        /// <summary>
        /// Gets or sets the unique identifier of the data source to manually record.
        /// </summary>
        /// <value>The unique identifier of the data source to manually record.</value>
        property System::String^ DataSourceId {
        public:
            System::String^ get() { return gcnew System::String(_newManualRecording->dataSourceId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newManualRecording->dataSourceId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the amount of time, from 0 to 30 seconds, to record after the manual recording is stopped.
        /// </summary>
        /// <value>The amount of time, in seconds, to record after the manual recording is stopped.</value>
        property int PostRecord {
        public:
            int get() { return _newManualRecording->postRecord; }
            void set(int value) { _newManualRecording->postRecord = value; }
        }

        /// <summary>
        /// Gets or sets the amount of time, from 0 to 30 seconds, to record prior to the manual recording start time.
        /// </summary>
        /// <value>The amount of time, in seconds, to record prior to the manual recording start time.</value>
        property int PreRecord {
        public:
            int get() { return _newManualRecording->preRecord; }
            void set(int value) { _newManualRecording->preRecord = value; }
        }

    internal:
        VxSdk::VxNewManualRecording* _newManualRecording;
    };
}
#endif // NewManualRecording_h__
