namespace SDKSampleApp.Source
{
    partial class AddSituationForm
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
            if(disposing && (components != null))
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
            this.ckbxAckNeeded = new System.Windows.Forms.CheckBox();
            this.ckbxAudibleNotify = new System.Windows.Forms.CheckBox();
            this.ckbxExpandBanner = new System.Windows.Forms.CheckBox();
            this.ckbxLog = new System.Windows.Forms.CheckBox();
            this.ckbxNotify = new System.Windows.Forms.CheckBox();
            this.nudAudibleLoopDelay = new System.Windows.Forms.NumericUpDown();
            this.nudAudiblePlayCount = new System.Windows.Forms.NumericUpDown();
            this.nudAutoAcknowledge = new System.Windows.Forms.NumericUpDown();
            this.nudSeverity = new System.Windows.Forms.NumericUpDown();
            this.nudSnoozeIntervals1 = new System.Windows.Forms.NumericUpDown();
            this.nudSnoozeIntervals2 = new System.Windows.Forms.NumericUpDown();
            this.nudSnoozeIntervals3 = new System.Windows.Forms.NumericUpDown();
            this.lblAudibleLoopDelay = new System.Windows.Forms.Label();
            this.lblAudiblePlayCount = new System.Windows.Forms.Label();
            this.lblAutoAcknowledge = new System.Windows.Forms.Label();
            this.lblSeverity = new System.Windows.Forms.Label();
            this.lblSnoozeIntervals = new System.Windows.Forms.Label();
            this.lblName = new System.Windows.Forms.Label();
            this.txbxName = new System.Windows.Forms.TextBox();
            this.txbxSourceDeviceId = new System.Windows.Forms.TextBox();
            this.lblSourceDeviceId = new System.Windows.Forms.Label();
            this.txbxType = new System.Windows.Forms.TextBox();
            this.lblType = new System.Windows.Forms.Label();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.nudAudibleLoopDelay)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudAudiblePlayCount)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudAutoAcknowledge)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSeverity)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSnoozeIntervals1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSnoozeIntervals2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSnoozeIntervals3)).BeginInit();
            this.SuspendLayout();
            // 
            // ckbxAckNeeded
            // 
            this.ckbxAckNeeded.AutoSize = true;
            this.ckbxAckNeeded.Location = new System.Drawing.Point(291, 40);
            this.ckbxAckNeeded.Name = "ckbxAckNeeded";
            this.ckbxAckNeeded.Size = new System.Drawing.Size(86, 17);
            this.ckbxAckNeeded.TabIndex = 0;
            this.ckbxAckNeeded.Text = "Ack Needed";
            this.ckbxAckNeeded.UseVisualStyleBackColor = true;
            // 
            // ckbxAudibleNotify
            // 
            this.ckbxAudibleNotify.AutoSize = true;
            this.ckbxAudibleNotify.Location = new System.Drawing.Point(291, 65);
            this.ckbxAudibleNotify.Name = "ckbxAudibleNotify";
            this.ckbxAudibleNotify.Size = new System.Drawing.Size(91, 17);
            this.ckbxAudibleNotify.TabIndex = 1;
            this.ckbxAudibleNotify.Text = "Audible Notify";
            this.ckbxAudibleNotify.UseVisualStyleBackColor = true;
            // 
            // ckbxExpandBanner
            // 
            this.ckbxExpandBanner.AutoSize = true;
            this.ckbxExpandBanner.Location = new System.Drawing.Point(291, 90);
            this.ckbxExpandBanner.Name = "ckbxExpandBanner";
            this.ckbxExpandBanner.Size = new System.Drawing.Size(99, 17);
            this.ckbxExpandBanner.TabIndex = 2;
            this.ckbxExpandBanner.Text = "Expand Banner";
            this.ckbxExpandBanner.UseVisualStyleBackColor = true;
            // 
            // ckbxLog
            // 
            this.ckbxLog.AutoSize = true;
            this.ckbxLog.Location = new System.Drawing.Point(291, 115);
            this.ckbxLog.Name = "ckbxLog";
            this.ckbxLog.Size = new System.Drawing.Size(44, 17);
            this.ckbxLog.TabIndex = 3;
            this.ckbxLog.Text = "Log";
            this.ckbxLog.UseVisualStyleBackColor = true;
            // 
            // ckbxNotify
            // 
            this.ckbxNotify.AutoSize = true;
            this.ckbxNotify.Location = new System.Drawing.Point(291, 15);
            this.ckbxNotify.Name = "ckbxNotify";
            this.ckbxNotify.Size = new System.Drawing.Size(53, 17);
            this.ckbxNotify.TabIndex = 4;
            this.ckbxNotify.Text = "Notify";
            this.ckbxNotify.UseVisualStyleBackColor = true;
            // 
            // nudAudibleLoopDelay
            // 
            this.nudAudibleLoopDelay.Location = new System.Drawing.Point(111, 94);
            this.nudAudibleLoopDelay.Name = "nudAudibleLoopDelay";
            this.nudAudibleLoopDelay.Size = new System.Drawing.Size(54, 20);
            this.nudAudibleLoopDelay.TabIndex = 5;
            // 
            // nudAudiblePlayCount
            // 
            this.nudAudiblePlayCount.Location = new System.Drawing.Point(111, 120);
            this.nudAudiblePlayCount.Name = "nudAudiblePlayCount";
            this.nudAudiblePlayCount.Size = new System.Drawing.Size(54, 20);
            this.nudAudiblePlayCount.TabIndex = 6;
            // 
            // nudAutoAcknowledge
            // 
            this.nudAutoAcknowledge.Location = new System.Drawing.Point(111, 146);
            this.nudAutoAcknowledge.Name = "nudAutoAcknowledge";
            this.nudAutoAcknowledge.Size = new System.Drawing.Size(54, 20);
            this.nudAutoAcknowledge.TabIndex = 7;
            // 
            // nudSeverity
            // 
            this.nudSeverity.Location = new System.Drawing.Point(111, 172);
            this.nudSeverity.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.nudSeverity.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudSeverity.Name = "nudSeverity";
            this.nudSeverity.Size = new System.Drawing.Size(54, 20);
            this.nudSeverity.TabIndex = 8;
            this.nudSeverity.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // nudSnoozeIntervals1
            // 
            this.nudSnoozeIntervals1.Location = new System.Drawing.Point(111, 198);
            this.nudSnoozeIntervals1.Name = "nudSnoozeIntervals1";
            this.nudSnoozeIntervals1.Size = new System.Drawing.Size(54, 20);
            this.nudSnoozeIntervals1.TabIndex = 9;
            // 
            // nudSnoozeIntervals2
            // 
            this.nudSnoozeIntervals2.Location = new System.Drawing.Point(171, 198);
            this.nudSnoozeIntervals2.Name = "nudSnoozeIntervals2";
            this.nudSnoozeIntervals2.Size = new System.Drawing.Size(54, 20);
            this.nudSnoozeIntervals2.TabIndex = 10;
            // 
            // nudSnoozeIntervals3
            // 
            this.nudSnoozeIntervals3.Location = new System.Drawing.Point(231, 198);
            this.nudSnoozeIntervals3.Name = "nudSnoozeIntervals3";
            this.nudSnoozeIntervals3.Size = new System.Drawing.Size(54, 20);
            this.nudSnoozeIntervals3.TabIndex = 11;
            // 
            // lblAudibleLoopDelay
            // 
            this.lblAudibleLoopDelay.AutoSize = true;
            this.lblAudibleLoopDelay.Location = new System.Drawing.Point(12, 96);
            this.lblAudibleLoopDelay.Name = "lblAudibleLoopDelay";
            this.lblAudibleLoopDelay.Size = new System.Drawing.Size(93, 13);
            this.lblAudibleLoopDelay.TabIndex = 12;
            this.lblAudibleLoopDelay.Text = "AudibleLoopDelay";
            // 
            // lblAudiblePlayCount
            // 
            this.lblAudiblePlayCount.AutoSize = true;
            this.lblAudiblePlayCount.Location = new System.Drawing.Point(12, 122);
            this.lblAudiblePlayCount.Name = "lblAudiblePlayCount";
            this.lblAudiblePlayCount.Size = new System.Drawing.Size(90, 13);
            this.lblAudiblePlayCount.TabIndex = 13;
            this.lblAudiblePlayCount.Text = "AudiblePlayCount";
            // 
            // lblAutoAcknowledge
            // 
            this.lblAutoAcknowledge.AutoSize = true;
            this.lblAutoAcknowledge.Location = new System.Drawing.Point(12, 148);
            this.lblAutoAcknowledge.Name = "lblAutoAcknowledge";
            this.lblAutoAcknowledge.Size = new System.Drawing.Size(94, 13);
            this.lblAutoAcknowledge.TabIndex = 14;
            this.lblAutoAcknowledge.Text = "AutoAcknowledge";
            // 
            // lblSeverity
            // 
            this.lblSeverity.AutoSize = true;
            this.lblSeverity.Location = new System.Drawing.Point(12, 174);
            this.lblSeverity.Name = "lblSeverity";
            this.lblSeverity.Size = new System.Drawing.Size(45, 13);
            this.lblSeverity.TabIndex = 15;
            this.lblSeverity.Text = "Severity";
            // 
            // lblSnoozeIntervals
            // 
            this.lblSnoozeIntervals.AutoSize = true;
            this.lblSnoozeIntervals.Location = new System.Drawing.Point(12, 200);
            this.lblSnoozeIntervals.Name = "lblSnoozeIntervals";
            this.lblSnoozeIntervals.Size = new System.Drawing.Size(83, 13);
            this.lblSnoozeIntervals.TabIndex = 16;
            this.lblSnoozeIntervals.Text = "SnoozeIntervals";
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Location = new System.Drawing.Point(71, 15);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(35, 13);
            this.lblName.TabIndex = 17;
            this.lblName.Text = "Name";
            // 
            // txbxName
            // 
            this.txbxName.Location = new System.Drawing.Point(112, 12);
            this.txbxName.Name = "txbxName";
            this.txbxName.Size = new System.Drawing.Size(173, 20);
            this.txbxName.TabIndex = 18;
            // 
            // txbxSourceDeviceId
            // 
            this.txbxSourceDeviceId.Location = new System.Drawing.Point(112, 38);
            this.txbxSourceDeviceId.Name = "txbxSourceDeviceId";
            this.txbxSourceDeviceId.Size = new System.Drawing.Size(173, 20);
            this.txbxSourceDeviceId.TabIndex = 20;
            // 
            // lblSourceDeviceId
            // 
            this.lblSourceDeviceId.AutoSize = true;
            this.lblSourceDeviceId.Location = new System.Drawing.Point(16, 41);
            this.lblSourceDeviceId.Name = "lblSourceDeviceId";
            this.lblSourceDeviceId.Size = new System.Drawing.Size(90, 13);
            this.lblSourceDeviceId.TabIndex = 19;
            this.lblSourceDeviceId.Text = "Source Device Id";
            // 
            // txbxType
            // 
            this.txbxType.Location = new System.Drawing.Point(112, 64);
            this.txbxType.Name = "txbxType";
            this.txbxType.Size = new System.Drawing.Size(173, 20);
            this.txbxType.TabIndex = 22;
            // 
            // lblType
            // 
            this.lblType.AutoSize = true;
            this.lblType.Location = new System.Drawing.Point(75, 67);
            this.lblType.Name = "lblType";
            this.lblType.Size = new System.Drawing.Size(31, 13);
            this.lblType.TabIndex = 21;
            this.lblType.Text = "Type";
            // 
            // btnAdd
            // 
            this.btnAdd.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnAdd.Location = new System.Drawing.Point(328, 230);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 23;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.ButtonAdd_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(247, 230);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 24;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // AddSituationForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(415, 265);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.txbxType);
            this.Controls.Add(this.lblType);
            this.Controls.Add(this.txbxSourceDeviceId);
            this.Controls.Add(this.lblSourceDeviceId);
            this.Controls.Add(this.txbxName);
            this.Controls.Add(this.lblName);
            this.Controls.Add(this.lblSnoozeIntervals);
            this.Controls.Add(this.lblSeverity);
            this.Controls.Add(this.lblAutoAcknowledge);
            this.Controls.Add(this.lblAudiblePlayCount);
            this.Controls.Add(this.lblAudibleLoopDelay);
            this.Controls.Add(this.nudSnoozeIntervals3);
            this.Controls.Add(this.nudSnoozeIntervals2);
            this.Controls.Add(this.nudSnoozeIntervals1);
            this.Controls.Add(this.nudSeverity);
            this.Controls.Add(this.nudAutoAcknowledge);
            this.Controls.Add(this.nudAudiblePlayCount);
            this.Controls.Add(this.nudAudibleLoopDelay);
            this.Controls.Add(this.ckbxNotify);
            this.Controls.Add(this.ckbxLog);
            this.Controls.Add(this.ckbxExpandBanner);
            this.Controls.Add(this.ckbxAudibleNotify);
            this.Controls.Add(this.ckbxAckNeeded);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddSituationForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Add Situation";
            ((System.ComponentModel.ISupportInitialize)(this.nudAudibleLoopDelay)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudAudiblePlayCount)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudAutoAcknowledge)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSeverity)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSnoozeIntervals1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSnoozeIntervals2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSnoozeIntervals3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox ckbxAckNeeded;
        private System.Windows.Forms.CheckBox ckbxAudibleNotify;
        private System.Windows.Forms.CheckBox ckbxExpandBanner;
        private System.Windows.Forms.CheckBox ckbxLog;
        private System.Windows.Forms.CheckBox ckbxNotify;
        private System.Windows.Forms.NumericUpDown nudAudibleLoopDelay;
        private System.Windows.Forms.NumericUpDown nudAudiblePlayCount;
        private System.Windows.Forms.NumericUpDown nudAutoAcknowledge;
        private System.Windows.Forms.NumericUpDown nudSeverity;
        private System.Windows.Forms.NumericUpDown nudSnoozeIntervals1;
        private System.Windows.Forms.NumericUpDown nudSnoozeIntervals2;
        private System.Windows.Forms.NumericUpDown nudSnoozeIntervals3;
        private System.Windows.Forms.Label lblAudibleLoopDelay;
        private System.Windows.Forms.Label lblAudiblePlayCount;
        private System.Windows.Forms.Label lblAutoAcknowledge;
        private System.Windows.Forms.Label lblSeverity;
        private System.Windows.Forms.Label lblSnoozeIntervals;
        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.TextBox txbxName;
        private System.Windows.Forms.TextBox txbxSourceDeviceId;
        private System.Windows.Forms.Label lblSourceDeviceId;
        private System.Windows.Forms.TextBox txbxType;
        private System.Windows.Forms.Label lblType;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnCancel;
    }
}