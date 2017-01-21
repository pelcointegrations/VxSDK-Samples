using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The MonitorManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// monitors from the VideoXpert system.</remarks>
    public partial class MonitorManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="MonitorManagerForm" /> class.
        /// </summary>
        public MonitorManagerForm()
        {
            InitializeComponent();

            PopulateMonitors();
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            // Verify that an item is selected.
            if (lvMonitorManager.SelectedItems.Count == 0)
                return;

            // Get the associated monitor object from the selected item and delete
            // it from the VideoXpert system.
            var monitor = (Monitor)lvMonitorManager.SelectedItems[0].Tag;
            MainForm.CurrentSystem.RemoveMonitor(monitor);
            lvMonitorManager.SelectedItems[0].Remove();
        }

        /// <summary>
        /// The ButtonNewMonitor_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonNewMonitor_Click(object sender, EventArgs args)
        {
            // Show the AddMonitorForm dialog.
            DialogResult result;
            using (var addMonitorForm = new AddMonitorForm())
            {
                result = addMonitorForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result == DialogResult.Cancel)
                return;

            // Refresh the items in the list view to include the newly added monitor.
            lvMonitorManager.Items.Clear();
            PopulateMonitors();
            lvMonitorManager.Refresh();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            // Refresh the items in the list view.
            lvMonitorManager.Items.Clear();
            PopulateMonitors();
            lvMonitorManager.Refresh();
        }

        /// <summary>
        /// The ButtonView_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonView_Click(object sender, EventArgs args)
        {
            // Verify that an item is selected.
            if (lvMonitorManager.SelectedItems.Count == 0)
                return;

            // Show the ViewMonitorForm dialog.
            var monitor = (Monitor)lvMonitorManager.SelectedItems[0].Tag;
            using (var viewMonitorForm = new ViewMonitorForm(monitor))
            {
                viewMonitorForm.ShowDialog();
            }

            // Refresh the items in the list view.
            lvMonitorManager.Items.Clear();
            PopulateMonitors();
            lvMonitorManager.Refresh();
        }

        /// <summary>
        /// The PopulateMonitors method.
        /// </summary>
        private void PopulateMonitors()
        {
            // Get the existing monitors from the VideoXpert system and add
            // them to the list view.
            var monitors = MainForm.CurrentSystem.GetMonitors();
            foreach (var monitor in monitors)
            {
                var lvItem = new ListViewItem(monitor.Number.ToString());
                lvItem.SubItems.Add(monitor.Name);
                lvItem.SubItems.Add(monitor.Layout.ToString().Replace("CellLayout", ""));
                lvItem.Tag = monitor;
                lvMonitorManager.Items.Add(lvItem);
            }
        }
    }
}
