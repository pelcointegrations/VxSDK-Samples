using System;
using System.Collections.Generic;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The UserManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// users from the VideoXpert system.</remarks>
    public partial class UserManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="UserManagerForm" /> class.
        /// </summary>
        public UserManagerForm()
        {
            InitializeComponent();

            PopulateUsers();
        }

        /// <summary>
        /// The PopulateUsers method.
        /// </summary>
        private void PopulateUsers()
        {
            lvUsers.Items.Clear();

            // Get the existing users from the VideoXpert system and add
            // them to the list view.
            var users = MainForm.CurrentSystem.GetUsers();
            foreach (var user in users)
            {
                var passwordExpireDate = user.PasswordExpiration == default(DateTime) ?
                    "Never" : user.PasswordExpiration.ToString("d");

                var lvItem = new ListViewItem(user.Name);
                lvItem.SubItems.Add(user.Id);
                lvItem.SubItems.Add(user.Domain);
                lvItem.SubItems.Add(user.AccountState ? "Enabled" : "Disabled");
                lvItem.SubItems.Add(passwordExpireDate);
                lvItem.Tag = user;
                lvUsers.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonNewUser_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonNewUser_Click(object sender, EventArgs args)
        {
            // Show the AddUserForm dialog.
            DialogResult result;
            using (var userForm = new AddUserForm())
            {
                result = userForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added user.
            PopulateUsers();
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            if (lvUsers.SelectedItems.Count == 0)
                return;

            // Get the associated user object from the selected item and delete
            // it from the VideoXpert system.
            var user = (User)lvUsers.SelectedItems[0].Tag;
            MainForm.CurrentSystem.DeleteUser(user);
            PopulateUsers();
        }

        /// <summary>
        /// The ButtonModify_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonModify_Click(object sender, EventArgs args)
        {
            if (lvUsers.SelectedItems.Count == 0)
                return;

            var user = (User)lvUsers.SelectedItems[0].Tag;

            // Show the modifyUserForm dialog.
            DialogResult result;
            using (var modifyUserForm = new ModifyUserForm(user))
            {
                result = modifyUserForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view.
            PopulateUsers();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            PopulateUsers();
        }
    }
}
