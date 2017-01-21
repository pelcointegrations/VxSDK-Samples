using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ModifyDeviceForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to modify a device.</remarks>
    public partial class ModifyDeviceForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedDevice property.
        /// </summary>
        /// <value>The currently selected device.</value>
        private Device SelectedDevice { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyDeviceForm" /> class.
        /// </summary>
        /// <param name="device">The <paramref name="device"/> parameter.</param>
        public ModifyDeviceForm(Device device)
        {
            InitializeComponent();
            SelectedDevice = device;
            tbxName.Text = device.Name;
            tbxUsername.Text = device.Username;
        }

        /// <summary>
        /// The ButtonSave_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSave_Click(object sender, EventArgs args)
        {
            if (!string.IsNullOrEmpty(tbxName.Text))
                SelectedDevice.Name = tbxName.Text;

            if (!string.IsNullOrEmpty(tbxUsername.Text))
                SelectedDevice.Username = tbxUsername.Text;

            if (!string.IsNullOrEmpty(tbxPassword.Text))
                SelectedDevice.Password = tbxPassword.Text;
        }
    }
}
