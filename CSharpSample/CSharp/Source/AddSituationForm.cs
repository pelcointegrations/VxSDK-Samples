using System;
using System.Collections.Generic;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddSituationForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to add a new
    /// situation to the VideoXpert system.</remarks>
    public partial class AddSituationForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddSituationForm" /> class.
        /// </summary>
        public AddSituationForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The ButtonAdd_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            var situation = new NewSituation
            {
                IsAckNeeded = this.ckbxAckNeeded.Checked,
                AudibleLoopDelay = (int)this.nudAudibleLoopDelay.Value,
                UseAudibleNotification = this.ckbxAudibleNotify.Checked,
                AudiblePlayCount = (int)this.nudAudiblePlayCount.Value,
                AutoAcknowledge = (int)this.nudAutoAcknowledge.Value,
                ShouldExpandBanner = this.ckbxExpandBanner.Checked,
                ShouldLog = this.ckbxLog.Checked,
                Name = this.txbxName.Text,
                ShouldNotify = this.ckbxNotify.Checked,
                Severity = (int)this.nudSeverity.Value,
                SourceDeviceId = this.txbxSourceDeviceId.Text,
                Type = this.txbxType.Text
            };

            var intervalList = new List<int>();
            if (this.nudSnoozeIntervals1.Value != 0)
            {
                intervalList.Add((int)this.nudSnoozeIntervals1.Value);
            }

            if (this.nudSnoozeIntervals2.Value != 0)
            {
                intervalList.Add((int)this.nudSnoozeIntervals2.Value);
            }

            if (this.nudSnoozeIntervals3.Value != 0)
            {
                intervalList.Add((int)this.nudSnoozeIntervals3.Value);
            }

            situation.SnoozeIntervals = intervalList;

            MainForm.CurrentSystem.AddSituation(situation);
        }
    }
}
