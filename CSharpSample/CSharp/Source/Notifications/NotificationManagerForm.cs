using System;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The NotificationManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// notifications from the VideoXpert system.</remarks>
    public partial class NotificationManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="NotificationManagerForm" /> class.
        /// </summary>
        public NotificationManagerForm()
        {
            InitializeComponent();

            PopulateNotifications();
        }

        /// <summary>
        /// The PopulateNotifications method.
        /// </summary>
        private void PopulateNotifications()
        {
            // Get the existing notifications from the VideoXpert system and add
            // them to the list view.
            var notifications = MainForm.CurrentSystem.GetNotifications();
            foreach (var notification in notifications)
            {
                var nameList = notification.Roles.Select(role => role.Name).ToList();
                var names = string.Join(", ", nameList);

                var lvItem = new ListViewItem(notification.Id);
                lvItem.SubItems.Add(names);
                lvItem.Tag = notification;
                lvNotificationManager.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            if (lvNotificationManager.SelectedItems.Count == 0)
                return;

            // Get the associated notification object from the selected item and delete
            // it from the VideoXpert system.
            var notification = (Notification)lvNotificationManager.SelectedItems[0].Tag;
            MainForm.CurrentSystem.DeleteNotification(notification);
            lvNotificationManager.SelectedItems[0].Remove();
        }

        /// <summary>
        /// The ButtonNewNotification_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonNewNotification_Click(object sender, EventArgs args)
        {
            // Show the AddNotificationForm dialog.
            DialogResult result;
            using (var addNotificationForm = new AddNotificationForm())
            {
                addNotificationForm.PopulateRoles();
                result = addNotificationForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added notification.
            lvNotificationManager.Items.Clear();
            PopulateNotifications();
            lvNotificationManager.Refresh();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            // Refresh the items in the list view to include the newly added notification.
            lvNotificationManager.Items.Clear();
            PopulateNotifications();
            lvNotificationManager.Refresh();
        }
    }
}
