using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The BookmarkManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// bookmarks from the VideoXpert system.</remarks>
    public partial class BookmarkManagerForm : Form
    {
        /// <summary>
        /// The _lastItemChecked field.
        /// </summary>  
        /// <remarks>Holds the last item checked in the BookmarkManager list view.</remarks>
        private ListViewItem _lastItemChecked;

        /// <summary>
        /// Initializes a new instance of the <see cref="BookmarkManagerForm" /> class.
        /// </summary>
        public BookmarkManagerForm()
        {
            InitializeComponent();

            PopulateBookmarks();
        }

        /// <summary>
        /// The PopulateBookmarks method.
        /// </summary>
        private void PopulateBookmarks()
        {
            // Get the existing bookmarks from the VideoXpert system and add
            // them to the list view.
            var bookmarks = MainForm.CurrentSystem.GetBookmarks();
            foreach (var bookmark in bookmarks)
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(bookmark.Description);
                lvItem.SubItems.Add(bookmark.Time.ToLocalTime().ToString("s"));
                lvItem.SubItems.Add(bookmark.Id);
                lvItem.SubItems.Add(bookmark.DataSource.Name);
                lvItem.Tag = bookmark;
                lvBookmarkManager.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            // Get the associated bookmark object from the selected item and delete
            // it from the VideoXpert system.
            var bookmark = (Bookmark)lvBookmarkManager.CheckedItems[0].Tag;
            MainForm.CurrentSystem.DeleteBookmark(bookmark);
            lvBookmarkManager.CheckedItems[0].Remove();
        }

        /// <summary>
        /// The ButtonNewBookmark_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonNewBookmark_Click(object sender, EventArgs args)
        {
            // Show the AddBookmarkForm dialog.
            DialogResult result;
            using (var bookmarkForm = new AddBookmarkForm())
            {
                result = bookmarkForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added bookmark.
            lvBookmarkManager.Items.Clear();
            PopulateBookmarks();
            lvBookmarkManager.Refresh();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            // Refresh the items in the list view to include the newly added bookmark.
            lvBookmarkManager.Items.Clear();
            PopulateBookmarks();
            lvBookmarkManager.Refresh();
        }

        /// <summary>
        /// The ListViewBookmarkManager_ItemCheck method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ListViewBookmarkManager_ItemCheck(object sender, ItemCheckEventArgs args)
        {
            // If we have the lastItem set as checked, and it is different
            // item than the one that fired the event, uncheck it.
            if (_lastItemChecked != null && _lastItemChecked.Checked
                && _lastItemChecked != lvBookmarkManager.Items[args.Index])
            {
                // Uncheck the last item and store the new one.
                _lastItemChecked.Checked = false;
            }

            // Store the current item.
            _lastItemChecked = lvBookmarkManager.Items[args.Index];
        }
    }
}
