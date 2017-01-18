#ifndef VxPrimitives_h__
#define VxPrimitives_h__

namespace VxSdk {
    /// <summary>
    /// Values that represent the current acknowledgement state of an event.
    /// </summary>
    struct VxAckState {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The event needs acknowledgement.</summary>
            kAckNeeded,
            /// <summary>The event is acknowledged.</summary>
            kAcked,
            /// <summary>The event is auto-acknowledged.</summary>
            kAutoAcked,
            /// <summary>No event acknowledgement is needed.</summary>
            kNoAckNeeded,
            /// <summary>The event has been silenced.</summary>
            kSilenced
        };
    };

    /// <summary>
    /// Values that represent possible monitor layouts.
    /// </summary>
    struct VxCellLayout {
        enum Value {
            /// <summary>A 1x1 monitor layout.</summary>
            k1x1,
            /// <summary>A 1x2 monitor layout.</summary>
            k1x2,
            /// <summary>A 2x1 monitor layout.</summary>
            k2x1,
            /// <summary>A 2x2 monitor layout.</summary>
            k2x2,
            /// <summary>A 2x3 monitor layout.</summary>
            k2x3,
            /// <summary>A 3x2 monitor layout.</summary>
            k3x2,
            /// <summary>A 3x3 monitor layout.</summary>
            k3x3,
            /// <summary>A 4x3 monitor layout.</summary>
            k4x3,
            /// <summary>A 4x4 monitor layout.</summary>
            k4x4,
            /// <summary>A 1 plus 12 monitor layout.</summary>
            k1plus12,
            /// <summary>A 2 plus 8 monitor layout.</summary>
            k2plus8,
            /// <summary>A 3 plus 4 monitor layout.</summary>
            k3plus4,
            /// <summary>A 1 plus 5 monitor layout.</summary>
            k1plus5,
            /// <summary>A 1 plus 7 monitor layout.</summary>
            k1plus7,
            /// <summary>A 12 plus 1 monitor layout.</summary>
            k12plus1,
            /// <summary>A 8 plus 2 monitor layout.</summary>
            k8plus2,
            /// <summary>A 1 plus 4 tall monitor layout.</summary>
            k1plus4tall,
            /// <summary>A 1 plus 4 wide monitor layout.</summary>
            k1plus4wide
        };
    };

    /// <summary>
    /// Values that represent collection filter types.
    /// </summary>
    struct VxCollectionFilterItem {
        enum Value {
            /// <summary>No filter.</summary>
            kNone,
            /// <summary>The maximum number of items to return per page.</summary>
            kCount,
            /// <summary>Filter by data source id.</summary>
            kDataSourceId,
            /// <summary>Filter by start time.</summary>
            kSearchStartTime,
            /// <summary>Filter by end time.</summary>
            kSearchEndTime,
            /// <summary>Filter by name.</summary>
            kName,
            /// <summary>Filter by id.</summary>
            kId,
            /// <summary>The start index.</summary>
            kStart,
            /// <summary>Filter by type.</summary>
            kType,
            /// <summary>Filter by situation type.</summary>
            kSituationType,
            /// <summary>True to return only items that are not assigned.</summary>
            kUnassigned,
            /// <summary>Filter by data source number.</summary>
            kDataSourceNumber,
            /// <summary>Filter by the description value.</summary>
            kDescription,
            /// <summary>Return items that have been modified since the given time.</summary>
            kModifiedSince,
            /// <summary>Filter by the time value.</summary>
            kTime,
            /// <summary>Filter by the end time value.</summary>
            kEndTime,
            /// <summary>Filter by the start time value.</summary>
            kStartTime,
            /// <summary>Filter by the event value.</summary>
            kEvent,
            /// <summary>Filter by the framerate value.</summary>
            kFramerate,
            /// <summary>Filter by the priority value.</summary>
            kPriority,
            /// <summary>Filter by the client type value.</summary>
            kClientType,
            /// <summary>True to return only owned items.</summary>
            kOwned,
            /// <summary>Filter by owner.</summary>
            kOwner,
            /// <summary>Filter by the username value.</summary>
            kUsername,
            /// <summary>Filter by comma-separated list of tag names.</summary>
            kAllTags,
            /// <summary>True to return only items that are capturing.</summary>
            kCapturing,
            /// <summary>Filter by IP.</summary>
            kIp,
            /// <summary>Filter by number.</summary>
            kNumber,
            /// <summary>True to return only items that are recording.</summary>
            kRecording,
            /// <summary>Filter by the state value.</summary>
            kState,
            /// <summary>True to return only items that are commissioned.</summary>
            kCommissioned,
            /// <summary>Filter by model.</summary>
            kModel,
            /// <summary>Filter by serial.</summary>
            kSerial,
            /// <summary>Filter by vendor.</summary>
            kVendor,
            /// <summary>Filter by version.</summary>
            kVersion,
            /// <summary>Filter by the ack state value.</summary>
            kAckState,
            /// <summary>Filter by the ack user value.</summary>
            kAckUser,
            /// <summary>Filter by generator device id.</summary>
            kGeneratorDeviceId,
            /// <summary>True to return items that were sent to the client.</summary>
            kNotifies,
            /// <summary>Filter by severity.</summary>
            kSeverity,
            /// <summary>Filter by source device id.</summary>
            kSourceDeviceId,
            /// <summary>Filter by source username.</summary>
            kSourceUserName,
            /// <summary>Filter by the percent complete value.</summary>
            kPercentComplete,
            /// <summary>Filter by the size value.</summary>
            kSize,
            /// <summary>Filter by status.</summary>
            kStatus,
            /// <summary>Filter by resource id.</summary>
            kResourceId,
            /// <summary>Filter by permission.</summary>
            kPermission,
            /// <summary>True to return items that are internal to the server and read-only</summary>
            kInternal,
            /// <summary>Filter by action.</summary>
            kAction,
            /// <summary>Filter by the audible notification value.</summary>
            kAudibleNotify,
            /// <summary>Filter by the log value.</summary>
            kLog,
            /// <summary>Filter by the notify value.</summary>
            kNotify,
            /// <summary>Filter by resource type.</summary>
            kResourceType
        };
    };

    /// <summary>
    /// Values that represent the current cluster configuration status.
    /// </summary>
    struct VxConfigStatus {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The cluster is configured.</summary>
            kConfigured,
            /// <summary>The cluster is being configured.</summary>
            kConfiguring,
            /// <summary>Cluster configuration failed.</summary>
            kFailed,
            /// <summary>The cluster is unconfigured.</summary>
            kUnconfigured
        };
    };

    /// <summary>
    /// Values that represent the particular type of a data source.
    /// </summary>
    struct VxDataSourceType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>A video data source.</summary>
            kVideo,
            /// <summary>An audio data source.</summary>
            kAudio
        };
    };

    /// <summary>
    /// Values that represent hardware type of a data storage.
    /// </summary>
    struct VxDataStorageType  {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>A Digital Sentry device.</summary>
            kDigitalSentry,
            /// <summary>An NSM network video recorder device.</summary>
            kNSM,
            /// <summary>A VideoXpert storage device.</summary>
            kVideoXpertStorage
        };
    };

    /// <summary>
    /// Values that represent the operational state of a device.
    /// </summary>
    struct VxDeviceState {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The device is offline.</summary>
            kOffline,
            /// <summary>The device is online.</summary>
            kOnline
        };
    };

    /// <summary>
    /// Values that represent device types.
    /// </summary>
    struct VxDeviceType {
        enum Value {
            /// <summary>A camera device.</summary>
            kCamera,
            /// <summary>A VideoXpert Core device.</summary>
            kCore,
            /// <summary>A VideoXpert Core/MediaGateway device.</summary>
            kCoreMg,
            /// <summary>A decoder device.</summary>
            kDecoder,
            /// <summary>An encoder device.</summary>
            kEncoder,
            /// <summary>An external device.</summary>
            kExternal,
            /// <summary>A system manager device.</summary>
            kManager,
            /// <summary>A VideoXpert MediaGateway device.</summary>
            kMg,
            /// <summary>A monitor device.</summary>
            kMonitor,
            /// <summary>A network storage device.</summary>
            kRecorder,
            /// <summary>A UDI device.</summary>
            kUdi,
            /// <summary>A UI device.</summary>
            kUi,
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>A VCD device.</summary>
            kVcd
        };
    };

    /// <summary>
    /// Values that represent the format of exported data.
    /// </summary>
    struct VxExportFormat {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>MKV file(s) contained withing a zip file.</summary>
            kMkvZip,
            /// <summary>An MP4 file.</summary>
            kMp4
        };
    };

    /// <summary>
    /// Values that represent status of an export.
    /// </summary>
    struct VxExportStatus {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The export is in progress.</summary>
            kExporting,
            /// <summary>The export has failed.</summary>
            kFailed,
            /// <summary>The export is queued to start.</summary>
            kPending,
            /// <summary>The export has completed successfully.</summary>
            kSuccessful
        };
    };

    /// <summary>
    /// Values that represent focus directions.
    /// </summary>
    struct VxFocusDirection {
        enum Value {
            /// <summary>Stop focus movement.</summary>
            kStop,
            /// <summary>Focus farther.</summary>
            kFar,
            /// <summary>Focus nearer.</summary>
            kNear
        };
    };

    /// <summary>
    /// Values that represent iris directions.
    /// </summary>
    struct VxIrisDirection {
        enum Value {
            /// <summary>Stop iris movement.</summary>
            kStop,
            /// <summary>Close the iris.</summary>
            kClose,
            /// <summary>Open the iris.</summary>
            kOpen
        };
    };

    /// <summary>
    /// Values that represent logging severity levels.
    /// </summary>
    struct VxLogLevel  {
        enum Value
        {
            /// <summary>Trace log level.</summary>
            kTrace,
            /// <summary>Debug log level.</summary>
            kDebug,
            /// <summary>Info log level.</summary>
            kInfo,
            /// <summary>Warning log level.</summary>
            kWarning,
            /// <summary>Error log level.</summary>
            kError,
            /// <summary>Fatal log level.</summary>
            kFatal,
            /// <summary>Disable logging.</summary>
            kNone
        };
    };

    /// <summary>
    /// Values that represent status of creating a quick report.
    /// </summary>
    struct VxReportCreationStatus {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The report creation is in progress.</summary>
            kInProgress,
            /// <summary>The report failed to be created.</summary>
            kFailed,
            /// <summary>The report has successfully been created.</summary>
            kSuccessful
        };
    };

    /// <summary>
    /// Values that represent a permission type.
    /// </summary>
    struct VxPermissionId  {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>View video sources.</summary>
            kViewVideoSources,
            /// <summary>Use PTZ mode.</summary>
            kUsePtzMode,
            /// <summary>Lock PTZ mode.</summary>
            kLockPtzMode,
            /// <summary>Create system bookmarks.</summary>
            kCreateSystemBookmarks,
            /// <summary>Delete system bookmarks.</summary>
            kDeleteSystemBookmarks,
            /// <summary>Launch saved views remotely.</summary>
            kLaunchSavedViewsRemotely,
            /// <summary>View recorded video.</summary>
            kViewRecordedVideo,
            /// <summary>Export media clips.</summary>
            kExportMediaClips,
            /// <summary>Delete exports.</summary>
            kDeleteExports,
            /// <summary>Use map.</summary>
            kUseMap,
            /// <summary>View maps.</summary>
            kViewMaps,
            /// <summary>Place cameras on map.</summary>
            kPlaceCamerasOnMap,
            /// <summary>Manage map files.</summary>
            kManageMapFiles,
            /// <summary>Access user views.</summary>
            kAccessUserViews,
            /// <summary>Manage system views.</summary>
            kManageSystemViews,
            /// <summary>Audit user activity.</summary>
            kAuditUserActivity,
            /// <summary>View event history.</summary>
            kViewEventHistory,
            /// <summary>Handle events.</summary>
            kHandleEvents,
            /// <summary>Configure events.</summary>
            kConfigureEvents,
            /// <summary>Manage user accounts.</summary>
            kManageUserAccounts,
            /// <summary>Manage aggregator account.</summary>
            kManageAggregatorAccount,
            /// <summary>Assign roles to users.</summary>
            kAssignRolesToUsers,
            /// <summary>Manage roles.</summary>
            kManageRoles,
            /// <summary>Manage system tags.</summary>
            kManageSystemTags,
            /// <summary>Setup edge devices.</summary>
            kSetupEdgeDevices,
            /// <summary>Configure monitor wall decoders.</summary>
            kConfigureMonitorWallDecoders,
            /// <summary>Configure recording.</summary>
            kConfigureRecording
        };
    };

    /// <summary>
    /// Values that represent the video framerate level.
    /// </summary>
    struct VxRecordingFramerate {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Low framerate.</summary>
            kLow,
            /// <summary>Normal framerate.</summary>
            kNormal
        };
    };

    /// <summary>
    /// Values that represent the type of trigger that caused the recording.
    /// </summary>
    struct VxRecordingType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Hardware or software alarm.</summary>
            kAlarm,
            /// <summary>Video analytic (non-motion).</summary>
            kAnalytic,
            /// <summary>General system event.</summary>
            kEvent,
            /// <summary>Manual user initiation.</summary>
            kManual,
            /// <summary>Motion anayltic.</summary>
            kMotion,
            /// <summary>Time-based (continuous); no event.</summary>
            kTimed
        };
    };

    /// <summary>
    /// Values that represent the interval at which triggers repeat.
    /// </summary>
    struct VxRecurrenceType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Repeat daily.</summary>
            kDaily,
            /// <summary>Repeat weekly.</summary>
            kWeekly,
            /// <summary>Repeat monthly.</summary>
            kMonthly,
            /// <summary>Repeat yearly.</summary>
            kYearly
        };
    };

    /// <summary>
    /// Values that represent types of content for quick reports.
    /// </summary>
    struct VxReportContent {
        enum Value {
            /// <summary>Snapshot of camera configuration.</summary>
            kCameraConfig,
            /// <summary>Snapshot of all system device information.</summary>
            kDeviceInfo,
            /// <summary>System event history.</summary>
            kEventHistory,
            /// <summary>Device online/offline history.</summary>
            kOnlineOffline,
            /// <summary>Snapshot of recorder configuration.</summary>
            kRecorderConfig,
            /// <summary>Snapshot of recorder diagnostics.</summary>
            kRecorderDiagnostics,
            /// <summary>User action history.</summary>
            kUserActions,
            /// <summary>Snapshot of Vx cluster configuration.</summary>
            kVxClusterConfig
        };
    };

    /// <summary>
    /// Values that represent a type of resource.
    /// </summary>
    struct VxResourceType  {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>A data source resource.</summary>
            kDataSource,
            /// <summary>A device resource.</summary>
            kDevice,
            /// <summary>A user resource.</summary>
            kUser
        };
    };

    /// <summary>
    /// Values that represent the result of calls to the VideoXpert system.
    /// </summary>
    struct VxResult {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknownError,
            /// <summary>The action was successful.</summary>
            kOK,
            /// <summary>The VideoXpert system version is not supported.</summary>
            kUnsupportedVersion,
            /// <summary>The size value was not sufficient enough to allocate the collection.</summary>
            kInsufficientSize,
            /// <summary>The login credentials were invalid.</summary>
            kInvalidLoginInfo,
            /// <summary>The attempted action is unsupported by the system.</summary>
            kActionUnavailable,
            /// <summary>A parameter was invalid.</summary>
            kInvalidParameters,
            /// <summary>There was an error communicating to the device.</summary>
            kCommunicationError,
            /// <summary>The key used to initialize the SDK was invalid.</summary>
            kInvalidKey
        };
    };

    /// <summary>
    /// Values that represent how long the recording device should attempt
    /// to retain the clip.
    /// </summary>
    struct VxRetentionPriority {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Low retention priority.</summary>
            kLow,
            /// <summary>Medium retention priority.</summary>
            kMedium,
            /// <summary>High retention priority.</summary>
            kHigh
        };
    };

    /// <summary>
    /// Values that represent schedule recording actions.
    /// </summary>
    struct VxScheduleAction {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Record only the resource (associated with the schedule) that was
            /// the source of the event causing the schedule trigger to activate.</summary>
            kEventSourceRecord,
            /// <summary>Record all resources associated with the schedule.</summary>
            kRecord
        };
    };

    /// <summary>
    /// Values that represent the available situation types for triggering a schedule.
    /// </summary>
    struct VxSituationType  {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Hardware or software alarm active (system/alarm_active).</summary>
            kAlarmActive,
            /// <summary>Hardware or software alarm inactive (system/alarm_inactive).</summary>
            kAlarmInactive,
            /// <summary>Motion anayltic alarm active (analytic/motion).</summary>
            kMotion,
            /// <summary>Motion anayltic alarm inactive (analytic/no_motion).</summary>
            kNoMotion
        };
    };

    /// <summary>
    /// Values that represent snapshot filter types.
    /// </summary>
    struct VxSnapshotFilterItem {
        enum Value {
            /// <summary>No filter.</summary>
            kNone,
            /// <summary>Time (RFC 3339 format) at which the initial image should start .</summary>
            kStartTime,
            /// <summary>Time (RFC 3339 format) at which no further images should be returned.</summary>
            kEndTime,
            /// <summary>Scale to given width in pixels, maintaining ratio.</summary>
            kWidth,
            /// <summary>Return multiple images offset by this amount of time, in seconds, between images.</summary>
            kOffset
        };
    };

    /// <summary>
    /// Values that represent stream protocols.
    /// </summary>
    struct VxStreamProtocol {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The Mjpeg (pull) protocol.</summary>
            kMjpegPull,
            /// <summary>The RTSP/RTP protocol.</summary>
            kRtspRtp
        };
    };

    /// <summary>
    /// Values that represent the types of system licenses.
    /// </summary>
    struct VxSystemLicenseType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Enterprise system license.</summary>
            kEnterprise,
            /// <summary>Ultimate system license.</summary>
            kUltimate,
            /// <summary>Unlicensed system.</summary>
            kUnlicensed
        };
    };

    /// <summary>
    /// Values that represent zoom directions.
    /// </summary>
    struct VxZoomDirection {
        enum Value {
            /// <summary>Do not perform a zoom action.</summary>
            kNone,
            /// <summary>Stop zoom movement.</summary>
            kStop,
            /// <summary>Zoom in.</summary>
            kIn,
            /// <summary>Zoom out.</summary>
            kOut
        };
    };
}

#endif // VxPrimitives_h__
