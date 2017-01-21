namespace SDKSampleApp.Source
{
    partial class AddMonitorForm
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
            this.gbxSettings = new System.Windows.Forms.GroupBox();
            this.tbxName = new System.Windows.Forms.TextBox();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.cbxMonitorDevices = new System.Windows.Forms.ComboBox();
            this.gbxHostDevice = new System.Windows.Forms.GroupBox();
            this.lblName = new System.Windows.Forms.Label();
            this.lblNumber = new System.Windows.Forms.Label();
            this.lblLayout = new System.Windows.Forms.Label();
            this.nudNumber = new System.Windows.Forms.NumericUpDown();
            this.cbxLayouts = new System.Windows.Forms.ComboBox();
            this.gbxSettings.SuspendLayout();
            this.gbxHostDevice.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudNumber)).BeginInit();
            this.SuspendLayout();
            // 
            // gbxSettings
            // 
            this.gbxSettings.Controls.Add(this.cbxLayouts);
            this.gbxSettings.Controls.Add(this.nudNumber);
            this.gbxSettings.Controls.Add(this.lblLayout);
            this.gbxSettings.Controls.Add(this.lblNumber);
            this.gbxSettings.Controls.Add(this.lblName);
            this.gbxSettings.Controls.Add(this.tbxName);
            this.gbxSettings.Location = new System.Drawing.Point(25, 76);
            this.gbxSettings.Name = "gbxSettings";
            this.gbxSettings.Size = new System.Drawing.Size(244, 112);
            this.gbxSettings.TabIndex = 6;
            this.gbxSettings.TabStop = false;
            this.gbxSettings.Text = "Settings";
            // 
            // tbxName
            // 
            this.tbxName.Location = new System.Drawing.Point(62, 48);
            this.tbxName.MaxLength = 64;
            this.tbxName.Name = "tbxName";
            this.tbxName.Size = new System.Drawing.Size(170, 20);
            this.tbxName.TabIndex = 0;
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(194, 194);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 19;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.ButtonAdd_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(113, 194);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 20;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // cbxMonitorDevices
            // 
            this.cbxMonitorDevices.FormattingEnabled = true;
            this.cbxMonitorDevices.Location = new System.Drawing.Point(6, 19);
            this.cbxMonitorDevices.Name = "cbxMonitorDevices";
            this.cbxMonitorDevices.Size = new System.Drawing.Size(226, 21);
            this.cbxMonitorDevices.TabIndex = 21;
            // 
            // gbxHostDevice
            // 
            this.gbxHostDevice.Controls.Add(this.cbxMonitorDevices);
            this.gbxHostDevice.Location = new System.Drawing.Point(25, 13);
            this.gbxHostDevice.Name = "gbxHostDevice";
            this.gbxHostDevice.Size = new System.Drawing.Size(244, 57);
            this.gbxHostDevice.TabIndex = 22;
            this.gbxHostDevice.TabStop = false;
            this.gbxHostDevice.Text = "Host Device";
            // 
            // lblName
            // 
            this.lblName.Location = new System.Drawing.Point(6, 51);
            this.lblName.Name = "lblName";
            this.lblName.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lblName.Size = new System.Drawing.Size(50, 13);
            this.lblName.TabIndex = 1;
            this.lblName.Text = "Name: ";
            this.lblName.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblNumber
            // 
            this.lblNumber.Location = new System.Drawing.Point(6, 77);
            this.lblNumber.Name = "lblNumber";
            this.lblNumber.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lblNumber.Size = new System.Drawing.Size(50, 13);
            this.lblNumber.TabIndex = 2;
            this.lblNumber.Text = "Number: ";
            this.lblNumber.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblLayout
            // 
            this.lblLayout.Location = new System.Drawing.Point(6, 25);
            this.lblLayout.Name = "lblLayout";
            this.lblLayout.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lblLayout.Size = new System.Drawing.Size(50, 13);
            this.lblLayout.TabIndex = 3;
            this.lblLayout.Text = "Layout: ";
            this.lblLayout.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // nudNumber
            // 
            this.nudNumber.Location = new System.Drawing.Point(62, 74);
            this.nudNumber.Name = "nudNumber";
            this.nudNumber.Size = new System.Drawing.Size(56, 20);
            this.nudNumber.TabIndex = 4;
            // 
            // cbxLayouts
            // 
            this.cbxLayouts.FormattingEnabled = true;
            this.cbxLayouts.Items.AddRange(new object[] {
            "1x1",
            "1x2",
            "2x1",
            "2x2",
            "2x3",
            "3x2",
            "3x3",
            "4x3",
            "4x4",
            "1+12",
            "2+8",
            "3+4",
            "1+5",
            "1+7",
            "12+1",
            "8+2",
            "1+4 (tall)",
            "1+4 (wide)"});
            this.cbxLayouts.Location = new System.Drawing.Point(62, 21);
            this.cbxLayouts.Name = "cbxLayouts";
            this.cbxLayouts.Size = new System.Drawing.Size(170, 21);
            this.cbxLayouts.TabIndex = 5;
            // 
            // AddMonitorForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(281, 225);
            this.Controls.Add(this.gbxHostDevice);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.gbxSettings);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddMonitorForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Add New Monitor";
            this.gbxSettings.ResumeLayout(false);
            this.gbxSettings.PerformLayout();
            this.gbxHostDevice.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.nudNumber)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbxSettings;
        private System.Windows.Forms.TextBox tbxName;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.ComboBox cbxMonitorDevices;
        private System.Windows.Forms.GroupBox gbxHostDevice;
        private System.Windows.Forms.Label lblLayout;
        private System.Windows.Forms.Label lblNumber;
        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.ComboBox cbxLayouts;
        private System.Windows.Forms.NumericUpDown nudNumber;
    }
}