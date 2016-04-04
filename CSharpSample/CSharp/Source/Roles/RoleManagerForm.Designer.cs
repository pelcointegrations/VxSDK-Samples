namespace SDKSampleApp.Source
{
    partial class RoleManagerForm
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
            this.btnManagePrivileges = new System.Windows.Forms.Button();
            this.btnNewRole = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.lvRoles = new System.Windows.Forms.ListView();
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chReadOnly = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // btnManagePrivileges
            // 
            this.btnManagePrivileges.Location = new System.Drawing.Point(526, 41);
            this.btnManagePrivileges.Name = "btnManagePrivileges";
            this.btnManagePrivileges.Size = new System.Drawing.Size(103, 23);
            this.btnManagePrivileges.TabIndex = 14;
            this.btnManagePrivileges.Text = "Manage Privileges";
            this.btnManagePrivileges.UseVisualStyleBackColor = true;
            this.btnManagePrivileges.Click += new System.EventHandler(this.ButtonManagePrivileges_Click);
            // 
            // btnNewRole
            // 
            this.btnNewRole.Location = new System.Drawing.Point(526, 12);
            this.btnNewRole.Name = "btnNewRole";
            this.btnNewRole.Size = new System.Drawing.Size(103, 23);
            this.btnNewRole.TabIndex = 12;
            this.btnNewRole.Text = "New Role";
            this.btnNewRole.UseVisualStyleBackColor = true;
            this.btnNewRole.Click += new System.EventHandler(this.ButtonNewRole_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(527, 70);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(102, 23);
            this.btnDelete.TabIndex = 11;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.ButtonDelete_Click);
            // 
            // lvRoles
            // 
            this.lvRoles.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chName,
            this.chId,
            this.chReadOnly});
            this.lvRoles.FullRowSelect = true;
            this.lvRoles.GridLines = true;
            this.lvRoles.Location = new System.Drawing.Point(12, 12);
            this.lvRoles.MultiSelect = false;
            this.lvRoles.Name = "lvRoles";
            this.lvRoles.Size = new System.Drawing.Size(508, 234);
            this.lvRoles.TabIndex = 10;
            this.lvRoles.UseCompatibleStateImageBehavior = false;
            this.lvRoles.View = System.Windows.Forms.View.Details;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 183;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 248;
            // 
            // chReadOnly
            // 
            this.chReadOnly.Text = "Read Only";
            this.chReadOnly.Width = 72;
            // 
            // RoleManagerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(635, 253);
            this.Controls.Add(this.btnManagePrivileges);
            this.Controls.Add(this.btnNewRole);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.lvRoles);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "RoleManagerForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Role Manager";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnManagePrivileges;
        private System.Windows.Forms.Button btnNewRole;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.ListView lvRoles;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chReadOnly;
    }
}