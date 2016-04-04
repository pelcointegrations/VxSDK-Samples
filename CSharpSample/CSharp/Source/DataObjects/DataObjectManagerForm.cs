using System;
using System.Windows.Forms;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The TagManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// data objects from the VideoXpert system.</remarks>
    public partial class DataObjectManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="DataObjectManagerForm" /> class.
        /// </summary>
        public DataObjectManagerForm()
        {
            InitializeComponent();

            PopulateDataObjects();
        }

        /// <summary>
        /// The PopulateDataObjects method.
        /// </summary>
        private void PopulateDataObjects()
        {
            lvDataObjects.Items.Clear();
            tbxData.Clear();

            // Get the existing data objects from the VideoXpert system and add
            // them to the list view.
            var dataObjects = MainForm.CurrentSystem.GetDataObjects();
            foreach (var dataObject in dataObjects)
            {
                var lvItem = new ListViewItem(dataObject.ClientType);
                lvItem.SubItems.Add(dataObject.Id);
                lvItem.SubItems.Add(dataObject.Owner);
                lvItem.Tag = dataObject;
                lvDataObjects.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonNewDataObject_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonNewDataObject_Click(object sender, EventArgs args)
        {
            // Show the AddDataObjectForm dialog.
            DialogResult result;
            using (var dataObjectForm = new AddDataObjectForm())
            {
                result = dataObjectForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added data object.
            PopulateDataObjects();
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            if (lvDataObjects.SelectedItems.Count == 0)
                return;

            // Get the associated data object from the selected item and delete
            // it from the VideoXpert system.
            var dataObject = (CPPCli.DataObject)lvDataObjects.SelectedItems[0].Tag;
            MainForm.CurrentSystem.DeleteDataObject(dataObject);
            PopulateDataObjects();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            PopulateDataObjects();
        }

        /// <summary>
        /// The ListViewDataObjects_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ListViewDataObjects_SelectedIndexChanged(object sender, EventArgs args)
        {
            tbxData.Clear();
            if (lvDataObjects.SelectedItems.Count == 0)
                return;

            // Get the associated data object object from the selected item and display its data.
            var dataObject = (CPPCli.DataObject)lvDataObjects.SelectedItems[0].Tag;
            tbxData.Text = dataObject.Data;
        }
    }
}
