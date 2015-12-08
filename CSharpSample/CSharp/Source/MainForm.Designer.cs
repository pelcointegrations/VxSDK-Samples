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
            this.btnPlay = new System.Windows.Forms.Button();
            this.lvDevices = new System.Windows.Forms.ListView();
            this.colHeadName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colHeadIp = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.panelVideoStreamLeft = new System.Windows.Forms.Panel();
            this.btnPause = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.lblTimeStampLeft = new System.Windows.Forms.Label();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.connectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.showLogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportManagerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.eventsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.subscribeToSystemEventsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.insertSystemEventToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.situationsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.situationManagerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ptzToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.showPTZControlsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.streamsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.streamProtocolToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rtspToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mjpegToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnSeek = new System.Windows.Forms.Button();
            this.btnLive = new System.Windows.Forms.Button();
            this.lblSpeed = new System.Windows.Forms.Label();
            this.nudSpeed = new System.Windows.Forms.NumericUpDown();
            this.scInner = new System.Windows.Forms.SplitContainer();
            this.lblTimeStampRight = new System.Windows.Forms.Label();
            this.scVideoPanels = new System.Windows.Forms.SplitContainer();
            this.panelVideoStreamRight = new System.Windows.Forms.Panel();
            this.scOuter = new System.Windows.Forms.SplitContainer();
            this.txbxLog = new System.Windows.Forms.TextBox();
            this.menuStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudSpeed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.scInner)).BeginInit();
            this.scInner.Panel1.SuspendLayout();
            this.scInner.Panel2.SuspendLayout();
            this.scInner.SuspendLayout();
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
            this.btnPlay.Location = new System.Drawing.Point(647, 366);
            this.btnPlay.Name = "btnPlay";
            this.btnPlay.Size = new System.Drawing.Size(45, 23);
            this.btnPlay.TabIndex = 14;
            this.btnPlay.Text = "Play";
            this.btnPlay.UseVisualStyleBackColor = true;
            this.btnPlay.Click += new System.EventHandler(this.ButtonPlay_Click);
            // 
            // lvDevices
            // 
            this.lvDevices.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lvDevices.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colHeadName,
            this.colHeadIp});
            this.lvDevices.FullRowSelect = true;
            this.lvDevices.HideSelection = false;
            this.lvDevices.Location = new System.Drawing.Point(3, 3);
            this.lvDevices.MultiSelect = false;
            this.lvDevices.Name = "lvDevices";
            this.lvDevices.Size = new System.Drawing.Size(360, 388);
            this.lvDevices.TabIndex = 1;
            this.lvDevices.UseCompatibleStateImageBehavior = false;
            this.lvDevices.View = System.Windows.Forms.View.Details;
            // 
            // colHeadName
            // 
            this.colHeadName.Text = "Name";
            this.colHeadName.Width = 237;
            // 
            // colHeadIp
            // 
            this.colHeadIp.Text = "IP";
            this.colHeadIp.Width = 100;
            // 
            // panelVideoStreamLeft
            // 
            this.panelVideoStreamLeft.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panelVideoStreamLeft.BackColor = System.Drawing.SystemColors.WindowText;
            this.panelVideoStreamLeft.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.panelVideoStreamLeft.Location = new System.Drawing.Point(3, 3);
            this.panelVideoStreamLeft.Name = "panelVideoStreamLeft";
            this.panelVideoStreamLeft.Size = new System.Drawing.Size(584, 353);
            this.panelVideoStreamLeft.TabIndex = 2;
            this.panelVideoStreamLeft.MouseClick += new System.Windows.Forms.MouseEventHandler(this.PanelVideoStreamLeft_MouseClick);
            // 
            // btnPause
            // 
            this.btnPause.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnPause.Enabled = false;
            this.btnPause.Location = new System.Drawing.Point(545, 366);
            this.btnPause.Name = "btnPause";
            this.btnPause.Size = new System.Drawing.Size(45, 23);
            this.btnPause.TabIndex = 2;
            this.btnPause.Text = "Pause";
            this.btnPause.UseVisualStyleBackColor = true;
            this.btnPause.Click += new System.EventHandler(this.ButtonPause_Click);
            // 
            // btnStop
            // 
            this.btnStop.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnStop.Enabled = false;
            this.btnStop.Location = new System.Drawing.Point(596, 366);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(45, 23);
            this.btnStop.TabIndex = 4;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.ButtonStop_Click);
            // 
            // lblTimeStampLeft
            // 
            this.lblTimeStampLeft.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblTimeStampLeft.Location = new System.Drawing.Point(3, 364);
            this.lblTimeStampLeft.Name = "lblTimeStampLeft";
            this.lblTimeStampLeft.Size = new System.Drawing.Size(125, 25);
            this.lblTimeStampLeft.TabIndex = 11;
            // 
            // menuStrip
            // 
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.exportToolStripMenuItem,
            this.eventsToolStripMenuItem,
            this.situationsToolStripMenuItem,
            this.ptzToolStripMenuItem,
            this.streamsToolStripMenuItem});
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
            this.showLogToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // connectToolStripMenuItem
            // 
            this.connectToolStripMenuItem.Name = "connectToolStripMenuItem";
            this.connectToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.connectToolStripMenuItem.Text = "Connect";
            this.connectToolStripMenuItem.Click += new System.EventHandler(this.MenuItemConnect_Click);
            // 
            // showLogToolStripMenuItem
            // 
            this.showLogToolStripMenuItem.Name = "showLogToolStripMenuItem";
            this.showLogToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.showLogToolStripMenuItem.Text = "Show Log";
            this.showLogToolStripMenuItem.Click += new System.EventHandler(this.MenuItemLog_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.MenuItemExit_Click);
            // 
            // exportToolStripMenuItem
            // 
            this.exportToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exportManagerToolStripMenuItem});
            this.exportToolStripMenuItem.Enabled = false;
            this.exportToolStripMenuItem.Name = "exportToolStripMenuItem";
            this.exportToolStripMenuItem.Size = new System.Drawing.Size(57, 20);
            this.exportToolStripMenuItem.Text = "Exports";
            // 
            // exportManagerToolStripMenuItem
            // 
            this.exportManagerToolStripMenuItem.Name = "exportManagerToolStripMenuItem";
            this.exportManagerToolStripMenuItem.Size = new System.Drawing.Size(157, 22);
            this.exportManagerToolStripMenuItem.Text = "Export Manager";
            this.exportManagerToolStripMenuItem.Click += new System.EventHandler(this.MenuItemExportManager_Click);
            // 
            // eventsToolStripMenuItem
            // 
            this.eventsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.subscribeToSystemEventsToolStripMenuItem,
            this.insertSystemEventToolStripMenuItem});
            this.eventsToolStripMenuItem.Enabled = false;
            this.eventsToolStripMenuItem.Name = "eventsToolStripMenuItem";
            this.eventsToolStripMenuItem.Size = new System.Drawing.Size(53, 20);
            this.eventsToolStripMenuItem.Text = "Events";
            // 
            // subscribeToSystemEventsToolStripMenuItem
            // 
            this.subscribeToSystemEventsToolStripMenuItem.Name = "subscribeToSystemEventsToolStripMenuItem";
            this.subscribeToSystemEventsToolStripMenuItem.Size = new System.Drawing.Size(217, 22);
            this.subscribeToSystemEventsToolStripMenuItem.Text = "Subscribe to System Events";
            this.subscribeToSystemEventsToolStripMenuItem.Click += new System.EventHandler(this.MenuItemSubscribe_Click);
            // 
            // insertSystemEventToolStripMenuItem
            // 
            this.insertSystemEventToolStripMenuItem.Name = "insertSystemEventToolStripMenuItem";
            this.insertSystemEventToolStripMenuItem.Size = new System.Drawing.Size(217, 22);
            this.insertSystemEventToolStripMenuItem.Text = "Insert System Event";
            this.insertSystemEventToolStripMenuItem.Click += new System.EventHandler(this.MenuItemInsertEvent_Click);
            // 
            // situationsToolStripMenuItem
            // 
            this.situationsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.situationManagerToolStripMenuItem});
            this.situationsToolStripMenuItem.Enabled = false;
            this.situationsToolStripMenuItem.Name = "situationsToolStripMenuItem";
            this.situationsToolStripMenuItem.Size = new System.Drawing.Size(71, 20);
            this.situationsToolStripMenuItem.Text = "Situations";
            // 
            // situationManagerToolStripMenuItem
            // 
            this.situationManagerToolStripMenuItem.Name = "situationManagerToolStripMenuItem";
            this.situationManagerToolStripMenuItem.Size = new System.Drawing.Size(171, 22);
            this.situationManagerToolStripMenuItem.Text = "Situation Manager";
            this.situationManagerToolStripMenuItem.Click += new System.EventHandler(this.MenuItemSituationManager_Click);
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
            // btnSeek
            // 
            this.btnSeek.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnSeek.Enabled = false;
            this.btnSeek.Location = new System.Drawing.Point(494, 366);
            this.btnSeek.Name = "btnSeek";
            this.btnSeek.Size = new System.Drawing.Size(45, 23);
            this.btnSeek.TabIndex = 36;
            this.btnSeek.Text = "Seek";
            this.btnSeek.UseVisualStyleBackColor = true;
            this.btnSeek.Click += new System.EventHandler(this.ButtonSeek_Click);
            // 
            // btnLive
            // 
            this.btnLive.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnLive.Enabled = false;
            this.btnLive.Location = new System.Drawing.Point(443, 366);
            this.btnLive.Name = "btnLive";
            this.btnLive.Size = new System.Drawing.Size(45, 23);
            this.btnLive.TabIndex = 37;
            this.btnLive.Text = "Live";
            this.btnLive.UseVisualStyleBackColor = true;
            this.btnLive.Click += new System.EventHandler(this.ButtonLive_Click);
            // 
            // lblSpeed
            // 
            this.lblSpeed.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblSpeed.AutoSize = true;
            this.lblSpeed.Location = new System.Drawing.Point(698, 370);
            this.lblSpeed.Name = "lblSpeed";
            this.lblSpeed.Size = new System.Drawing.Size(38, 13);
            this.lblSpeed.TabIndex = 38;
            this.lblSpeed.Text = "Speed";
            // 
            // nudSpeed
            // 
            this.nudSpeed.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.nudSpeed.Location = new System.Drawing.Point(737, 367);
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
            this.scInner.Panel1.Controls.Add(this.lvDevices);
            // 
            // scInner.Panel2
            // 
            this.scInner.Panel2.Controls.Add(this.lblTimeStampRight);
            this.scInner.Panel2.Controls.Add(this.scVideoPanels);
            this.scInner.Panel2.Controls.Add(this.lblTimeStampLeft);
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
            // lblTimeStampRight
            // 
            this.lblTimeStampRight.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.lblTimeStampRight.Location = new System.Drawing.Point(1058, 364);
            this.lblTimeStampRight.Name = "lblTimeStampRight";
            this.lblTimeStampRight.Size = new System.Drawing.Size(125, 25);
            this.lblTimeStampRight.TabIndex = 44;
            this.lblTimeStampRight.TextAlign = System.Drawing.ContentAlignment.TopRight;
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
            this.panelVideoStreamRight.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.panelVideoStreamRight.Location = new System.Drawing.Point(5, 3);
            this.panelVideoStreamRight.Name = "panelVideoStreamRight";
            this.panelVideoStreamRight.Size = new System.Drawing.Size(581, 353);
            this.panelVideoStreamRight.TabIndex = 3;
            this.panelVideoStreamRight.MouseClick += new System.Windows.Forms.MouseEventHandler(this.PanelVideoStreamRight_MouseClick);
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

        private System.Windows.Forms.ColumnHeader colHeadName;
        private System.Windows.Forms.ColumnHeader colHeadIp;

        public System.Windows.Forms.Panel panelVideoStreamLeft;

        public System.Windows.Forms.Label lblTimeStampLeft;
        public System.Windows.Forms.ListView lvDevices;
        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem connectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportManagerToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem subscribeToSystemEventsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem showPTZControlsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem streamsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem streamProtocolToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rtspToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mjpegToolStripMenuItem;
        public System.Windows.Forms.Button btnPlay;
        public System.Windows.Forms.Button btnPause;
        public System.Windows.Forms.Button btnStop;
        public System.Windows.Forms.ToolStripMenuItem exportToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem eventsToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem ptzToolStripMenuItem;
        public System.Windows.Forms.Button btnSeek;
        public System.Windows.Forms.Button btnLive;
        private System.Windows.Forms.Label lblSpeed;
        private System.Windows.Forms.NumericUpDown nudSpeed;
        private System.Windows.Forms.SplitContainer scInner;
        private System.Windows.Forms.ToolStripMenuItem insertSystemEventToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem situationsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem situationManagerToolStripMenuItem;
        private System.Windows.Forms.SplitContainer scOuter;
        public System.Windows.Forms.TextBox txbxLog;

        public System.Windows.Forms.Panel panelVideoStreamRight;

        public System.Windows.Forms.SplitContainer scVideoPanels;

        public System.Windows.Forms.Label lblTimeStampRight;
        private System.Windows.Forms.ToolStripMenuItem showLogToolStripMenuItem;
    }
}

