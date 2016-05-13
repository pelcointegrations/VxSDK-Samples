// Declares the MediaControl class.
#ifndef MediaControl_h__
#define MediaControl_h__

#include "MediaEvent.h"
#include "Utils.h"
#include "DataSource.h"

namespace CPPCli {

    /// <summary>
    /// The MediaControl class creates a controller object that provides the ability to
    /// create and control video streams.
    /// </summary>
    public ref class MediaControl {
    public:

        /// <summary>
        /// Values that represent the different playback modes.
        /// </summary>
        enum class Modes {
            /// <summary>The stream is stopped.</summary>
            Stopped,

            /// <summary>The stream is playing live video.</summary>
            Live,

            /// <summary>The stream is playing recorded video.</summary>
            Playback
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="dataSource">The data source to use to create the stream.</param>
        /// <param name="dataInterface">The data interface to use to create the stream.</param>
        MediaControl(DataSource^ dataSource, DataInterface^ dataInterface);

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~MediaControl() {
            this->!MediaControl();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !MediaControl();

        /// <summary>
        /// Set the display window using the given window handle.
        /// </summary>
        /// <param name="windowHandle">An <c>IntPtr</c> to the window handle.</param>
        void SetVideoWindow(System::IntPtr windowHandle);

        /// <summary>
        /// Set the stream to a new data source.
        /// </summary>
        /// <param name="dataSource">The data source to set the stream to.</param>
        /// <param name="dataInterface">The data interface to use to create the stream.</param>
        void SetDataSource(DataSource^ dataSource, DataInterface^ dataInterface);

        /// <summary>
        /// Call Play on the stream.
        /// </summary>
        /// <param name="speed">The playback speed.  Negative values can be used for reverse playback.</param>
        bool Play(int speed);

        /// <summary>
        /// Call Pause on the stream.
        /// </summary>
        void Pause();

        /// <summary>
        /// Call TearDown on the stream.
        /// </summary>
        void Stop();

        /// <summary>
        /// Call GoToLive on the stream.
        /// </summary>
        void GoToLive();

        /// <summary>
        /// Call Play on the stream with the supplied start time, resulting in a playback stream.
        /// </summary>
        /// <param name="time">The start time for playback.</param>
        /// <param name="speed">The playback speed.  Negative values can be used for reverse playback.</param>
        bool Seek(System::DateTime time, int speed);

        /// <summary>
        /// Gets the current playback mode.
        /// </summary>
        /// <value>The current stream mode.</value>
        property Modes Mode {
            Modes get() { return (Modes)_control->GetMode(); }
        }

        /// <summary>
        /// Gets the current playback mode.
        /// </summary>
        /// <value>The current stream mode.</value>
        property DataSource^ CurrentDataSource {
            DataSource^ get() { return _currentdataSource; }
        }

        /// <summary>
        /// Get the status of the pipeline.
        /// </summary>
        /// <returns>True if pipeline is active, otherwise false.</returns>
        property bool IsPipelineActive {
            bool get() { return _control->IsPipelineActive(); }
        }

        /// <summary>
        /// The native event callback delegate.
        /// </summary>
        /// <param name="timeEvent">The time event sent from the stream.</param>
        [System::Runtime::InteropServices::UnmanagedFunctionPointer(
            System::Runtime::InteropServices::CallingConvention::Cdecl)]
        delegate void TimestampCallbackDelegate(MediaController::TimestampEvent* timeEvent);

        /// <summary>
        /// The managed event delegate.
        /// </summary>
        /// <param name="mediaEvent">The media event sent from the stream as a managed type.</param>
        delegate void TimestampEventDelegate(MediaEvent^ mediaEvent);

        /// <summary>
        /// TimestampEvent is raised whenever a new timestamp is received from the stream.
        /// </summary>
        event TimestampEventDelegate ^ TimestampEvent {
            void add(TimestampEventDelegate ^eventDelegate);
            void remove(TimestampEventDelegate ^eventDelegate);
        }

    internal:
        MediaController::IController* _control;
        void _FireTimestampEvent(MediaController::TimestampEvent* timeEvent);
        TimestampCallbackDelegate ^ _timestampCallback;
        TimestampEventDelegate ^ _timestampEvent;
        DataSource^ _currentdataSource;
    };
}
#endif // MediaControl_h__
