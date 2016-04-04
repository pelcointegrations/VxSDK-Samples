using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ModifyScheduleSourcesForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to modify the source
    /// settings of a schedule.</remarks>
    public partial class ModifyScheduleSourcesForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedSchedule property.
        /// </summary>
        /// <value>The currently selected schedule.</value>
        private Schedule SelectedSchedule { get; set; }

        /// <summary>
        /// Gets or sets the CurrentSourceList property.
        /// </summary>
        /// <value>The list of sources for the currently selected schedule.</value>
        private List<string> CurrentSourceList { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyScheduleSourcesForm" /> class.
        /// </summary>
        /// <param name="schedule">The <paramref name="schedule"/> parameter.</param>
        public ModifyScheduleSourcesForm(Schedule schedule)
        {
            InitializeComponent();
            SelectedSchedule = schedule;
            PopulateDataSources();
        }

        /// <summary>
        /// The PopulateDataSources method.
        /// </summary>
        private void PopulateDataSources()
        {
            CurrentSourceList = new List<string>();
            foreach (var dataSource in SelectedSchedule.GetLinks())
                CurrentSourceList.Add(dataSource.Id);

            // Clone each item in the MainForm ListView and add it to lvDataSources.
            foreach (var dataSource in MainForm.CurrentDataSources)
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(dataSource.Number.ToString());
                lvItem.SubItems.Add(dataSource.Name);
                lvItem.Tag = dataSource;
                if (CurrentSourceList.Any(s => dataSource.Id.Contains(s)))
                    lvItem.Checked = true;

                lvScheduleSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonSave_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSave_Click(object sender, EventArgs args)
        {
            var linkList = new List<DataSource>();
            var unlinkList = new List<DataSource>();

            foreach (ListViewItem item in lvScheduleSources.Items)
            {
                var dataSource = (DataSource)item.Tag;

                if (item.Checked)
                {
                    if (!CurrentSourceList.Any(s => dataSource.Id.Contains(s)))
                        linkList.Add(dataSource);
                }
                else
                {
                    if (CurrentSourceList.Any(s => dataSource.Id.Contains(s)))
                        unlinkList.Add(dataSource);
                }
            }

            if (linkList.Count > 0)
                SelectedSchedule.Link(linkList);

            if (unlinkList.Count > 0)
                SelectedSchedule.Unlink(unlinkList);
        }
    }
}
