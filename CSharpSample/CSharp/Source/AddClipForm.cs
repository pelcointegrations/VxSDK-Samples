using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddClipForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create a new
    /// clip entry in the <see cref="NewExportForm"/> AvailableClips list view.</remarks>
    public partial class AddClipForm : Form
    {
        /// <summary>
        /// Gets the SelectedClip property.
        /// </summary>
        /// <value>The Clip contained in the Tag property of the selected clip
        /// in the <see cref="NewExportForm"/> AvailableClips list view.</value>
        private static Clip SelectedClip
        {
            get
            {
                if (NewExportForm.Instance.lvAvailableClips.SelectedItems[0] != null)
                {
                    return (Clip)NewExportForm.Instance.lvAvailableClips.SelectedItems[0].Tag;
                }

                return null;
            }
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AddClipForm" /> class.
        /// </summary>    
        public AddClipForm()
        {
            InitializeComponent();

            if (SelectedClip == null) 
                return;

            // Get the start and end time of the selected clip.
            var startTime = SelectedClip.StartTime.ToLocalTime();
            var endTime = SelectedClip.EndTime.ToLocalTime();

            // Set up the DateTimePickers to only allow values within the selected 
            // clips time frame.
            dtpStartDate.MinDate = startTime;
            dtpStartDate.MaxDate = endTime;
            dtpStartDate.Value = startTime;

            dtpEndDate.MinDate = startTime;
            dtpEndDate.MaxDate = endTime;
            dtpEndDate.Value = endTime;
        }

        /// <summary>
        /// The ButtonAdd_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter</param>
        /// <param name="args">The <paramref name="args"/> parameter</param>
        /// <remarks>Uses the settings to add a new entry to the 
        /// <see cref="NewExportForm"/> AvailableClips list view.</remarks>
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            var newExportClip = new NewExportClip
            {
                DataSourceId = SelectedClip.Id,
                StartTime = dtpStartDate.Value.ToUniversalTime(),
                EndTime = dtpEndDate.Value.ToUniversalTime()
            };

            var lvItem = new ListViewItem(SelectedClip.EventType.ToString());
            lvItem.SubItems.Add(newExportClip.StartTime.ToLocalTime().ToString("s"));
            lvItem.SubItems.Add(newExportClip.EndTime.ToLocalTime().ToString("s"));
            lvItem.Tag = newExportClip;
            NewExportForm.Instance.lvAddedClips.Items.Add(lvItem);
            Close();
        }
    }
}
