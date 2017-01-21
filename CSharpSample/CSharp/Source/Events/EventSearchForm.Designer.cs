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
            this.btnNextPage = new System.Windows.Forms.Button();
            this.nudResultsPerPage = new System.Windows.Forms.NumericUpDown();
            this.lblResultsPerPage = new System.Windows.Forms.Label();
            this.btnPreviousPage = new System.Windows.Forms.Button();
            this.gbxEndTime.SuspendLayout();
            this.gbxStartTime.SuspendLayout();
            this.gbxSituationType.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudResultsPerPage)).BeginInit();
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
            this.lvEvents.Size = new System.Drawing.Size(747, 283);
            this.lvEvents.TabIndex = 9;
            this.lvEvents.UseCompatibleStateImageBehavior = false;
            this.lvEvents.View = System.Windows.Forms.View.Details;
            // 
            // chTime
            // 
            this.chTime.Text = "Time";
            this.chTime.Width = 135;
            // 
            // chType
            // 
            this.chType.Text = "Type";
            this.chType.Width = 158;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 280;
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
            this.btnClear.Location = new System.Drawing.Point(684, 47);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 10;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.ButtonClear_Click);
            // 
            // btnSearch
            // 
            this.btnSearch.Location = new System.Drawing.Point(684, 18);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(75, 23);
            this.btnSearch.TabIndex = 11;
            this.btnSearch.Text = "Search";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.ButtonSearch_Click);
            // 
            // btnSilence
            // 
            this.btnSilence.Location = new System.Drawing.Point(12, 364);
            this.btnSilence.Name = "btnSilence";
            this.btnSilence.Size = new System.Drawing.Size(80, 23);
            this.btnSilence.TabIndex = 12;
            this.btnSilence.Text = "Silence";
            this.btnSilence.UseVisualStyleBackColor = true;
            this.btnSilence.Click += new System.EventHandler(this.ButtonSilence_Click);
            // 
            // btnAck
            // 
            this.btnAck.Location = new System.Drawing.Point(103, 364);
            this.btnAck.Name = "btnAck";
            this.btnAck.Size = new System.Drawing.Size(80, 23);
            this.btnAck.TabIndex = 13;
            this.btnAck.Text = "Acknowledge";
            this.btnAck.UseVisualStyleBackColor = true;
            this.btnAck.Click += new System.EventHandler(this.ButtonAck_Click);
            // 
            // btnNextPage
            // 
            this.btnNextPage.Enabled = false;
            this.btnNextPage.Location = new System.Drawing.Point(674, 364);
            this.btnNextPage.Name = "btnNextPage";
            this.btnNextPage.Size = new System.Drawing.Size(85, 23);
            this.btnNextPage.TabIndex = 14;
            this.btnNextPage.Text = "Next Page";
            this.btnNextPage.UseVisualStyleBackColor = true;
            this.btnNextPage.Click += new System.EventHandler(this.ButtonNextPage_Click);
            // 
            // nudResultsPerPage
            // 
            this.nudResultsPerPage.Location = new System.Drawing.Point(503, 365);
            this.nudResultsPerPage.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.nudResultsPerPage.Name = "nudResultsPerPage";
            this.nudResultsPerPage.Size = new System.Drawing.Size(72, 20);
            this.nudResultsPerPage.TabIndex = 15;
            this.nudResultsPerPage.Value = new decimal(new int[] {
            15,
            0,
            0,
            0});
            // 
            // lblResultsPerPage
            // 
            this.lblResultsPerPage.AutoSize = true;
            this.lblResultsPerPage.Location = new System.Drawing.Point(405, 369);
            this.lblResultsPerPage.Name = "lblResultsPerPage";
            this.lblResultsPerPage.Size = new System.Drawing.Size(92, 13);
            this.lblResultsPerPage.TabIndex = 16;
            this.lblResultsPerPage.Text = "Results Per Page:";
            // 
            // btnPreviousPage
            // 
            this.btnPreviousPage.Enabled = false;
            this.btnPreviousPage.Location = new System.Drawing.Point(581, 364);
            this.btnPreviousPage.Name = "btnPreviousPage";
            this.btnPreviousPage.Size = new System.Drawing.Size(85, 23);
            this.btnPreviousPage.TabIndex = 17;
            this.btnPreviousPage.Text = "Previous Page";
            this.btnPreviousPage.UseVisualStyleBackColor = true;
            this.btnPreviousPage.Click += new System.EventHandler(this.ButtonPreviousPage_Click);
            // 
            // EventSearchForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(771, 395);
            this.Controls.Add(this.btnPreviousPage);
            this.Controls.Add(this.lblResultsPerPage);
            this.Controls.Add(this.nudResultsPerPage);
            this.Controls.Add(this.btnNextPage);
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
            ((System.ComponentModel.ISupportInitialize)(this.nudResultsPerPage)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

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
        private System.Windows.Forms.Button btnNextPage;
        private System.Windows.Forms.NumericUpDown nudResultsPerPage;
        private System.Windows.Forms.Label lblResultsPerPage;
        private System.Windows.Forms.Button btnPreviousPage;
    }
}