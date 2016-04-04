using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddUserForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create a new user.</remarks>
    public partial class AddUserForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddUserForm" /> class.
        /// </summary>
        public AddUserForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The ButtonOk_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonOk_Click(object sender, EventArgs args)
        {
            try
            {
                var newUser = new NewUser
                {
                    Name = tbxName.Text,
                    Password = tbxPassword.Text,
                    Domain = tbxDomain.Text,
                    MustChangePassword = ckbxRequireChange.Checked
                };

                MainForm.CurrentSystem.AddUser(newUser);
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog(string.Format("Error creating user: {0}", ex.Message));
                throw;
            }
        }
    }
}
