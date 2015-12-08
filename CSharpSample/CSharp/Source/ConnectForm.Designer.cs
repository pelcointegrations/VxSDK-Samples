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
            this.txbxIp = new System.Windows.Forms.TextBox();
            this.lblUsername = new System.Windows.Forms.Label();
            this.txbxUsername = new System.Windows.Forms.TextBox();
            this.lblPassword = new System.Windows.Forms.Label();
            this.txbxPassword = new System.Windows.Forms.TextBox();
            this.btnConnect = new System.Windows.Forms.Button();
            this.tblLoginControls.SuspendLayout();
            this.SuspendLayout();
            // 
            // tblLoginControls
            // 
            this.tblLoginControls.AutoSize = true;
            this.tblLoginControls.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.tblLoginControls.ColumnCount = 3;
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tblLoginControls.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tblLoginControls.Controls.Add(this.lblIp, 0, 0);
            this.tblLoginControls.Controls.Add(this.btnConnect, 2, 2);
            this.tblLoginControls.Controls.Add(this.txbxIp, 1, 0);
            this.tblLoginControls.Controls.Add(this.lblUsername, 0, 1);
            this.tblLoginControls.Controls.Add(this.txbxUsername, 1, 1);
            this.tblLoginControls.Controls.Add(this.lblPassword, 0, 2);
            this.tblLoginControls.Controls.Add(this.txbxPassword, 1, 2);
            this.tblLoginControls.Location = new System.Drawing.Point(12, 12);
            this.tblLoginControls.Name = "tblLoginControls";
            this.tblLoginControls.RowCount = 3;
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tblLoginControls.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tblLoginControls.Size = new System.Drawing.Size(237, 79);
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
            // txbxIp
            // 
            this.txbxIp.Location = new System.Drawing.Point(68, 3);
            this.txbxIp.Name = "txbxIp";
            this.txbxIp.Size = new System.Drawing.Size(100, 20);
            this.txbxIp.TabIndex = 5;
            this.txbxIp.Text = "10.221.224.106";
            // 
            // lblUsername
            // 
            this.lblUsername.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblUsername.AutoSize = true;
            this.lblUsername.Location = new System.Drawing.Point(5, 31);
            this.lblUsername.Margin = new System.Windows.Forms.Padding(5);
            this.lblUsername.Name = "lblUsername";
            this.lblUsername.Size = new System.Drawing.Size(55, 13);
            this.lblUsername.TabIndex = 3;
            this.lblUsername.Text = "Username";
            // 
            // txbxUsername
            // 
            this.txbxUsername.Location = new System.Drawing.Point(68, 29);
            this.txbxUsername.Name = "txbxUsername";
            this.txbxUsername.Size = new System.Drawing.Size(100, 20);
            this.txbxUsername.TabIndex = 8;
            this.txbxUsername.Text = "admin";
            // 
            // lblPassword
            // 
            this.lblPassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblPassword.AutoSize = true;
            this.lblPassword.Location = new System.Drawing.Point(7, 57);
            this.lblPassword.Margin = new System.Windows.Forms.Padding(5);
            this.lblPassword.Name = "lblPassword";
            this.lblPassword.Size = new System.Drawing.Size(53, 13);
            this.lblPassword.TabIndex = 4;
            this.lblPassword.Text = "Password";
            // 
            // txbxPassword
            // 
            this.txbxPassword.Location = new System.Drawing.Point(68, 55);
            this.txbxPassword.Name = "txbxPassword";
            this.txbxPassword.Size = new System.Drawing.Size(100, 20);
            this.txbxPassword.TabIndex = 9;
            this.txbxPassword.Text = "admin123";
            // 
            // btnConnect
            // 
            this.btnConnect.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnConnect.Location = new System.Drawing.Point(174, 55);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(60, 21);
            this.btnConnect.TabIndex = 11;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.ButtonConnect_Click);
            // 
            // ConnectForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(257, 102);
            this.Controls.Add(this.tblLoginControls);
            this.MaximizeBox = false;
            this.Name = "ConnectForm";
            this.ShowIcon = false;
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Connect To System";
            this.tblLoginControls.ResumeLayout(false);
            this.tblLoginControls.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tblLoginControls;
        private System.Windows.Forms.Label lblIp;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.TextBox txbxIp;
        private System.Windows.Forms.Label lblUsername;
        public System.Windows.Forms.TextBox txbxUsername;
        private System.Windows.Forms.Label lblPassword;
        public System.Windows.Forms.TextBox txbxPassword;
    }
}