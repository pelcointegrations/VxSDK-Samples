using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The QuickReportForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create quick system reports.</remarks>
    public partial class QuickReportForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="QuickReportForm" /> class.
        /// </summary>
        public QuickReportForm()
        {
            InitializeComponent();
            dtpStartDate.Value = DateTime.Now.AddHours(-1);
        }

        /// <summary>
        /// The ButtonExportReports_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonExportReports_Click(object sender, EventArgs args)
        {
            var newQuickReport = new NewQuickReport();
            if (ckbxCameraConfig.Checked)
                newQuickReport.Contents.Add(NewQuickReport.ReportContent.CameraConfig);
            if (ckbxSystemDevice.Checked)
                newQuickReport.Contents.Add(NewQuickReport.ReportContent.DeviceInfo);
            if (ckbxEventHistory.Checked)
                newQuickReport.Contents.Add(NewQuickReport.ReportContent.EventHistory);
            if (ckbxOnlineOffline.Checked)
                newQuickReport.Contents.Add(NewQuickReport.ReportContent.OnlineOffline);
            if (ckbxRecorderAssignment.Checked)
                newQuickReport.Contents.Add(NewQuickReport.ReportContent.RecorderConfig);
            if (ckbxRecorderDiag.Checked)
                newQuickReport.Contents.Add(NewQuickReport.ReportContent.RecorderDiagnostics);
            if (ckbxUserActions.Checked)
                newQuickReport.Contents.Add(NewQuickReport.ReportContent.UserActions);
            if (ckbxVxClusterConfig.Checked)
                newQuickReport.Contents.Add(NewQuickReport.ReportContent.VxClusterConfig);

            if (gbxReportStartTime.Enabled)
            {
                newQuickReport.StartTime = dtpStartDate.Value;
                newQuickReport.EndTime = dtpEndDate.Value;
            }

            var quickReport = MainForm.CurrentSystem.CreateQuickReport(newQuickReport);
            if (quickReport == null)
            {
                MessageBox.Show("Unable to create quick report.\n (Not supported)");
                Close();
                return;
            }

            using (var reportStatusForm = new ReportStatusForm(quickReport))
            {
                reportStatusForm.ShowDialog();
            }
        }

        /// <summary>
        /// The CheckBoxTimeNeeded_CheckedChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void CheckBoxTimeNeeded_CheckedChanged(object sender, EventArgs args)
        {
            if (ckbxOnlineOffline.Checked || ckbxUserActions.Checked || ckbxEventHistory.Checked)
            {
                gbxReportStartTime.Enabled = true;
                gbxReportEndTime.Enabled = true;
            }
            else
            {
                gbxReportStartTime.Enabled = false;
                gbxReportEndTime.Enabled = false;
            }
        }
    }
}
