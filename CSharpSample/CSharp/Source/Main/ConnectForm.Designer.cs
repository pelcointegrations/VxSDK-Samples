namespace SDKSampleApp.Source
{
    partial class ConnectForm
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
            this.tblLoginControls = new System.Windows.Forms.TableLayoutPanel();
            this.lblIp = new System.Windows.Forms.Label();
            this.btnConnect = new System.Windows.Forms.Button();
            this.txbxIp = new System.Windows.Forms.TextBox();
            this.lblUserName = new System.Windows.Forms.Label();
            this.txbxUserName = new System.Windows.Forms.TextBox();
            this.lblPassword = new System.Windows.Forms.Label();
            this.txbxPassword = new System.Windows.Forms.TextBox();
            this.bgwAddDevices = new System.ComponentModel.BackgroundWorker();
            this.btnSelectLogPath = new System.Windows.Forms.Button();
            this.fbdSelectLogPath = new System.Windows.Forms.FolderBrowserDialog();
            this.tbxLogPath = new System.Windows.Forms.TextBox();
            this.lblPort = new System.Windows.Forms.Label();
            this.tbxPort = new System.Windows.Forms.TextBox();
            this.gbxLogSettings = new System.Windows.Forms.GroupBox();
            this.tblLoginControls.SuspendLayout();
            this.gbxLogSettings.SuspendLayout();
            this.SuspendLayout();
            // 
            // tblLoginControls
            // 
            this.tblLoginControls.AutoSize = true;
            this.tblLoginControls.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.tblLoginControls.ColumnCount = 4;
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tblLoginControls.Controls.Add(this.lblIp, 0, 0);
            this.tblLoginControls.Controls.Add(this.txbxIp, 1, 0);
            this.tblLoginControls.Controls.Add(this.lblUserName, 0, 3);
            this.tblLoginControls.Controls.Add(this.txbxUserName, 1, 3);
            this.tblLoginControls.Controls.Add(this.lblPort, 0, 1);
            this.tblLoginControls.Controls.Add(this.tbxPort, 1, 1);
            this.tblLoginControls.Controls.Add(this.lblPassword, 0, 4);
            this.tblLoginControls.Controls.Add(this.txbxPassword, 1, 4);
            this.tblLoginControls.Controls.Add(this.btnConnect, 3, 4);
            this.tblLoginControls.Location = new System.Drawing.Point(28, 12);
            this.tblLoginControls.Name = "tblLoginControls";
            this.tblLoginControls.RowCount = 5;
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tblLoginControls.Size = new System.Drawing.Size(237, 105);
            this.tblLoginControls.TabIndex = 1;
            // 
            // lblIp
            // 
            this.lblIp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblIp.AutoSize = true;
            this.lblIp.Location = new System.Drawing.Point(43, 5);
            this.lblIp.Margin = new System.Windows.Forms.Padding(5);
            this.lblIp.Name = "lblIp";
            this.lblIp.Size = new System.Drawing.Size(17, 13);
            this.lblIp.TabIndex = 0;
            this.lblIp.Text = "IP";
            this.lblIp.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // btnConnect
            // 
            this.btnConnect.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnConnect.Location = new System.Drawing.Point(174, 81);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(60, 21);
            this.btnConnect.TabIndex = 11;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.ButtonConnect_Click);
            // 
            // txbxIp
            // 
            this.txbxIp.Location = new System.Drawing.Point(68, 3);
            this.txbxIp.Name = "txbxIp";
            this.txbxIp.Size = new System.Drawing.Size(100, 20);
            this.txbxIp.TabIndex = 5;
            // 
            // lblUserName
            // 
            this.lblUserName.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblUserName.AutoSize = true;
            this.lblUserName.Location = new System.Drawing.Point(5, 57);
            this.lblUserName.Margin = new System.Windows.Forms.Padding(5);
            this.lblUserName.Name = "lblUserName";
            this.lblUserName.Size = new System.Drawing.Size(55, 13);
            this.lblUserName.TabIndex = 3;
            this.lblUserName.Text = "Username";
            // 
            // txbxUserName
            // 
            this.txbxUserName.Location = new System.Drawing.Point(68, 55);
            this.txbxUserName.Name = "txbxUserName";
            this.txbxUserName.Size = new System.Drawing.Size(100, 20);
            this.txbxUserName.TabIndex = 8;
            // 
            // lblPassword
            // 
            this.lblPassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblPassword.AutoSize = true;
            this.lblPassword.Location = new System.Drawing.Point(7, 83);
            this.lblPassword.Margin = new System.Windows.Forms.Padding(5);
            this.lblPassword.Name = "lblPassword";
            this.lblPassword.Size = new System.Drawing.Size(53, 13);
            this.lblPassword.TabIndex = 4;
            this.lblPassword.Text = "Password";
            // 
            // txbxPassword
            // 
            this.txbxPassword.Location = new System.Drawing.Point(68, 81);
            this.txbxPassword.Name = "txbxPassword";
            this.txbxPassword.Size = new System.Drawing.Size(100, 20);
            this.txbxPassword.TabIndex = 9;
            // 
            // bgwAddDevices
            // 
            this.bgwAddDevices.DoWork += new System.ComponentModel.DoWorkEventHandler(this.BGWorkerAddDataSources_DoWork);
            this.bgwAddDevices.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.BGWorkerAddDevices_ProgressChanged);
            this.bgwAddDevices.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.BGWorkerAddDevices_RunWorkerCompleted);
            // 
            // btnSelectLogPath
            // 
            this.btnSelectLogPath.Location = new System.Drawing.Point(219, 17);
            this.btnSelectLogPath.Name = "btnSelectLogPath";
            this.btnSelectLogPath.Size = new System.Drawing.Size(52, 23);
            this.btnSelectLogPath.TabIndex = 2;
            this.btnSelectLogPath.Text = "Select";
            this.btnSelectLogPath.UseVisualStyleBackColor = true;
            this.btnSelectLogPath.Click += new System.EventHandler(this.ButtonSelectLogPath_Click);
            // 
            // fbdSelectLogPath
            // 
            this.fbdSelectLogPath.RootFolder = System.Environment.SpecialFolder.MyComputer;
            // 
            // tbxLogPath
            // 
            this.tbxLogPath.Location = new System.Drawing.Point(6, 19);
            this.tbxLogPath.Name = "tbxLogPath";
            this.tbxLogPath.ReadOnly = true;
            this.tbxLogPath.Size = new System.Drawing.Size(207, 20);
            this.tbxLogPath.TabIndex = 3;
            // 
            // lblPort
            // 
            this.lblPort.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblPort.AutoSize = true;
            this.lblPort.Location = new System.Drawing.Point(34, 31);
            this.lblPort.Margin = new System.Windows.Forms.Padding(5);
            this.lblPort.Name = "lblPort";
            this.lblPort.Size = new System.Drawing.Size(26, 13);
            this.lblPort.TabIndex = 12;
            this.lblPort.Text = "Port";
            this.lblPort.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // tbxPort
            // 
            this.tbxPort.Location = new System.Drawing.Point(68, 29);
            this.tbxPort.Name = "tbxPort";
            this.tbxPort.Size = new System.Drawing.Size(100, 20);
            this.tbxPort.TabIndex = 14;
            // 
            // gbxLogSettings
            // 
            this.gbxLogSettings.Controls.Add(this.btnSelectLogPath);
            this.gbxLogSettings.Controls.Add(this.tbxLogPath);
            this.gbxLogSettings.Location = new System.Drawing.Point(7, 133);
            this.gbxLogSettings.Name = "gbxLogSettings";
            this.gbxLogSettings.Size = new System.Drawing.Size(279, 53);
            this.gbxLogSettings.TabIndex = 5;
            this.gbxLogSettings.TabStop = false;
            this.gbxLogSettings.Text = "Logging Directory";
            // 
            // ConnectForm
            // 
            this.AcceptButton = this.btnConnect;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(293, 191);
            this.Controls.Add(this.gbxLogSettings);
            this.Controls.Add(this.tblLoginControls);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ConnectForm";
            this.ShowIcon = false;
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Connect To System";
            this.tblLoginControls.ResumeLayout(false);
            this.tblLoginControls.PerformLayout();
            this.gbxLogSettings.ResumeLayout(false);
            this.gbxLogSettings.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.OnFormClosed);
        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tblLoginControls;
        private System.Windows.Forms.Label lblIp;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.TextBox txbxIp;
        private System.Windows.Forms.Label lblUserName;
        public System.Windows.Forms.TextBox txbxUserName;
        private System.Windows.Forms.Label lblPassword;
        public System.Windows.Forms.TextBox txbxPassword;
        private System.ComponentModel.BackgroundWorker bgwAddDevices;
        private System.Windows.Forms.Button btnSelectLogPath;
        private System.Windows.Forms.FolderBrowserDialog fbdSelectLogPath;
        private System.Windows.Forms.TextBox tbxLogPath;
        private System.Windows.Forms.Label lblPort;
        private System.Windows.Forms.TextBox tbxPort;
        private System.Windows.Forms.GroupBox gbxLogSettings;
    }
}