using System;
using System.Collections.Generic;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddEventForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create a new
    /// event and push it to the VideoXpert system.</remarks>
    public partial class AddEventForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddEventForm" /> class.
        /// </summary>    
        public AddEventForm()
        {
            InitializeComponent();

            // Get the situations available on the VideoXpert system and use
            // them to pre-populate the type and device id drop downs.
            var situations = MainForm.CurrentSystem.GetSituations();
            foreach (var situation in situations)
            {
                if (!string.IsNullOrEmpty(situation.Type))
                    cbxSituationType.Items.Add(situation.Type);

                if (!string.IsNullOrEmpty(situation.SourceDeviceId))
                    cbxSourceDeviceId.Items.Add(situation.SourceDeviceId);
            }

            dtpTime.Value = DateTime.Now;
        }

        /// <summary>
        /// The ButtonAdd_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>     
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            var newEvent = new NewEvent 
            {
                GeneratorDeviceId = txbxGeneratorDeviceId.Text,
                SituationType = cbxSituationType.Text,
                SourceDeviceId = cbxSourceDeviceId.Text,
                Time = dtpTime.Value.ToUniversalTime()
            };

            // Check each property text box to see if there is a value.  If so, add it to the new event.
            var propertyList = new List<KeyValuePair<string, string>>();
            if (!string.IsNullOrEmpty(txbxName1.Text) && !string.IsNullOrEmpty(txbxValue1.Text))
                propertyList.Add(new KeyValuePair<string, string>(txbxName1.Text, txbxValue1.Text));

            if (!string.IsNullOrEmpty(txbxName2.Text) && !string.IsNullOrEmpty(txbxValue2.Text))
                propertyList.Add(new KeyValuePair<string, string>(txbxName2.Text, txbxValue2.Text));

            if (!string.IsNullOrEmpty(txbxName3.Text) && !string.IsNullOrEmpty(txbxValue3.Text))
                propertyList.Add(new KeyValuePair<string, string>(txbxName3.Text, txbxValue3.Text));

            newEvent.Properties = propertyList;

            MainForm.CurrentSystem.InjectEvent(newEvent);
        }
    }
}
