namespace SDKSampleApp.Source
{
    partial class NotificationManagerForm
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
            this.lvNotificationManager = new System.Windows.Forms.ListView();
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chRoleNames = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnNewNotification = new System.Windows.Forms.Button();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lvNotificationManager
            // 
            this.lvNotificationManager.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chId,
            this.chRoleNames});
            this.lvNotificationManager.FullRowSelect = true;
            this.lvNotificationManager.GridLines = true;
            this.lvNotificationManager.Location = new System.Drawing.Point(12, 12);
            this.lvNotificationManager.MultiSelect = false;
            this.lvNotificationManager.Name = "lvNotificationManager";
            this.lvNotificationManager.Size = new System.Drawing.Size(754, 320);
            this.lvNotificationManager.TabIndex = 0;
            this.lvNotificationManager.UseCompatibleStateImageBehavior = false;
            this.lvNotificationManager.View = System.Windows.Forms.View.Details;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 224;
            // 
            // chRoleNames
            // 
            this.chRoleNames.Text = "Roles To Notify";
            this.chRoleNames.Width = 526;
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(772, 41);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(89, 23);
            this.btnDelete.TabIndex = 2;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.ButtonDelete_Click);
            // 
            // btnNewNotification
            // 
            this.btnNewNotification.Location = new System.Drawing.Point(771, 12);
            this.btnNewNotification.Name = "btnNewNotification";
            this.btnNewNotification.Size = new System.Drawing.Size(90, 23);
            this.btnNewNotification.TabIndex = 3;
            this.btnNewNotification.Text = "New Notification";
            this.btnNewNotification.UseVisualStyleBackColor = true;
            this.btnNewNotification.Click += new System.EventHandler(this.ButtonNewNotification_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(772, 70);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(89, 23);
            this.btnRefresh.TabIndex = 4;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // NotificationManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(866, 350);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnNewNotification);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.lvNotificationManager);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "NotificationManagerForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Notification Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView lvNotificationManager;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chRoleNames;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnNewNotification;
        private System.Windows.Forms.Button btnRefresh;
    }
}