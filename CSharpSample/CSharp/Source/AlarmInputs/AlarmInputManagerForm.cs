using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AlarmInputManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view alarm inputs on the VideoXpert system.</remarks>
    public partial class AlarmInputManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AlarmInputManagerForm" /> class.
        /// </summary>
        public AlarmInputManagerForm()
        {
            InitializeComponent();

            PopulateAlarmInputs();
        }

        /// <summary>
        /// The ButtonModify_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonModify_Click(object sender, EventArgs args)
        {
            if (lvAlarmInputManager.SelectedItems.Count == 0)
                return;

            var alarmInput = (AlarmInput)lvAlarmInputManager.SelectedItems[0].Tag;

            // Show the ModifyAlarmInputForm dialog.
            DialogResult result;
            using (var modifyAlarmInputForm = new ModifyAlarmInputForm(alarmInput))
            {
                result = modifyAlarmInputForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view.
            PopulateAlarmInputs();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            // Refresh the items in the list view.
            PopulateAlarmInputs();
            lvAlarmInputManager.Refresh();
        }

        /// <summary>
        /// The PopulateAlarmInputs method.
        /// </summary>
        private void PopulateAlarmInputs()
        {
            // Get the existing alarm inputs from the VideoXpert system and add
            // them to the list view.
            lvAlarmInputManager.Items.Clear();
            var alarmInputs = MainForm.CurrentSystem.GetAlarmInputs();
            foreach (var alarmInput in alarmInputs)
            {
                var lvItem = new ListViewItem(alarmInput.Name);
                lvItem.SubItems.Add(alarmInput.Description);
                lvItem.SubItems.Add(alarmInput.Id);
                lvItem.SubItems.Add(alarmInput.State.ToString());
                lvItem.Tag = alarmInput;
                lvAlarmInputManager.Items.Add(lvItem);
            }
        }
    }
}
