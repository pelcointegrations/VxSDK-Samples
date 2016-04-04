using System;
using System.Drawing;
using System.Windows.Forms;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The InputBox class.
    /// </summary>
    /// <remarks>Provides a reusable dialog window for entering a numeric value.</remarks> 
    public static class InputBox
    {
        /// <summary>
        /// The Show method.
        /// </summary>
        /// <param name="title">The title of the dialog window.</param>
        /// <param name="prompt">The text to show inside of the dialog window.</param>
        /// <param name="value">The value entered.</param>
        /// <param name="min">The minimum value that can be entered.</param>
        /// <param name="max">The max value that can be entered.</param>
        /// <returns>The result of the dialog.</returns>
        public static DialogResult Show(string title, string prompt, ref decimal value, int min = 0, int max = 100)
        {
            var form = new Form();
            var label = new Label();
            var numericUpDown = new NumericUpDown();
            var buttonOk = new Button();
            var buttonCancel = new Button();

            form.Text = title;
            label.Text = prompt;
            numericUpDown.Minimum = min;
            numericUpDown.Maximum = max;
            numericUpDown.Value = value;

            buttonOk.Text = @"OK";
            buttonCancel.Text = @"Cancel";
            buttonOk.DialogResult = DialogResult.OK;
            buttonCancel.DialogResult = DialogResult.Cancel;

            label.SetBounds(9, 20, 372, 13);
            numericUpDown.SetBounds(12, 36, 372, 20);
            buttonOk.SetBounds(228, 72, 75, 23);
            buttonCancel.SetBounds(309, 72, 75, 23);

            label.AutoSize = true;
            numericUpDown.Anchor = numericUpDown.Anchor | AnchorStyles.Right;
            buttonOk.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            buttonCancel.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;

            form.ClientSize = new Size(396, 107);
            form.Controls.AddRange(new Control[] { label, numericUpDown, buttonOk, buttonCancel });
            form.ClientSize = new Size(Math.Max(300, label.Right + 10), form.ClientSize.Height);
            form.FormBorderStyle = FormBorderStyle.FixedDialog;
            form.StartPosition = FormStartPosition.CenterScreen;
            form.MinimizeBox = false;
            form.MaximizeBox = false;
            form.AcceptButton = buttonOk;
            form.CancelButton = buttonCancel;

            var dialogResult = form.ShowDialog();
            value = numericUpDown.Value;
            return dialogResult;
        }
    }
}
