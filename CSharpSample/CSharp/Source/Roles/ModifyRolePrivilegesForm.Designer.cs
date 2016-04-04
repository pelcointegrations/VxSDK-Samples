namespace SDKSampleApp.Source
{
    using System.Windows.Forms;

    partial class ModifyRolePrivilegesForm
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
            this.lblViewVideoSources = new System.Windows.Forms.Label();
            this.lblLaunchSavedViews = new System.Windows.Forms.Label();
            this.lblCreateBookmarks = new System.Windows.Forms.Label();
            this.lblDeleteBookmarks = new System.Windows.Forms.Label();
            this.lblUsePtz = new System.Windows.Forms.Label();
            this.lblSurveillance = new System.Windows.Forms.Label();
            this.tlpLeft = new System.Windows.Forms.TableLayoutPanel();
            this.cbxLockPtzMode = new System.Windows.Forms.ComboBox();
            this.cbxUsePtzMode = new System.Windows.Forms.ComboBox();
            this.cbxDeleteSystemBookmarks = new System.Windows.Forms.ComboBox();
            this.cbxCreateSystemBookmarks = new System.Windows.Forms.ComboBox();
            this.lblLockPtz = new System.Windows.Forms.Label();
            this.lblConfigureRecording = new System.Windows.Forms.Label();
            this.lblSystemManagement = new System.Windows.Forms.Label();
            this.lblInvestigation = new System.Windows.Forms.Label();
            this.lblViewRecordedVideo = new System.Windows.Forms.Label();
            this.lblExport = new System.Windows.Forms.Label();
            this.lblDeleteExports = new System.Windows.Forms.Label();
            this.lblPlugIns = new System.Windows.Forms.Label();
            this.lblUseMaps = new System.Windows.Forms.Label();
            this.lblViewMaps = new System.Windows.Forms.Label();
            this.lblManageMaps = new System.Windows.Forms.Label();
            this.cbxConfigureRecording = new System.Windows.Forms.ComboBox();
            this.lblPlaceCamerasOnMaps = new System.Windows.Forms.Label();
            this.cbxViewVideoSources = new System.Windows.Forms.ComboBox();
            this.cbxLaunchSavedViewsRemotely = new System.Windows.Forms.ComboBox();
            this.cbxExportMediaClips = new System.Windows.Forms.ComboBox();
            this.cbxViewRecordedVideo = new System.Windows.Forms.ComboBox();
            this.cbxDeleteExports = new System.Windows.Forms.ComboBox();
            this.cbxUseMap = new System.Windows.Forms.ComboBox();
            this.cbxManageMapFiles = new System.Windows.Forms.ComboBox();
            this.cbxViewMaps = new System.Windows.Forms.ComboBox();
            this.cbxPlaceCamerasOnMap = new System.Windows.Forms.ComboBox();
            this.btnViewVideoSources = new System.Windows.Forms.Button();
            this.btnCreateSystemBookmarks = new System.Windows.Forms.Button();
            this.btnDeleteSystemBookmarks = new System.Windows.Forms.Button();
            this.btnUsePtzMode = new System.Windows.Forms.Button();
            this.btnLockPtzMode = new System.Windows.Forms.Button();
            this.btnViewRecordedVideo = new System.Windows.Forms.Button();
            this.lblResourceAccessLeft = new System.Windows.Forms.Label();
            this.lblPriorityLeft = new System.Windows.Forms.Label();
            this.priViewVideoSources = new System.Windows.Forms.Button();
            this.priLaunchSavedViewsRemotely = new System.Windows.Forms.Button();
            this.priCreateSystemBookmarks = new System.Windows.Forms.Button();
            this.priDeleteSystemBookmarks = new System.Windows.Forms.Button();
            this.priUsePtzMode = new System.Windows.Forms.Button();
            this.priLockPtzMode = new System.Windows.Forms.Button();
            this.priViewRecordedVideo = new System.Windows.Forms.Button();
            this.priExportMediaClips = new System.Windows.Forms.Button();
            this.priDeleteExports = new System.Windows.Forms.Button();
            this.priUseMap = new System.Windows.Forms.Button();
            this.priViewMaps = new System.Windows.Forms.Button();
            this.priManageMapFiles = new System.Windows.Forms.Button();
            this.priPlaceCamerasOnMap = new System.Windows.Forms.Button();
            this.priConfigureRecording = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.tlpRight = new System.Windows.Forms.TableLayoutPanel();
            this.lblAuditUserActivity = new System.Windows.Forms.Label();
            this.lblAccessUserViews = new System.Windows.Forms.Label();
            this.lblManageViews = new System.Windows.Forms.Label();
            this.lblEventManagement = new System.Windows.Forms.Label();
            this.lblHandleEvents = new System.Windows.Forms.Label();
            this.lblConfigureEvents = new System.Windows.Forms.Label();
            this.lblViewEventHistory = new System.Windows.Forms.Label();
            this.lblUserManagement = new System.Windows.Forms.Label();
            this.lblManageUserAccounts = new System.Windows.Forms.Label();
            this.lblManageAggregator = new System.Windows.Forms.Label();
            this.lblAssignRoles = new System.Windows.Forms.Label();
            this.lblManageRoles = new System.Windows.Forms.Label();
            this.lblDeviceManagement = new System.Windows.Forms.Label();
            this.lblConfigureMonitorWall = new System.Windows.Forms.Label();
            this.lblSetupEdgeDevices = new System.Windows.Forms.Label();
            this.lblManageTags = new System.Windows.Forms.Label();
            this.cbxAuditUserActivity = new System.Windows.Forms.ComboBox();
            this.cbxAccessUserViews = new System.Windows.Forms.ComboBox();
            this.cbxManageSystemViews = new System.Windows.Forms.ComboBox();
            this.cbxHandleEvents = new System.Windows.Forms.ComboBox();
            this.cbxConfigureEvents = new System.Windows.Forms.ComboBox();
            this.cbxViewEventHistory = new System.Windows.Forms.ComboBox();
            this.cbxManageUserAccounts = new System.Windows.Forms.ComboBox();
            this.cbxManageAggregatorAccount = new System.Windows.Forms.ComboBox();
            this.cbxAssignRolesToUsers = new System.Windows.Forms.ComboBox();
            this.cbxManageRoles = new System.Windows.Forms.ComboBox();
            this.cbxConfigureMonitorWallDecoders = new System.Windows.Forms.ComboBox();
            this.cbxSetupEdgeDevices = new System.Windows.Forms.ComboBox();
            this.cbxManageSystemTags = new System.Windows.Forms.ComboBox();
            this.btnAccessUserViews = new System.Windows.Forms.Button();
            this.btnManageUserAccounts = new System.Windows.Forms.Button();
            this.btnSetupEdgeDevices = new System.Windows.Forms.Button();
            this.lblPriorityRight = new System.Windows.Forms.Label();
            this.lblResourceAccessRight = new System.Windows.Forms.Label();
            this.lblSupervisionAndReports = new System.Windows.Forms.Label();
            this.priAuditUserActivity = new System.Windows.Forms.Button();
            this.priAccessUserViews = new System.Windows.Forms.Button();
            this.priManageSystemViews = new System.Windows.Forms.Button();
            this.priHandleEvents = new System.Windows.Forms.Button();
            this.priConfigureEvents = new System.Windows.Forms.Button();
            this.priViewEventHistory = new System.Windows.Forms.Button();
            this.priManageUserAccounts = new System.Windows.Forms.Button();
            this.priManageAggregatorAccount = new System.Windows.Forms.Button();
            this.priAssignRolesToUsers = new System.Windows.Forms.Button();
            this.priManageRoles = new System.Windows.Forms.Button();
            this.priConfigureMonitorWallDecoders = new System.Windows.Forms.Button();
            this.priSetupEdgeDevices = new System.Windows.Forms.Button();
            this.priManageSystemTags = new System.Windows.Forms.Button();
            this.tlpLeft.SuspendLayout();
            this.tlpRight.SuspendLayout();
            this.SuspendLayout();
            // 
            // lblViewVideoSources
            // 
            this.lblViewVideoSources.AutoSize = true;
            this.lblViewVideoSources.BackColor = System.Drawing.Color.Transparent;
            this.lblViewVideoSources.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblViewVideoSources.Location = new System.Drawing.Point(3, 25);
            this.lblViewVideoSources.Name = "lblViewVideoSources";
            this.lblViewVideoSources.Size = new System.Drawing.Size(174, 25);
            this.lblViewVideoSources.TabIndex = 0;
            this.lblViewVideoSources.Text = "  View Video Sources";
            this.lblViewVideoSources.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblLaunchSavedViews
            // 
            this.lblLaunchSavedViews.AutoSize = true;
            this.lblLaunchSavedViews.BackColor = System.Drawing.Color.Transparent;
            this.lblLaunchSavedViews.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblLaunchSavedViews.Location = new System.Drawing.Point(3, 50);
            this.lblLaunchSavedViews.Name = "lblLaunchSavedViews";
            this.lblLaunchSavedViews.Size = new System.Drawing.Size(174, 25);
            this.lblLaunchSavedViews.TabIndex = 1;
            this.lblLaunchSavedViews.Text = "    Launch Saved Views Remotely";
            this.lblLaunchSavedViews.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblCreateBookmarks
            // 
            this.lblCreateBookmarks.AutoSize = true;
            this.lblCreateBookmarks.BackColor = System.Drawing.Color.Transparent;
            this.lblCreateBookmarks.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCreateBookmarks.Location = new System.Drawing.Point(3, 75);
            this.lblCreateBookmarks.Name = "lblCreateBookmarks";
            this.lblCreateBookmarks.Size = new System.Drawing.Size(174, 25);
            this.lblCreateBookmarks.TabIndex = 2;
            this.lblCreateBookmarks.Text = "    Create System Bookmarks";
            this.lblCreateBookmarks.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblDeleteBookmarks
            // 
            this.lblDeleteBookmarks.AutoSize = true;
            this.lblDeleteBookmarks.BackColor = System.Drawing.Color.Transparent;
            this.lblDeleteBookmarks.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblDeleteBookmarks.Location = new System.Drawing.Point(3, 100);
            this.lblDeleteBookmarks.Name = "lblDeleteBookmarks";
            this.lblDeleteBookmarks.Size = new System.Drawing.Size(174, 25);
            this.lblDeleteBookmarks.TabIndex = 3;
            this.lblDeleteBookmarks.Text = "      Delete System Bookmarks";
            this.lblDeleteBookmarks.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblUsePtz
            // 
            this.lblUsePtz.AutoSize = true;
            this.lblUsePtz.BackColor = System.Drawing.Color.Transparent;
            this.lblUsePtz.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblUsePtz.Location = new System.Drawing.Point(3, 125);
            this.lblUsePtz.Name = "lblUsePtz";
            this.lblUsePtz.Size = new System.Drawing.Size(174, 25);
            this.lblUsePtz.TabIndex = 6;
            this.lblUsePtz.Text = "    Use PTZ Mode";
            this.lblUsePtz.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblSurveillance
            // 
            this.lblSurveillance.AutoSize = true;
            this.lblSurveillance.BackColor = System.Drawing.Color.Transparent;
            this.lblSurveillance.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblSurveillance.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSurveillance.Location = new System.Drawing.Point(3, 0);
            this.lblSurveillance.Name = "lblSurveillance";
            this.lblSurveillance.Size = new System.Drawing.Size(174, 25);
            this.lblSurveillance.TabIndex = 7;
            this.lblSurveillance.Text = "Surveillance";
            this.lblSurveillance.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // tlpLeft
            // 
            this.tlpLeft.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.tlpLeft.ColumnCount = 6;
            this.tlpLeft.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 180F));
            this.tlpLeft.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 130F));
            this.tlpLeft.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 100F));
            this.tlpLeft.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tlpLeft.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 60F));
            this.tlpLeft.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 5F));
            this.tlpLeft.Controls.Add(this.cbxLockPtzMode, 1, 6);
            this.tlpLeft.Controls.Add(this.cbxUsePtzMode, 1, 5);
            this.tlpLeft.Controls.Add(this.cbxDeleteSystemBookmarks, 1, 4);
            this.tlpLeft.Controls.Add(this.cbxCreateSystemBookmarks, 1, 3);
            this.tlpLeft.Controls.Add(this.lblSurveillance, 0, 0);
            this.tlpLeft.Controls.Add(this.lblLockPtz, 0, 6);
            this.tlpLeft.Controls.Add(this.lblUsePtz, 0, 5);
            this.tlpLeft.Controls.Add(this.lblViewVideoSources, 0, 1);
            this.tlpLeft.Controls.Add(this.lblConfigureRecording, 0, 17);
            this.tlpLeft.Controls.Add(this.lblSystemManagement, 0, 16);
            this.tlpLeft.Controls.Add(this.lblLaunchSavedViews, 0, 2);
            this.tlpLeft.Controls.Add(this.lblCreateBookmarks, 0, 3);
            this.tlpLeft.Controls.Add(this.lblDeleteBookmarks, 0, 4);
            this.tlpLeft.Controls.Add(this.lblInvestigation, 0, 7);
            this.tlpLeft.Controls.Add(this.lblViewRecordedVideo, 0, 8);
            this.tlpLeft.Controls.Add(this.lblExport, 0, 9);
            this.tlpLeft.Controls.Add(this.lblDeleteExports, 0, 10);
            this.tlpLeft.Controls.Add(this.lblPlugIns, 0, 11);
            this.tlpLeft.Controls.Add(this.lblUseMaps, 0, 12);
            this.tlpLeft.Controls.Add(this.lblViewMaps, 0, 13);
            this.tlpLeft.Controls.Add(this.lblManageMaps, 0, 14);
            this.tlpLeft.Controls.Add(this.cbxConfigureRecording, 1, 17);
            this.tlpLeft.Controls.Add(this.lblPlaceCamerasOnMaps, 0, 15);
            this.tlpLeft.Controls.Add(this.cbxViewVideoSources, 1, 1);
            this.tlpLeft.Controls.Add(this.cbxLaunchSavedViewsRemotely, 1, 2);
            this.tlpLeft.Controls.Add(this.cbxExportMediaClips, 1, 9);
            this.tlpLeft.Controls.Add(this.cbxViewRecordedVideo, 1, 8);
            this.tlpLeft.Controls.Add(this.cbxDeleteExports, 1, 10);
            this.tlpLeft.Controls.Add(this.cbxUseMap, 1, 12);
            this.tlpLeft.Controls.Add(this.cbxManageMapFiles, 1, 14);
            this.tlpLeft.Controls.Add(this.cbxViewMaps, 1, 13);
            this.tlpLeft.Controls.Add(this.cbxPlaceCamerasOnMap, 1, 15);
            this.tlpLeft.Controls.Add(this.btnViewVideoSources, 2, 1);
            this.tlpLeft.Controls.Add(this.btnCreateSystemBookmarks, 2, 3);
            this.tlpLeft.Controls.Add(this.btnDeleteSystemBookmarks, 2, 4);
            this.tlpLeft.Controls.Add(this.btnUsePtzMode, 2, 5);
            this.tlpLeft.Controls.Add(this.btnLockPtzMode, 2, 6);
            this.tlpLeft.Controls.Add(this.btnViewRecordedVideo, 2, 8);
            this.tlpLeft.Controls.Add(this.lblResourceAccessLeft, 1, 0);
            this.tlpLeft.Controls.Add(this.lblPriorityLeft, 4, 0);
            this.tlpLeft.Controls.Add(this.priViewVideoSources, 4, 1);
            this.tlpLeft.Controls.Add(this.priLaunchSavedViewsRemotely, 4, 2);
            this.tlpLeft.Controls.Add(this.priCreateSystemBookmarks, 4, 3);
            this.tlpLeft.Controls.Add(this.priDeleteSystemBookmarks, 4, 4);
            this.tlpLeft.Controls.Add(this.priUsePtzMode, 4, 5);
            this.tlpLeft.Controls.Add(this.priLockPtzMode, 4, 6);
            this.tlpLeft.Controls.Add(this.priViewRecordedVideo, 4, 8);
            this.tlpLeft.Controls.Add(this.priExportMediaClips, 4, 9);
            this.tlpLeft.Controls.Add(this.priDeleteExports, 4, 10);
            this.tlpLeft.Controls.Add(this.priUseMap, 4, 12);
            this.tlpLeft.Controls.Add(this.priViewMaps, 4, 13);
            this.tlpLeft.Controls.Add(this.priManageMapFiles, 4, 14);
            this.tlpLeft.Controls.Add(this.priPlaceCamerasOnMap, 4, 15);
            this.tlpLeft.Controls.Add(this.priConfigureRecording, 4, 17);
            this.tlpLeft.Location = new System.Drawing.Point(12, 12);
            this.tlpLeft.Name = "tlpLeft";
            this.tlpLeft.RowCount = 18;
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tlpLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tlpLeft.Size = new System.Drawing.Size(494, 449);
            this.tlpLeft.TabIndex = 8;
            // 
            // cbxLockPtzMode
            // 
            this.cbxLockPtzMode.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxLockPtzMode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxLockPtzMode.Enabled = false;
            this.cbxLockPtzMode.FormattingEnabled = true;
            this.cbxLockPtzMode.Items.AddRange(new object[] {
            "None",
            "Any Camera",
            "Selected Cameras"});
            this.cbxLockPtzMode.Location = new System.Drawing.Point(183, 153);
            this.cbxLockPtzMode.Name = "cbxLockPtzMode";
            this.cbxLockPtzMode.Size = new System.Drawing.Size(124, 21);
            this.cbxLockPtzMode.TabIndex = 54;
            this.cbxLockPtzMode.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxLockPtzMode.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxUsePtzMode
            // 
            this.cbxUsePtzMode.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxUsePtzMode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxUsePtzMode.Enabled = false;
            this.cbxUsePtzMode.FormattingEnabled = true;
            this.cbxUsePtzMode.Items.AddRange(new object[] {
            "None",
            "Any Camera",
            "Selected Cameras"});
            this.cbxUsePtzMode.Location = new System.Drawing.Point(183, 128);
            this.cbxUsePtzMode.Name = "cbxUsePtzMode";
            this.cbxUsePtzMode.Size = new System.Drawing.Size(124, 21);
            this.cbxUsePtzMode.TabIndex = 51;
            this.cbxUsePtzMode.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxUsePtzMode.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxDeleteSystemBookmarks
            // 
            this.cbxDeleteSystemBookmarks.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxDeleteSystemBookmarks.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxDeleteSystemBookmarks.Enabled = false;
            this.cbxDeleteSystemBookmarks.FormattingEnabled = true;
            this.cbxDeleteSystemBookmarks.Items.AddRange(new object[] {
            "None",
            "Any Camera",
            "Selected Cameras"});
            this.cbxDeleteSystemBookmarks.Location = new System.Drawing.Point(183, 103);
            this.cbxDeleteSystemBookmarks.Name = "cbxDeleteSystemBookmarks";
            this.cbxDeleteSystemBookmarks.Size = new System.Drawing.Size(124, 21);
            this.cbxDeleteSystemBookmarks.TabIndex = 48;
            this.cbxDeleteSystemBookmarks.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxDeleteSystemBookmarks.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxCreateSystemBookmarks
            // 
            this.cbxCreateSystemBookmarks.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxCreateSystemBookmarks.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxCreateSystemBookmarks.Enabled = false;
            this.cbxCreateSystemBookmarks.FormattingEnabled = true;
            this.cbxCreateSystemBookmarks.Items.AddRange(new object[] {
            "None",
            "Any Camera",
            "Selected Cameras"});
            this.cbxCreateSystemBookmarks.Location = new System.Drawing.Point(183, 78);
            this.cbxCreateSystemBookmarks.Name = "cbxCreateSystemBookmarks";
            this.cbxCreateSystemBookmarks.Size = new System.Drawing.Size(124, 21);
            this.cbxCreateSystemBookmarks.TabIndex = 45;
            this.cbxCreateSystemBookmarks.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxCreateSystemBookmarks.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // lblLockPtz
            // 
            this.lblLockPtz.AutoSize = true;
            this.lblLockPtz.BackColor = System.Drawing.Color.Transparent;
            this.lblLockPtz.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblLockPtz.Location = new System.Drawing.Point(3, 150);
            this.lblLockPtz.Name = "lblLockPtz";
            this.lblLockPtz.Size = new System.Drawing.Size(174, 25);
            this.lblLockPtz.TabIndex = 5;
            this.lblLockPtz.Text = "      Lock PTZ Mode";
            this.lblLockPtz.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblConfigureRecording
            // 
            this.lblConfigureRecording.AutoSize = true;
            this.lblConfigureRecording.BackColor = System.Drawing.Color.Transparent;
            this.lblConfigureRecording.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblConfigureRecording.Location = new System.Drawing.Point(3, 420);
            this.lblConfigureRecording.Name = "lblConfigureRecording";
            this.lblConfigureRecording.Size = new System.Drawing.Size(174, 27);
            this.lblConfigureRecording.TabIndex = 35;
            this.lblConfigureRecording.Text = "  Configure Recording";
            this.lblConfigureRecording.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblSystemManagement
            // 
            this.lblSystemManagement.AutoSize = true;
            this.lblSystemManagement.BackColor = System.Drawing.Color.Transparent;
            this.lblSystemManagement.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblSystemManagement.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSystemManagement.Location = new System.Drawing.Point(3, 400);
            this.lblSystemManagement.Name = "lblSystemManagement";
            this.lblSystemManagement.Size = new System.Drawing.Size(174, 20);
            this.lblSystemManagement.TabIndex = 34;
            this.lblSystemManagement.Text = "System Management";
            this.lblSystemManagement.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblInvestigation
            // 
            this.lblInvestigation.AutoSize = true;
            this.lblInvestigation.BackColor = System.Drawing.Color.Transparent;
            this.lblInvestigation.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblInvestigation.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblInvestigation.Location = new System.Drawing.Point(3, 175);
            this.lblInvestigation.Name = "lblInvestigation";
            this.lblInvestigation.Size = new System.Drawing.Size(174, 25);
            this.lblInvestigation.TabIndex = 8;
            this.lblInvestigation.Text = "Investigation";
            this.lblInvestigation.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblViewRecordedVideo
            // 
            this.lblViewRecordedVideo.AutoSize = true;
            this.lblViewRecordedVideo.BackColor = System.Drawing.Color.Transparent;
            this.lblViewRecordedVideo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblViewRecordedVideo.Location = new System.Drawing.Point(3, 200);
            this.lblViewRecordedVideo.Name = "lblViewRecordedVideo";
            this.lblViewRecordedVideo.Size = new System.Drawing.Size(174, 25);
            this.lblViewRecordedVideo.TabIndex = 9;
            this.lblViewRecordedVideo.Text = "  View Recorded Video";
            this.lblViewRecordedVideo.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblExport
            // 
            this.lblExport.AutoSize = true;
            this.lblExport.BackColor = System.Drawing.Color.Transparent;
            this.lblExport.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblExport.Location = new System.Drawing.Point(3, 225);
            this.lblExport.Name = "lblExport";
            this.lblExport.Size = new System.Drawing.Size(174, 25);
            this.lblExport.TabIndex = 10;
            this.lblExport.Text = "    Export Media Clips";
            this.lblExport.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblDeleteExports
            // 
            this.lblDeleteExports.AutoSize = true;
            this.lblDeleteExports.BackColor = System.Drawing.Color.Transparent;
            this.lblDeleteExports.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblDeleteExports.Location = new System.Drawing.Point(3, 250);
            this.lblDeleteExports.Name = "lblDeleteExports";
            this.lblDeleteExports.Size = new System.Drawing.Size(174, 25);
            this.lblDeleteExports.TabIndex = 11;
            this.lblDeleteExports.Text = "      Delete Exports";
            this.lblDeleteExports.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblPlugIns
            // 
            this.lblPlugIns.AutoSize = true;
            this.lblPlugIns.BackColor = System.Drawing.Color.Transparent;
            this.lblPlugIns.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblPlugIns.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPlugIns.Location = new System.Drawing.Point(3, 275);
            this.lblPlugIns.Name = "lblPlugIns";
            this.lblPlugIns.Size = new System.Drawing.Size(174, 25);
            this.lblPlugIns.TabIndex = 12;
            this.lblPlugIns.Text = "Plug-Ins";
            this.lblPlugIns.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblUseMaps
            // 
            this.lblUseMaps.AutoSize = true;
            this.lblUseMaps.BackColor = System.Drawing.Color.Transparent;
            this.lblUseMaps.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblUseMaps.Location = new System.Drawing.Point(3, 300);
            this.lblUseMaps.Name = "lblUseMaps";
            this.lblUseMaps.Size = new System.Drawing.Size(174, 25);
            this.lblUseMaps.TabIndex = 13;
            this.lblUseMaps.Text = "  Use Map";
            this.lblUseMaps.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblViewMaps
            // 
            this.lblViewMaps.AutoSize = true;
            this.lblViewMaps.BackColor = System.Drawing.Color.Transparent;
            this.lblViewMaps.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblViewMaps.Location = new System.Drawing.Point(3, 325);
            this.lblViewMaps.Name = "lblViewMaps";
            this.lblViewMaps.Size = new System.Drawing.Size(174, 25);
            this.lblViewMaps.TabIndex = 16;
            this.lblViewMaps.Text = "    View Maps";
            this.lblViewMaps.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblManageMaps
            // 
            this.lblManageMaps.AutoSize = true;
            this.lblManageMaps.BackColor = System.Drawing.Color.Transparent;
            this.lblManageMaps.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblManageMaps.Location = new System.Drawing.Point(3, 350);
            this.lblManageMaps.Name = "lblManageMaps";
            this.lblManageMaps.Size = new System.Drawing.Size(174, 25);
            this.lblManageMaps.TabIndex = 19;
            this.lblManageMaps.Text = "      Manage Map Files";
            this.lblManageMaps.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cbxConfigureRecording
            // 
            this.cbxConfigureRecording.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxConfigureRecording.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxConfigureRecording.FormattingEnabled = true;
            this.cbxConfigureRecording.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxConfigureRecording.Location = new System.Drawing.Point(183, 423);
            this.cbxConfigureRecording.Name = "cbxConfigureRecording";
            this.cbxConfigureRecording.Size = new System.Drawing.Size(124, 21);
            this.cbxConfigureRecording.TabIndex = 63;
            this.cbxConfigureRecording.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxConfigureRecording.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // lblPlaceCamerasOnMaps
            // 
            this.lblPlaceCamerasOnMaps.AutoSize = true;
            this.lblPlaceCamerasOnMaps.BackColor = System.Drawing.Color.Transparent;
            this.lblPlaceCamerasOnMaps.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblPlaceCamerasOnMaps.Location = new System.Drawing.Point(3, 375);
            this.lblPlaceCamerasOnMaps.Name = "lblPlaceCamerasOnMaps";
            this.lblPlaceCamerasOnMaps.Size = new System.Drawing.Size(174, 25);
            this.lblPlaceCamerasOnMaps.TabIndex = 22;
            this.lblPlaceCamerasOnMaps.Text = "      Place Cameras on Map";
            this.lblPlaceCamerasOnMaps.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cbxViewVideoSources
            // 
            this.cbxViewVideoSources.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxViewVideoSources.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxViewVideoSources.FormattingEnabled = true;
            this.cbxViewVideoSources.Items.AddRange(new object[] {
            "None",
            "Any Camera",
            "Selected Cameras"});
            this.cbxViewVideoSources.Location = new System.Drawing.Point(183, 28);
            this.cbxViewVideoSources.Name = "cbxViewVideoSources";
            this.cbxViewVideoSources.Size = new System.Drawing.Size(124, 21);
            this.cbxViewVideoSources.TabIndex = 36;
            this.cbxViewVideoSources.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxViewVideoSources.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxLaunchSavedViewsRemotely
            // 
            this.cbxLaunchSavedViewsRemotely.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxLaunchSavedViewsRemotely.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxLaunchSavedViewsRemotely.Enabled = false;
            this.cbxLaunchSavedViewsRemotely.FormattingEnabled = true;
            this.cbxLaunchSavedViewsRemotely.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxLaunchSavedViewsRemotely.Location = new System.Drawing.Point(183, 53);
            this.cbxLaunchSavedViewsRemotely.Name = "cbxLaunchSavedViewsRemotely";
            this.cbxLaunchSavedViewsRemotely.Size = new System.Drawing.Size(124, 21);
            this.cbxLaunchSavedViewsRemotely.TabIndex = 37;
            this.cbxLaunchSavedViewsRemotely.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxLaunchSavedViewsRemotely.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxExportMediaClips
            // 
            this.cbxExportMediaClips.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxExportMediaClips.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxExportMediaClips.Enabled = false;
            this.cbxExportMediaClips.FormattingEnabled = true;
            this.cbxExportMediaClips.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxExportMediaClips.Location = new System.Drawing.Point(183, 228);
            this.cbxExportMediaClips.Name = "cbxExportMediaClips";
            this.cbxExportMediaClips.Size = new System.Drawing.Size(124, 21);
            this.cbxExportMediaClips.TabIndex = 38;
            this.cbxExportMediaClips.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxExportMediaClips.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxViewRecordedVideo
            // 
            this.cbxViewRecordedVideo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxViewRecordedVideo.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxViewRecordedVideo.FormattingEnabled = true;
            this.cbxViewRecordedVideo.Items.AddRange(new object[] {
            "None",
            "Any Camera",
            "Selected Cameras"});
            this.cbxViewRecordedVideo.Location = new System.Drawing.Point(183, 203);
            this.cbxViewRecordedVideo.Name = "cbxViewRecordedVideo";
            this.cbxViewRecordedVideo.Size = new System.Drawing.Size(124, 21);
            this.cbxViewRecordedVideo.TabIndex = 55;
            this.cbxViewRecordedVideo.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxViewRecordedVideo.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxDeleteExports
            // 
            this.cbxDeleteExports.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxDeleteExports.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxDeleteExports.Enabled = false;
            this.cbxDeleteExports.FormattingEnabled = true;
            this.cbxDeleteExports.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxDeleteExports.Location = new System.Drawing.Point(183, 253);
            this.cbxDeleteExports.Name = "cbxDeleteExports";
            this.cbxDeleteExports.Size = new System.Drawing.Size(124, 21);
            this.cbxDeleteExports.TabIndex = 39;
            this.cbxDeleteExports.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxDeleteExports.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxUseMap
            // 
            this.cbxUseMap.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxUseMap.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxUseMap.FormattingEnabled = true;
            this.cbxUseMap.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxUseMap.Location = new System.Drawing.Point(183, 303);
            this.cbxUseMap.Name = "cbxUseMap";
            this.cbxUseMap.Size = new System.Drawing.Size(124, 21);
            this.cbxUseMap.TabIndex = 41;
            this.cbxUseMap.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxUseMap.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxManageMapFiles
            // 
            this.cbxManageMapFiles.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxManageMapFiles.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxManageMapFiles.Enabled = false;
            this.cbxManageMapFiles.FormattingEnabled = true;
            this.cbxManageMapFiles.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxManageMapFiles.Location = new System.Drawing.Point(183, 353);
            this.cbxManageMapFiles.Name = "cbxManageMapFiles";
            this.cbxManageMapFiles.Size = new System.Drawing.Size(124, 21);
            this.cbxManageMapFiles.TabIndex = 43;
            this.cbxManageMapFiles.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxManageMapFiles.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxViewMaps
            // 
            this.cbxViewMaps.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxViewMaps.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxViewMaps.Enabled = false;
            this.cbxViewMaps.FormattingEnabled = true;
            this.cbxViewMaps.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxViewMaps.Location = new System.Drawing.Point(183, 328);
            this.cbxViewMaps.Name = "cbxViewMaps";
            this.cbxViewMaps.Size = new System.Drawing.Size(124, 21);
            this.cbxViewMaps.TabIndex = 46;
            this.cbxViewMaps.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxViewMaps.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxPlaceCamerasOnMap
            // 
            this.cbxPlaceCamerasOnMap.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxPlaceCamerasOnMap.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxPlaceCamerasOnMap.Enabled = false;
            this.cbxPlaceCamerasOnMap.FormattingEnabled = true;
            this.cbxPlaceCamerasOnMap.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxPlaceCamerasOnMap.Location = new System.Drawing.Point(183, 378);
            this.cbxPlaceCamerasOnMap.Name = "cbxPlaceCamerasOnMap";
            this.cbxPlaceCamerasOnMap.Size = new System.Drawing.Size(124, 21);
            this.cbxPlaceCamerasOnMap.TabIndex = 49;
            this.cbxPlaceCamerasOnMap.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxPlaceCamerasOnMap.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // btnViewVideoSources
            // 
            this.btnViewVideoSources.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnViewVideoSources.Enabled = false;
            this.btnViewVideoSources.Location = new System.Drawing.Point(332, 28);
            this.btnViewVideoSources.Name = "btnViewVideoSources";
            this.btnViewVideoSources.Size = new System.Drawing.Size(75, 19);
            this.btnViewVideoSources.TabIndex = 64;
            this.btnViewVideoSources.Text = "Select";
            this.btnViewVideoSources.UseVisualStyleBackColor = true;
            this.btnViewVideoSources.Click += new System.EventHandler(this.ButtonSources_Click);
            // 
            // btnCreateSystemBookmarks
            // 
            this.btnCreateSystemBookmarks.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnCreateSystemBookmarks.Enabled = false;
            this.btnCreateSystemBookmarks.Location = new System.Drawing.Point(332, 78);
            this.btnCreateSystemBookmarks.Name = "btnCreateSystemBookmarks";
            this.btnCreateSystemBookmarks.Size = new System.Drawing.Size(75, 19);
            this.btnCreateSystemBookmarks.TabIndex = 65;
            this.btnCreateSystemBookmarks.Text = "Select";
            this.btnCreateSystemBookmarks.UseVisualStyleBackColor = true;
            this.btnCreateSystemBookmarks.Click += new System.EventHandler(this.ButtonSources_Click);
            // 
            // btnDeleteSystemBookmarks
            // 
            this.btnDeleteSystemBookmarks.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnDeleteSystemBookmarks.Enabled = false;
            this.btnDeleteSystemBookmarks.Location = new System.Drawing.Point(332, 103);
            this.btnDeleteSystemBookmarks.Name = "btnDeleteSystemBookmarks";
            this.btnDeleteSystemBookmarks.Size = new System.Drawing.Size(75, 19);
            this.btnDeleteSystemBookmarks.TabIndex = 66;
            this.btnDeleteSystemBookmarks.Text = "Select";
            this.btnDeleteSystemBookmarks.UseVisualStyleBackColor = true;
            this.btnDeleteSystemBookmarks.Click += new System.EventHandler(this.ButtonSources_Click);
            // 
            // btnUsePtzMode
            // 
            this.btnUsePtzMode.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnUsePtzMode.Enabled = false;
            this.btnUsePtzMode.Location = new System.Drawing.Point(332, 128);
            this.btnUsePtzMode.Name = "btnUsePtzMode";
            this.btnUsePtzMode.Size = new System.Drawing.Size(75, 19);
            this.btnUsePtzMode.TabIndex = 67;
            this.btnUsePtzMode.Text = "Select";
            this.btnUsePtzMode.UseVisualStyleBackColor = true;
            this.btnUsePtzMode.Click += new System.EventHandler(this.ButtonSources_Click);
            // 
            // btnLockPtzMode
            // 
            this.btnLockPtzMode.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnLockPtzMode.Enabled = false;
            this.btnLockPtzMode.Location = new System.Drawing.Point(332, 153);
            this.btnLockPtzMode.Name = "btnLockPtzMode";
            this.btnLockPtzMode.Size = new System.Drawing.Size(75, 19);
            this.btnLockPtzMode.TabIndex = 68;
            this.btnLockPtzMode.Text = "Select";
            this.btnLockPtzMode.UseVisualStyleBackColor = true;
            this.btnLockPtzMode.Click += new System.EventHandler(this.ButtonSources_Click);
            // 
            // btnViewRecordedVideo
            // 
            this.btnViewRecordedVideo.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnViewRecordedVideo.Enabled = false;
            this.btnViewRecordedVideo.Location = new System.Drawing.Point(332, 203);
            this.btnViewRecordedVideo.Name = "btnViewRecordedVideo";
            this.btnViewRecordedVideo.Size = new System.Drawing.Size(75, 19);
            this.btnViewRecordedVideo.TabIndex = 69;
            this.btnViewRecordedVideo.Text = "Select";
            this.btnViewRecordedVideo.UseVisualStyleBackColor = true;
            this.btnViewRecordedVideo.Click += new System.EventHandler(this.ButtonSources_Click);
            // 
            // lblResourceAccessLeft
            // 
            this.lblResourceAccessLeft.AutoSize = true;
            this.lblResourceAccessLeft.BackColor = System.Drawing.Color.Transparent;
            this.lblResourceAccessLeft.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblResourceAccessLeft.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblResourceAccessLeft.Location = new System.Drawing.Point(183, 0);
            this.lblResourceAccessLeft.Name = "lblResourceAccessLeft";
            this.lblResourceAccessLeft.Size = new System.Drawing.Size(124, 25);
            this.lblResourceAccessLeft.TabIndex = 100;
            this.lblResourceAccessLeft.Text = "Resource Access";
            this.lblResourceAccessLeft.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblPriorityLeft
            // 
            this.lblPriorityLeft.AutoSize = true;
            this.lblPriorityLeft.BackColor = System.Drawing.Color.Transparent;
            this.lblPriorityLeft.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblPriorityLeft.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPriorityLeft.Location = new System.Drawing.Point(433, 0);
            this.lblPriorityLeft.Name = "lblPriorityLeft";
            this.lblPriorityLeft.Size = new System.Drawing.Size(54, 25);
            this.lblPriorityLeft.TabIndex = 101;
            this.lblPriorityLeft.Text = "Priority";
            this.lblPriorityLeft.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // priViewVideoSources
            // 
            this.priViewVideoSources.Enabled = false;
            this.priViewVideoSources.Location = new System.Drawing.Point(433, 28);
            this.priViewVideoSources.Name = "priViewVideoSources";
            this.priViewVideoSources.Size = new System.Drawing.Size(50, 19);
            this.priViewVideoSources.TabIndex = 102;
            this.priViewVideoSources.Text = "25";
            this.priViewVideoSources.UseVisualStyleBackColor = true;
            this.priViewVideoSources.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priLaunchSavedViewsRemotely
            // 
            this.priLaunchSavedViewsRemotely.Enabled = false;
            this.priLaunchSavedViewsRemotely.Location = new System.Drawing.Point(433, 53);
            this.priLaunchSavedViewsRemotely.Name = "priLaunchSavedViewsRemotely";
            this.priLaunchSavedViewsRemotely.Size = new System.Drawing.Size(50, 19);
            this.priLaunchSavedViewsRemotely.TabIndex = 103;
            this.priLaunchSavedViewsRemotely.Text = "25";
            this.priLaunchSavedViewsRemotely.UseVisualStyleBackColor = true;
            this.priLaunchSavedViewsRemotely.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priCreateSystemBookmarks
            // 
            this.priCreateSystemBookmarks.Enabled = false;
            this.priCreateSystemBookmarks.Location = new System.Drawing.Point(433, 78);
            this.priCreateSystemBookmarks.Name = "priCreateSystemBookmarks";
            this.priCreateSystemBookmarks.Size = new System.Drawing.Size(50, 19);
            this.priCreateSystemBookmarks.TabIndex = 104;
            this.priCreateSystemBookmarks.Text = "25";
            this.priCreateSystemBookmarks.UseVisualStyleBackColor = true;
            this.priCreateSystemBookmarks.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priDeleteSystemBookmarks
            // 
            this.priDeleteSystemBookmarks.Enabled = false;
            this.priDeleteSystemBookmarks.Location = new System.Drawing.Point(433, 103);
            this.priDeleteSystemBookmarks.Name = "priDeleteSystemBookmarks";
            this.priDeleteSystemBookmarks.Size = new System.Drawing.Size(50, 19);
            this.priDeleteSystemBookmarks.TabIndex = 105;
            this.priDeleteSystemBookmarks.Text = "25";
            this.priDeleteSystemBookmarks.UseVisualStyleBackColor = true;
            this.priDeleteSystemBookmarks.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priUsePtzMode
            // 
            this.priUsePtzMode.Enabled = false;
            this.priUsePtzMode.Location = new System.Drawing.Point(433, 128);
            this.priUsePtzMode.Name = "priUsePtzMode";
            this.priUsePtzMode.Size = new System.Drawing.Size(50, 19);
            this.priUsePtzMode.TabIndex = 106;
            this.priUsePtzMode.Text = "25";
            this.priUsePtzMode.UseVisualStyleBackColor = true;
            this.priUsePtzMode.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priLockPtzMode
            // 
            this.priLockPtzMode.Enabled = false;
            this.priLockPtzMode.Location = new System.Drawing.Point(433, 153);
            this.priLockPtzMode.Name = "priLockPtzMode";
            this.priLockPtzMode.Size = new System.Drawing.Size(50, 19);
            this.priLockPtzMode.TabIndex = 107;
            this.priLockPtzMode.Text = "25";
            this.priLockPtzMode.UseVisualStyleBackColor = true;
            this.priLockPtzMode.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priViewRecordedVideo
            // 
            this.priViewRecordedVideo.Enabled = false;
            this.priViewRecordedVideo.Location = new System.Drawing.Point(433, 203);
            this.priViewRecordedVideo.Name = "priViewRecordedVideo";
            this.priViewRecordedVideo.Size = new System.Drawing.Size(50, 19);
            this.priViewRecordedVideo.TabIndex = 108;
            this.priViewRecordedVideo.Text = "25";
            this.priViewRecordedVideo.UseVisualStyleBackColor = true;
            this.priViewRecordedVideo.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priExportMediaClips
            // 
            this.priExportMediaClips.Enabled = false;
            this.priExportMediaClips.Location = new System.Drawing.Point(433, 228);
            this.priExportMediaClips.Name = "priExportMediaClips";
            this.priExportMediaClips.Size = new System.Drawing.Size(50, 19);
            this.priExportMediaClips.TabIndex = 109;
            this.priExportMediaClips.Text = "25";
            this.priExportMediaClips.UseVisualStyleBackColor = true;
            this.priExportMediaClips.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priDeleteExports
            // 
            this.priDeleteExports.Enabled = false;
            this.priDeleteExports.Location = new System.Drawing.Point(433, 253);
            this.priDeleteExports.Name = "priDeleteExports";
            this.priDeleteExports.Size = new System.Drawing.Size(50, 19);
            this.priDeleteExports.TabIndex = 110;
            this.priDeleteExports.Text = "25";
            this.priDeleteExports.UseVisualStyleBackColor = true;
            this.priDeleteExports.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priUseMap
            // 
            this.priUseMap.Enabled = false;
            this.priUseMap.Location = new System.Drawing.Point(433, 303);
            this.priUseMap.Name = "priUseMap";
            this.priUseMap.Size = new System.Drawing.Size(50, 19);
            this.priUseMap.TabIndex = 111;
            this.priUseMap.Text = "25";
            this.priUseMap.UseVisualStyleBackColor = true;
            this.priUseMap.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priViewMaps
            // 
            this.priViewMaps.Enabled = false;
            this.priViewMaps.Location = new System.Drawing.Point(433, 328);
            this.priViewMaps.Name = "priViewMaps";
            this.priViewMaps.Size = new System.Drawing.Size(50, 19);
            this.priViewMaps.TabIndex = 112;
            this.priViewMaps.Text = "25";
            this.priViewMaps.UseVisualStyleBackColor = true;
            this.priViewMaps.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priManageMapFiles
            // 
            this.priManageMapFiles.Enabled = false;
            this.priManageMapFiles.Location = new System.Drawing.Point(433, 353);
            this.priManageMapFiles.Name = "priManageMapFiles";
            this.priManageMapFiles.Size = new System.Drawing.Size(50, 19);
            this.priManageMapFiles.TabIndex = 113;
            this.priManageMapFiles.Text = "25";
            this.priManageMapFiles.UseVisualStyleBackColor = true;
            this.priManageMapFiles.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priPlaceCamerasOnMap
            // 
            this.priPlaceCamerasOnMap.Enabled = false;
            this.priPlaceCamerasOnMap.Location = new System.Drawing.Point(433, 378);
            this.priPlaceCamerasOnMap.Name = "priPlaceCamerasOnMap";
            this.priPlaceCamerasOnMap.Size = new System.Drawing.Size(50, 19);
            this.priPlaceCamerasOnMap.TabIndex = 114;
            this.priPlaceCamerasOnMap.Text = "25";
            this.priPlaceCamerasOnMap.UseVisualStyleBackColor = true;
            this.priPlaceCamerasOnMap.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priConfigureRecording
            // 
            this.priConfigureRecording.Enabled = false;
            this.priConfigureRecording.Location = new System.Drawing.Point(433, 423);
            this.priConfigureRecording.Name = "priConfigureRecording";
            this.priConfigureRecording.Size = new System.Drawing.Size(50, 21);
            this.priConfigureRecording.TabIndex = 115;
            this.priConfigureRecording.Text = "25";
            this.priConfigureRecording.UseVisualStyleBackColor = true;
            this.priConfigureRecording.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // btnSave
            // 
            this.btnSave.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnSave.Location = new System.Drawing.Point(947, 468);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(75, 23);
            this.btnSave.TabIndex = 29;
            this.btnSave.Text = "OK";
            this.btnSave.UseVisualStyleBackColor = true;
            // 
            // tlpRight
            // 
            this.tlpRight.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.tlpRight.ColumnCount = 6;
            this.tlpRight.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 180F));
            this.tlpRight.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 130F));
            this.tlpRight.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 100F));
            this.tlpRight.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tlpRight.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 60F));
            this.tlpRight.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 5F));
            this.tlpRight.Controls.Add(this.lblAuditUserActivity, 0, 1);
            this.tlpRight.Controls.Add(this.lblAccessUserViews, 0, 2);
            this.tlpRight.Controls.Add(this.lblManageViews, 0, 3);
            this.tlpRight.Controls.Add(this.lblEventManagement, 0, 4);
            this.tlpRight.Controls.Add(this.lblHandleEvents, 0, 5);
            this.tlpRight.Controls.Add(this.lblConfigureEvents, 0, 6);
            this.tlpRight.Controls.Add(this.lblViewEventHistory, 0, 7);
            this.tlpRight.Controls.Add(this.lblUserManagement, 0, 8);
            this.tlpRight.Controls.Add(this.lblManageUserAccounts, 0, 9);
            this.tlpRight.Controls.Add(this.lblManageAggregator, 0, 10);
            this.tlpRight.Controls.Add(this.lblAssignRoles, 0, 11);
            this.tlpRight.Controls.Add(this.lblManageRoles, 0, 12);
            this.tlpRight.Controls.Add(this.lblDeviceManagement, 0, 13);
            this.tlpRight.Controls.Add(this.lblConfigureMonitorWall, 0, 14);
            this.tlpRight.Controls.Add(this.lblSetupEdgeDevices, 0, 15);
            this.tlpRight.Controls.Add(this.lblManageTags, 0, 16);
            this.tlpRight.Controls.Add(this.cbxAuditUserActivity, 1, 1);
            this.tlpRight.Controls.Add(this.cbxAccessUserViews, 1, 2);
            this.tlpRight.Controls.Add(this.cbxManageSystemViews, 1, 3);
            this.tlpRight.Controls.Add(this.cbxHandleEvents, 1, 5);
            this.tlpRight.Controls.Add(this.cbxConfigureEvents, 1, 6);
            this.tlpRight.Controls.Add(this.cbxViewEventHistory, 1, 7);
            this.tlpRight.Controls.Add(this.cbxManageUserAccounts, 1, 9);
            this.tlpRight.Controls.Add(this.cbxManageAggregatorAccount, 1, 10);
            this.tlpRight.Controls.Add(this.cbxAssignRolesToUsers, 1, 11);
            this.tlpRight.Controls.Add(this.cbxManageRoles, 1, 12);
            this.tlpRight.Controls.Add(this.cbxConfigureMonitorWallDecoders, 1, 14);
            this.tlpRight.Controls.Add(this.cbxSetupEdgeDevices, 1, 15);
            this.tlpRight.Controls.Add(this.cbxManageSystemTags, 1, 16);
            this.tlpRight.Controls.Add(this.btnAccessUserViews, 2, 2);
            this.tlpRight.Controls.Add(this.btnManageUserAccounts, 2, 9);
            this.tlpRight.Controls.Add(this.btnSetupEdgeDevices, 2, 15);
            this.tlpRight.Controls.Add(this.lblPriorityRight, 4, 0);
            this.tlpRight.Controls.Add(this.lblResourceAccessRight, 1, 0);
            this.tlpRight.Controls.Add(this.lblSupervisionAndReports, 0, 0);
            this.tlpRight.Controls.Add(this.priAuditUserActivity, 4, 1);
            this.tlpRight.Controls.Add(this.priAccessUserViews, 4, 2);
            this.tlpRight.Controls.Add(this.priManageSystemViews, 4, 3);
            this.tlpRight.Controls.Add(this.priHandleEvents, 4, 5);
            this.tlpRight.Controls.Add(this.priConfigureEvents, 4, 6);
            this.tlpRight.Controls.Add(this.priViewEventHistory, 4, 7);
            this.tlpRight.Controls.Add(this.priManageUserAccounts, 4, 9);
            this.tlpRight.Controls.Add(this.priManageAggregatorAccount, 4, 10);
            this.tlpRight.Controls.Add(this.priAssignRolesToUsers, 4, 11);
            this.tlpRight.Controls.Add(this.priManageRoles, 4, 12);
            this.tlpRight.Controls.Add(this.priConfigureMonitorWallDecoders, 4, 14);
            this.tlpRight.Controls.Add(this.priSetupEdgeDevices, 4, 15);
            this.tlpRight.Controls.Add(this.priManageSystemTags, 4, 16);
            this.tlpRight.Location = new System.Drawing.Point(528, 13);
            this.tlpRight.Name = "tlpRight";
            this.tlpRight.RowCount = 18;
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 25F));
            this.tlpRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tlpRight.Size = new System.Drawing.Size(494, 449);
            this.tlpRight.TabIndex = 31;
            // 
            // lblAuditUserActivity
            // 
            this.lblAuditUserActivity.AutoSize = true;
            this.lblAuditUserActivity.BackColor = System.Drawing.Color.Transparent;
            this.lblAuditUserActivity.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblAuditUserActivity.Location = new System.Drawing.Point(3, 25);
            this.lblAuditUserActivity.Name = "lblAuditUserActivity";
            this.lblAuditUserActivity.Size = new System.Drawing.Size(174, 25);
            this.lblAuditUserActivity.TabIndex = 28;
            this.lblAuditUserActivity.Text = "  Audit User Activity";
            this.lblAuditUserActivity.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblAccessUserViews
            // 
            this.lblAccessUserViews.AutoSize = true;
            this.lblAccessUserViews.BackColor = System.Drawing.Color.Transparent;
            this.lblAccessUserViews.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblAccessUserViews.Location = new System.Drawing.Point(3, 50);
            this.lblAccessUserViews.Name = "lblAccessUserViews";
            this.lblAccessUserViews.Size = new System.Drawing.Size(174, 25);
            this.lblAccessUserViews.TabIndex = 31;
            this.lblAccessUserViews.Text = "  Access User Views";
            this.lblAccessUserViews.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblManageViews
            // 
            this.lblManageViews.AutoSize = true;
            this.lblManageViews.BackColor = System.Drawing.Color.Transparent;
            this.lblManageViews.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblManageViews.Location = new System.Drawing.Point(3, 75);
            this.lblManageViews.Name = "lblManageViews";
            this.lblManageViews.Size = new System.Drawing.Size(174, 25);
            this.lblManageViews.TabIndex = 14;
            this.lblManageViews.Text = "  Manage System Views";
            this.lblManageViews.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblEventManagement
            // 
            this.lblEventManagement.AutoSize = true;
            this.lblEventManagement.BackColor = System.Drawing.Color.Transparent;
            this.lblEventManagement.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblEventManagement.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblEventManagement.Location = new System.Drawing.Point(3, 100);
            this.lblEventManagement.Name = "lblEventManagement";
            this.lblEventManagement.Size = new System.Drawing.Size(174, 25);
            this.lblEventManagement.TabIndex = 17;
            this.lblEventManagement.Text = "Event Management";
            this.lblEventManagement.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblHandleEvents
            // 
            this.lblHandleEvents.AutoSize = true;
            this.lblHandleEvents.BackColor = System.Drawing.Color.Transparent;
            this.lblHandleEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblHandleEvents.Location = new System.Drawing.Point(3, 125);
            this.lblHandleEvents.Name = "lblHandleEvents";
            this.lblHandleEvents.Size = new System.Drawing.Size(174, 25);
            this.lblHandleEvents.TabIndex = 20;
            this.lblHandleEvents.Text = "  Handle Events";
            this.lblHandleEvents.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblConfigureEvents
            // 
            this.lblConfigureEvents.AutoSize = true;
            this.lblConfigureEvents.BackColor = System.Drawing.Color.Transparent;
            this.lblConfigureEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblConfigureEvents.Location = new System.Drawing.Point(3, 150);
            this.lblConfigureEvents.Name = "lblConfigureEvents";
            this.lblConfigureEvents.Size = new System.Drawing.Size(174, 25);
            this.lblConfigureEvents.TabIndex = 23;
            this.lblConfigureEvents.Text = "  Configure Events";
            this.lblConfigureEvents.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblViewEventHistory
            // 
            this.lblViewEventHistory.AutoSize = true;
            this.lblViewEventHistory.BackColor = System.Drawing.Color.Transparent;
            this.lblViewEventHistory.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblViewEventHistory.Location = new System.Drawing.Point(3, 175);
            this.lblViewEventHistory.Name = "lblViewEventHistory";
            this.lblViewEventHistory.Size = new System.Drawing.Size(174, 25);
            this.lblViewEventHistory.TabIndex = 26;
            this.lblViewEventHistory.Text = "  View Event History";
            this.lblViewEventHistory.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblUserManagement
            // 
            this.lblUserManagement.AutoSize = true;
            this.lblUserManagement.BackColor = System.Drawing.Color.Transparent;
            this.lblUserManagement.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblUserManagement.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUserManagement.Location = new System.Drawing.Point(3, 200);
            this.lblUserManagement.Name = "lblUserManagement";
            this.lblUserManagement.Size = new System.Drawing.Size(174, 25);
            this.lblUserManagement.TabIndex = 29;
            this.lblUserManagement.Text = "User Management";
            this.lblUserManagement.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblManageUserAccounts
            // 
            this.lblManageUserAccounts.AutoSize = true;
            this.lblManageUserAccounts.BackColor = System.Drawing.Color.Transparent;
            this.lblManageUserAccounts.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblManageUserAccounts.Location = new System.Drawing.Point(3, 225);
            this.lblManageUserAccounts.Name = "lblManageUserAccounts";
            this.lblManageUserAccounts.Size = new System.Drawing.Size(174, 25);
            this.lblManageUserAccounts.TabIndex = 32;
            this.lblManageUserAccounts.Text = "  Manage User Accounts";
            this.lblManageUserAccounts.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblManageAggregator
            // 
            this.lblManageAggregator.AutoSize = true;
            this.lblManageAggregator.BackColor = System.Drawing.Color.Transparent;
            this.lblManageAggregator.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblManageAggregator.Location = new System.Drawing.Point(3, 250);
            this.lblManageAggregator.Name = "lblManageAggregator";
            this.lblManageAggregator.Size = new System.Drawing.Size(174, 25);
            this.lblManageAggregator.TabIndex = 15;
            this.lblManageAggregator.Text = "    Manage Aggregator Account";
            this.lblManageAggregator.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblAssignRoles
            // 
            this.lblAssignRoles.AutoSize = true;
            this.lblAssignRoles.BackColor = System.Drawing.Color.Transparent;
            this.lblAssignRoles.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblAssignRoles.Location = new System.Drawing.Point(3, 275);
            this.lblAssignRoles.Name = "lblAssignRoles";
            this.lblAssignRoles.Size = new System.Drawing.Size(174, 25);
            this.lblAssignRoles.TabIndex = 18;
            this.lblAssignRoles.Text = "    Assign Roles to Users";
            this.lblAssignRoles.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblManageRoles
            // 
            this.lblManageRoles.AutoSize = true;
            this.lblManageRoles.BackColor = System.Drawing.Color.Transparent;
            this.lblManageRoles.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblManageRoles.Location = new System.Drawing.Point(3, 300);
            this.lblManageRoles.Name = "lblManageRoles";
            this.lblManageRoles.Size = new System.Drawing.Size(174, 25);
            this.lblManageRoles.TabIndex = 21;
            this.lblManageRoles.Text = "  Manage Roles";
            this.lblManageRoles.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblDeviceManagement
            // 
            this.lblDeviceManagement.AutoSize = true;
            this.lblDeviceManagement.BackColor = System.Drawing.Color.Transparent;
            this.lblDeviceManagement.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblDeviceManagement.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDeviceManagement.Location = new System.Drawing.Point(3, 325);
            this.lblDeviceManagement.Name = "lblDeviceManagement";
            this.lblDeviceManagement.Size = new System.Drawing.Size(174, 25);
            this.lblDeviceManagement.TabIndex = 24;
            this.lblDeviceManagement.Text = "Device Management";
            this.lblDeviceManagement.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblConfigureMonitorWall
            // 
            this.lblConfigureMonitorWall.AutoSize = true;
            this.lblConfigureMonitorWall.BackColor = System.Drawing.Color.Transparent;
            this.lblConfigureMonitorWall.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblConfigureMonitorWall.Location = new System.Drawing.Point(3, 350);
            this.lblConfigureMonitorWall.Name = "lblConfigureMonitorWall";
            this.lblConfigureMonitorWall.Size = new System.Drawing.Size(174, 25);
            this.lblConfigureMonitorWall.TabIndex = 27;
            this.lblConfigureMonitorWall.Text = "  Configure Monitor Wall Decoders";
            this.lblConfigureMonitorWall.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblSetupEdgeDevices
            // 
            this.lblSetupEdgeDevices.AutoSize = true;
            this.lblSetupEdgeDevices.BackColor = System.Drawing.Color.Transparent;
            this.lblSetupEdgeDevices.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblSetupEdgeDevices.Location = new System.Drawing.Point(3, 375);
            this.lblSetupEdgeDevices.Name = "lblSetupEdgeDevices";
            this.lblSetupEdgeDevices.Size = new System.Drawing.Size(174, 25);
            this.lblSetupEdgeDevices.TabIndex = 30;
            this.lblSetupEdgeDevices.Text = "  Setup Edge Devices";
            this.lblSetupEdgeDevices.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblManageTags
            // 
            this.lblManageTags.AutoSize = true;
            this.lblManageTags.BackColor = System.Drawing.Color.Transparent;
            this.lblManageTags.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblManageTags.Location = new System.Drawing.Point(3, 400);
            this.lblManageTags.Name = "lblManageTags";
            this.lblManageTags.Size = new System.Drawing.Size(174, 25);
            this.lblManageTags.TabIndex = 33;
            this.lblManageTags.Text = "  Manage System Tags";
            this.lblManageTags.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cbxAuditUserActivity
            // 
            this.cbxAuditUserActivity.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxAuditUserActivity.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxAuditUserActivity.FormattingEnabled = true;
            this.cbxAuditUserActivity.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxAuditUserActivity.Location = new System.Drawing.Point(183, 28);
            this.cbxAuditUserActivity.Name = "cbxAuditUserActivity";
            this.cbxAuditUserActivity.Size = new System.Drawing.Size(124, 21);
            this.cbxAuditUserActivity.TabIndex = 52;
            this.cbxAuditUserActivity.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxAuditUserActivity.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxAccessUserViews
            // 
            this.cbxAccessUserViews.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxAccessUserViews.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxAccessUserViews.FormattingEnabled = true;
            this.cbxAccessUserViews.Items.AddRange(new object[] {
            "None",
            "Any User",
            "Selected Users"});
            this.cbxAccessUserViews.Location = new System.Drawing.Point(183, 53);
            this.cbxAccessUserViews.Name = "cbxAccessUserViews";
            this.cbxAccessUserViews.Size = new System.Drawing.Size(124, 21);
            this.cbxAccessUserViews.TabIndex = 40;
            this.cbxAccessUserViews.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxAccessUserViews.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxManageSystemViews
            // 
            this.cbxManageSystemViews.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxManageSystemViews.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxManageSystemViews.FormattingEnabled = true;
            this.cbxManageSystemViews.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxManageSystemViews.Location = new System.Drawing.Point(183, 78);
            this.cbxManageSystemViews.Name = "cbxManageSystemViews";
            this.cbxManageSystemViews.Size = new System.Drawing.Size(124, 21);
            this.cbxManageSystemViews.TabIndex = 42;
            this.cbxManageSystemViews.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxManageSystemViews.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxHandleEvents
            // 
            this.cbxHandleEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxHandleEvents.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxHandleEvents.FormattingEnabled = true;
            this.cbxHandleEvents.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxHandleEvents.Location = new System.Drawing.Point(183, 128);
            this.cbxHandleEvents.Name = "cbxHandleEvents";
            this.cbxHandleEvents.Size = new System.Drawing.Size(124, 21);
            this.cbxHandleEvents.TabIndex = 44;
            this.cbxHandleEvents.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxHandleEvents.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxConfigureEvents
            // 
            this.cbxConfigureEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxConfigureEvents.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxConfigureEvents.FormattingEnabled = true;
            this.cbxConfigureEvents.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxConfigureEvents.Location = new System.Drawing.Point(183, 153);
            this.cbxConfigureEvents.Name = "cbxConfigureEvents";
            this.cbxConfigureEvents.Size = new System.Drawing.Size(124, 21);
            this.cbxConfigureEvents.TabIndex = 47;
            this.cbxConfigureEvents.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxConfigureEvents.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxViewEventHistory
            // 
            this.cbxViewEventHistory.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxViewEventHistory.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxViewEventHistory.FormattingEnabled = true;
            this.cbxViewEventHistory.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxViewEventHistory.Location = new System.Drawing.Point(183, 178);
            this.cbxViewEventHistory.Name = "cbxViewEventHistory";
            this.cbxViewEventHistory.Size = new System.Drawing.Size(124, 21);
            this.cbxViewEventHistory.TabIndex = 50;
            this.cbxViewEventHistory.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxViewEventHistory.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxManageUserAccounts
            // 
            this.cbxManageUserAccounts.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxManageUserAccounts.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxManageUserAccounts.FormattingEnabled = true;
            this.cbxManageUserAccounts.Items.AddRange(new object[] {
            "None",
            "Any User",
            "Selected Users"});
            this.cbxManageUserAccounts.Location = new System.Drawing.Point(183, 228);
            this.cbxManageUserAccounts.Name = "cbxManageUserAccounts";
            this.cbxManageUserAccounts.Size = new System.Drawing.Size(124, 21);
            this.cbxManageUserAccounts.TabIndex = 53;
            this.cbxManageUserAccounts.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxManageUserAccounts.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxManageAggregatorAccount
            // 
            this.cbxManageAggregatorAccount.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxManageAggregatorAccount.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxManageAggregatorAccount.Enabled = false;
            this.cbxManageAggregatorAccount.FormattingEnabled = true;
            this.cbxManageAggregatorAccount.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxManageAggregatorAccount.Location = new System.Drawing.Point(183, 253);
            this.cbxManageAggregatorAccount.Name = "cbxManageAggregatorAccount";
            this.cbxManageAggregatorAccount.Size = new System.Drawing.Size(124, 21);
            this.cbxManageAggregatorAccount.TabIndex = 56;
            this.cbxManageAggregatorAccount.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxManageAggregatorAccount.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxAssignRolesToUsers
            // 
            this.cbxAssignRolesToUsers.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxAssignRolesToUsers.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxAssignRolesToUsers.Enabled = false;
            this.cbxAssignRolesToUsers.FormattingEnabled = true;
            this.cbxAssignRolesToUsers.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxAssignRolesToUsers.Location = new System.Drawing.Point(183, 278);
            this.cbxAssignRolesToUsers.Name = "cbxAssignRolesToUsers";
            this.cbxAssignRolesToUsers.Size = new System.Drawing.Size(124, 21);
            this.cbxAssignRolesToUsers.TabIndex = 57;
            this.cbxAssignRolesToUsers.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxAssignRolesToUsers.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxManageRoles
            // 
            this.cbxManageRoles.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxManageRoles.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxManageRoles.FormattingEnabled = true;
            this.cbxManageRoles.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxManageRoles.Location = new System.Drawing.Point(183, 303);
            this.cbxManageRoles.Name = "cbxManageRoles";
            this.cbxManageRoles.Size = new System.Drawing.Size(124, 21);
            this.cbxManageRoles.TabIndex = 58;
            this.cbxManageRoles.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxManageRoles.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxConfigureMonitorWallDecoders
            // 
            this.cbxConfigureMonitorWallDecoders.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxConfigureMonitorWallDecoders.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxConfigureMonitorWallDecoders.FormattingEnabled = true;
            this.cbxConfigureMonitorWallDecoders.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxConfigureMonitorWallDecoders.Location = new System.Drawing.Point(183, 353);
            this.cbxConfigureMonitorWallDecoders.Name = "cbxConfigureMonitorWallDecoders";
            this.cbxConfigureMonitorWallDecoders.Size = new System.Drawing.Size(124, 21);
            this.cbxConfigureMonitorWallDecoders.TabIndex = 59;
            this.cbxConfigureMonitorWallDecoders.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxConfigureMonitorWallDecoders.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxSetupEdgeDevices
            // 
            this.cbxSetupEdgeDevices.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxSetupEdgeDevices.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxSetupEdgeDevices.FormattingEnabled = true;
            this.cbxSetupEdgeDevices.Items.AddRange(new object[] {
            "None",
            "Any Device",
            "Selected Devices"});
            this.cbxSetupEdgeDevices.Location = new System.Drawing.Point(183, 378);
            this.cbxSetupEdgeDevices.Name = "cbxSetupEdgeDevices";
            this.cbxSetupEdgeDevices.Size = new System.Drawing.Size(124, 21);
            this.cbxSetupEdgeDevices.TabIndex = 61;
            this.cbxSetupEdgeDevices.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxSetupEdgeDevices.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // cbxManageSystemTags
            // 
            this.cbxManageSystemTags.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cbxManageSystemTags.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxManageSystemTags.FormattingEnabled = true;
            this.cbxManageSystemTags.Items.AddRange(new object[] {
            "None",
            "Any Resource"});
            this.cbxManageSystemTags.Location = new System.Drawing.Point(183, 403);
            this.cbxManageSystemTags.Name = "cbxManageSystemTags";
            this.cbxManageSystemTags.Size = new System.Drawing.Size(124, 21);
            this.cbxManageSystemTags.TabIndex = 60;
            this.cbxManageSystemTags.SelectedIndexChanged += new System.EventHandler(this.ComboBox_SelectedIndexChanged);
            this.cbxManageSystemTags.Click += new System.EventHandler(this.ComboBox_Click);
            // 
            // btnAccessUserViews
            // 
            this.btnAccessUserViews.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnAccessUserViews.Enabled = false;
            this.btnAccessUserViews.Location = new System.Drawing.Point(332, 53);
            this.btnAccessUserViews.Name = "btnAccessUserViews";
            this.btnAccessUserViews.Size = new System.Drawing.Size(75, 19);
            this.btnAccessUserViews.TabIndex = 70;
            this.btnAccessUserViews.Text = "Select";
            this.btnAccessUserViews.UseVisualStyleBackColor = true;
            this.btnAccessUserViews.Click += new System.EventHandler(this.ButtonSources_Click);
            // 
            // btnManageUserAccounts
            // 
            this.btnManageUserAccounts.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnManageUserAccounts.Enabled = false;
            this.btnManageUserAccounts.Location = new System.Drawing.Point(332, 228);
            this.btnManageUserAccounts.Name = "btnManageUserAccounts";
            this.btnManageUserAccounts.Size = new System.Drawing.Size(75, 19);
            this.btnManageUserAccounts.TabIndex = 71;
            this.btnManageUserAccounts.Text = "Select";
            this.btnManageUserAccounts.UseVisualStyleBackColor = true;
            this.btnManageUserAccounts.Click += new System.EventHandler(this.ButtonSources_Click);
            // 
            // btnSetupEdgeDevices
            // 
            this.btnSetupEdgeDevices.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnSetupEdgeDevices.Enabled = false;
            this.btnSetupEdgeDevices.Location = new System.Drawing.Point(332, 378);
            this.btnSetupEdgeDevices.Name = "btnSetupEdgeDevices";
            this.btnSetupEdgeDevices.Size = new System.Drawing.Size(75, 19);
            this.btnSetupEdgeDevices.TabIndex = 72;
            this.btnSetupEdgeDevices.Text = "Select";
            this.btnSetupEdgeDevices.UseVisualStyleBackColor = true;
            this.btnSetupEdgeDevices.Click += new System.EventHandler(this.ButtonSources_Click);
            // 
            // lblPriorityRight
            // 
            this.lblPriorityRight.AutoSize = true;
            this.lblPriorityRight.BackColor = System.Drawing.Color.Transparent;
            this.lblPriorityRight.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblPriorityRight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPriorityRight.Location = new System.Drawing.Point(433, 0);
            this.lblPriorityRight.Name = "lblPriorityRight";
            this.lblPriorityRight.Size = new System.Drawing.Size(54, 25);
            this.lblPriorityRight.TabIndex = 102;
            this.lblPriorityRight.Text = "Priority";
            this.lblPriorityRight.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblResourceAccessRight
            // 
            this.lblResourceAccessRight.AutoSize = true;
            this.lblResourceAccessRight.BackColor = System.Drawing.Color.Transparent;
            this.lblResourceAccessRight.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblResourceAccessRight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblResourceAccessRight.Location = new System.Drawing.Point(183, 0);
            this.lblResourceAccessRight.Name = "lblResourceAccessRight";
            this.lblResourceAccessRight.Size = new System.Drawing.Size(124, 25);
            this.lblResourceAccessRight.TabIndex = 101;
            this.lblResourceAccessRight.Text = "Resource Access";
            this.lblResourceAccessRight.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblSupervisionAndReports
            // 
            this.lblSupervisionAndReports.AutoSize = true;
            this.lblSupervisionAndReports.BackColor = System.Drawing.Color.Transparent;
            this.lblSupervisionAndReports.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSupervisionAndReports.Location = new System.Drawing.Point(3, 0);
            this.lblSupervisionAndReports.Name = "lblSupervisionAndReports";
            this.lblSupervisionAndReports.Size = new System.Drawing.Size(164, 15);
            this.lblSupervisionAndReports.TabIndex = 103;
            this.lblSupervisionAndReports.Text = "Supervision And Reports";
            this.lblSupervisionAndReports.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // priAuditUserActivity
            // 
            this.priAuditUserActivity.Enabled = false;
            this.priAuditUserActivity.Location = new System.Drawing.Point(433, 28);
            this.priAuditUserActivity.Name = "priAuditUserActivity";
            this.priAuditUserActivity.Size = new System.Drawing.Size(50, 19);
            this.priAuditUserActivity.TabIndex = 104;
            this.priAuditUserActivity.Text = "25";
            this.priAuditUserActivity.UseVisualStyleBackColor = true;
            this.priAuditUserActivity.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priAccessUserViews
            // 
            this.priAccessUserViews.Enabled = false;
            this.priAccessUserViews.Location = new System.Drawing.Point(433, 53);
            this.priAccessUserViews.Name = "priAccessUserViews";
            this.priAccessUserViews.Size = new System.Drawing.Size(50, 19);
            this.priAccessUserViews.TabIndex = 105;
            this.priAccessUserViews.Text = "25";
            this.priAccessUserViews.UseVisualStyleBackColor = true;
            this.priAccessUserViews.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priManageSystemViews
            // 
            this.priManageSystemViews.Enabled = false;
            this.priManageSystemViews.Location = new System.Drawing.Point(433, 78);
            this.priManageSystemViews.Name = "priManageSystemViews";
            this.priManageSystemViews.Size = new System.Drawing.Size(50, 19);
            this.priManageSystemViews.TabIndex = 106;
            this.priManageSystemViews.Text = "25";
            this.priManageSystemViews.UseVisualStyleBackColor = true;
            this.priManageSystemViews.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priHandleEvents
            // 
            this.priHandleEvents.Enabled = false;
            this.priHandleEvents.Location = new System.Drawing.Point(433, 128);
            this.priHandleEvents.Name = "priHandleEvents";
            this.priHandleEvents.Size = new System.Drawing.Size(50, 19);
            this.priHandleEvents.TabIndex = 107;
            this.priHandleEvents.Text = "25";
            this.priHandleEvents.UseVisualStyleBackColor = true;
            this.priHandleEvents.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priConfigureEvents
            // 
            this.priConfigureEvents.Enabled = false;
            this.priConfigureEvents.Location = new System.Drawing.Point(433, 153);
            this.priConfigureEvents.Name = "priConfigureEvents";
            this.priConfigureEvents.Size = new System.Drawing.Size(50, 19);
            this.priConfigureEvents.TabIndex = 108;
            this.priConfigureEvents.Text = "25";
            this.priConfigureEvents.UseVisualStyleBackColor = true;
            this.priConfigureEvents.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priViewEventHistory
            // 
            this.priViewEventHistory.Enabled = false;
            this.priViewEventHistory.Location = new System.Drawing.Point(433, 178);
            this.priViewEventHistory.Name = "priViewEventHistory";
            this.priViewEventHistory.Size = new System.Drawing.Size(50, 19);
            this.priViewEventHistory.TabIndex = 109;
            this.priViewEventHistory.Text = "25";
            this.priViewEventHistory.UseVisualStyleBackColor = true;
            this.priViewEventHistory.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priManageUserAccounts
            // 
            this.priManageUserAccounts.Enabled = false;
            this.priManageUserAccounts.Location = new System.Drawing.Point(433, 228);
            this.priManageUserAccounts.Name = "priManageUserAccounts";
            this.priManageUserAccounts.Size = new System.Drawing.Size(50, 19);
            this.priManageUserAccounts.TabIndex = 110;
            this.priManageUserAccounts.Text = "25";
            this.priManageUserAccounts.UseVisualStyleBackColor = true;
            this.priManageUserAccounts.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priManageAggregatorAccount
            // 
            this.priManageAggregatorAccount.Enabled = false;
            this.priManageAggregatorAccount.Location = new System.Drawing.Point(433, 253);
            this.priManageAggregatorAccount.Name = "priManageAggregatorAccount";
            this.priManageAggregatorAccount.Size = new System.Drawing.Size(50, 19);
            this.priManageAggregatorAccount.TabIndex = 111;
            this.priManageAggregatorAccount.Text = "25";
            this.priManageAggregatorAccount.UseVisualStyleBackColor = true;
            this.priManageAggregatorAccount.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priAssignRolesToUsers
            // 
            this.priAssignRolesToUsers.Enabled = false;
            this.priAssignRolesToUsers.Location = new System.Drawing.Point(433, 278);
            this.priAssignRolesToUsers.Name = "priAssignRolesToUsers";
            this.priAssignRolesToUsers.Size = new System.Drawing.Size(50, 19);
            this.priAssignRolesToUsers.TabIndex = 112;
            this.priAssignRolesToUsers.Text = "25";
            this.priAssignRolesToUsers.UseVisualStyleBackColor = true;
            this.priAssignRolesToUsers.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priManageRoles
            // 
            this.priManageRoles.Enabled = false;
            this.priManageRoles.Location = new System.Drawing.Point(433, 303);
            this.priManageRoles.Name = "priManageRoles";
            this.priManageRoles.Size = new System.Drawing.Size(50, 19);
            this.priManageRoles.TabIndex = 113;
            this.priManageRoles.Text = "25";
            this.priManageRoles.UseVisualStyleBackColor = true;
            this.priManageRoles.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priConfigureMonitorWallDecoders
            // 
            this.priConfigureMonitorWallDecoders.Enabled = false;
            this.priConfigureMonitorWallDecoders.Location = new System.Drawing.Point(433, 353);
            this.priConfigureMonitorWallDecoders.Name = "priConfigureMonitorWallDecoders";
            this.priConfigureMonitorWallDecoders.Size = new System.Drawing.Size(50, 19);
            this.priConfigureMonitorWallDecoders.TabIndex = 114;
            this.priConfigureMonitorWallDecoders.Text = "25";
            this.priConfigureMonitorWallDecoders.UseVisualStyleBackColor = true;
            this.priConfigureMonitorWallDecoders.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priSetupEdgeDevices
            // 
            this.priSetupEdgeDevices.Enabled = false;
            this.priSetupEdgeDevices.Location = new System.Drawing.Point(433, 378);
            this.priSetupEdgeDevices.Name = "priSetupEdgeDevices";
            this.priSetupEdgeDevices.Size = new System.Drawing.Size(50, 19);
            this.priSetupEdgeDevices.TabIndex = 115;
            this.priSetupEdgeDevices.Text = "25";
            this.priSetupEdgeDevices.UseVisualStyleBackColor = true;
            this.priSetupEdgeDevices.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // priManageSystemTags
            // 
            this.priManageSystemTags.Enabled = false;
            this.priManageSystemTags.Location = new System.Drawing.Point(433, 403);
            this.priManageSystemTags.Name = "priManageSystemTags";
            this.priManageSystemTags.Size = new System.Drawing.Size(50, 19);
            this.priManageSystemTags.TabIndex = 116;
            this.priManageSystemTags.Text = "25";
            this.priManageSystemTags.UseVisualStyleBackColor = true;
            this.priManageSystemTags.Click += new System.EventHandler(this.ButtonPriority_Click);
            // 
            // ModifyRolePrivilegesForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1033, 499);
            this.Controls.Add(this.tlpRight);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.tlpLeft);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ModifyRolePrivilegesForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Modify Privileges";
            this.Load += new System.EventHandler(this.ModifyRolePrivilegesForm_Load);
            this.tlpLeft.ResumeLayout(false);
            this.tlpLeft.PerformLayout();
            this.tlpRight.ResumeLayout(false);
            this.tlpRight.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label lblViewVideoSources;
        private System.Windows.Forms.Label lblLaunchSavedViews;
        private System.Windows.Forms.Label lblCreateBookmarks;
        private System.Windows.Forms.Label lblDeleteBookmarks;
        private System.Windows.Forms.Label lblUsePtz;
        private System.Windows.Forms.Label lblSurveillance;
        private System.Windows.Forms.TableLayoutPanel tlpLeft;
        private System.Windows.Forms.Label lblLockPtz;
        private System.Windows.Forms.Label lblInvestigation;
        private System.Windows.Forms.Label lblViewRecordedVideo;
        private System.Windows.Forms.Label lblExport;
        private System.Windows.Forms.Label lblDeleteExports;
        private System.Windows.Forms.Label lblPlugIns;
        private System.Windows.Forms.Label lblUseMaps;
        private System.Windows.Forms.Label lblViewMaps;
        private System.Windows.Forms.Label lblManageMaps;
        private System.Windows.Forms.Label lblPlaceCamerasOnMaps;
        private System.Windows.Forms.ComboBox cbxLockPtzMode;
        private System.Windows.Forms.ComboBox cbxUsePtzMode;
        private System.Windows.Forms.ComboBox cbxDeleteSystemBookmarks;
        private System.Windows.Forms.ComboBox cbxCreateSystemBookmarks;
        private System.Windows.Forms.ComboBox cbxViewVideoSources;
        private System.Windows.Forms.ComboBox cbxLaunchSavedViewsRemotely;
        private System.Windows.Forms.ComboBox cbxExportMediaClips;
        private System.Windows.Forms.ComboBox cbxViewRecordedVideo;
        private System.Windows.Forms.ComboBox cbxDeleteExports;
        private System.Windows.Forms.ComboBox cbxUseMap;
        private System.Windows.Forms.ComboBox cbxManageMapFiles;
        private System.Windows.Forms.ComboBox cbxViewMaps;
        private System.Windows.Forms.ComboBox cbxPlaceCamerasOnMap;
        private System.Windows.Forms.Button btnViewVideoSources;
        private System.Windows.Forms.Button btnCreateSystemBookmarks;
        private System.Windows.Forms.Button btnDeleteSystemBookmarks;
        private System.Windows.Forms.Button btnUsePtzMode;
        private System.Windows.Forms.Button btnLockPtzMode;
        private System.Windows.Forms.Button btnViewRecordedVideo;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Label lblResourceAccessLeft;
        private System.Windows.Forms.Label lblPriorityLeft;
        private System.Windows.Forms.TableLayoutPanel tlpRight;
        private System.Windows.Forms.Label lblAuditUserActivity;
        private System.Windows.Forms.Label lblAccessUserViews;
        private System.Windows.Forms.Label lblManageViews;
        private System.Windows.Forms.Label lblPriorityRight;
        private System.Windows.Forms.Label lblResourceAccessRight;
        private System.Windows.Forms.Label lblEventManagement;
        private System.Windows.Forms.Label lblHandleEvents;
        private System.Windows.Forms.Label lblConfigureEvents;
        private System.Windows.Forms.Label lblViewEventHistory;
        private System.Windows.Forms.Label lblUserManagement;
        private System.Windows.Forms.Label lblManageUserAccounts;
        private System.Windows.Forms.Label lblManageAggregator;
        private System.Windows.Forms.Label lblAssignRoles;
        private System.Windows.Forms.Label lblManageRoles;
        private System.Windows.Forms.Label lblDeviceManagement;
        private System.Windows.Forms.Label lblConfigureMonitorWall;
        private System.Windows.Forms.Label lblSetupEdgeDevices;
        private System.Windows.Forms.Label lblManageTags;
        private System.Windows.Forms.Label lblSystemManagement;
        private System.Windows.Forms.Label lblConfigureRecording;
        private System.Windows.Forms.ComboBox cbxAuditUserActivity;
        private System.Windows.Forms.ComboBox cbxAccessUserViews;
        private System.Windows.Forms.ComboBox cbxManageSystemViews;
        private System.Windows.Forms.ComboBox cbxHandleEvents;
        private System.Windows.Forms.ComboBox cbxConfigureEvents;
        private System.Windows.Forms.ComboBox cbxViewEventHistory;
        private System.Windows.Forms.ComboBox cbxManageUserAccounts;
        private System.Windows.Forms.ComboBox cbxManageAggregatorAccount;
        private System.Windows.Forms.ComboBox cbxAssignRolesToUsers;
        private System.Windows.Forms.ComboBox cbxManageRoles;
        private System.Windows.Forms.ComboBox cbxConfigureMonitorWallDecoders;
        private System.Windows.Forms.ComboBox cbxSetupEdgeDevices;
        private System.Windows.Forms.ComboBox cbxManageSystemTags;
        private System.Windows.Forms.ComboBox cbxConfigureRecording;
        private System.Windows.Forms.Button btnAccessUserViews;
        private System.Windows.Forms.Button btnManageUserAccounts;
        private System.Windows.Forms.Button btnSetupEdgeDevices;
        private System.Windows.Forms.Label lblSupervisionAndReports;
        private Button priViewVideoSources;
        private Button priLaunchSavedViewsRemotely;
        private Button priCreateSystemBookmarks;
        private Button priDeleteSystemBookmarks;
        private Button priUsePtzMode;
        private Button priLockPtzMode;
        private Button priViewRecordedVideo;
        private Button priExportMediaClips;
        private Button priDeleteExports;
        private Button priUseMap;
        private Button priViewMaps;
        private Button priManageMapFiles;
        private Button priPlaceCamerasOnMap;
        private Button priConfigureRecording;
        private Button priAuditUserActivity;
        private Button priAccessUserViews;
        private Button priManageSystemViews;
        private Button priHandleEvents;
        private Button priConfigureEvents;
        private Button priViewEventHistory;
        private Button priManageUserAccounts;
        private Button priManageAggregatorAccount;
        private Button priAssignRolesToUsers;
        private Button priManageRoles;
        private Button priConfigureMonitorWallDecoders;
        private Button priSetupEdgeDevices;
        private Button priManageSystemTags;
    }
}