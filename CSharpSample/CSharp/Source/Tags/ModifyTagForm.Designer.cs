namespace SDKSampleApp.Source
{
    partial class ModifyTagForm
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
            this.gbxLinkedDataSources = new System.Windows.Forms.GroupBox();
            this.lvTagSources = new System.Windows.Forms.ListView();
            this.chCheckBoxSources = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chDataSourceName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.gbxLinkedDevices = new System.Windows.Forms.GroupBox();
            this.lvTagDevices = new System.Windows.Forms.ListView();
            this.chCheckBox = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chDeviceName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.gbxLinkedDataSources.SuspendLayout();
            this.gbxLinkedDevices.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbxLinkedDataSources
            // 
            this.gbxLinkedDataSources.Controls.Add(this.lvTagSources);
            this.gbxLinkedDataSources.Location = new System.Drawing.Point(327, 12);
            this.gbxLinkedDataSources.Name = "gbxLinkedDataSources";
            this.gbxLinkedDataSources.Size = new System.Drawing.Size(309, 247);
            this.gbxLinkedDataSources.TabIndex = 3;
            this.gbxLinkedDataSources.TabStop = false;
            this.gbxLinkedDataSources.Text = "Linked Data Sources";
            // 
            // lvTagSources
            // 
            this.lvTagSources.CheckBoxes = true;
            this.lvTagSources.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chCheckBoxSources,
            this.chDataSourceName});
            this.lvTagSources.Location = new System.Drawing.Point(6, 19);
            this.lvTagSources.Name = "lvTagSources";
            this.lvTagSources.Size = new System.Drawing.Size(297, 222);
            this.lvTagSources.TabIndex = 2;
            this.lvTagSources.UseCompatibleStateImageBehavior = false;
            this.lvTagSources.View = System.Windows.Forms.View.Details;
            // 
            // chCheckBoxSources
            // 
            this.chCheckBoxSources.Text = "";
            this.chCheckBoxSources.Width = 25;
            // 
            // chDataSourceName
            // 
            this.chDataSourceName.Text = "Name";
            this.chDataSourceName.Width = 267;
            // 
            // gbxLinkedDevices
            // 
            this.gbxLinkedDevices.Controls.Add(this.lvTagDevices);
            this.gbxLinkedDevices.Location = new System.Drawing.Point(12, 12);
            this.gbxLinkedDevices.Name = "gbxLinkedDevices";
            this.gbxLinkedDevices.Size = new System.Drawing.Size(309, 247);
            this.gbxLinkedDevices.TabIndex = 2;
            this.gbxLinkedDevices.TabStop = false;
            this.gbxLinkedDevices.Text = "Linked Devices";
            // 
            // lvTagDevices
            // 
            this.lvTagDevices.CheckBoxes = true;
            this.lvTagDevices.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chCheckBox,
            this.chDeviceName});
            this.lvTagDevices.Location = new System.Drawing.Point(6, 19);
            this.lvTagDevices.Name = "lvTagDevices";
            this.lvTagDevices.Size = new System.Drawing.Size(297, 222);
            this.lvTagDevices.TabIndex = 3;
            this.lvTagDevices.UseCompatibleStateImageBehavior = false;
            this.lvTagDevices.View = System.Windows.Forms.View.Details;
            // 
            // chCheckBox
            // 
            this.chCheckBox.Text = "";
            this.chCheckBox.Width = 25;
            // 
            // chDeviceName
            // 
            this.chDeviceName.Text = "Name";
            this.chDeviceName.Width = 267;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(480, 265);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 30;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnSave
            // 
            this.btnSave.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnSave.Location = new System.Drawing.Point(561, 265);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(75, 23);
            this.btnSave.TabIndex = 29;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.ButtonSave_Click);
            // 
            // ModifyTagForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(647, 298);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.gbxLinkedDataSources);
            this.Controls.Add(this.gbxLinkedDevices);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ModifyTagForm";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Modify Tag";
            this.gbxLinkedDataSources.ResumeLayout(false);
            this.gbxLinkedDevices.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbxLinkedDataSources;
        private System.Windows.Forms.ListView lvTagSources;
        private System.Windows.Forms.ColumnHeader chDataSourceName;
        private System.Windows.Forms.GroupBox gbxLinkedDevices;
        private System.Windows.Forms.ListView lvTagDevices;
        private System.Windows.Forms.ColumnHeader chDeviceName;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.ColumnHeader chCheckBoxSources;
        private System.Windows.Forms.ColumnHeader chCheckBox;
    }
}