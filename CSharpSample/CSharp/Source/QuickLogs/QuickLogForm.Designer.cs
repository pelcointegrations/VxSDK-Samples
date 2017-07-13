namespace SDKSampleApp.Source
{
    partial class QuickLogForm
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
            this.btnActions = new System.Windows.Forms.Button();
            this.lblCurrentStatus = new System.Windows.Forms.Label();
            this.lblStatus = new System.Windows.Forms.Label();
            this.bgWorker = new System.ComponentModel.BackgroundWorker();
            this.SuspendLayout();
            // 
            // btnActions
            // 
            this.btnActions.Location = new System.Drawing.Point(87, 42);
            this.btnActions.Name = "btnActions";
            this.btnActions.Size = new System.Drawing.Size(75, 23);
            this.btnActions.TabIndex = 21;
            this.btnActions.Text = "Export Logs";
            this.btnActions.UseVisualStyleBackColor = true;
            this.btnActions.Click += new System.EventHandler(this.ButtonActions_Click);
            // 
            // lblCurrentStatus
            // 
            this.lblCurrentStatus.AutoSize = true;
            this.lblCurrentStatus.Location = new System.Drawing.Point(55, 9);
            this.lblCurrentStatus.Name = "lblCurrentStatus";
            this.lblCurrentStatus.Size = new System.Drawing.Size(0, 13);
            this.lblCurrentStatus.TabIndex = 23;
            // 
            // lblStatus
            // 
            this.lblStatus.AutoSize = true;
            this.lblStatus.Location = new System.Drawing.Point(9, 9);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(40, 13);
            this.lblStatus.TabIndex = 22;
            this.lblStatus.Text = "Status:";
            // 
            // bgWorker
            // 
            this.bgWorker.DoWork += new System.ComponentModel.DoWorkEventHandler(this.BackgroundWorker_DoWork);
            // 
            // QuickLogForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(249, 77);
            this.Controls.Add(this.lblCurrentStatus);
            this.Controls.Add(this.lblStatus);
            this.Controls.Add(this.btnActions);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "QuickLogForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Generate Quick Log";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnActions;
        private System.Windows.Forms.Label lblCurrentStatus;
        private System.Windows.Forms.Label lblStatus;
        private System.ComponentModel.BackgroundWorker bgWorker;
    }
}