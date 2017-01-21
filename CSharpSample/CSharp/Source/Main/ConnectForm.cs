using System;
using System.ComponentModel;
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
            txbxIp.Text = Properties.Settings.Default.IP;
            tbxPort.Text = Properties.Settings.Default.Port;
            txbxUserName.Text = Properties.Settings.Default.UserName;
            txbxPassword.Text = Properties.Settings.Default.Password;
            var defaultLogPath = Properties.Settings.Default.LogDirectory;
            if (string.IsNullOrEmpty(defaultLogPath))
            {
                defaultLogPath = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData) +
                                 "\\Pelco\\VxSdk\\Logs";
            }

            fbdSelectLogPath.SelectedPath = defaultLogPath;
            tbxLogPath.Text = defaultLogPath;
        }

        /// <summary>
        /// The AddItemToListView method.
        /// </summary>
        /// <param name="item">The item to add to the list.</param>
        private static void AddItemToListView(ListViewItem item)
        {
            if (MainForm.Instance.lvDataSources.InvokeRequired)
            {
                MainForm.Instance.lvDataSources.Invoke(
                    new MethodInvoker(delegate { MainForm.Instance.lvDataSources.Items.Add(item); }));
            }
            else
                MainForm.Instance.lvDataSources.Items.Add(item);
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
            Properties.Settings.Default.LogDirectory = tbxLogPath.Text;
            Properties.Settings.Default.Save();
        }

        /// <summary>
        /// The ButtonSelectLogPath_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSelectLogPath_Click(object sender, EventArgs args)
        {
            if (fbdSelectLogPath.ShowDialog() != DialogResult.OK)
                return;

            var name = fbdSelectLogPath.SelectedPath;
            tbxLogPath.Text = name;
            Refresh();
        }

        /// <summary>
        /// The ButtonConnect_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonConnect_Click(object sender, EventArgs args)
        {
            MainForm.CurrentSystem = new VXSystem(txbxIp.Text, Convert.ToInt32(tbxPort.Text), true);
            var result = VxGlobal.SetLogPath(tbxLogPath.Text.Replace(@"\", @"\\"));
            try
            {
                // Create a new VideoXpert system.
                if (result != Results.Value.OK)
                {
                    MainForm.Instance.WriteToLog("Error setting log path: " + result);
                    return;
                }

                result = VxGlobal.InitializeSdk(MainForm.SdkKey);
                if (result != Results.Value.OK)
                {
                    MainForm.CurrentSystem.Dispose();
                    MainForm.Instance.WriteToLog("Error initializing SDK: " + result);
                    return;
                }

                result = MainForm.CurrentSystem.Login(txbxUserName.Text, txbxPassword.Text);
                if (result != Results.Value.OK)
                {
                    MainForm.CurrentSystem.Dispose();
                    MainForm.Instance.WriteToLog("Error logging in: " + result);
                    return;
                }

                MainForm.CurrentDevices = MainForm.CurrentSystem.GetDevices();
                bgwAddDevices.WorkerReportsProgress = true;
                bgwAddDevices.RunWorkerAsync();

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
            MainForm.Instance.WriteToLog("Info: Logged in to " + txbxIp.Text + " as " + user.Name + ".");

            Close();
        }

        /// <summary>
        /// The BGWorkerAddDataSources_DoWork method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void BGWorkerAddDataSources_DoWork(object sender, DoWorkEventArgs args)
        {
            if (MainForm.CurrentDataSources != null)
                return;

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
                bgwAddDevices.ReportProgress((int)progress, null);

                var lvItem = new ListViewItem(dataSource.Name);
                lvItem.SubItems.Add(dataSource.Ip);
                lvItem.SubItems.Add(((VxDeviceState)dataSource.State).ToString());
                lvItem.Tag = dataSource;
                AddItemToListView(lvItem);
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
            });
        }

        /// <summary>
        /// The BGWorkerAddDevices_ProgressChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void BGWorkerAddDevices_ProgressChanged(object sender, ProgressChangedEventArgs args)
        {
            MainForm.Instance.pbLoadCameras.Invoke(
                new MethodInvoker(delegate { MainForm.Instance.pbLoadCameras.Value = args.ProgressPercentage; }));
        }

        /// <summary>
        /// The BGWorkerAddDevices_RunWorkerCompleted method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void BGWorkerAddDevices_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs args)
        {
            ChangeProgressViewState(false);
        }
    }
}
