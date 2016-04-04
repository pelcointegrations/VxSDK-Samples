using System;
using System.Collections.Generic;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The StreamSelectionForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that allows the user to select a stream.</remarks>
    public partial class StreamSelectionForm : Form
    {
        /// <summary>
        /// Gets or sets the SelectedInterface property.
        /// </summary>
        /// <value>The currently selected data interface.</value>
        public DataInterface SelectedInterface { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="StreamSelectionForm" /> class.
        /// </summary>
        /// <param name="dataInterfaces">The data interfaces to get streams from.</param>
        public StreamSelectionForm(IEnumerable<DataInterface> dataInterfaces)
        {
            InitializeComponent();

            // Iterate the data interface list and parse out the endpoint URL.
            var interfaceList = new Dictionary<string, DataInterface>();
            foreach (var dataInterface in dataInterfaces)
            {
                IEnumerable<string> set = dataInterface.DataEndpoint.Split('&');
                foreach (var section in set)
                {
                    if (!section.StartsWith("streaming_uri=")) 
                        continue;

                    var url = System.Net.WebUtility.UrlDecode(section.Substring(14));
                    interfaceList[url] = dataInterface;
                }
            }

            // Populate the stream list.
            foreach (var item in interfaceList)
            {
                var lvItem = new ListViewItem(item.Key) { Tag = item.Value };
                lvStreams.Items.Add(lvItem);
            }
        }

        /// <summary>
        /// The ButtonOk_Click method.
        /// </summary>
        /// <param name="sender">The <paramref name="sender"/> parameter.</param>
        /// <param name="args">The <paramref name="args"/> parameter.</param>
        private void ButtonOk_Click(object sender, EventArgs args)
        {
            // Close the dialog if no situations are checked.
            if (lvStreams.SelectedItems.Count == 0)
                return;

            SelectedInterface = (DataInterface)lvStreams.SelectedItems[0].Tag;
        }
    }
}
