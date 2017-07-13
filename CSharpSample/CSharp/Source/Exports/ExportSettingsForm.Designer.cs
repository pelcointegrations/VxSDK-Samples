namespace SDKSampleApp.Source
{
    partial class ExportSettingsForm
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
            this.gbxPassword = new System.Windows.Forms.GroupBox();
            this.tbxExportPassword = new System.Windows.Forms.TextBox();
            this.gbxName = new System.Windows.Forms.GroupBox();
            this.tbxExportName = new System.Windows.Forms.TextBox();
            this.btnStartExport = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.gbxPassword.SuspendLayout();
            this.gbxName.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbxPassword
            // 
            this.gbxPassword.Controls.Add(this.tbxExportPassword);
            this.gbxPassword.Location = new System.Drawing.Point(12, 69);
            this.gbxPassword.Name = "gbxPassword";
            this.gbxPassword.Size = new System.Drawing.Size(260, 51);
            this.gbxPassword.TabIndex = 18;
            this.gbxPassword.TabStop = false;
            this.gbxPassword.Text = "Export Password";
            // 
            // tbxExportPassword
            // 
            this.tbxExportPassword.Location = new System.Drawing.Point(6, 19);
            this.tbxExportPassword.Name = "tbxExportPassword";
            this.tbxExportPassword.Size = new System.Drawing.Size(248, 20);
            this.tbxExportPassword.TabIndex = 8;
            // 
            // gbxName
            // 
            this.gbxName.Controls.Add(this.tbxExportName);
            this.gbxName.Location = new System.Drawing.Point(12, 12);
            this.gbxName.Name = "gbxName";
            this.gbxName.Size = new System.Drawing.Size(260, 51);
            this.gbxName.TabIndex = 17;
            this.gbxName.TabStop = false;
            this.gbxName.Text = "Export Name";
            // 
            // tbxExportName
            // 
            this.tbxExportName.Location = new System.Drawing.Point(6, 19);
            this.tbxExportName.Name = "tbxExportName";
            this.tbxExportName.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.tbxExportName.Size = new System.Drawing.Size(248, 20);
            this.tbxExportName.TabIndex = 8;
            this.tbxExportName.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // btnStartExport
            // 
            this.btnStartExport.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnStartExport.Location = new System.Drawing.Point(197, 126);
            this.btnStartExport.Name = "btnStartExport";
            this.btnStartExport.Size = new System.Drawing.Size(75, 23);
            this.btnStartExport.TabIndex = 15;
            this.btnStartExport.Text = "Export";
            this.btnStartExport.UseVisualStyleBackColor = true;
            this.btnStartExport.Click += new System.EventHandler(this.ButtonStartExport_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(12, 126);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 19;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // ExportSettingsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 158);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.gbxPassword);
            this.Controls.Add(this.gbxName);
            this.Controls.Add(this.btnStartExport);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ExportSettingsForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "ExportSettingsForm";
            this.gbxPassword.ResumeLayout(false);
            this.gbxPassword.PerformLayout();
            this.gbxName.ResumeLayout(false);
            this.gbxName.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbxPassword;
        private System.Windows.Forms.TextBox tbxExportPassword;
        private System.Windows.Forms.GroupBox gbxName;
        private System.Windows.Forms.TextBox tbxExportName;
        private System.Windows.Forms.Button btnStartExport;
        private System.Windows.Forms.Button btnCancel;
    }
}