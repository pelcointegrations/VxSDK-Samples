using System;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ModifyDataSourceForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to modify a dataSource.</remarks>
    public partial class ModifyDataSourceForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedDataSource property.
        /// </summary>
        /// <value>The currently selected dataSource.</value>
        private DataSource SelectedDataSource { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ModifyDataSourceForm" /> class.
        /// </summary>
        /// <param name="dataSource">The <paramref name="dataSource"/> parameter.</param>
        public ModifyDataSourceForm(DataSource dataSource)
        {
            InitializeComponent();
            SelectedDataSource = dataSource;
            tbxName.Text = dataSource.Name;
            nudNumber.Value = dataSource.Number;
        }

        /// <summary>
        /// The ButtonSave_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonSave_Click(object sender, EventArgs args)
        {
            if (!string.IsNullOrEmpty(tbxName.Text) && SelectedDataSource.Name != tbxName.Text)
                SelectedDataSource.Name = tbxName.Text;

            if (SelectedDataSource.Number != (int)nudNumber.Value)
                SelectedDataSource.Number = (int)nudNumber.Value;
        }
    }
}
