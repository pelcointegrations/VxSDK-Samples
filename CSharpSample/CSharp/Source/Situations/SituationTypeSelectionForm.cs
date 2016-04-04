using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The SituationTypeSelectionForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to select the situation types to
    /// subscribe to.</remarks>
    public partial class SituationTypeSelectionForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="SituationTypeSelectionForm" /> class.
        /// </summary>
        public SituationTypeSelectionForm()
        {
            InitializeComponent();

            // Get the situations available on the VideoXpert system and use
            // them to pre-populate the type list.
            var situations = MainForm.CurrentSystem.GetSituations();
            foreach (var situation in situations.Where(situation => !string.IsNullOrEmpty(situation.Type)))
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(situation.Type);
                lvItem.Tag = situation;
                lvSituationTypes.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonSubscribe_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSubscribe_Click(object sender, System.EventArgs args)
        {
            // Close the dialog if no situations are checked.
            if (lvSituationTypes.CheckedItems.Count == 0)
                return;

            // Build a list of situation types based on the checked items.
            var situations = new List<Situation>();
            foreach (ListViewItem item in lvSituationTypes.CheckedItems)
                situations.Add((Situation)item.Tag);

            // Subscribe to system events using the situation types as a filter.
            MainForm.CurrentSystem.SubscribeToEventsByType(MainForm.Instance.OnSystemEvent, situations);
            MainForm.Instance.WriteToLog(string.Format("Subscribed to events for {0} situations.", situations.Count));
        }
    }
}
