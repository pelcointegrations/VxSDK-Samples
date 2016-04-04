using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ModifyRolePrivilegesForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to modify the privileges
    /// of the selected role.</remarks>
    public partial class ModifyRolePrivilegesForm : Form
    {
        /// <summary>
        /// Gets the ComboBoxes property.
        /// </summary>
        /// <value>A list of the combo boxes on the form.</value>
        private IEnumerable<ComboBox> ComboBoxes
        {
            get { return tlpLeft.Controls.OfType<ComboBox>().Concat(tlpRight.Controls.OfType<ComboBox>()); }
        }

        /// <summary>
        /// Gets or sets a value indicating whether the UI is initialized.
        /// </summary>
        /// <value>Indicates whether the UI has been initialized or not.</value>
        private bool IsInitialized { get; set; }

        /// <summary>
        /// Gets or sets the OriginalIndex property.
        /// </summary>
        /// <value>The original index for a combo box.</value>
        private int OriginalIndex { get; set; }

        /// <summary>
        /// Gets or sets the SelectedRole property.
        /// </summary>
        /// <value>The currently selected role.</value>
        private Role SelectedRole { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyRolePrivilegesForm" /> class.
        /// </summary>
        /// <param name="role">The selected role.</param>
        public ModifyRolePrivilegesForm(Role role)
        {
            InitializeComponent();
            SelectedRole = role;
            foreach (var comboBox in ComboBoxes)
                comboBox.SelectedIndex = 0;

            PopulateRoles();
            IsInitialized = true;
        }

        /// <summary>
        /// The GetButtonByName method.
        /// </summary>
        /// <param name="name">The button name.</param>
        /// <returns>A <c>Button</c> if found, otherwise <c>null</c>.</returns>
        private Button GetButtonByName(string name)
        {
            var allButtons = tlpLeft.Controls.OfType<Button>().Concat(tlpRight.Controls.OfType<Button>());
            return allButtons.FirstOrDefault(btn => btn.Name == name);
        }

        /// <summary>
        /// The PopulateRoles method.
        /// </summary>
        private void PopulateRoles()
        {
            foreach (var privilege in SelectedRole.Privileges)
                EnableRowControls(privilege);
        }

        /// <summary>
        /// The EnableRowControls method.
        /// </summary>
        /// <param name="privilege">The privilege to enable the row for.</param>
        private void EnableRowControls(Privilege privilege)
        {
            var comboBox = ComboBoxes.FirstOrDefault(cbx => cbx.Name == "cbx" + privilege.PermissionId);
            if (comboBox == null)
                return;

            var priorityButton = GetButtonByName("pri" + privilege.PermissionId);
            var sourceButton = GetButtonByName("btn" + privilege.PermissionId);
            comboBox.SelectedIndex = privilege.IsRestricted ? 2 : 1;
            priorityButton.Text = privilege.Priority.ToString();
            priorityButton.Enabled = true;
            priorityButton.Tag = privilege;
            if (sourceButton != null)
                sourceButton.Enabled = privilege.IsRestricted;

            HandleRelations(comboBox);
        }

        /// <summary>
        /// The TableLayoutPanel_CellPaint method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void TableLayoutPanel_CellPaint(object sender, TableLayoutCellPaintEventArgs args)
        {
            if (args.Row % 2 != 0)
                return;

            var g = args.Graphics;
            var r = args.CellBounds;
            g.FillRectangle(Brushes.Gainsboro, r);
        }

        /// <summary>
        /// The ModifyRolePrivilegesForm_Load method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ModifyRolePrivilegesForm_Load(object sender, EventArgs args)
        {
            tlpLeft.CellPaint += TableLayoutPanel_CellPaint;
            tlpRight.CellPaint += TableLayoutPanel_CellPaint;
        }

        /// <summary>
        /// The ButtonPriority_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonPriority_Click(object sender, EventArgs args)
        {
            var button = (Button)sender;
            var privilege = (Privilege)button.Tag;

            decimal value = privilege.Priority;
            if (InputBox.Show("Priority", "Priority:", ref value, 1, 250) != DialogResult.OK)
                return;

            privilege.Priority = (int)value;
            button.Text = value.ToString();
        }

        /// <summary>
        /// The ButtonSources_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSources_Click(object sender, EventArgs args)
        {
            var button = (Button)sender;
            var buttonName = button.Name.Substring(3);
            var priorityButton = GetButtonByName("pri" + buttonName);
            var privilege = (Privilege)priorityButton.Tag;

            // Show the ModifyPrivilegeSourcesForm dialog.
            using (var modifyPrivilegeSourcesForm = new ModifyPrivilegeSourcesForm(privilege))
            {
                modifyPrivilegeSourcesForm.ShowDialog();
            }
        }

        /// <summary>
        /// The ComboBox_SelectedIndexChanged method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ComboBox_SelectedIndexChanged(object sender, EventArgs args)
        {
            var comboBox = (ComboBox)sender;
            if (!IsInitialized)
                return;

            if (comboBox.SelectedIndex == OriginalIndex)
                return;

            var comboBoxName = comboBox.Name.Substring(3);
            var priorityButton = GetButtonByName("pri" + comboBoxName);
            HandleRelations(comboBox);

            if (comboBox.SelectedIndex == 0)
            {
                var privilege = (Privilege)priorityButton.Tag;
                var result = SelectedRole.RemovePrivilege(privilege);
                if (result != Results.Value.OK)
                {
                    comboBox.SelectedIndex = OriginalIndex;
                    return;
                }

                priorityButton.Tag = null;
            }
            else if (priorityButton.Tag == null)
            {
                var newPrivilege = new NewPrivilege();
                var permission = (Privilege.PermissionIds)Enum.Parse(typeof(Privilege.PermissionIds), comboBoxName);
                newPrivilege.PermissionId = permission;
                newPrivilege.Priority = 25;
                var result = SelectedRole.AddPrivilege(newPrivilege);
                if (result != Results.Value.OK)
                {
                    comboBox.SelectedIndex = OriginalIndex;
                    return;
                }

                var privilege = SelectedRole.Privileges.First(priv => priv.PermissionId == permission);
                privilege.IsRestricted = comboBox.SelectedIndex == 2;
                priorityButton.Text = @"25";
                priorityButton.Tag = privilege;
            }
            else
            {
                var privilege = (Privilege)priorityButton.Tag;
                privilege.IsRestricted = comboBox.SelectedIndex == 2;
            }

            priorityButton.Enabled = comboBox.SelectedIndex != 0;
            var sourceButton = GetButtonByName("btn" + comboBoxName);
            if (sourceButton != null)
                sourceButton.Enabled = comboBox.SelectedIndex == 2;
        }

        /// <summary>
        /// The HandleRelations method.
        /// </summary>
        /// <param name="comboBox">The combo box to handle.</param>
        private void HandleRelations(ListControl comboBox)
        {
            var enabled = comboBox.SelectedIndex > 0;
            var comboBoxName = comboBox.Name.Substring(3);
            var permission = (Privilege.PermissionIds)Enum.Parse(typeof(Privilege.PermissionIds), comboBoxName);

            switch (permission)
            {
                case Privilege.PermissionIds.ViewVideoSources:
                    if (!enabled)
                    {
                        cbxLaunchSavedViewsRemotely.SelectedIndex = 0;
                        cbxCreateSystemBookmarks.SelectedIndex = 0;
                        cbxUsePtzMode.SelectedIndex = 0;
                    }

                    cbxLaunchSavedViewsRemotely.Enabled = enabled;
                    cbxCreateSystemBookmarks.Enabled = enabled;
                    cbxUsePtzMode.Enabled = enabled;
                    break;
                case Privilege.PermissionIds.CreateSystemBookmarks:
                    if (!enabled)
                        cbxDeleteSystemBookmarks.SelectedIndex = 0;

                    cbxDeleteSystemBookmarks.Enabled = enabled;
                    break;
                case Privilege.PermissionIds.UsePtzMode:
                    if (!enabled)
                        cbxLockPtzMode.SelectedIndex = 0;

                    cbxLockPtzMode.Enabled = enabled;
                    break;
                case Privilege.PermissionIds.ViewRecordedVideo:
                    if (!enabled)
                        cbxExportMediaClips.SelectedIndex = 0;

                    cbxExportMediaClips.Enabled = enabled;
                    break;
                case Privilege.PermissionIds.ExportMediaClips:
                    if (!enabled)
                        cbxDeleteExports.SelectedIndex = 0;

                    cbxDeleteExports.Enabled = enabled;
                    break;
                case Privilege.PermissionIds.UseMap:
                    if (!enabled)
                        cbxViewMaps.SelectedIndex = 0;

                    cbxViewMaps.Enabled = enabled;
                    break;
                case Privilege.PermissionIds.ViewMaps:
                    if (!enabled)
                    {
                        cbxManageMapFiles.SelectedIndex = 0;
                        cbxPlaceCamerasOnMap.SelectedIndex = 0;
                    }

                    cbxManageMapFiles.Enabled = enabled;
                    cbxPlaceCamerasOnMap.Enabled = enabled;
                    break;
                case Privilege.PermissionIds.ManageUserAccounts:
                    if (!enabled)
                    {
                        cbxManageAggregatorAccount.SelectedIndex = 0;
                        cbxAssignRolesToUsers.SelectedIndex = 0;
                    }

                    cbxManageAggregatorAccount.Enabled = enabled;
                    cbxAssignRolesToUsers.Enabled = enabled;
                    break;
            }
        }

        /// <summary>
        /// The ComboBox_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ComboBox_Click(object sender, EventArgs args)
        {
            var cbx = (ComboBox)sender;
            OriginalIndex = cbx.SelectedIndex;
        }
    }
}
