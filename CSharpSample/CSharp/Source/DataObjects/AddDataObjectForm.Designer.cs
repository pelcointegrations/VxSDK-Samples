namespace SDKSampleApp.Source
{
    partial class AddDataObjectForm
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
            this.gbxData = new System.Windows.Forms.GroupBox();
            this.tbxData = new System.Windows.Forms.TextBox();
            this.lblClientType = new System.Windows.Forms.Label();
            this.tbxClientType = new System.Windows.Forms.TextBox();
            this.ckbxPrivate = new System.Windows.Forms.CheckBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnOk = new System.Windows.Forms.Button();
            this.gbxSettings = new System.Windows.Forms.GroupBox();
            this.gbxData.SuspendLayout();
            this.gbxSettings.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbxData
            // 
            this.gbxData.Controls.Add(this.tbxData);
            this.gbxData.Location = new System.Drawing.Point(12, 100);
            this.gbxData.Name = "gbxData";
            this.gbxData.Size = new System.Drawing.Size(583, 234);
            this.gbxData.TabIndex = 21;
            this.gbxData.TabStop = false;
            this.gbxData.Text = "Data";
            // 
            // tbxData
            // 
            this.tbxData.BackColor = System.Drawing.SystemColors.Window;
            this.tbxData.Location = new System.Drawing.Point(6, 19);
            this.tbxData.Multiline = true;
            this.tbxData.Name = "tbxData";
            this.tbxData.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbxData.Size = new System.Drawing.Size(571, 209);
            this.tbxData.TabIndex = 19;
            // 
            // lblClientType
            // 
            this.lblClientType.AutoSize = true;
            this.lblClientType.Location = new System.Drawing.Point(6, 27);
            this.lblClientType.Name = "lblClientType";
            this.lblClientType.Size = new System.Drawing.Size(66, 13);
            this.lblClientType.TabIndex = 22;
            this.lblClientType.Text = "Client Type: ";
            // 
            // tbxClientType
            // 
            this.tbxClientType.Location = new System.Drawing.Point(78, 24);
            this.tbxClientType.Name = "tbxClientType";
            this.tbxClientType.Size = new System.Drawing.Size(243, 20);
            this.tbxClientType.TabIndex = 23;
            // 
            // ckbxPrivate
            // 
            this.ckbxPrivate.AutoSize = true;
            this.ckbxPrivate.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.ckbxPrivate.Location = new System.Drawing.Point(27, 50);
            this.ckbxPrivate.Name = "ckbxPrivate";
            this.ckbxPrivate.Size = new System.Drawing.Size(65, 17);
            this.ckbxPrivate.TabIndex = 24;
            this.ckbxPrivate.Text = "Private: ";
            this.ckbxPrivate.UseVisualStyleBackColor = true;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(471, 340);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(59, 23);
            this.btnCancel.TabIndex = 26;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnOk
            // 
            this.btnOk.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnOk.Location = new System.Drawing.Point(536, 340);
            this.btnOk.Name = "btnOk";
            this.btnOk.Size = new System.Drawing.Size(59, 23);
            this.btnOk.TabIndex = 25;
            this.btnOk.Text = "Ok";
            this.btnOk.UseVisualStyleBackColor = true;
            this.btnOk.Click += new System.EventHandler(this.ButtonOk_Click);
            // 
            // gbxSettings
            // 
            this.gbxSettings.Controls.Add(this.tbxClientType);
            this.gbxSettings.Controls.Add(this.lblClientType);
            this.gbxSettings.Controls.Add(this.ckbxPrivate);
            this.gbxSettings.Location = new System.Drawing.Point(12, 12);
            this.gbxSettings.Name = "gbxSettings";
            this.gbxSettings.Size = new System.Drawing.Size(344, 82);
            this.gbxSettings.TabIndex = 27;
            this.gbxSettings.TabStop = false;
            this.gbxSettings.Text = "Settings";
            // 
            // AddDataObjectForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(607, 375);
            this.Controls.Add(this.gbxSettings);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnOk);
            this.Controls.Add(this.gbxData);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddDataObjectForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Add Data Object";
            this.gbxData.ResumeLayout(false);
            this.gbxData.PerformLayout();
            this.gbxSettings.ResumeLayout(false);
            this.gbxSettings.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbxData;
        private System.Windows.Forms.TextBox tbxData;
        private System.Windows.Forms.Label lblClientType;
        private System.Windows.Forms.TextBox tbxClientType;
        private System.Windows.Forms.CheckBox ckbxPrivate;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnOk;
        private System.Windows.Forms.GroupBox gbxSettings;
    }
}