using System.Drawing;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ControlManager class.
    /// </summary>
    /// <remarks>Manages the UI controls based on the selected video panel.</remarks> 
    public class ControlManager
    {
        /// <summary>
        /// The Controls enumeration.
        /// </summary>
        /// <remarks>The left or right control.</remarks>
        public enum Controls
        {
            /// <summary>The left control.</summary>
            Left,

            /// <summary>The right control.</summary>
            Right,
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ControlManager" /> class.
        /// </summary>
        public ControlManager()
        {
            Instance = this;
            this.SelectControl(Controls.Left);
        }

        /// <summary>
        /// Gets the Instance property.
        /// </summary>
        /// <value>The current <see cref="ControlManager"/> instance.</value>
        public static ControlManager Instance { get; private set; }

        /// <summary>
        /// Gets or sets the SelectedControl property.
        /// </summary>
        /// <value>A <see cref="Controls"/>.</value>
        public Controls SelectedControl { get; set; }

        /// <summary>
        /// The SubscribeToTimestamps method.
        /// </summary>
        public void SubscribeToTimestamps()
        {
            if (this.SelectedControl == Controls.Left)
            {
                this.Current.TimestampEvent += OnTimestampEventLeft;
            }
            else
            {
                this.Current.TimestampEvent += OnTimestampEventRight;
            }
        }

        /// <summary>
        /// The UnsubscribeToTimestamps method.
        /// </summary>
        public void UnsubscribeToTimestamps()
        {
            if (this.SelectedControl == Controls.Left)
            {
                this.Current.TimestampEvent -= OnTimestampEventLeft;
            }
            else
            {
                this.Current.TimestampEvent -= OnTimestampEventRight;
            }
        }

        /// <summary>
        /// The SelectControl method.
        /// </summary>
        /// <param name="control">The <paramref name="control"/> to select.</param>
        public void SelectControl(Controls control)
        {
            if (control == Controls.Left)
            {
                this.SelectedControl = Controls.Left;
                MainForm.Instance.scVideoPanels.Panel1.BackColor = Color.LimeGreen;
                MainForm.Instance.scVideoPanels.Panel2.BackColor = SystemColors.Control;
                this.ChangePtzFormState(this.PtzControl != null);
                if (MainForm.Instance.lvDevices.Items.Count > 0)
                    MainForm.Instance.lvDevices.Items[this._playingIndexLeft].Selected = true;
            }
            else
            {
                this.SelectedControl = Controls.Right;
                MainForm.Instance.scVideoPanels.Panel1.BackColor = SystemColors.Control;
                MainForm.Instance.scVideoPanels.Panel2.BackColor = Color.LimeGreen;
                this.ChangePtzFormState(this.PtzControl != null);
                if (MainForm.Instance.lvDevices.Items.Count > 0)
                    MainForm.Instance.lvDevices.Items[this._playingIndexRight].Selected = true;
            }
        }

        /// <summary>
        /// The ChangePtzFormState method.
        /// </summary>
        /// <param name="enabled">The state to set the <c>PTZControlForm</c> controls.</param>
        public void ChangePtzFormState(bool enabled)
        {
            var isEnabled = enabled;
            if (this.Current != null && this.Current.Mode != MediaControl.Modes.Live)
                isEnabled = false;

            foreach (Control control in PTZControlForm.Instance.Controls)
            {
                control.Enabled = isEnabled;
            }

            PTZControlForm.GetPatterns();
            PTZControlForm.GetPresets();
        }

        /// <summary>
        /// The SetPlayingIndex method.
        /// </summary>
        public void SetPlayingIndex()
        {
            if (this.SelectedControl == Controls.Left)
            {
                this._playingIndexLeft = MainForm.Instance.lvDevices.SelectedItems[0].Index;
            }
            else
            {
                this._playingIndexRight = MainForm.Instance.lvDevices.SelectedItems[0].Index;
            }
        }

        /// <summary>
        /// Gets or sets the Current property.
        /// </summary>
        /// <value>A <see cref="MediaControl"/>.</value>
        public MediaControl Current
        {
            get
            {
                return this.SelectedControl == Controls.Left ? this._mediaControllerLeft : this._mediaControllerRight;
            }

            set
            {
                if (this.SelectedControl == Controls.Left)
                {
                    this._mediaControllerLeft = value;
                }
                else
                {
                    this._mediaControllerRight = value;
                }
            }
        }

        /// <summary>
        /// Gets or sets the PtzControl property.
        /// </summary>
        /// <value>A <see cref="PtzController"/>.</value>
        public PtzController PtzControl
        {
            get
            {
                return this.SelectedControl == Controls.Left ? this._ptzCtrlLeft : this._ptzCtrlRight;
            }

            set
            {
                if (this.SelectedControl == Controls.Left)
                {
                    this._ptzCtrlLeft = value;
                }
                else
                {
                    this._ptzCtrlRight = value;
                }
            }
        }

        /// <summary>
        /// Gets the SelectedPanel property.
        /// </summary>
        /// <value>The selected <see cref="Panel"/>.</value>
        public Panel SelectedPanel
        {
            get
            {
                return this.SelectedControl == Controls.Left ? 
                    MainForm.Instance.panelVideoStreamLeft : MainForm.Instance.panelVideoStreamRight;
            }
        }

        /// <summary>
        /// Gets the SelectedLabel property.
        /// </summary>
        /// <value>The selected <see cref="Label"/>.</value>
        public Label SelectedLabel
        {
            get
            {
                return this.SelectedControl == Controls.Left ? 
                    MainForm.Instance.lblTimeStampLeft : MainForm.Instance.lblTimeStampRight;
            }
        }

        /// <summary>
        /// The OnTimestampEventLeft method.
        /// </summary>
        /// <param name="timeEvent">The <paramref name="timeEvent"/> parameter.</param>
        private static void OnTimestampEventLeft(MediaEvent timeEvent)
        {
            // Note that the timestamp is in UTC by default, so you must convert it to local time
            // if that is the format required.
            var timestamp = timeEvent.Timestamp.ToLocalTime().ToString("s");
            MainForm.Instance.lblTimeStampLeft.BeginInvoke((MethodInvoker) delegate
            {
                MainForm.Instance.lblTimeStampLeft.Text = timestamp;
            });
        }

        /// <summary>
        /// The OnTimestampEventRight method.
        /// </summary>
        /// <param name="timeEvent">The <paramref name="timeEvent"/> parameter.</param>
        private static void OnTimestampEventRight(MediaEvent timeEvent)
        {
            // Note that the timestamp is in UTC by default, so you must convert it to local time
            // if that is the format required.
            var timestamp = timeEvent.Timestamp.ToLocalTime().ToString("s");
            MainForm.Instance.lblTimeStampRight.BeginInvoke((MethodInvoker) delegate
            {
                MainForm.Instance.lblTimeStampRight.Text = timestamp;
            });
        }

        /// <summary>
        /// The _mediaControllerLeft field.
        /// </summary>  
        private MediaControl _mediaControllerLeft;

        /// <summary>
        /// The _mediaControllerRight field.
        /// </summary>  
        private MediaControl _mediaControllerRight;

        /// <summary>
        /// The _ptzCtrlLeft field.
        /// </summary>  
        private PtzController _ptzCtrlLeft;

        /// <summary>
        /// The _ptzCtrlRight field.
        /// </summary>  
        private PtzController _ptzCtrlRight;

        /// <summary>
        /// The _playingIndexLeft field.
        /// </summary>  
        private int _playingIndexLeft;

        /// <summary>
        /// The _playingIndexRight field.
        /// </summary>  
        private int _playingIndexRight;
    }
}
