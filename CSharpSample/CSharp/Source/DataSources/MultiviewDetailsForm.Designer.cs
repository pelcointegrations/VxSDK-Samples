namespace SDKSampleApp.Source
{
    partial class MultiviewDetailsForm
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
            this.lvUserInfo = new System.Windows.Forms.ListView();
            this.chFirstName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chLastName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chEmployeeId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chNote = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chPhoneNumbers = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnClose = new System.Windows.Forms.Button();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lvUserInfo
            // 
            this.lvUserInfo.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chName,
            this.chFirstName,
            this.chLastName,
            this.chEmployeeId,
            this.chNote,
            this.chPhoneNumbers});
            this.lvUserInfo.FullRowSelect = true;
            this.lvUserInfo.Location = new System.Drawing.Point(12, 12);
            this.lvUserInfo.MultiSelect = false;
            this.lvUserInfo.Name = "lvUserInfo";
            this.lvUserInfo.Size = new System.Drawing.Size(1101, 299);
            this.lvUserInfo.TabIndex = 9;
            this.lvUserInfo.UseCompatibleStateImageBehavior = false;
            this.lvUserInfo.View = System.Windows.Forms.View.Details;
            // 
            // chFirstName
            // 
            this.chFirstName.Text = "First";
            this.chFirstName.Width = 100;
            // 
            // chLastName
            // 
            this.chLastName.Text = "Last";
            this.chLastName.Width = 100;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 200;
            // 
            // chEmployeeId
            // 
            this.chEmployeeId.Text = "ID";
            this.chEmployeeId.Width = 75;
            // 
            // chNote
            // 
            this.chNote.Text = "Note";
            this.chNote.Width = 300;
            // 
            // chPhoneNumbers
            // 
            this.chPhoneNumbers.Text = "Phone Numbers";
            this.chPhoneNumbers.Width = 300;
            // 
            // btnClose
            // 
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnClose.Location = new System.Drawing.Point(1037, 317);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 10;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(956, 316);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(75, 23);
            this.btnRefresh.TabIndex = 11;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // MultiviewDetailsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1124, 351);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.lvUserInfo);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MultiviewDetailsForm";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Multiview User Information";
            this.TopMost = true;
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView lvUserInfo;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chFirstName;
        private System.Windows.Forms.ColumnHeader chLastName;
        private System.Windows.Forms.ColumnHeader chEmployeeId;
        private System.Windows.Forms.ColumnHeader chNote;
        private System.Windows.Forms.ColumnHeader chPhoneNumbers;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.Button btnRefresh;
    }
}