using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The DrawingManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// drawings from the VideoXpert system.</remarks>
    public partial class DrawingManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="DrawingManagerForm" /> class.
        /// </summary>
        public DrawingManagerForm()
        {
            InitializeComponent();

            PopulateDrawings();
        }

        /// <summary>
        /// The PopulateDrawings method.
        /// </summary>
        private void PopulateDrawings()
        {
            // Get the existing drawings from the VideoXpert system and add
            // them to the list view.
            var drawings = MainForm.CurrentSystem.GetDrawings();
            foreach (var drawing in drawings)
            {
                var markers = drawing.Markers;

                var lvItem = new ListViewItem(drawing.Name);
                lvItem.SubItems.Add(drawing.Id);
                lvItem.SubItems.Add(markers.Count.ToString());
                lvItem.Tag = drawing;
                lvDrawingManager.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            if (lvDrawingManager.SelectedItems.Count == 0)
                return;

            // Get the associated drawing object from the selected item and delete
            // it from the VideoXpert system.
            var drawing = (Drawing)lvDrawingManager.SelectedItems[0].Tag;
            MainForm.CurrentSystem.DeleteDrawing(drawing);
            lvDrawingManager.SelectedItems[0].Remove();
        }

        /// <summary>
        /// The ButtonNewDrawing_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonNewDrawing_Click(object sender, EventArgs args)
        {
            // Show the AddDrawingForm dialog.
            DialogResult result;
            using (var addDrawingForm = new AddDrawingForm())
            {
                result = addDrawingForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added drawing.
            lvDrawingManager.Items.Clear();
            PopulateDrawings();
            lvDrawingManager.Refresh();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            // Refresh the items in the list view to include the newly added drawing.
            lvDrawingManager.Items.Clear();
            PopulateDrawings();
            lvDrawingManager.Refresh();
        }

        /// <summary>
        /// The ButtonModify_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonModify_Click(object sender, EventArgs args)
        {
            if (lvDrawingManager.SelectedItems.Count == 0)
                return;

            var drawing = (Drawing)lvDrawingManager.SelectedItems[0].Tag;
            using (var editDrawingForm = new ModifyDrawingForm(drawing))
            {
                var result = editDrawingForm.ShowDialog();
                if (result != DialogResult.OK)
                    return;

                // Refresh the items in the list view to include the newly added Drawing.
                lvDrawingManager.Items.Clear();
                PopulateDrawings();
                lvDrawingManager.Refresh();
            }
        }

        /// <summary>
        /// The ButtonView_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonView_Click(object sender, EventArgs args)
        {
            if (lvDrawingManager.SelectedItems.Count == 0)
                return;

            var drawing = (Drawing)lvDrawingManager.SelectedItems[0].Tag;
            using (var viewDrawingForm = new ViewDrawingForm(drawing))
            {
                viewDrawingForm.ShowDialog();
            }
        }
    }
}
