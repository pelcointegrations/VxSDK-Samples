// Declares the data source class.
#ifndef DataSource_h__
#define DataSource_h__

#include "Clip.h"
#include "DataInterface.h"
#include "DataSession.h"
#include "PtzController.h"

namespace CPPCli {
    ref class DataStorage;
    ref class Device;

    /// <summary>
    /// The DataSource class represents a data producer in the system hosted by a device. Each
    /// DataSource provides a list of DataInterface, each of which provides a particular protocol
    /// used to transmit and control the data produced by this DataSource.
    /// </summary>
    public ref class DataSource {
    public:

        /// <summary>
        /// Values that represent the particular type of a data source.
        /// </summary>
        enum class Types {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>A video data source.</summary>
            Video,

            /// <summary>An audio data source.</summary>
            Audio
        };

        /// <summary>
        /// Values that represent the operational state of a device.
        /// </summary>
        enum class States {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>The device is offline.</summary>
            Offline,

            /// <summary>The device is online.</summary>
            Online
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxDataSource">The vx data source.</param>
        DataSource(VxSdk::IVxDataSource* vxDataSource);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~DataSource() {
            this->!DataSource();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !DataSource();

        /// <summary>
        /// Create a new MJPEG stream.
        /// </summary>
        /// <returns><c>nullptr</c> if it fails, else the new MJPEG streams <see cref="DataSession"/>.</returns>
        CPPCli::DataSession^ CreateMjpegStream();

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Gets the clips associated with this data source.
        /// </summary>
        /// <value>A <c>List</c> of the associated clips.</value>
        property System::Collections::Generic::List<Clip^>^ Clips {
        public:
            System::Collections::Generic::List<Clip^>^ get() { return _GetClips(); }
        }

        /// <summary>
        /// Gets all interfaces available for retrieval of data from this data source.
        /// </summary>
        /// <value>A <c>List</c> of the data interfaces.</value>
        property System::Collections::Generic::List<DataInterface^>^ DataInterfaces {
        public:
            System::Collections::Generic::List<DataInterface^>^ get() { return _GetDataInterfaces(); }
        }

        /// <summary>
        /// Gets the data storages that this data source is associated with.
        /// </summary>
        /// <value>A <c>List</c> of the associated data storages.</value>
        property System::Collections::Generic::List<DataStorage^>^ DataStorages {
        public:
            System::Collections::Generic::List<DataStorage^>^ get() { return _GetDataStorages(); }
        }

        /// <summary>
        /// Gets a value indicating whether the live stream is available.
        /// </summary>
        /// <value><c>true</c> if live is available, <c>false</c> if not.</value>
        property bool HasLiveStream {
        public:
            bool get() { return _dataSource->hasLive; }
        }

        /// <summary>
        /// Gets a value indicating whether the recorded video is available.
        /// </summary>
        /// <value><c>true</c> if recorded video is available, <c>false</c> if not.</value>
        property bool HasRecordedVideo {
        public:
            bool get() { return _dataSource->hasRecorded; }
        }

        /// <summary>
        /// Gets the device that hosts this data source.
        /// </summary>
        /// <value>The host device.</value>
        property CPPCli::Device^ HostDevice {
        public:
            CPPCli::Device^ get() { return _GetHostDevice(); }
        }

        /// <summary>
        /// Gets the unique identifier for this data source.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_dataSource->id); }
        }

        /// <summary>
        /// Gets the IP.
        /// </summary>
        /// <value>The IP.</value>
        property System::String^ Ip {
        public:
            System::String^ get() { return gcnew System::String(_dataSource->ip); }
        }

        /// <summary>
        /// Gets a value indicating whether this data source is currently being captured by a recorder.
        /// </summary>
        /// <value><c>true</c> if capturing, <c>false</c> if not.</value>
        property bool IsCapturing {
        public:
            bool get() { return _dataSource->isCapturing; }
        }

        /// <summary>
        /// Gets a value indicating whether PTZ is enabled.
        /// </summary>
        /// <value><c>true</c> if PTZ is enabled, <c>false</c> if not.</value>
        property bool IsPTZ {
        public:
            bool get() { return _CanPtz(); }
        }

        /// <summary>
        /// Gets a value indicating whether the data source is currently recording.
        /// </summary>
        /// <value><c>true</c> if recording, <c>false</c> if not.</value>
        property bool IsRecording {
        public:
            bool get() { return _dataSource->isRecording; }
        }

        /// <summary>
        /// Gets the friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_dataSource->name); }
            void set(System::String^ value) {
                char name[64];
                strncpy_s(name, Utils::ConvertSysStringNonConst(value), sizeof(name));
                _dataSource->SetName(name);
            }
        }

        /// <summary>
        /// Gets the number used to designate the data source.
        /// </summary>
        /// <value>The data source number.</value>
        property int Number {
        public:
            int get() { return _dataSource->number; }
            void set(int value) { _dataSource->SetNumber(value); }
        }

        /// <summary>
        /// Gets the <see cref="PtzController"/> associated with this data source.
        /// </summary>
        /// <value><c>nullptr</c> if PTZ is not supported on the device, else the <see cref="PtzController"/>.</value>
        property PtzController^ PTZController {
        public:
            PtzController^ get() { return _GetPtzController(); }
        }

        /// <summary>
        /// Gets the RTSP stream endpoint URI.
        /// </summary>
        /// <value>The RTSP endpoint.</value>
        property System::String^ RtspEndpoint {
        public:
            System::String^ get() { return _GetRtspEndpoint(); }
        }

        /// <summary>
        /// Gets the URI to retrieve the current live frame.
        /// </summary>
        /// <value>The JPEG URI.</value>
        property System::String^ SnapshotUri {
        public:
            System::String^ get() { return gcnew System::String(_dataSource->snapshotUri); }
        }

        /// <summary>
        /// Gets the current operational state of the associated device.
        /// </summary>
        /// <value>The current device state.</value>
        property States State {
        public:
            States get() { return States(_dataSource->state); }
        }

        /// <summary>
        /// Gets the type of media this data source contains.
        /// </summary>
        /// <value>The media type.</value>
        property Types Type {
        public:
            Types get() { return Types(_dataSource->type); }
        }

    internal:
        VxSdk::IVxDataSource* _dataSource;
        bool _CanPtz();
        System::Collections::Generic::List<Clip^>^ _GetClips();
        System::Collections::Generic::List<DataInterface^>^ _GetDataInterfaces();
        System::Collections::Generic::List<DataStorage^>^ _GetDataStorages();
        CPPCli::Device^ _GetHostDevice();
        PtzController^ _GetPtzController();
        System::String^ _GetRtspEndpoint();
    };
}
#endif // DataSource_h__
