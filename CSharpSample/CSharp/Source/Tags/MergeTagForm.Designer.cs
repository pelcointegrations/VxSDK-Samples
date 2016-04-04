namespace SDKSampleApp.Source
{
    partial class MergeTagForm
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
            this.btnMerge = new System.Windows.Forms.Button();
            this.gbxLinkedDataSources = new System.Windows.Forms.GroupBox();
            this.lvTags = new System.Windows.Forms.ListView();
            this.chName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.chOwner = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.gbxLinkedDataSources.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(480, 179);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 33;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnMerge
            // 
            this.btnMerge.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnMerge.Location = new System.Drawing.Point(561, 179);
            this.btnMerge.Name = "btnMerge";
            this.btnMerge.Size = new System.Drawing.Size(75, 23);
            this.btnMerge.TabIndex = 32;
            this.btnMerge.Text = "Merge";
            this.btnMerge.UseVisualStyleBackColor = true;
            this.btnMerge.Click += new System.EventHandler(this.ButtonMerge_Click);
            // 
            // gbxLinkedDataSources
            // 
            this.gbxLinkedDataSources.Controls.Add(this.lvTags);
            this.gbxLinkedDataSources.Location = new System.Drawing.Point(12, 12);
            this.gbxLinkedDataSources.Name = "gbxLinkedDataSources";
            this.gbxLinkedDataSources.Size = new System.Drawing.Size(624, 161);
            this.gbxLinkedDataSources.TabIndex = 31;
            this.gbxLinkedDataSources.TabStop = false;
            this.gbxLinkedDataSources.Text = "Tag To Merge With";
            // 
            // lvTags
            // 
            this.lvTags.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.chName,
            this.chId,
            this.chOwner});
            this.lvTags.FullRowSelect = true;
            this.lvTags.Location = new System.Drawing.Point(6, 19);
            this.lvTags.MultiSelect = false;
            this.lvTags.Name = "lvTags";
            this.lvTags.Size = new System.Drawing.Size(612, 136);
            this.lvTags.TabIndex = 3;
            this.lvTags.UseCompatibleStateImageBehavior = false;
            this.lvTags.View = System.Windows.Forms.View.Details;
            // 
            // chName
            // 
            this.chName.Text = "Name";
            this.chName.Width = 168;
            // 
            // chId
            // 
            this.chId.Text = "ID";
            this.chId.Width = 317;
            // 
            // chOwner
            // 
            this.chOwner.Text = "Owner";
            this.chOwner.Width = 117;
            // 
            // MergeTagForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(643, 209);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnMerge);
            this.Controls.Add(this.gbxLinkedDataSources);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MergeTagForm";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Merge Tag";
            this.gbxLinkedDataSources.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnMerge;
        private System.Windows.Forms.GroupBox gbxLinkedDataSources;
        private System.Windows.Forms.ListView lvTags;
        private System.Windows.Forms.ColumnHeader chName;
        private System.Windows.Forms.ColumnHeader chId;
        private System.Windows.Forms.ColumnHeader chOwner;
    }
}