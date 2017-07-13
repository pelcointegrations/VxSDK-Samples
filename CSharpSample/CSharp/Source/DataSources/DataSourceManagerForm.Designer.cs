namespace SDKSampleApp.Source
{
    partial class DataSourceManagerForm
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
            this.btnRefresh = new System.Windows.Forms.Button();
            this.btnModify = new System.Windows.Forms.Button();
            this.lvDataSources = new System.Windows.Forms.ListView();
            this.chNumber = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chIp = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chState = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnManageLinks = new System.Windows.Forms.Button();
            this.btnAutoNumber = new System.Windows.Forms.Button();
            this.btnViewerInfo = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(1072, 128);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(83, 23);
            this.btnRefresh.TabIndex = 12;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // btnModify
            // 
            this.btnModify.Location = new System.Drawing.Point(1072, 12);
            this.btnModify.Name = "btnModify";
            this.btnModify.Size = new System.Drawing.Size(83, 23);
            this.btnModify.TabIndex = 11;
            this.btnModify.Text = "Modify";
            this.btnModify.UseVisualStyleBackColor = true;
            this.btnModify.Click += new System.EventHandler(this.ButtonModify_Click);
            // 
            // lvDataSources
            // 
            this.lvDataSources.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chNumber,
            this.chType,
            this.chName,
            this.chIp,
            this.chId,
            this.chState});
            this.lvDataSources.FullRowSelect = true;
            this.lvDataSources.Location = new System.Drawing.Point(12, 12);
            this.lvDataSources.MultiSelect = false;
            this.lvDataSources.Name = "lvDataSources";
            this.lvDataSources.Size = new System.Drawing.Size(1055, 395);
            this.lvDataSources.TabIndex = 8;
            this.lvDataSources.UseCompatibleStateImageBehavior = false;
            this.lvDataSources.View = System.Windows.Forms.View.Details;
            // 
            // chNumber
            // 
            this.chNumber.Text = "Number";
            this.chNumber.Width = 64;
            // 
            // chType
            // 
            this.chType.Text = "Type";
            this.chType.Width = 70;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 330;
            // 
            // chIp
            // 
            this.chIp.Text = "IP";
            this.chIp.Width = 120;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 350;
            // 
            // chState
            // 
            this.chState.Text = "State";
            this.chState.Width = 75;
            // 
            // btnManageLinks
            // 
            this.btnManageLinks.Location = new System.Drawing.Point(1072, 41);
            this.btnManageLinks.Name = "btnManageLinks";
            this.btnManageLinks.Size = new System.Drawing.Size(83, 23);
            this.btnManageLinks.TabIndex = 13;
            this.btnManageLinks.Text = "Manage Links";
            this.btnManageLinks.UseVisualStyleBackColor = true;
            this.btnManageLinks.Click += new System.EventHandler(this.ButtonManageLinks_Click);
            // 
            // btnAutoNumber
            // 
            this.btnAutoNumber.Location = new System.Drawing.Point(1073, 70);
            this.btnAutoNumber.Name = "btnAutoNumber";
            this.btnAutoNumber.Size = new System.Drawing.Size(83, 23);
            this.btnAutoNumber.TabIndex = 14;
            this.btnAutoNumber.Text = "Auto-Number";
            this.btnAutoNumber.UseVisualStyleBackColor = true;
            this.btnAutoNumber.Click += new System.EventHandler(this.ButtonAutoNumber_Click);
            // 
            // btnViewerInfo
            // 
            this.btnViewerInfo.Location = new System.Drawing.Point(1072, 99);
            this.btnViewerInfo.Name = "btnViewerInfo";
            this.btnViewerInfo.Size = new System.Drawing.Size(83, 23);
            this.btnViewerInfo.TabIndex = 15;
            this.btnViewerInfo.Text = "Viewer Info";
            this.btnViewerInfo.UseVisualStyleBackColor = true;
            this.btnViewerInfo.Click += new System.EventHandler(this.ButtonViewerInfo_Click);
            // 
            // DataSourceManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1160, 419);
            this.Controls.Add(this.btnViewerInfo);
            this.Controls.Add(this.btnAutoNumber);
            this.Controls.Add(this.btnManageLinks);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnModify);
            this.Controls.Add(this.lvDataSources);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "DataSourceManagerForm";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Data Source Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.Button btnModify;
        private System.Windows.Forms.ListView lvDataSources;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chNumber;
        private System.Windows.Forms.ColumnHeader chState;
        private System.Windows.Forms.ColumnHeader chType;
        private System.Windows.Forms.ColumnHeader chIp;
        private System.Windows.Forms.Button btnManageLinks;
        private System.Windows.Forms.Button btnAutoNumber;
        private System.Windows.Forms.Button btnViewerInfo;
    }
}