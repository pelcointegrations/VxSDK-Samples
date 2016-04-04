namespace SDKSampleApp.Source
{
    partial class AddDeviceAssignmentForm
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
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.gbxDevice = new System.Windows.Forms.GroupBox();
            this.cbxDevices = new System.Windows.Forms.ComboBox();
            this.gbxDriverType = new System.Windows.Forms.GroupBox();
            this.lblNoDriversFound = new System.Windows.Forms.Label();
            this.cbxDriverTypes = new System.Windows.Forms.ComboBox();
            this.lvDataSources = new System.Windows.Forms.ListView();
            this.chCheckBox = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chDataSource = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lblNoUnassignedDevices = new System.Windows.Forms.Label();
            this.gbxDevice.SuspendLayout();
            this.gbxDriverType.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(71, 283);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 25;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnAdd
            // 
            this.btnAdd.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnAdd.Location = new System.Drawing.Point(152, 283);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 24;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.ButtonAdd_Click);
            // 
            // gbxDevice
            // 
            this.gbxDevice.Controls.Add(this.lblNoUnassignedDevices);
            this.gbxDevice.Controls.Add(this.cbxDevices);
            this.gbxDevice.Location = new System.Drawing.Point(12, 12);
            this.gbxDevice.Name = "gbxDevice";
            this.gbxDevice.Size = new System.Drawing.Size(215, 67);
            this.gbxDevice.TabIndex = 21;
            this.gbxDevice.TabStop = false;
            this.gbxDevice.Text = "Device";
            // 
            // cbxDevices
            // 
            this.cbxDevices.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxDevices.FormattingEnabled = true;
            this.cbxDevices.Location = new System.Drawing.Point(12, 19);
            this.cbxDevices.Name = "cbxDevices";
            this.cbxDevices.Size = new System.Drawing.Size(197, 21);
            this.cbxDevices.TabIndex = 0;
            this.cbxDevices.SelectedIndexChanged += new System.EventHandler(this.ComboBoxDevices_SelectedIndexChanged);
            // 
            // gbxDriverType
            // 
            this.gbxDriverType.Controls.Add(this.lblNoDriversFound);
            this.gbxDriverType.Controls.Add(this.cbxDriverTypes);
            this.gbxDriverType.Location = new System.Drawing.Point(12, 210);
            this.gbxDriverType.Name = "gbxDriverType";
            this.gbxDriverType.Size = new System.Drawing.Size(215, 67);
            this.gbxDriverType.TabIndex = 23;
            this.gbxDriverType.TabStop = false;
            this.gbxDriverType.Text = "Driver Type";
            // 
            // lblNoDriversFound
            // 
            this.lblNoDriversFound.AutoSize = true;
            this.lblNoDriversFound.Location = new System.Drawing.Point(10, 45);
            this.lblNoDriversFound.Name = "lblNoDriversFound";
            this.lblNoDriversFound.Size = new System.Drawing.Size(165, 13);
            this.lblNoDriversFound.TabIndex = 2;
            this.lblNoDriversFound.Text = "No drivers found on data storage.";
            this.lblNoDriversFound.Visible = false;
            // 
            // cbxDriverTypes
            // 
            this.cbxDriverTypes.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbxDriverTypes.FormattingEnabled = true;
            this.cbxDriverTypes.Location = new System.Drawing.Point(12, 19);
            this.cbxDriverTypes.Name = "cbxDriverTypes";
            this.cbxDriverTypes.Size = new System.Drawing.Size(197, 21);
            this.cbxDriverTypes.TabIndex = 1;
            // 
            // lvDataSources
            // 
            this.lvDataSources.CheckBoxes = true;
            this.lvDataSources.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chCheckBox,
            this.chDataSource});
            this.lvDataSources.HideSelection = false;
            this.lvDataSources.Location = new System.Drawing.Point(12, 85);
            this.lvDataSources.MultiSelect = false;
            this.lvDataSources.Name = "lvDataSources";
            this.lvDataSources.Size = new System.Drawing.Size(215, 119);
            this.lvDataSources.TabIndex = 22;
            this.lvDataSources.UseCompatibleStateImageBehavior = false;
            this.lvDataSources.View = System.Windows.Forms.View.Details;
            // 
            // chCheckBox
            // 
            this.chCheckBox.Text = "";
            this.chCheckBox.Width = 30;
            // 
            // chDataSource
            // 
            this.chDataSource.Text = "Data Source";
            this.chDataSource.Width = 180;
            // 
            // lblNoUnassignedDevices
            // 
            this.lblNoUnassignedDevices.AutoSize = true;
            this.lblNoUnassignedDevices.Location = new System.Drawing.Point(10, 43);
            this.lblNoUnassignedDevices.Name = "lblNoUnassignedDevices";
            this.lblNoUnassignedDevices.Size = new System.Drawing.Size(151, 13);
            this.lblNoUnassignedDevices.TabIndex = 3;
            this.lblNoUnassignedDevices.Text = "No unassigned devices found.";
            this.lblNoUnassignedDevices.Visible = false;
            // 
            // AddDeviceAssignmentForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(241, 315);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.gbxDevice);
            this.Controls.Add(this.gbxDriverType);
            this.Controls.Add(this.lvDataSources);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddDeviceAssignmentForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Add Device Assignment";
            this.gbxDevice.ResumeLayout(false);
            this.gbxDevice.PerformLayout();
            this.gbxDriverType.ResumeLayout(false);
            this.gbxDriverType.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.GroupBox gbxDevice;
        private System.Windows.Forms.GroupBox gbxDriverType;
        private System.Windows.Forms.ListView lvDataSources;
        private System.Windows.Forms.ColumnHeader chCheckBox;
        private System.Windows.Forms.ColumnHeader chDataSource;
        private System.Windows.Forms.ComboBox cbxDevices;
        private System.Windows.Forms.ComboBox cbxDriverTypes;
        private System.Windows.Forms.Label lblNoDriversFound;
        private System.Windows.Forms.Label lblNoUnassignedDevices;
    }
}