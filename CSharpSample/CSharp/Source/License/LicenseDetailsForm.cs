using System;
using System.Collections.Generic;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The LicenseDetailsForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that contains the detailed info of the system license.</remarks>
    public partial class LicenseDetailsForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="LicenseDetailsForm" /> class.
        /// </summary>
        public LicenseDetailsForm()
        {
            InitializeComponent();
            GetLicenseInfo();
            tvLicenseDetails.ExpandAll();
        }

        /// <summary>
        /// The GetLicenseInfo method.
        /// </summary>
        public void GetLicenseInfo()
        {
            // Get the license from the current system.
            var license = MainForm.CurrentSystem.GetLicense();
            if (license == null) 
                return;

            // Create the base node.
            var licenseNode = tvLicenseDetails.Nodes.Add("License");

            // Use reflection to get each available property from the license.
            foreach (var prop in license.GetType().GetProperties())
            {
                // Get the value from the property.
                var val = prop.GetValue(license, null);

                // Skip if the value is a List type.
                if (val.GetType() == typeof(List<LicenseFeature>))
                    continue;

                // Add the value to the current node.
                licenseNode.Nodes.Add(string.Format("{0}: {1}", prop.Name, val));
            }

            if (license.LicenseFeatures.Count == 0)
                return;

            // Populate the feature nodes if present.
            foreach (var feature in license.LicenseFeatures)
                AddFeatureInfo(feature, licenseNode);
        }

        /// <summary>
        /// The AddFeatureInfo method.
        /// </summary>
        /// <param name="licenseFeature">The <paramref name="licenseFeature"/> to add the info for.</param>
        /// <param name="licenseNode">The node to add the info to.</param>
        private static void AddFeatureInfo(LicenseFeature licenseFeature, TreeNode licenseNode)
        {
            var featureNode = licenseNode.Nodes.Add("Feature");

            // Use reflection to get each available property from the license feature.
            foreach (var prop in licenseFeature.GetType().GetProperties())
            {
                // Get the value from the property.
                var val = prop.GetValue(licenseFeature, null);

                // Skip if the value is a List type.
                if (val.GetType() == typeof(List<Device>))
                    continue;

                // Generate a string based on the value type.
                string valList;
                if (val is DateTime)
                {
                    var dt = (DateTime)val;
                    valList = dt == default(DateTime) ? "None" : dt.ToString("G");
                }
                else
                    valList = val.ToString();

                // Add the value to the current node.
                featureNode.Nodes.Add(string.Format("{0}: {1}", prop.Name, valList));
            }

            if (licenseFeature.CommissionedDevices.Count == 0)
                return;

            // Add a new node for commissioned devices if they are present and populate it.
            var deviceNode = featureNode.Nodes.Add("Commissioned Devices");
            foreach (var device in licenseFeature.CommissionedDevices)
                AddDeviceInfo(device, deviceNode);
        }

        /// <summary>
        /// The AddDeviceInfo method.
        /// </summary>
        /// <param name="device">The <paramref name="device"/> to add the info for.</param>
        /// <param name="deviceNode">The node to add the info to.</param>
        private static void AddDeviceInfo(Device device, TreeNode deviceNode)
        {
            // Change the device type to a more readable form.
            string type;
            switch (device.Type)
            {
                case Device.Types.CoreMg:
                    type = "Core/MediaGateway";
                    break;
                case Device.Types.Mg:
                    type = "MediaGateway";
                    break;
                case Device.Types.Udi:
                    type = "UDI";
                    break;
                case Device.Types.Ui:
                    type = "User Interface";
                    break;
                case Device.Types.Vcd:
                    type = "VCD";
                    break;
                default:
                    type = device.Type.ToString();
                    break;
            }

            // Add the device info to the current node.
            deviceNode.Nodes.Add(string.Format("{0}: {1}", type, device.Name));
        }
    }
}
