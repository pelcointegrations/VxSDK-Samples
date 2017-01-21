using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The EventDisplayForm class.
    /// </summary>
    /// <remarks>Provides a window that displays event info.</remarks>
    public partial class EventDisplayForm : Form
    {
        /// <summary>
        /// Gets or sets the CurrentEvent property.
        /// </summary>
        /// <value>The event to display in this form.</value>
        private Event CurrentEvent { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="EventDisplayForm" /> class.
        /// </summary>
        /// <param name="receivedEvent">The event to display.</param>
        public EventDisplayForm(Event receivedEvent)
        {
            InitializeComponent();

            CurrentEvent = receivedEvent;
            PopulateEventInfo();
        }

        /// <summary>
        /// The FormatText method.
        /// </summary>
        /// <param name="text">The text to format.</param>
        /// <returns>The formatted string.</returns>
        public static string FormatText(string text)
        {
            if (text == null)
                return string.Empty;

            var nameSplit = text.Split('_');
            var builder = new StringBuilder();
            foreach (var value in nameSplit)
            {
                builder.Append(char.ToUpper(value[0], CultureInfo.InvariantCulture) + value.Substring(1));
                builder.Append(' ');
            }

            return builder.ToString();
        }

        /// <summary>
        /// The FormatType method.
        /// </summary>
        /// <param name="typeArray">The string array containing the situation type.</param>
        /// <returns>The formatted string.</returns>
        public static string FormatType(IEnumerable<string> typeArray)
        {
            var builder = new StringBuilder();
            if (typeArray == null) 
                return builder.ToString();

            foreach (var value in typeArray)
            {
                builder.Append(char.ToUpper(value[0], CultureInfo.InvariantCulture) + value.Substring(1));
                builder.Append(' ');
            }

            return builder.ToString();
        }

        /// <summary>
        /// The PopulateEventInfo method.
        /// </summary>
        private void PopulateEventInfo()
        {
            var situationType = CurrentEvent.SituationType.Split('/');
            lblEventName.Text = FormatText(situationType.Last());
            lblEventTypeValue.Text = FormatType(situationType.Take(situationType.Length - 1).ToArray());
            lblStatusValue.Text = FormatText(CurrentEvent.AckState.ToString());
            lblDateValue.Text = CurrentEvent.Time.ToString("MMMM dd, yyyy");
            lblTimeValue.Text = CurrentEvent.Time.ToString("h:mm:ss tt");
            lblSeverityValue.Text = Math.Abs(CurrentEvent.Severity - 11).ToString();
            lblUserValue.Text = CurrentEvent.SourceUserName;
            lblGeneratorValue.Text = CurrentEvent.GeneratorDeviceId;
            lblSourceValue.Text = CurrentEvent.SourceDeviceId;

            foreach (var device in MainForm.CurrentDevices.Where(device => device.Id == CurrentEvent.GeneratorDeviceId))
                lblGeneratorValue.Text = device.Name;

            foreach (var device in MainForm.CurrentDevices.Where(device => device.Id == CurrentEvent.SourceDeviceId))
                lblSourceValue.Text = device.Name;

            if (CurrentEvent.AckState == Event.AckStates.AckNeeded)
                return;

            btnAck.Enabled = false;
            btnSilence.Enabled = false;
        }

        /// <summary>
        /// The ButtonAck_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonAck_Click(object sender, EventArgs args)
        {
            CurrentEvent.Acknowledge();
            Close();
        }

        /// <summary>
        /// The ButtonOk_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonOk_Click(object sender, EventArgs args)
        {
            Close();
        }

        /// <summary>
        /// The ButtonSilence_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSilence_Click(object sender, EventArgs args)
        {
            decimal value = 0;
            if (InputBox.Show("Silence", "Wake Time:", ref value) != DialogResult.OK)
                return;

            CurrentEvent.Silence((int)value);
            Close();
        }
    }
}
