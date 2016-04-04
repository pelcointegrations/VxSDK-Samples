namespace SDKSampleApp.Source
{
    partial class TagManagerForm
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
            this.gbxLinkedDevices = new System.Windows.Forms.GroupBox();
            this.lvDevices = new System.Windows.Forms.ListView();
            this.chDeviceName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.gbxLinkedDataSources = new System.Windows.Forms.GroupBox();
            this.lvDataSources = new System.Windows.Forms.ListView();
            this.chDataSourceName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lvTags = new System.Windows.Forms.ListView();
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chOwner = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnNewTag = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnMerge = new System.Windows.Forms.Button();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.btnModify = new System.Windows.Forms.Button();
            this.gbxLinkedDevices.SuspendLayout();
            this.gbxLinkedDataSources.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbxLinkedDevices
            // 
            this.gbxLinkedDevices.Controls.Add(this.lvDevices);
            this.gbxLinkedDevices.Location = new System.Drawing.Point(12, 154);
            this.gbxLinkedDevices.Name = "gbxLinkedDevices";
            this.gbxLinkedDevices.Size = new System.Drawing.Size(309, 104);
            this.gbxLinkedDevices.TabIndex = 0;
            this.gbxLinkedDevices.TabStop = false;
            this.gbxLinkedDevices.Text = "Linked Devices";
            // 
            // lvDevices
            // 
            this.lvDevices.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chDeviceName});
            this.lvDevices.Location = new System.Drawing.Point(6, 19);
            this.lvDevices.Name = "lvDevices";
            this.lvDevices.Size = new System.Drawing.Size(297, 79);
            this.lvDevices.TabIndex = 3;
            this.lvDevices.UseCompatibleStateImageBehavior = false;
            this.lvDevices.View = System.Windows.Forms.View.Details;
            // 
            // chDeviceName
            // 
            this.chDeviceName.Text = "Name";
            this.chDeviceName.Width = 293;
            // 
            // gbxLinkedDataSources
            // 
            this.gbxLinkedDataSources.Controls.Add(this.lvDataSources);
            this.gbxLinkedDataSources.Location = new System.Drawing.Point(327, 154);
            this.gbxLinkedDataSources.Name = "gbxLinkedDataSources";
            this.gbxLinkedDataSources.Size = new System.Drawing.Size(309, 104);
            this.gbxLinkedDataSources.TabIndex = 1;
            this.gbxLinkedDataSources.TabStop = false;
            this.gbxLinkedDataSources.Text = "Linked Data Sources";
            // 
            // lvDataSources
            // 
            this.lvDataSources.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chDataSourceName});
            this.lvDataSources.Location = new System.Drawing.Point(6, 19);
            this.lvDataSources.Name = "lvDataSources";
            this.lvDataSources.Size = new System.Drawing.Size(297, 79);
            this.lvDataSources.TabIndex = 2;
            this.lvDataSources.UseCompatibleStateImageBehavior = false;
            this.lvDataSources.View = System.Windows.Forms.View.Details;
            // 
            // chDataSourceName
            // 
            this.chDataSourceName.Text = "Name";
            this.chDataSourceName.Width = 292;
            // 
            // lvTags
            // 
            this.lvTags.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chName,
            this.chId,
            this.chOwner});
            this.lvTags.FullRowSelect = true;
            this.lvTags.Location = new System.Drawing.Point(18, 12);
            this.lvTags.MultiSelect = false;
            this.lvTags.Name = "lvTags";
            this.lvTags.Size = new System.Drawing.Size(612, 136);
            this.lvTags.TabIndex = 2;
            this.lvTags.UseCompatibleStateImageBehavior = false;
            this.lvTags.View = System.Windows.Forms.View.Details;
            this.lvTags.SelectedIndexChanged += new System.EventHandler(this.ListViewTags_SelectedIndexChanged);
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 168;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 317;
            // 
            // chOwner
            // 
            this.chOwner.Text = "Owner";
            this.chOwner.Width = 117;
            // 
            // btnNewTag
            // 
            this.btnNewTag.Location = new System.Drawing.Point(636, 12);
            this.btnNewTag.Name = "btnNewTag";
            this.btnNewTag.Size = new System.Drawing.Size(75, 23);
            this.btnNewTag.TabIndex = 3;
            this.btnNewTag.Text = "New Tag";
            this.btnNewTag.UseVisualStyleBackColor = true;
            this.btnNewTag.Click += new System.EventHandler(this.ButtonNewTag_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(636, 41);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(75, 23);
            this.btnDelete.TabIndex = 4;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.ButtonDelete_Click);
            // 
            // btnMerge
            // 
            this.btnMerge.Location = new System.Drawing.Point(635, 99);
            this.btnMerge.Name = "btnMerge";
            this.btnMerge.Size = new System.Drawing.Size(75, 23);
            this.btnMerge.TabIndex = 5;
            this.btnMerge.Text = "Merge";
            this.btnMerge.UseVisualStyleBackColor = true;
            this.btnMerge.Click += new System.EventHandler(this.ButtonMerge_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(635, 128);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(75, 23);
            this.btnRefresh.TabIndex = 6;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // btnModify
            // 
            this.btnModify.Location = new System.Drawing.Point(636, 70);
            this.btnModify.Name = "btnModify";
            this.btnModify.Size = new System.Drawing.Size(75, 23);
            this.btnModify.TabIndex = 7;
            this.btnModify.Text = "Modify";
            this.btnModify.UseVisualStyleBackColor = true;
            this.btnModify.Click += new System.EventHandler(this.ButtonModify_Click);
            // 
            // TagManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(722, 268);
            this.Controls.Add(this.btnModify);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnMerge);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnNewTag);
            this.Controls.Add(this.lvTags);
            this.Controls.Add(this.gbxLinkedDataSources);
            this.Controls.Add(this.gbxLinkedDevices);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "TagManagerForm";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Tag Manager";
            this.gbxLinkedDevices.ResumeLayout(false);
            this.gbxLinkedDataSources.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbxLinkedDevices;
        private System.Windows.Forms.ListView lvDevices;
        private System.Windows.Forms.GroupBox gbxLinkedDataSources;
        private System.Windows.Forms.ListView lvDataSources;
        private System.Windows.Forms.ListView lvTags;
        private System.Windows.Forms.Button btnNewTag;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnMerge;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chOwner;
        private System.Windows.Forms.ColumnHeader chDeviceName;
        private System.Windows.Forms.ColumnHeader chDataSourceName;
        private System.Windows.Forms.Button btnModify;
    }
}