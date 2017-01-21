using System;
using System.Drawing;
using System.IO;
using System.Net;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ViewDrawingForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to view a drawing.</remarks>
    public partial class ViewDrawingForm : Form
    {
        /// <summary>
        /// Gets or sets the CurrentDrawing property.
        /// </summary>
        /// <value>The current drawing.</value>
        private Drawing CurrentDrawing { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ViewDrawingForm" /> class.
        /// </summary>
        /// <param name="drawing">The drawing to view.</param>
        public ViewDrawingForm(Drawing drawing)
        {
            InitializeComponent();

            CurrentDrawing = drawing;
            GetImage();
            GetMarkers();
            Refresh();
        }

        /// <summary>
        /// The GetImage method.
        /// </summary>
        public async void GetImage()
        {
            var imageUri = CurrentDrawing.GetImageUri();
            if (string.IsNullOrEmpty(imageUri))
                return;

            var response = await Utilities.SendRequest(new Uri(imageUri));
            if (response.StatusCode != HttpStatusCode.OK)
            {
                MessageBox.Show(string.Format("Unable to get image, server returned {0}.", response.StatusCode));
                return;
            }

            var bytes = await response.Content.ReadAsByteArrayAsync();
            using (var ms = new MemoryStream(bytes))
            {
                pbxMain.Image = Image.FromStream(ms);
            }
        }

        /// <summary>
        /// The GetMarkers method.
        /// </summary>
        public void GetMarkers()
        {
            var markers = CurrentDrawing.Markers;
            if (markers.Count == 0)
                return;

            foreach (var marker in markers)
            {
                var adjustedX = marker.X / 3;
                var adjustedY = marker.Y / 3;

                if (adjustedX >= 617)
                    adjustedX = 617;
                else
                    adjustedX = adjustedX - 16;

                if (adjustedY >= 630)
                    adjustedY = 630;
                else
                    adjustedY = adjustedY - 16;

                var pbx = new PictureBox
                {
                    Location = new Point((int)adjustedX, (int)adjustedY),
                    BackColor = Color.Transparent,
                    Image = Utilities.RotateImage(Properties.Resources.camera_online, marker.Direction),
                    Size = new Size(32, 32),
                    SizeMode = PictureBoxSizeMode.CenterImage,
                    Tag = marker
                };

                var toolTip = new ToolTip();
                toolTip.SetToolTip(pbx, marker.Name);

                pbxMain.Controls.Add(pbx);
            }
        }
    }
}
