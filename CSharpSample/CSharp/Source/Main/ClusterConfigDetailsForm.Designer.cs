namespace SDKSampleApp.Source
{
    partial class ClusterConfigDetailsForm
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
            this.lvClusterConfigDetails = new System.Windows.Forms.ListView();
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chValue = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chBlank = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // btnClose
            // 
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnClose.Location = new System.Drawing.Point(401, 367);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 5;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            // 
            // lvClusterConfigDetails
            // 
            this.lvClusterConfigDetails.Activation = System.Windows.Forms.ItemActivation.TwoClick;
            this.lvClusterConfigDetails.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chBlank,
            this.chName,
            this.chValue});
            this.lvClusterConfigDetails.GridLines = true;
            this.lvClusterConfigDetails.HeaderStyle = System.Windows.Forms.ColumnHeaderStyle.None;
            this.lvClusterConfigDetails.Location = new System.Drawing.Point(12, 12);
            this.lvClusterConfigDetails.MultiSelect = false;
            this.lvClusterConfigDetails.Name = "lvClusterConfigDetails";
            this.lvClusterConfigDetails.Size = new System.Drawing.Size(464, 349);
            this.lvClusterConfigDetails.TabIndex = 4;
            this.lvClusterConfigDetails.UseCompatibleStateImageBehavior = false;
            this.lvClusterConfigDetails.View = System.Windows.Forms.View.Details;
            // 
            // chName
            // 
            this.chName.DisplayIndex = 0;
            this.chName.Text = "Name";
            this.chName.Width = 160;
            // 
            // chValue
            // 
            this.chValue.DisplayIndex = 1;
            this.chValue.Text = "Value";
            this.chValue.Width = 300;
            // 
            // chBlank
            // 
            this.chBlank.DisplayIndex = 2;
            this.chBlank.Width = 0;
            // 
            // ClusterConfigDetailsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(488, 396);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.lvClusterConfigDetails);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ClusterConfigDetailsForm";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Cluster Configuration Details";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.ListView lvClusterConfigDetails;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chValue;
        private System.Windows.Forms.ColumnHeader chBlank;
    }
}