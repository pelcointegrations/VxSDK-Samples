using System;

namespace SDKSampleApp.Source
{
    partial class NewExportForm
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
            this.btnAddClip = new System.Windows.Forms.Button();
            this.btnRemoveClip = new System.Windows.Forms.Button();
            this.lvDataSources = new System.Windows.Forms.ListView();
            this.colHeadName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lvAvailableClips = new System.Windows.Forms.ListView();
            this.colHeadType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colHeadStartTime = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colHeadEndTime = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lvAddedClips = new System.Windows.Forms.ListView();
            this.colHeadAddType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colHeadAddStartTime = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colHeadAddEndTime = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnExportSettings = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnAddClip
            // 
            this.btnAddClip.Location = new System.Drawing.Point(670, 173);
            this.btnAddClip.Name = "btnAddClip";
            this.btnAddClip.Size = new System.Drawing.Size(75, 23);
            this.btnAddClip.TabIndex = 5;
            this.btnAddClip.Text = "Add >>";
            this.btnAddClip.UseVisualStyleBackColor = true;
            this.btnAddClip.Click += new System.EventHandler(this.ButtonAddClip_Click);
            // 
            // btnRemoveClip
            // 
            this.btnRemoveClip.Location = new System.Drawing.Point(670, 202);
            this.btnRemoveClip.Name = "btnRemoveClip";
            this.btnRemoveClip.Size = new System.Drawing.Size(75, 23);
            this.btnRemoveClip.TabIndex = 11;
            this.btnRemoveClip.Text = "<< Remove";
            this.btnRemoveClip.UseVisualStyleBackColor = true;
            this.btnRemoveClip.Click += new System.EventHandler(this.ButtonRemoveClip_Click);
            // 
            // lvDataSources
            // 
            this.lvDataSources.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colHeadName});
            this.lvDataSources.HideSelection = false;
            this.lvDataSources.Location = new System.Drawing.Point(12, 13);
            this.lvDataSources.MultiSelect = false;
            this.lvDataSources.Name = "lvDataSources";
            this.lvDataSources.Size = new System.Drawing.Size(210, 374);
            this.lvDataSources.TabIndex = 15;
            this.lvDataSources.UseCompatibleStateImageBehavior = false;
            this.lvDataSources.View = System.Windows.Forms.View.Details;
            this.lvDataSources.SelectedIndexChanged += new System.EventHandler(this.ListViewDevices_ItemSelected);
            // 
            // colHeadName
            // 
            this.colHeadName.Text = "Name";
            this.colHeadName.Width = 206;
            // 
            // lvAvailableClips
            // 
            this.lvAvailableClips.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colHeadType,
            this.colHeadStartTime,
            this.colHeadEndTime});
            this.lvAvailableClips.HideSelection = false;
            this.lvAvailableClips.Location = new System.Drawing.Point(228, 13);
            this.lvAvailableClips.MultiSelect = false;
            this.lvAvailableClips.Name = "lvAvailableClips";
            this.lvAvailableClips.Size = new System.Drawing.Size(436, 374);
            this.lvAvailableClips.TabIndex = 16;
            this.lvAvailableClips.UseCompatibleStateImageBehavior = false;
            this.lvAvailableClips.View = System.Windows.Forms.View.Details;
            // 
            // colHeadType
            // 
            this.colHeadType.Text = "Type";
            this.colHeadType.Width = 112;
            // 
            // colHeadStartTime
            // 
            this.colHeadStartTime.Text = "Start Time";
            this.colHeadStartTime.Width = 160;
            // 
            // colHeadEndTime
            // 
            this.colHeadEndTime.Text = "End Time";
            this.colHeadEndTime.Width = 160;
            // 
            // lvAddedClips
            // 
            this.lvAddedClips.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colHeadAddType,
            this.colHeadAddStartTime,
            this.colHeadAddEndTime});
            this.lvAddedClips.HideSelection = false;
            this.lvAddedClips.Location = new System.Drawing.Point(753, 13);
            this.lvAddedClips.MultiSelect = false;
            this.lvAddedClips.Name = "lvAddedClips";
            this.lvAddedClips.Size = new System.Drawing.Size(436, 345);
            this.lvAddedClips.TabIndex = 17;
            this.lvAddedClips.UseCompatibleStateImageBehavior = false;
            this.lvAddedClips.View = System.Windows.Forms.View.Details;
            // 
            // colHeadAddType
            // 
            this.colHeadAddType.Text = "Type";
            this.colHeadAddType.Width = 112;
            // 
            // colHeadAddStartTime
            // 
            this.colHeadAddStartTime.Text = "Start Time";
            this.colHeadAddStartTime.Width = 160;
            // 
            // colHeadAddEndTime
            // 
            this.colHeadAddEndTime.Text = "End Time";
            this.colHeadAddEndTime.Width = 160;
            // 
            // btnExportSettings
            // 
            this.btnExportSettings.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnExportSettings.Location = new System.Drawing.Point(1114, 364);
            this.btnExportSettings.Name = "btnExportSettings";
            this.btnExportSettings.Size = new System.Drawing.Size(75, 23);
            this.btnExportSettings.TabIndex = 18;
            this.btnExportSettings.Text = "Export";
            this.btnExportSettings.UseVisualStyleBackColor = true;
            this.btnExportSettings.Click += new System.EventHandler(this.ButtonExportSettings_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(1033, 364);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 19;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // NewExportForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1201, 399);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnExportSettings);
            this.Controls.Add(this.lvAddedClips);
            this.Controls.Add(this.lvAvailableClips);
            this.Controls.Add(this.lvDataSources);
            this.Controls.Add(this.btnRemoveClip);
            this.Controls.Add(this.btnAddClip);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "NewExportForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Export Clips";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnAddClip;
        private System.Windows.Forms.Button btnRemoveClip;
        private System.Windows.Forms.ListView lvDataSources;
        private System.Windows.Forms.ColumnHeader colHeadName;
        private System.Windows.Forms.ColumnHeader colHeadType;
        private System.Windows.Forms.ColumnHeader colHeadStartTime;
        private System.Windows.Forms.ColumnHeader colHeadEndTime;
        private System.Windows.Forms.Button btnExportSettings;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.ColumnHeader colHeadAddType;
        private System.Windows.Forms.ColumnHeader colHeadAddStartTime;
        private System.Windows.Forms.ColumnHeader colHeadAddEndTime;
        public System.Windows.Forms.ListView lvAvailableClips;
        public System.Windows.Forms.ListView lvAddedClips;
    }
}