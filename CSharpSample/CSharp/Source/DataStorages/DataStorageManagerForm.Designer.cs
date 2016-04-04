namespace SDKSampleApp.Source
{
    partial class DataStorageManagerForm
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
            this.btnAssignDevice = new System.Windows.Forms.Button();
            this.btnViewDetails = new System.Windows.Forms.Button();
            this.btnUnassignDevice = new System.Windows.Forms.Button();
            this.lvDataStorageManager = new System.Windows.Forms.ListView();
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chHostDevice = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chDriversCount = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chAssignmentCount = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // btnAssignDevice
            // 
            this.btnAssignDevice.Location = new System.Drawing.Point(772, 41);
            this.btnAssignDevice.Name = "btnAssignDevice";
            this.btnAssignDevice.Size = new System.Drawing.Size(100, 23);
            this.btnAssignDevice.TabIndex = 14;
            this.btnAssignDevice.Text = "Assign Device";
            this.btnAssignDevice.UseVisualStyleBackColor = true;
            this.btnAssignDevice.Click += new System.EventHandler(this.ButtonAssignDevice_Click);
            // 
            // btnViewDetails
            // 
            this.btnViewDetails.Location = new System.Drawing.Point(772, 12);
            this.btnViewDetails.Name = "btnViewDetails";
            this.btnViewDetails.Size = new System.Drawing.Size(100, 23);
            this.btnViewDetails.TabIndex = 13;
            this.btnViewDetails.Text = "View Details";
            this.btnViewDetails.UseVisualStyleBackColor = true;
            this.btnViewDetails.Click += new System.EventHandler(this.ButtonViewDetails_Click);
            // 
            // btnUnassignDevice
            // 
            this.btnUnassignDevice.Location = new System.Drawing.Point(773, 70);
            this.btnUnassignDevice.Name = "btnUnassignDevice";
            this.btnUnassignDevice.Size = new System.Drawing.Size(99, 23);
            this.btnUnassignDevice.TabIndex = 11;
            this.btnUnassignDevice.Text = "Unassign Device";
            this.btnUnassignDevice.UseVisualStyleBackColor = true;
            this.btnUnassignDevice.Click += new System.EventHandler(this.ButtonUnassignDevice_Click);
            // 
            // lvDataStorageManager
            // 
            this.lvDataStorageManager.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chName,
            this.chId,
            this.chType,
            this.chHostDevice,
            this.chDriversCount,
            this.chAssignmentCount});
            this.lvDataStorageManager.FullRowSelect = true;
            this.lvDataStorageManager.GridLines = true;
            this.lvDataStorageManager.HideSelection = false;
            this.lvDataStorageManager.Location = new System.Drawing.Point(12, 12);
            this.lvDataStorageManager.MultiSelect = false;
            this.lvDataStorageManager.Name = "lvDataStorageManager";
            this.lvDataStorageManager.Size = new System.Drawing.Size(754, 320);
            this.lvDataStorageManager.TabIndex = 10;
            this.lvDataStorageManager.UseCompatibleStateImageBehavior = false;
            this.lvDataStorageManager.View = System.Windows.Forms.View.Details;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 167;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 218;
            // 
            // chType
            // 
            this.chType.Text = "Type";
            this.chType.Width = 106;
            // 
            // chHostDevice
            // 
            this.chHostDevice.Text = "Host Device";
            this.chHostDevice.Width = 142;
            // 
            // chDriversCount
            // 
            this.chDriversCount.Text = "Drivers";
            this.chDriversCount.Width = 46;
            // 
            // chAssignmentCount
            // 
            this.chAssignmentCount.Text = "Assignments";
            this.chAssignmentCount.Width = 71;
            // 
            // DataStorageManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(878, 349);
            this.Controls.Add(this.btnAssignDevice);
            this.Controls.Add(this.btnViewDetails);
            this.Controls.Add(this.btnUnassignDevice);
            this.Controls.Add(this.lvDataStorageManager);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "DataStorageManagerForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Data Storage Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnAssignDevice;
        private System.Windows.Forms.Button btnViewDetails;
        private System.Windows.Forms.Button btnUnassignDevice;
        private System.Windows.Forms.ListView lvDataStorageManager;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chType;
        private System.Windows.Forms.ColumnHeader chHostDevice;
        private System.Windows.Forms.ColumnHeader chDriversCount;
        private System.Windows.Forms.ColumnHeader chAssignmentCount;
    }
}