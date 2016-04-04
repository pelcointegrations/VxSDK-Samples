using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ExportManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete export
    /// files from the VideoXpert system.</remarks>
    public partial class ExportManagerForm : Form
    {
        /// <summary>
        /// The _lastItemChecked field.
        /// </summary>  
        /// <remarks>Holds the last item checked in the ExportManager list view.</remarks>
        private ListViewItem _lastItemChecked;

        /// <summary>
        /// Initializes a new instance of the <see cref="ExportManagerForm" /> class.
        /// </summary>
        public ExportManagerForm()
        {
            InitializeComponent();

            PopulateExports();
        }

        /// <summary>
        /// The PopulateExports method.
        /// </summary>
        private void PopulateExports()
        {
            // Get the existing exports from the VideoXpert system and add
            // them to the list view.
            var exports = MainForm.CurrentSystem.GetExports();
            foreach (var export in exports)
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(export.Name);
                lvItem.SubItems.Add(export.Initiated.ToLocalTime().ToString("s"));
                lvItem.SubItems.Add(export.Owner);
                lvItem.SubItems.Add(export.FileSizeKb.ToString());
                lvItem.SubItems.Add(export.Status.ToString());
                lvItem.Tag = export;
                lvExportManager.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonDownload_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonDownload_Click(object sender, EventArgs args)
        {
            // Get the associated Export object from the selected item.
            var export = (Export)lvExportManager.CheckedItems[0].Tag;
            
            // Open a save file dialog for the user to select a filename for the
            // export download.
            saveFileDialog.ShowDialog();
            saveFileDialog.Dispose();

            using (var downloadForm = new DownloadProgressForm())
            {
                downloadForm.StartDownload(new Uri(export.DataUri), saveFileDialog.FileName, export.FileSizeKb);
                downloadForm.ShowDialog();
            }
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            // Get the associated Export object from the selected item and delete
            // it from the VideoXpert system.
            var export = (Export)lvExportManager.CheckedItems[0].Tag;
            MainForm.CurrentSystem.DeleteExport(export);
            lvExportManager.CheckedItems[0].Remove();
        }

        /// <summary>
        /// The ButtonNewExport_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonNewExport_Click(object sender, EventArgs args)
        {
            // Show the AddSituationForm dialog.
            DialogResult result;
            using (var exportForm = new NewExportForm())
            {
                result = exportForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added situation.
            lvExportManager.Items.Clear();
            PopulateExports();
            lvExportManager.Refresh();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            // Refresh the items in the list view.
            lvExportManager.Items.Clear();
            PopulateExports();
            lvExportManager.Refresh();
        }

        /// <summary>
        /// The ListViewExportManager_ItemCheck method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ListViewExportManager_ItemCheck(object sender, ItemCheckEventArgs args)
        {
            // If we have the lastItem set as checked, and it is different
            // item than the one that fired the event, uncheck it.
            if (_lastItemChecked != null && _lastItemChecked.Checked
                && _lastItemChecked != lvExportManager.Items[args.Index])
            {
                // Uncheck the last item and store the new one.
                _lastItemChecked.Checked = false;
            }

            // Store the current item.
            _lastItemChecked = lvExportManager.Items[args.Index];
        }
    }
}
