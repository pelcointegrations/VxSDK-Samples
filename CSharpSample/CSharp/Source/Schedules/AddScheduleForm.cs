using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddScheduleForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to select the settings
    /// that will be used to create a new schedule.</remarks> 
    public partial class AddScheduleForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddScheduleForm" /> class.
        /// </summary>
        public AddScheduleForm()
        {
            InitializeComponent();
            cbxAction.SelectedIndex = 1;
        }

        /// <summary>
        /// The ButtonGenerate_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonGenerate_Click(object sender, EventArgs args)
        {
            tbxId.Clear();
            tbxId.Text = Guid.NewGuid().ToString();
        }

        /// <summary>
        /// The ButtonAddScheduleTrigger_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAddScheduleTrigger_Click(object sender, EventArgs args)
        {
            // Show the ScheduleTriggerForm dialog in new mode.
            using (var addScheduleTriggerForm = new AddScheduleTriggerForm(lvScheduleTriggers))
            {
                addScheduleTriggerForm.ShowDialog();
            }

            // Refresh the items in the list view.
            lvScheduleTriggers.Refresh();
        }

        /// <summary>
        /// The ButtonRemoveScheduleTrigger_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRemoveScheduleTrigger_Click(object sender, EventArgs args)
        {
            if (lvScheduleTriggers.CheckedItems.Count <= 0)
                return;

            for (var i = lvScheduleTriggers.Items.Count - 1; i >= 0; i--)
            {
                if (lvScheduleTriggers.Items[i].Checked)
                    lvScheduleTriggers.Items[i].Remove();
            }
        }

        /// <summary>
        /// The ButtonAdd_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            if (lvScheduleTriggers.Items.Count == 0)
                return;

            var newSchedule = new NewSchedule
            {
                Id = tbxId.Text,
                Name = tbxName.Text,
                UseAllDataSources = ckbxUseAllDataSources.Checked,
                Action = (Schedule.Actions)cbxAction.SelectedIndex + 1
            };

            foreach (ListViewItem triggerItem in lvScheduleTriggers.Items)
                newSchedule.ScheduleTriggers.Add((NewScheduleTrigger)triggerItem.Tag);

            try
            {
                MainForm.CurrentSystem.AddSchedule(newSchedule);
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog(string.Format("Error creating schedule: {0}", ex.Message));
            }
        }

        /// <summary>
        /// The ListViewScheduleTriggers_ItemChecked method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ListViewScheduleTriggers_ItemChecked(object sender, ItemCheckedEventArgs args)
        {
            btnRemoveScheduleTrigger.Enabled = lvScheduleTriggers.CheckedItems.Count > 0;
        }
    }
}
