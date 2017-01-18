// Declares the clip class.
#ifndef Clip_h__
#define Clip_h__

#include "SnapshotFilter.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The Clip class represents a contiguous duration of stored media originating from a single DataSource.
    /// </summary>
    public ref class Clip {
    public:

        /// <summary>
        /// Values that represent the video framerate level.
        /// </summary>
        enum class RecordingFramerates {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>Low framerate.</summary>
            Low,

            /// <summary>Normal framerate.</summary>
            Normal
        };

        /// <summary>
        /// Values that represent the type of trigger that caused the recording.
        /// </summary>
        enum class RecordingTypes {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>Hardware or software alarm.</summary>
            Alarm,

            /// <summary>Video analytic (non-motion).</summary>
            Analytic,

            /// <summary>General system event.</summary>
            Event,

            /// <summary>Manual user initiation.</summary>
            Manual,

            /// <summary>Motion anayltic.</summary>
            Motion,

            /// <summary>Time-based (continuous); no event.</summary>
            Timed
        };

        /// <summary>
        /// Values that represent how long the recording device should attempt
        /// to retain the clip.
        /// </summary>
        enum class RetentionPriorities {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>Low retention priority.</summary>
            Low,

            /// <summary>Medium retention priority.</summary>
            Medium,

            /// <summary>High retention priority.</summary>
            High
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxClip">The vx clip.</param>
        Clip(VxSdk::IVxClip* vxClip);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Clip() {
            this->!Clip();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Clip();

        /// <summary>
        /// Gets the endpoint URI for snapshots.
        /// </summary>
        /// <returns>The snapshot endpoint.</returns>
        System::String^ GetSnapshotEndpoint(SnapshotFilter^ filter);

        /// <summary>
        /// Gets the unique identifier of the clips data source.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ DataSourceId {
        public:
            System::String^ get() { return gcnew System::String(_clip->dataSourceId); }
        }

        /// <summary>
        /// Gets the friendly name of the clips data source.
        /// </summary>
        /// <value>The friendly name of the data source.</value>
        property System::String^ DataSourceName {
        public:
            System::String^ get() { return gcnew System::String(_clip->dataSourceName); }
        }

        /// <summary>
        /// Gets the end time of the clip.
        /// </summary>
        /// <value>The end time.</value>
        property System::DateTime EndTime {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_clip->endTime); }
        }

        /// <summary>
        /// Gets the event type that triggered the recording of the clip.
        /// </summary>
        /// <value>The recording event type.</value>
        property RecordingTypes EventType {
        public:
            RecordingTypes get() { return RecordingTypes(_clip->recordingType); }
        }

        /// <summary>
        /// Gets the framerate of the clip.
        /// </summary>
        /// <value>The framerate.</value>
        property RecordingFramerates Framerate {
        public:
            RecordingFramerates get() { return RecordingFramerates(_clip->framerate); }
        }

        /// <summary>
        /// Gets the type of media contained in the clip.
        /// </summary>
        /// <value>The media type.</value>
        property System::String^ MediaType {
        public:
            System::String^ get() { return gcnew System::String(_clip->type); }
        }

        /// <summary>
        /// Gets the recording retention priority of the clip.
        /// </summary>
        /// <value>The priority level.</value>
        property RetentionPriorities Priority {
        public:
            RetentionPriorities get() { return RetentionPriorities(_clip->priority); }
        }

        /// <summary>
        /// Gets the start time of the clip.
        /// </summary>
        /// <value>The start time.</value>
        property System::DateTime StartTime {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_clip->startTime); }
        }

    internal:
        VxSdk::IVxClip* _clip;
    };
}
#endif // Clip_h__
