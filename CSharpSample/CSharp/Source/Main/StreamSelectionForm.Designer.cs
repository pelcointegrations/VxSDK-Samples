namespace SDKSampleApp.Source
{
    partial class StreamSelectionForm
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
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnOk = new System.Windows.Forms.Button();
            this.lvStreams = new System.Windows.Forms.ListView();
            this.chEndpoint = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lvDetailedStreams = new System.Windows.Forms.ListView();
            this.chStream = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chMulticast = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chFramerate = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chBitrate = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chResolution = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(297, 185);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 31;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnOk
            // 
            this.btnOk.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnOk.Location = new System.Drawing.Point(378, 185);
            this.btnOk.Name = "btnOk";
            this.btnOk.Size = new System.Drawing.Size(75, 23);
            this.btnOk.TabIndex = 30;
            this.btnOk.Text = "OK";
            this.btnOk.UseVisualStyleBackColor = true;
            this.btnOk.Click += new System.EventHandler(this.ButtonOk_Click);
            // 
            // lvStreams
            // 
            this.lvStreams.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chEndpoint});
            this.lvStreams.FullRowSelect = true;
            this.lvStreams.GridLines = true;
            this.lvStreams.Location = new System.Drawing.Point(12, 12);
            this.lvStreams.MultiSelect = false;
            this.lvStreams.Name = "lvStreams";
            this.lvStreams.Size = new System.Drawing.Size(441, 167);
            this.lvStreams.TabIndex = 29;
            this.lvStreams.UseCompatibleStateImageBehavior = false;
            this.lvStreams.View = System.Windows.Forms.View.Details;
            // 
            // chEndpoint
            // 
            this.chEndpoint.Text = "Stream Endpoint";
            this.chEndpoint.Width = 438;
            // 
            // lvDetailedStreams
            // 
            this.lvDetailedStreams.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chStream,
            this.chMulticast,
            this.chFramerate,
            this.chBitrate,
            this.chResolution});
            this.lvDetailedStreams.FullRowSelect = true;
            this.lvDetailedStreams.GridLines = true;
            this.lvDetailedStreams.Location = new System.Drawing.Point(12, 12);
            this.lvDetailedStreams.MultiSelect = false;
            this.lvDetailedStreams.Name = "lvDetailedStreams";
            this.lvDetailedStreams.Size = new System.Drawing.Size(441, 167);
            this.lvDetailedStreams.TabIndex = 32;
            this.lvDetailedStreams.UseCompatibleStateImageBehavior = false;
            this.lvDetailedStreams.View = System.Windows.Forms.View.Details;
            this.lvDetailedStreams.Visible = false;
            // 
            // chStream
            // 
            this.chStream.Text = "Stream";
            this.chStream.Width = 100;
            // 
            // chMulticast
            // 
            this.chMulticast.Text = "Multicast";
            this.chMulticast.Width = 78;
            // 
            // chFramerate
            // 
            this.chFramerate.Text = "Framerate";
            this.chFramerate.Width = 78;
            // 
            // chBitrate
            // 
            this.chBitrate.Text = "Bitrate";
            this.chBitrate.Width = 78;
            // 
            // chResolution
            // 
            this.chResolution.Text = "Resolution";
            this.chResolution.Width = 95;
            // 
            // StreamSelectionForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(465, 220);
            this.Controls.Add(this.lvDetailedStreams);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnOk);
            this.Controls.Add(this.lvStreams);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "StreamSelectionForm";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Select Stream";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnOk;
        private System.Windows.Forms.ListView lvStreams;
        private System.Windows.Forms.ColumnHeader chEndpoint;
        private System.Windows.Forms.ListView lvDetailedStreams;
        private System.Windows.Forms.ColumnHeader chStream;
        private System.Windows.Forms.ColumnHeader chMulticast;
        private System.Windows.Forms.ColumnHeader chFramerate;
        private System.Windows.Forms.ColumnHeader chBitrate;
        private System.Windows.Forms.ColumnHeader chResolution;
    }
}