using System;
using System.ComponentModel;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CPPCli;
using SDKSampleApp.Enums;
using SDKSampleApp.Properties;

namespace SDKSampleApp.Source
{
    public static class Utilities
    {
        /// <summary>
        /// The AddRowToGridView method.
        /// </summary>
        /// <param name="item">The item to add to the list.</param>
        private static int AddRowToGridView(object[] item)
        {
            var rowIndex = 0;
            if (MainForm.Instance.dgvDataSources.InvokeRequired)
            {
                MainForm.Instance.dgvDataSources.Invoke(
                    new MethodInvoker(delegate { rowIndex = MainForm.Instance.dgvDataSources.Rows.Add(item); }));
            }
            else
                rowIndex = MainForm.Instance.dgvDataSources.Rows.Add(item);

            return rowIndex;
        }

        /// <summary>
        /// The BackgroundWorker_DoWork method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        public static void BackgroundWorker_DoWork(object sender, DoWorkEventArgs args)
        {
            MainForm.Instance.dgvDataSources.Invoke(new MethodInvoker(delegate { MainForm.Instance.dgvDataSources.Rows.Clear(); }));

            if (MainForm.CurrentDevices != null)
                MainForm.CurrentDevices.Clear();
            MainForm.CurrentDevices = MainForm.CurrentSystem.GetDevices();

            if (MainForm.CurrentDataSources != null)
                MainForm.CurrentDataSources.Clear();

            ChangeProgressViewState(true);
            MainForm.CurrentDataSources = MainForm.CurrentSystem.GetDataSources();

            var dataSourceTotal = MainForm.CurrentDataSources.Count;
            var dataSourceNum = 0;
            foreach (var dataSource in MainForm.CurrentDataSources)
            {
                dataSourceNum++;
                if (dataSource.Type != DataSource.Types.Video)
                    continue;

                var progress = ((decimal)dataSourceNum / dataSourceTotal) * 100;
                MainForm.Instance.bgWorker.ReportProgress((int)progress, null);
                Bitmap camIcon;
                if (dataSource.DataInterfaces.Any(item => (int) item.RenderType > 0 && (int) item.RenderType <= 4))
                {
                    camIcon = dataSource.State == DataSource.States.Offline ? Resources.cam_pano_offline : Resources.cam_pano;
                }
                else
                {
                    if (dataSource.IsPTZ)
                        camIcon = dataSource.State == DataSource.States.Offline ? Resources.cam_ptz_offline : Resources.cam_ptz;
                    else
                        camIcon = dataSource.State == DataSource.States.Offline ? Resources.cam_fixed_offline : Resources.cam_fixed;
                }

                object[] row = { camIcon, dataSource.Name, dataSource.Number.ToString() };
                var index = AddRowToGridView(row);
                var newRow = MainForm.Instance.dgvDataSources.Rows[index];
                newRow.Tag = dataSource;
            }

            MainForm.Instance.BeginInvoke((MethodInvoker)delegate
            {
                // If data source collection was successful enable the UI elements.
                MainForm.Instance.eventsToolStripMenuItem.Enabled = true;
                MainForm.Instance.manageToolStripMenuItem.Enabled = true;
                MainForm.Instance.btnSeek.Enabled = true;
                MainForm.Instance.btnPause.Enabled = true;
                MainForm.Instance.btnPlay.Enabled = true;
                MainForm.Instance.btnStop.Enabled = true;
                MainForm.Instance.btnSnapshot.Enabled = true;
                MainForm.Instance.btnRefreshDataSources.Enabled = true;
            });
        }

        /// <summary>
        /// The BackgroundWorker_ProgressChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        public static void BackgroundWorker_ProgressChanged(object sender, ProgressChangedEventArgs args)
        {
            MainForm.Instance.pbLoadCameras.Invoke(
                new MethodInvoker(delegate { MainForm.Instance.pbLoadCameras.Value = args.ProgressPercentage; }));
        }

        /// <summary>
        /// The BackgroundWorker_RunWorkerCompleted method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        public static void BackgroundWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs args)
        {
            ChangeProgressViewState(false);
        }

        /// <summary>
        /// The ChangeProgressViewState method.
        /// </summary>
        /// <param name="isVisible">The value to set the visible property to.</param>
        private static void ChangeProgressViewState(bool isVisible)
        {
            if (MainForm.Instance.pbLoadCameras.InvokeRequired)
            {
                MainForm.Instance.pbLoadCameras.Invoke(
                    new MethodInvoker(delegate { MainForm.Instance.pbLoadCameras.Visible = isVisible; }));
            }
            else
                MainForm.Instance.pbLoadCameras.Visible = isVisible;

            if (MainForm.Instance.lblAddingCameras.InvokeRequired)
            {
                MainForm.Instance.lblAddingCameras.Invoke(
                    new MethodInvoker(delegate { MainForm.Instance.lblAddingCameras.Visible = isVisible; }));
            }
            else
                MainForm.Instance.lblAddingCameras.Visible = isVisible;

            if (MainForm.Instance.btnRefreshDataSources.InvokeRequired)
            {
                MainForm.Instance.btnRefreshDataSources.Invoke(
                    new MethodInvoker(delegate { MainForm.Instance.btnRefreshDataSources.Visible = !isVisible; }));
            }
            else
                MainForm.Instance.btnRefreshDataSources.Visible = !isVisible;
        }

        /// <summary>
        /// The EncodeToBase64 method.
        /// </summary>
        /// <param name="toEncode">The string to encode to Base64.</param>
        /// <returns>The Base64 encoded string.</returns>
        public static string EncodeToBase64(string toEncode)
        {
            var toEncodeAsBytes = Encoding.ASCII.GetBytes(toEncode);
            var returnValue = Convert.ToBase64String(toEncodeAsBytes);
            return returnValue;
        }

        /// <summary>
        /// The FormatFileSize method.
        /// </summary>
        /// <param name="byteValue">The size of the file in bytes.</param>
        /// <param name="decimalPlaces">The amount of decimal places to use.</param>
        /// <returns>The file size formatted as a readable string.</returns>
        public static string FormatFileSize(long byteValue, int decimalPlaces = 1)
        {
            string[] sizeSuffixes = { "bytes", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB" };
            if (byteValue < 0) { return "-" + FormatFileSize(-byteValue); }
            if (byteValue == 0) { return "0.0 bytes"; }


            var mag = (int)Math.Log(byteValue, 1024);
            var adjustedSize = (decimal)byteValue / (1L << (mag * 10));
            if (Math.Round(adjustedSize, decimalPlaces) < 1000)
                return string.Format("{0:n" + decimalPlaces + "} {1}", adjustedSize, sizeSuffixes[mag]);

            mag += 1;
            adjustedSize /= 1024;
            return string.Format("{0:n" + decimalPlaces + "} {1}", adjustedSize, sizeSuffixes[mag]);
        }

        /// <summary>
        /// The RotateImage method.
        /// </summary>
        /// <param name="image">The image to be rotated.</param>
        /// <param name="rotationAngle">The angle (in degrees).</param>
        /// <returns>The rotated image.</returns>
        public static Image RotateImage(Image image, float rotationAngle)
        {
            if (image == null)
                return null;

            // Create an empty image.
            var bitmap = new Bitmap(image.Width, image.Height);
            bitmap.SetResolution(image.HorizontalResolution, image.VerticalResolution);

            // Turn the bitmap into a graphics object.
            var graphics = Graphics.FromImage(bitmap);

            // Set the rotation point to the center of the image.
            graphics.TranslateTransform((float)bitmap.Width / 2, (float)bitmap.Height / 2);

            // Rotate the image.
            graphics.RotateTransform(rotationAngle);
            graphics.TranslateTransform(-(float)bitmap.Width / 2, -(float)bitmap.Height / 2);

            // Set the InterpolationMode to HighQualityBicubic to ensure a high
            // quality image once it is transformed to the specified size.
            graphics.InterpolationMode = InterpolationMode.HighQualityBicubic;

            // Draw the new image onto the graphics object.
            graphics.DrawImage(image, new Point(0, 0));

            // Dispose of the graphics object.
            graphics.Dispose();

            // Return the image.
            return bitmap;
        }

        /// <summary>
        /// The SendRequest method.
        /// </summary>
        /// <param name="uri">The request <c>Uri</c>.</param>
        /// <returns>The response message.</returns>
        public static async Task<HttpResponseMessage> SendRequest(Uri uri)
        {
            // Create a new WebClient instance.
            var client = new HttpClient();

            // Supply the username and password that was used to create the VideoXpert system.
            var request = new HttpRequestMessage(HttpMethod.Get, uri);
            request.Headers.Add("X-Serenity-User", EncodeToBase64(MainForm.CurrentUserName));
            request.Headers.Add("X-Serenity-Password", EncodeToBase64(MainForm.CurrentPassword));

            // Forces the WebClient to trust the security certificate handed back from the VideoXpert server.
            ServicePointManager.ServerCertificateValidationCallback = delegate { return true; };

            var response = await client.SendAsync(request);
            return response;
        }
    }
}
