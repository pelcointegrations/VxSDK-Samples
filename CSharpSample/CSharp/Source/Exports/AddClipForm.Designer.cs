namespace SDKSampleApp.Source
{
    partial class AddClipForm
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
            this.gbxEndTime = new System.Windows.Forms.GroupBox();
            this.dtpEndDate = new System.Windows.Forms.DateTimePicker();
            this.gbxStartTime = new System.Windows.Forms.GroupBox();
            this.dtpStartDate = new System.Windows.Forms.DateTimePicker();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.tblPanelSnapshotPreview = new System.Windows.Forms.TableLayoutPanel();
            this.pbxImage5 = new System.Windows.Forms.PictureBox();
            this.pbxImage4 = new System.Windows.Forms.PictureBox();
            this.pbxImage3 = new System.Windows.Forms.PictureBox();
            this.pbxImage1 = new System.Windows.Forms.PictureBox();
            this.pbxImage2 = new System.Windows.Forms.PictureBox();
            this.lblSnapshot1 = new System.Windows.Forms.Label();
            this.lblSnapshot2 = new System.Windows.Forms.Label();
            this.lblSnapshot3 = new System.Windows.Forms.Label();
            this.lblSnapshot4 = new System.Windows.Forms.Label();
            this.lblSnapshot5 = new System.Windows.Forms.Label();
            this.gbxEndTime.SuspendLayout();
            this.gbxStartTime.SuspendLayout();
            this.tblPanelSnapshotPreview.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage2)).BeginInit();
            this.SuspendLayout();
            // 
            // gbxEndTime
            // 
            this.gbxEndTime.Controls.Add(this.dtpEndDate);
            this.gbxEndTime.Location = new System.Drawing.Point(779, 12);
            this.gbxEndTime.Name = "gbxEndTime";
            this.gbxEndTime.Size = new System.Drawing.Size(215, 58);
            this.gbxEndTime.TabIndex = 6;
            this.gbxEndTime.TabStop = false;
            this.gbxEndTime.Text = "End Time";
            // 
            // dtpEndDate
            // 
            this.dtpEndDate.CustomFormat = "HH:mm:ss  MM/dd/yyyy";
            this.dtpEndDate.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpEndDate.Location = new System.Drawing.Point(6, 23);
            this.dtpEndDate.Name = "dtpEndDate";
            this.dtpEndDate.Size = new System.Drawing.Size(204, 20);
            this.dtpEndDate.TabIndex = 2;
            this.dtpEndDate.ValueChanged += new System.EventHandler(this.DatePickerEnd_ValueChanged);
            // 
            // gbxStartTime
            // 
            this.gbxStartTime.Controls.Add(this.dtpStartDate);
            this.gbxStartTime.Location = new System.Drawing.Point(12, 12);
            this.gbxStartTime.Name = "gbxStartTime";
            this.gbxStartTime.Size = new System.Drawing.Size(215, 58);
            this.gbxStartTime.TabIndex = 5;
            this.gbxStartTime.TabStop = false;
            this.gbxStartTime.Text = "Start Time";
            // 
            // dtpStartDate
            // 
            this.dtpStartDate.CustomFormat = "HH:mm:ss  MM/dd/yyyy";
            this.dtpStartDate.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpStartDate.Location = new System.Drawing.Point(6, 23);
            this.dtpStartDate.Name = "dtpStartDate";
            this.dtpStartDate.Size = new System.Drawing.Size(204, 20);
            this.dtpStartDate.TabIndex = 2;
            this.dtpStartDate.ValueChanged += new System.EventHandler(this.DatePickerStart_ValueChanged);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(919, 259);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 7;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.ButtonAdd_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(838, 259);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 8;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // tblPanelSnapshotPreview
            // 
            this.tblPanelSnapshotPreview.BackColor = System.Drawing.Color.Black;
            this.tblPanelSnapshotPreview.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Single;
            this.tblPanelSnapshotPreview.ColumnCount = 5;
            this.tblPanelSnapshotPreview.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tblPanelSnapshotPreview.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tblPanelSnapshotPreview.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tblPanelSnapshotPreview.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tblPanelSnapshotPreview.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tblPanelSnapshotPreview.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tblPanelSnapshotPreview.Controls.Add(this.pbxImage5, 4, 0);
            this.tblPanelSnapshotPreview.Controls.Add(this.pbxImage4, 3, 0);
            this.tblPanelSnapshotPreview.Controls.Add(this.pbxImage3, 2, 0);
            this.tblPanelSnapshotPreview.Controls.Add(this.pbxImage1, 0, 0);
            this.tblPanelSnapshotPreview.Controls.Add(this.pbxImage2, 1, 0);
            this.tblPanelSnapshotPreview.Location = new System.Drawing.Point(12, 76);
            this.tblPanelSnapshotPreview.Name = "tblPanelSnapshotPreview";
            this.tblPanelSnapshotPreview.RowCount = 1;
            this.tblPanelSnapshotPreview.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tblPanelSnapshotPreview.Size = new System.Drawing.Size(982, 162);
            this.tblPanelSnapshotPreview.TabIndex = 9;
            // 
            // pbxImage5
            // 
            this.pbxImage5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.pbxImage5.Location = new System.Drawing.Point(788, 4);
            this.pbxImage5.Name = "pbxImage5";
            this.pbxImage5.Size = new System.Drawing.Size(190, 154);
            this.pbxImage5.TabIndex = 4;
            this.pbxImage5.TabStop = false;
            // 
            // pbxImage4
            // 
            this.pbxImage4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.pbxImage4.Location = new System.Drawing.Point(592, 4);
            this.pbxImage4.Name = "pbxImage4";
            this.pbxImage4.Size = new System.Drawing.Size(189, 154);
            this.pbxImage4.TabIndex = 3;
            this.pbxImage4.TabStop = false;
            // 
            // pbxImage3
            // 
            this.pbxImage3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.pbxImage3.Location = new System.Drawing.Point(396, 4);
            this.pbxImage3.Name = "pbxImage3";
            this.pbxImage3.Size = new System.Drawing.Size(189, 154);
            this.pbxImage3.TabIndex = 2;
            this.pbxImage3.TabStop = false;
            // 
            // pbxImage1
            // 
            this.pbxImage1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.pbxImage1.Location = new System.Drawing.Point(4, 4);
            this.pbxImage1.Name = "pbxImage1";
            this.pbxImage1.Size = new System.Drawing.Size(189, 154);
            this.pbxImage1.TabIndex = 0;
            this.pbxImage1.TabStop = false;
            // 
            // pbxImage2
            // 
            this.pbxImage2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.pbxImage2.Location = new System.Drawing.Point(200, 4);
            this.pbxImage2.Name = "pbxImage2";
            this.pbxImage2.Size = new System.Drawing.Size(189, 154);
            this.pbxImage2.TabIndex = 1;
            this.pbxImage2.TabStop = false;
            // 
            // lblSnapshot1
            // 
            this.lblSnapshot1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblSnapshot1.Location = new System.Drawing.Point(18, 243);
            this.lblSnapshot1.Name = "lblSnapshot1";
            this.lblSnapshot1.Size = new System.Drawing.Size(187, 13);
            this.lblSnapshot1.TabIndex = 10;
            this.lblSnapshot1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblSnapshot2
            // 
            this.lblSnapshot2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblSnapshot2.Location = new System.Drawing.Point(212, 243);
            this.lblSnapshot2.Name = "lblSnapshot2";
            this.lblSnapshot2.Size = new System.Drawing.Size(189, 13);
            this.lblSnapshot2.TabIndex = 11;
            this.lblSnapshot2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblSnapshot3
            // 
            this.lblSnapshot3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblSnapshot3.Location = new System.Drawing.Point(408, 243);
            this.lblSnapshot3.Name = "lblSnapshot3";
            this.lblSnapshot3.Size = new System.Drawing.Size(189, 13);
            this.lblSnapshot3.TabIndex = 12;
            this.lblSnapshot3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblSnapshot4
            // 
            this.lblSnapshot4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblSnapshot4.Location = new System.Drawing.Point(604, 243);
            this.lblSnapshot4.Name = "lblSnapshot4";
            this.lblSnapshot4.Size = new System.Drawing.Size(189, 13);
            this.lblSnapshot4.TabIndex = 13;
            this.lblSnapshot4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblSnapshot5
            // 
            this.lblSnapshot5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblSnapshot5.Location = new System.Drawing.Point(800, 243);
            this.lblSnapshot5.Name = "lblSnapshot5";
            this.lblSnapshot5.Size = new System.Drawing.Size(189, 13);
            this.lblSnapshot5.TabIndex = 14;
            this.lblSnapshot5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // AddClipForm
            // 
            this.AcceptButton = this.btnAdd;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.btnCancel;
            this.ClientSize = new System.Drawing.Size(1006, 294);
            this.Controls.Add(this.lblSnapshot5);
            this.Controls.Add(this.lblSnapshot4);
            this.Controls.Add(this.lblSnapshot3);
            this.Controls.Add(this.lblSnapshot2);
            this.Controls.Add(this.lblSnapshot1);
            this.Controls.Add(this.tblPanelSnapshotPreview);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.gbxEndTime);
            this.Controls.Add(this.gbxStartTime);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddClipForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Add Clip";
            this.gbxEndTime.ResumeLayout(false);
            this.gbxStartTime.ResumeLayout(false);
            this.tblPanelSnapshotPreview.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbxEndTime;
        private System.Windows.Forms.DateTimePicker dtpEndDate;
        private System.Windows.Forms.GroupBox gbxStartTime;
        private System.Windows.Forms.DateTimePicker dtpStartDate;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.TableLayoutPanel tblPanelSnapshotPreview;
        private System.Windows.Forms.PictureBox pbxImage1;
        private System.Windows.Forms.PictureBox pbxImage5;
        private System.Windows.Forms.PictureBox pbxImage4;
        private System.Windows.Forms.PictureBox pbxImage3;
        private System.Windows.Forms.PictureBox pbxImage2;
        private System.Windows.Forms.Label lblSnapshot1;
        private System.Windows.Forms.Label lblSnapshot2;
        private System.Windows.Forms.Label lblSnapshot3;
        private System.Windows.Forms.Label lblSnapshot4;
        private System.Windows.Forms.Label lblSnapshot5;
    }
}