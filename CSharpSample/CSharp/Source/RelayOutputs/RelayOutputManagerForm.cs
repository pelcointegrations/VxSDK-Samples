using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The RelayOutputManagerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view relay outputs on the VideoXpert system.</remarks>
    public partial class RelayOutputManagerForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="RelayOutputManagerForm" /> class.
        /// </summary>
        public RelayOutputManagerForm()
        {
            InitializeComponent();

            PopulateRelayOutputs();
        }

        /// <summary>
        /// The ButtonModify_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonModify_Click(object sender, EventArgs args)
        {
            if (lvRelayOutputManager.SelectedItems.Count == 0)
                return;

            var relayOutput = (RelayOutput)lvRelayOutputManager.SelectedItems[0].Tag;

            // Show the ModifyRelayOutputForm dialog.
            DialogResult result;
            using (var modifyRelayOutputForm = new ModifyRelayOutputForm(relayOutput))
            {
                result = modifyRelayOutputForm.ShowDialog();
            }

            // If the dialog was closed without clicking OK then skip the refresh.
            if (result != DialogResult.OK)
                return;

            // Refresh the items in the list view.
            PopulateRelayOutputs();
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonRefresh_Click(object sender, EventArgs args)
        {
            // Refresh the items in the list view.
            PopulateRelayOutputs();
            lvRelayOutputManager.Refresh();
        }

        /// <summary>
        /// The ButtonTrigger_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonTrigger_Click(object sender, EventArgs args)
        {
            if (lvRelayOutputManager.SelectedItems.Count == 0)
                return;

            // Get the associated relay output object from the selected item and trigger it.
            var relayOutput = (RelayOutput)lvRelayOutputManager.SelectedItems[0].Tag;
            if (relayOutput == null)
                return;

            relayOutput.State = relayOutput.State == RelayOutput.RelayStates.Active ? RelayOutput.RelayStates.Inactive : RelayOutput.RelayStates.Active;
            relayOutput.Refresh();
            lvRelayOutputManager.SelectedItems[0].SubItems[3].Text = relayOutput.State.ToString();
            lvRelayOutputManager.Refresh();
            btnTrigger.Text = relayOutput.State == RelayOutput.RelayStates.Active ? "Deactivate" : "Activate";
        }

        /// <summary>
        /// The ListViewRelayOutputManager_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ListViewRelayOutputManager_SelectedIndexChanged(object sender, EventArgs args)
        {
            if (lvRelayOutputManager.SelectedItems.Count == 0)
                return;

            // Get the associated relay output object from the selected item.
            var relayOutput = (RelayOutput)lvRelayOutputManager.SelectedItems[0].Tag;
            if (relayOutput == null)
                return;

            btnTrigger.Text = relayOutput.State == RelayOutput.RelayStates.Active ? "Deactivate" : "Activate";
        }

        /// <summary>
        /// The PopulateRelayOutputs method.
        /// </summary>
        private void PopulateRelayOutputs()
        {
            // Get the existing relay outputs from the VideoXpert system and add
            // them to the list view.
            lvRelayOutputManager.Items.Clear();
            var relayOutputs = MainForm.CurrentSystem.GetRelayOutputs();
            foreach (var relayOutput in relayOutputs)
            {
                var lvItem = new ListViewItem(relayOutput.Name);
                lvItem.SubItems.Add(relayOutput.Description);
                lvItem.SubItems.Add(relayOutput.Id);
                lvItem.SubItems.Add(relayOutput.State.ToString());
                lvItem.Tag = relayOutput;
                lvRelayOutputManager.Items.Add(lvItem);
            }
        }
    }
}
