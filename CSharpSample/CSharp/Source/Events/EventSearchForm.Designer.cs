namespace SDKSampleApp.Source
{
    partial class EventSearchForm
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
            this.gbxEndTime = new System.Windows.Forms.GroupBox();
            this.dtpEndDate = new System.Windows.Forms.DateTimePicker();
            this.gbxStartTime = new System.Windows.Forms.GroupBox();
            this.dtpStartDate = new System.Windows.Forms.DateTimePicker();
            this.gbxSituationType = new System.Windows.Forms.GroupBox();
            this.cbxSituationType = new System.Windows.Forms.ComboBox();
            this.lvEvents = new System.Windows.Forms.ListView();
            this.chTime = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chSeverity = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chAckState = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnClear = new System.Windows.Forms.Button();
            this.btnSearch = new System.Windows.Forms.Button();
            this.btnSilence = new System.Windows.Forms.Button();
            this.btnAck = new System.Windows.Forms.Button();
            this.gbxEndTime.SuspendLayout();
            this.gbxStartTime.SuspendLayout();
            this.gbxSituationType.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbxEndTime
            // 
            this.gbxEndTime.Controls.Add(this.dtpEndDate);
            this.gbxEndTime.Location = new System.Drawing.Point(454, 12);
            this.gbxEndTime.Name = "gbxEndTime";
            this.gbxEndTime.Size = new System.Drawing.Size(215, 58);
            this.gbxEndTime.TabIndex = 8;
            this.gbxEndTime.TabStop = false;
            this.gbxEndTime.Text = "Search End Time";
            // 
            // dtpEndDate
            // 
            this.dtpEndDate.CustomFormat = "HH:mm:ss  MM/dd/yyyy";
            this.dtpEndDate.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpEndDate.Location = new System.Drawing.Point(6, 23);
            this.dtpEndDate.Name = "dtpEndDate";
            this.dtpEndDate.Size = new System.Drawing.Size(204, 20);
            this.dtpEndDate.TabIndex = 2;
            // 
            // gbxStartTime
            // 
            this.gbxStartTime.Controls.Add(this.dtpStartDate);
            this.gbxStartTime.Location = new System.Drawing.Point(233, 12);
            this.gbxStartTime.Name = "gbxStartTime";
            this.gbxStartTime.Size = new System.Drawing.Size(215, 58);
            this.gbxStartTime.TabIndex = 7;
            this.gbxStartTime.TabStop = false;
            this.gbxStartTime.Text = "Search Start Time";
            // 
            // dtpStartDate
            // 
            this.dtpStartDate.CustomFormat = "HH:mm:ss  MM/dd/yyyy";
            this.dtpStartDate.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpStartDate.Location = new System.Drawing.Point(6, 23);
            this.dtpStartDate.Name = "dtpStartDate";
            this.dtpStartDate.Size = new System.Drawing.Size(204, 20);
            this.dtpStartDate.TabIndex = 2;
            // 
            // gbxSituationType
            // 
            this.gbxSituationType.Controls.Add(this.cbxSituationType);
            this.gbxSituationType.Location = new System.Drawing.Point(12, 12);
            this.gbxSituationType.Name = "gbxSituationType";
            this.gbxSituationType.Size = new System.Drawing.Size(215, 58);
            this.gbxSituationType.TabIndex = 8;
            this.gbxSituationType.TabStop = false;
            this.gbxSituationType.Text = "Situation Type";
            // 
            // cbxSituationType
            // 
            this.cbxSituationType.FormattingEnabled = true;
            this.cbxSituationType.Items.AddRange(new object[] {
            "Any"});
            this.cbxSituationType.Location = new System.Drawing.Point(6, 23);
            this.cbxSituationType.Name = "cbxSituationType";
            this.cbxSituationType.Size = new System.Drawing.Size(203, 21);
            this.cbxSituationType.TabIndex = 0;
            // 
            // lvEvents
            // 
            this.lvEvents.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chTime,
            this.chType,
            this.chId,
            this.chSeverity,
            this.chAckState});
            this.lvEvents.Location = new System.Drawing.Point(12, 76);
            this.lvEvents.MultiSelect = false;
            this.lvEvents.Name = "lvEvents";
            this.lvEvents.Size = new System.Drawing.Size(742, 193);
            this.lvEvents.TabIndex = 9;
            this.lvEvents.UseCompatibleStateImageBehavior = false;
            this.lvEvents.View = System.Windows.Forms.View.Details;
            // 
            // chTime
            // 
            this.chTime.Text = "Time";
            this.chTime.Width = 130;
            // 
            // chType
            // 
            this.chType.Text = "Type";
            this.chType.Width = 158;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 270;
            // 
            // chSeverity
            // 
            this.chSeverity.Text = "Severity";
            // 
            // chAckState
            // 
            this.chAckState.Text = "Ack State";
            this.chAckState.Width = 110;
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(679, 47);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 10;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.ButtonClear_Click);
            // 
            // btnSearch
            // 
            this.btnSearch.Location = new System.Drawing.Point(679, 18);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(75, 23);
            this.btnSearch.TabIndex = 11;
            this.btnSearch.Text = "Search";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.ButtonSearch_Click);
            // 
            // btnSilence
            // 
            this.btnSilence.Location = new System.Drawing.Point(297, 275);
            this.btnSilence.Name = "btnSilence";
            this.btnSilence.Size = new System.Drawing.Size(80, 23);
            this.btnSilence.TabIndex = 12;
            this.btnSilence.Text = "Silence";
            this.btnSilence.UseVisualStyleBackColor = true;
            this.btnSilence.Click += new System.EventHandler(this.ButtonSilence_Click);
            // 
            // btnAck
            // 
            this.btnAck.Location = new System.Drawing.Point(388, 275);
            this.btnAck.Name = "btnAck";
            this.btnAck.Size = new System.Drawing.Size(80, 23);
            this.btnAck.TabIndex = 13;
            this.btnAck.Text = "Acknowledge";
            this.btnAck.UseVisualStyleBackColor = true;
            this.btnAck.Click += new System.EventHandler(this.ButtonAck_Click);
            // 
            // EventSearchForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(765, 308);
            this.Controls.Add(this.btnAck);
            this.Controls.Add(this.btnSilence);
            this.Controls.Add(this.btnSearch);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.lvEvents);
            this.Controls.Add(this.gbxSituationType);
            this.Controls.Add(this.gbxEndTime);
            this.Controls.Add(this.gbxStartTime);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "EventSearchForm";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Event Search";
            this.gbxEndTime.ResumeLayout(false);
            this.gbxStartTime.ResumeLayout(false);
            this.gbxSituationType.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbxEndTime;
        private System.Windows.Forms.DateTimePicker dtpEndDate;
        private System.Windows.Forms.GroupBox gbxStartTime;
        private System.Windows.Forms.DateTimePicker dtpStartDate;
        private System.Windows.Forms.GroupBox gbxSituationType;
        private System.Windows.Forms.ComboBox cbxSituationType;
        private System.Windows.Forms.ListView lvEvents;
        private System.Windows.Forms.ColumnHeader chTime;
        private System.Windows.Forms.ColumnHeader chType;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chSeverity;
        private System.Windows.Forms.ColumnHeader chAckState;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.Button btnSilence;
        private System.Windows.Forms.Button btnAck;
    }
}