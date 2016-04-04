using System;
using System.Windows.Forms;
using CPPCli;
using SDKSampleApp.Enums;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The NewExportForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create clips,
    /// add them to a new export and begin the export process.</remarks>
    public partial class NewExportForm : Form
    {
        /// <summary>
        /// Gets the Instance property.
        /// </summary>
        /// <value>The current <see cref="NewExportForm"/> instance.</value>
        public static NewExportForm Instance { get; private set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="NewExportForm" /> class.
        /// </summary>        
        public NewExportForm()
        {
            InitializeComponent();

            // Clone each item in the MainForm ListView and add it to lvDataSources.
            foreach (ListViewItem item in MainForm.Instance.lvDataSources.Items)
            {
                var lvItem = (ListViewItem)item.Clone();
                lvDataSources.Items.Add(lvItem);
            }

            Instance = this;
        }

        /// <summary>
        /// The ListViewDevices_ItemSelected method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        /// <remarks>Populates the available clips list when a new device is selected.</remarks>
        public void ListViewDevices_ItemSelected(object sender, EventArgs args)
        {
            try
            {
                lvAvailableClips.Items.Clear();

                if (lvDataSources.SelectedItems.Count == 0) return;

                // Get the selected device.
                var dataSource = (DataSource)lvDataSources.SelectedItems[0].Tag;

                foreach (var dataInterface in dataSource.DataInterfaces)
                {
                    // If the protocol is not Rtsp/Rtp then it will not be recording.
                    if (dataInterface.Protocol != (DataInterface.StreamProtocols)VxStreamProtocol.RtspRtp)
                        continue;

                    var clips = dataSource.Clips;
                    if (clips.Count <= 0)
                        continue;

                    foreach (var clip in clips)
                    {
                        var lvItem = new ListViewItem(clip.EventType.ToString());
                        lvItem.SubItems.Add(clip.StartTime.ToLocalTime().ToString("s"));
                        lvItem.SubItems.Add(clip.EndTime.ToLocalTime().ToString("s"));
                        lvItem.Tag = clip;
                        lvAvailableClips.Items.Add(lvItem);
                    }

                    return;
                }
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog(string.Format("Error: {0}", ex.Message));
            }
        }

        /// <summary>
        /// The ButtonAddClip_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.s</param>
        private void ButtonAddClip_Click(object sender, EventArgs args)
        {
            if (lvAvailableClips.SelectedItems.Count == 0)
                return;

            using (var addClipForm = new AddClipForm())
            {
                addClipForm.ShowDialog();
            }
        }

        /// <summary>
        /// The ButtonExportSettings_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonExportSettings_Click(object sender, EventArgs args)
        {
            DialogResult result;
            using (var settingsForm = new ExportSettingsForm())
            {
                result = settingsForm.ShowDialog();
            }

            if (result == DialogResult.OK)
                Close();
        }

        /// <summary>
        /// The ButtonRemoveClip_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.s</param>
        private void ButtonRemoveClip_Click(object sender, EventArgs args)
        {
            if (lvAddedClips.SelectedItems.Count != 0)
                lvAddedClips.SelectedItems[0].Remove();
        }
    }
}
