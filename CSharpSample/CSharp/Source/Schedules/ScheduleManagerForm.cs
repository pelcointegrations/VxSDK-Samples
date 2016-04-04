using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ScheduleManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view, create and delete
    /// schedules from the VideoXpert system.</remarks>
    public partial class ScheduleManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="ScheduleManagerForm" /> class.
        /// </summary>
        public ScheduleManagerForm()
        {
            InitializeComponent();

            PopulateSchedules();
        }

        /// <summary>
        /// The PopulateSchedules method.
        /// </summary>
        private void PopulateSchedules()
        {
            // Get the existing schedules from the VideoXpert system and add
            // them to the list view.
            var schedules = MainForm.CurrentSystem.GetSchedules();
            foreach (var schedule in schedules)
            {
                var scheduleSources = schedule.GetLinks();

                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(schedule.Name);
                lvItem.SubItems.Add(schedule.Id);
                lvItem.SubItems.Add(schedule.Action.ToString());
                lvItem.SubItems.Add(schedule.UseAllDataSources.ToString());
                lvItem.SubItems.Add(scheduleSources.Count.ToString());
                lvItem.SubItems.Add(schedule.ScheduleTriggers.Count.ToString());
                lvItem.Tag = schedule;
                lvScheduleManager.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonDelete_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonDelete_Click(object sender, EventArgs args)
        {
            foreach (ListViewItem item in lvScheduleManager.CheckedItems)
            {
                // Get the associated Schedule object from the selected item and delete
                // it from the VideoXpert system.
                var schedule = (Schedule)item.Tag;
                MainForm.CurrentSystem.DeleteSchedule(schedule);
                item.Remove();
            }
        }

        /// <summary>
        /// The ButtonNewSchedule_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonNewSchedule_Click(object sender, EventArgs args)
        {
            // Show the AddScheduleForm dialog.
            DialogResult result;
            using (var scheduleForm = new AddScheduleForm())
            {
                result = scheduleForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include the newly added schedule.
            lvScheduleManager.Items.Clear();
            PopulateSchedules();
            lvScheduleManager.Refresh();
        }

        /// <summary>
        /// The ButtonViewDetails_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonViewDetails_Click(object sender, EventArgs args)
        {
            if (lvScheduleManager.CheckedItems.Count != 1)
                return;

            var situation = (Schedule)lvScheduleManager.CheckedItems[0].Tag;

            using (var scheduleDetailsForm = new ScheduleDetailsForm())
            {
                scheduleDetailsForm.GetScheduleInfo(situation);
                scheduleDetailsForm.ShowDialog();
            }
        }

        /// <summary>
        /// The ButtonManageSources_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonManageSources_Click(object sender, EventArgs args)
        {
            if (lvScheduleManager.CheckedItems.Count != 1)
                return;

            var schedule = (Schedule)lvScheduleManager.CheckedItems[0].Tag;

            // Show the ModifyScheduleSourcesForm dialog.
            DialogResult result;
            using (var modifySourcesForm = new ModifyScheduleSourcesForm(schedule))
            {
                result = modifySourcesForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view to include any new changes.
            lvScheduleManager.Items.Clear();
            PopulateSchedules();
            lvScheduleManager.Refresh();
        }
    }
}
