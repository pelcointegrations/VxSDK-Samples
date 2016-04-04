namespace SDKSampleApp.Source
{
    partial class DataObjectManagerForm
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
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnNewDataObject = new System.Windows.Forms.Button();
            this.lvDataObjects = new System.Windows.Forms.ListView();
            this.chClientType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chOwner = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.tbxData = new System.Windows.Forms.TextBox();
            this.gbxData = new System.Windows.Forms.GroupBox();
            this.gbxData.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(601, 70);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(97, 23);
            this.btnRefresh.TabIndex = 18;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(600, 41);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(97, 23);
            this.btnDelete.TabIndex = 16;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.ButtonDelete_Click);
            // 
            // btnNewDataObject
            // 
            this.btnNewDataObject.Location = new System.Drawing.Point(601, 12);
            this.btnNewDataObject.Name = "btnNewDataObject";
            this.btnNewDataObject.Size = new System.Drawing.Size(97, 23);
            this.btnNewDataObject.TabIndex = 15;
            this.btnNewDataObject.Text = "New Data Object";
            this.btnNewDataObject.UseVisualStyleBackColor = true;
            this.btnNewDataObject.Click += new System.EventHandler(this.ButtonNewDataObject_Click);
            // 
            // lvDataObjects
            // 
            this.lvDataObjects.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chClientType,
            this.chId,
            this.chOwner});
            this.lvDataObjects.FullRowSelect = true;
            this.lvDataObjects.Location = new System.Drawing.Point(12, 12);
            this.lvDataObjects.MultiSelect = false;
            this.lvDataObjects.Name = "lvDataObjects";
            this.lvDataObjects.Size = new System.Drawing.Size(583, 110);
            this.lvDataObjects.TabIndex = 14;
            this.lvDataObjects.UseCompatibleStateImageBehavior = false;
            this.lvDataObjects.View = System.Windows.Forms.View.Details;
            this.lvDataObjects.SelectedIndexChanged += new System.EventHandler(this.ListViewDataObjects_SelectedIndexChanged);
            // 
            // chClientType
            // 
            this.chClientType.Text = "Client Type";
            this.chClientType.Width = 209;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 275;
            // 
            // chOwner
            // 
            this.chOwner.Text = "Owner";
            this.chOwner.Width = 94;
            // 
            // tbxData
            // 
            this.tbxData.BackColor = System.Drawing.SystemColors.Window;
            this.tbxData.Location = new System.Drawing.Point(6, 19);
            this.tbxData.Multiline = true;
            this.tbxData.Name = "tbxData";
            this.tbxData.ReadOnly = true;
            this.tbxData.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbxData.Size = new System.Drawing.Size(571, 209);
            this.tbxData.TabIndex = 19;
            // 
            // gbxData
            // 
            this.gbxData.Controls.Add(this.tbxData);
            this.gbxData.Location = new System.Drawing.Point(12, 128);
            this.gbxData.Name = "gbxData";
            this.gbxData.Size = new System.Drawing.Size(583, 234);
            this.gbxData.TabIndex = 20;
            this.gbxData.TabStop = false;
            this.gbxData.Text = "Data";
            // 
            // DataObjectManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(709, 368);
            this.Controls.Add(this.gbxData);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnNewDataObject);
            this.Controls.Add(this.lvDataObjects);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "DataObjectManagerForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Data Object Manager";
            this.gbxData.ResumeLayout(false);
            this.gbxData.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnNewDataObject;
        private System.Windows.Forms.ListView lvDataObjects;
        private System.Windows.Forms.ColumnHeader chClientType;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chOwner;
        private System.Windows.Forms.TextBox tbxData;
        private System.Windows.Forms.GroupBox gbxData;
    }
}