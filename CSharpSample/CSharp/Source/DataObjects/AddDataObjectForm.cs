using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The AddDataObjectForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to create a new data object.</remarks>
    public partial class AddDataObjectForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="AddDataObjectForm" /> class.
        /// </summary>
        public AddDataObjectForm()
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
                var newDataObject = new NewDataObject
                {
                    ClientType = tbxClientType.Text,
                    IsPrivate = ckbxPrivate.Checked,
                    Data = tbxData.Text
                };

                MainForm.CurrentSystem.AddDataObject(newDataObject);
            }
            catch (Exception ex)
            {
                MainForm.Instance.WriteToLog(string.Format("Error creating data object: {0}", ex.Message));
                throw;
            }
        }
    }
}
