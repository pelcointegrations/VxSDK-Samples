using System;
using System.Collections.Generic;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    using System.Linq;

    /// <summary>
    /// The AddUserForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to modify a user.</remarks>
    public partial class ModifyUserForm : Form
    {
        /// <summary>
        /// Gets or sets the CurrentRoleList property.
        /// </summary>
        /// <value>The list of roles for the currently selected user.</value>
        private List<string> CurrentRoleList { get; set; }

        /// <summary>
        /// Gets or sets the SelectedUser property.
        /// </summary>
        /// <value>The currently selected user.</value>
        private User SelectedUser { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyUserForm" /> class.
        /// </summary>
        /// <param name="user">The <paramref name="user"/> parameter.</param>
        public ModifyUserForm(User user)
        {
            InitializeComponent();
            SelectedUser = user;
            ckbxAccountEnabled.Checked = SelectedUser.AccountState;
            PopulateRoles();
        }

        /// <summary>
        /// The CheckBoxAccountEnabled_CheckedChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void CheckBoxAccountEnabled_CheckedChanged(object sender, EventArgs args)
        {
            if (ckbxAccountEnabled.Checked)
            {
                gbxRoleAssociations.Enabled = true;
                ckbxChangePassword.Enabled = true;
                if (ckbxChangePassword.Checked)
                    tbxNewPassword.Enabled = true;
            }
            else
            {
                gbxRoleAssociations.Enabled = false;
                ckbxChangePassword.Enabled = false;
                tbxNewPassword.Enabled = false;
            }
        }

        /// <summary>
        /// The CheckBoxChangePassword_CheckedChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void CheckBoxChangePassword_CheckedChanged(object sender, EventArgs args)
        {
            tbxNewPassword.Enabled = ckbxChangePassword.Checked;
        }

        /// <summary>
        /// The ButtonSave_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSave_Click(object sender, EventArgs args)
        {
            if (ckbxAccountEnabled.Checked != SelectedUser.AccountState)
                SelectedUser.AccountState = ckbxAccountEnabled.Checked;

            if (ckbxChangePassword.Checked && tbxNewPassword.Text.Length > 0)
                SelectedUser.SetPassword(tbxNewPassword.Text);

            LinkRoles();
        }

        /// <summary>
        /// The PopulateRoles method.
        /// </summary>
        private void PopulateRoles()
        {
            CurrentRoleList = new List<string>();
            foreach (var role in SelectedUser.Roles)
                CurrentRoleList.Add(role.Id);

            // Get all roles and add them to lvUserRoles, checking them if they are
            // assigned to this user.
            foreach (var role in MainForm.CurrentSystem.GetRoles())
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(role.Name);
                lvItem.Tag = role;
                if (CurrentRoleList.Any(s => role.Id.Contains(s)))
                    lvItem.Checked = true;

                lvUserRoles.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The LinkRoles method.
        /// </summary>
        private void LinkRoles()
        {
            foreach (ListViewItem item in lvUserRoles.Items)
            {
                var role = (Role)item.Tag;

                if (item.Checked)
                {
                    if (!CurrentRoleList.Any(s => role.Id.Contains(s)))
                        SelectedUser.AddToRole(role);
                }
                else
                {
                    if (CurrentRoleList.Any(s => role.Id.Contains(s)))
                        SelectedUser.RemoveFromRole(role);
                }
            }
        }
    }
}
