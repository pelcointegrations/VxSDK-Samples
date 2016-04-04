using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The RemoveDeviceAssignmentForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to unassign a device from
    /// a data storage.</remarks>
    public partial class RemoveDeviceAssignmentForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedDataStorage property.
        /// </summary>
        /// <value>The selected data storage.</value>
        public DataStorage SelectedDataStorage { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="RemoveDeviceAssignmentForm" /> class.
        /// </summary>
        /// <param name="dataStorage">The selected data storage.</param>
        public RemoveDeviceAssignmentForm(DataStorage dataStorage)
        {
            InitializeComponent();
            SelectedDataStorage = dataStorage;

            // Add each data source assigned to the data storage to lvDataSources.
            foreach (var dataSource in SelectedDataStorage.DataSources)
            {
                var lvItem = new ListViewItem(dataSource.Name);
                lvItem.SubItems.Add(dataSource.Ip);
                lvItem.Tag = dataSource;
                lvDataSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonRemove_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRemove_Click(object sender, EventArgs args)
        {
            // Return unless a data source has been selected.
            if (lvDataSources.SelectedItems.Count < 1) 
                return;

            // Get the selected data source.
            var dataSource = (DataSource)lvDataSources.SelectedItems[0].Tag;

            // Unssign the selected data sources host device.
            var result = SelectedDataStorage.UnassignDevice(dataSource.HostDevice);
            if (result != Results.Value.OK)
                MainForm.Instance.WriteToLog(string.Format("Warning: UnassignDevice returned {0}", result));
        }
    }
}
