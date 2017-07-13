using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ModifyRelayOutputForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to modify a relay output.</remarks>
    public partial class ModifyRelayOutputForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedRelayOutput property.
        /// </summary>
        /// <value>The currently selected relay output.</value>
        private RelayOutput SelectedRelayOutput { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyRelayOutputForm" /> class.
        /// </summary>
        /// <param name="relayOutput">The <paramref name="relayOutput"/> parameter.</param>
        public ModifyRelayOutputForm(RelayOutput relayOutput)
        {
            InitializeComponent();
            SelectedRelayOutput = relayOutput;
            tbxName.Text = relayOutput.Name;
            tbxDescription.Text = relayOutput.Description;
        }

        /// <summary>
        /// The ButtonSave_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSave_Click(object sender, EventArgs args)
        {
            if (!string.IsNullOrEmpty(tbxName.Text) && SelectedRelayOutput.Name != tbxName.Text)
                SelectedRelayOutput.Name = tbxName.Text;

            if (!string.IsNullOrEmpty(tbxDescription.Text) && SelectedRelayOutput.Description != tbxDescription.Text)
                SelectedRelayOutput.Description = tbxDescription.Text;
        }
    }
}
