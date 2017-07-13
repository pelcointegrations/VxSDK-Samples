// Declares the data source class.
#ifndef DataSource_h__
#define DataSource_h__

#include "Clip.h"
#include "DataSession.h"
#include "PtzController.h"

namespace CPPCli {
    ref class DataStorage;
    ref class Device;
    ref class ResourceRel;
    ref class UserInfo;

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
        /// Gets all data storages associated with this data source; includes edge and failover data storages.
        /// </summary>
        /// <value>A <c>List</c> of all associated data storages.</value>
        property System::Collections::Generic::List<DataStorage^>^ AllDataStorages {
        public:
            System::Collections::Generic::List<DataStorage^>^ get() { return _GetAllDataStorages(); }
        }

        /// <summary>
        /// Gets all possible audio resource relations for this data source (both linked and non-linked).
        /// Each linked resource shall be considered to be associated to this data source while non-linked resources
        /// shall not be (they are available to be associated).
        /// </summary>
        /// <value>A <c>List</c> of related audio resources.</value>
        property System::Collections::Generic::List<ResourceRel^>^ AudioRelations {
        public:
            System::Collections::Generic::List<ResourceRel^>^ get() { return _GetAudioRelations(); }
        }

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
        /// Gets the edge clips associated with this data source; may take a long time (minutes).
        /// </summary>
        /// <value>A <c>List</c> of the associated edge clips.</value>
        property System::Collections::Generic::List<Clip^>^ EdgeClips {
        public:
            System::Collections::Generic::List<Clip^>^ get() { return _GetEdgeClips(); }
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
        /// Gets the zero-based index (per host device) indicating the "position" of the data source (per data source type)
        /// within the host device.
        /// </summary>
        /// <value>The data source index.</value>
        property int Index {
        public:
            int get() { return _dataSource->index; }
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
        /// Gets the currently linked audio resource relation for this data source, if any.
        /// </summary>
        /// <value>The linked audio resource if available, otherwise <c>nullptr</c>.</value>
        property ResourceRel^ LinkedAudioRelation {
        public:
            ResourceRel^ get() { return _GetLinkedAudioRelation(); }
        }

        /// <summary>
        /// Gets the multiple viewer information for this data source.  This information contains details on the
        /// current viewers of this data source.
        /// </summary>
        /// <value>A <c>List</c> of user information for all viewers of this data source.</value>
        property System::Collections::Generic::List<UserInfo^>^ MultiviewInfo {
        public:
            System::Collections::Generic::List<UserInfo^>^ get() { return _GetMultiviewInfo(); }
        }

        /// <summary>
        /// Gets or sets the friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_dataSource->name); }
            void set(System::String^ value) {
                char name[64];
                VxSdk::Utilities::StrCopySafe(name, Utils::ConvertSysStringNonConst(value));
                _dataSource->SetName(name);
            }
        }

        /// <summary>
        /// Gets or sets the number used to designate the data source.
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

        /// <summary>
        /// Gets all possible video resource relations for this data source (both linked and non-linked).
        /// Each linked resource shall be considered to be associated to this data source while non-linked resources
        /// shall not be (they are available to be associated).
        /// </summary>
        /// <value>A <c>List</c> of related video resources.</value>
        property System::Collections::Generic::List<ResourceRel^>^ VideoRelations {
        public:
            System::Collections::Generic::List<ResourceRel^>^ get() { return _GetVideoRelations(); }
        }

    internal:
        VxSdk::IVxDataSource* _dataSource;
        bool _CanPtz();
        System::Collections::Generic::List<DataStorage^>^ _GetAllDataStorages();
        System::Collections::Generic::List<ResourceRel^>^ _GetAudioRelations();
        System::Collections::Generic::List<Clip^>^ _GetClips();
        System::Collections::Generic::List<DataInterface^>^ _GetDataInterfaces();
        System::Collections::Generic::List<DataStorage^>^ _GetDataStorages();
        System::Collections::Generic::List<Clip^>^ _GetEdgeClips();
        CPPCli::Device^ _GetHostDevice();
        ResourceRel^ _GetLinkedAudioRelation();
        System::Collections::Generic::List<UserInfo^>^ _GetMultiviewInfo();
        PtzController^ _GetPtzController();
        System::String^ _GetRtspEndpoint();
        System::Collections::Generic::List<ResourceRel^>^ _GetVideoRelations();
    };
}
#endif // DataSource_h__
