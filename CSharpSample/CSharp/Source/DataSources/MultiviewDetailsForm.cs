using System.Linq;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The MultiviewDetailsForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that contains the user info for all users viewing the selected data source.</remarks>
    public partial class MultiviewDetailsForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedDataSource property.
        /// </summary>
        /// <value>The currently selected dataSource.</value>
        private DataSource SelectedDataSource { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="MultiviewDetailsForm" /> class.
        /// </summary>
        /// <param name="dataSource">The <paramref name="dataSource"/> parameter.</param>
        public MultiviewDetailsForm(DataSource dataSource)
        {
            InitializeComponent();
            SelectedDataSource = dataSource;
            PopulateUserInfo();
        }

        /// <summary>
        /// The PopulateUserInfo method.
        /// </summary>
        private void PopulateUserInfo()
        {
            lvUserInfo.Items.Clear();

            foreach (var userInfo in SelectedDataSource.MultiviewInfo)
            {
                var lvItem = new ListViewItem(userInfo.Name);
                lvItem.SubItems.Add(userInfo.FirstName);
                lvItem.SubItems.Add(userInfo.LastName);
                lvItem.SubItems.Add(userInfo.EmployeeId);
                lvItem.SubItems.Add(userInfo.Note);
                if (userInfo.PhoneNumbers.Count > 0)
                {
                    var numbers = (from kvp in userInfo.PhoneNumbers select kvp.Value).ToList();
                    lvItem.SubItems.Add(string.Join(", ", numbers));
                }
                lvUserInfo.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonRefresh_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonRefresh_Click(object sender, System.EventArgs args)
        {
            PopulateUserInfo();
        }
    }
}
