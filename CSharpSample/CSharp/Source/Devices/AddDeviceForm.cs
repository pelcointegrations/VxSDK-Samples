using System;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddDeviceForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create a new device.</remarks>
    public partial class AddDeviceForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddDeviceForm" /> class.
        /// </summary>
        public AddDeviceForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The PopulateComboBoxes method.
        /// </summary>
        private void PopulateDataStorages()
        {
            cbxRecorder.Items.Clear();

            // Get the data storages from the VideoXpert system and add
            // them to the combo box.
            var storages = MainForm.CurrentSystem.GetDataStorages();
            foreach (var storage in storages.Where(item => item.Type == DataStorage.DataStorageTypes.VideoXpertStorage))
            {
                var item = new ComboboxItem
                {
                    Text = storage.Name,
                    Value = storage
                };

                cbxRecorder.Items.Add(item);
            }

            if (cbxRecorder.Items.Count > 0)
                cbxRecorder.SelectedIndex = 0;
        }

        /// <summary>
        /// The PopulateDrivers method.
        /// </summary>
        /// <param name="dataStorage">The data storage used to get the drivers.</param>
        private void PopulateDrivers(DataStorage dataStorage)
        {
            cbxDriverType.Items.Clear();

            // Get the drivers from the data storage and add them to the combo box.
            var drivers = dataStorage.Drivers;
            foreach (var driver in drivers)
            {
                var item = new ComboboxItem
                {
                    Text = driver.Name,
                    Value = driver.Type
                };

                cbxDriverType.Items.Add(item);
            }

            if (cbxDriverType.Items.Count > 0)
                cbxDriverType.SelectedIndex = 0;
        }

        /// <summary>
        /// The ButtonOk_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonOk_Click(object sender, EventArgs args)
        {
            if (string.IsNullOrEmpty(cbxDeviceType.Text))
                return;

            try
            {
                var newDevice = new NewDevice
                {
                    Ip = tbxIp.Text,
                    Name = tbxName.Text,
                    Username = tbxUsername.Text,
                    Password = tbxPassword.Text,
                    ShouldAutoCommission = ckbxAutoCommission.Checked,
                    Type = (Device.Types)cbxDeviceType.SelectedIndex
                };

                if (cbxRecorder.Enabled)
                {
                    var dataStorageItem = cbxRecorder.SelectedItem as ComboboxItem;
                    if (dataStorageItem != null)
                    {
                        var dataStorage = dataStorageItem.Value as DataStorage;
                        if (dataStorage != null)
                            newDevice.DataStorageId = dataStorage.Id;
                    }

                    var driverTypeItem = cbxDriverType.SelectedItem as ComboboxItem;
                    if (driverTypeItem != null)
                    {
                        var driverType = driverTypeItem.Value.ToString();
                        if (!string.IsNullOrEmpty(driverType))
                            newDevice.DriverType = driverType;
                    }
                }

                MainForm.CurrentSystem.AddDevice(newDevice);
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog(string.Format("Error adding device: {0}", ex.Message));
                throw;
            }
        }

        /// <summary>
        /// The ComboBoxDeviceType_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ComboBoxDeviceType_SelectedIndexChanged(object sender, EventArgs args)
        {
            if (cbxDeviceType.Text == @"Camera" || cbxDeviceType.Text == @"Encoder")
            {
                cbxRecorder.Enabled = true;
                cbxDriverType.Enabled = true;
                PopulateDataStorages();
            }
            else
            {
                cbxRecorder.Enabled = false;
                cbxDriverType.Enabled = false;
                cbxRecorder.Items.Clear();
                cbxRecorder.Text = string.Empty;
                cbxDriverType.Items.Clear();
                cbxDriverType.Text = string.Empty;
            }
        }

        /// <summary>
        /// The ComboBoxRecorder_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ComboBoxRecorder_SelectedIndexChanged(object sender, EventArgs args)
        {
            var dataStorageItem = cbxRecorder.SelectedItem as ComboboxItem;
            if (dataStorageItem == null)
                return;

            var dataStorage = dataStorageItem.Value as DataStorage;
            if (dataStorage != null)
                PopulateDrivers(dataStorage);
        }
    }
}
