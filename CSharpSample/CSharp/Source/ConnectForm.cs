using System;
using System.Windows.Forms;
using CPPCli;
using SDKSampleApp.Enums;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ConnectForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to enter the IP, username
    /// and password of the VideoXpert system to connect to.</remarks>
    public partial class ConnectForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="ConnectForm" /> class.
        /// </summary>
        public ConnectForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The ButtonConnect_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonConnect_Click(object sender, EventArgs args)
        {
            try
            {
                // Create a new VideoXpert system.
                MainForm.CurrentSystem = new VXSystem(txbxIp.Text);
                var result = MainForm.CurrentSystem.InitializeSdk(MainForm.SdkKey);
                if(result != Results.Value.OK)
                {
                    MainForm.CurrentSystem.Dispose();
                    MainForm.Instance.WriteToLog("Error initializing SDK: " + result);
                    return;
                }
                result = MainForm.CurrentSystem.Login(txbxUsername.Text, txbxPassword.Text);
                if (result != Results.Value.OK)
                {
                    MainForm.CurrentSystem.Dispose();
                    MainForm.Instance.WriteToLog("Error logging in: " + result);
                    return;
                }

                // Get all of the devices from the system and add them to the device list.
                MainForm.CurrentDevices = MainForm.CurrentSystem.GetDevices();
                foreach (var vxDevice in MainForm.CurrentDevices)
                {
                    var lvItem = new ListViewItem(vxDevice.Name);
                    lvItem.SubItems.Add(vxDevice.Ip);
                    lvItem.SubItems.Add(((VxDeviceState)vxDevice.State).ToString());
                    lvItem.Tag = vxDevice;
                    MainForm.Instance.lvDevices.Items.Add(lvItem);
                }

                // Save the username and password entered by the user for future use.
                MainForm.CurrentUserName = txbxUsername.Text;
                MainForm.CurrentPassword = txbxPassword.Text;
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog("Error: " + ex.Message);
                return;
            }

            // If the system creation did not throw then assume we have a valid system
            // and enable the UI elements.
            MainForm.Instance.exportToolStripMenuItem.Enabled = true;
            MainForm.Instance.eventsToolStripMenuItem.Enabled = true;
            MainForm.Instance.situationsToolStripMenuItem.Enabled = true;
            MainForm.Instance.btnSeek.Enabled = true;
            MainForm.Instance.btnPause.Enabled = true;
            MainForm.Instance.btnPlay.Enabled = true;
            MainForm.Instance.btnStop.Enabled = true;
            MainForm.Instance.btnLive.Enabled = true;

            Close();
        }
    }
}
