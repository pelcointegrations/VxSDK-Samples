using System;
using System.Collections.Generic;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ScheduleDetailsForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that contains the detailed info for the selected schedule.</remarks>
    public partial class ScheduleDetailsForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="ScheduleDetailsForm" /> class.
        /// </summary>
        public ScheduleDetailsForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The GetScheduleInfo method.
        /// </summary>
        /// <param name="schedule">The <paramref name="schedule"/> to get information for.</param>
        public void GetScheduleInfo(Schedule schedule)
        {
            if (schedule == null) return;

            AddPropertyInfo(schedule);

            var triggerNum = 0;
            foreach (var trigger in schedule.ScheduleTriggers)
            {
                triggerNum++;
                var lvTriggerItem = new ListViewItem("Schedule Trigger #" + triggerNum);
                lvTriggerItem.SubItems.Add("------------------------");
                lvScheduleDetails.Items.Add(lvTriggerItem);
                AddScheduleTriggerInfo(trigger);
            }
        }

        /// <summary>
        /// The AddPropertyInfo method.
        /// </summary>
        /// <param name="schedule">The <paramref name="schedule"/> to add the properties for.</param>
        private void AddPropertyInfo(Schedule schedule)
        {
            // Use reflection to get each available property from the schedule.
            foreach (var prop in schedule.GetType().GetProperties())
            {
                // Get the value from the property.
                var val = prop.GetValue(schedule, null);

                // Get each item if the value is a List type and generate a string.
                if (val.GetType() == typeof(List<ScheduleTrigger>))
                    continue;

                var valList = val.ToString();

                // Add the property name and value to the list view.
                var lvItem = new ListViewItem(prop.Name);
                lvItem.SubItems.Add(valList);
                lvScheduleDetails.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The AddScheduleTriggerInfo method.
        /// </summary>
        /// <param name="trigger">The <paramref name="trigger"/> to add the info for.</param>
        private void AddScheduleTriggerInfo(ScheduleTrigger trigger)
        {
            // Use reflection to get each available property from the schedule.
            foreach (var prop in trigger.GetType().GetProperties())
            {
                // Get the value from the property.
                var val = prop.GetValue(trigger, null);

                // Get each item if the value is a List type and generate a string.
                string valList;
                if (val.GetType() == typeof(List<string>))
                    valList = string.Join(", ", (List<string>)val);
                else if (val.GetType() == typeof(List<int>))
                    valList = string.Join(", ", (List<int>)val);
                else if (val is DateTime)
                {
                    var dt = (DateTime)val;
                    valList = dt.ToString(prop.Name.Contains("Time") ? "HH:mm:ss" : "d");
                }
                else if (val.GetType() == typeof(List<KeyValuePair<string, string>>))
                    valList = string.Join(", ", (List<KeyValuePair<string, string>>)val);
                else
                    valList = val.ToString();

                // Add the property name and value to the list view.
                var lvItem = new ListViewItem(prop.Name);
                lvItem.SubItems.Add(valList);
                lvScheduleDetails.Items.Add(lvItem);
            }
        }
    }
}
