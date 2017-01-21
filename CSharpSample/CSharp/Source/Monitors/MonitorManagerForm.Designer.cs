namespace SDKSampleApp.Source
{
    partial class MonitorManagerForm
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
            this.lvMonitorManager = new System.Windows.Forms.ListView();
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chLayout = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnNewMonitor = new System.Windows.Forms.Button();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.btnView = new System.Windows.Forms.Button();
            this.chNumber = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // lvMonitorManager
            // 
            this.lvMonitorManager.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chNumber,
            this.chName,
            this.chLayout});
            this.lvMonitorManager.FullRowSelect = true;
            this.lvMonitorManager.GridLines = true;
            this.lvMonitorManager.Location = new System.Drawing.Point(12, 12);
            this.lvMonitorManager.MultiSelect = false;
            this.lvMonitorManager.Name = "lvMonitorManager";
            this.lvMonitorManager.Size = new System.Drawing.Size(474, 320);
            this.lvMonitorManager.TabIndex = 0;
            this.lvMonitorManager.UseCompatibleStateImageBehavior = false;
            this.lvMonitorManager.View = System.Windows.Forms.View.Details;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 302;
            // 
            // chLayout
            // 
            this.chLayout.Text = "Layout";
            this.chLayout.Width = 107;
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(493, 70);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(89, 23);
            this.btnDelete.TabIndex = 2;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.ButtonDelete_Click);
            // 
            // btnNewMonitor
            // 
            this.btnNewMonitor.Location = new System.Drawing.Point(492, 12);
            this.btnNewMonitor.Name = "btnNewMonitor";
            this.btnNewMonitor.Size = new System.Drawing.Size(90, 23);
            this.btnNewMonitor.TabIndex = 3;
            this.btnNewMonitor.Text = "New Monitor";
            this.btnNewMonitor.UseVisualStyleBackColor = true;
            this.btnNewMonitor.Click += new System.EventHandler(this.ButtonNewMonitor_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(493, 99);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(89, 23);
            this.btnRefresh.TabIndex = 4;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // btnView
            // 
            this.btnView.Location = new System.Drawing.Point(493, 41);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(89, 23);
            this.btnView.TabIndex = 6;
            this.btnView.Text = "View";
            this.btnView.UseVisualStyleBackColor = true;
            this.btnView.Click += new System.EventHandler(this.ButtonView_Click);
            // 
            // chNumber
            // 
            this.chNumber.Text = "Number";
            // 
            // MonitorManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(590, 350);
            this.Controls.Add(this.btnView);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnNewMonitor);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.lvMonitorManager);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MonitorManagerForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Monitor Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView lvMonitorManager;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chLayout;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnNewMonitor;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.Button btnView;
        private System.Windows.Forms.ColumnHeader chNumber;
    }
}