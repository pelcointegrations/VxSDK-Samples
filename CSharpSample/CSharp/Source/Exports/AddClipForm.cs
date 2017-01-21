using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Net;
using System.Net.Http;
using System.Threading.Tasks;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddClipForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create a new
    /// clip entry in the <see cref="NewExportForm"/> AvailableClips list view.</remarks>
    public partial class AddClipForm : Form
    {
        /// <summary>
        /// The _initialStartSet field.
        /// </summary>  
        /// <remarks>Used to determine if the clip snapshots should be refreshed.</remarks>
        private bool _initialStartSet;

        /// <summary>
        /// The _initialEndSet field.
        /// </summary>  
        /// <remarks>Used to determine if the clip snapshots should be refreshed.</remarks>
        private bool _initialEndSet;

        /// <summary>
        /// Gets the SelectedClip property.
        /// </summary>
        /// <value>The Clip contained in the Tag property of the selected clip
        /// in the <see cref="NewExportForm"/> AvailableClips list view.</value>
        private static Clip SelectedClip
        {
            get
            {
                if (NewExportForm.Instance.lvAvailableClips.SelectedItems.Count != 0)
                    return (Clip)NewExportForm.Instance.lvAvailableClips.SelectedItems[0].Tag;

                return null;
            }
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AddClipForm" /> class.
        /// </summary>    
        public AddClipForm()
        {
            InitializeComponent();

            if (SelectedClip == null) 
                return;

            // Get the start and end time of the selected clip.
            var startTime = SelectedClip.StartTime.ToLocalTime();
            var endTime = SelectedClip.EndTime.ToLocalTime();

            // Set up the DateTimePickers to only allow values within the selected 
            // clips time frame.
            dtpStartDate.MinDate = startTime;
            dtpStartDate.MaxDate = endTime;
            dtpStartDate.Value = startTime;

            dtpEndDate.MinDate = startTime;
            dtpEndDate.MaxDate = endTime;
            dtpEndDate.Value = endTime;

            RefreshClipImages();
        }

        /// <summary>
        /// The GetMultiPartImages method.
        /// </summary>
        /// <param name="snapshotFilter">The <paramref name="snapshotFilter"/> parameter.</param>
        /// <returns>A list of image data.</returns>
        private static async Task<List<ImageByteArray>> GetMultiPartImages(SnapshotFilter snapshotFilter)
        {
            var listBytes = new List<ImageByteArray>();
            var uri = new Uri(SelectedClip.GetSnapshotEndpoint(snapshotFilter));
            var response = await MainForm.Instance.SendRequest(uri);
            if (response.StatusCode != HttpStatusCode.OK)
                return null;

            var multipartContent = await response.Content.ReadAsMultipartAsync();
            foreach (var content in multipartContent.Contents)
            {
                var bytes = await content.ReadAsByteArrayAsync();
                if (bytes == null)
                    continue;

                listBytes.Add(new ImageByteArray(bytes, content.Headers));
            }

            listBytes.Sort((a, b) => a.ImageTime.CompareTo(b.ImageTime));
            return listBytes;
        }

        /// <summary>
        /// The ButtonAdd_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter</param>
        /// <param name="args">The <paramref name="args"/> parameter</param>
        /// <remarks>Uses the settings to add a new entry to the 
        /// <see cref="NewExportForm"/> AvailableClips list view.</remarks>
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            var newExportClip = new NewExportClip
            {
                DataSourceId = SelectedClip.DataSourceId,
                StartTime = dtpStartDate.Value.ToUniversalTime(),
                EndTime = dtpEndDate.Value.ToUniversalTime()
            };

            var lvItem = new ListViewItem(SelectedClip.EventType.ToString());
            lvItem.SubItems.Add(newExportClip.StartTime.ToLocalTime().ToString("s"));
            lvItem.SubItems.Add(newExportClip.EndTime.ToLocalTime().ToString("s"));
            lvItem.Tag = newExportClip;
            NewExportForm.Instance.lvAddedClips.Items.Add(lvItem);
            Close();
        }

        /// <summary>
        /// The DatePickerStart_ValueChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void DatePickerStart_ValueChanged(object sender, EventArgs args)
        {
            if (!_initialStartSet)
            {
                _initialStartSet = true;
                return;
            }

            RefreshClipImages();
        }

        /// <summary>
        /// The DatePickerEnd_ValueChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void DatePickerEnd_ValueChanged(object sender, EventArgs args)
        {
            if (!_initialEndSet)
            {
                _initialEndSet = true;
                return;
            }

            RefreshClipImages();
        }

        /// <summary>
        /// The RefreshClipImages method.
        /// </summary>
        private async void RefreshClipImages()
        {
            var startTime = dtpStartDate.Value.ToUniversalTime();
            var endTime = dtpEndDate.Value.ToUniversalTime();

            var snapshotFilter = new SnapshotFilter
            {
                StartTime = startTime,
                EndTime = endTime,
                Offset = (int)Math.Round((endTime - startTime).TotalSeconds / 5),
                Width = pbxImage1.Width
            };

            var pictureBoxes = new List<PictureBox> { pbxImage1, pbxImage2, pbxImage3, pbxImage4, pbxImage5 };
            var labels = new List<Label> { lblSnapshot1, lblSnapshot2, lblSnapshot3, lblSnapshot4, lblSnapshot5 };

            var listBytes = await GetMultiPartImages(snapshotFilter);
            if (listBytes.Count == 0) 
                return;

            var i = 0;
            foreach (var pictureBox in pictureBoxes)
            {
                MemoryStream memStream = null;
                try
                {
                    memStream = new MemoryStream(listBytes[i].Bytes);
                    pictureBox.SizeMode = PictureBoxSizeMode.StretchImage;
                    pictureBox.Image = Image.FromStream(memStream);
                }
                finally
                {
                    if (memStream != null)
                    {
                        memStream.Dispose();
                    }
                }

                if (listBytes.Count > i + 1)
                    i++;
            }

            i = 0;
            foreach (var label in labels)
            {
                label.Text = listBytes[i].ImageTime.ToLocalTime().ToString("s");
                if (listBytes.Count > i + 1)
                    i++;
            }
        }
    }
}
