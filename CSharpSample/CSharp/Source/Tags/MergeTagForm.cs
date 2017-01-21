using System;
using System.Windows.Forms;

namespace SDKSampleApp.Source
{
    using CPPCli;

    /// <summary>
    /// The MergeTagForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to select a tag to merge with.</remarks>
    public partial class MergeTagForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedTag property.
        /// </summary>
        /// <value>The currently selected tag.</value>
        private Tag SelectedTag { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="MergeTagForm" /> class.
        /// </summary>
        /// <param name="selectedTag">The tag selected in the tag manager form.</param>
        public MergeTagForm(Tag selectedTag)
        {
            InitializeComponent();

            SelectedTag = selectedTag;
            PopulateTags();
        }

        /// <summary>
        /// The PopulateTags method.
        /// </summary>
        private void PopulateTags()
        {
            lvTags.Items.Clear();

            // Get the existing tags from the VideoXpert system and add
            // them to the list view.
            var tags = MainForm.CurrentSystem.GetTags();
            foreach (var tag in tags)
            {
                if (tag.Id == SelectedTag.Id)
                    continue;

                var lvItem = new ListViewItem(tag.Name);
                lvItem.SubItems.Add(tag.Id);
                lvItem.SubItems.Add(tag.OwnerName);
                lvItem.Tag = tag;
                lvTags.Items.Add(lvItem);
            }
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
            SelectedTag.Merge(tag);
        }
    }
}
