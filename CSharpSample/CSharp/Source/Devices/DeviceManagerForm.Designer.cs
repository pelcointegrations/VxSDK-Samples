namespace SDKSampleApp.Source
{
    partial class DeviceManagerForm
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
            this.btnRefresh = new System.Windows.Forms.Button();
            this.btnModify = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.lvDevices = new System.Windows.Forms.ListView();
            this.chType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chIp = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chModel = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chState = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chVersion = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chCommissioned = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnAutoDiscover = new System.Windows.Forms.Button();
            this.btnCommission = new System.Windows.Forms.Button();
            this.btnDecommission = new System.Windows.Forms.Button();
            this.lblAutoDiscoveryStatus = new System.Windows.Forms.Label();
            this.lblStatus = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(1073, 186);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(83, 23);
            this.btnRefresh.TabIndex = 12;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // btnModify
            // 
            this.btnModify.Location = new System.Drawing.Point(1073, 70);
            this.btnModify.Name = "btnModify";
            this.btnModify.Size = new System.Drawing.Size(83, 23);
            this.btnModify.TabIndex = 11;
            this.btnModify.Text = "Modify";
            this.btnModify.UseVisualStyleBackColor = true;
            this.btnModify.Click += new System.EventHandler(this.ButtonModify_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(1073, 41);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(83, 23);
            this.btnDelete.TabIndex = 10;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.ButtonDelete_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(1073, 12);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(83, 23);
            this.btnAdd.TabIndex = 9;
            this.btnAdd.Text = "Add Device";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.ButtonAdd_Click);
            // 
            // lvDevices
            // 
            this.lvDevices.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chType,
            this.chName,
            this.chIp,
            this.chId,
            this.chModel,
            this.chState,
            this.chVersion,
            this.chCommissioned});
            this.lvDevices.FullRowSelect = true;
            this.lvDevices.Location = new System.Drawing.Point(12, 12);
            this.lvDevices.MultiSelect = false;
            this.lvDevices.Name = "lvDevices";
            this.lvDevices.Size = new System.Drawing.Size(1055, 395);
            this.lvDevices.TabIndex = 8;
            this.lvDevices.UseCompatibleStateImageBehavior = false;
            this.lvDevices.View = System.Windows.Forms.View.Details;
            // 
            // chType
            // 
            this.chType.Text = "Type";
            this.chType.Width = 100;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 186;
            // 
            // chIp
            // 
            this.chIp.Text = "IP";
            this.chIp.Width = 120;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 274;
            // 
            // chModel
            // 
            this.chModel.Text = "Model";
            this.chModel.Width = 94;
            // 
            // chState
            // 
            this.chState.Text = "State";
            // 
            // chVersion
            // 
            this.chVersion.Text = "Version";
            this.chVersion.Width = 137;
            // 
            // chCommissioned
            // 
            this.chCommissioned.Text = "Commissioned";
            this.chCommissioned.Width = 79;
            // 
            // btnAutoDiscover
            // 
            this.btnAutoDiscover.Location = new System.Drawing.Point(1073, 99);
            this.btnAutoDiscover.Name = "btnAutoDiscover";
            this.btnAutoDiscover.Size = new System.Drawing.Size(83, 23);
            this.btnAutoDiscover.TabIndex = 13;
            this.btnAutoDiscover.Text = "AutoDiscover";
            this.btnAutoDiscover.UseVisualStyleBackColor = true;
            this.btnAutoDiscover.Click += new System.EventHandler(this.ButtonAutoDiscover_Click);
            // 
            // btnCommission
            // 
            this.btnCommission.Location = new System.Drawing.Point(1073, 128);
            this.btnCommission.Name = "btnCommission";
            this.btnCommission.Size = new System.Drawing.Size(83, 23);
            this.btnCommission.TabIndex = 14;
            this.btnCommission.Text = "Commission";
            this.btnCommission.UseVisualStyleBackColor = true;
            this.btnCommission.Click += new System.EventHandler(this.ButtonCommission_Click);
            // 
            // btnDecommission
            // 
            this.btnDecommission.Location = new System.Drawing.Point(1073, 157);
            this.btnDecommission.Name = "btnDecommission";
            this.btnDecommission.Size = new System.Drawing.Size(83, 23);
            this.btnDecommission.TabIndex = 15;
            this.btnDecommission.Text = "Decommission";
            this.btnDecommission.UseVisualStyleBackColor = true;
            this.btnDecommission.Click += new System.EventHandler(this.ButtonDecommission_Click);
            // 
            // lblAutoDiscoveryStatus
            // 
            this.lblAutoDiscoveryStatus.AutoSize = true;
            this.lblAutoDiscoveryStatus.Location = new System.Drawing.Point(13, 413);
            this.lblAutoDiscoveryStatus.Name = "lblAutoDiscoveryStatus";
            this.lblAutoDiscoveryStatus.Size = new System.Drawing.Size(115, 13);
            this.lblAutoDiscoveryStatus.TabIndex = 16;
            this.lblAutoDiscoveryStatus.Text = "AutoDiscovery Status: ";
            // 
            // lblStatus
            // 
            this.lblStatus.AutoSize = true;
            this.lblStatus.Location = new System.Drawing.Point(125, 413);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(0, 13);
            this.lblStatus.TabIndex = 17;
            // 
            // DeviceManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1160, 432);
            this.Controls.Add(this.lblStatus);
            this.Controls.Add(this.lblAutoDiscoveryStatus);
            this.Controls.Add(this.btnDecommission);
            this.Controls.Add(this.btnCommission);
            this.Controls.Add(this.btnAutoDiscover);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnModify);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.lvDevices);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "DeviceManagerForm";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Device Manager";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.Button btnModify;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.ListView lvDevices;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chModel;
        private System.Windows.Forms.ColumnHeader chState;
        private System.Windows.Forms.ColumnHeader chVersion;
        private System.Windows.Forms.ColumnHeader chType;
        private System.Windows.Forms.ColumnHeader chIp;
        private System.Windows.Forms.ColumnHeader chCommissioned;
        private System.Windows.Forms.Button btnAutoDiscover;
        private System.Windows.Forms.Button btnCommission;
        private System.Windows.Forms.Button btnDecommission;
        private System.Windows.Forms.Label lblAutoDiscoveryStatus;
        private System.Windows.Forms.Label lblStatus;
    }
}