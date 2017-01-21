using System;
using System.Collections.Generic;
using System.Drawing;
using System.Globalization;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The ClusterConfigDetailsForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that contains the cluster configuration info.</remarks>
    public partial class ClusterConfigDetailsForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="ClusterConfigDetailsForm" /> class.
        /// </summary>
        public ClusterConfigDetailsForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The GetClusterConfig method.
        /// </summary>
        /// <param name="system">The <paramref name="system"/> to get the cluster configuration for.</param>
        public void GetClusterConfig(VXSystem system)
        {
            if (system == null)
                return;

            var clusterConfig = system.ClusterConfig;
            if (clusterConfig == null)
                return;

            AddPropertyInfo(clusterConfig, "Cluster Configuration");
            AddPropertyInfo(clusterConfig.TimeConfig, "Time Configuration");
            foreach (var node in clusterConfig.NodeConfigurations)
                AddPropertyInfo(node, "Node Configuration");

            if (clusterConfig.StatusDescription.Length <= 25)
                return;

            lvClusterConfigDetails.AutoResizeColumns(ColumnHeaderAutoResizeStyle.ColumnContent);
            lvClusterConfigDetails.Columns[0].Width = 0;
        }

        /// <summary>
        /// The AddPropertyInfo method.
        /// </summary>
        /// <param name="configObject">The <paramref name="configObject"/> to add the properties for.</param>
        /// <param name="title">The text to use for the header row.</param>
        private void AddPropertyInfo(object configObject, string title)
        {
            // Add a section header row for the current set of properties.
            var lvMainItem = new ListViewItem(string.Empty) { BackColor = Color.LightGray };
            lvMainItem.SubItems.Add(title);
            lvClusterConfigDetails.Items.Add(lvMainItem);

            // Use reflection to get each available property from the configuration object.
            foreach (var prop in configObject.GetType().GetProperties())
            {
                string valItem;

                // Get the value from the property.
                var val = prop.GetValue(configObject, null);

                // Skip the property if the value is a node list.
                if (val.GetType() == typeof(List<Configuration.Node>))
                    continue;

                // Skip the property if the value is a time configuration.
                if (val.GetType() == typeof(Configuration.Time))
                    continue;

                // Convert the property to a local time string if it's a DateTime type.
                if (val is DateTime)
                {
                    var time = (DateTime)val;
                    valItem = time.ToLocalTime().ToString(CultureInfo.InvariantCulture);
                }
                else
                    valItem = val.ToString();

                // Add the property name and value to the list view.
                var lvItem = new ListViewItem(string.Empty);
                lvItem.SubItems.Add(prop.Name);
                lvItem.SubItems.Add(valItem);
                lvClusterConfigDetails.Items.Add(lvItem);
            }
        }
    }
}
