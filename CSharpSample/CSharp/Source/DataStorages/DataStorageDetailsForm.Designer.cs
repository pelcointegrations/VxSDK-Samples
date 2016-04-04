namespace SDKSampleApp.Source
{
    partial class DataStorageDetailsForm
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
            this.btnClose = new System.Windows.Forms.Button();
            this.lvDataStorageDetails = new System.Windows.Forms.ListView();
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chValue = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chBlank = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // btnClose
            // 
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnClose.Location = new System.Drawing.Point(410, 367);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 5;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            // 
            // lvDataStorageDetails
            // 
            this.lvDataStorageDetails.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chBlank,
            this.chName,
            this.chValue});
            this.lvDataStorageDetails.GridLines = true;
            this.lvDataStorageDetails.HeaderStyle = System.Windows.Forms.ColumnHeaderStyle.None;
            this.lvDataStorageDetails.Location = new System.Drawing.Point(12, 12);
            this.lvDataStorageDetails.MultiSelect = false;
            this.lvDataStorageDetails.Name = "lvDataStorageDetails";
            this.lvDataStorageDetails.Size = new System.Drawing.Size(473, 349);
            this.lvDataStorageDetails.TabIndex = 4;
            this.lvDataStorageDetails.UseCompatibleStateImageBehavior = false;
            this.lvDataStorageDetails.View = System.Windows.Forms.View.Details;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 120;
            // 
            // chValue
            // 
            this.chValue.Text = "Value";
            this.chValue.Width = 347;
            // 
            // chBlank
            // 
            this.chBlank.Text = "";
            this.chBlank.Width = 0;
            // 
            // DataStorageDetailsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(498, 401);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.lvDataStorageDetails);
            this.Name = "DataStorageDetailsForm";
            this.Text = "Data Storage Details";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.ListView lvDataStorageDetails;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chValue;
        private System.Windows.Forms.ColumnHeader chBlank;
    }
}