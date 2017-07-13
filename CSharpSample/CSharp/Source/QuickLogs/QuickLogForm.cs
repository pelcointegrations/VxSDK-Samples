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
    /// The QuickLogForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create quick system logs.</remarks>
    public partial class QuickLogForm : Form
    {
        /// <summary>
        /// Gets or sets a value indicating whether the log generation is being cancelled.
        /// </summary>
        /// <value>True when cancelling the log creation, otherwise false.</value>
        private bool Cancelling { get; set; }

        /// <summary>
        /// Gets or sets the Client property.
        /// </summary>
        /// <value>The download client.</value>
        private WebClient Client { get; set; }

        /// <summary>
        /// Gets or sets the Log property.
        /// </summary>
        /// <value>The current quick log.</value>
        private QuickLog Log { get; set; }

        /// <summary>
        /// Gets or sets the LogPath property.
        /// </summary>
        /// <value>The path to save the quick log to.</value>
        private string LogPath { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="QuickLogForm" /> class.
        /// </summary>
        public QuickLogForm()
        {
            InitializeComponent();
            lblCurrentStatus.Text = @"Idle";
        }

        /// <summary>
        /// Updates the status of the log creation in a new thread.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        public void BackgroundWorker_DoWork(object sender, DoWorkEventArgs args)
        {
            while (Log.Status == QuickLog.LogCreationStatus.InProgress && !Cancelling)
            {
                Thread.Sleep(2000);
            }

            Invoke((MethodInvoker)delegate
            {
                lblCurrentStatus.Text = Cancelling ? @"Cancelled" : Log.Status.ToString();
                btnActions.Text = Log.Status == QuickLog.LogCreationStatus.Successful ? "Download" : "Close";
            });
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
                case @"Export Logs":
                    Log = MainForm.CurrentSystem.CreateQuickLog();
                    if (Log == null)
                    {
                        lblCurrentStatus.Text = "Unable to create quick log.\n (Not supported)";
                        btnActions.Text = @"Close";
                        break;
                    }

                    lblCurrentStatus.Text = @"Creating Logs";
                    btnActions.Text = @"Cancel";
                    bgWorker.RunWorkerAsync();
                    break;
                case @"Download":
                    StartDownload();
                    break;
                case @"Cancel":
                    if (lblCurrentStatus.Text.StartsWith(@"Downloading"))
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
        /// The SelectPath method.
        /// </summary>
        /// <returns>The selected path.</returns>
        private static string SelectPath()
        {
            using (var folderDialog = new FolderBrowserDialog())
            {
                folderDialog.SelectedPath = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
                folderDialog.Description = @"Choose Quick Log Save Path...";

                var time = DateTime.UtcNow.ToString("MM-dd-yyyy_HH_mm_ss");
                var result = folderDialog.ShowDialog();
                if (result != DialogResult.OK)
                    return string.Empty;

                return folderDialog.SelectedPath + "\\QuickLog-" + time + ".zip";
            }
        }

        /// <summary>
        /// The StartDownload method.
        /// </summary>
        private void StartDownload()
        {
            LogPath = SelectPath();
            if (string.IsNullOrEmpty(LogPath))
                return;

            lblCurrentStatus.Text = @"Downloading";
            btnActions.Text = @"Cancel";

            // Create a new WebClient instance.
            Client = new WebClient();

            // Forces the WebClient to trust the security certificate handed back from the VideoXpert server.
            ServicePointManager.ServerCertificateValidationCallback = delegate { return true; };

            // Supply the username and password that was used to create the VideoXpert system.
            Client.Headers.Add("X-Serenity-User", Utilities.EncodeToBase64(MainForm.CurrentUserName));
            Client.Headers.Add("X-Serenity-Password", Utilities.EncodeToBase64(MainForm.CurrentPassword));

            // Subscribe to the download events.
            Client.DownloadProgressChanged += WebClientDownloadProgressChanged;
            Client.DownloadFileCompleted += WebClientDownloadFileCompleted;
            Client.DownloadFileAsync(new Uri(Log.QuickLogEndpoint), LogPath);
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
                if (File.Exists(LogPath))
                    File.Delete(LogPath);
            }
            else if (args.Error != null)
            {
                lblCurrentStatus.Text = string.Format("Error: {0}", args.Error.Message);
                if (File.Exists(LogPath))
                    File.Delete(LogPath);
            }
            else
                lblCurrentStatus.Text = @"Download complete";

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
            lblCurrentStatus.Text = @"Downloading " + Utilities.FormatFileSize(args.BytesReceived);
        }
    }
}
