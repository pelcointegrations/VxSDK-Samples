using System.Drawing;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The DataStorageDetailsForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that contains the detailed info for the selected data storage.</remarks>
    public partial class DataStorageDetailsForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="DataStorageDetailsForm" /> class.
        /// </summary>
        public DataStorageDetailsForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The GetDataStorageInfo method.
        /// </summary>
        /// <param name="dataStorage">The <paramref name="dataStorage"/> to get information for.</param>
        public void GetDataStorageInfo(DataStorage dataStorage)
        {
            if (dataStorage == null)
                return;

            AddDataStorageInfo(dataStorage);

            if (dataStorage.DataSources.Count > 0)
                AddDataSourceInfo(dataStorage);

            if (dataStorage.Drivers.Count > 0)
                AddDriverInfo(dataStorage);
        }

        /// <summary>
        /// The AddDataStorageInfo method.
        /// </summary>
        /// <param name="dataStorage">The <paramref name="dataStorage"/> to add the info for.</param>
        private void AddDataStorageInfo(DataStorage dataStorage)
        {
            var lvMainItem = new ListViewItem(string.Empty) { BackColor = Color.LightGray };
            lvMainItem.SubItems.Add("Data Storage");
            lvDataStorageDetails.Items.Add(lvMainItem);

            // Use reflection to get each available property from the schedule.
            foreach (var prop in dataStorage.GetType().GetProperties())
            {
                // Get the value from the property.
                var val = prop.GetValue(dataStorage, null);

                // Get each item if the value is a List type and generate a string.
                if (val.GetType() != typeof(string))
                    continue;

                var valList = val.ToString();

                // Add the property name and value to the list view.
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(prop.Name);
                lvItem.SubItems.Add(valList);
                lvDataStorageDetails.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The AddDataSourceInfo method.
        /// </summary>
        /// <param name="dataStorage">The <paramref name="dataStorage"/> to add the info for.</param>
        private void AddDataSourceInfo(DataStorage dataStorage)
        {
            var lvItem = new ListViewItem(string.Empty) { BackColor = Color.LightGray };
            lvItem.SubItems.Add("Assignments");
            lvDataStorageDetails.Items.Add(lvItem);
            foreach (var dataSource in dataStorage.DataSources)
            {
                var lvSubItem = new ListViewItem(string.Empty);
                lvSubItem.SubItems.Add("Camera");
                lvSubItem.SubItems.Add(dataSource.Name);
                lvDataStorageDetails.Items.Add(lvSubItem);
            }
        }

        /// <summary>
        /// The AddDriverInfo method.
        /// </summary>
        /// <param name="dataStorage">The <paramref name="dataStorage"/> to add the info for.</param>
        private void AddDriverInfo(DataStorage dataStorage)
        {
            var lvItem = new ListViewItem(string.Empty) { BackColor = Color.LightGray };
            lvItem.SubItems.Add("Drivers");
            lvDataStorageDetails.Items.Add(lvItem);
            foreach (var driver in dataStorage.Drivers)
            {
                var lvSubItem = new ListViewItem(string.Empty);
                lvSubItem.SubItems.Add("Name");
                lvSubItem.SubItems.Add(driver.Name);
                lvDataStorageDetails.Items.Add(lvSubItem);
            }
        }
    }
}
