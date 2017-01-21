using System;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddMonitorForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to select the settings
    /// that will be used to create a new monitor.</remarks> 
    public partial class AddMonitorForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddMonitorForm" /> class.
        /// </summary>
        public AddMonitorForm()
        {
            InitializeComponent();
            // Get the monitor devices from the VideoXpert system and add them to the combo box.
            foreach (var device in MainForm.CurrentDevices.Where(dev => dev.Type == Device.Types.Monitor))
            {
                var item = new ComboboxItem
                {
                    Text = device.Name,
                    Value = device.Id
                };
                cbxMonitorDevices.Items.Add(item);
            }
        }

        /// <summary>
        /// The ButtonAdd_Click method
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter</param>
        /// <param name="args">The <paramref name="args"/> parameter</param>
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            try
            {
                // Verify that an item is selected.
                if (cbxMonitorDevices.SelectedItem == null)
                {
                    MessageBox.Show(this, @"Host device is required.", @"Invalid Settings", MessageBoxButtons.OK,
                        MessageBoxIcon.Warning);
                    return;
                }

                // Create a new monitor object and add it to the VideoXpert system.
                var item = (ComboboxItem)cbxMonitorDevices.SelectedItem;
                var newMonitor = new NewMonitor
                {
                    HostDeviceId = item.Value.ToString(),
                    Name = tbxName.Text,
                    Number = (int) nudNumber.Value,
                    Layout = (Monitor.Layouts) cbxLayouts.SelectedIndex
                };
                MainForm.CurrentSystem.CreateMonitor(newMonitor);
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog(string.Format("Error creating Monitor: {0}", ex.Message));
                throw;
            }

            Close();
        }
    }
}
