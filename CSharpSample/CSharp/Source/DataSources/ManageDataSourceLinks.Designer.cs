namespace SDKSampleApp.Source
{
    partial class ManageDataSourceLinksForm
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
            this.lvDataSources = new System.Windows.Forms.ListView();
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chIp = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chNumber = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chLinked = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnLink = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lvDataSources
            // 
            this.lvDataSources.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chNumber,
            this.chName,
            this.chIp,
            this.chLinked});
            this.lvDataSources.FullRowSelect = true;
            this.lvDataSources.Location = new System.Drawing.Point(10, 11);
            this.lvDataSources.MultiSelect = false;
            this.lvDataSources.Name = "lvDataSources";
            this.lvDataSources.Size = new System.Drawing.Size(645, 258);
            this.lvDataSources.TabIndex = 9;
            this.lvDataSources.UseCompatibleStateImageBehavior = false;
            this.lvDataSources.View = System.Windows.Forms.View.Details;
            this.lvDataSources.SelectedIndexChanged += new System.EventHandler(this.ListViewDataSources_SelectedIndexChanged);
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 350;
            // 
            // chIp
            // 
            this.chIp.Text = "IP";
            this.chIp.Width = 120;
            // 
            // chNumber
            // 
            this.chNumber.Text = "Number";
            this.chNumber.Width = 94;
            // 
            // chLinked
            // 
            this.chLinked.Text = "Linked";
            // 
            // btnLink
            // 
            this.btnLink.Location = new System.Drawing.Point(660, 11);
            this.btnLink.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnLink.Name = "btnLink";
            this.btnLink.Size = new System.Drawing.Size(56, 26);
            this.btnLink.TabIndex = 10;
            this.btnLink.Text = "Link";
            this.btnLink.UseVisualStyleBackColor = true;
            this.btnLink.Click += new System.EventHandler(this.ButtonLink_Click);
            // 
            // ManageDataSourceLinksForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(723, 275);
            this.Controls.Add(this.btnLink);
            this.Controls.Add(this.lvDataSources);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ManageDataSourceLinksForm";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Manage Data Source Links";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView lvDataSources;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chIp;
        private System.Windows.Forms.ColumnHeader chNumber;
        private System.Windows.Forms.ColumnHeader chLinked;
        private System.Windows.Forms.Button btnLink;
    }
}