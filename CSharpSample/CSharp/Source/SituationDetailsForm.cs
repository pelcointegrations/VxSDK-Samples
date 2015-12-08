using System.Collections.Generic;
using System.Windows.Forms;
using CPPCli;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The SituationDetailsForm class.
    /// </summary>
    /// <remarks>Provides a dialog window that contains the detailed info for the selected situation.</remarks> 
    public partial class SituationDetailsForm : Form
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="SituationDetailsForm" /> class.
        /// </summary>   
        public SituationDetailsForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The GetSituationInfo method.
        /// </summary>
        /// <param name="situation">The <paramref name="situation"/> to get information for.</param>
        public void GetSituationInfo(Situation situation)
        {
            if (situation == null) 
                return;

            // Use reflection to get each available property from the situation.
            foreach (var prop in situation.GetType().GetProperties())
            {
                // Get the value from the property.
                var val = prop.GetValue(situation, null);
                
                // Get each item if the value is a List type and generate a string.
                string valList;
                if (val.GetType() == typeof(List<string>))
                {
                    valList = string.Join(", ", (List<string>)val);
                }
                else if (val.GetType() == typeof(List<int>))
                {
                    valList = string.Join(", ", (List<int>)val);
                }
                else
                {
                    valList = val.ToString();
                }

                // Add the property name and value to the list view.
                var lvItem = new ListViewItem(prop.Name);
                lvItem.SubItems.Add(valList);
                lvSituationDetails.Items.Add(lvItem);
            }
        }
    }
}
