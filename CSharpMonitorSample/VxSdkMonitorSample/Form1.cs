using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VxSdkMonitorSample
{
    public partial class Form1 : Form
    {
        private VxSdk _vxSdk;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _vxSdk = new VxSdk();
            listBoxMonitors.DataSource = _vxSdk.Monitors;
            listBoxMonitors.DisplayMember = "Name";
            listBoxCameras.DataSource = _vxSdk.Cameras;
            listBoxCameras.DisplayMember = "Name";
        }

        private async void buttonLogin_Click(object sender, EventArgs e)
        {
            labelMessage.Text = string.Empty;

            var ip = textBoxIp.Text;
            var user = textBoxUser.Text;
            var passwd = textBoxPassword.Text;

            string msg = string.Empty;
            bool success = await _vxSdk.Init(ip, user, passwd);
            if (success)
            {
                await _vxSdk.GetMonitors();
                await _vxSdk.GetCameras();
            }
            else
                labelMessage.Text = "Failed to login to the Vx system provided";
        }

        private async void button1x1_Click(object sender, EventArgs e)
        {
            var monitor = listBoxMonitors.SelectedItem as CPPCli.Monitor;
            await _vxSdk.ChangeLayout(monitor, VxSdk.VxLayout.Layout1x1);
            UpdateCellsList(1);
        }

        private async void button2x2_Click(object sender, EventArgs e)
        {
            var monitor = listBoxMonitors.SelectedItem as CPPCli.Monitor;
            await _vxSdk.ChangeLayout(monitor, VxSdk.VxLayout.Layout2x2);
            UpdateCellsList(4);
        }

        private async void button3x3_Click(object sender, EventArgs e)
        {
            var monitor = listBoxMonitors.SelectedItem as CPPCli.Monitor;
            await _vxSdk.ChangeLayout(monitor, VxSdk.VxLayout.Layout3x3);
            UpdateCellsList(9);
        }

        private async void button4x4_Click(object sender, EventArgs e)
        {
            var monitor = listBoxMonitors.SelectedItem as CPPCli.Monitor;
            await _vxSdk.ChangeLayout(monitor, VxSdk.VxLayout.Layout4x4);
            UpdateCellsList(16);
        }

        private void checkBoxLive_CheckedChanged(object sender, EventArgs e)
        {
            dateTimePickerRecorded.Enabled = !checkBoxLive.Checked;
        }

        private async void buttonShowVideo_Click(object sender, EventArgs e)
        {
            var monitor = listBoxMonitors.SelectedItem as CPPCli.Monitor;
            int cellIdx = listBoxCells.SelectedIndex;
            var camera = listBoxCameras.SelectedItem as CPPCli.DataSource;
            DateTime time = checkBoxLive.Checked ? default(DateTime) : dateTimePickerRecorded.Value;

            if (monitor == null || cellIdx == -1 || camera == null)
            {
                labelMessage.Text = "Ensure a monitor, cell, and camera are selected";
                return;
            }
            else
                labelMessage.Text = string.Empty;

            await _vxSdk.PlayVideo(monitor, cellIdx, camera, time);
        }

        private void UpdateCellsList(int count)
        {
            listBoxCells.Items.Clear();
            for (int i = 0; i < count; i++)
                listBoxCells.Items.Add($"__ {i+1} __");
            if (listBoxCells.Items.Count > 0)
                listBoxCells.SelectedIndex = 0;
        }
    }
}
