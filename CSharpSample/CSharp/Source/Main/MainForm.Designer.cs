namespace SDKSampleApp.Source
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.btnPlay = new System.Windows.Forms.Button();
            this.panelVideoStreamLeft = new System.Windows.Forms.Panel();
            this.btnPause = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.lblTimestampLeft = new System.Windows.Forms.Label();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.connectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.vxSDKLogLevelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.logTraceToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.logDebugToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.logInfoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.logWarningToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.logErrorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.logFatalToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.logDisableToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.modifyLoggingPathToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.snapshotPathToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.showLogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.logoutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.eventsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.subscribeToSystemEventsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.subscribeToSystemEventsByTypeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.displayEventDialogsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.insertSystemEventToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.searchEventsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ptzToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.showPTZControlsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.streamsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.streamProtocolToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rtspToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mjpegToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.manageToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.alarmInputsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.bookmarkManagerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clusterConfigToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dataObjectsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dataSourcesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dataStorageManagerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.devicesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.drawingManagerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportManagerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.licenseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.monitorsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.notificationsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.quickLogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.quickReportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.relayOutputsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rolesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.scheduleManagerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.situationManagerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tagManagerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.usersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnSeek = new System.Windows.Forms.Button();
            this.btnLive = new System.Windows.Forms.Button();
            this.lblSpeed = new System.Windows.Forms.Label();
            this.nudSpeed = new System.Windows.Forms.NumericUpDown();
            this.scInner = new System.Windows.Forms.SplitContainer();
            this.dgvDataSources = new System.Windows.Forms.DataGridView();
            this.colStatus = new System.Windows.Forms.DataGridViewImageColumn();
            this.colName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colNumber = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.btnRefreshDataSources = new System.Windows.Forms.Button();
            this.pbLoadCameras = new System.Windows.Forms.ProgressBar();
            this.lblAddingCameras = new System.Windows.Forms.Label();
            this.nudPostRecord = new System.Windows.Forms.NumericUpDown();
            this.lblPostRecord = new System.Windows.Forms.Label();
            this.nudPreRecord = new System.Windows.Forms.NumericUpDown();
            this.lblPreRecord = new System.Windows.Forms.Label();
            this.btnManualRecord = new System.Windows.Forms.Button();
            this.dtpSeekTime = new System.Windows.Forms.DateTimePicker();
            this.btnSnapshot = new System.Windows.Forms.Button();
            this.lblTimestampRight = new System.Windows.Forms.Label();
            this.scVideoPanels = new System.Windows.Forms.SplitContainer();
            this.panelVideoStreamRight = new System.Windows.Forms.Panel();
            this.scOuter = new System.Windows.Forms.SplitContainer();
            this.txbxLog = new System.Windows.Forms.TextBox();
            this.bgWorker = new System.ComponentModel.BackgroundWorker();
            this.menuStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudSpeed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.scInner)).BeginInit();
            this.scInner.Panel1.SuspendLayout();
            this.scInner.Panel2.SuspendLayout();
            this.scInner.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDataSources)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPostRecord)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPreRecord)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.scVideoPanels)).BeginInit();
            this.scVideoPanels.Panel1.SuspendLayout();
            this.scVideoPanels.Panel2.SuspendLayout();
            this.scVideoPanels.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.scOuter)).BeginInit();
            this.scOuter.Panel1.SuspendLayout();
            this.scOuter.Panel2.SuspendLayout();
            this.scOuter.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnPlay
            // 
            this.btnPlay.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnPlay.Enabled = false;
            this.btnPlay.ForeColor = System.Drawing.SystemColors.WindowText;
            this.btnPlay.Location = new System.Drawing.Point(557, 366);
            this.btnPlay.Name = "btnPlay";
            this.btnPlay.Size = new System.Drawing.Size(45, 23);
            this.btnPlay.TabIndex = 14;
            this.btnPlay.Text = "Play";
            this.btnPlay.Click += new System.EventHandler(this.ButtonPlay_Click);
            // 
            // panelVideoStreamLeft
            // 
            this.panelVideoStreamLeft.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panelVideoStreamLeft.BackColor = System.Drawing.SystemColors.WindowText;
            this.panelVideoStreamLeft.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("panelVideoStreamLeft.BackgroundImage")));
            this.panelVideoStreamLeft.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.panelVideoStreamLeft.Location = new System.Drawing.Point(3, 3);
            this.panelVideoStreamLeft.Name = "panelVideoStreamLeft";
            this.panelVideoStreamLeft.Size = new System.Drawing.Size(584, 353);
            this.panelVideoStreamLeft.TabIndex = 2;
            this.panelVideoStreamLeft.Click += new System.EventHandler(this.PanelVideoStream_Click);
            this.panelVideoStreamLeft.MouseClick += new System.Windows.Forms.MouseEventHandler(this.PanelVideoStreamLeft_MouseClick);
            this.panelVideoStreamLeft.MouseEnter += new System.EventHandler(this.PanelVideoStream_MouseEnter);
            this.panelVideoStreamLeft.MouseLeave += new System.EventHandler(this.PanelVideoStream_MouseLeave);
            this.panelVideoStreamLeft.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.PanelVideoStream_MouseWheel);
            // 
            // btnPause
            // 
            this.btnPause.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnPause.Enabled = false;
            this.btnPause.ForeColor = System.Drawing.SystemColors.WindowText;
            this.btnPause.Location = new System.Drawing.Point(455, 366);
            this.btnPause.Name = "btnPause";
            this.btnPause.Size = new System.Drawing.Size(45, 23);
            this.btnPause.TabIndex = 2;
            this.btnPause.Text = "Pause";
            this.btnPause.Click += new System.EventHandler(this.ButtonPause_Click);
            // 
            // btnStop
            // 
            this.btnStop.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnStop.Enabled = false;
            this.btnStop.ForeColor = System.Drawing.SystemColors.WindowText;
            this.btnStop.Location = new System.Drawing.Point(506, 366);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(45, 23);
            this.btnStop.TabIndex = 4;
            this.btnStop.Text = "Stop";
            this.btnStop.Click += new System.EventHandler(this.ButtonStop_Click);
            // 
            // lblTimestampLeft
            // 
            this.lblTimestampLeft.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblTimestampLeft.Location = new System.Drawing.Point(3, 364);
            this.lblTimestampLeft.Name = "lblTimestampLeft";
            this.lblTimestampLeft.Size = new System.Drawing.Size(125, 25);
            this.lblTimestampLeft.TabIndex = 11;
            // 
            // menuStrip
            // 
            this.menuStrip.BackColor = System.Drawing.SystemColors.Control;
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.eventsToolStripMenuItem,
            this.ptzToolStripMenuItem,
            this.streamsToolStripMenuItem,
            this.manageToolStripMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(1584, 24);
            this.menuStrip.TabIndex = 35;
            this.menuStrip.Text = "menuStrip";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.connectToolStripMenuItem,
            this.vxSDKLogLevelToolStripMenuItem,
            this.modifyLoggingPathToolStripMenuItem,
            this.snapshotPathToolStripMenuItem,
            this.showLogToolStripMenuItem,
            this.logoutToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // connectToolStripMenuItem
            // 
            this.connectToolStripMenuItem.Name = "connectToolStripMenuItem";
            this.connectToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.connectToolStripMenuItem.Text = "Connect";
            this.connectToolStripMenuItem.Click += new System.EventHandler(this.MenuItemConnect_Click);
            // 
            // vxSDKLogLevelToolStripMenuItem
            // 
            this.vxSDKLogLevelToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.logTraceToolStripMenuItem,
            this.logDebugToolStripMenuItem,
            this.logInfoToolStripMenuItem,
            this.logWarningToolStripMenuItem,
            this.logErrorToolStripMenuItem,
            this.logFatalToolStripMenuItem,
            this.logDisableToolStripMenuItem});
            this.vxSDKLogLevelToolStripMenuItem.Name = "vxSDKLogLevelToolStripMenuItem";
            this.vxSDKLogLevelToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.vxSDKLogLevelToolStripMenuItem.Text = "VxSDK Log Level";
            // 
            // logTraceToolStripMenuItem
            // 
            this.logTraceToolStripMenuItem.Name = "logTraceToolStripMenuItem";
            this.logTraceToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.logTraceToolStripMenuItem.Tag = 0;
            this.logTraceToolStripMenuItem.Text = "Trace";
            this.logTraceToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLogLevel_Click);
            // 
            // logDebugToolStripMenuItem
            // 
            this.logDebugToolStripMenuItem.Name = "logDebugToolStripMenuItem";
            this.logDebugToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.logDebugToolStripMenuItem.Tag = 1;
            this.logDebugToolStripMenuItem.Text = "Debug";
            this.logDebugToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLogLevel_Click);
            // 
            // logInfoToolStripMenuItem
            // 
            this.logInfoToolStripMenuItem.Checked = true;
            this.logInfoToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.logInfoToolStripMenuItem.Name = "logInfoToolStripMenuItem";
            this.logInfoToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.logInfoToolStripMenuItem.Tag = 2;
            this.logInfoToolStripMenuItem.Text = "Info";
            this.logInfoToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLogLevel_Click);
            // 
            // logWarningToolStripMenuItem
            // 
            this.logWarningToolStripMenuItem.Name = "logWarningToolStripMenuItem";
            this.logWarningToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.logWarningToolStripMenuItem.Tag = 3;
            this.logWarningToolStripMenuItem.Text = "Warning";
            this.logWarningToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLogLevel_Click);
            // 
            // logErrorToolStripMenuItem
            // 
            this.logErrorToolStripMenuItem.Name = "logErrorToolStripMenuItem";
            this.logErrorToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.logErrorToolStripMenuItem.Tag = 4;
            this.logErrorToolStripMenuItem.Text = "Error";
            this.logErrorToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLogLevel_Click);
            // 
            // logFatalToolStripMenuItem
            // 
            this.logFatalToolStripMenuItem.Name = "logFatalToolStripMenuItem";
            this.logFatalToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.logFatalToolStripMenuItem.Tag = 5;
            this.logFatalToolStripMenuItem.Text = "Fatal";
            this.logFatalToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLogLevel_Click);
            // 
            // logDisableToolStripMenuItem
            // 
            this.logDisableToolStripMenuItem.Name = "logDisableToolStripMenuItem";
            this.logDisableToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.logDisableToolStripMenuItem.Tag = 6;
            this.logDisableToolStripMenuItem.Text = "Disable";
            this.logDisableToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLogLevel_Click);
            // 
            // modifyLoggingPathToolStripMenuItem
            // 
            this.modifyLoggingPathToolStripMenuItem.Name = "modifyLoggingPathToolStripMenuItem";
            this.modifyLoggingPathToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.modifyLoggingPathToolStripMenuItem.Text = "Modify Logging Path";
            this.modifyLoggingPathToolStripMenuItem.Click += new System.EventHandler(this.MenuItemModifyLoggingPath_Click);
            // 
            // snapshotPathToolStripMenuItem
            // 
            this.snapshotPathToolStripMenuItem.Name = "snapshotPathToolStripMenuItem";
            this.snapshotPathToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.snapshotPathToolStripMenuItem.Text = "Modify Snapshot location";
            this.snapshotPathToolStripMenuItem.Click += new System.EventHandler(this.MenuItemSnapshotPath_Click);
            // 
            // showLogToolStripMenuItem
            // 
            this.showLogToolStripMenuItem.Name = "showLogToolStripMenuItem";
            this.showLogToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.showLogToolStripMenuItem.Text = "Show Log";
            this.showLogToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLog_Click);
            // 
            // logoutToolStripMenuItem
            // 
            this.logoutToolStripMenuItem.Name = "logoutToolStripMenuItem";
            this.logoutToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.logoutToolStripMenuItem.Text = "Logout";
            this.logoutToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLogout_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.MenuItemExit_Click);
            // 
            // eventsToolStripMenuItem
            // 
            this.eventsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.subscribeToSystemEventsToolStripMenuItem,
            this.subscribeToSystemEventsByTypeToolStripMenuItem,
            this.displayEventDialogsToolStripMenuItem,
            this.insertSystemEventToolStripMenuItem,
            this.searchEventsToolStripMenuItem});
            this.eventsToolStripMenuItem.Enabled = false;
            this.eventsToolStripMenuItem.Name = "eventsToolStripMenuItem";
            this.eventsToolStripMenuItem.Size = new System.Drawing.Size(53, 20);
            this.eventsToolStripMenuItem.Text = "Events";
            // 
            // subscribeToSystemEventsToolStripMenuItem
            // 
            this.subscribeToSystemEventsToolStripMenuItem.Name = "subscribeToSystemEventsToolStripMenuItem";
            this.subscribeToSystemEventsToolStripMenuItem.Size = new System.Drawing.Size(261, 22);
            this.subscribeToSystemEventsToolStripMenuItem.Text = "Subscribe to System Events";
            this.subscribeToSystemEventsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemSubscribe_Click);
            // 
            // subscribeToSystemEventsByTypeToolStripMenuItem
            // 
            this.subscribeToSystemEventsByTypeToolStripMenuItem.Name = "subscribeToSystemEventsByTypeToolStripMenuItem";
            this.subscribeToSystemEventsByTypeToolStripMenuItem.Size = new System.Drawing.Size(261, 22);
            this.subscribeToSystemEventsByTypeToolStripMenuItem.Text = "Subscribe to System Events By Type";
            this.subscribeToSystemEventsByTypeToolStripMenuItem.Click += new System.EventHandler(this.MenuItemSubscribeByType_Click);
            // 
            // displayEventDialogsToolStripMenuItem
            // 
            this.displayEventDialogsToolStripMenuItem.Name = "displayEventDialogsToolStripMenuItem";
            this.displayEventDialogsToolStripMenuItem.Size = new System.Drawing.Size(261, 22);
            this.displayEventDialogsToolStripMenuItem.Text = "Display Event Dialogs";
            this.displayEventDialogsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemDisplayEventDialogs_Click);
            // 
            // insertSystemEventToolStripMenuItem
            // 
            this.insertSystemEventToolStripMenuItem.Name = "insertSystemEventToolStripMenuItem";
            this.insertSystemEventToolStripMenuItem.Size = new System.Drawing.Size(261, 22);
            this.insertSystemEventToolStripMenuItem.Text = "Insert System Event";
            this.insertSystemEventToolStripMenuItem.Click += new System.EventHandler(this.MenuItemInsertEvent_Click);
            // 
            // searchEventsToolStripMenuItem
            // 
            this.searchEventsToolStripMenuItem.Name = "searchEventsToolStripMenuItem";
            this.searchEventsToolStripMenuItem.Size = new System.Drawing.Size(261, 22);
            this.searchEventsToolStripMenuItem.Text = "Event Search";
            this.searchEventsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemSearchEvents_Click);
            // 
            // ptzToolStripMenuItem
            // 
            this.ptzToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.showPTZControlsToolStripMenuItem});
            this.ptzToolStripMenuItem.Name = "ptzToolStripMenuItem";
            this.ptzToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
            this.ptzToolStripMenuItem.Text = "PTZ";
            // 
            // showPTZControlsToolStripMenuItem
            // 
            this.showPTZControlsToolStripMenuItem.Name = "showPTZControlsToolStripMenuItem";
            this.showPTZControlsToolStripMenuItem.Size = new System.Drawing.Size(175, 22);
            this.showPTZControlsToolStripMenuItem.Text = "Show PTZ Controls";
            this.showPTZControlsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemShowPtzControls_Click);
            // 
            // streamsToolStripMenuItem
            // 
            this.streamsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.streamProtocolToolStripMenuItem});
            this.streamsToolStripMenuItem.Name = "streamsToolStripMenuItem";
            this.streamsToolStripMenuItem.Size = new System.Drawing.Size(61, 20);
            this.streamsToolStripMenuItem.Text = "Streams";
            // 
            // streamProtocolToolStripMenuItem
            // 
            this.streamProtocolToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.rtspToolStripMenuItem,
            this.mjpegToolStripMenuItem});
            this.streamProtocolToolStripMenuItem.Name = "streamProtocolToolStripMenuItem";
            this.streamProtocolToolStripMenuItem.Size = new System.Drawing.Size(159, 22);
            this.streamProtocolToolStripMenuItem.Text = "Stream Protocol";
            // 
            // rtspToolStripMenuItem
            // 
            this.rtspToolStripMenuItem.Checked = true;
            this.rtspToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.rtspToolStripMenuItem.Name = "rtspToolStripMenuItem";
            this.rtspToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.rtspToolStripMenuItem.Text = "RTSP";
            this.rtspToolStripMenuItem.Click += new System.EventHandler(this.MenuItemProtocol_Click);
            // 
            // mjpegToolStripMenuItem
            // 
            this.mjpegToolStripMenuItem.Name = "mjpegToolStripMenuItem";
            this.mjpegToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.mjpegToolStripMenuItem.Text = "MJPEG";
            this.mjpegToolStripMenuItem.Click += new System.EventHandler(this.MenuItemProtocol_Click);
            // 
            // manageToolStripMenuItem
            // 
            this.manageToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.alarmInputsToolStripMenuItem,
            this.bookmarkManagerToolStripMenuItem,
            this.clusterConfigToolStripMenuItem,
            this.dataObjectsToolStripMenuItem,
            this.dataSourcesToolStripMenuItem,
            this.dataStorageManagerToolStripMenuItem,
            this.devicesToolStripMenuItem,
            this.drawingManagerToolStripMenuItem,
            this.exportManagerToolStripMenuItem,
            this.licenseToolStripMenuItem,
            this.monitorsToolStripMenuItem,
            this.notificationsToolStripMenuItem,
            this.quickLogToolStripMenuItem,
            this.quickReportToolStripMenuItem,
            this.relayOutputsToolStripMenuItem,
            this.rolesToolStripMenuItem,
            this.scheduleManagerToolStripMenuItem,
            this.situationManagerToolStripMenuItem,
            this.tagManagerToolStripMenuItem,
            this.usersToolStripMenuItem});
            this.manageToolStripMenuItem.Enabled = false;
            this.manageToolStripMenuItem.Name = "manageToolStripMenuItem";
            this.manageToolStripMenuItem.Size = new System.Drawing.Size(62, 20);
            this.manageToolStripMenuItem.Text = "Manage";
            // 
            // alarmInputsToolStripMenuItem
            // 
            this.alarmInputsToolStripMenuItem.Name = "alarmInputsToolStripMenuItem";
            this.alarmInputsToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.alarmInputsToolStripMenuItem.Text = "Alarm Inputs";
            this.alarmInputsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemAlarmInputManager_Click);
            // 
            // bookmarkManagerToolStripMenuItem
            // 
            this.bookmarkManagerToolStripMenuItem.Name = "bookmarkManagerToolStripMenuItem";
            this.bookmarkManagerToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.bookmarkManagerToolStripMenuItem.Text = "Bookmarks";
            this.bookmarkManagerToolStripMenuItem.Click += new System.EventHandler(this.MenuItemBookmarkManager_Click);
            // 
            // clusterConfigToolStripMenuItem
            // 
            this.clusterConfigToolStripMenuItem.Name = "clusterConfigToolStripMenuItem";
            this.clusterConfigToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.clusterConfigToolStripMenuItem.Text = "Cluster Configuration";
            this.clusterConfigToolStripMenuItem.Click += new System.EventHandler(this.MenuItemClusterConfig_Click);
            // 
            // dataObjectsToolStripMenuItem
            // 
            this.dataObjectsToolStripMenuItem.Name = "dataObjectsToolStripMenuItem";
            this.dataObjectsToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.dataObjectsToolStripMenuItem.Text = "Data Objects";
            this.dataObjectsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemDataObjectManager_Click);
            // 
            // dataSourcesToolStripMenuItem
            // 
            this.dataSourcesToolStripMenuItem.Name = "dataSourcesToolStripMenuItem";
            this.dataSourcesToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.dataSourcesToolStripMenuItem.Text = "Data Sources";
            this.dataSourcesToolStripMenuItem.Click += new System.EventHandler(this.MenuItemDataSourceManager_Click);
            // 
            // dataStorageManagerToolStripMenuItem
            // 
            this.dataStorageManagerToolStripMenuItem.Name = "dataStorageManagerToolStripMenuItem";
            this.dataStorageManagerToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.dataStorageManagerToolStripMenuItem.Text = "Data Storage";
            this.dataStorageManagerToolStripMenuItem.Click += new System.EventHandler(this.MenuItemDataStorageManager_Click);
            // 
            // devicesToolStripMenuItem
            // 
            this.devicesToolStripMenuItem.Name = "devicesToolStripMenuItem";
            this.devicesToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.devicesToolStripMenuItem.Text = "Devices";
            this.devicesToolStripMenuItem.Click += new System.EventHandler(this.MenuItemDeviceManager_Click);
            // 
            // drawingManagerToolStripMenuItem
            // 
            this.drawingManagerToolStripMenuItem.Name = "drawingManagerToolStripMenuItem";
            this.drawingManagerToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.drawingManagerToolStripMenuItem.Text = "Drawings";
            this.drawingManagerToolStripMenuItem.Click += new System.EventHandler(this.MenuItemDrawingManager_Click);
            // 
            // exportManagerToolStripMenuItem
            // 
            this.exportManagerToolStripMenuItem.Name = "exportManagerToolStripMenuItem";
            this.exportManagerToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.exportManagerToolStripMenuItem.Text = "Exports";
            this.exportManagerToolStripMenuItem.Click += new System.EventHandler(this.MenuItemExportManager_Click);
            // 
            // licenseToolStripMenuItem
            // 
            this.licenseToolStripMenuItem.Name = "licenseToolStripMenuItem";
            this.licenseToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.licenseToolStripMenuItem.Text = "License";
            this.licenseToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLicenseDetails_Click);
            // 
            // monitorsToolStripMenuItem
            // 
            this.monitorsToolStripMenuItem.Name = "monitorsToolStripMenuItem";
            this.monitorsToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.monitorsToolStripMenuItem.Text = "Monitors";
            this.monitorsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemMonitors_Click);
            // 
            // notificationsToolStripMenuItem
            // 
            this.notificationsToolStripMenuItem.Name = "notificationsToolStripMenuItem";
            this.notificationsToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.notificationsToolStripMenuItem.Text = "Notifications";
            this.notificationsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemNotifications_Click);
            // 
            // quickLogToolStripMenuItem
            // 
            this.quickLogToolStripMenuItem.Name = "quickLogToolStripMenuItem";
            this.quickLogToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.quickLogToolStripMenuItem.Text = "Quick Log";
            this.quickLogToolStripMenuItem.Click += new System.EventHandler(this.MenuItemQuickLog_Click);
            // 
            // quickReportToolStripMenuItem
            // 
            this.quickReportToolStripMenuItem.Name = "quickReportToolStripMenuItem";
            this.quickReportToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.quickReportToolStripMenuItem.Text = "Quick Report";
            this.quickReportToolStripMenuItem.Click += new System.EventHandler(this.MenuItemQuickReport_Click);
            // 
            // relayOutputsToolStripMenuItem
            // 
            this.relayOutputsToolStripMenuItem.Name = "relayOutputsToolStripMenuItem";
            this.relayOutputsToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.relayOutputsToolStripMenuItem.Text = "Relay Outputs";
            this.relayOutputsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemRelayOutputManager_Click);
            // 
            // rolesToolStripMenuItem
            // 
            this.rolesToolStripMenuItem.Name = "rolesToolStripMenuItem";
            this.rolesToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.rolesToolStripMenuItem.Text = "Roles";
            this.rolesToolStripMenuItem.Click += new System.EventHandler(this.MenuItemRoleManager_Click);
            // 
            // scheduleManagerToolStripMenuItem
            // 
            this.scheduleManagerToolStripMenuItem.Name = "scheduleManagerToolStripMenuItem";
            this.scheduleManagerToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.scheduleManagerToolStripMenuItem.Text = "Schedules";
            this.scheduleManagerToolStripMenuItem.Click += new System.EventHandler(this.MenuItemScheduleManager_Click);
            // 
            // situationManagerToolStripMenuItem
            // 
            this.situationManagerToolStripMenuItem.Name = "situationManagerToolStripMenuItem";
            this.situationManagerToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.situationManagerToolStripMenuItem.Text = "Situations";
            this.situationManagerToolStripMenuItem.Click += new System.EventHandler(this.MenuItemSituationManager_Click);
            // 
            // tagManagerToolStripMenuItem
            // 
            this.tagManagerToolStripMenuItem.Name = "tagManagerToolStripMenuItem";
            this.tagManagerToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.tagManagerToolStripMenuItem.Text = "Tags";
            this.tagManagerToolStripMenuItem.Click += new System.EventHandler(this.MenuItemTagManager_Click);
            // 
            // usersToolStripMenuItem
            // 
            this.usersToolStripMenuItem.Name = "usersToolStripMenuItem";
            this.usersToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.usersToolStripMenuItem.Text = "Users";
            this.usersToolStripMenuItem.Click += new System.EventHandler(this.MenuItemUserManager_Click);
            // 
            // btnSeek
            // 
            this.btnSeek.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnSeek.Enabled = false;
            this.btnSeek.ForeColor = System.Drawing.SystemColors.WindowText;
            this.btnSeek.Location = new System.Drawing.Point(353, 366);
            this.btnSeek.Name = "btnSeek";
            this.btnSeek.Size = new System.Drawing.Size(45, 23);
            this.btnSeek.TabIndex = 36;
            this.btnSeek.Text = "Seek";
            this.btnSeek.Click += new System.EventHandler(this.ButtonSeek_Click);
            // 
            // btnLive
            // 
            this.btnLive.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnLive.Enabled = false;
            this.btnLive.ForeColor = System.Drawing.SystemColors.WindowText;
            this.btnLive.Location = new System.Drawing.Point(404, 366);
            this.btnLive.Name = "btnLive";
            this.btnLive.Size = new System.Drawing.Size(45, 23);
            this.btnLive.TabIndex = 37;
            this.btnLive.Text = "Live";
            this.btnLive.Click += new System.EventHandler(this.ButtonLive_Click);
            // 
            // lblSpeed
            // 
            this.lblSpeed.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblSpeed.AutoSize = true;
            this.lblSpeed.Location = new System.Drawing.Point(608, 371);
            this.lblSpeed.Name = "lblSpeed";
            this.lblSpeed.Size = new System.Drawing.Size(38, 13);
            this.lblSpeed.TabIndex = 38;
            this.lblSpeed.Text = "Speed";
            // 
            // nudSpeed
            // 
            this.nudSpeed.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.nudSpeed.DecimalPlaces = 1;
            this.nudSpeed.Location = new System.Drawing.Point(647, 369);
            this.nudSpeed.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.nudSpeed.Minimum = new decimal(new int[] {
            300,
            0,
            0,
            -2147483648});
            this.nudSpeed.Name = "nudSpeed";
            this.nudSpeed.Size = new System.Drawing.Size(44, 20);
            this.nudSpeed.TabIndex = 39;
            this.nudSpeed.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // scInner
            // 
            this.scInner.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.scInner.Location = new System.Drawing.Point(3, 3);
            this.scInner.Name = "scInner";
            // 
            // scInner.Panel1
            // 
            this.scInner.Panel1.Controls.Add(this.dgvDataSources);
            this.scInner.Panel1.Controls.Add(this.btnRefreshDataSources);
            this.scInner.Panel1.Controls.Add(this.pbLoadCameras);
            this.scInner.Panel1.Controls.Add(this.lblAddingCameras);
            // 
            // scInner.Panel2
            // 
            this.scInner.Panel2.BackColor = System.Drawing.SystemColors.Control;
            this.scInner.Panel2.Controls.Add(this.nudPostRecord);
            this.scInner.Panel2.Controls.Add(this.lblPostRecord);
            this.scInner.Panel2.Controls.Add(this.nudPreRecord);
            this.scInner.Panel2.Controls.Add(this.lblPreRecord);
            this.scInner.Panel2.Controls.Add(this.btnManualRecord);
            this.scInner.Panel2.Controls.Add(this.dtpSeekTime);
            this.scInner.Panel2.Controls.Add(this.btnSnapshot);
            this.scInner.Panel2.Controls.Add(this.lblTimestampRight);
            this.scInner.Panel2.Controls.Add(this.scVideoPanels);
            this.scInner.Panel2.Controls.Add(this.lblTimestampLeft);
            this.scInner.Panel2.Controls.Add(this.nudSpeed);
            this.scInner.Panel2.Controls.Add(this.btnLive);
            this.scInner.Panel2.Controls.Add(this.lblSpeed);
            this.scInner.Panel2.Controls.Add(this.btnPause);
            this.scInner.Panel2.Controls.Add(this.btnStop);
            this.scInner.Panel2.Controls.Add(this.btnSeek);
            this.scInner.Panel2.Controls.Add(this.btnPlay);
            this.scInner.Size = new System.Drawing.Size(1559, 394);
            this.scInner.SplitterDistance = 366;
            this.scInner.TabIndex = 40;
            // 
            // dgvDataSources
            // 
            this.dgvDataSources.AllowUserToAddRows = false;
            this.dgvDataSources.AllowUserToDeleteRows = false;
            this.dgvDataSources.AllowUserToResizeRows = false;
            this.dgvDataSources.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvDataSources.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dgvDataSources.CellBorderStyle = System.Windows.Forms.DataGridViewCellBorderStyle.SingleHorizontal;
            this.dgvDataSources.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvDataSources.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.colStatus,
            this.colName,
            this.colNumber});
            this.dgvDataSources.Location = new System.Drawing.Point(0, 0);
            this.dgvDataSources.MultiSelect = false;
            this.dgvDataSources.Name = "dgvDataSources";
            this.dgvDataSources.ReadOnly = true;
            this.dgvDataSources.RowHeadersVisible = false;
            this.dgvDataSources.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvDataSources.ShowEditingIcon = false;
            this.dgvDataSources.ShowRowErrors = false;
            this.dgvDataSources.Size = new System.Drawing.Size(366, 359);
            this.dgvDataSources.TabIndex = 5;
            this.dgvDataSources.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.GridViewDataSources_CellDoubleClick);
            // 
            // colStatus
            // 
            this.colStatus.HeaderText = "";
            this.colStatus.Name = "colStatus";
            this.colStatus.ReadOnly = true;
            this.colStatus.Width = 40;
            // 
            // colName
            // 
            this.colName.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.colName.HeaderText = "Name";
            this.colName.Name = "colName";
            this.colName.ReadOnly = true;
            // 
            // colNumber
            // 
            this.colNumber.HeaderText = "#";
            this.colNumber.Name = "colNumber";
            this.colNumber.ReadOnly = true;
            this.colNumber.Width = 60;
            // 
            // btnRefreshDataSources
            // 
            this.btnRefreshDataSources.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnRefreshDataSources.Enabled = false;
            this.btnRefreshDataSources.Location = new System.Drawing.Point(3, 366);
            this.btnRefreshDataSources.Name = "btnRefreshDataSources";
            this.btnRefreshDataSources.Size = new System.Drawing.Size(75, 23);
            this.btnRefreshDataSources.TabIndex = 4;
            this.btnRefreshDataSources.Text = "Refresh";
            this.btnRefreshDataSources.Click += new System.EventHandler(this.ButtonRefreshDataSources_Click);
            // 
            // pbLoadCameras
            // 
            this.pbLoadCameras.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbLoadCameras.BackColor = System.Drawing.SystemColors.Control;
            this.pbLoadCameras.Location = new System.Drawing.Point(99, 371);
            this.pbLoadCameras.Name = "pbLoadCameras";
            this.pbLoadCameras.Size = new System.Drawing.Size(264, 21);
            this.pbLoadCameras.TabIndex = 3;
            this.pbLoadCameras.Visible = false;
            // 
            // lblAddingCameras
            // 
            this.lblAddingCameras.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblAddingCameras.Location = new System.Drawing.Point(3, 375);
            this.lblAddingCameras.Name = "lblAddingCameras";
            this.lblAddingCameras.Size = new System.Drawing.Size(90, 13);
            this.lblAddingCameras.TabIndex = 2;
            this.lblAddingCameras.Text = "Loading Cameras";
            this.lblAddingCameras.Visible = false;
            // 
            // nudPostRecord
            // 
            this.nudPostRecord.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.nudPostRecord.Enabled = false;
            this.nudPostRecord.Location = new System.Drawing.Point(881, 366);
            this.nudPostRecord.Maximum = new decimal(new int[] {
            30,
            0,
            0,
            0});
            this.nudPostRecord.Name = "nudPostRecord";
            this.nudPostRecord.Size = new System.Drawing.Size(44, 20);
            this.nudPostRecord.TabIndex = 51;
            this.nudPostRecord.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblPostRecord
            // 
            this.lblPostRecord.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblPostRecord.AutoSize = true;
            this.lblPostRecord.Location = new System.Drawing.Point(852, 370);
            this.lblPostRecord.Name = "lblPostRecord";
            this.lblPostRecord.Size = new System.Drawing.Size(28, 13);
            this.lblPostRecord.TabIndex = 50;
            this.lblPostRecord.Text = "Post";
            // 
            // nudPreRecord
            // 
            this.nudPreRecord.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.nudPreRecord.Enabled = false;
            this.nudPreRecord.Location = new System.Drawing.Point(802, 366);
            this.nudPreRecord.Maximum = new decimal(new int[] {
            30,
            0,
            0,
            0});
            this.nudPreRecord.Name = "nudPreRecord";
            this.nudPreRecord.Size = new System.Drawing.Size(44, 20);
            this.nudPreRecord.TabIndex = 49;
            this.nudPreRecord.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.nudPreRecord.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // lblPreRecord
            // 
            this.lblPreRecord.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblPreRecord.AutoSize = true;
            this.lblPreRecord.Location = new System.Drawing.Point(777, 370);
            this.lblPreRecord.Name = "lblPreRecord";
            this.lblPreRecord.Size = new System.Drawing.Size(23, 13);
            this.lblPreRecord.TabIndex = 48;
            this.lblPreRecord.Text = "Pre";
            // 
            // btnManualRecord
            // 
            this.btnManualRecord.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnManualRecord.Enabled = false;
            this.btnManualRecord.Location = new System.Drawing.Point(931, 365);
            this.btnManualRecord.Name = "btnManualRecord";
            this.btnManualRecord.Size = new System.Drawing.Size(51, 23);
            this.btnManualRecord.TabIndex = 47;
            this.btnManualRecord.Text = "Record";
            this.btnManualRecord.UseVisualStyleBackColor = true;
            this.btnManualRecord.Click += new System.EventHandler(this.ButtonManualRecord_Click);
            // 
            // dtpSeekTime
            // 
            this.dtpSeekTime.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.dtpSeekTime.CustomFormat = "yyyy-MM-dd hh:mm:ss tt";
            this.dtpSeekTime.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpSeekTime.Location = new System.Drawing.Point(206, 367);
            this.dtpSeekTime.Name = "dtpSeekTime";
            this.dtpSeekTime.ShowUpDown = true;
            this.dtpSeekTime.Size = new System.Drawing.Size(141, 20);
            this.dtpSeekTime.TabIndex = 46;
            // 
            // btnSnapshot
            // 
            this.btnSnapshot.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnSnapshot.Enabled = false;
            this.btnSnapshot.Location = new System.Drawing.Point(697, 366);
            this.btnSnapshot.Name = "btnSnapshot";
            this.btnSnapshot.Size = new System.Drawing.Size(75, 23);
            this.btnSnapshot.TabIndex = 45;
            this.btnSnapshot.Text = "Snapshot";
            this.btnSnapshot.Click += new System.EventHandler(this.ButtonSnapshot_Click);
            // 
            // lblTimestampRight
            // 
            this.lblTimestampRight.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.lblTimestampRight.Location = new System.Drawing.Point(1058, 364);
            this.lblTimestampRight.Name = "lblTimestampRight";
            this.lblTimestampRight.Size = new System.Drawing.Size(125, 25);
            this.lblTimestampRight.TabIndex = 44;
            this.lblTimestampRight.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // scVideoPanels
            // 
            this.scVideoPanels.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.scVideoPanels.Location = new System.Drawing.Point(3, 3);
            this.scVideoPanels.Name = "scVideoPanels";
            // 
            // scVideoPanels.Panel1
            // 
            this.scVideoPanels.Panel1.Controls.Add(this.panelVideoStreamLeft);
            // 
            // scVideoPanels.Panel2
            // 
            this.scVideoPanels.Panel2.Controls.Add(this.panelVideoStreamRight);
            this.scVideoPanels.Size = new System.Drawing.Size(1183, 359);
            this.scVideoPanels.SplitterDistance = 590;
            this.scVideoPanels.TabIndex = 41;
            // 
            // panelVideoStreamRight
            // 
            this.panelVideoStreamRight.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panelVideoStreamRight.BackColor = System.Drawing.SystemColors.WindowText;
            this.panelVideoStreamRight.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("panelVideoStreamRight.BackgroundImage")));
            this.panelVideoStreamRight.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.panelVideoStreamRight.Location = new System.Drawing.Point(3, 3);
            this.panelVideoStreamRight.Name = "panelVideoStreamRight";
            this.panelVideoStreamRight.Size = new System.Drawing.Size(578, 353);
            this.panelVideoStreamRight.TabIndex = 3;
            this.panelVideoStreamRight.Click += new System.EventHandler(this.PanelVideoStream_Click);
            this.panelVideoStreamRight.MouseClick += new System.Windows.Forms.MouseEventHandler(this.PanelVideoStreamRight_MouseClick);
            this.panelVideoStreamRight.MouseEnter += new System.EventHandler(this.PanelVideoStream_MouseEnter);
            this.panelVideoStreamRight.MouseLeave += new System.EventHandler(this.PanelVideoStream_MouseLeave);
            this.panelVideoStreamRight.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.PanelVideoStream_MouseWheel);
            // 
            // scOuter
            // 
            this.scOuter.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.scOuter.FixedPanel = System.Windows.Forms.FixedPanel.Panel2;
            this.scOuter.Location = new System.Drawing.Point(12, 27);
            this.scOuter.Name = "scOuter";
            this.scOuter.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // scOuter.Panel1
            // 
            this.scOuter.Panel1.Controls.Add(this.scInner);
            // 
            // scOuter.Panel2
            // 
            this.scOuter.Panel2.Controls.Add(this.txbxLog);
            this.scOuter.Size = new System.Drawing.Size(1567, 494);
            this.scOuter.SplitterDistance = 404;
            this.scOuter.TabIndex = 41;
            // 
            // txbxLog
            // 
            this.txbxLog.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbxLog.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txbxLog.Location = new System.Drawing.Point(6, 3);
            this.txbxLog.Multiline = true;
            this.txbxLog.Name = "txbxLog";
            this.txbxLog.ReadOnly = true;
            this.txbxLog.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbxLog.Size = new System.Drawing.Size(1554, 78);
            this.txbxLog.TabIndex = 0;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1584, 528);
            this.Controls.Add(this.scOuter);
            this.Controls.Add(this.menuStrip);
            this.MainMenuStrip = this.menuStrip;
            this.Name = "MainForm";
            this.Text = "C# VideoXpert SDK Sample";
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudSpeed)).EndInit();
            this.scInner.Panel1.ResumeLayout(false);
            this.scInner.Panel2.ResumeLayout(false);
            this.scInner.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.scInner)).EndInit();
            this.scInner.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvDataSources)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPostRecord)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPreRecord)).EndInit();
            this.scVideoPanels.Panel1.ResumeLayout(false);
            this.scVideoPanels.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.scVideoPanels)).EndInit();
            this.scVideoPanels.ResumeLayout(false);
            this.scOuter.Panel1.ResumeLayout(false);
            this.scOuter.Panel2.ResumeLayout(false);
            this.scOuter.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.scOuter)).EndInit();
            this.scOuter.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.Panel panelVideoStreamLeft;

        public System.Windows.Forms.Label lblTimestampLeft;
        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem connectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem subscribeToSystemEventsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem showPTZControlsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem streamsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem streamProtocolToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rtspToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mjpegToolStripMenuItem;
        public System.Windows.Forms.Button btnPlay;
        public System.Windows.Forms.Button btnPause;
        public System.Windows.Forms.Button btnStop;
        public System.Windows.Forms.ToolStripMenuItem eventsToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem ptzToolStripMenuItem;
        public System.Windows.Forms.Button btnSeek;
        public System.Windows.Forms.Button btnLive;
        private System.Windows.Forms.Label lblSpeed;
        private System.Windows.Forms.NumericUpDown nudSpeed;
        private System.Windows.Forms.SplitContainer scInner;
        private System.Windows.Forms.ToolStripMenuItem insertSystemEventToolStripMenuItem;
        private System.Windows.Forms.SplitContainer scOuter;
        public System.Windows.Forms.TextBox txbxLog;

        public System.Windows.Forms.Panel panelVideoStreamRight;

        public System.Windows.Forms.SplitContainer scVideoPanels;

        public System.Windows.Forms.Label lblTimestampRight;
        private System.Windows.Forms.ToolStripMenuItem showLogToolStripMenuItem;
        public System.Windows.Forms.Button btnSnapshot;
        private System.Windows.Forms.ToolStripMenuItem snapshotPathToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem manageToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem bookmarkManagerToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem scheduleManagerToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem exportManagerToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem situationManagerToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem dataStorageManagerToolStripMenuItem;
        public System.Windows.Forms.Label lblAddingCameras;
        public System.Windows.Forms.ProgressBar pbLoadCameras;
        private System.Windows.Forms.ToolStripMenuItem tagManagerToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem searchEventsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem displayEventDialogsToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem subscribeToSystemEventsByTypeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem usersToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dataObjectsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rolesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clusterConfigToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem drawingManagerToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem devicesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem licenseToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem notificationsToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem vxSDKLogLevelToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem logTraceToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem logDebugToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem logInfoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem logWarningToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem logErrorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem logFatalToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem logDisableToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem quickReportToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem monitorsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dataSourcesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem quickLogToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem logoutToolStripMenuItem;
        public System.Windows.Forms.Button btnRefreshDataSources;
        public System.ComponentModel.BackgroundWorker bgWorker;
        private System.Windows.Forms.DateTimePicker dtpSeekTime;
        public System.Windows.Forms.DataGridView dgvDataSources;
        private System.Windows.Forms.DataGridViewImageColumn colStatus;
        private System.Windows.Forms.DataGridViewTextBoxColumn colName;
        private System.Windows.Forms.DataGridViewTextBoxColumn colNumber;
        public System.Windows.Forms.Button btnManualRecord;
        private System.Windows.Forms.NumericUpDown nudPostRecord;
        private System.Windows.Forms.Label lblPostRecord;
        private System.Windows.Forms.NumericUpDown nudPreRecord;
        private System.Windows.Forms.Label lblPreRecord;
        private System.Windows.Forms.ToolStripMenuItem alarmInputsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem relayOutputsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem modifyLoggingPathToolStripMenuItem;
    }
}

