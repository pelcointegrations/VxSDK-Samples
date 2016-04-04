namespace SDKSampleApp.Source
{
    partial class SituationTypeSelectionForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lvSituationTypes = new System.Windows.Forms.ListView();
            this.chCheckBox = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chSituationType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnSubscribe = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lvSituationTypes
            // 
            this.lvSituationTypes.CheckBoxes = true;
            this.lvSituationTypes.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chCheckBox,
            this.chSituationType});
            this.lvSituationTypes.FullRowSelect = true;
            this.lvSituationTypes.GridLines = true;
            this.lvSituationTypes.Location = new System.Drawing.Point(12, 12);
            this.lvSituationTypes.MultiSelect = false;
            this.lvSituationTypes.Name = "lvSituationTypes";
            this.lvSituationTypes.Size = new System.Drawing.Size(435, 219);
            this.lvSituationTypes.TabIndex = 7;
            this.lvSituationTypes.UseCompatibleStateImageBehavior = false;
            this.lvSituationTypes.View = System.Windows.Forms.View.Details;
            // 
            // chCheckBox
            // 
            this.chCheckBox.Text = " ";
            this.chCheckBox.Width = 30;
            // 
            // chSituationType
            // 
            this.chSituationType.Text = "Situation Type";
            this.chSituationType.Width = 400;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(292, 237);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 28;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnSubscribe
            // 
            this.btnSubscribe.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnSubscribe.Location = new System.Drawing.Point(373, 237);
            this.btnSubscribe.Name = "btnSubscribe";
            this.btnSubscribe.Size = new System.Drawing.Size(75, 23);
            this.btnSubscribe.TabIndex = 27;
            this.btnSubscribe.Text = "Subscribe";
            this.btnSubscribe.UseVisualStyleBackColor = true;
            this.btnSubscribe.Click += new System.EventHandler(this.ButtonSubscribe_Click);
            // 
            // SituationTypeSelectionForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(460, 269);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnSubscribe);
            this.Controls.Add(this.lvSituationTypes);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SituationTypeSelectionForm";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Select Situation Types";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView lvSituationTypes;
        private System.Windows.Forms.ColumnHeader chCheckBox;
        private System.Windows.Forms.ColumnHeader chSituationType;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnSubscribe;
    }
}