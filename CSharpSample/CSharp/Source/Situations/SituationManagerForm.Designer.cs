namespace SDKSampleApp.Source
{
    partial class SituationManagerForm
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
            this.lvSituationManager = new System.Windows.Forms.ListView();
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnNewSituation = new System.Windows.Forms.Button();
            this.btnDeleteSituation = new System.Windows.Forms.Button();
            this.btnViewSituation = new System.Windows.Forms.Button();
            this.btnModifyNotifications = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lvSituationManager
            // 
            this.lvSituationManager.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4});
            this.lvSituationManager.FullRowSelect = true;
            this.lvSituationManager.GridLines = true;
            this.lvSituationManager.HideSelection = false;
            this.lvSituationManager.Location = new System.Drawing.Point(12, 12);
            this.lvSituationManager.MultiSelect = false;
            this.lvSituationManager.Name = "lvSituationManager";
            this.lvSituationManager.Size = new System.Drawing.Size(632, 320);
            this.lvSituationManager.TabIndex = 1;
            this.lvSituationManager.UseCompatibleStateImageBehavior = false;
            this.lvSituationManager.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Type";
            this.columnHeader2.Width = 280;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Severity";
            this.columnHeader3.Width = 50;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Source Device ID";
            this.columnHeader4.Width = 266;
            // 
            // btnNewSituation
            // 
            this.btnNewSituation.Location = new System.Drawing.Point(650, 12);
            this.btnNewSituation.Name = "btnNewSituation";
            this.btnNewSituation.Size = new System.Drawing.Size(107, 23);
            this.btnNewSituation.TabIndex = 4;
            this.btnNewSituation.Text = "Add New";
            this.btnNewSituation.UseVisualStyleBackColor = true;
            this.btnNewSituation.Click += new System.EventHandler(this.ButtonNewSituation_Click);
            // 
            // btnDeleteSituation
            // 
            this.btnDeleteSituation.Location = new System.Drawing.Point(650, 99);
            this.btnDeleteSituation.Name = "btnDeleteSituation";
            this.btnDeleteSituation.Size = new System.Drawing.Size(107, 23);
            this.btnDeleteSituation.TabIndex = 5;
            this.btnDeleteSituation.Text = "Delete";
            this.btnDeleteSituation.UseVisualStyleBackColor = true;
            this.btnDeleteSituation.Click += new System.EventHandler(this.ButtonDeleteSituation_Click);
            // 
            // btnViewSituation
            // 
            this.btnViewSituation.Location = new System.Drawing.Point(650, 41);
            this.btnViewSituation.Name = "btnViewSituation";
            this.btnViewSituation.Size = new System.Drawing.Size(107, 23);
            this.btnViewSituation.TabIndex = 6;
            this.btnViewSituation.Text = "View Details";
            this.btnViewSituation.UseVisualStyleBackColor = true;
            this.btnViewSituation.Click += new System.EventHandler(this.ButtonViewSituation_Click);
            // 
            // btnModifyNotifications
            // 
            this.btnModifyNotifications.Location = new System.Drawing.Point(650, 70);
            this.btnModifyNotifications.Name = "btnModifyNotifications";
            this.btnModifyNotifications.Size = new System.Drawing.Size(107, 23);
            this.btnModifyNotifications.TabIndex = 7;
            this.btnModifyNotifications.Text = "Modify Notifications";
            this.btnModifyNotifications.UseVisualStyleBackColor = true;
            this.btnModifyNotifications.Click += new System.EventHandler(this.ButtonModifyNotifications_Click);
            // 
            // SituationManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(761, 343);
            this.Controls.Add(this.btnModifyNotifications);
            this.Controls.Add(this.btnViewSituation);
            this.Controls.Add(this.btnDeleteSituation);
            this.Controls.Add(this.btnNewSituation);
            this.Controls.Add(this.lvSituationManager);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SituationManagerForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Situation Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView lvSituationManager;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.Button btnNewSituation;
        private System.Windows.Forms.Button btnDeleteSituation;
        private System.Windows.Forms.Button btnViewSituation;
        private System.Windows.Forms.Button btnModifyNotifications;
    }
}