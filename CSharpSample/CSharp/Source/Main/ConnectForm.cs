using System;
using System.Windows.Forms;
using CPPCli;

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
            txbxIp.Text = Properties.Settings.Default.IP;
            tbxPort.Text = Properties.Settings.Default.Port;
            txbxUserName.Text = Properties.Settings.Default.UserName;
            txbxPassword.Text = Properties.Settings.Default.Password;
        }

        /// <summary>
        /// The OnFormClosed method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void OnFormClosed(object sender, FormClosedEventArgs args)
        {
            Properties.Settings.Default.IP = txbxIp.Text;
            Properties.Settings.Default.Port = tbxPort.Text;
            Properties.Settings.Default.UserName = txbxUserName.Text;
            Properties.Settings.Default.Password = txbxPassword.Text;
            Properties.Settings.Default.Save();
        }

        /// <summary>
        /// The ButtonConnect_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonConnect_Click(object sender, EventArgs args)
        {
            MainForm.CurrentSystem = new VXSystem(txbxIp.Text, Convert.ToInt32(tbxPort.Text), true);
            try
            {
                var result = MainForm.CurrentSystem.Login(txbxUserName.Text, txbxPassword.Text);
                if (result != Results.Value.OK)
                {
                    MainForm.CurrentSystem.Dispose();
                    MainForm.Instance.WriteToLog("Error logging in: " + result);
                    return;
                }

                MainForm.Instance.bgWorker.WorkerReportsProgress = true;
                MainForm.Instance.bgWorker.RunWorkerAsync();

                // Save the username and password entered by the user for future use.
                MainForm.CurrentUserName = txbxUserName.Text;
                MainForm.CurrentPassword = txbxPassword.Text;
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog("Error: " + ex.Message);
                return;
            }

            var user = MainForm.CurrentSystem.Currentuser;
            var sysDevice = MainForm.CurrentSystem.HostDevice;
            var sysName = sysDevice == null ? txbxIp.Text : sysDevice.Name;
            MainForm.Instance.WriteToLog("Info: Logged in to " + sysName + " as " + user.Name + ".");
            MainForm.Instance.SubscribeToInternalEvents();

            Close();
        }
    }
}
