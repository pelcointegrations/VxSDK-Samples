namespace SDKSampleApp.Source
{
    partial class AddDeviceForm
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
            this.tbxName = new System.Windows.Forms.TextBox();
            this.tbxPassword = new System.Windows.Forms.TextBox();
            this.tbxUsername = new System.Windows.Forms.TextBox();
            this.ckbxAutoCommission = new System.Windows.Forms.CheckBox();
            this.lblName = new System.Windows.Forms.Label();
            this.lblPassword = new System.Windows.Forms.Label();
            this.lblUsername = new System.Windows.Forms.Label();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnOk = new System.Windows.Forms.Button();
            this.lblDeviceType = new System.Windows.Forms.Label();
            this.cbxDeviceType = new System.Windows.Forms.ComboBox();
            this.cbxDriverType = new System.Windows.Forms.ComboBox();
            this.lblDriverType = new System.Windows.Forms.Label();
            this.cbxRecorder = new System.Windows.Forms.ComboBox();
            this.lblRecorder = new System.Windows.Forms.Label();
            this.lblIp = new System.Windows.Forms.Label();
            this.tbxIp = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // tbxName
            // 
            this.tbxName.Location = new System.Drawing.Point(96, 63);
            this.tbxName.Name = "tbxName";
            this.tbxName.Size = new System.Drawing.Size(156, 20);
            this.tbxName.TabIndex = 0;
            // 
            // tbxPassword
            // 
            this.tbxPassword.Location = new System.Drawing.Point(96, 115);
            this.tbxPassword.Name = "tbxPassword";
            this.tbxPassword.Size = new System.Drawing.Size(156, 20);
            this.tbxPassword.TabIndex = 1;
            // 
            // tbxUsername
            // 
            this.tbxUsername.Location = new System.Drawing.Point(96, 89);
            this.tbxUsername.Name = "tbxUsername";
            this.tbxUsername.Size = new System.Drawing.Size(156, 20);
            this.tbxUsername.TabIndex = 2;
            // 
            // ckbxAutoCommission
            // 
            this.ckbxAutoCommission.AutoSize = true;
            this.ckbxAutoCommission.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.ckbxAutoCommission.Location = new System.Drawing.Point(143, 195);
            this.ckbxAutoCommission.Name = "ckbxAutoCommission";
            this.ckbxAutoCommission.Size = new System.Drawing.Size(109, 17);
            this.ckbxAutoCommission.TabIndex = 3;
            this.ckbxAutoCommission.Text = "Auto-Commission:";
            this.ckbxAutoCommission.UseVisualStyleBackColor = true;
            // 
            // lblName
            // 
            this.lblName.Location = new System.Drawing.Point(12, 61);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(79, 20);
            this.lblName.TabIndex = 4;
            this.lblName.Text = "Name: ";
            this.lblName.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblPassword
            // 
            this.lblPassword.Location = new System.Drawing.Point(12, 113);
            this.lblPassword.Name = "lblPassword";
            this.lblPassword.Size = new System.Drawing.Size(79, 20);
            this.lblPassword.TabIndex = 5;
            this.lblPassword.Text = "Password: ";
            this.lblPassword.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblUsername
            // 
            this.lblUsername.Location = new System.Drawing.Point(12, 87);
            this.lblUsername.Name = "lblUsername";
            this.lblUsername.Size = new System.Drawing.Size(79, 20);
            this.lblUsername.TabIndex = 6;
            this.lblUsername.Text = "Username: ";
            this.lblUsername.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(128, 218);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(59, 23);
            this.btnCancel.TabIndex = 8;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnOk
            // 
            this.btnOk.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnOk.Location = new System.Drawing.Point(193, 218);
            this.btnOk.Name = "btnOk";
            this.btnOk.Size = new System.Drawing.Size(59, 23);
            this.btnOk.TabIndex = 7;
            this.btnOk.Text = "Ok";
            this.btnOk.UseVisualStyleBackColor = true;
            this.btnOk.Click += new System.EventHandler(this.ButtonOk_Click);
            // 
            // lblDeviceType
            // 
            this.lblDeviceType.Location = new System.Drawing.Point(12, 9);
            this.lblDeviceType.Name = "lblDeviceType";
            this.lblDeviceType.Size = new System.Drawing.Size(79, 20);
            this.lblDeviceType.TabIndex = 9;
            this.lblDeviceType.Text = "Device Type: ";
            this.lblDeviceType.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // cbxDeviceType
            // 
            this.cbxDeviceType.FormattingEnabled = true;
            this.cbxDeviceType.Items.AddRange(new object[] {
            "Camera",
            "Core",
            "CoreMediaGateway",
            "Decoder",
            "Encoder",
            "Manager",
            "MediaGateway",
            "Monitor",
            "Recorder",
            "UDI",
            "UI",
            "VCD"});
            this.cbxDeviceType.Location = new System.Drawing.Point(97, 10);
            this.cbxDeviceType.Name = "cbxDeviceType";
            this.cbxDeviceType.Size = new System.Drawing.Size(155, 21);
            this.cbxDeviceType.TabIndex = 10;
            this.cbxDeviceType.SelectedIndexChanged += new System.EventHandler(this.ComboBoxDeviceType_SelectedIndexChanged);
            // 
            // cbxDriverType
            // 
            this.cbxDriverType.Enabled = false;
            this.cbxDriverType.FormattingEnabled = true;
            this.cbxDriverType.Location = new System.Drawing.Point(97, 168);
            this.cbxDriverType.Name = "cbxDriverType";
            this.cbxDriverType.Size = new System.Drawing.Size(155, 21);
            this.cbxDriverType.TabIndex = 12;
            // 
            // lblDriverType
            // 
            this.lblDriverType.Location = new System.Drawing.Point(12, 167);
            this.lblDriverType.Name = "lblDriverType";
            this.lblDriverType.Size = new System.Drawing.Size(79, 20);
            this.lblDriverType.TabIndex = 11;
            this.lblDriverType.Text = "Driver Type: ";
            this.lblDriverType.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // cbxRecorder
            // 
            this.cbxRecorder.Enabled = false;
            this.cbxRecorder.FormattingEnabled = true;
            this.cbxRecorder.Location = new System.Drawing.Point(97, 141);
            this.cbxRecorder.Name = "cbxRecorder";
            this.cbxRecorder.Size = new System.Drawing.Size(155, 21);
            this.cbxRecorder.TabIndex = 14;
            this.cbxRecorder.SelectedIndexChanged += new System.EventHandler(this.ComboBoxRecorder_SelectedIndexChanged);
            // 
            // lblRecorder
            // 
            this.lblRecorder.Location = new System.Drawing.Point(12, 139);
            this.lblRecorder.Name = "lblRecorder";
            this.lblRecorder.Size = new System.Drawing.Size(79, 20);
            this.lblRecorder.TabIndex = 13;
            this.lblRecorder.Text = "Recorder: ";
            this.lblRecorder.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblIp
            // 
            this.lblIp.Location = new System.Drawing.Point(12, 35);
            this.lblIp.Name = "lblIp";
            this.lblIp.Size = new System.Drawing.Size(79, 20);
            this.lblIp.TabIndex = 16;
            this.lblIp.Text = "IP: ";
            this.lblIp.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // tbxIp
            // 
            this.tbxIp.Location = new System.Drawing.Point(96, 37);
            this.tbxIp.Name = "tbxIp";
            this.tbxIp.Size = new System.Drawing.Size(156, 20);
            this.tbxIp.TabIndex = 15;
            // 
            // AddDeviceForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(267, 247);
            this.Controls.Add(this.lblIp);
            this.Controls.Add(this.tbxIp);
            this.Controls.Add(this.cbxRecorder);
            this.Controls.Add(this.lblRecorder);
            this.Controls.Add(this.cbxDriverType);
            this.Controls.Add(this.lblDriverType);
            this.Controls.Add(this.cbxDeviceType);
            this.Controls.Add(this.lblDeviceType);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnOk);
            this.Controls.Add(this.lblUsername);
            this.Controls.Add(this.lblPassword);
            this.Controls.Add(this.lblName);
            this.Controls.Add(this.ckbxAutoCommission);
            this.Controls.Add(this.tbxUsername);
            this.Controls.Add(this.tbxPassword);
            this.Controls.Add(this.tbxName);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddDeviceForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Add Device";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbxName;
        private System.Windows.Forms.TextBox tbxPassword;
        private System.Windows.Forms.TextBox tbxUsername;
        private System.Windows.Forms.CheckBox ckbxAutoCommission;
        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.Label lblPassword;
        private System.Windows.Forms.Label lblUsername;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnOk;
        private System.Windows.Forms.Label lblDeviceType;
        private System.Windows.Forms.ComboBox cbxDeviceType;
        private System.Windows.Forms.ComboBox cbxDriverType;
        private System.Windows.Forms.Label lblDriverType;
        private System.Windows.Forms.ComboBox cbxRecorder;
        private System.Windows.Forms.Label lblRecorder;
        private System.Windows.Forms.Label lblIp;
        private System.Windows.Forms.TextBox tbxIp;
    }
}