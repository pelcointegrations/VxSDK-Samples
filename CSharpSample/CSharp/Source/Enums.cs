namespace SDKSampleApp.Enums
{
    /// <summary>
    /// The VxResult enumeration.
    /// </summary>
    /// <remarks>The result of an executed method.</remarks>
    public enum VxResult
    {
        /// <summary>Unknown error occured.</summary>
        UnknownError,

        /// <summary>No errors occured.</summary>
        OK,

        /// <summary>Received an unsupported version error from the system.</summary>
        UnsupportedVersion,

        /// <summary>An invalid handle was given.</summary>
        InvalidHandle,

        /// <summary>The size value was insufficient.</summary>
        InsufficientSize,

        /// <summary>Login info is invalid for the selected system.</summary>
        InvalidLoginInfo
    }

    /// <summary>
    /// The VxAckState enumeration.
    /// </summary>
    /// <remarks>The acknowledgement state of an event.</remarks>
    public enum VxAckState
    {
        /// <summary>An error or unknown value was returned.</summary>
        Unknown,

        /// <summary>Event acknowledgement is needed.</summary>
        AckNeeded,

        /// <summary>Event is acknowledged.</summary>
        Acked,

        /// <summary>Event is auto-acknowledged.</summary>
        AutoAcked,

        /// <summary>No event acknowledgement is needed.</summary>
        NoAckNeeded,

        /// <summary>The event has been silenced.</summary>
        Silenced
    }

    /// <summary>
    /// The VxDeviceState enumeration.
    /// </summary>
    /// <remarks>The operational state of a device.</remarks>
    public enum VxDeviceState
    {
        /// <summary>An error or unknown value was returned.</summary>
        Unknown,

        /// <summary>The device is offline.</summary>
        Offline,

        /// <summary>The device is online.</summary>
        Online
    }

    /// <summary>
    /// The VxDeviceType enumeration.
    /// </summary>
    /// <remarks>The particular type of a device.</remarks>
    public enum VxDeviceType
    {
        /// <summary>An error or unknown value was returned.</summary>
        Unknown,

        /// <summary>A camera device.</summary>
        Camera,

        /// <summary>A VideoXpert Core device.</summary>
        Core,

        /// <summary>A VideoXpert Core/MediaGateway device.</summary>
        CoreMg,

        /// <summary>A decoder device.</summary>
        Decoder,

        /// <summary>An encoder device.</summary>
        Encoder,

        /// <summary>A system manager device.</summary>
        Manager,

        /// <summary>A VideoXpert MediaGateway device.</summary>
        Mg,

        /// <summary>A monitor device.</summary>
        Monitor,

        /// <summary>A network storage device.</summary>
        Recorder,

        /// <summary>A UDI device.</summary>
        Udi,

        /// <summary>A UI device.</summary>
        Ui,

        /// <summary>A VCD device.</summary>
        Vcd
    }

    /// <summary>
    /// The VxDataSourceType enumeration.
    /// </summary>
    /// <remarks>The particular type of a data source.</remarks>
    public enum VxDataSourceType
    {
        /// <summary>An error or unknown value was returned.</summary>
        Unknown,

        /// <summary>A video data source.</summary>
        Video,

        /// <summary>An audio data source.</summary>
        Audio
    }

    /// <summary>
    /// The VxStreamProtocol enumeration.
    /// </summary>
    /// <remarks>The stream interface protocol.</remarks>
    public enum VxStreamProtocol
    {
        /// <summary>An error or unknown value was returned.</summary>
        Unknown,

        /// <summary>An Mjpeg (pull) protocol interface.</summary>
        MjpegPull,

        /// <summary>An RTSP/RTP protocol interface.</summary>
        RtspRtp
    }

    /// <summary>
    /// The VxRecordType enumeration.
    /// </summary>
    /// <remarks> The type of trigger that caused the recording.</remarks>
    public enum VxRecordType
    {
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
    }

    /// <summary>
    /// The VxRecordFramerate enumeration.
    /// </summary>
    /// <remarks>The video framerate level.</remarks>
    public enum VxRecordFramerate
    {
        /// <summary>An error or unknown value was returned.</summary>
        Unknown,

        /// <summary>Low framerate.</summary>
        Low,

        /// <summary>Normal framerate.</summary>
        Normal
    }

    /// <summary>
    /// The VxRetentionPriority enumeration.
    /// </summary>
    /// <remarks>Indicates how long the recording device should attempt to retain the clip.</remarks>
    public enum VxRetentionPriority
    {
        /// <summary>An error or unknown value was returned.</summary>
        Unknown,

        /// <summary>Low retention priority.</summary>
        Low,

        /// <summary>Medium retention priority.</summary>
        Medium,

        /// <summary>High retention priority.</summary>
        High
    }
}
