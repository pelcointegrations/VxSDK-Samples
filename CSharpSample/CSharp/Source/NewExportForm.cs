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

            // Clone each item in the MainForm ListView and add it to lvDevices.
            foreach (ListViewItem item in MainForm.Instance.lvDevices.Items)
            {
                var lvItem = (ListViewItem)item.Clone();
                lvDevices.Items.Add(lvItem);
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
                // Get the selected device.
                var dev = (Device)lvDevices.SelectedItems[0].Tag;
                var dataSources = dev.DataSources;
                foreach (var dataSource in dataSources)
                {
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
            }
            catch 
            { }   
        }

        /// <summary>
        /// The ButtonAddClip_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.s</param>
        private void ButtonAddClip_Click(object sender, EventArgs args)
        {
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
                this.Close();
        }

        /// <summary>
        /// The ButtonRemoveClip_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.s</param>
        private void ButtonRemoveClip_Click(object sender, EventArgs args)
        {
            if (lvAddedClips.SelectedItems[0] != null)
            {
                lvAddedClips.SelectedItems[0].Remove();
            }
        }
    }
}
