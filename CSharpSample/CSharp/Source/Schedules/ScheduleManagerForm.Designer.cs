namespace SDKSampleApp.Source
{
    partial class ScheduleManagerForm
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
            this.btnNewSchedule = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.lvScheduleManager = new System.Windows.Forms.ListView();
            this.chCheckBox = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chAction = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chUseAllDataSources = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chSourcesCount = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chTriggerCount = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnViewDetails = new System.Windows.Forms.Button();
            this.btnManageSources = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnNewSchedule
            // 
            this.btnNewSchedule.Location = new System.Drawing.Point(772, 12);
            this.btnNewSchedule.Name = "btnNewSchedule";
            this.btnNewSchedule.Size = new System.Drawing.Size(100, 23);
            this.btnNewSchedule.TabIndex = 7;
            this.btnNewSchedule.Text = "New Schedule";
            this.btnNewSchedule.UseVisualStyleBackColor = true;
            this.btnNewSchedule.Click += new System.EventHandler(this.ButtonNewSchedule_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(773, 99);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(99, 23);
            this.btnDelete.TabIndex = 6;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.ButtonDelete_Click);
            // 
            // lvScheduleManager
            // 
            this.lvScheduleManager.CheckBoxes = true;
            this.lvScheduleManager.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chCheckBox,
            this.chName,
            this.chId,
            this.chAction,
            this.chUseAllDataSources,
            this.chSourcesCount,
            this.chTriggerCount});
            this.lvScheduleManager.FullRowSelect = true;
            this.lvScheduleManager.GridLines = true;
            this.lvScheduleManager.Location = new System.Drawing.Point(12, 12);
            this.lvScheduleManager.MultiSelect = false;
            this.lvScheduleManager.Name = "lvScheduleManager";
            this.lvScheduleManager.Size = new System.Drawing.Size(754, 320);
            this.lvScheduleManager.TabIndex = 5;
            this.lvScheduleManager.UseCompatibleStateImageBehavior = false;
            this.lvScheduleManager.View = System.Windows.Forms.View.Details;
            // 
            // chCheckBox
            // 
            this.chCheckBox.Text = " ";
            this.chCheckBox.Width = 30;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 163;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 220;
            // 
            // chAction
            // 
            this.chAction.Text = "Action";
            this.chAction.Width = 109;
            // 
            // chUseAllDataSources
            // 
            this.chUseAllDataSources.Text = "Use All Data Sources";
            this.chUseAllDataSources.Width = 117;
            // 
            // chSourcesCount
            // 
            this.chSourcesCount.Text = "Sources";
            this.chSourcesCount.Width = 55;
            // 
            // chTriggerCount
            // 
            this.chTriggerCount.Text = "Triggers";
            this.chTriggerCount.Width = 55;
            // 
            // btnViewDetails
            // 
            this.btnViewDetails.Location = new System.Drawing.Point(772, 41);
            this.btnViewDetails.Name = "btnViewDetails";
            this.btnViewDetails.Size = new System.Drawing.Size(100, 23);
            this.btnViewDetails.TabIndex = 8;
            this.btnViewDetails.Text = "View Details";
            this.btnViewDetails.UseVisualStyleBackColor = true;
            this.btnViewDetails.Click += new System.EventHandler(this.ButtonViewDetails_Click);
            // 
            // btnManageSources
            // 
            this.btnManageSources.Location = new System.Drawing.Point(772, 70);
            this.btnManageSources.Name = "btnManageSources";
            this.btnManageSources.Size = new System.Drawing.Size(100, 23);
            this.btnManageSources.TabIndex = 9;
            this.btnManageSources.Text = "Manage Sources";
            this.btnManageSources.UseVisualStyleBackColor = true;
            this.btnManageSources.Click += new System.EventHandler(this.ButtonManageSources_Click);
            // 
            // ScheduleManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(878, 349);
            this.Controls.Add(this.btnManageSources);
            this.Controls.Add(this.btnViewDetails);
            this.Controls.Add(this.btnNewSchedule);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.lvScheduleManager);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ScheduleManagerForm";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Schedule Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnNewSchedule;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.ListView lvScheduleManager;
        private System.Windows.Forms.ColumnHeader chCheckBox;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chAction;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chUseAllDataSources;
        private System.Windows.Forms.ColumnHeader chTriggerCount;
        private System.Windows.Forms.Button btnViewDetails;
        private System.Windows.Forms.ColumnHeader chSourcesCount;
        private System.Windows.Forms.Button btnManageSources;
    }
}