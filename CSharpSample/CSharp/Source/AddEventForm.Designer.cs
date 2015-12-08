namespace SDKSampleApp.Source
{
    partial class AddEventForm
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
            if(disposing && (components != null))
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
            this.txbxGeneratorDeviceId = new System.Windows.Forms.TextBox();
            this.cbxSituationType = new System.Windows.Forms.ComboBox();
            this.cbxSourceDeviceId = new System.Windows.Forms.ComboBox();
            this.dtpTime = new System.Windows.Forms.DateTimePicker();
            this.txbxName1 = new System.Windows.Forms.TextBox();
            this.txbxValue1 = new System.Windows.Forms.TextBox();
            this.txbxName2 = new System.Windows.Forms.TextBox();
            this.txbxValue2 = new System.Windows.Forms.TextBox();
            this.txbxName3 = new System.Windows.Forms.TextBox();
            this.txbxValue3 = new System.Windows.Forms.TextBox();
            this.lblGeneratorDeviceId = new System.Windows.Forms.Label();
            this.lblSituationType = new System.Windows.Forms.Label();
            this.lblSourceDeviceId = new System.Windows.Forms.Label();
            this.lblTime = new System.Windows.Forms.Label();
            this.lblProperties = new System.Windows.Forms.Label();
            this.lblName = new System.Windows.Forms.Label();
            this.lblValue = new System.Windows.Forms.Label();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txbxGeneratorDeviceId
            // 
            this.txbxGeneratorDeviceId.Location = new System.Drawing.Point(131, 27);
            this.txbxGeneratorDeviceId.Name = "txbxGeneratorDeviceId";
            this.txbxGeneratorDeviceId.Size = new System.Drawing.Size(266, 20);
            this.txbxGeneratorDeviceId.TabIndex = 0;
            // 
            // cbxSituationType
            // 
            this.cbxSituationType.FormattingEnabled = true;
            this.cbxSituationType.Location = new System.Drawing.Point(131, 66);
            this.cbxSituationType.Name = "cbxSituationType";
            this.cbxSituationType.Size = new System.Drawing.Size(266, 21);
            this.cbxSituationType.TabIndex = 1;
            // 
            // cbxSourceDeviceId
            // 
            this.cbxSourceDeviceId.FormattingEnabled = true;
            this.cbxSourceDeviceId.Location = new System.Drawing.Point(131, 107);
            this.cbxSourceDeviceId.Name = "cbxSourceDeviceId";
            this.cbxSourceDeviceId.Size = new System.Drawing.Size(266, 21);
            this.cbxSourceDeviceId.TabIndex = 2;
            // 
            // dtpTime
            // 
            this.dtpTime.CustomFormat = "yyyy-MM-dd HH:mm:ss";
            this.dtpTime.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpTime.Location = new System.Drawing.Point(131, 147);
            this.dtpTime.Name = "dtpTime";
            this.dtpTime.Size = new System.Drawing.Size(266, 20);
            this.dtpTime.TabIndex = 3;
            // 
            // txbxName1
            // 
            this.txbxName1.Location = new System.Drawing.Point(131, 198);
            this.txbxName1.Name = "txbxName1";
            this.txbxName1.Size = new System.Drawing.Size(130, 20);
            this.txbxName1.TabIndex = 4;
            // 
            // txbxValue1
            // 
            this.txbxValue1.Location = new System.Drawing.Point(267, 198);
            this.txbxValue1.Name = "txbxValue1";
            this.txbxValue1.Size = new System.Drawing.Size(130, 20);
            this.txbxValue1.TabIndex = 5;
            // 
            // txbxName2
            // 
            this.txbxName2.Location = new System.Drawing.Point(131, 224);
            this.txbxName2.Name = "txbxName2";
            this.txbxName2.Size = new System.Drawing.Size(130, 20);
            this.txbxName2.TabIndex = 6;
            // 
            // txbxValue2
            // 
            this.txbxValue2.Location = new System.Drawing.Point(267, 224);
            this.txbxValue2.Name = "txbxValue2";
            this.txbxValue2.Size = new System.Drawing.Size(130, 20);
            this.txbxValue2.TabIndex = 7;
            // 
            // txbxName3
            // 
            this.txbxName3.Location = new System.Drawing.Point(131, 250);
            this.txbxName3.Name = "txbxName3";
            this.txbxName3.Size = new System.Drawing.Size(130, 20);
            this.txbxName3.TabIndex = 8;
            // 
            // txbxValue3
            // 
            this.txbxValue3.Location = new System.Drawing.Point(267, 250);
            this.txbxValue3.Name = "txbxValue3";
            this.txbxValue3.Size = new System.Drawing.Size(130, 20);
            this.txbxValue3.TabIndex = 9;
            // 
            // lblGeneratorDeviceId
            // 
            this.lblGeneratorDeviceId.AutoSize = true;
            this.lblGeneratorDeviceId.Location = new System.Drawing.Point(22, 30);
            this.lblGeneratorDeviceId.Name = "lblGeneratorDeviceId";
            this.lblGeneratorDeviceId.Size = new System.Drawing.Size(103, 13);
            this.lblGeneratorDeviceId.TabIndex = 10;
            this.lblGeneratorDeviceId.Text = "Generator Device Id";
            // 
            // lblSituationType
            // 
            this.lblSituationType.AutoSize = true;
            this.lblSituationType.Location = new System.Drawing.Point(50, 69);
            this.lblSituationType.Name = "lblSituationType";
            this.lblSituationType.Size = new System.Drawing.Size(75, 13);
            this.lblSituationType.TabIndex = 11;
            this.lblSituationType.Text = "Situation Type";
            // 
            // lblSourceDeviceId
            // 
            this.lblSourceDeviceId.AutoSize = true;
            this.lblSourceDeviceId.Location = new System.Drawing.Point(35, 110);
            this.lblSourceDeviceId.Name = "lblSourceDeviceId";
            this.lblSourceDeviceId.Size = new System.Drawing.Size(90, 13);
            this.lblSourceDeviceId.TabIndex = 12;
            this.lblSourceDeviceId.Text = "Source Device Id";
            // 
            // lblTime
            // 
            this.lblTime.AutoSize = true;
            this.lblTime.Location = new System.Drawing.Point(64, 153);
            this.lblTime.Name = "lblTime";
            this.lblTime.Size = new System.Drawing.Size(61, 13);
            this.lblTime.TabIndex = 13;
            this.lblTime.Text = "Event Time";
            // 
            // lblProperties
            // 
            this.lblProperties.AutoSize = true;
            this.lblProperties.Location = new System.Drawing.Point(33, 201);
            this.lblProperties.Name = "lblProperties";
            this.lblProperties.Size = new System.Drawing.Size(92, 13);
            this.lblProperties.TabIndex = 14;
            this.lblProperties.Text = "Custom Properties";
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Location = new System.Drawing.Point(185, 182);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(35, 13);
            this.lblName.TabIndex = 15;
            this.lblName.Text = "Name";
            // 
            // lblValue
            // 
            this.lblValue.AutoSize = true;
            this.lblValue.Location = new System.Drawing.Point(316, 182);
            this.lblValue.Name = "lblValue";
            this.lblValue.Size = new System.Drawing.Size(34, 13);
            this.lblValue.TabIndex = 16;
            this.lblValue.Text = "Value";
            // 
            // btnAdd
            // 
            this.btnAdd.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnAdd.Location = new System.Drawing.Point(319, 276);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 17;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.ButtonAdd_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(238, 276);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 18;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // AddEventForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(416, 309);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.lblValue);
            this.Controls.Add(this.lblName);
            this.Controls.Add(this.lblProperties);
            this.Controls.Add(this.lblTime);
            this.Controls.Add(this.lblSourceDeviceId);
            this.Controls.Add(this.lblSituationType);
            this.Controls.Add(this.lblGeneratorDeviceId);
            this.Controls.Add(this.txbxValue3);
            this.Controls.Add(this.txbxName3);
            this.Controls.Add(this.txbxValue2);
            this.Controls.Add(this.txbxName2);
            this.Controls.Add(this.txbxValue1);
            this.Controls.Add(this.txbxName1);
            this.Controls.Add(this.dtpTime);
            this.Controls.Add(this.cbxSourceDeviceId);
            this.Controls.Add(this.cbxSituationType);
            this.Controls.Add(this.txbxGeneratorDeviceId);
            this.Name = "AddEventForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Add Event";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txbxGeneratorDeviceId;
        private System.Windows.Forms.ComboBox cbxSituationType;
        private System.Windows.Forms.ComboBox cbxSourceDeviceId;
        private System.Windows.Forms.DateTimePicker dtpTime;
        private System.Windows.Forms.TextBox txbxName1;
        private System.Windows.Forms.TextBox txbxValue1;
        private System.Windows.Forms.TextBox txbxName2;
        private System.Windows.Forms.TextBox txbxValue2;
        private System.Windows.Forms.TextBox txbxName3;
        private System.Windows.Forms.TextBox txbxValue3;
        private System.Windows.Forms.Label lblGeneratorDeviceId;
        private System.Windows.Forms.Label lblSituationType;
        private System.Windows.Forms.Label lblSourceDeviceId;
        private System.Windows.Forms.Label lblTime;
        private System.Windows.Forms.Label lblProperties;
        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.Label lblValue;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnCancel;
    }
}