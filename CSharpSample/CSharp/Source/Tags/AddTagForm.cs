using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddTagForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create a new tag.</remarks>
    public partial class AddTagForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddTagForm" /> class.
        /// </summary>
        public AddTagForm()
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
                var newTag = new NewTag { IsPublic = ckbxIsPublic.Checked, Name = txbxName.Text };
                MainForm.CurrentSystem.CreateTag(newTag);
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog(string.Format("Error creating tag: {0}", ex.Message));
                throw;
            }
        }
    }
}
