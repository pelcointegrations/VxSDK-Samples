using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ModifyNotificationsForm class.
    /// </summary>
    /// <remarks>
    /// Provides a dialog window that allows the user to modify the notifications for a situation.
    /// </remarks>
    public partial class ModifyNotificationsForm : Form
    {
        private Situation CurrentSituation { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyNotificationsForm" /> class.
        /// </summary>
        /// <param name="situation">The situation to modify.</param>
        public ModifyNotificationsForm(Situation situation)
        {
            InitializeComponent();
            CurrentSituation = situation;
        }

        /// <summary>
        /// The PopulateRoles method.
        /// </summary>
        public void PopulateRoles()
        {
            clbRoles.Items.Clear();
            CurrentSituation.Refresh();

            // Get the existing roles from the VideoXpert system and add them to the list box.
            var roles = MainForm.CurrentSystem.GetRoles();
            var table = new DataTable();
            table.Columns.Add(new DataColumn("OBJECT", typeof(Role)));
            table.Columns.Add(new DataColumn("NAME", typeof(string)));
            foreach (var role in roles.Where(role => !role.IsReadOnly || role.Name == "administrator"))
                table.Rows.Add(role, role.Name);

            clbRoles.DataSource = table;
            clbRoles.ValueMember = "OBJECT";
            clbRoles.DisplayMember = "NAME";

            var index = 0;
            var indexes = new List<int>();
            foreach (DataRowView item in clbRoles.Items)
            {
                indexes.AddRange(from notification in CurrentSituation.Notifications from role in notification.Roles
                                     where role.Name == (string)item["NAME"] select index);
                index++;
            }

            foreach (var i in indexes)
                clbRoles.SetItemChecked(i, true);
        }

        /// <summary>
        /// The ButtonSave_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonSave_Click(object sender, EventArgs args)
        {
            var roles = (from DataRowView view in clbRoles.CheckedItems select (Role)view["OBJECT"]).ToList();

            foreach (var remNotification in CurrentSituation.Notifications)
                CurrentSituation.RemoveNotification(remNotification);

            var newNotification = new NewNotification();
            foreach (var role in roles)
                newNotification.Roles.Add(role);

            var notification = MainForm.CurrentSystem.CreateNotification(newNotification);
            if (notification == null) 
                return;

            CurrentSituation.AddNotification(notification);
        }
    }
}
