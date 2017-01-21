using System;
using System.Data;
using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddNotificationForm class.
    /// </summary>
    /// <remarks>
    /// Provides a dialog window that allows the user to add a notification to the VideoXpert system.
    /// </remarks>
    public partial class AddNotificationForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddNotificationForm" /> class.
        /// </summary>
        public AddNotificationForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The PopulateRoles method.
        /// </summary>
        public void PopulateRoles()
        {
            clbRoles.Items.Clear();

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
        }

        /// <summary>
        /// The ButtonAdd_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param> 
        private void ButtonAdd_Click(object sender, EventArgs args)
        {
            var roles = (from DataRowView view in clbRoles.CheckedItems select (Role)view["OBJECT"]).ToList();

            var newNotification = new NewNotification();
            foreach (var role in roles)
                newNotification.Roles.Add(role);

            MainForm.CurrentSystem.CreateNotification(newNotification);
        }
    }
}
