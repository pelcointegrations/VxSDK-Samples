using System;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The PTZControlForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that contains the PTZ controls for a
    /// device that has PTZ enabled.</remarks> 
    public partial class PTZControlForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="PTZControlForm" /> class.
        /// </summary>
        public PTZControlForm()
        {
            InitializeComponent();
            Instance = this;
        }

        /// <summary>
        /// Gets the Instance property.
        /// </summary>
        /// <value>The current <see cref="PTZControlForm"/> instance.</value>
        public static PTZControlForm Instance { get; private set; }

        /// <summary>
        /// Gets the <see cref="PtzLock" />.
        /// </summary>
        /// <value>The associated <see cref="PtzLock"/>.</value>
        public static PtzLock PTZLock
        {
            get { return ControlManager.Instance.PtzControl.PTZLock; }
        }

        /// <summary>
        /// The TryParseNullable method.
        /// </summary>
        /// <param name="value">The PTZ Controller.</param>
        /// <returns>An <c>int</c> if valid, otherwise <c>null</c>.</returns>
        public static int? TryParseNullable(string value)
        {
            int outValue;
            return int.TryParse(value, out outValue) ? (int?)outValue : null;
        }

        /// <summary>
        /// The GetPatterns method.
        /// </summary>
        /// <remarks>Gets all of the patterns from the VideoXpert system for the selected
        /// device and adds them to the patterns combo box.</remarks>
        public static void GetPatterns()
        {
            if (Instance.cbxPatterns.Items.Count > 0)
            {
                Instance.cbxPatterns.DataSource = null;
                Instance.cbxPatterns.Items.Clear();
            }

            if (ControlManager.Instance.PtzControl == null)
                return;

            var patterns = ControlManager.Instance.PtzControl.GetPatterns().Select(pattern => 
                new { Id = pattern, Text = pattern.Name }).ToList();
            Instance.cbxPatterns.ValueMember = "Id";
            Instance.cbxPatterns.DisplayMember = "Text";
            Instance.cbxPatterns.DataSource = patterns;
        }

        /// <summary>
        /// The GetPresets method.
        /// </summary>
        /// <remarks>Gets all of the presets from the VideoXpert system for the selected
        /// device and adds them to the presets combo box.</remarks>
        public static void GetPresets()
        {
            if (Instance.cbxPresets.Items.Count > 0)
            {
                Instance.cbxPresets.DataSource = null;
                Instance.cbxPresets.Items.Clear();
            }

            if (ControlManager.Instance.PtzControl == null)
                return;

            var presets = ControlManager.Instance.PtzControl.GetPresets().Select(preset => 
                new { Id = preset, Text = preset.Name }).ToList();
            Instance.cbxPresets.ValueMember = "Id";
            Instance.cbxPresets.DisplayMember = "Text";
            Instance.cbxPresets.DataSource = presets;
        }

        /// <summary>
        /// The UpdatePtzLockInfo method.
        /// </summary>
        /// <remarks>Updates the ptz lock info.</remarks>
        public static void UpdatePtzLockInfo()
        {
            if (PTZLock != null)
            {
                Instance.btnLock.Text = PTZLock.IsLocked ? @"Unlock" : @"Lock";
                Instance.lblLockOwner.Text = string.Format("Owner: {0}", PTZLock.Owner);
                Instance.lblExpireTime.Text = string.Format("Expires: {0}", PTZLock.ExpireTime);
                Instance.btnLock.Enabled = true;
                Instance.btnRefreshLock.Enabled = true;
            }
            else
            {
                Instance.lblLockOwner.Text = @"No Ptz Lock found.";
                Instance.lblExpireTime.Text = string.Empty;
                Instance.btnLock.Enabled = false;
                Instance.btnRefreshLock.Enabled = false;
            }
        }

        /// <summary>
        /// Calls appropriate AbsoluteMove method if the values needed are present.
        /// </summary>
        /// <param name="panValue">The pan amount if present, otherwise <c>null</c>.</param>
        /// <param name="tiltValue">The tilt amount if present, otherwise <c>null</c>.</param>
        /// <param name="zoomValue">The zoom amount if present, otherwise <c>null</c>.</param>
        /// <returns><c>true</c> if AbsoluteMove was called, otherwise <c>false</c>.</returns>
        private static bool TryAbsoluteMove(int? panValue, int? tiltValue, int? zoomValue)
        {
            if (!panValue.HasValue || !tiltValue.HasValue)
                return false;

            if (zoomValue.HasValue)
                ControlManager.Instance.PtzControl.AbsoluteMove(panValue.Value, tiltValue.Value, zoomValue.Value);
            else
                ControlManager.Instance.PtzControl.AbsoluteMove(panValue.Value, tiltValue.Value);

            return true;
        }

        /// <summary>
        /// The StopPtz method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        /// <remarks>Called when the mouse up event occurs from a PTZ control button.  The stop call
        /// will stop all PTZ actions.</remarks>
        private void StopPtz(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.Stop();
        }

        /// <summary>
        /// The ButtonPtzUL_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzUL_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousMove(-100, 100, PtzController.ZoomDirections.None);
        }

        /// <summary>
        /// The ButtonPtzL_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzL_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousMove(-100, 0, PtzController.ZoomDirections.None);
        }

        /// <summary>
        /// The ButtonPtzDL_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzDL_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
            {
                ControlManager.Instance.PtzControl.ContinuousMove(-100, -100, PtzController.ZoomDirections.None);
            }
        }

        /// <summary>
        /// The ButtonPtzU_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzU_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousMove(0, 100, PtzController.ZoomDirections.None);
        }

        /// <summary>
        /// The ButtonPtzUR_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzUR_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousMove(100, 100, PtzController.ZoomDirections.None);
        }

        /// <summary>
        /// The ButtonPtzR_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzR_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousMove(100, 0, PtzController.ZoomDirections.None);
        }

        /// <summary>
        /// The ButtonPtzDR_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzDR_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousMove(100, -100, PtzController.ZoomDirections.None);
        }

        /// <summary>
        /// The ButtonPtzD_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzD_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousMove(0, -100, PtzController.ZoomDirections.None);
        }

        /// <summary>
        /// The ButtonPtzZoomIn_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzZoomIn_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousMove(0, 0, PtzController.ZoomDirections.In);
        }

        /// <summary>
        /// The ButtonPtzZoomOut_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonPtzZoomOut_Click(object sender, MouseEventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousMove(0, 0, PtzController.ZoomDirections.Out);
        }

        /// <summary>
        /// The ButtonTriggerPreset_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonTriggerPreset_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null && cbxPresets.SelectedItem != null)
                ControlManager.Instance.PtzControl.TriggerPreset((Preset)cbxPresets.SelectedValue);
        }

        /// <summary>
        /// The ButtonTriggerPattern_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>        
        private void ButtonTriggerPattern_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null && cbxPatterns.SelectedItem != null)
                ControlManager.Instance.PtzControl.TriggerPattern((Pattern)cbxPatterns.SelectedValue);
        }

        /// <summary>
        /// The ButtonPtzFocusNear_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>    
        private void ButtonPtzFocusNear_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousFocus(PtzController.FocusDirections.Near);
        }

        /// <summary>
        /// The ButtonPtzFocusFar_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>    
        private void ButtonPtzFocusFar_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousFocus(PtzController.FocusDirections.Far);
        }

        /// <summary>
        /// The ButtonPtzIrisOpen_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>    
        private void ButtonPtzIrisOpen_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousIris(PtzController.IrisDirections.Open);
        }

        /// <summary>
        /// The ButtonPtzIrisClose_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>    
        private void ButtonPtzIrisClose_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl != null)
                ControlManager.Instance.PtzControl.ContinuousIris(PtzController.IrisDirections.Close);
        }

        /// <summary>
        /// The ButtonGetPosition_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>    
        private void ButtonGetPosition_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl == null)
                return;

            txbxAbsX.Text = ControlManager.Instance.PtzControl.X.ToString();
            txbxAbsY.Text = ControlManager.Instance.PtzControl.Y.ToString();
            txbxAbsZ.Text = ControlManager.Instance.PtzControl.Z.ToString();
        }

        /// <summary>
        /// The ButtonSetPosition_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>    
        private void ButtonSetPosition_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl == null)
                return;

            var panValue = TryParseNullable(txbxAbsX.Text);
            var tiltValue = TryParseNullable(txbxAbsY.Text);
            var zoomValue = TryParseNullable(txbxAbsZ.Text);

            // If only a Pan value was provided, call <see cref="AbsolutePan"/>.
            if (panValue.HasValue && !tiltValue.HasValue && !zoomValue.HasValue)
            {
                ControlManager.Instance.PtzControl.AbsolutePan(Convert.ToInt32(txbxAbsX.Text));
                return;
            }

            // If only a Tilt value was provided, call <see cref="AbsoluteTilt"/>.
            if (!panValue.HasValue && tiltValue.HasValue && !zoomValue.HasValue)
            {
                ControlManager.Instance.PtzControl.AbsoluteTilt(Convert.ToInt32(txbxAbsY.Text));
                return;
            }

            // If only a Zoom value was provided, call <see cref="AbsoluteZoom"/>.
            if (!panValue.HasValue && !tiltValue.HasValue && zoomValue.HasValue)
            {
                ControlManager.Instance.PtzControl.AbsoluteZoom(Convert.ToInt32(txbxAbsZ.Text));
                return;
            }

            // Call the appropriate AbsoluteMove method if the values needed are present.
            if (TryAbsoluteMove(panValue, tiltValue, zoomValue))
                return;

            MainForm.Instance.WriteToLog("Invalid amount of values.");
        }

        /// <summary>
        /// The ButtonMove_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>    
        private void ButtonMove_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl == null)
                return;

            int valueX = int.TryParse(txbxRelX.Text, out valueX) ? valueX : 0;
            int valueY = int.TryParse(txbxRelY.Text, out valueY) ? valueY : 0;
            int valueZ = int.TryParse(txbxRelZ.Text, out valueZ) ? valueZ : 0;

            ControlManager.Instance.PtzControl.RelativeMove(valueX, valueY, valueZ);
        }

        /// <summary>
        /// The OnFormClosing method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void OnFormClosing(object sender, FormClosingEventArgs args)
        {
            // Hide the form and cancel the close event so it can be reopened later.
            Hide();
            args.Cancel = true;
        }

        /// <summary>
        /// The ButtonRefreshLock_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRefreshLock_Click(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl == null)
                return;

            UpdatePtzLockInfo();
        }

        /// <summary>
        /// The ButtonLockClick method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonLockClick(object sender, EventArgs args)
        {
            if (ControlManager.Instance.PtzControl == null)
                return;

            if (PTZLock != null)
            {
                if (PTZLock.IsLocked)
                    PTZLock.Unlock();
                else
                    PTZLock.Lock(300);
            }

            UpdatePtzLockInfo();
        }
    }
}
