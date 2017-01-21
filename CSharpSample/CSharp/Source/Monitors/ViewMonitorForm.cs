using System;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ViewMonitorForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view a monitor.</remarks>
    public partial class ViewMonitorForm : Form
    {
        /// <summary>
        /// Gets or sets the currently selected monitor.
        /// </summary>
        /// <value>The current monitor.</value>
        private Monitor CurrentMonitor { get; set; }

        /// <summary>
        /// Gets or sets the IsInitialized property.
        /// </summary>
        /// <value>Specifies whether the layout combo box has been initialized or not.</value>
        private bool IsInitialized { get; set; }

        /// <summary>
        /// Gets or sets the LastSelectedPanel property.
        /// </summary>
        /// <value>The last panel selected by the user.</value>
        private Panel LastSelectedPanel { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ViewMonitorForm" /> class.
        /// </summary>
        /// <param name="monitor">The monitor to view.</param>
        public ViewMonitorForm(Monitor monitor)
        {
            InitializeComponent();

            PopulateDataSources();
            dtpTime.Value = DateTime.Now.AddHours(-1);
            CurrentMonitor = monitor;
            IsInitialized = false;
            cbxLayouts.SelectedIndex = (int)CurrentMonitor.Layout;
            ResetTableValues();
            SetCellLayout();
        }

        /// <summary>
        /// Adds a right-click context menu to a label.
        /// </summary>
        /// <param name="label">The label to add the context menu to.</param>
        private void AddContextMenu(Control label)
        {
            var cm = new ContextMenu();
            cm.MenuItems.Add("Remove Data Source");
            cm.MenuItems[0].Tag = label;
            cm.MenuItems[0].Click += MenuItemRemoveDataSource_OnClick;
            label.ContextMenu = cm;
        }

        /// <summary>
        /// The ButtonLive_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonLive_Click(object sender, EventArgs args)
        {
            // Verify a panel has been selected.
            if (LastSelectedPanel == null)
                return;

            var label = LastSelectedPanel.Controls.OfType<Label>().FirstOrDefault();
            if (label == null)
                return;

            var cell = (MonitorCell)label.Tag;
            if (cell != null)
                cell.GoToLive();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            CurrentMonitor.Refresh();
            IsInitialized = false;
            ResetTableValues();
            cbxLayouts.SelectedIndex = (int)CurrentMonitor.Layout;
        }

        /// <summary>
        /// The ButtonSetSpeed_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSetSpeed_Click(object sender, EventArgs args)
        {
            // Verify a panel has been selected.
            if (LastSelectedPanel == null)
                return;

            var label = LastSelectedPanel.Controls.OfType<Label>().FirstOrDefault();
            if (label == null)
                return;

            var cell = (MonitorCell)label.Tag;
            if (cell != null)
                cell.Speed = (float)nudSpeed.Value;
        }

        /// <summary>
        /// The ButtonSetTime_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSetTime_Click(object sender, EventArgs args)
        {
            // Verify a panel has been selected.
            if (LastSelectedPanel == null)
                return;

            var label = LastSelectedPanel.Controls.OfType<Label>().FirstOrDefault();
            if (label == null)
                return;

            var cell = (MonitorCell)label.Tag;
            if (cell != null)
                cell.Time = dtpTime.Value.ToUniversalTime();
        }

        /// <summary>
        /// The ComboBoxLayouts_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ComboBoxLayouts_SelectedIndexChanged(object sender, EventArgs args)
        {
            // Skip setting the montor layout if this is the first call to this method.
            if (!IsInitialized)
            {
                IsInitialized = true;
                SetCellLayout();
                return;
            }

            // Set the layout on the monitor and refresh the cell layout in the UI.
            CurrentMonitor.Layout = (Monitor.Layouts)cbxLayouts.SelectedIndex;
            SetCellLayout();
        }

        /// <summary>
        /// Adjusts the cells within the table layout panel based on the selected monitor layout.
        /// </summary>
        private void DisableExtraRows(int startingRowIndex)
        {
            // Set the height for each row beyond the start index to 0.
            for (var i = 0; i <= tlpCells.RowStyles.Count; i++)
                if (i > startingRowIndex)
                    tlpCells.RowStyles[i - 1].Height = 0;
        }

        /// <summary>
        /// The LabelCell_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void LabelCell_Click(object sender, EventArgs args)
        {
            // Remove the highlight from the last selected panel.
            if (LastSelectedPanel != null)
                LastSelectedPanel.BackColor = Color.Black;

            // Get the label that was clicked.
            var label = sender as Label;
            if (label == null)
                return;

            // Get the parent panel of the label.
            var panel = label.Parent as Panel;
            if (panel == null)
                return;

            // Set the highlight for the selected panel.
            panel.BackColor = Color.White;
            LastSelectedPanel = panel;
        }

        /// <summary>
        /// The LabelCell_OnDragDrop method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void LabelCell_OnDragDrop(object sender, DragEventArgs args)
        {
            // Get the label that the data source was dropped on to.
            var label = (Label)sender;

            // Get the data source that was dropped on to the label.
            var dataSource = ((ListViewItem)args.Data.GetData(typeof(ListViewItem))).Tag as DataSource;
            if (dataSource != null)
            {
                // Set the label text and the data source for the monitor cell.
                label.Text = dataSource.Name;
                var cell = label.Tag as MonitorCell;
                if (cell != null)
                    cell.DataSourceId = dataSource.Id;
            }

            // Refresh the UI to verify the label is updated.
            Refresh();
        }

        /// <summary>
        /// The LabelCell_OnDragEnter method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void LabelCell_OnDragEnter(object sender, DragEventArgs args)
        {
            if (args.Data.GetDataPresent(typeof(ListViewItem)))
                args.Effect = DragDropEffects.Move;
        }

        /// <summary>
        /// The ListViewDataSources_OnItemDrag method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ListViewDataSources_OnItemDrag(object sender, ItemDragEventArgs args)
        {
            DoDragDrop(args.Item, DragDropEffects.Move);
        }

        /// <summary>
        /// The MenuItemRemoveDataSource_OnClick method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemRemoveDataSource_OnClick(object sender, EventArgs args)
        {
            // Get the menu item that was clicked.
            var item = (MenuItem)sender;

            // Get the label from the menu items tag.
            var label = item.Tag as Label;
            if (label == null)
                return;

            // Clear the label and remove the data source from the monitor cell.
            label.Text = string.Empty;
            var cell = label.Tag as MonitorCell;
            if (cell != null)
                cell.DataSourceId = string.Empty;
        }

        /// <summary>
        /// Populates the list view with all available data sources.
        /// </summary>
        private void PopulateDataSources()
        {
            // Clear any existing items from the list view.
            lvDataSources.Items.Clear();

            // Get the existing data sources from the VideoXpert system and add
            // them to the list view.
            var dataSources = MainForm.CurrentDataSources;
            foreach (var dataSource in dataSources)
            {
                var lvItem = new ListViewItem(dataSource.Name);
                lvItem.SubItems.Add(dataSource.Ip);
                lvItem.Tag = dataSource;
                lvDataSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// Resets the table layout panel settings to the default values.
        /// </summary>
        private void ResetTableValues()
        {
            // Set the row and column count to the default 4x4 layout.
            tlpCells.RowCount = 4;
            tlpCells.ColumnCount = 4;

            // Reset the column and row spans for each panel in the table layout.
            foreach (var panel in tlpCells.Controls.OfType<Panel>())
            {
                tlpCells.SetColumnSpan(panel, 1);
                tlpCells.SetRowSpan(panel, 1);
            }

            // Reset all row size types to percentage.
            foreach (RowStyle row in tlpCells.RowStyles)
                row.SizeType = SizeType.Percent;

            // Reset all column size types to percentage.
            foreach (ColumnStyle column in tlpCells.ColumnStyles)
                column.SizeType = SizeType.Percent;
        }

        /// <summary>
        /// Sets the labels for each cell within the table layout panel.
        /// </summary>
        private void SetCellLabels()
        {
            var panels = tlpCells.Controls.OfType<Panel>().ToList();
            panels.Sort((x, y) => string.CompareOrdinal(x.Name, y.Name));

            var cells = CurrentMonitor.MonitorCells;
            foreach (var cell in cells)
            {
                var dataSource = MainForm.CurrentDataSources.FirstOrDefault(ds => ds.Id == cell.DataSourceId);
                var label = panels[cell.Index - 1].Controls.OfType<Label>().FirstOrDefault();
                if (label == null)
                    continue;

                label.Text = dataSource != null ? dataSource.Name : string.Empty;
                label.Tag = cell;
                AddContextMenu(label);
            }
        }

        /// <summary>
        /// Adjusts the cells within the table layout panel based on the selected monitor layout.
        /// </summary>
        private void SetCellLayout()
        {
            // Get the current monitor layout.
            var layout = CurrentMonitor.Layout;

            // Reset the table layout panel settings.
            ResetTableValues();

            // Adjust the table layout panel cells based on the layout.
            switch (layout)
            {
                case Monitor.Layouts.CellLayout1x1:
                    tlpCells.ColumnCount = 1;
                    tlpCells.ColumnStyles[0].Width = 100;
                    tlpCells.RowStyles[0].Height = 100;
                    DisableExtraRows(1);
                    break;
                case Monitor.Layouts.CellLayout1x2:
                    tlpCells.ColumnCount = 1;
                    tlpCells.ColumnStyles[0].Width = 100;
                    tlpCells.RowStyles[0].Height = 50;
                    tlpCells.RowStyles[1].Height = 50;
                    DisableExtraRows(2);
                    break;
                case Monitor.Layouts.CellLayout2x1:
                    tlpCells.ColumnCount = 2;
                    tlpCells.ColumnStyles[0].Width = 50;
                    tlpCells.ColumnStyles[1].Width = 50;
                    tlpCells.RowStyles[0].Height = 100;
                    DisableExtraRows(1);
                    break;
                case Monitor.Layouts.CellLayout2x2:
                    tlpCells.ColumnCount = 2;
                    tlpCells.ColumnStyles[0].Width = 50;
                    tlpCells.ColumnStyles[1].Width = 50;
                    tlpCells.RowStyles[0].Height = 50;
                    tlpCells.RowStyles[1].Height = 50;
                    DisableExtraRows(2);
                    break;
                case Monitor.Layouts.CellLayout2x3:
                    tlpCells.ColumnCount = 2;
                    tlpCells.ColumnStyles[0].Width = 50;
                    tlpCells.ColumnStyles[1].Width = 50;
                    tlpCells.RowStyles[0].Height = 33.3f;
                    tlpCells.RowStyles[1].Height = 33.3f;
                    tlpCells.RowStyles[2].Height = 33.3f;
                    DisableExtraRows(3);
                    break;
                case Monitor.Layouts.CellLayout3x2:
                    tlpCells.ColumnCount = 3;
                    tlpCells.ColumnStyles[0].Width = 33.3f;
                    tlpCells.ColumnStyles[1].Width = 33.3f;
                    tlpCells.ColumnStyles[2].Width = 33.3f;
                    tlpCells.RowStyles[0].Height = 50;
                    tlpCells.RowStyles[1].Height = 50;
                    DisableExtraRows(2);
                    break;
                case Monitor.Layouts.CellLayout3x3:
                    tlpCells.ColumnCount = 3;
                    tlpCells.ColumnStyles[0].Width = 33.3f;
                    tlpCells.ColumnStyles[1].Width = 33.3f;
                    tlpCells.ColumnStyles[2].Width = 33.3f;
                    tlpCells.RowStyles[0].Height = 33.3f;
                    tlpCells.RowStyles[1].Height = 33.3f;
                    tlpCells.RowStyles[2].Height = 33.3f;
                    DisableExtraRows(3);
                    break;
                case Monitor.Layouts.CellLayout4x3:
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 33.3f;
                    tlpCells.RowStyles[1].Height = 33.3f;
                    tlpCells.RowStyles[2].Height = 33.3f;
                    DisableExtraRows(3);
                    break;
                case Monitor.Layouts.CellLayout4x4:
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 25;
                    tlpCells.RowStyles[1].Height = 25;
                    tlpCells.RowStyles[2].Height = 25;
                    tlpCells.RowStyles[3].Height = 25;
                    break;
                case Monitor.Layouts.CellLayout1plus12:
                    tlpCells.SetColumnSpan(pnlCell_01, 2);
                    tlpCells.SetRowSpan(pnlCell_01, 2);
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 25;
                    tlpCells.RowStyles[1].Height = 25;
                    tlpCells.RowStyles[2].Height = 25;
                    tlpCells.RowStyles[3].Height = 25;
                    DisableExtraRows(4);
                    break;
                case Monitor.Layouts.CellLayout2plus8:
                    tlpCells.SetColumnSpan(pnlCell_01, 2);
                    tlpCells.SetColumnSpan(pnlCell_02, 2);
                    tlpCells.SetRowSpan(pnlCell_01, 2);
                    tlpCells.SetRowSpan(pnlCell_02, 2);
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 25;
                    tlpCells.RowStyles[1].Height = 25;
                    tlpCells.RowStyles[2].Height = 25;
                    tlpCells.RowStyles[3].Height = 25;
                    DisableExtraRows(4);
                    break;
                case Monitor.Layouts.CellLayout3plus4:
                    tlpCells.SetColumnSpan(pnlCell_01, 2);
                    tlpCells.SetColumnSpan(pnlCell_02, 2);
                    tlpCells.SetColumnSpan(pnlCell_03, 2);
                    tlpCells.SetRowSpan(pnlCell_01, 2);
                    tlpCells.SetRowSpan(pnlCell_02, 2);
                    tlpCells.SetRowSpan(pnlCell_03, 2);
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 25;
                    tlpCells.RowStyles[1].Height = 25;
                    tlpCells.RowStyles[2].Height = 25;
                    tlpCells.RowStyles[3].Height = 25;
                    DisableExtraRows(4);
                    break;
                case Monitor.Layouts.CellLayout1plus5:
                    tlpCells.ColumnCount = 3;
                    tlpCells.SetColumnSpan(pnlCell_01, 2);
                    tlpCells.SetRowSpan(pnlCell_01, 2);
                    tlpCells.ColumnStyles[0].Width = 33.3f;
                    tlpCells.ColumnStyles[1].Width = 33.3f;
                    tlpCells.ColumnStyles[2].Width = 33.3f;
                    tlpCells.RowStyles[0].Height = 33.3f;
                    tlpCells.RowStyles[1].Height = 33.3f;
                    tlpCells.RowStyles[2].Height = 33.3f;
                    DisableExtraRows(3);
                    break;
                case Monitor.Layouts.CellLayout1plus7:
                    tlpCells.SetColumnSpan(pnlCell_01, 3);
                    tlpCells.SetRowSpan(pnlCell_01, 3);
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 25;
                    tlpCells.RowStyles[1].Height = 25;
                    tlpCells.RowStyles[2].Height = 25;
                    tlpCells.RowStyles[3].Height = 25;
                    DisableExtraRows(4);
                    break;
                case Monitor.Layouts.CellLayout12plus1:
                    tlpCells.SetColumnSpan(pnlCell_06, 2);
                    tlpCells.SetRowSpan(pnlCell_06, 2);
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 25;
                    tlpCells.RowStyles[1].Height = 25;
                    tlpCells.RowStyles[2].Height = 25;
                    tlpCells.RowStyles[3].Height = 25;
                    DisableExtraRows(4);
                    break;
                case Monitor.Layouts.CellLayout8plus2:
                    tlpCells.SetColumnSpan(pnlCell_05, 2);
                    tlpCells.SetColumnSpan(pnlCell_06, 2);
                    tlpCells.SetRowSpan(pnlCell_05, 2);
                    tlpCells.SetRowSpan(pnlCell_06, 2);
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 25;
                    tlpCells.RowStyles[1].Height = 25;
                    tlpCells.RowStyles[2].Height = 25;
                    tlpCells.RowStyles[3].Height = 25;
                    DisableExtraRows(4);
                    break;
                case Monitor.Layouts.CellLayout1plus4tall:
                    tlpCells.SetColumnSpan(pnlCell_01, 3);
                    tlpCells.SetRowSpan(pnlCell_01, 4);
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 25;
                    tlpCells.RowStyles[1].Height = 25;
                    tlpCells.RowStyles[2].Height = 25;
                    tlpCells.RowStyles[3].Height = 25;
                    DisableExtraRows(4);
                    break;
                case Monitor.Layouts.CellLayout1plus4wide:
                    tlpCells.SetColumnSpan(pnlCell_01, 4);
                    tlpCells.SetRowSpan(pnlCell_01, 3);
                    tlpCells.ColumnStyles[0].Width = 25;
                    tlpCells.ColumnStyles[1].Width = 25;
                    tlpCells.ColumnStyles[2].Width = 25;
                    tlpCells.ColumnStyles[3].Width = 25;
                    tlpCells.RowStyles[0].Height = 25;
                    tlpCells.RowStyles[1].Height = 25;
                    tlpCells.RowStyles[2].Height = 25;
                    tlpCells.RowStyles[3].Height = 25;
                    DisableExtraRows(4);
                    break;
                default:
                    MainForm.Instance.WriteToLog("Unknown Monitor Layout Selected.");
                    break;
            }

            // Set the labels for the cells and refresh the UI.
            SetCellLabels();
            Refresh();
        }
    }
}
