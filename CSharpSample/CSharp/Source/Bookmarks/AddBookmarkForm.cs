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

            // Clone each item in the MainForm ListView and add it to lvDataSources.
            foreach (ListViewItem item in MainForm.Instance.lvDataSources.Items)
            {
                var lvItem = (ListViewItem)item.Clone();
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
            if (lvDataSources.SelectedItems[0] == null)
                return;

            var dataSource = (DataSource)lvDataSources.SelectedItems[0].Tag;
            var newBookmark = new NewBookmark
            {
                Description = this.tbxDescription.Text,
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
