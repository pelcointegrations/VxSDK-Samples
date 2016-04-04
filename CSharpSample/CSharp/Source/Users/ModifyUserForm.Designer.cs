namespace SDKSampleApp.Source
{
    partial class ModifyUserForm
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
            this.ckbxAccountEnabled = new System.Windows.Forms.CheckBox();
            this.gbxRoleAssociations = new System.Windows.Forms.GroupBox();
            this.lvUserRoles = new System.Windows.Forms.ListView();
            this.chCheckBox = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chDeviceName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.ckbxChangePassword = new System.Windows.Forms.CheckBox();
            this.lblNewPassword = new System.Windows.Forms.Label();
            this.tbxNewPassword = new System.Windows.Forms.TextBox();
            this.gbxAccountSettings = new System.Windows.Forms.GroupBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.gbxRoleAssociations.SuspendLayout();
            this.gbxAccountSettings.SuspendLayout();
            this.SuspendLayout();
            // 
            // ckbxAccountEnabled
            // 
            this.ckbxAccountEnabled.AutoSize = true;
            this.ckbxAccountEnabled.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.ckbxAccountEnabled.Location = new System.Drawing.Point(9, 28);
            this.ckbxAccountEnabled.Name = "ckbxAccountEnabled";
            this.ckbxAccountEnabled.Size = new System.Drawing.Size(114, 17);
            this.ckbxAccountEnabled.TabIndex = 0;
            this.ckbxAccountEnabled.Text = "Account Enabled: ";
            this.ckbxAccountEnabled.UseVisualStyleBackColor = true;
            this.ckbxAccountEnabled.CheckedChanged += new System.EventHandler(this.CheckBoxAccountEnabled_CheckedChanged);
            // 
            // gbxRoleAssociations
            // 
            this.gbxRoleAssociations.Controls.Add(this.lvUserRoles);
            this.gbxRoleAssociations.Location = new System.Drawing.Point(12, 132);
            this.gbxRoleAssociations.Name = "gbxRoleAssociations";
            this.gbxRoleAssociations.Size = new System.Drawing.Size(308, 247);
            this.gbxRoleAssociations.TabIndex = 3;
            this.gbxRoleAssociations.TabStop = false;
            this.gbxRoleAssociations.Text = "Role Associations";
            // 
            // lvUserRoles
            // 
            this.lvUserRoles.CheckBoxes = true;
            this.lvUserRoles.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chCheckBox,
            this.chDeviceName});
            this.lvUserRoles.Location = new System.Drawing.Point(6, 19);
            this.lvUserRoles.Name = "lvUserRoles";
            this.lvUserRoles.Size = new System.Drawing.Size(296, 222);
            this.lvUserRoles.TabIndex = 3;
            this.lvUserRoles.UseCompatibleStateImageBehavior = false;
            this.lvUserRoles.View = System.Windows.Forms.View.Details;
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
            // ckbxChangePassword
            // 
            this.ckbxChangePassword.AutoSize = true;
            this.ckbxChangePassword.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.ckbxChangePassword.Location = new System.Drawing.Point(6, 58);
            this.ckbxChangePassword.Name = "ckbxChangePassword";
            this.ckbxChangePassword.Size = new System.Drawing.Size(118, 17);
            this.ckbxChangePassword.TabIndex = 4;
            this.ckbxChangePassword.Text = "Change Password: ";
            this.ckbxChangePassword.UseVisualStyleBackColor = true;
            this.ckbxChangePassword.CheckedChanged += new System.EventHandler(this.CheckBoxChangePassword_CheckedChanged);
            // 
            // lblNewPassword
            // 
            this.lblNewPassword.AutoSize = true;
            this.lblNewPassword.Location = new System.Drawing.Point(23, 88);
            this.lblNewPassword.Name = "lblNewPassword";
            this.lblNewPassword.Size = new System.Drawing.Size(84, 13);
            this.lblNewPassword.TabIndex = 5;
            this.lblNewPassword.Text = "New Password: ";
            // 
            // tbxNewPassword
            // 
            this.tbxNewPassword.Enabled = false;
            this.tbxNewPassword.Location = new System.Drawing.Point(110, 85);
            this.tbxNewPassword.Name = "tbxNewPassword";
            this.tbxNewPassword.Size = new System.Drawing.Size(175, 20);
            this.tbxNewPassword.TabIndex = 6;
            // 
            // gbxAccountSettings
            // 
            this.gbxAccountSettings.Controls.Add(this.ckbxAccountEnabled);
            this.gbxAccountSettings.Controls.Add(this.tbxNewPassword);
            this.gbxAccountSettings.Controls.Add(this.lblNewPassword);
            this.gbxAccountSettings.Controls.Add(this.ckbxChangePassword);
            this.gbxAccountSettings.Location = new System.Drawing.Point(12, 12);
            this.gbxAccountSettings.Name = "gbxAccountSettings";
            this.gbxAccountSettings.Size = new System.Drawing.Size(308, 114);
            this.gbxAccountSettings.TabIndex = 7;
            this.gbxAccountSettings.TabStop = false;
            this.gbxAccountSettings.Text = "Account Settings";
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(164, 385);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 32;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnSave
            // 
            this.btnSave.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnSave.Location = new System.Drawing.Point(245, 385);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(75, 23);
            this.btnSave.TabIndex = 31;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.ButtonSave_Click);
            // 
            // ModifyUserForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(331, 417);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.gbxAccountSettings);
            this.Controls.Add(this.gbxRoleAssociations);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ModifyUserForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Modify User";
            this.gbxRoleAssociations.ResumeLayout(false);
            this.gbxAccountSettings.ResumeLayout(false);
            this.gbxAccountSettings.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.CheckBox ckbxAccountEnabled;
        private System.Windows.Forms.GroupBox gbxRoleAssociations;
        private System.Windows.Forms.ListView lvUserRoles;
        private System.Windows.Forms.ColumnHeader chCheckBox;
        private System.Windows.Forms.ColumnHeader chDeviceName;
        private System.Windows.Forms.CheckBox ckbxChangePassword;
        private System.Windows.Forms.Label lblNewPassword;
        private System.Windows.Forms.TextBox tbxNewPassword;
        private System.Windows.Forms.GroupBox gbxAccountSettings;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnSave;
    }
}