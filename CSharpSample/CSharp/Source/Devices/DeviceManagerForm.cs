using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The DeviceManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// devices from the VideoXpert system.</remarks>
    public partial class DeviceManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="DeviceManagerForm" /> class.
        /// </summary>
        public DeviceManagerForm()
        {
            InitializeComponent();

            PopulateDevices();
        }

        /// <summary>
        /// The PopulateDevices method.
        /// </summary>
        private void PopulateDevices()
        {
            lvDevices.Items.Clear();

            // Get the existing Devices from the VideoXpert system and add
            // them to the list view.
            var devices = MainForm.CurrentSystem.GetDevices();
            foreach (var device in devices)
            {
                var lvItem = new ListViewItem(device.Type.ToString());
                lvItem.SubItems.Add(device.Name);
                lvItem.SubItems.Add(device.Ip);
                lvItem.SubItems.Add(device.Id);
                lvItem.SubItems.Add(device.Model);
                lvItem.SubItems.Add(device.State.ToString());
                lvItem.SubItems.Add(device.Version);
                lvItem.SubItems.Add(device.IsCommissioned ? "Yes" : "No");
                lvItem.Tag = device;
                lvDevices.Items.Add(lvItem);
            }

            lblStatus.Text = MainForm.CurrentSystem.DeviceSearchStatus.ToString();
        }

        /// <summary>
        /// The ButtonAdd_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            // Show the AddDeviceForm dialog.
            DialogResult result;
            using (var addDeviceForm = new AddDeviceForm())
            {
                result = addDeviceForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added Device.
            PopulateDevices();
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            if (lvDevices.SelectedItems.Count == 0)
                return;

            // Get the associated Device object from the selected item and delete
            // it from the VideoXpert system.
            var device = (Device)lvDevices.SelectedItems[0].Tag;
            MainForm.CurrentSystem.DeleteDevice(device);
            PopulateDevices();
        }

        /// <summary>
        /// The ButtonModify_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonModify_Click(object sender, EventArgs args)
        {
            if (lvDevices.SelectedItems.Count == 0)
                return;

            var device = (Device)lvDevices.SelectedItems[0].Tag;

            // Show the ModifyDeviceForm dialog.
            DialogResult result;
            using (var modifyDeviceForm = new ModifyDeviceForm(device))
            {
                result = modifyDeviceForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view.
            PopulateDevices();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            PopulateDevices();
        }

        /// <summary>
        /// The ButtonAutoDiscover_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAutoDiscover_Click(object sender, EventArgs args)
        {
            MainForm.CurrentSystem.AutoAddDevices();
        }

        /// <summary>
        /// The ButtonCommission_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonCommission_Click(object sender, EventArgs args)
        {
            if (lvDevices.SelectedItems.Count == 0)
                return;

            var device = (Device)lvDevices.SelectedItems[0].Tag;
            MainForm.CurrentSystem.CommissionDevice(device);
            PopulateDevices();
        }

        /// <summary>
        /// The ButtonDecommission_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonDecommission_Click(object sender, EventArgs args)
        {
            if (lvDevices.SelectedItems.Count == 0)
                return;

            var device = (Device)lvDevices.SelectedItems[0].Tag;
            MainForm.CurrentSystem.DecommissionDevice(device);
            PopulateDevices();
        }
    }
}
