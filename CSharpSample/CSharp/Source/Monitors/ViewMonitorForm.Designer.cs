namespace SDKSampleApp.Source
{
    partial class ViewMonitorForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ViewMonitorForm));
            this.lvDataSources = new System.Windows.Forms.ListView();
            this.colHeadName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colHeadIp = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnRefresh = new System.Windows.Forms.Button();
            this.tlpCells = new System.Windows.Forms.TableLayoutPanel();
            this.pnlCell_01 = new System.Windows.Forms.Panel();
            this.lblCell_01 = new System.Windows.Forms.Label();
            this.pnlCell_02 = new System.Windows.Forms.Panel();
            this.lblCell_02 = new System.Windows.Forms.Label();
            this.pnlCell_03 = new System.Windows.Forms.Panel();
            this.lblCell_03 = new System.Windows.Forms.Label();
            this.pnlCell_04 = new System.Windows.Forms.Panel();
            this.lblCell_04 = new System.Windows.Forms.Label();
            this.pnlCell_05 = new System.Windows.Forms.Panel();
            this.lblCell_05 = new System.Windows.Forms.Label();
            this.pnlCell_06 = new System.Windows.Forms.Panel();
            this.lblCell_06 = new System.Windows.Forms.Label();
            this.pnlCell_07 = new System.Windows.Forms.Panel();
            this.lblCell_07 = new System.Windows.Forms.Label();
            this.pnlCell_08 = new System.Windows.Forms.Panel();
            this.lblCell_08 = new System.Windows.Forms.Label();
            this.pnlCell_09 = new System.Windows.Forms.Panel();
            this.lblCell_09 = new System.Windows.Forms.Label();
            this.pnlCell_10 = new System.Windows.Forms.Panel();
            this.lblCell_10 = new System.Windows.Forms.Label();
            this.pnlCell_11 = new System.Windows.Forms.Panel();
            this.lblCell_11 = new System.Windows.Forms.Label();
            this.pnlCell_12 = new System.Windows.Forms.Panel();
            this.lblCell_12 = new System.Windows.Forms.Label();
            this.pnlCell_13 = new System.Windows.Forms.Panel();
            this.lblCell_13 = new System.Windows.Forms.Label();
            this.pnlCell_14 = new System.Windows.Forms.Panel();
            this.lblCell_14 = new System.Windows.Forms.Label();
            this.pnlCell_15 = new System.Windows.Forms.Panel();
            this.lblCell_15 = new System.Windows.Forms.Label();
            this.pnlCell_16 = new System.Windows.Forms.Panel();
            this.lblCell_16 = new System.Windows.Forms.Label();
            this.cbxLayouts = new System.Windows.Forms.ComboBox();
            this.nudSpeed = new System.Windows.Forms.NumericUpDown();
            this.btnLive = new System.Windows.Forms.Button();
            this.btnSetTime = new System.Windows.Forms.Button();
            this.btnSetSpeed = new System.Windows.Forms.Button();
            this.dtpTime = new System.Windows.Forms.DateTimePicker();
            this.gbxTime = new System.Windows.Forms.GroupBox();
            this.gbxSpeed = new System.Windows.Forms.GroupBox();
            this.gbxMonitorLayout = new System.Windows.Forms.GroupBox();
            this.tlpCells.SuspendLayout();
            this.pnlCell_01.SuspendLayout();
            this.pnlCell_02.SuspendLayout();
            this.pnlCell_03.SuspendLayout();
            this.pnlCell_04.SuspendLayout();
            this.pnlCell_05.SuspendLayout();
            this.pnlCell_06.SuspendLayout();
            this.pnlCell_07.SuspendLayout();
            this.pnlCell_08.SuspendLayout();
            this.pnlCell_09.SuspendLayout();
            this.pnlCell_10.SuspendLayout();
            this.pnlCell_11.SuspendLayout();
            this.pnlCell_12.SuspendLayout();
            this.pnlCell_13.SuspendLayout();
            this.pnlCell_14.SuspendLayout();
            this.pnlCell_15.SuspendLayout();
            this.pnlCell_16.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudSpeed)).BeginInit();
            this.gbxTime.SuspendLayout();
            this.gbxSpeed.SuspendLayout();
            this.gbxMonitorLayout.SuspendLayout();
            this.SuspendLayout();
            // 
            // lvDataSources
            // 
            this.lvDataSources.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colHeadName,
            this.colHeadIp});
            this.lvDataSources.FullRowSelect = true;
            this.lvDataSources.HideSelection = false;
            this.lvDataSources.Location = new System.Drawing.Point(658, 3);
            this.lvDataSources.MultiSelect = false;
            this.lvDataSources.Name = "lvDataSources";
            this.lvDataSources.Size = new System.Drawing.Size(320, 694);
            this.lvDataSources.TabIndex = 2;
            this.lvDataSources.UseCompatibleStateImageBehavior = false;
            this.lvDataSources.View = System.Windows.Forms.View.Details;
            this.lvDataSources.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.ListViewDataSources_OnItemDrag);
            // 
            // colHeadName
            // 
            this.colHeadName.Text = "Name";
            this.colHeadName.Width = 255;
            // 
            // colHeadIp
            // 
            this.colHeadIp.Text = "Ip";
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(138, 19);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(56, 21);
            this.btnRefresh.TabIndex = 6;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.ButtonRefresh_Click);
            // 
            // tlpCells
            // 
            this.tlpCells.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.tlpCells.ColumnCount = 4;
            this.tlpCells.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tlpCells.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tlpCells.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tlpCells.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tlpCells.Controls.Add(this.pnlCell_01, 0, 0);
            this.tlpCells.Controls.Add(this.pnlCell_02, 1, 0);
            this.tlpCells.Controls.Add(this.pnlCell_03, 2, 0);
            this.tlpCells.Controls.Add(this.pnlCell_04, 3, 0);
            this.tlpCells.Controls.Add(this.pnlCell_05, 0, 1);
            this.tlpCells.Controls.Add(this.pnlCell_06, 1, 1);
            this.tlpCells.Controls.Add(this.pnlCell_07, 2, 1);
            this.tlpCells.Controls.Add(this.pnlCell_08, 3, 1);
            this.tlpCells.Controls.Add(this.pnlCell_09, 0, 2);
            this.tlpCells.Controls.Add(this.pnlCell_10, 1, 2);
            this.tlpCells.Controls.Add(this.pnlCell_11, 2, 2);
            this.tlpCells.Controls.Add(this.pnlCell_12, 3, 2);
            this.tlpCells.Controls.Add(this.pnlCell_13, 0, 3);
            this.tlpCells.Controls.Add(this.pnlCell_14, 1, 3);
            this.tlpCells.Controls.Add(this.pnlCell_15, 2, 3);
            this.tlpCells.Controls.Add(this.pnlCell_16, 3, 3);
            this.tlpCells.Location = new System.Drawing.Point(12, 3);
            this.tlpCells.Name = "tlpCells";
            this.tlpCells.RowCount = 4;
            this.tlpCells.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tlpCells.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tlpCells.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tlpCells.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tlpCells.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tlpCells.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tlpCells.Size = new System.Drawing.Size(640, 640);
            this.tlpCells.TabIndex = 8;
            // 
            // pnlCell_01
            // 
            this.pnlCell_01.BackColor = System.Drawing.Color.Black;
            this.pnlCell_01.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_01.Controls.Add(this.lblCell_01);
            this.pnlCell_01.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_01.Location = new System.Drawing.Point(1, 1);
            this.pnlCell_01.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_01.Name = "pnlCell_01";
            this.pnlCell_01.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_01.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_01.TabIndex = 0;
            // 
            // lblCell_01
            // 
            this.lblCell_01.AllowDrop = true;
            this.lblCell_01.BackColor = System.Drawing.Color.Black;
            this.lblCell_01.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_01.ForeColor = System.Drawing.Color.White;
            this.lblCell_01.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_01.Image")));
            this.lblCell_01.Location = new System.Drawing.Point(1, 1);
            this.lblCell_01.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_01.Name = "lblCell_01";
            this.lblCell_01.Size = new System.Drawing.Size(156, 156);
            this.lblCell_01.TabIndex = 0;
            this.lblCell_01.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_01.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_01.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_01.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_02
            // 
            this.pnlCell_02.BackColor = System.Drawing.Color.Black;
            this.pnlCell_02.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_02.Controls.Add(this.lblCell_02);
            this.pnlCell_02.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_02.Location = new System.Drawing.Point(161, 1);
            this.pnlCell_02.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_02.Name = "pnlCell_02";
            this.pnlCell_02.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_02.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_02.TabIndex = 1;
            // 
            // lblCell_02
            // 
            this.lblCell_02.AllowDrop = true;
            this.lblCell_02.BackColor = System.Drawing.Color.Black;
            this.lblCell_02.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_02.ForeColor = System.Drawing.Color.White;
            this.lblCell_02.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_02.Image")));
            this.lblCell_02.Location = new System.Drawing.Point(1, 1);
            this.lblCell_02.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_02.Name = "lblCell_02";
            this.lblCell_02.Size = new System.Drawing.Size(156, 156);
            this.lblCell_02.TabIndex = 1;
            this.lblCell_02.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_02.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_02.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_02.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_03
            // 
            this.pnlCell_03.BackColor = System.Drawing.Color.Black;
            this.pnlCell_03.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_03.Controls.Add(this.lblCell_03);
            this.pnlCell_03.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_03.Location = new System.Drawing.Point(321, 1);
            this.pnlCell_03.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_03.Name = "pnlCell_03";
            this.pnlCell_03.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_03.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_03.TabIndex = 2;
            // 
            // lblCell_03
            // 
            this.lblCell_03.AllowDrop = true;
            this.lblCell_03.BackColor = System.Drawing.Color.Black;
            this.lblCell_03.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_03.ForeColor = System.Drawing.Color.White;
            this.lblCell_03.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_03.Image")));
            this.lblCell_03.Location = new System.Drawing.Point(1, 1);
            this.lblCell_03.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_03.Name = "lblCell_03";
            this.lblCell_03.Size = new System.Drawing.Size(156, 156);
            this.lblCell_03.TabIndex = 1;
            this.lblCell_03.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_03.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_03.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_03.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_04
            // 
            this.pnlCell_04.BackColor = System.Drawing.Color.Black;
            this.pnlCell_04.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_04.Controls.Add(this.lblCell_04);
            this.pnlCell_04.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_04.Location = new System.Drawing.Point(481, 1);
            this.pnlCell_04.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_04.Name = "pnlCell_04";
            this.pnlCell_04.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_04.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_04.TabIndex = 3;
            // 
            // lblCell_04
            // 
            this.lblCell_04.AllowDrop = true;
            this.lblCell_04.BackColor = System.Drawing.Color.Black;
            this.lblCell_04.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_04.ForeColor = System.Drawing.Color.White;
            this.lblCell_04.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_04.Image")));
            this.lblCell_04.Location = new System.Drawing.Point(1, 1);
            this.lblCell_04.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_04.Name = "lblCell_04";
            this.lblCell_04.Size = new System.Drawing.Size(156, 156);
            this.lblCell_04.TabIndex = 1;
            this.lblCell_04.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_04.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_04.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_04.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_05
            // 
            this.pnlCell_05.BackColor = System.Drawing.Color.Black;
            this.pnlCell_05.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_05.Controls.Add(this.lblCell_05);
            this.pnlCell_05.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_05.Location = new System.Drawing.Point(1, 161);
            this.pnlCell_05.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_05.Name = "pnlCell_05";
            this.pnlCell_05.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_05.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_05.TabIndex = 4;
            // 
            // lblCell_05
            // 
            this.lblCell_05.AllowDrop = true;
            this.lblCell_05.BackColor = System.Drawing.Color.Black;
            this.lblCell_05.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_05.ForeColor = System.Drawing.Color.White;
            this.lblCell_05.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_05.Image")));
            this.lblCell_05.Location = new System.Drawing.Point(1, 1);
            this.lblCell_05.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_05.Name = "lblCell_05";
            this.lblCell_05.Size = new System.Drawing.Size(156, 156);
            this.lblCell_05.TabIndex = 1;
            this.lblCell_05.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_05.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_05.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_05.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_06
            // 
            this.pnlCell_06.BackColor = System.Drawing.Color.Black;
            this.pnlCell_06.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_06.Controls.Add(this.lblCell_06);
            this.pnlCell_06.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_06.Location = new System.Drawing.Point(161, 161);
            this.pnlCell_06.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_06.Name = "pnlCell_06";
            this.pnlCell_06.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_06.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_06.TabIndex = 5;
            // 
            // lblCell_06
            // 
            this.lblCell_06.AllowDrop = true;
            this.lblCell_06.BackColor = System.Drawing.Color.Black;
            this.lblCell_06.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_06.ForeColor = System.Drawing.Color.White;
            this.lblCell_06.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_06.Image")));
            this.lblCell_06.Location = new System.Drawing.Point(1, 1);
            this.lblCell_06.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_06.Name = "lblCell_06";
            this.lblCell_06.Size = new System.Drawing.Size(156, 156);
            this.lblCell_06.TabIndex = 1;
            this.lblCell_06.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_06.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_06.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_06.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_07
            // 
            this.pnlCell_07.BackColor = System.Drawing.Color.Black;
            this.pnlCell_07.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_07.Controls.Add(this.lblCell_07);
            this.pnlCell_07.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_07.Location = new System.Drawing.Point(321, 161);
            this.pnlCell_07.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_07.Name = "pnlCell_07";
            this.pnlCell_07.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_07.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_07.TabIndex = 6;
            // 
            // lblCell_07
            // 
            this.lblCell_07.AllowDrop = true;
            this.lblCell_07.BackColor = System.Drawing.Color.Black;
            this.lblCell_07.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_07.ForeColor = System.Drawing.Color.White;
            this.lblCell_07.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_07.Image")));
            this.lblCell_07.Location = new System.Drawing.Point(1, 1);
            this.lblCell_07.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_07.Name = "lblCell_07";
            this.lblCell_07.Size = new System.Drawing.Size(156, 156);
            this.lblCell_07.TabIndex = 1;
            this.lblCell_07.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_07.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_07.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_07.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_08
            // 
            this.pnlCell_08.BackColor = System.Drawing.Color.Black;
            this.pnlCell_08.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_08.Controls.Add(this.lblCell_08);
            this.pnlCell_08.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_08.Location = new System.Drawing.Point(481, 161);
            this.pnlCell_08.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_08.Name = "pnlCell_08";
            this.pnlCell_08.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_08.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_08.TabIndex = 7;
            // 
            // lblCell_08
            // 
            this.lblCell_08.AllowDrop = true;
            this.lblCell_08.BackColor = System.Drawing.Color.Black;
            this.lblCell_08.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_08.ForeColor = System.Drawing.Color.White;
            this.lblCell_08.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_08.Image")));
            this.lblCell_08.Location = new System.Drawing.Point(1, 1);
            this.lblCell_08.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_08.Name = "lblCell_08";
            this.lblCell_08.Size = new System.Drawing.Size(156, 156);
            this.lblCell_08.TabIndex = 1;
            this.lblCell_08.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_08.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_08.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_08.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_09
            // 
            this.pnlCell_09.BackColor = System.Drawing.Color.Black;
            this.pnlCell_09.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_09.Controls.Add(this.lblCell_09);
            this.pnlCell_09.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_09.Location = new System.Drawing.Point(1, 321);
            this.pnlCell_09.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_09.Name = "pnlCell_09";
            this.pnlCell_09.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_09.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_09.TabIndex = 8;
            // 
            // lblCell_09
            // 
            this.lblCell_09.AllowDrop = true;
            this.lblCell_09.BackColor = System.Drawing.Color.Black;
            this.lblCell_09.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_09.ForeColor = System.Drawing.Color.White;
            this.lblCell_09.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_09.Image")));
            this.lblCell_09.Location = new System.Drawing.Point(1, 1);
            this.lblCell_09.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_09.Name = "lblCell_09";
            this.lblCell_09.Size = new System.Drawing.Size(156, 156);
            this.lblCell_09.TabIndex = 1;
            this.lblCell_09.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_09.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_09.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_09.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_10
            // 
            this.pnlCell_10.BackColor = System.Drawing.Color.Black;
            this.pnlCell_10.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_10.Controls.Add(this.lblCell_10);
            this.pnlCell_10.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_10.Location = new System.Drawing.Point(161, 321);
            this.pnlCell_10.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_10.Name = "pnlCell_10";
            this.pnlCell_10.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_10.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_10.TabIndex = 9;
            // 
            // lblCell_10
            // 
            this.lblCell_10.AllowDrop = true;
            this.lblCell_10.BackColor = System.Drawing.Color.Black;
            this.lblCell_10.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_10.ForeColor = System.Drawing.Color.White;
            this.lblCell_10.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_10.Image")));
            this.lblCell_10.Location = new System.Drawing.Point(1, 1);
            this.lblCell_10.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_10.Name = "lblCell_10";
            this.lblCell_10.Size = new System.Drawing.Size(156, 156);
            this.lblCell_10.TabIndex = 1;
            this.lblCell_10.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_10.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_10.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_10.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_11
            // 
            this.pnlCell_11.BackColor = System.Drawing.Color.Black;
            this.pnlCell_11.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_11.Controls.Add(this.lblCell_11);
            this.pnlCell_11.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_11.Location = new System.Drawing.Point(321, 321);
            this.pnlCell_11.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_11.Name = "pnlCell_11";
            this.pnlCell_11.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_11.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_11.TabIndex = 10;
            // 
            // lblCell_11
            // 
            this.lblCell_11.AllowDrop = true;
            this.lblCell_11.BackColor = System.Drawing.Color.Black;
            this.lblCell_11.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_11.ForeColor = System.Drawing.Color.White;
            this.lblCell_11.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_11.Image")));
            this.lblCell_11.Location = new System.Drawing.Point(1, 1);
            this.lblCell_11.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_11.Name = "lblCell_11";
            this.lblCell_11.Size = new System.Drawing.Size(156, 156);
            this.lblCell_11.TabIndex = 1;
            this.lblCell_11.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_11.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_11.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_11.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_12
            // 
            this.pnlCell_12.BackColor = System.Drawing.Color.Black;
            this.pnlCell_12.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_12.Controls.Add(this.lblCell_12);
            this.pnlCell_12.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_12.Location = new System.Drawing.Point(481, 321);
            this.pnlCell_12.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_12.Name = "pnlCell_12";
            this.pnlCell_12.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_12.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_12.TabIndex = 11;
            // 
            // lblCell_12
            // 
            this.lblCell_12.AllowDrop = true;
            this.lblCell_12.BackColor = System.Drawing.Color.Black;
            this.lblCell_12.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_12.ForeColor = System.Drawing.Color.White;
            this.lblCell_12.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_12.Image")));
            this.lblCell_12.Location = new System.Drawing.Point(1, 1);
            this.lblCell_12.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_12.Name = "lblCell_12";
            this.lblCell_12.Size = new System.Drawing.Size(156, 156);
            this.lblCell_12.TabIndex = 1;
            this.lblCell_12.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_12.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_12.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_12.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_13
            // 
            this.pnlCell_13.BackColor = System.Drawing.Color.Black;
            this.pnlCell_13.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_13.Controls.Add(this.lblCell_13);
            this.pnlCell_13.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_13.Location = new System.Drawing.Point(1, 481);
            this.pnlCell_13.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_13.Name = "pnlCell_13";
            this.pnlCell_13.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_13.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_13.TabIndex = 12;
            // 
            // lblCell_13
            // 
            this.lblCell_13.AllowDrop = true;
            this.lblCell_13.BackColor = System.Drawing.Color.Black;
            this.lblCell_13.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_13.ForeColor = System.Drawing.Color.White;
            this.lblCell_13.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_13.Image")));
            this.lblCell_13.Location = new System.Drawing.Point(1, 1);
            this.lblCell_13.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_13.Name = "lblCell_13";
            this.lblCell_13.Size = new System.Drawing.Size(156, 156);
            this.lblCell_13.TabIndex = 1;
            this.lblCell_13.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_13.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_13.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_13.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_14
            // 
            this.pnlCell_14.BackColor = System.Drawing.Color.Black;
            this.pnlCell_14.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_14.Controls.Add(this.lblCell_14);
            this.pnlCell_14.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_14.Location = new System.Drawing.Point(161, 481);
            this.pnlCell_14.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_14.Name = "pnlCell_14";
            this.pnlCell_14.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_14.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_14.TabIndex = 13;
            // 
            // lblCell_14
            // 
            this.lblCell_14.AllowDrop = true;
            this.lblCell_14.BackColor = System.Drawing.Color.Black;
            this.lblCell_14.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_14.ForeColor = System.Drawing.Color.White;
            this.lblCell_14.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_14.Image")));
            this.lblCell_14.Location = new System.Drawing.Point(1, 1);
            this.lblCell_14.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_14.Name = "lblCell_14";
            this.lblCell_14.Size = new System.Drawing.Size(156, 156);
            this.lblCell_14.TabIndex = 1;
            this.lblCell_14.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_14.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_14.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_14.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_15
            // 
            this.pnlCell_15.BackColor = System.Drawing.Color.Black;
            this.pnlCell_15.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_15.Controls.Add(this.lblCell_15);
            this.pnlCell_15.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_15.Location = new System.Drawing.Point(321, 481);
            this.pnlCell_15.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_15.Name = "pnlCell_15";
            this.pnlCell_15.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_15.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_15.TabIndex = 14;
            // 
            // lblCell_15
            // 
            this.lblCell_15.AllowDrop = true;
            this.lblCell_15.BackColor = System.Drawing.Color.Black;
            this.lblCell_15.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_15.ForeColor = System.Drawing.Color.White;
            this.lblCell_15.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_15.Image")));
            this.lblCell_15.Location = new System.Drawing.Point(1, 1);
            this.lblCell_15.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_15.Name = "lblCell_15";
            this.lblCell_15.Size = new System.Drawing.Size(156, 156);
            this.lblCell_15.TabIndex = 1;
            this.lblCell_15.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_15.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_15.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_15.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // pnlCell_16
            // 
            this.pnlCell_16.BackColor = System.Drawing.Color.Black;
            this.pnlCell_16.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pnlCell_16.Controls.Add(this.lblCell_16);
            this.pnlCell_16.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCell_16.Location = new System.Drawing.Point(481, 481);
            this.pnlCell_16.Margin = new System.Windows.Forms.Padding(1);
            this.pnlCell_16.Name = "pnlCell_16";
            this.pnlCell_16.Padding = new System.Windows.Forms.Padding(1);
            this.pnlCell_16.Size = new System.Drawing.Size(158, 158);
            this.pnlCell_16.TabIndex = 15;
            // 
            // lblCell_16
            // 
            this.lblCell_16.AllowDrop = true;
            this.lblCell_16.BackColor = System.Drawing.Color.Black;
            this.lblCell_16.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCell_16.ForeColor = System.Drawing.Color.White;
            this.lblCell_16.Image = ((System.Drawing.Image)(resources.GetObject("lblCell_16.Image")));
            this.lblCell_16.Location = new System.Drawing.Point(1, 1);
            this.lblCell_16.Margin = new System.Windows.Forms.Padding(1);
            this.lblCell_16.Name = "lblCell_16";
            this.lblCell_16.Size = new System.Drawing.Size(156, 156);
            this.lblCell_16.TabIndex = 1;
            this.lblCell_16.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblCell_16.Click += new System.EventHandler(this.LabelCell_Click);
            this.lblCell_16.DragDrop += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragDrop);
            this.lblCell_16.DragEnter += new System.Windows.Forms.DragEventHandler(this.LabelCell_OnDragEnter);
            // 
            // cbxLayouts
            // 
            this.cbxLayouts.FormattingEnabled = true;
            this.cbxLayouts.Items.AddRange(new object[] {
            "1x1",
            "1x2",
            "2x1",
            "2x2",
            "2x3",
            "3x2",
            "3x3",
            "4x3",
            "4x4",
            "1+12",
            "2+8",
            "3+4",
            "1+5",
            "1+7",
            "12+1",
            "8+2",
            "1+4 (tall)",
            "1+4 (wide)"});
            this.cbxLayouts.Location = new System.Drawing.Point(11, 19);
            this.cbxLayouts.Name = "cbxLayouts";
            this.cbxLayouts.Size = new System.Drawing.Size(121, 21);
            this.cbxLayouts.TabIndex = 9;
            this.cbxLayouts.SelectedIndexChanged += new System.EventHandler(this.ComboBoxLayouts_SelectedIndexChanged);
            // 
            // nudSpeed
            // 
            this.nudSpeed.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.nudSpeed.DecimalPlaces = 1;
            this.nudSpeed.Location = new System.Drawing.Point(16, 20);
            this.nudSpeed.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.nudSpeed.Minimum = new decimal(new int[] {
            300,
            0,
            0,
            -2147483648});
            this.nudSpeed.Name = "nudSpeed";
            this.nudSpeed.Size = new System.Drawing.Size(50, 20);
            this.nudSpeed.TabIndex = 46;
            this.nudSpeed.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // btnLive
            // 
            this.btnLive.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnLive.Location = new System.Drawing.Point(193, 20);
            this.btnLive.Name = "btnLive";
            this.btnLive.Size = new System.Drawing.Size(45, 22);
            this.btnLive.TabIndex = 44;
            this.btnLive.Text = "Live";
            this.btnLive.UseVisualStyleBackColor = true;
            this.btnLive.Click += new System.EventHandler(this.ButtonLive_Click);
            // 
            // btnSetTime
            // 
            this.btnSetTime.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnSetTime.Location = new System.Drawing.Point(142, 20);
            this.btnSetTime.Name = "btnSetTime";
            this.btnSetTime.Size = new System.Drawing.Size(45, 22);
            this.btnSetTime.TabIndex = 43;
            this.btnSetTime.Text = "Set";
            this.btnSetTime.UseVisualStyleBackColor = true;
            this.btnSetTime.Click += new System.EventHandler(this.ButtonSetTime_Click);
            // 
            // btnSetSpeed
            // 
            this.btnSetSpeed.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnSetSpeed.Location = new System.Drawing.Point(72, 19);
            this.btnSetSpeed.Name = "btnSetSpeed";
            this.btnSetSpeed.Size = new System.Drawing.Size(49, 22);
            this.btnSetSpeed.TabIndex = 42;
            this.btnSetSpeed.Text = "Set";
            this.btnSetSpeed.UseVisualStyleBackColor = true;
            this.btnSetSpeed.Click += new System.EventHandler(this.ButtonSetSpeed_Click);
            // 
            // dtpTime
            // 
            this.dtpTime.CustomFormat = "MM/dd/yyyy HH:mm:ss";
            this.dtpTime.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpTime.Location = new System.Drawing.Point(6, 19);
            this.dtpTime.Name = "dtpTime";
            this.dtpTime.ShowUpDown = true;
            this.dtpTime.Size = new System.Drawing.Size(130, 20);
            this.dtpTime.TabIndex = 47;
            this.dtpTime.Value = new System.DateTime(2016, 12, 12, 17, 3, 46, 0);
            // 
            // gbxTime
            // 
            this.gbxTime.Controls.Add(this.dtpTime);
            this.gbxTime.Controls.Add(this.btnSetTime);
            this.gbxTime.Controls.Add(this.btnLive);
            this.gbxTime.Location = new System.Drawing.Point(405, 650);
            this.gbxTime.Name = "gbxTime";
            this.gbxTime.Size = new System.Drawing.Size(246, 47);
            this.gbxTime.TabIndex = 48;
            this.gbxTime.TabStop = false;
            this.gbxTime.Text = "Time";
            // 
            // gbxSpeed
            // 
            this.gbxSpeed.Controls.Add(this.nudSpeed);
            this.gbxSpeed.Controls.Add(this.btnSetSpeed);
            this.gbxSpeed.Location = new System.Drawing.Point(240, 650);
            this.gbxSpeed.Name = "gbxSpeed";
            this.gbxSpeed.Size = new System.Drawing.Size(137, 47);
            this.gbxSpeed.TabIndex = 49;
            this.gbxSpeed.TabStop = false;
            this.gbxSpeed.Text = "Speed";
            // 
            // gbxMonitorLayout
            // 
            this.gbxMonitorLayout.Controls.Add(this.cbxLayouts);
            this.gbxMonitorLayout.Controls.Add(this.btnRefresh);
            this.gbxMonitorLayout.Location = new System.Drawing.Point(12, 650);
            this.gbxMonitorLayout.Name = "gbxMonitorLayout";
            this.gbxMonitorLayout.Size = new System.Drawing.Size(200, 47);
            this.gbxMonitorLayout.TabIndex = 50;
            this.gbxMonitorLayout.TabStop = false;
            this.gbxMonitorLayout.Text = "Monitor Layout";
            // 
            // ViewMonitorForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(982, 699);
            this.Controls.Add(this.gbxMonitorLayout);
            this.Controls.Add(this.gbxSpeed);
            this.Controls.Add(this.gbxTime);
            this.Controls.Add(this.tlpCells);
            this.Controls.Add(this.lvDataSources);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ViewMonitorForm";
            this.ShowIcon = false;
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "View Monitor";
            this.tlpCells.ResumeLayout(false);
            this.pnlCell_01.ResumeLayout(false);
            this.pnlCell_02.ResumeLayout(false);
            this.pnlCell_03.ResumeLayout(false);
            this.pnlCell_04.ResumeLayout(false);
            this.pnlCell_05.ResumeLayout(false);
            this.pnlCell_06.ResumeLayout(false);
            this.pnlCell_07.ResumeLayout(false);
            this.pnlCell_08.ResumeLayout(false);
            this.pnlCell_09.ResumeLayout(false);
            this.pnlCell_10.ResumeLayout(false);
            this.pnlCell_11.ResumeLayout(false);
            this.pnlCell_12.ResumeLayout(false);
            this.pnlCell_13.ResumeLayout(false);
            this.pnlCell_14.ResumeLayout(false);
            this.pnlCell_15.ResumeLayout(false);
            this.pnlCell_16.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.nudSpeed)).EndInit();
            this.gbxTime.ResumeLayout(false);
            this.gbxSpeed.ResumeLayout(false);
            this.gbxMonitorLayout.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        public System.Windows.Forms.ListView lvDataSources;
        private System.Windows.Forms.ColumnHeader colHeadName;
        private System.Windows.Forms.ColumnHeader colHeadIp;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.TableLayoutPanel tlpCells;
        private System.Windows.Forms.ComboBox cbxLayouts;
        private System.Windows.Forms.Label lblCell_01;
        private System.Windows.Forms.Label lblCell_03;
        private System.Windows.Forms.Label lblCell_04;
        private System.Windows.Forms.Label lblCell_05;
        private System.Windows.Forms.Label lblCell_06;
        private System.Windows.Forms.Label lblCell_07;
        private System.Windows.Forms.Label lblCell_08;
        private System.Windows.Forms.Label lblCell_09;
        private System.Windows.Forms.Label lblCell_10;
        private System.Windows.Forms.Label lblCell_11;
        private System.Windows.Forms.Label lblCell_12;
        private System.Windows.Forms.Label lblCell_13;
        private System.Windows.Forms.Label lblCell_14;
        private System.Windows.Forms.Label lblCell_15;
        private System.Windows.Forms.Label lblCell_16;
        private System.Windows.Forms.Label lblCell_02;
        private System.Windows.Forms.Panel pnlCell_01;
        private System.Windows.Forms.Panel pnlCell_02;
        private System.Windows.Forms.Panel pnlCell_03;
        private System.Windows.Forms.Panel pnlCell_04;
        private System.Windows.Forms.Panel pnlCell_05;
        private System.Windows.Forms.Panel pnlCell_06;
        private System.Windows.Forms.Panel pnlCell_07;
        private System.Windows.Forms.Panel pnlCell_08;
        private System.Windows.Forms.Panel pnlCell_09;
        private System.Windows.Forms.Panel pnlCell_10;
        private System.Windows.Forms.Panel pnlCell_11;
        private System.Windows.Forms.Panel pnlCell_12;
        private System.Windows.Forms.Panel pnlCell_13;
        private System.Windows.Forms.Panel pnlCell_14;
        private System.Windows.Forms.Panel pnlCell_15;
        private System.Windows.Forms.Panel pnlCell_16;
        private System.Windows.Forms.NumericUpDown nudSpeed;
        public System.Windows.Forms.Button btnLive;
        public System.Windows.Forms.Button btnSetTime;
        public System.Windows.Forms.Button btnSetSpeed;
        private System.Windows.Forms.DateTimePicker dtpTime;
        private System.Windows.Forms.GroupBox gbxTime;
        private System.Windows.Forms.GroupBox gbxSpeed;
        private System.Windows.Forms.GroupBox gbxMonitorLayout;
    }
}