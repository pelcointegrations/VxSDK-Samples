using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddScheduleTriggerForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to select the settings
    /// that will be used to create a new schedule trigger.</remarks> 
    public partial class AddScheduleTriggerForm : Form
    {
        [DllImport("User32.dll")]
        private static extern int SendMessage(int listViewHandle, int msg, int flagParam, int objectParam);

        /// <summary>
        /// Gets or sets the ScheduleTriggerListView property.
        /// </summary>
        /// <value>The list view to add the new schedule trigger to.</value>
        public ListView ScheduleTriggerListView { get; set; }

        /// <summary>
        /// Gets or sets the LastItemChecked property.
        /// </summary>
        /// <value>The last item checked in the event sources list view.</value>
        public ListViewItem LastItemChecked { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="AddScheduleTriggerForm" /> class.
        /// </summary>
        /// <param name="listView">The <paramref name="listView"/> parameter.</param>
        public AddScheduleTriggerForm(ListView listView)
        {
            InitializeComponent();
            ScheduleTriggerListView = listView;
            SetUpForm();
        }

        /// <summary>
        /// The ListView_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ListView_SelectedIndexChanged(object sender, ListViewItemSelectionChangedEventArgs args)
        {
            if (!args.IsSelected)
                return;

            args.Item.Selected = false;
            args.Item.Focused = false;
        }

        /// <summary>
        /// The SetUpForm method.
        /// </summary>
        private void SetUpForm()
        {
            const int setIconSpacing = 0x1000 + 53;
            const int x = 34;
            const int y = 28;

            SendMessage((int)lvMonthly.Handle, setIconSpacing, 0, x * 65536 + y);
            SendMessage((int)lvYearly.Handle, setIconSpacing, 0, x * 65536 + y);
            SendMessage((int)lvWeekly.Handle, setIconSpacing, 0, x * 65536 + y);

            cbxFramerate.SelectedIndex = 1;
            cbxRecurrenceType.SelectedIndex = 0;
            cbxEvent.SelectedIndex = 0;

            foreach (var device in MainForm.CurrentDevices)
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(device.Name);
                lvItem.Tag = device;
                lvEventSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ComboBoxRecurrenceType_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ComboBoxRecurrenceType_SelectedIndexChanged(object sender, EventArgs args)
        {
            switch (cbxRecurrenceType.SelectedIndex)
            {
                case 0:
                    lvWeekly.Enabled = false;
                    lvMonthly.Enabled = false;
                    lvYearly.Enabled = false;
                    break;
                case 1:
                    lvWeekly.Enabled = true;
                    lvMonthly.Enabled = false;
                    lvYearly.Enabled = false;
                    break;
                case 2:
                    lvWeekly.Enabled = false;
                    lvMonthly.Enabled = true;
                    lvYearly.Enabled = true;
                    break;
                case 3:
                    lvWeekly.Enabled = false;
                    lvMonthly.Enabled = false;
                    lvYearly.Enabled = true;
                    break;
                default:
                    MainForm.Instance.WriteToLog(@"Invalid selection made.");
                    break;
            }
        }

        /// <summary>
        /// The ComboBoxEvent_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ComboBoxEvent_SelectedIndexChanged(object sender, EventArgs args)
        {
            if (cbxEvent.SelectedIndex == 0)
            {
                gbxEventProperties.Enabled = false;
                gbxEventSources.Enabled = false;
            }
            else
            {
                gbxEventProperties.Enabled = true;
                gbxEventSources.Enabled = true;
            }
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
        /// The ButtonAddEventProperty_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAddEventProperty_Click(object sender, EventArgs args)
        {
            // Show the NewPropertyForm dialog.
            using (var newPropertyForm = new NewPropertyForm(lvEventProperties))
            {
                newPropertyForm.ShowDialog();
            }

            // Refresh the items in the list view.
            lvEventProperties.Refresh();
        }

        /// <summary>
        /// The ButtonRemoveEventProperty_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRemoveEventProperty_Click(object sender, EventArgs args)
        {
            if (lvEventProperties.SelectedItems.Count > 0)
                lvEventProperties.SelectedItems[0].Remove();
        }

        /// <summary>
        /// The ListViewEventSources_ItemCheck method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ListViewEventSources_ItemCheck(object sender, ItemCheckEventArgs args)
        {
            // If we have the lastItem set as checked, and it is different
            // item than the one that fired the event, uncheck it.
            if (LastItemChecked != null && LastItemChecked.Checked
                && LastItemChecked != lvEventSources.Items[args.Index])
            {
                // Uncheck the last item and store the new one.
                LastItemChecked.Checked = false;
            }

            // Store the current item.
            LastItemChecked = lvEventSources.Items[args.Index];
        }

        /// <summary>
        /// The ButtonAdd_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            // Create a new schedule trigger using the form info.
            var scheduleTrigger = new NewScheduleTrigger
            {
                DailyEndTime = dtpDailyEndTime.Value,
                DailyStartTime = dtpDailyStartTime.Value,
                EndDate = dtpEndDate.Value,
                StartDate = dtpStartDate.Value,
                Id = tbxId.Text,
                Framerate = (Clip.RecordingFramerates)cbxFramerate.SelectedIndex + 1,
                PreTrigger = (int)nudPreRecord.Value,
                PostTrigger = (int)nudPostRecord.Value,
                Timeout = (int)nudDuration.Value,
                RecurrenceType = (ScheduleTrigger.RecurrenceTypes)cbxRecurrenceType.SelectedIndex + 1
            };

            // Add the recurrence settings to the schedule trigger.
            AddRecurrenceDetails(scheduleTrigger);

            // If an event is selected add the event settings to the schedule trigger.
            if (cbxEvent.SelectedIndex != 0)
                AddEventDetails(scheduleTrigger);

            // Add the schedule trigger to the list view.
            var lvItem = new ListViewItem(string.Empty);
            lvItem.SubItems.Add(scheduleTrigger.Id);
            lvItem.SubItems.Add(scheduleTrigger.DailyStartTime.ToString("HH:mm:ss"));
            lvItem.SubItems.Add(scheduleTrigger.DailyEndTime.ToString("HH:mm:ss"));
            lvItem.SubItems.Add(scheduleTrigger.StartDate.ToString("d"));
            lvItem.SubItems.Add(scheduleTrigger.EndDate.ToString("d"));
            lvItem.SubItems.Add(scheduleTrigger.RecurrenceType.ToString());
            lvItem.SubItems.Add(scheduleTrigger.Event == 0 ? "None" : scheduleTrigger.Event.ToString());
            lvItem.SubItems.Add(scheduleTrigger.PreTrigger.ToString());
            lvItem.SubItems.Add(scheduleTrigger.PostTrigger.ToString());
            lvItem.SubItems.Add(scheduleTrigger.Timeout.ToString());
            lvItem.Tag = scheduleTrigger;
            ScheduleTriggerListView.Items.Add(lvItem);
        }

        /// <summary>
        /// The AddEventDetails method.
        /// </summary>
        /// <param name="scheduleTrigger">The new schedule trigger to add info to.</param>
        private void AddEventDetails(NewScheduleTrigger scheduleTrigger)
        {
            // Set the situation type based on the selection.
            scheduleTrigger.Event = cbxEvent.SelectedIndex == 1
                            ? ScheduleTrigger.SituationTypes.AlarmActive
                            : ScheduleTrigger.SituationTypes.Motion;

            // Set the event sources if they have been added.
            if (lvEventSources.CheckedItems.Count > 0)
            {
                var selectedDevice = (Device)lvEventSources.CheckedItems[0].Tag;
                scheduleTrigger.EventSource = selectedDevice.Id;
            }

            // Set the event properties if they have been added.
            var eventProperties = new List<KeyValuePair<string, string>>();
            foreach (ListViewItem item in lvEventProperties.Items)
                eventProperties.Add(new KeyValuePair<string, string>(item.SubItems[0].Text, item.SubItems[1].Text));

            scheduleTrigger.EventProperties = eventProperties;
        }

        /// <summary>
        /// The AddRecurrenceDetails method.
        /// </summary>
        /// <param name="scheduleTrigger">The new schedule trigger to add info to.</param>
        private void AddRecurrenceDetails(NewScheduleTrigger scheduleTrigger)
        {
            // If the weekly type is selected, add the selected days of the week to the schedule trigger.
            if (scheduleTrigger.RecurrenceType == ScheduleTrigger.RecurrenceTypes.Weekly)
            {
                var weeklyValues = (from ListViewItem item in lvWeekly.CheckedItems select item.Index + 1).ToList();
                scheduleTrigger.RecurWeekly = weeklyValues;
            }

            // If the monthly type is selected, add the selected days of the month to the schedule trigger.
            if (scheduleTrigger.RecurrenceType == ScheduleTrigger.RecurrenceTypes.Monthly)
            {
                var monthlyValues = (from ListViewItem item in lvMonthly.CheckedItems select item.Index + 1).ToList();
                scheduleTrigger.RecurMonthly = monthlyValues;
            }

            // If the yearly or monthly type is selected, add the selected months to the schedule trigger.
            if (scheduleTrigger.RecurrenceType != ScheduleTrigger.RecurrenceTypes.Monthly
                && scheduleTrigger.RecurrenceType != ScheduleTrigger.RecurrenceTypes.Yearly)
                return;

            var yearlyValues = (from ListViewItem item in lvYearly.CheckedItems select item.Index + 1).ToList();
            scheduleTrigger.RecurYearly = yearlyValues;
        }
    }
}
