using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ModifyPrivilegeSourcesForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to modify the linked sources
    /// of the selected privilege.</remarks>
    public partial class ModifyPrivilegeSourcesForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedPrivilege property.
        /// </summary>
        /// <value>The currently selected privilege.</value>
        private Privilege SelectedPrivilege { get; set; }

        /// <summary>
        /// Gets or sets the _currentSourceList property.
        /// </summary>
        /// <value>The list of sources for the currently selected schedule.</value>
        private List<string> CurrentSourceList { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyPrivilegeSourcesForm" /> class.
        /// </summary>
        /// <param name="privilege">The selected privilege.</param>
        public ModifyPrivilegeSourcesForm(Privilege privilege)
        {
            InitializeComponent();

            SelectedPrivilege = privilege;

            CurrentSourceList = new List<string>();
            if (SelectedPrivilege.ResourceType == Privilege.ResourceTypes.DataSource)
                PopulateDataSources();

            if (SelectedPrivilege.ResourceType == Privilege.ResourceTypes.Device)
                PopulateDevices();

            if (SelectedPrivilege.ResourceType == Privilege.ResourceTypes.User)
                PopulateUsers();
        }

        /// <summary>
        /// The PopulateDataSources method.
        /// </summary>
        private void PopulateDataSources()
        {
            foreach (var dataSource in SelectedPrivilege.LinkedDataSources)
                CurrentSourceList.Add(dataSource.Id);

            // Add each data source to lvPrivilegeSources.
            foreach (var dataSource in MainForm.CurrentDataSources)
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(dataSource.Name);
                lvItem.Tag = dataSource;
                if (CurrentSourceList.Any(s => dataSource.Id.Contains(s)))
                    lvItem.Checked = true;

                lvPrivilegeSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The PopulateDevices method.
        /// </summary>
        private void PopulateDevices()
        {
            foreach (var device in SelectedPrivilege.LinkedDevices)
                CurrentSourceList.Add(device.Id);

            // Add each device to lvPrivilegeSources.
            foreach (var device in MainForm.CurrentDevices)
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(device.Name);
                lvItem.Tag = device;
                if (CurrentSourceList.Any(s => device.Id.Contains(s)))
                    lvItem.Checked = true;

                lvPrivilegeSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The PopulateUsers method.
        /// </summary>
        private void PopulateUsers()
        {
            foreach (var user in SelectedPrivilege.LinkedUsers)
                CurrentSourceList.Add(user.Id);

            // Add each user to lvPrivilegeSources.
            foreach (var user in MainForm.CurrentSystem.GetUsers())
            {
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(user.Name);
                lvItem.Tag = user;
                if (CurrentSourceList.Any(s => user.Id.Contains(s)))
                    lvItem.Checked = true;

                lvPrivilegeSources.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonSave_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>  
        private void ButtonSave_Click(object sender, EventArgs args)
        {
            if (SelectedPrivilege.ResourceType == Privilege.ResourceTypes.DataSource)
                LinkDataSources();

            if (SelectedPrivilege.ResourceType == Privilege.ResourceTypes.Device)
                LinkDevices();

            if (SelectedPrivilege.ResourceType == Privilege.ResourceTypes.User)
                LinkUsers();
        }

        /// <summary>
        /// The LinkDataSources method.
        /// </summary>
        private void LinkDataSources()
        {
            var linkList = new List<DataSource>();
            var unlinkList = new List<DataSource>();

            foreach (ListViewItem item in lvPrivilegeSources.Items)
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
                SelectedPrivilege.Link(linkList);

            if (unlinkList.Count > 0)
                SelectedPrivilege.Unlink(unlinkList);

            SelectedPrivilege.IsRestricted = SelectedPrivilege.LinkedDataSources.Count > 0;
        }

        /// <summary>
        /// The LinkDevices method.
        /// </summary>
        private void LinkDevices()
        {
            var linkList = new List<Device>();
            var unlinkList = new List<Device>();

            foreach (ListViewItem item in lvPrivilegeSources.Items)
            {
                var device = (Device)item.Tag;

                if (item.Checked)
                {
                    if (!CurrentSourceList.Any(s => device.Id.Contains(s)))
                        linkList.Add(device);
                }
                else
                {
                    if (CurrentSourceList.Any(s => device.Id.Contains(s)))
                        unlinkList.Add(device);
                }
            }

            if (linkList.Count > 0)
                SelectedPrivilege.Link(linkList);

            if (unlinkList.Count > 0)
                SelectedPrivilege.Unlink(unlinkList);

            SelectedPrivilege.IsRestricted = SelectedPrivilege.LinkedDevices.Count > 0;
        }

        /// <summary>
        /// The LinkUsers method.
        /// </summary>
        private void LinkUsers()
        {
            var linkList = new List<User>();
            var unlinkList = new List<User>();

            foreach (ListViewItem item in lvPrivilegeSources.Items)
            {
                var user = (User)item.Tag;

                if (item.Checked)
                {
                    if (!CurrentSourceList.Any(s => user.Id.Contains(s)))
                        linkList.Add(user);
                }
                else
                {
                    if (CurrentSourceList.Any(s => user.Id.Contains(s)))
                        unlinkList.Add(user);
                }
            }

            if (linkList.Count > 0)
                SelectedPrivilege.Link(linkList);

            if (unlinkList.Count > 0)
                SelectedPrivilege.Unlink(unlinkList);

            SelectedPrivilege.IsRestricted = SelectedPrivilege.LinkedUsers.Count > 0;
        }
    }
}
