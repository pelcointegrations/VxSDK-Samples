using System;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The DataSourceManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// devices from the VideoXpert system.</remarks>
    public partial class DataSourceManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="DataSourceManagerForm" /> class.
        /// </summary>
        public DataSourceManagerForm()
        {
            InitializeComponent();

            PopulateDataSources();
        }

        /// <summary>
        /// The PopulateDataSources method.
        /// </summary>
        private void PopulateDataSources()
        {
            lvDataSources.Items.Clear();

            // Get the existing data sources from the VideoXpert system and add them
            // to the list view.
            var dataSources = MainForm.CurrentSystem.GetDataSources().OrderByDescending(x => x.Type);
            foreach (var dataSource in dataSources)
            {
                var lvItem = new ListViewItem(dataSource.Number.ToString());
                lvItem.SubItems.Add(dataSource.Type.ToString());
                lvItem.SubItems.Add(dataSource.Name);
                lvItem.SubItems.Add(dataSource.Ip);
                lvItem.SubItems.Add(dataSource.Id);
                lvItem.SubItems.Add(dataSource.State.ToString());
                lvItem.Tag = dataSource;
                lvDataSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonAutoNumber_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAutoNumber_Click(object sender, EventArgs args)
        {
            decimal value = 1;
            if (InputBox.Show("Auto-Number", "Automatically number all data sources that do not have a number already set.\n\nStarting Number:", ref value, 1, 999999) != DialogResult.OK)
                return;

            var currentNum = (int)value;
            var dataSources = MainForm.CurrentSystem.GetDataSources().OrderBy(x => x.Type);
            foreach (var dataSource in dataSources.Where(x => x.Number == 0))
            {
                while (dataSources.Any(x => x.Number == currentNum))
                {
                    currentNum++;
                }
                dataSource.Number = currentNum;
                currentNum++;
            }

            // Refresh the items in the list view.
            PopulateDataSources();
        }

        /// <summary>
        /// The ButtonManageLinks_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonManageLinks_Click(object sender, EventArgs args)
        {
            if (lvDataSources.SelectedItems.Count == 0)
                return;

            var dataSource = (DataSource)lvDataSources.SelectedItems[0].Tag;

            // Show the ManageDataSourceLinksForm dialog.
            using (var manageDataSourceLinksForm = new ManageDataSourceLinksForm(dataSource))
            {
                 manageDataSourceLinksForm.ShowDialog();
            }
        }

        /// <summary>
        /// The ButtonModify_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonModify_Click(object sender, EventArgs args)
        {
            if (lvDataSources.SelectedItems.Count == 0)
                return;

            var dataSource = (DataSource)lvDataSources.SelectedItems[0].Tag;

            // Show the ModifyDataSourceForm dialog.
            DialogResult result;
            using (var modifyDataSourceForm = new ModifyDataSourceForm(dataSource))
            {
                result = modifyDataSourceForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view.
            PopulateDataSources();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            PopulateDataSources();
        }

        /// <summary>
        /// The ButtonViewerInfo_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonViewerInfo_Click(object sender, EventArgs args)
        {
            if (lvDataSources.SelectedItems.Count == 0)
                return;

            var dataSource = (DataSource)lvDataSources.SelectedItems[0].Tag;

            // Show the MultiviewDetailsForm dialog.
            using (var multiviewDetailsForm = new MultiviewDetailsForm(dataSource))
            {
                multiviewDetailsForm.ShowDialog();
            }
        }
    }
}
