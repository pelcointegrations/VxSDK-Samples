namespace VxSdkMonitorSample
{
    partial class Form1
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
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.listBoxMonitors = new System.Windows.Forms.ListBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxIp = new System.Windows.Forms.TextBox();
            this.textBoxUser = new System.Windows.Forms.TextBox();
            this.textBoxPassword = new System.Windows.Forms.TextBox();
            this.buttonLogin = new System.Windows.Forms.Button();
            this.labelMessage = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.button1x1 = new System.Windows.Forms.Button();
            this.button2x2 = new System.Windows.Forms.Button();
            this.button3x3 = new System.Windows.Forms.Button();
            this.button4x4 = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.listBoxCells = new System.Windows.Forms.ListBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.listBoxCameras = new System.Windows.Forms.ListBox();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.checkBoxLive = new System.Windows.Forms.CheckBox();
            this.dateTimePickerRecorded = new System.Windows.Forms.DateTimePicker();
            this.buttonShowVideo = new System.Windows.Forms.Button();
            this.tableLayoutPanel1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 6;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.Controls.Add(this.groupBox1, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.groupBox2, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.groupBox3, 2, 0);
            this.tableLayoutPanel1.Controls.Add(this.groupBox4, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.groupBox5, 3, 0);
            this.tableLayoutPanel1.Controls.Add(this.groupBox6, 4, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(755, 283);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.listBoxMonitors);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox1.Location = new System.Drawing.Point(191, 3);
            this.groupBox1.Name = "groupBox1";
            this.tableLayoutPanel1.SetRowSpan(this.groupBox1, 2);
            this.groupBox1.Size = new System.Drawing.Size(151, 277);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select Monitor";
            // 
            // listBoxMonitors
            // 
            this.listBoxMonitors.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBoxMonitors.FormattingEnabled = true;
            this.listBoxMonitors.Location = new System.Drawing.Point(3, 16);
            this.listBoxMonitors.Name = "listBoxMonitors";
            this.listBoxMonitors.Size = new System.Drawing.Size(145, 258);
            this.listBoxMonitors.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox2.Controls.Add(this.tableLayoutPanel2);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox2.Location = new System.Drawing.Point(3, 3);
            this.groupBox2.Name = "groupBox2";
            this.tableLayoutPanel1.SetRowSpan(this.groupBox2, 2);
            this.groupBox2.Size = new System.Drawing.Size(182, 277);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Enter Vx Info";
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.tableLayoutPanel2.ColumnCount = 2;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.Controls.Add(this.label1, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.label2, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.label3, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.textBoxIp, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.textBoxUser, 1, 1);
            this.tableLayoutPanel2.Controls.Add(this.textBoxPassword, 1, 2);
            this.tableLayoutPanel2.Controls.Add(this.buttonLogin, 1, 3);
            this.tableLayoutPanel2.Controls.Add(this.labelMessage, 0, 4);
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel2.Location = new System.Drawing.Point(3, 16);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 5;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(176, 258);
            this.tableLayoutPanel2.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(5, 5);
            this.label1.Margin = new System.Windows.Forms.Padding(5);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(17, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "IP";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(5, 31);
            this.label2.Margin = new System.Windows.Forms.Padding(5);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Username";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(5, 57);
            this.label3.Margin = new System.Windows.Forms.Padding(5);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Password";
            // 
            // textBoxIp
            // 
            this.textBoxIp.Location = new System.Drawing.Point(68, 3);
            this.textBoxIp.Name = "textBoxIp";
            this.textBoxIp.Size = new System.Drawing.Size(100, 20);
            this.textBoxIp.TabIndex = 3;
            // 
            // textBoxUser
            // 
            this.textBoxUser.Location = new System.Drawing.Point(68, 29);
            this.textBoxUser.Name = "textBoxUser";
            this.textBoxUser.Size = new System.Drawing.Size(100, 20);
            this.textBoxUser.TabIndex = 4;
            // 
            // textBoxPassword
            // 
            this.textBoxPassword.Location = new System.Drawing.Point(68, 55);
            this.textBoxPassword.Name = "textBoxPassword";
            this.textBoxPassword.Size = new System.Drawing.Size(100, 20);
            this.textBoxPassword.TabIndex = 5;
            // 
            // buttonLogin
            // 
            this.buttonLogin.Location = new System.Drawing.Point(68, 81);
            this.buttonLogin.Name = "buttonLogin";
            this.buttonLogin.Size = new System.Drawing.Size(75, 23);
            this.buttonLogin.TabIndex = 6;
            this.buttonLogin.Text = "Login";
            this.buttonLogin.UseVisualStyleBackColor = true;
            this.buttonLogin.Click += new System.EventHandler(this.buttonLogin_Click);
            // 
            // labelMessage
            // 
            this.labelMessage.AutoSize = true;
            this.tableLayoutPanel2.SetColumnSpan(this.labelMessage, 2);
            this.labelMessage.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.labelMessage.Location = new System.Drawing.Point(5, 112);
            this.labelMessage.Margin = new System.Windows.Forms.Padding(5);
            this.labelMessage.Name = "labelMessage";
            this.labelMessage.Size = new System.Drawing.Size(16, 13);
            this.labelMessage.TabIndex = 7;
            this.labelMessage.Text = "...";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.flowLayoutPanel1);
            this.groupBox3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox3.Location = new System.Drawing.Point(348, 3);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(88, 179);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Select Layout";
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.button1x1);
            this.flowLayoutPanel1.Controls.Add(this.button2x2);
            this.flowLayoutPanel1.Controls.Add(this.button3x3);
            this.flowLayoutPanel1.Controls.Add(this.button4x4);
            this.flowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel1.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(3, 16);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(82, 160);
            this.flowLayoutPanel1.TabIndex = 0;
            // 
            // button1x1
            // 
            this.button1x1.Location = new System.Drawing.Point(3, 3);
            this.button1x1.Name = "button1x1";
            this.button1x1.Size = new System.Drawing.Size(75, 23);
            this.button1x1.TabIndex = 0;
            this.button1x1.Text = "1x1";
            this.button1x1.UseVisualStyleBackColor = true;
            this.button1x1.Click += new System.EventHandler(this.button1x1_Click);
            // 
            // button2x2
            // 
            this.button2x2.Location = new System.Drawing.Point(3, 32);
            this.button2x2.Name = "button2x2";
            this.button2x2.Size = new System.Drawing.Size(75, 23);
            this.button2x2.TabIndex = 1;
            this.button2x2.Text = "2x2";
            this.button2x2.UseVisualStyleBackColor = true;
            this.button2x2.Click += new System.EventHandler(this.button2x2_Click);
            // 
            // button3x3
            // 
            this.button3x3.Location = new System.Drawing.Point(3, 61);
            this.button3x3.Name = "button3x3";
            this.button3x3.Size = new System.Drawing.Size(75, 23);
            this.button3x3.TabIndex = 2;
            this.button3x3.Text = "3x3";
            this.button3x3.UseVisualStyleBackColor = true;
            this.button3x3.Click += new System.EventHandler(this.button3x3_Click);
            // 
            // button4x4
            // 
            this.button4x4.Location = new System.Drawing.Point(3, 90);
            this.button4x4.Name = "button4x4";
            this.button4x4.Size = new System.Drawing.Size(75, 23);
            this.button4x4.TabIndex = 3;
            this.button4x4.Text = "4x4";
            this.button4x4.UseVisualStyleBackColor = true;
            this.button4x4.Click += new System.EventHandler(this.button4x4_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.listBoxCells);
            this.groupBox4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox4.Location = new System.Drawing.Point(348, 188);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(88, 92);
            this.groupBox4.TabIndex = 3;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Select Cell";
            // 
            // listBoxCells
            // 
            this.listBoxCells.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBoxCells.FormattingEnabled = true;
            this.listBoxCells.Location = new System.Drawing.Point(3, 16);
            this.listBoxCells.Name = "listBoxCells";
            this.listBoxCells.Size = new System.Drawing.Size(82, 73);
            this.listBoxCells.TabIndex = 0;
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.listBoxCameras);
            this.groupBox5.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox5.Location = new System.Drawing.Point(442, 3);
            this.groupBox5.Name = "groupBox5";
            this.tableLayoutPanel1.SetRowSpan(this.groupBox5, 2);
            this.groupBox5.Size = new System.Drawing.Size(151, 277);
            this.groupBox5.TabIndex = 4;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Select Camera";
            // 
            // listBoxCameras
            // 
            this.listBoxCameras.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBoxCameras.FormattingEnabled = true;
            this.listBoxCameras.Location = new System.Drawing.Point(3, 16);
            this.listBoxCameras.Name = "listBoxCameras";
            this.listBoxCameras.Size = new System.Drawing.Size(145, 258);
            this.listBoxCameras.TabIndex = 0;
            // 
            // groupBox6
            // 
            this.groupBox6.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox6.Controls.Add(this.tableLayoutPanel3);
            this.groupBox6.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox6.Location = new System.Drawing.Point(599, 3);
            this.groupBox6.Name = "groupBox6";
            this.tableLayoutPanel1.SetRowSpan(this.groupBox6, 2);
            this.groupBox6.Size = new System.Drawing.Size(153, 277);
            this.groupBox6.TabIndex = 5;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Select Time";
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 2;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel3.Controls.Add(this.label5, 0, 1);
            this.tableLayoutPanel3.Controls.Add(this.label4, 0, 0);
            this.tableLayoutPanel3.Controls.Add(this.checkBoxLive, 1, 0);
            this.tableLayoutPanel3.Controls.Add(this.dateTimePickerRecorded, 0, 2);
            this.tableLayoutPanel3.Controls.Add(this.buttonShowVideo, 0, 3);
            this.tableLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel3.Location = new System.Drawing.Point(3, 16);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 4;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(147, 258);
            this.tableLayoutPanel3.TabIndex = 0;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(5, 29);
            this.label5.Margin = new System.Windows.Forms.Padding(5);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(54, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Recorded";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(5, 5);
            this.label4.Margin = new System.Windows.Forms.Padding(5);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(27, 13);
            this.label4.TabIndex = 2;
            this.label4.Text = "Live";
            // 
            // checkBoxLive
            // 
            this.checkBoxLive.AutoSize = true;
            this.checkBoxLive.Checked = true;
            this.checkBoxLive.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxLive.Location = new System.Drawing.Point(69, 5);
            this.checkBoxLive.Margin = new System.Windows.Forms.Padding(5);
            this.checkBoxLive.Name = "checkBoxLive";
            this.checkBoxLive.Size = new System.Drawing.Size(15, 14);
            this.checkBoxLive.TabIndex = 3;
            this.checkBoxLive.UseVisualStyleBackColor = true;
            this.checkBoxLive.CheckedChanged += new System.EventHandler(this.checkBoxLive_CheckedChanged);
            // 
            // dateTimePickerRecorded
            // 
            this.tableLayoutPanel3.SetColumnSpan(this.dateTimePickerRecorded, 2);
            this.dateTimePickerRecorded.CustomFormat = "yyyy-MM-dd HH:mm:ss";
            this.dateTimePickerRecorded.Enabled = false;
            this.dateTimePickerRecorded.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dateTimePickerRecorded.Location = new System.Drawing.Point(3, 50);
            this.dateTimePickerRecorded.Name = "dateTimePickerRecorded";
            this.dateTimePickerRecorded.Size = new System.Drawing.Size(141, 20);
            this.dateTimePickerRecorded.TabIndex = 5;
            // 
            // buttonShowVideo
            // 
            this.tableLayoutPanel3.SetColumnSpan(this.buttonShowVideo, 2);
            this.buttonShowVideo.Location = new System.Drawing.Point(3, 76);
            this.buttonShowVideo.Name = "buttonShowVideo";
            this.buttonShowVideo.Size = new System.Drawing.Size(141, 53);
            this.buttonShowVideo.TabIndex = 6;
            this.buttonShowVideo.Text = "Show Video";
            this.buttonShowVideo.UseVisualStyleBackColor = true;
            this.buttonShowVideo.Click += new System.EventHandler(this.buttonShowVideo_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(755, 283);
            this.Controls.Add(this.tableLayoutPanel1);
            this.MinimumSize = new System.Drawing.Size(771, 322);
            this.Name = "Form1";
            this.Text = "VxSdk Monitor Sample";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.flowLayoutPanel1.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox6.ResumeLayout(false);
            this.tableLayoutPanel3.ResumeLayout(false);
            this.tableLayoutPanel3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ListBox listBoxMonitors;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxIp;
        private System.Windows.Forms.TextBox textBoxUser;
        private System.Windows.Forms.TextBox textBoxPassword;
        private System.Windows.Forms.Button buttonLogin;
        private System.Windows.Forms.Label labelMessage;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Button button1x1;
        private System.Windows.Forms.Button button2x2;
        private System.Windows.Forms.Button button3x3;
        private System.Windows.Forms.Button button4x4;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.ListBox listBoxCells;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.ListBox listBoxCameras;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.CheckBox checkBoxLive;
        private System.Windows.Forms.DateTimePicker dateTimePickerRecorded;
        private System.Windows.Forms.Button buttonShowVideo;
    }
}

