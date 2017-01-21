using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ModifyTagForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to modify a tag.</remarks>
    public partial class ModifyTagForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedTag property.
        /// </summary>
        /// <value>The currently selected tag.</value>
        private Tag SelectedTag { get; set; }

        /// <summary>
        /// Gets or sets the CurrentDeviceList property.
        /// </summary>
        /// <value>The list of devices for the currently selected tag.</value>
        private List<string> CurrentDeviceList { get; set; }

        /// <summary>
        /// Gets or sets the CurrentSourceList property.
        /// </summary>
        /// <value>The list of sources for the currently selected tag.</value>
        private List<string> CurrentSourceList { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyTagForm" /> class.
        /// </summary>
        /// <param name="tag">The <paramref name="tag"/> parameter.</param>
        public ModifyTagForm(Tag tag)
        {
            InitializeComponent();
            SelectedTag = tag;
            PopulateDataSources();
            PopulateDevices();
        }

        /// <summary>
        /// The ButtonSave_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSave_Click(object sender, EventArgs args)
        {
            LinkDataSources();
            LinkDevices();
        }

        /// <summary>
        /// The LinkDataSources method.
        /// </summary>
        private void LinkDataSources()
        {
            var linkList = new List<DataSource>();
            var unlinkList = new List<DataSource>();

            foreach (ListViewItem item in lvTagSources.Items)
            {
                var dataSource = (DataSource)item.Tag;

                if (item.Checked)
                {
                    if (!CurrentSourceList.Any(s => dataSource.Id.Contains(s)))
                        linkList.Add(dataSource);
                }
                else
                {
                    if (CurrentSourceList.Any(s => dataSource.Id.Contains(s)))
                        unlinkList.Add(dataSource);
                }
            }

            if (linkList.Count > 0)
                SelectedTag.Link(linkList);

            if (unlinkList.Count > 0)
                SelectedTag.Unlink(unlinkList);
        }

        /// <summary>
        /// The LinkDevices method.
        /// </summary>
        private void LinkDevices()
        {
            var linkList = new List<Device>();
            var unlinkList = new List<Device>();

            foreach (ListViewItem item in lvTagDevices.Items)
            {
                var device = (Device)item.Tag;

                if (item.Checked)
                {
                    if (!CurrentDeviceList.Any(s => device.Id.Contains(s)))
                        linkList.Add(device);
                }
                else
                {
                    if (CurrentDeviceList.Any(s => device.Id.Contains(s)))
                        unlinkList.Add(device);
                }
            }

            if (linkList.Count > 0)
                SelectedTag.Link(linkList);

            if (unlinkList.Count > 0)
                SelectedTag.Unlink(unlinkList);
        }

        /// <summary>
        /// The PopulateDataSources method.
        /// </summary>
        private void PopulateDataSources()
        {
            CurrentSourceList = new List<string>();
            foreach (var dataSource in SelectedTag.LinkedDataSources)
                CurrentSourceList.Add(dataSource.Id);

            // Clone each item in the MainForm ListView and add it to lvDataSources.
            foreach (var dataSource in MainForm.CurrentDataSources)
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(dataSource.Name);
                lvItem.Tag = dataSource;
                if (CurrentSourceList.Any(s => dataSource.Id.Contains(s)))
                    lvItem.Checked = true;

                lvTagSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The PopulateDataSources method.
        /// </summary>
        private void PopulateDevices()
        {
            CurrentDeviceList = new List<string>();
            foreach (var device in SelectedTag.LinkedDevices)
                CurrentDeviceList.Add(device.Id);

            // Clone each item in the MainForm ListView and add it to lvDataSources.
            foreach (var device in MainForm.CurrentDevices)
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(device.Name);
                lvItem.Tag = device;
                if (CurrentDeviceList.Any(s => device.Id.Contains(s)))
                    lvItem.Checked = true;

                lvTagDevices.Items.Add(lvItem);
            }
        }
    }
}
