namespace SDKSampleApp.Source
{
    partial class QuickReportForm
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
            this.btnExportReports = new System.Windows.Forms.Button();
            this.ckbxCameraConfig = new System.Windows.Forms.CheckBox();
            this.ckbxOnlineOffline = new System.Windows.Forms.CheckBox();
            this.ckbxRecorderAssignment = new System.Windows.Forms.CheckBox();
            this.ckbxRecorderDiag = new System.Windows.Forms.CheckBox();
            this.ckbxUserActions = new System.Windows.Forms.CheckBox();
            this.ckbxEventHistory = new System.Windows.Forms.CheckBox();
            this.ckbxVxClusterConfig = new System.Windows.Forms.CheckBox();
            this.ckbxSystemDevice = new System.Windows.Forms.CheckBox();
            this.gbxReportContent = new System.Windows.Forms.GroupBox();
            this.gbxReportEndTime = new System.Windows.Forms.GroupBox();
            this.dtpEndDate = new System.Windows.Forms.DateTimePicker();
            this.gbxReportStartTime = new System.Windows.Forms.GroupBox();
            this.dtpStartDate = new System.Windows.Forms.DateTimePicker();
            this.btnCancel = new System.Windows.Forms.Button();
            this.gbxReportContent.SuspendLayout();
            this.gbxReportEndTime.SuspendLayout();
            this.gbxReportStartTime.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnExportReports
            // 
            this.btnExportReports.Location = new System.Drawing.Point(432, 141);
            this.btnExportReports.Name = "btnExportReports";
            this.btnExportReports.Size = new System.Drawing.Size(86, 23);
            this.btnExportReports.TabIndex = 1;
            this.btnExportReports.Text = "Export Reports";
            this.btnExportReports.UseVisualStyleBackColor = true;
            this.btnExportReports.Click += new System.EventHandler(this.ButtonExportReports_Click);
            // 
            // ckbxCameraConfig
            // 
            this.ckbxCameraConfig.AutoSize = true;
            this.ckbxCameraConfig.Location = new System.Drawing.Point(6, 19);
            this.ckbxCameraConfig.Name = "ckbxCameraConfig";
            this.ckbxCameraConfig.Size = new System.Drawing.Size(127, 17);
            this.ckbxCameraConfig.TabIndex = 2;
            this.ckbxCameraConfig.Text = "Camera Configuration";
            this.ckbxCameraConfig.UseVisualStyleBackColor = true;
            // 
            // ckbxOnlineOffline
            // 
            this.ckbxOnlineOffline.AutoSize = true;
            this.ckbxOnlineOffline.Location = new System.Drawing.Point(6, 71);
            this.ckbxOnlineOffline.Name = "ckbxOnlineOffline";
            this.ckbxOnlineOffline.Size = new System.Drawing.Size(91, 17);
            this.ckbxOnlineOffline.TabIndex = 3;
            this.ckbxOnlineOffline.Text = "Online/Offline";
            this.ckbxOnlineOffline.UseVisualStyleBackColor = true;
            this.ckbxOnlineOffline.CheckedChanged += new System.EventHandler(this.CheckBoxTimeNeeded_CheckedChanged);
            // 
            // ckbxRecorderAssignment
            // 
            this.ckbxRecorderAssignment.AutoSize = true;
            this.ckbxRecorderAssignment.Location = new System.Drawing.Point(6, 97);
            this.ckbxRecorderAssignment.Name = "ckbxRecorderAssignment";
            this.ckbxRecorderAssignment.Size = new System.Drawing.Size(166, 17);
            this.ckbxRecorderAssignment.TabIndex = 4;
            this.ckbxRecorderAssignment.Text = "Recorder Camera Assignment";
            this.ckbxRecorderAssignment.UseVisualStyleBackColor = true;
            // 
            // ckbxRecorderDiag
            // 
            this.ckbxRecorderDiag.AutoSize = true;
            this.ckbxRecorderDiag.Location = new System.Drawing.Point(172, 19);
            this.ckbxRecorderDiag.Name = "ckbxRecorderDiag";
            this.ckbxRecorderDiag.Size = new System.Drawing.Size(128, 17);
            this.ckbxRecorderDiag.TabIndex = 5;
            this.ckbxRecorderDiag.Text = "Recorder Diagnostics";
            this.ckbxRecorderDiag.UseVisualStyleBackColor = true;
            // 
            // ckbxUserActions
            // 
            this.ckbxUserActions.AutoSize = true;
            this.ckbxUserActions.Location = new System.Drawing.Point(172, 71);
            this.ckbxUserActions.Name = "ckbxUserActions";
            this.ckbxUserActions.Size = new System.Drawing.Size(86, 17);
            this.ckbxUserActions.TabIndex = 6;
            this.ckbxUserActions.Text = "User Actions";
            this.ckbxUserActions.UseVisualStyleBackColor = true;
            this.ckbxUserActions.CheckedChanged += new System.EventHandler(this.CheckBoxTimeNeeded_CheckedChanged);
            // 
            // ckbxEventHistory
            // 
            this.ckbxEventHistory.AutoSize = true;
            this.ckbxEventHistory.Location = new System.Drawing.Point(6, 45);
            this.ckbxEventHistory.Name = "ckbxEventHistory";
            this.ckbxEventHistory.Size = new System.Drawing.Size(89, 17);
            this.ckbxEventHistory.TabIndex = 7;
            this.ckbxEventHistory.Text = "Event History";
            this.ckbxEventHistory.UseVisualStyleBackColor = true;
            this.ckbxEventHistory.CheckedChanged += new System.EventHandler(this.CheckBoxTimeNeeded_CheckedChanged);
            // 
            // ckbxVxClusterConfig
            // 
            this.ckbxVxClusterConfig.AutoSize = true;
            this.ckbxVxClusterConfig.Location = new System.Drawing.Point(172, 97);
            this.ckbxVxClusterConfig.Name = "ckbxVxClusterConfig";
            this.ckbxVxClusterConfig.Size = new System.Drawing.Size(140, 17);
            this.ckbxVxClusterConfig.TabIndex = 8;
            this.ckbxVxClusterConfig.Text = "VX Cluster Configuration";
            this.ckbxVxClusterConfig.UseVisualStyleBackColor = true;
            // 
            // ckbxSystemDevice
            // 
            this.ckbxSystemDevice.AutoSize = true;
            this.ckbxSystemDevice.Location = new System.Drawing.Point(172, 45);
            this.ckbxSystemDevice.Name = "ckbxSystemDevice";
            this.ckbxSystemDevice.Size = new System.Drawing.Size(97, 17);
            this.ckbxSystemDevice.TabIndex = 9;
            this.ckbxSystemDevice.Text = "System Device";
            this.ckbxSystemDevice.UseVisualStyleBackColor = true;
            // 
            // gbxReportContent
            // 
            this.gbxReportContent.Controls.Add(this.ckbxCameraConfig);
            this.gbxReportContent.Controls.Add(this.ckbxSystemDevice);
            this.gbxReportContent.Controls.Add(this.ckbxOnlineOffline);
            this.gbxReportContent.Controls.Add(this.ckbxVxClusterConfig);
            this.gbxReportContent.Controls.Add(this.ckbxRecorderAssignment);
            this.gbxReportContent.Controls.Add(this.ckbxEventHistory);
            this.gbxReportContent.Controls.Add(this.ckbxRecorderDiag);
            this.gbxReportContent.Controls.Add(this.ckbxUserActions);
            this.gbxReportContent.Location = new System.Drawing.Point(12, 12);
            this.gbxReportContent.Name = "gbxReportContent";
            this.gbxReportContent.Size = new System.Drawing.Size(316, 123);
            this.gbxReportContent.TabIndex = 10;
            this.gbxReportContent.TabStop = false;
            this.gbxReportContent.Text = "Report Content";
            // 
            // gbxReportEndTime
            // 
            this.gbxReportEndTime.Controls.Add(this.dtpEndDate);
            this.gbxReportEndTime.Enabled = false;
            this.gbxReportEndTime.Location = new System.Drawing.Point(334, 77);
            this.gbxReportEndTime.Name = "gbxReportEndTime";
            this.gbxReportEndTime.Size = new System.Drawing.Size(184, 58);
            this.gbxReportEndTime.TabIndex = 12;
            this.gbxReportEndTime.TabStop = false;
            this.gbxReportEndTime.Text = "Report End Time";
            // 
            // dtpEndDate
            // 
            this.dtpEndDate.CustomFormat = "HH:mm:ss  MM/dd/yyyy";
            this.dtpEndDate.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpEndDate.Location = new System.Drawing.Point(6, 23);
            this.dtpEndDate.Name = "dtpEndDate";
            this.dtpEndDate.Size = new System.Drawing.Size(172, 20);
            this.dtpEndDate.TabIndex = 2;
            // 
            // gbxReportStartTime
            // 
            this.gbxReportStartTime.Controls.Add(this.dtpStartDate);
            this.gbxReportStartTime.Enabled = false;
            this.gbxReportStartTime.Location = new System.Drawing.Point(334, 12);
            this.gbxReportStartTime.Name = "gbxReportStartTime";
            this.gbxReportStartTime.Size = new System.Drawing.Size(184, 58);
            this.gbxReportStartTime.TabIndex = 11;
            this.gbxReportStartTime.TabStop = false;
            this.gbxReportStartTime.Text = "Report Start Time";
            // 
            // dtpStartDate
            // 
            this.dtpStartDate.CustomFormat = "HH:mm:ss  MM/dd/yyyy";
            this.dtpStartDate.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpStartDate.Location = new System.Drawing.Point(6, 23);
            this.dtpStartDate.Name = "dtpStartDate";
            this.dtpStartDate.Size = new System.Drawing.Size(172, 20);
            this.dtpStartDate.TabIndex = 2;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(351, 141);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 21;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // QuickReportForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(531, 173);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.gbxReportEndTime);
            this.Controls.Add(this.gbxReportStartTime);
            this.Controls.Add(this.gbxReportContent);
            this.Controls.Add(this.btnExportReports);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "QuickReportForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Generate Quick Report";
            this.gbxReportContent.ResumeLayout(false);
            this.gbxReportContent.PerformLayout();
            this.gbxReportEndTime.ResumeLayout(false);
            this.gbxReportStartTime.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnExportReports;
        private System.Windows.Forms.CheckBox ckbxCameraConfig;
        private System.Windows.Forms.CheckBox ckbxOnlineOffline;
        private System.Windows.Forms.CheckBox ckbxRecorderAssignment;
        private System.Windows.Forms.CheckBox ckbxRecorderDiag;
        private System.Windows.Forms.CheckBox ckbxUserActions;
        private System.Windows.Forms.CheckBox ckbxEventHistory;
        private System.Windows.Forms.CheckBox ckbxVxClusterConfig;
        private System.Windows.Forms.CheckBox ckbxSystemDevice;
        private System.Windows.Forms.GroupBox gbxReportContent;
        private System.Windows.Forms.GroupBox gbxReportEndTime;
        private System.Windows.Forms.DateTimePicker dtpEndDate;
        private System.Windows.Forms.GroupBox gbxReportStartTime;
        private System.Windows.Forms.DateTimePicker dtpStartDate;
        private System.Windows.Forms.Button btnCancel;
    }
}