namespace SDKSampleApp.Source
{
    partial class ExportManagerForm
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
            this.lvExportManager = new System.Windows.Forms.ListView();
            this.chCheckBox = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chCreatedOn = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chCreatedBy = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chFileSize = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chStatus = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnDownload = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnNewExport = new System.Windows.Forms.Button();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lvExportManager
            // 
            this.lvExportManager.CheckBoxes = true;
            this.lvExportManager.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chCheckBox,
            this.chName,
            this.chCreatedOn,
            this.chCreatedBy,
            this.chFileSize,
            this.chStatus});
            this.lvExportManager.FullRowSelect = true;
            this.lvExportManager.GridLines = true;
            this.lvExportManager.Location = new System.Drawing.Point(12, 12);
            this.lvExportManager.MultiSelect = false;
            this.lvExportManager.Name = "lvExportManager";
            this.lvExportManager.Size = new System.Drawing.Size(754, 320);
            this.lvExportManager.TabIndex = 0;
            this.lvExportManager.UseCompatibleStateImageBehavior = false;
            this.lvExportManager.View = System.Windows.Forms.View.Details;
            this.lvExportManager.ItemCheck += new System.Windows.Forms.ItemCheckEventHandler(this.ListViewExportManager_ItemCheck);
            // 
            // chCheckBox
            // 
            this.chCheckBox.Text = " ";
            this.chCheckBox.Width = 30;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 150;
            // 
            // chCreatedOn
            // 
            this.chCreatedOn.Text = "Created on";
            this.chCreatedOn.Width = 150;
            // 
            // chCreatedBy
            // 
            this.chCreatedBy.Text = "Created by";
            this.chCreatedBy.Width = 150;
            // 
            // chFileSize
            // 
            this.chFileSize.Text = "File size";
            this.chFileSize.Width = 150;
            // 
            // chStatus
            // 
            this.chStatus.Text = "Status";
            this.chStatus.Width = 120;
            // 
            // btnDownload
            // 
            this.btnDownload.Location = new System.Drawing.Point(772, 12);
            this.btnDownload.Name = "btnDownload";
            this.btnDownload.Size = new System.Drawing.Size(75, 23);
            this.btnDownload.TabIndex = 1;
            this.btnDownload.Text = "Download";
            this.btnDownload.UseVisualStyleBackColor = true;
            this.btnDownload.Click += new System.EventHandler(this.ButtonDownload_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(772, 41);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(75, 23);
            this.btnDelete.TabIndex = 2;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.ButtonDelete_Click);
            // 
            // btnNewExport
            // 
            this.btnNewExport.Location = new System.Drawing.Point(772, 309);
            this.btnNewExport.Name = "btnNewExport";
            this.btnNewExport.Size = new System.Drawing.Size(75, 23);
            this.btnNewExport.TabIndex = 3;
            this.btnNewExport.Text = "New Export";
            this.btnNewExport.UseVisualStyleBackColor = true;
            this.btnNewExport.Click += new System.EventHandler(this.ButtonNewExport_Click);
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.DefaultExt = "zip";
            this.saveFileDialog.FileName = ".zip";
            this.saveFileDialog.Title = "Save Export";
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(772, 70);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(75, 23);
            this.btnRefresh.TabIndex = 4;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // ExportManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(858, 350);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnNewExport);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnDownload);
            this.Controls.Add(this.lvExportManager);
            this.Name = "ExportManagerForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Export Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView lvExportManager;
        private System.Windows.Forms.ColumnHeader chCheckBox;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chCreatedOn;
        private System.Windows.Forms.ColumnHeader chCreatedBy;
        private System.Windows.Forms.ColumnHeader chFileSize;
        private System.Windows.Forms.ColumnHeader chStatus;
        private System.Windows.Forms.Button btnDownload;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnNewExport;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.Button btnRefresh;
    }
}