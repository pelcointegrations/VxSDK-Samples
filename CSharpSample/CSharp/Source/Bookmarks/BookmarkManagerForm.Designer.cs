namespace SDKSampleApp.Source
{
    partial class BookmarkManagerForm
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
            this.lvBookmarkManager = new System.Windows.Forms.ListView();
            this.chCheckBox = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chDescription = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chTime = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnNewBookmark = new System.Windows.Forms.Button();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lvBookmarkManager
            // 
            this.lvBookmarkManager.CheckBoxes = true;
            this.lvBookmarkManager.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chCheckBox,
            this.chDescription,
            this.chTime,
            this.chId,
            this.chName});
            this.lvBookmarkManager.FullRowSelect = true;
            this.lvBookmarkManager.GridLines = true;
            this.lvBookmarkManager.Location = new System.Drawing.Point(12, 12);
            this.lvBookmarkManager.MultiSelect = false;
            this.lvBookmarkManager.Name = "lvBookmarkManager";
            this.lvBookmarkManager.Size = new System.Drawing.Size(703, 320);
            this.lvBookmarkManager.TabIndex = 0;
            this.lvBookmarkManager.UseCompatibleStateImageBehavior = false;
            this.lvBookmarkManager.View = System.Windows.Forms.View.Details;
            this.lvBookmarkManager.ItemCheck += new System.Windows.Forms.ItemCheckEventHandler(this.ListViewBookmarkManager_ItemCheck);
            // 
            // chCheckBox
            // 
            this.chCheckBox.Text = " ";
            this.chCheckBox.Width = 30;
            // 
            // chDescription
            // 
            this.chDescription.Text = "Description";
            this.chDescription.Width = 155;
            // 
            // chTime
            // 
            this.chTime.Text = "Time";
            this.chTime.Width = 150;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 224;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 135;
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(722, 41);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(89, 23);
            this.btnDelete.TabIndex = 2;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.ButtonDelete_Click);
            // 
            // btnNewBookmark
            // 
            this.btnNewBookmark.Location = new System.Drawing.Point(721, 12);
            this.btnNewBookmark.Name = "btnNewBookmark";
            this.btnNewBookmark.Size = new System.Drawing.Size(90, 23);
            this.btnNewBookmark.TabIndex = 3;
            this.btnNewBookmark.Text = "New Bookmark";
            this.btnNewBookmark.UseVisualStyleBackColor = true;
            this.btnNewBookmark.Click += new System.EventHandler(this.ButtonNewBookmark_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(722, 70);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(89, 23);
            this.btnRefresh.TabIndex = 4;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // BookmarkManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(819, 350);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnNewBookmark);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.lvBookmarkManager);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "BookmarkManagerForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Bookmark Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView lvBookmarkManager;
        private System.Windows.Forms.ColumnHeader chCheckBox;
        private System.Windows.Forms.ColumnHeader chDescription;
        private System.Windows.Forms.ColumnHeader chTime;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnNewBookmark;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.ColumnHeader chName;
    }
}