using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The RoleManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// roles from the VideoXpert system.</remarks>
    public partial class RoleManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="RoleManagerForm" /> class.
        /// </summary>
        public RoleManagerForm()
        {
            InitializeComponent();

            PopulateRoles();
        }

        /// <summary>
        /// The PopulateRoles method.
        /// </summary>
        private void PopulateRoles()
        {
            lvRoles.Items.Clear();

            // Get the existing roles from the VideoXpert system and add them to the list view.
            var roles = MainForm.CurrentSystem.GetRoles();
            foreach (var role in roles)
            {
                var lvItem = new ListViewItem(role.Name);
                lvItem.SubItems.Add(role.Id);
                lvItem.SubItems.Add(role.IsReadOnly.ToString());
                lvItem.Tag = role;
                lvRoles.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonNewRole_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonNewRole_Click(object sender, EventArgs args)
        {
            // Show the AddRoleForm dialog.
            DialogResult result;
            using (var addRoleForm = new AddRoleForm())
            {
                result = addRoleForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added role.
            PopulateRoles();
        }

        /// <summary>
        /// The ButtonManagePrivileges_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonManagePrivileges_Click(object sender, EventArgs args)
        {
            if (lvRoles.SelectedItems.Count != 1)
                return;

            var role = (Role)lvRoles.SelectedItems[0].Tag;

            // Show the ModifyRolePrivilegesForm dialog.
            DialogResult result;
            using (var modifyRolePrivilegesForm = new ModifyRolePrivilegesForm(role))
            {
                result = modifyRolePrivilegesForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            PopulateRoles();
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            if (lvRoles.SelectedItems.Count == 0)
                return;

            // Get the associated role from the selected item and delete
            // it from the VideoXpert system.
            var role = (Role)lvRoles.SelectedItems[0].Tag;
            MainForm.CurrentSystem.DeleteRole(role);
            PopulateRoles();
        }
    }
}
