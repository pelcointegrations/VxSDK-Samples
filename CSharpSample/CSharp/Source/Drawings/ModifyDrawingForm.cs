using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Windows.Forms;
using CPPCli;
using SDKSampleApp.Properties;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ModifyDrawingForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to modify a drawing.</remarks>
    public partial class ModifyDrawingForm : Form
    {
        /// <summary>
        /// Gets or sets the CurrentDrawing property.
        /// </summary>
        /// <value>The current drawing.</value>
        private Drawing CurrentDrawing { get; set; }

        /// <summary>
        /// Gets or sets the ImageUri property.
        /// </summary>
        /// <value>The URI to the drawing image.</value>
        private string ImageUri { get; set; }

        /// <summary>
        /// Gets or sets the NewDrawingName property.
        /// </summary>
        /// <value>The name to use for renaming the drawing.</value>
        private string NewDrawingName { get; set; }

        /// <summary>
        /// Gets or sets a value indicating whether the mouse is clicked.
        /// </summary>
        /// <value>The current mouse down status.</value>
        private bool IsMouseDown { get; set; }

        /// <summary>
        /// Gets or sets the LastX property.
        /// </summary>
        /// <value>The last X coordinate.</value>
        private int LastX { get; set; }

        /// <summary>
        /// Gets or sets the LastY property.
        /// </summary>
        /// <value>The last Y coordinate.</value>
        private int LastY { get; set; }

        /// <summary>
        /// Gets or sets the MarkersToDelete property.
        /// </summary>
        /// <value>The list of markers to delete on save.</value>
        private List<Marker> MarkersToDelete { get; set; }

        /// <summary>
        /// Gets or sets a value indicating whether the image should be deleted.
        /// </summary>
        /// <value>Indicates whether the image should be deleted or not.</value>
        private bool ShouldDeleteImage { get; set; }

        /// <summary>
        /// Gets or sets a value indicating whether the image should be set.
        /// </summary>
        /// <value>Indicates whether the image should be set or not.</value>
        private bool ShouldSetImage { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyDrawingForm" /> class.
        /// </summary>
        /// <param name="drawing">The drawing to edit.</param>
        public ModifyDrawingForm(Drawing drawing)
        {
            CurrentDrawing = drawing;
            MarkersToDelete = new List<Marker>();

            InitializeComponent();
            Text = string.Format("Edit {0}", CurrentDrawing.Name);
            pbxMain.AllowDrop = true;

            // Clone each item in the MainForm ListView and add it to lvDataSources.
            foreach (ListViewItem item in MainForm.Instance.lvDataSources.Items)
            {
                var ds = (DataSource)item.Tag;
                var lvItem = new ListViewItem(ds.Name);
                lvItem.SubItems.Add(ds.Number.ToString());
                lvItem.Tag = ds;
                lvDataSources.Items.Add(lvItem);
            }

            GetImage();
            Refresh();
        }

        /// <summary>
        /// The GetImage method.
        /// </summary>
        public async void GetImage()
        {
            var imageUri = CurrentDrawing.GetImageUri();
            if (!string.IsNullOrEmpty(imageUri))
            {
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

            var markers = CurrentDrawing.Markers;
            if (markers.Count == 0)
                return;

            foreach (var marker in markers)
                DisplayMarker(marker);
        }

        /// <summary>
        /// The DisplayMarker method.
        /// </summary>
        /// <param name="marker">The marker to display.</param>
        public void DisplayMarker(Marker marker)
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
                Tag = new KeyValuePair<Marker, float>(marker, marker.Direction),
                Location = new Point((int)adjustedX, (int)adjustedY),
                Image = Utilities.RotateImage(Resources.camera_online, marker.Direction)
            };

            AddPictureBox(pbx, marker.Name);
        }

        /// <summary>
        /// The DisplayNewMarker method.
        /// </summary>
        /// <param name="dataSource">The data source associated with the new marker.</param>
        /// <param name="location">The location of the new marker.</param>
        public void DisplayNewMarker(DataSource dataSource, Point location)
        {
            var marker = new NewMarker
            {
                Name = dataSource.Name,
                AssociatedDataSourceId = dataSource.Id
            };

            var pbx = new PictureBox
            {
                Tag = marker,
                Location = new Point(location.X - 16, location.Y - 16),
                Image = Resources.camera_online
            };

            AddPictureBox(pbx, dataSource.Name);
        }

        /// <summary>
        /// The AddPictureBox method.
        /// </summary>
        /// <param name="pictureBox">The picture box to add.</param>
        /// <param name="markerName">The name of the marker.</param>
        public void AddPictureBox(PictureBox pictureBox, string markerName)
        {
            pictureBox.BackColor = Color.Transparent;
            pictureBox.Size = new Size(32, 32);
            pictureBox.SizeMode = PictureBoxSizeMode.CenterImage;
            pictureBox.MouseClick += PictureBoxCamera_Click;
            pictureBox.MouseDown += PictureBoxCamera_MouseDown;
            pictureBox.MouseMove += PictureBoxCamera_MouseMove;
            pictureBox.MouseUp += PictureBoxCamera_MouseUp;

            var menuStrip = new ContextMenuStrip();
            var itemRemove = menuStrip.Items.Add("Remove camera");
            itemRemove.Tag = pictureBox;
            itemRemove.Click += ItemRemoveCamera_Click;
            var itemRotate = menuStrip.Items.Add("Rotate camera");
            itemRotate.Tag = pictureBox;
            itemRotate.Click += ItemRotateCamera_Click;
            pictureBox.ContextMenuStrip = menuStrip;

            var toolTip = new ToolTip();
            toolTip.SetToolTip(pictureBox, markerName);

            pbxMain.Controls.Add(pictureBox);
        }

        /// <summary>
        /// The PictureBoxCamera_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private static void PictureBoxCamera_Click(object sender, MouseEventArgs args)
        {
            if (args.Button != MouseButtons.Right)
                return;

            var pbx = sender as PictureBox;
            if (pbx != null)
                pbx.ContextMenuStrip.Show();
        }

        /// <summary>
        /// The IsDataSourceUsed method.
        /// </summary>
        /// <param name="dataSource">The data source to check.</param>
        /// <returns><c>true</c> if a marker exists with the associated data
        /// source, otherwise <c>false</c>.</returns>
        private bool IsDataSourceUsed(DataSource dataSource)
        {
            foreach (var pictureBoxCamera in pbxMain.Controls.OfType<PictureBox>())
            {
                if (pictureBoxCamera.Tag.GetType() == typeof(NewMarker))
                {
                    var newMarker = pictureBoxCamera.Tag as NewMarker;
                    if (newMarker == null)
                        return false;

                    if (dataSource.Id == newMarker.AssociatedDataSourceId)
                        return true;
                }
                else
                {
                    var kvPair = (KeyValuePair<Marker, float>)pictureBoxCamera.Tag;
                    var markerDataSource = kvPair.Key.GetAssociation();
                    if (markerDataSource == null)
                        continue;

                    if (dataSource.Id == markerDataSource.Id)
                        return true;
                }
            }

            return false;
        }

        /// <summary>
        /// The ButtonClearImage_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonClearImage_Click(object sender, EventArgs args)
        {
            ShouldDeleteImage = true;
            pbxMain.Image = null;
            Refresh();
        }

        /// <summary>
        /// The ButtonRename_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRename_Click(object sender, EventArgs args)
        {
            var prompt = new Form()
            {
                Width = 500,
                Height = 150,
                FormBorderStyle = FormBorderStyle.FixedDialog,
                Text = @"Enter new name:",
                StartPosition = FormStartPosition.CenterScreen
            };

            var textLabel = new Label
            {
                Left = 50,
                Top = 20,
                Text = @"Rename Drawing"
            };

            var textBox = new TextBox
            {
                Left = 50,
                Top = 50,
                Width = 400
            };

            var confirmation = new Button
            {
                Text = @"Ok",
                Left = 350,
                Width = 100,
                Top = 70,
                DialogResult = DialogResult.OK
            };

            confirmation.Click += (s, e) => { prompt.Close(); };
            prompt.Controls.Add(textBox);
            prompt.Controls.Add(confirmation);
            prompt.Controls.Add(textLabel);
            prompt.AcceptButton = confirmation;

            var name = prompt.ShowDialog() == DialogResult.OK ? textBox.Text : string.Empty;
            if (string.IsNullOrEmpty(name))
                return;

            Text = string.Format("Edit {0}", name);
            NewDrawingName = name;
        }

        /// <summary>
        /// The ButtonSave_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSave_Click(object sender, EventArgs args)
        {
            if (ShouldDeleteImage)
                CurrentDrawing.DeleteImage();

            if (ShouldSetImage)
                CurrentDrawing.SetImage(ImageUri);

            if (!string.IsNullOrEmpty(NewDrawingName))
                CurrentDrawing.Name = NewDrawingName;

            foreach (var marker in MarkersToDelete)
                CurrentDrawing.DeleteMarker(marker);

            foreach (var pictureBoxCamera in pbxMain.Controls.OfType<PictureBox>())
            {
                if (pictureBoxCamera.Tag.GetType() == typeof(NewMarker))
                {
                    var newMarker = pictureBoxCamera.Tag as NewMarker;
                    if (newMarker == null)
                        return;

                    var newX = (pictureBoxCamera.Location.X + 16) * 3;
                    var newY = (pictureBoxCamera.Location.Y + 16) * 3;
                    newMarker.X = newX;
                    newMarker.Y = newY;

                    CurrentDrawing.AddMarker(newMarker);
                }
                else
                {
                    if (pictureBoxCamera.Tag.GetType() != typeof(KeyValuePair<Marker, float>))
                        return;

                    var kvPair = (KeyValuePair<Marker, float>)pictureBoxCamera.Tag;
                    var marker = kvPair.Key;
                    var newX = (pictureBoxCamera.Location.X + 16) * 3;
                    var newY = (pictureBoxCamera.Location.Y + 16) * 3;
                    marker.SetCoordinates(newX, newY);
                    marker.Direction = kvPair.Value;
                }
            }
        }

        /// <summary>
        /// The ButtonSetImage_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSetImage_Click(object sender, EventArgs args)
        {
            if (ofdSelectImage.ShowDialog() != DialogResult.OK)
                return;

            ImageUri = ofdSelectImage.FileName;
            ShouldSetImage = true;
            ShouldDeleteImage = false;
            pbxMain.Image = Image.FromFile(ofdSelectImage.FileName);
            Refresh();
        }

        /// <summary>
        /// The ItemRemoveCamera_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ItemRemoveCamera_Click(object sender, EventArgs args)
        {
            var toolStripItem = (ToolStripItem)sender;
            var pictureBoxCamera = toolStripItem.Tag as PictureBox;
            if (pictureBoxCamera == null)
                return;

            if (pictureBoxCamera.Tag.GetType() != typeof(NewMarker))
            {
                var kvPair = (KeyValuePair<Marker, float>)pictureBoxCamera.Tag;
                MarkersToDelete.Add(kvPair.Key);
            }

            pictureBoxCamera.Dispose();
            Refresh();
        }

        /// <summary>
        /// The ItemRotateCamera_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ItemRotateCamera_Click(object sender, EventArgs args)
        {
            var toolStripItem = (ToolStripItem)sender;
            var pictureBoxCamera = toolStripItem.Tag as PictureBox;
            if (pictureBoxCamera == null)
                return;

            decimal rotationValue;
            if (pictureBoxCamera.Tag.GetType() == typeof(NewMarker))
            {
                var newMarker = (NewMarker)pictureBoxCamera.Tag;
                if (newMarker == null)
                    return;

                rotationValue = (decimal)newMarker.Direction;
                InputBox.Show("Rotate Camera", "Enter rotation value:", ref rotationValue, 0, 359);
                newMarker.Direction = (float)rotationValue;
            }
            else
            {
                var kvPair = (KeyValuePair<Marker, float>)pictureBoxCamera.Tag;
                rotationValue = (decimal)kvPair.Value;
                InputBox.Show("Rotate Camera", "Enter rotation value:", ref rotationValue, 0, 359);
                pictureBoxCamera.Tag = new KeyValuePair<Marker, float>(kvPair.Key, (float)rotationValue);
            }

            pictureBoxCamera.Image = Utilities.RotateImage(Resources.camera_online, (float)rotationValue);
            Refresh();
        }

        /// <summary>
        /// The ListViewDataSources_OnItemDrag method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ListViewDataSources_OnItemDrag(object sender, ItemDragEventArgs args)
        {
            DoDragDrop(args.Item, DragDropEffects.Move);
        }

        /// <summary>
        /// The PictureBoxCamera_MouseDown method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void PictureBoxCamera_MouseDown(object sender, MouseEventArgs args)
        {
            IsMouseDown = true;

            LastX = args.X;
            LastY = args.Y;
        }

        /// <summary>
        /// The PictureBoxCamera_MouseMove method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void PictureBoxCamera_MouseMove(object sender, MouseEventArgs args)
        {
            var pbx = (PictureBox)sender;
            if (!IsMouseDown)
                return;

            pbx.Location = new Point(pbx.Location.X - (LastX - args.X), pbx.Location.Y - (LastY - args.Y));
            Refresh();
        }

        /// <summary>
        /// The PictureBoxCamera_MouseUp method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void PictureBoxCamera_MouseUp(object sender, MouseEventArgs args)
        {
            IsMouseDown = false;
        }

        /// <summary>
        /// The PictureBoxMain_OnDragDrop method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void PictureBoxMain_OnDragDrop(object sender, DragEventArgs args)
        {
            var pbxPoint = pbxMain.PointToClient(new Point(args.X, args.Y));
            if (!args.Data.GetDataPresent(typeof(ListViewItem)))
                return;

            var lvItem = args.Data.GetData(typeof(ListViewItem)) as ListViewItem;
            if (lvItem != null)
            {
                var ds = lvItem.Tag as DataSource;
                if (ds == null)
                    return;

                if (IsDataSourceUsed(ds))
                {
                    MessageBox.Show(this, string.Format("Camera {0} already in use.", ds.Name));
                    return;
                }

                DisplayNewMarker(ds, pbxPoint);
            }

            Refresh();
        }

        /// <summary>
        /// The PictureBoxMain_OnDragEnter method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void PictureBoxMain_OnDragEnter(object sender, DragEventArgs args)
        {
            if (args.Data.GetDataPresent(typeof(ListViewItem)))
            {
                args.Effect = DragDropEffects.Move;
            }
        }
    }
}
