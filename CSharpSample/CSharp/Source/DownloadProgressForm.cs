using System;
using System.ComponentModel;
using System.Net;
using System.Windows.Forms;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The DownloadProgressForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that displays the current progress of a
    /// newly created export.</remarks>
    public partial class DownloadProgressForm : Form
    {
        /// <summary>
        /// The _fileSize field.
        /// </summary>
        /// <remarks>Used to calculate the download completion percentage of the export.</remarks>
        private double _fileSize;

        /// <summary>
        /// The _webClient field.
        /// </summary>
        /// <remarks>Used to download the export file once it has completed.</remarks>
        private WebClient _webClient;

        /// <summary>
        /// Initializes a new instance of the <see cref="DownloadProgressForm" /> class.
        /// </summary>
        public DownloadProgressForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The WebClientDownloadProgressChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        public void WebClientDownloadProgressChanged(object sender, DownloadProgressChangedEventArgs args)
        {
            // Calculate the download percentage and update the progress bar value.
            var percentComplete = (args.BytesReceived / _fileSize) * 100;
            progressBar.Value = (int)percentComplete;
            if (!(percentComplete >= 100))
                return;

            // Notify the user of completion and unsubscribe from the notification events.
            lblDownloading.Text = @"Download complete.";
            _webClient.DownloadProgressChanged -= WebClientDownloadProgressChanged;
            _webClient.DownloadFileCompleted -= WebClientDownloadFileCompleted;
            _webClient.Dispose();
            btnCancel.Text = @"Close";
        }

        /// <summary>
        /// The WebClientDownloadFileCompleted method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        /// <remarks>Checks to see if the download completed event was due to an error or cancellation.</remarks>
        public void WebClientDownloadFileCompleted(object sender, AsyncCompletedEventArgs args)
        {
            if (args == null)
                return;

            if (args.Error == null)
                return;

            // Notify the user that the download has either been cancelled or had an error.
            lblDownloading.Text = args.Cancelled ? 
                "Download cancelled." : string.Format("Error: {0}", args.Error.Message);

            btnCancel.Text = @"Close";
            if (_webClient != null)
            {
                _webClient.DownloadProgressChanged -= WebClientDownloadProgressChanged;
                _webClient.DownloadFileCompleted -= WebClientDownloadFileCompleted;
                _webClient.Dispose();
            }
        }

        /// <summary>
        /// The StartDownload method.
        /// </summary>
        /// <param name="dataUri">The <c>Uri</c> of the export file to download.</param>
        /// <param name="fileName">The name to use for the downloaded export file.</param>
        /// <param name="fileSize">The size of the file to be downloaded.</param>
        public void StartDownload(Uri dataUri, string fileName, int fileSize)
        {
            lblDownloading.Text = string.Format("Downloading file to {0}", fileName);
            _fileSize = fileSize * 1024;

            // Create a new WebClient instance.
            _webClient = new WebClient();

            // Forces the WebClient to trust the security certificate handed back from the VideoXpert server.
            ServicePointManager.ServerCertificateValidationCallback = delegate { return true; };

            // Supply the username and password that was used to create the VideoXpert system.
            _webClient.Headers.Add("X-Serenity-User", EncodeToBase64(MainForm.CurrentUserName));
            _webClient.Headers.Add("X-Serenity-Password", EncodeToBase64(MainForm.CurrentPassword));

            // Subscribe to the download events.
            _webClient.DownloadProgressChanged += WebClientDownloadProgressChanged;
            _webClient.DownloadFileCompleted += WebClientDownloadFileCompleted;
            _webClient.DownloadFileAsync(dataUri, fileName);
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
        /// The ButtonCancel_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>   
        private void ButtonCancel_Click(object sender, EventArgs args)
        {
            if (_webClient != null)
            {
                _webClient.CancelAsync();
                return;
            }

            Close();
        }
    }
}
