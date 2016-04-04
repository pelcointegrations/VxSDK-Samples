using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddDeviceAssignmentForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to add a new device assignment to
    /// a data storage.</remarks>
    public partial class AddDeviceAssignmentForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddDeviceAssignmentForm" /> class.
        /// </summary>
        /// <param name="dataStorage">The selected data storage.</param>
        public AddDeviceAssignmentForm(DataStorage dataStorage)
        {
            InitializeComponent();
            SelectedDataStorage = dataStorage;

            PopulateStorageInfo();
        }

        /// <summary>
        /// Gets or sets the SelectedDataStorage property.
        /// </summary>
        /// <value>The selected data storage.</value>
        public DataStorage SelectedDataStorage { get; set; }

        /// <summary>
        /// The ButtonAdd_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAdd_Click(object sender, System.EventArgs args)
        {
            // Create a new device assignment.
            var newDeviceAssignment = new NewDeviceAssignment();
            var device = ((ComboboxItem)cbxDevices.SelectedItem).Value as Device;
            if (device != null)
                newDeviceAssignment.DeviceId = device.Id;

            // If drivers are present, add the selected one to the new assignment.
            if (cbxDriverTypes.Items.Count > 0)
            {
                var driver = ((ComboboxItem)cbxDriverTypes.SelectedItem).Value as Driver;
                if (driver != null)
                    newDeviceAssignment.DriverType = driver.Type;
            }

            // Add any selected data sources to the new assignment.
            foreach (var dataSource in from ListViewItem item in lvDataSources.CheckedItems select (DataSource)item.Tag)
                newDeviceAssignment.DataSourceIds.Add(dataSource.Id);

            // Assign the device.
            var result = SelectedDataStorage.AssignDevice(newDeviceAssignment);
            if (result != Results.Value.OK)
                MainForm.Instance.WriteToLog(string.Format("Warning: UnassignDevice returned {0}", result));
        }

        /// <summary>
        /// The ComboBoxDevices_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ComboBoxDevices_SelectedIndexChanged(object sender, System.EventArgs args)
        {
            lvDataSources.Items.Clear();
            var device = ((ComboboxItem)cbxDevices.SelectedItem).Value as Device;

            if (device == null)
                return;

            // Add each data source to lvDataSources.
            foreach (var dataSource in device.DataSources)
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(dataSource.Name);
                lvItem.Tag = dataSource;
                lvDataSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The PopulateStorageInfo method.
        /// </summary>
        private void PopulateStorageInfo()
        {
            var hostIds = SelectedDataStorage.DataSources.Select(dataSource => dataSource.HostDevice.Id).ToList();

            // Iterate through each device on the VxSystem.  This will allow us to filter for assigned data sources.
            foreach (var device in MainForm.CurrentDevices)
            {
                // Check if the device has its data source assigned and that it is a camera.
                if (hostIds.Any(hostId => hostId == device.Id) || device.Type != Device.Types.Camera)
                    continue;

                cbxDevices.Items.Add(new ComboboxItem { Text = device.Name, Value = device });
            }

            // Add any drivers found on the data storage.
            foreach (var driver in SelectedDataStorage.Drivers)
                cbxDriverTypes.Items.Add(new ComboboxItem { Text = driver.Name, Value = driver });

            UpdateControls();
        }

        /// <summary>
        /// The UpdateControls method.
        /// </summary>
        private void UpdateControls()
        {
            // Disable the driver drop down if no drivers are found.
            if (cbxDriverTypes.Items.Count < 1)
            {
                cbxDriverTypes.Enabled = false;
                lblNoDriversFound.Visible = true;
            }
            else
                cbxDriverTypes.SelectedIndex = 0;

            // Disable the device drop down and add button if no devices are found.
            if (cbxDevices.Items.Count < 1)
            {
                cbxDevices.Enabled = false;
                btnAdd.Enabled = false;
                lblNoUnassignedDevices.Visible = true;
            }
            else
                cbxDevices.SelectedIndex = 0;
        }
    }
}
