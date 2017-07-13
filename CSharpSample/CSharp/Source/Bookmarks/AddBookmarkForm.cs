using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddBookmarkForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to select the settings
    /// that will be used to create a new bookmark.</remarks> 
    public partial class AddBookmarkForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddBookmarkForm" /> class.
        /// </summary>
        public AddBookmarkForm()
        {
            InitializeComponent();

            foreach (DataGridViewRow row in MainForm.Instance.dgvDataSources.Rows)
            {
                var ds = (DataSource)row.Tag;
                var lvItem = new ListViewItem(ds.Name);
                lvItem.SubItems.Add(ds.Number.ToString());
                lvItem.Tag = ds;
                lvDataSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonAdd_Click method
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter</param>
        /// <param name="args">The <paramref name="args"/> parameter</param>
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            if (lvDataSources.SelectedItems.Count == 0)
                return;

            var dataSource = (DataSource)lvDataSources.SelectedItems[0].Tag;
            var newBookmark = new NewBookmark
            {
                Description = tbxDescription.Text,
                Name = tbxName.Text,
                Time = dtpTime.Value.ToUniversalTime(),
                DataSourceId = dataSource.Id
            };

            try
            {
                MainForm.CurrentSystem.CreateBookmark(newBookmark);
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog(string.Format("Error creating bookmark: {0}", ex.Message));
                throw;
            }
        }
    }
}
