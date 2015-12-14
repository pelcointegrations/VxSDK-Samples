using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using CPPCli;
using SDKSampleApp.Enums;
using SDKSampleApp.Properties;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The MainForm class.
    /// </summary>
    /// <remarks>This class contains the main UI form.</remarks>
    public partial class MainForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="MainForm" /> class.
        /// </summary>
        public MainForm()
        {
            InitializeComponent();
            scOuter.Panel2Collapsed = true;
            Instance = this;
            PtzForm = new PTZControlForm();
            Control = new ControlManager();
        }

        /// <summary>
        /// The SDK key used to initialize the SDK.
        /// </summary>
        public static string SdkKey { get { return "ReplaceWithGeneratedKey"; } }

        /// <summary>
        /// Gets or sets the CurrentDevice property.
        /// </summary>
        /// <value>The device that is currently streaming.</value>
        public static Device CurrentDevice { get; set; }

        /// <summary>
        /// Gets or sets the CurrentDevices property.
        /// </summary>
        /// <value>The current list of devices found on the VideoXpert system.</value>
        public static List<Device> CurrentDevices { get; set; }

        /// <summary>
        /// Gets or sets the CurrentPassword property.
        /// </summary>
        /// <value>The current VideoXpert system password.</value>
        public static string CurrentPassword { get; set; }

        /// <summary>
        /// Gets or sets the CurrentSystem property.
        /// </summary>
        /// <value>The current VideoXpert system.</value>
        public static VXSystem CurrentSystem { get; set; }

        /// <summary>
        /// Gets or sets the CurrentUserName property.
        /// </summary>
        /// <value>The current VideoXpert system user name.</value>
        public static string CurrentUserName { get; set; }

        /// <summary>
        /// Gets the Instance property.
        /// </summary>
        /// <value>The current <see cref="MainForm"/> instance.</value>
        public static MainForm Instance { get; private set; }

        /// <summary>
        /// Gets or sets the PtzForm property.
        /// </summary>
        /// <value>A <see cref="PTZControlForm"/>.</value>
        public static PTZControlForm PtzForm { get; set; }

        /// <summary>
        /// Gets or sets the Control property.
        /// </summary>
        /// <value>A <see cref="ControlManager"/>.</value>
        public ControlManager Control { get; set; }

        /// <summary>
        /// The WriteToLog method.
        /// </summary>
        /// <param name="message">The <paramref name="message"/> parameter.</param>
        public void WriteToLog(string message)
        {
            var time = DateTime.Now;
            txbxLog.BeginInvoke((MethodInvoker)delegate
            {
                txbxLog.AppendText(time.ToLongTimeString() + ": " + message + "\n");
            });
        }

        /// <summary>
        /// The ButtonLive_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonLive_Click(object sender, EventArgs args)
        {
            if (Control.Current == null) 
                StartStream();

            Control.Current.GoToLive();
            Control.ChangePtzFormState(Control.PtzControl != null);
        }

        /// <summary>
        /// The ButtonPause_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonPause_Click(object sender, EventArgs args)
        {
            if (Control.Current == null)
                return;

            Control.Current.Pause();
            Control.ChangePtzFormState(false);
        }

        /// <summary>
        /// The ButtonPlay_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonPlay_Click(object sender, EventArgs args)
        {
            StartStream();
        }

        /// <summary>
        /// The ButtonSeek_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSeek_Click(object sender, EventArgs args)
        {
            // The seek time value must be in UTC format.
            var yesterday = DateTime.UtcNow.AddDays(-1);
            StartStream(yesterday);
        }

        /// <summary>
        /// The ButtonStop_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonStop_Click(object sender, EventArgs args)
        {
            StopStream();
        }

        /// <summary>
        /// The MenuItemLog_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemLog_Click(object sender, EventArgs args)
        {
            if (scOuter.Panel2Collapsed)
            {
                showLogToolStripMenuItem.Text = @"Hide Log";
                this.ClientSize = new System.Drawing.Size(this.ClientSize.Width, this.ClientSize.Height + 90);
                scOuter.Panel2Collapsed = false;
            }
            else
            {
                showLogToolStripMenuItem.Text = @"Show Log";
                this.ClientSize = new System.Drawing.Size(this.ClientSize.Width, this.ClientSize.Height - 90);
                scOuter.Panel2Collapsed = true;
            }
        }

        /// <summary>
        /// The MenuItemConnect_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemConnect_Click(object sender, EventArgs args)
        {
            using (var connectForm = new ConnectForm())
            {
                connectForm.ShowDialog();
            }
        }

        /// <summary>
        /// The MenuItemExit_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemExit_Click(object sender, EventArgs args)
        {
            Close();
        }

        /// <summary>
        /// The MenuItemExportManager_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemExportManager_Click(object sender, EventArgs args)
        {
            using (var exportForm = new ExportManagerForm())
            {
                exportForm.ShowDialog();
            }
        }

        /// <summary>
        /// The MenuItemInsertEvent_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemInsertEvent_Click(object sender, EventArgs args)
        {
            using (var addEventForm = new AddEventForm())
            {
                addEventForm.ShowDialog();
            }
        }

        /// <summary>
        /// The MenuItemProtocol_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemProtocol_Click(object sender, EventArgs args)
        {
            var item = sender as ToolStripMenuItem;
            if (item.Text == @"MJPEG")
            {
                rtspToolStripMenuItem.Checked = false;
                mjpegToolStripMenuItem.Checked = true;
            }
            else
            {
                rtspToolStripMenuItem.Checked = true;
                mjpegToolStripMenuItem.Checked = false;
            }

            StopAllStreams();
        }

        /// <summary>
        /// The MenuItemShowPtzControls_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemShowPtzControls_Click(object sender, EventArgs args)
        {
            PtzForm.Show();
        }

        /// <summary>
        /// The MenuItemSituationManager_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemSituationManager_Click(object sender, EventArgs args)
        {
            using (var situationForm = new SituationManagerForm())
            {
                situationForm.ShowDialog();
            }
        }

        /// <summary>
        /// The MenuItemSubscribe_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void MenuItemSubscribe_Click(object sender, EventArgs args)
        {
            if (!subscribeToSystemEventsToolStripMenuItem.Checked)
            {
                CurrentSystem.SystemEvent += OnSystemEvent;
                subscribeToSystemEventsToolStripMenuItem.Checked = true;
            }
            else
            {
                CurrentSystem.SystemEvent -= OnSystemEvent;
                subscribeToSystemEventsToolStripMenuItem.Checked = false;
            }
        }

        /// <summary>
        /// The PanelVideoStreamLeft_MouseClick method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void PanelVideoStreamLeft_MouseClick(object sender, MouseEventArgs args)
        {
            Control.SelectControl(ControlManager.Controls.Left);
        }

        /// <summary>
        /// The PanelVideoStreamRight_MouseClick method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void PanelVideoStreamRight_MouseClick(object sender, MouseEventArgs args)
        {
            Control.SelectControl(ControlManager.Controls.Right);
        }

        /// <summary>
        /// The OnSystemEvent method.
        /// </summary>
        /// <param name="systemEvent">The <paramref name="systemEvent"/> parameter.</param>
        private void OnSystemEvent(Event systemEvent)
        {
            foreach (var device in CurrentDevices.Where(device => device.Id == systemEvent.GeneratorDeviceId))
            {
                    WriteToLog(string.Format(Resources.EventHeaderFormatString, device.Name, device.Ip));
            }

            WriteToLog(string.Format(
                    Resources.EventDetailsFormatString,
                    systemEvent.Time,
                    systemEvent.Severity,
                    systemEvent.SituationType,
                    (VxAckState)systemEvent.AckState,
                    systemEvent.GeneratorDeviceId,
                    systemEvent.Id,
                    systemEvent.SourceUserName));
        }

        /// <summary>
        /// The SetupPtzControls method.
        /// </summary>
        /// <param name="dataSource">The <paramref name="dataSource"/> parameter.</param>
        /// <remarks>Checks if PTZ is enabled on the device.  If enabled, it also gets the
        /// available presets and patterns for the device.</remarks>
        private void SetupPtzControls(DataSource dataSource)
        {
            Control.PtzControl = dataSource.IsPTZ ? dataSource.PTZController : null;
            Control.ChangePtzFormState(dataSource.IsPTZ);
        }

        /// <summary>
        /// The StartStream method.
        /// </summary>
        /// <param name="seekTime">The <paramref name="seekTime"/> in UTC format.  If no value or a default 
        /// DateTime object is given then the stream is started in live mode.</param>
        private void StartStream(DateTime seekTime = default(DateTime))
        {
            try
            {
                // Get the data sources for the selected device.
                var device = (Device)lvDevices.SelectedItems[0].Tag;
                var dataSources = device.DataSources;
                if (dataSources.Count == 0)
                {
                    WriteToLog("No DataSources found!");
                    return;
                }

                // Get the correct data source based on the selected protocol type.
                DataSource dataSource;
                VxStreamProtocol selProtocol;
                if (mjpegToolStripMenuItem.Checked)
                {
                    dataSource = dataSources.First(ds => ds.DataInterfaces.FirstOrDefault(iFace =>
                        iFace.Protocol == (DataInterface.StreamProtocols)VxStreamProtocol.MjpegPull) != null);
                    selProtocol = VxStreamProtocol.MjpegPull;
                }
                else
                {
                    dataSource = dataSources.FirstOrDefault(ds => ds.DataInterfaces.FirstOrDefault(iFace =>
                        iFace.Protocol == (DataInterface.StreamProtocols)VxStreamProtocol.RtspRtp) != null);
                    selProtocol = VxStreamProtocol.RtspRtp;
                }

                // If the protocol type is unavailable on the device then exit.
                if (dataSource == null)
                    return;

                // If the media controller exists then a stream is running and the user is
                // requesting a new action on it.  If it's null then this is either the
                // first run or an existing stream has been stopped.  So a new media controller
                // instance is needed.
                if (Control.Current == null)
                {
                    Control.Current = new MediaControl(dataSource, (DataInterface.StreamProtocols)selProtocol);
                    Control.SubscribeToTimestamps();
                    Control.Current.SetVideoWindow(Control.SelectedPanel.Handle);
                }
                else
                {
                    // If a new device has been selected while another stream is running, stop the
                    // old stream and set up the new stream using the new data source.
                    if (device.Id != CurrentDevice.Id)
                    {
                        Control.Current.Stop();
                        Control.Current.SetDataSource(dataSource, (DataInterface.StreamProtocols)selProtocol);
                    }
                }

                if (seekTime == default(DateTime))
                {
                    Control.Current.Play((int)nudSpeed.Value);
                }
                else
                {
                    Control.Current.Seek(seekTime, (int)nudSpeed.Value);
                }

                Control.SetPlayingIndex();
                SetupPtzControls(dataSource);
                CurrentDevice = device;
            }
            catch (Exception ex)
            {
                WriteToLog(string.Format(@"Error: {0}\n", ex.Message));
            }
        }

        /// <summary>
        /// The StopStream method.
        /// </summary>
        private void StopStream()
        {
            try
            {
                if (Control.Current == null)
                    return;

                Control.Current.Stop();

                Control.UnsubscribeToTimestamps();
                Control.SelectedLabel.BeginInvoke((MethodInvoker)delegate
                {
                    Control.SelectedLabel.Text = string.Empty;
                });

                Control.SelectedPanel.Refresh();

                Control.PtzControl = null;
                Control.ChangePtzFormState(false);

                Control.Current.Dispose();
                Control.Current = null;
            }
            catch (Exception ex)
            {
                WriteToLog(string.Format(@"Error: {0}\n", ex.Message));
            }
        }

        /// <summary>
        /// The StopAllStreams method.
        /// </summary>
        private void StopAllStreams()
        {
            try
            {
                Control.SelectControl(ControlManager.Controls.Left);
                StopStream();
                Control.SelectControl(ControlManager.Controls.Right);
                StopStream();
            }
            catch (Exception ex)
            {
                WriteToLog(string.Format(@"Error: {0}\n", ex.Message));
            }
        }
    }
}
