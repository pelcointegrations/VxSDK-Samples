// Declares the manual recording class.
#ifndef ManualRecording_h__
#define ManualRecording_h__

#include "VxSdk.h"
#include "DataSource.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The ManualRecording class represents an instance of an active manual recording (the action, not the recorded clip).
    /// Each manual recording will cause its specified data source to be manually recorded by all data storages that the
    /// data source is assigned to. Only one manual recording per user per data source is allowed. A clip created via the
    /// application of a manual recording will have an event value of manual.
    /// </summary>
    public ref class ManualRecording {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxManualRecording">The vx manual recording.</param>
        ManualRecording(VxSdk::IVxManualRecording* vxManualRecording);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~ManualRecording() {
            this->!ManualRecording();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !ManualRecording();

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Gets the data source that is being manually recorded.
        /// </summary>
        /// <value>The data source being manually recorded.</value>
        property CPPCli::DataSource^ DataSource {
        public:
            CPPCli::DataSource^ get() { return _GetDataSource(); }
        }

        /// <summary>
        /// Gets the unique identifier of the data source that is being manually recorded.
        /// </summary>
        /// <value>The unique identifier of the data source.</value>
        property System::String^ DataSourceId {
        public:
            System::String^ get() { return gcnew System::String(_manualRecording->dataSourceId); }
        }

        /// <summary>
        /// Gets the unique manual recording identifier.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_manualRecording->id); }
        }

        /// <summary>
        /// Gets the name of the user that created this manual recording.
        /// </summary>
        /// <value>The owner name.</value>
        property System::String^ OwnerName {
        public:
            System::String^ get() { return gcnew System::String(_manualRecording->owner); }
        }

        /// <summary>
        /// Gets the time at which this manual recording was created (not necessarily the exact time that the manual record clip starts).
        /// </summary>
        /// <value>A default <c>DateTime</c> if it fails, else the <c>DateTime</c> at which this manual recording was created.</value>
        property System::DateTime Time {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_manualRecording->time); }
        }

    internal:
        VxSdk::IVxManualRecording* _manualRecording;
        CPPCli::DataSource^ _GetDataSource();
    };
}
#endif // ManualRecording_h__
