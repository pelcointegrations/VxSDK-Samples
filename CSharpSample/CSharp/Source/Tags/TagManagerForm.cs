using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The TagManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// tags from the VideoXpert system.</remarks>
    public partial class TagManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="TagManagerForm" /> class.
        /// </summary>
        public TagManagerForm()
        {
            InitializeComponent();

            PopulateTags();
        }

        /// <summary>
        /// The PopulateTags method.
        /// </summary>
        private void PopulateTags()
        {
            lvTags.Items.Clear();
            lvDataSources.Items.Clear();
            lvDevices.Items.Clear();

            // Get the existing tags from the VideoXpert system and add
            // them to the list view.
            var tags = MainForm.CurrentSystem.GetTags();
            foreach (var tag in tags)
            {
                var lvItem = new ListViewItem(tag.Name);
                lvItem.SubItems.Add(tag.Id);
                lvItem.SubItems.Add(tag.Owner);
                lvItem.Tag = tag;
                lvTags.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonNewTag_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonNewTag_Click(object sender, EventArgs args)
        {
            // Show the AddTagForm dialog.
            DialogResult result;
            using (var tagForm = new AddTagForm())
            {
                result = tagForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added tag.
            PopulateTags();
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            if (lvTags.SelectedItems.Count == 0)
                return;

            // Get the associated tag object from the selected item and delete
            // it from the VideoXpert system.
            var tag = (Tag)lvTags.SelectedItems[0].Tag;
            MainForm.CurrentSystem.DeleteTag(tag);
            PopulateTags();
        }

        /// <summary>
        /// The ButtonModify_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonModify_Click(object sender, EventArgs args)
        {
            if (lvTags.SelectedItems.Count == 0)
                return;

            var tag = (Tag)lvTags.SelectedItems[0].Tag;

            // Show the ModifyTagForm dialog.
            DialogResult result;
            using (var modifyTagForm = new ModifyTagForm(tag))
            {
                result = modifyTagForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view.
            PopulateTags();
        }

        /// <summary>
        /// The ButtonMerge_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonMerge_Click(object sender, EventArgs args)
        {
            if (lvTags.SelectedItems.Count == 0)
                return;

            var tag = (Tag)lvTags.SelectedItems[0].Tag;

            // Show the MergeTagForm dialog.
            DialogResult result;
            using (var mergeTagForm = new MergeTagForm(tag))
            {
                result = mergeTagForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view.
            PopulateTags();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            PopulateTags();
        }

        /// <summary>
        /// The ListViewTags_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ListViewTags_SelectedIndexChanged(object sender, EventArgs args)
        {
            lvDataSources.Items.Clear();
            lvDevices.Items.Clear();

            if (lvTags.SelectedItems.Count == 0)
                return;

            // Get the selected tag.
            var tag = (Tag)lvTags.SelectedItems[0].Tag;

            foreach (var datasource in tag.LinkedDataSources)
            {
                var lvItem = new ListViewItem(datasource.Name);
                lvDataSources.Items.Add(lvItem);
            }

            foreach (var device in tag.LinkedDevices)
            {
                var lvItem = new ListViewItem(device.Name);
                lvDevices.Items.Add(lvItem);
            }
        }
    }
}
