using System;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The EventSearchForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to search for events.</remarks>
    public partial class EventSearchForm : Form
    {
        /// <summary>
        /// Gets or sets the StartIndex property.
        /// </summary>
        /// <value>The index of the first element returned in current page of the collection.</value>
        private int StartIndex { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="EventSearchForm" /> class.
        /// </summary>
        public EventSearchForm()
        {
            InitializeComponent();

            // Get the situations available on the VideoXpert system and use
            // them to pre-populate the type drop down.
            var situations = MainForm.CurrentSystem.GetSituations();
            foreach (var situation in situations.Where(situation => !string.IsNullOrEmpty(situation.Type)))
                cbxSituationType.Items.Add(situation.Type);

            cbxSituationType.SelectedIndex = 0;
            dtpStartDate.Value = DateTime.Now - TimeSpan.FromDays(1);
            StartIndex = 0;
        }

        /// <summary>
        /// The ButtonAck_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAck_Click(object sender, EventArgs args)
        {
            if (lvEvents.SelectedItems.Count == 0)
                return;

            // Get the associated event object from the selected item and acknowledge it.
            var tag = (Event)lvEvents.SelectedItems[0].Tag;
            tag.Acknowledge();
        }

        /// <summary>
        /// The ButtonClear_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonClear_Click(object sender, EventArgs args)
        {
            btnNextPage.Enabled = false;
            btnPreviousPage.Enabled = false;
            lvEvents.Items.Clear();
        }

        /// <summary>
        /// The ButtonNextPage_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonNextPage_Click(object sender, EventArgs args)
        {
            btnNextPage.Enabled = false;
            StartIndex += (int)nudResultsPerPage.Value;
            Search();
        }

        /// <summary>
        /// The ButtonPreviousPage_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonPreviousPage_Click(object sender, EventArgs args)
        {
            btnPreviousPage.Enabled = false;
            StartIndex -= (int)nudResultsPerPage.Value;
            if (StartIndex < 0)
                StartIndex = 0;

            Search();
        }

        /// <summary>
        /// The ButtonSearch_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSearch_Click(object sender, EventArgs args)
        {
            StartIndex = 0;
            btnPreviousPage.Enabled = false;
            btnNextPage.Enabled = false;
            Search();
        }

        /// <summary>
        /// The ButtonSilence_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSilence_Click(object sender, EventArgs args)
        {
            if (lvEvents.SelectedItems.Count == 0)
                return;

            // Get the associated event object from the selected item and silence it.
            var selEvent = (Event)lvEvents.SelectedItems[0].Tag;

            decimal value = 0;
            if (InputBox.Show("Silence", "Wake Time:", ref value) == DialogResult.OK)
                selEvent.Silence((int)value);
        }

        /// <summary>
        /// Perform an event search.
        /// </summary>
        private void Search()
        {
            var type = string.Empty;
            if (cbxSituationType.SelectedIndex != 0)
                type = cbxSituationType.SelectedItem.ToString();

            var start = dtpStartDate.Value.ToUniversalTime();
            var end = dtpEndDate.Value.ToUniversalTime();
            var count = (int)nudResultsPerPage.Value;
            var events = MainForm.CurrentSystem.SearchEvents(type, start, end, StartIndex, count);
            if (events.Count > 0)
            {
                lvEvents.Items.Clear();
                if (events.Count >= (int)nudResultsPerPage.Value)
                    btnNextPage.Enabled = true;

                if (StartIndex > 0)
                    btnPreviousPage.Enabled = true;
            }
            else
                btnNextPage.Enabled = false;

            foreach (var vxEvent in events)
            {
                var lvItem = new ListViewItem(vxEvent.Time.ToLocalTime().ToString("u"));
                lvItem.SubItems.Add(vxEvent.SituationType);
                lvItem.SubItems.Add(vxEvent.Id);
                lvItem.SubItems.Add(vxEvent.Severity.ToString());
                lvItem.SubItems.Add(vxEvent.AckState.ToString());
                lvItem.Tag = vxEvent;
                lvEvents.Items.Add(lvItem);
            }
        }
    }
}
