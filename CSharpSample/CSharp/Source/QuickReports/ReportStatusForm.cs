using System;
using System.ComponentModel;
using System.IO;
using System.Net;
using System.Threading;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ReportStatusForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to monitor the status of a quick report.</remarks>
    public partial class ReportStatusForm : Form
    {
        /// <summary>
        /// Gets or sets a value indicating whether the report generation is being cancelled.
        /// </summary>
        /// <value>True when cancelling the report creation, otherwise false.</value>
        private bool Cancelling { get; set; }

        /// <summary>
        /// Gets or sets the Client property.
        /// </summary>
        /// <value>The download client.</value>
        private WebClient Client { get; set; }

        /// <summary>
        /// Gets or sets the Report property.
        /// </summary>
        /// <value>The current quick report.</value>
        private QuickReport Report { get; set; }

        /// <summary>
        /// Gets or sets the ReportPath property.
        /// </summary>
        /// <value>The path to save the quick report to.</value>
        private string ReportPath { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ReportStatusForm" /> class.
        /// </summary>
        /// <param name="quickReport">The quick report to monitor the status of.</param>
        public ReportStatusForm(QuickReport quickReport)
        {
            InitializeComponent();
            Report = quickReport;
            lblCurrentStatus.Text = @"In Progress";
            bgWorker.RunWorkerAsync();
        }

        /// <summary>
        /// Updates the status of the report creation in a new thread.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        public void BackgroundWorker_DoWork(object sender, DoWorkEventArgs args)
        {
            while (Report.Status == QuickReport.ReportCreationStatus.InProgress && !Cancelling)
            {
                Thread.Sleep(2000);
            }

            Invoke((MethodInvoker)delegate
            {
                lblCurrentStatus.Text = Cancelling ? @"Cancelled" : Report.Status.ToString();
                btnActions.Text = Report.Status == QuickReport.ReportCreationStatus.Successful ? "Download" : "Close";
            });
        }

        /// <summary>
        /// The EncodeToBase64 method.
        /// </summary>
        /// <param name="toEncode">The string to encode to Base64.</param>
        /// <returns>The Base64 encoded string.</returns>
        private static string EncodeToBase64(string toEncode)
        {
            var toEncodeAsBytes = System.Text.Encoding.ASCII.GetBytes(toEncode);
            var returnValue = Convert.ToBase64String(toEncodeAsBytes);
            return returnValue;
        }

        /// <summary>
        /// The SelectPath method.
        /// </summary>
        /// <returns>The selected path.</returns>
        private static string SelectPath()
        {
            using (var folderDialog = new FolderBrowserDialog())
            {
                folderDialog.SelectedPath = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
                folderDialog.Description = @"Choose Quick Report Save Path...";

                var time = DateTime.UtcNow.ToString("MM-dd-yyyy_HH_mm_ss");
                var result = folderDialog.ShowDialog();
                if (result != DialogResult.OK)
                    return string.Empty;

                return folderDialog.SelectedPath + "\\QuickReport-" + time + ".zip";
            }
        }

        /// <summary>
        /// The ButtonActions_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonActions_Click(object sender, EventArgs args)
        {
            switch (btnActions.Text)
            {
                case @"Download":
                    StartDownload();
                    break;
                case @"Cancel":
                    if (lblCurrentStatus.Text == @"Downloading")
                        CancelDownload();
                    else
                        Cancelling = true;
                    break;
                default:
                    Close();
                    break;
            }
        }

        /// <summary>
        /// The CancelDownload method.
        /// </summary>
        private void CancelDownload()
        {
            if (Client != null)
                Client.CancelAsync();
        }

        /// <summary>
        /// The StartDownload method.
        /// </summary>
        private void StartDownload()
        {
            ReportPath = SelectPath();
            if (string.IsNullOrEmpty(ReportPath))
                return;

            lblCurrentStatus.Text = @"Downloading";
            btnActions.Text = @"Cancel";
            progressBar.Visible = true;

            // Create a new WebClient instance.
            Client = new WebClient();

            // Forces the WebClient to trust the security certificate handed back from the VideoXpert server.
            ServicePointManager.ServerCertificateValidationCallback = delegate { return true; };

            // Supply the username and password that was used to create the VideoXpert system.
            Client.Headers.Add("X-Serenity-User", EncodeToBase64(MainForm.CurrentUserName));
            Client.Headers.Add("X-Serenity-Password", EncodeToBase64(MainForm.CurrentPassword));

            // Subscribe to the download events.
            Client.DownloadProgressChanged += WebClientDownloadProgressChanged;
            Client.DownloadFileCompleted += WebClientDownloadFileCompleted;
            Client.DownloadFileAsync(new Uri(Report.QuickReportEndpoint), ReportPath);
        }

        /// <summary>
        /// The WebClientDownloadFileCompleted method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        /// <remarks>Checks to see if the download completed event was due to an error or cancellation.</remarks>
        private void WebClientDownloadFileCompleted(object sender, AsyncCompletedEventArgs args)
        {
            if (args.Cancelled)
            {
                lblCurrentStatus.Text = @"Cancelled";
                if (File.Exists(ReportPath))
                    File.Delete(ReportPath);
            }
            else if (args.Error != null)
            {
                lblCurrentStatus.Text = string.Format("Error: {0}", args.Error.Message);
                if (File.Exists(ReportPath))
                    File.Delete(ReportPath);
            }
            else
            {
                progressBar.Value = progressBar.Maximum;
                lblCurrentStatus.Text = @"Download complete";
            }

            Client.DownloadProgressChanged -= WebClientDownloadProgressChanged;
            Client.DownloadFileCompleted -= WebClientDownloadFileCompleted;
            Client.Dispose();
            btnActions.Text = @"Close";
        }

        /// <summary>
        /// The WebClientDownloadProgressChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void WebClientDownloadProgressChanged(object sender, DownloadProgressChangedEventArgs args)
        {
            if ((int)args.TotalBytesToReceive == -1)
                return;

            // Update the progress bar value.
            progressBar.Maximum = (int)args.TotalBytesToReceive;
            progressBar.Value = (int)args.BytesReceived;
        }
    }
}
