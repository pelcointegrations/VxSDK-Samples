namespace SDKSampleApp.Source
{
    partial class RelayOutputManagerForm
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
            this.lvRelayOutputManager = new System.Windows.Forms.ListView();
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chDescription = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chState = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnTrigger = new System.Windows.Forms.Button();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.btnModify = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lvRelayOutputManager
            // 
            this.lvRelayOutputManager.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chName,
            this.chDescription,
            this.chId,
            this.chState});
            this.lvRelayOutputManager.FullRowSelect = true;
            this.lvRelayOutputManager.GridLines = true;
            this.lvRelayOutputManager.HideSelection = false;
            this.lvRelayOutputManager.Location = new System.Drawing.Point(12, 12);
            this.lvRelayOutputManager.MultiSelect = false;
            this.lvRelayOutputManager.Name = "lvRelayOutputManager";
            this.lvRelayOutputManager.Size = new System.Drawing.Size(703, 320);
            this.lvRelayOutputManager.TabIndex = 0;
            this.lvRelayOutputManager.UseCompatibleStateImageBehavior = false;
            this.lvRelayOutputManager.View = System.Windows.Forms.View.Details;
            this.lvRelayOutputManager.SelectedIndexChanged += new System.EventHandler(this.ListViewRelayOutputManager_SelectedIndexChanged);
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 135;
            // 
            // chDescription
            // 
            this.chDescription.Text = "Description";
            this.chDescription.Width = 185;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 224;
            // 
            // chState
            // 
            this.chState.Text = "State";
            this.chState.Width = 150;
            // 
            // btnTrigger
            // 
            this.btnTrigger.Location = new System.Drawing.Point(721, 12);
            this.btnTrigger.Name = "btnTrigger";
            this.btnTrigger.Size = new System.Drawing.Size(89, 23);
            this.btnTrigger.TabIndex = 2;
            this.btnTrigger.Text = "Activate";
            this.btnTrigger.UseVisualStyleBackColor = true;
            this.btnTrigger.Click += new System.EventHandler(this.ButtonTrigger_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(721, 70);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(89, 23);
            this.btnRefresh.TabIndex = 4;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // btnModify
            // 
            this.btnModify.Location = new System.Drawing.Point(721, 41);
            this.btnModify.Name = "btnModify";
            this.btnModify.Size = new System.Drawing.Size(89, 23);
            this.btnModify.TabIndex = 12;
            this.btnModify.Text = "Modify";
            this.btnModify.UseVisualStyleBackColor = true;
            this.btnModify.Click += new System.EventHandler(this.ButtonModify_Click);
            // 
            // RelayOutputManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(819, 350);
            this.Controls.Add(this.btnModify);
            this.Controls.Add(this.btnRefresh);
            this.Controls.Add(this.btnTrigger);
            this.Controls.Add(this.lvRelayOutputManager);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "RelayOutputManagerForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "RelayOutput Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView lvRelayOutputManager;
        private System.Windows.Forms.ColumnHeader chDescription;
        private System.Windows.Forms.ColumnHeader chState;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.Button btnTrigger;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.Button btnModify;
    }
}