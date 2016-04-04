using System;
using System.Windows.Forms;

namespace SDKSampleApp.Source
{
    partial class PTZControlForm
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
            this.gbPatterns = new System.Windows.Forms.GroupBox();
            this.btnStop = new System.Windows.Forms.Button();
            this.cbxPatterns = new System.Windows.Forms.ComboBox();
            this.btnTriggerPattern = new System.Windows.Forms.Button();
            this.gbPresets = new System.Windows.Forms.GroupBox();
            this.cbxPresets = new System.Windows.Forms.ComboBox();
            this.btnTriggerPreset = new System.Windows.Forms.Button();
            this.btnPtzZoomOut = new System.Windows.Forms.Button();
            this.btnPtzZoomIn = new System.Windows.Forms.Button();
            this.btnPtzUR = new System.Windows.Forms.Button();
            this.btnPtzUL = new System.Windows.Forms.Button();
            this.btnPtzDL = new System.Windows.Forms.Button();
            this.btnPtzDR = new System.Windows.Forms.Button();
            this.btnPtzD = new System.Windows.Forms.Button();
            this.btnPtzR = new System.Windows.Forms.Button();
            this.btnPtzL = new System.Windows.Forms.Button();
            this.btnPtzU = new System.Windows.Forms.Button();
            this.btnPtzFocusFar = new System.Windows.Forms.Button();
            this.btnPtzIrisClose = new System.Windows.Forms.Button();
            this.btnPtzIrisOpen = new System.Windows.Forms.Button();
            this.btnPtzFocusNear = new System.Windows.Forms.Button();
            this.lblZoom = new System.Windows.Forms.Label();
            this.lblFocus = new System.Windows.Forms.Label();
            this.lblIris = new System.Windows.Forms.Label();
            this.gbAbsoluteMove = new System.Windows.Forms.GroupBox();
            this.btnSetPosition = new System.Windows.Forms.Button();
            this.btnGetPosition = new System.Windows.Forms.Button();
            this.lblAbsZ = new System.Windows.Forms.Label();
            this.lblAbsY = new System.Windows.Forms.Label();
            this.lblAbsX = new System.Windows.Forms.Label();
            this.txbxAbsZ = new System.Windows.Forms.TextBox();
            this.txbxAbsY = new System.Windows.Forms.TextBox();
            this.txbxAbsX = new System.Windows.Forms.TextBox();
            this.gbRelativeMove = new System.Windows.Forms.GroupBox();
            this.btnMove = new System.Windows.Forms.Button();
            this.lblRelZ = new System.Windows.Forms.Label();
            this.lblRelY = new System.Windows.Forms.Label();
            this.lblRelX = new System.Windows.Forms.Label();
            this.txbxRelZ = new System.Windows.Forms.TextBox();
            this.txbxRelY = new System.Windows.Forms.TextBox();
            this.txbxRelX = new System.Windows.Forms.TextBox();
            this.gbPtzLock = new System.Windows.Forms.GroupBox();
            this.lblExpireTime = new System.Windows.Forms.Label();
            this.lblLockOwner = new System.Windows.Forms.Label();
            this.btnLock = new System.Windows.Forms.Button();
            this.btnRefreshLock = new System.Windows.Forms.Button();
            this.gbPatterns.SuspendLayout();
            this.gbPresets.SuspendLayout();
            this.gbAbsoluteMove.SuspendLayout();
            this.gbRelativeMove.SuspendLayout();
            this.gbPtzLock.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbPatterns
            // 
            this.gbPatterns.Controls.Add(this.btnStop);
            this.gbPatterns.Controls.Add(this.cbxPatterns);
            this.gbPatterns.Controls.Add(this.btnTriggerPattern);
            this.gbPatterns.Location = new System.Drawing.Point(12, 185);
            this.gbPatterns.Name = "gbPatterns";
            this.gbPatterns.Size = new System.Drawing.Size(210, 75);
            this.gbPatterns.TabIndex = 46;
            this.gbPatterns.TabStop = false;
            this.gbPatterns.Text = "Patterns";
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(77, 46);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(60, 21);
            this.btnStop.TabIndex = 33;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.MouseDown += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // cbxPatterns
            // 
            this.cbxPatterns.FormattingEnabled = true;
            this.cbxPatterns.Location = new System.Drawing.Point(6, 19);
            this.cbxPatterns.Name = "cbxPatterns";
            this.cbxPatterns.Size = new System.Drawing.Size(196, 21);
            this.cbxPatterns.TabIndex = 31;
            // 
            // btnTriggerPattern
            // 
            this.btnTriggerPattern.Location = new System.Drawing.Point(142, 46);
            this.btnTriggerPattern.Name = "btnTriggerPattern";
            this.btnTriggerPattern.Size = new System.Drawing.Size(60, 21);
            this.btnTriggerPattern.TabIndex = 32;
            this.btnTriggerPattern.Text = "Trigger";
            this.btnTriggerPattern.UseVisualStyleBackColor = true;
            this.btnTriggerPattern.Click += new System.EventHandler(this.ButtonTriggerPattern_Click);
            // 
            // gbPresets
            // 
            this.gbPresets.Controls.Add(this.cbxPresets);
            this.gbPresets.Controls.Add(this.btnTriggerPreset);
            this.gbPresets.Location = new System.Drawing.Point(12, 104);
            this.gbPresets.Name = "gbPresets";
            this.gbPresets.Size = new System.Drawing.Size(210, 75);
            this.gbPresets.TabIndex = 45;
            this.gbPresets.TabStop = false;
            this.gbPresets.Text = "Presets";
            // 
            // cbxPresets
            // 
            this.cbxPresets.FormattingEnabled = true;
            this.cbxPresets.Location = new System.Drawing.Point(6, 19);
            this.cbxPresets.Name = "cbxPresets";
            this.cbxPresets.Size = new System.Drawing.Size(198, 21);
            this.cbxPresets.TabIndex = 31;
            // 
            // btnTriggerPreset
            // 
            this.btnTriggerPreset.Location = new System.Drawing.Point(142, 46);
            this.btnTriggerPreset.Name = "btnTriggerPreset";
            this.btnTriggerPreset.Size = new System.Drawing.Size(60, 21);
            this.btnTriggerPreset.TabIndex = 32;
            this.btnTriggerPreset.Text = "Trigger";
            this.btnTriggerPreset.UseVisualStyleBackColor = true;
            this.btnTriggerPreset.Click += new System.EventHandler(this.ButtonTriggerPreset_Click);
            // 
            // btnPtzZoomOut
            // 
            this.btnPtzZoomOut.Location = new System.Drawing.Point(117, 68);
            this.btnPtzZoomOut.Name = "btnPtzZoomOut";
            this.btnPtzZoomOut.Size = new System.Drawing.Size(31, 30);
            this.btnPtzZoomOut.TabIndex = 44;
            this.btnPtzZoomOut.Text = "-";
            this.btnPtzZoomOut.UseVisualStyleBackColor = true;
            this.btnPtzZoomOut.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzZoomOut_Click);
            this.btnPtzZoomOut.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzZoomIn
            // 
            this.btnPtzZoomIn.Location = new System.Drawing.Point(117, 10);
            this.btnPtzZoomIn.Name = "btnPtzZoomIn";
            this.btnPtzZoomIn.Size = new System.Drawing.Size(31, 30);
            this.btnPtzZoomIn.TabIndex = 43;
            this.btnPtzZoomIn.Text = "+";
            this.btnPtzZoomIn.UseVisualStyleBackColor = true;
            this.btnPtzZoomIn.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzZoomIn_Click);
            this.btnPtzZoomIn.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzUR
            // 
            this.btnPtzUR.Location = new System.Drawing.Point(70, 10);
            this.btnPtzUR.Name = "btnPtzUR";
            this.btnPtzUR.Size = new System.Drawing.Size(31, 30);
            this.btnPtzUR.TabIndex = 42;
            this.btnPtzUR.Text = "UR";
            this.btnPtzUR.UseVisualStyleBackColor = true;
            this.btnPtzUR.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzUR_Click);
            this.btnPtzUR.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzUL
            // 
            this.btnPtzUL.Location = new System.Drawing.Point(12, 10);
            this.btnPtzUL.Name = "btnPtzUL";
            this.btnPtzUL.Size = new System.Drawing.Size(30, 30);
            this.btnPtzUL.TabIndex = 41;
            this.btnPtzUL.Text = "UL";
            this.btnPtzUL.UseVisualStyleBackColor = true;
            this.btnPtzUL.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzUL_Click);
            this.btnPtzUL.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzDL
            // 
            this.btnPtzDL.Location = new System.Drawing.Point(12, 68);
            this.btnPtzDL.Name = "btnPtzDL";
            this.btnPtzDL.Size = new System.Drawing.Size(30, 30);
            this.btnPtzDL.TabIndex = 40;
            this.btnPtzDL.Text = "DL";
            this.btnPtzDL.UseVisualStyleBackColor = true;
            this.btnPtzDL.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzDL_Click);
            this.btnPtzDL.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzDR
            // 
            this.btnPtzDR.Location = new System.Drawing.Point(70, 68);
            this.btnPtzDR.Name = "btnPtzDR";
            this.btnPtzDR.Size = new System.Drawing.Size(31, 30);
            this.btnPtzDR.TabIndex = 39;
            this.btnPtzDR.Text = "DR";
            this.btnPtzDR.UseVisualStyleBackColor = true;
            this.btnPtzDR.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzDR_Click);
            this.btnPtzDR.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzD
            // 
            this.btnPtzD.Location = new System.Drawing.Point(41, 68);
            this.btnPtzD.Name = "btnPtzD";
            this.btnPtzD.Size = new System.Drawing.Size(30, 30);
            this.btnPtzD.TabIndex = 38;
            this.btnPtzD.Text = "D";
            this.btnPtzD.UseVisualStyleBackColor = true;
            this.btnPtzD.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzD_Click);
            this.btnPtzD.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzR
            // 
            this.btnPtzR.Location = new System.Drawing.Point(70, 39);
            this.btnPtzR.Name = "btnPtzR";
            this.btnPtzR.Size = new System.Drawing.Size(31, 30);
            this.btnPtzR.TabIndex = 37;
            this.btnPtzR.Text = "R";
            this.btnPtzR.UseVisualStyleBackColor = true;
            this.btnPtzR.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzR_Click);
            this.btnPtzR.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzL
            // 
            this.btnPtzL.Location = new System.Drawing.Point(12, 39);
            this.btnPtzL.Name = "btnPtzL";
            this.btnPtzL.Size = new System.Drawing.Size(30, 30);
            this.btnPtzL.TabIndex = 36;
            this.btnPtzL.Text = "L";
            this.btnPtzL.UseVisualStyleBackColor = true;
            this.btnPtzL.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzL_Click);
            this.btnPtzL.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzU
            // 
            this.btnPtzU.Location = new System.Drawing.Point(41, 10);
            this.btnPtzU.Name = "btnPtzU";
            this.btnPtzU.Size = new System.Drawing.Size(30, 30);
            this.btnPtzU.TabIndex = 35;
            this.btnPtzU.Text = "U";
            this.btnPtzU.UseVisualStyleBackColor = true;
            this.btnPtzU.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzU_Click);
            this.btnPtzU.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzFocusFar
            // 
            this.btnPtzFocusFar.Location = new System.Drawing.Point(154, 68);
            this.btnPtzFocusFar.Name = "btnPtzFocusFar";
            this.btnPtzFocusFar.Size = new System.Drawing.Size(31, 30);
            this.btnPtzFocusFar.TabIndex = 47;
            this.btnPtzFocusFar.Text = "-";
            this.btnPtzFocusFar.UseVisualStyleBackColor = true;
            this.btnPtzFocusFar.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzFocusFar_Click);
            this.btnPtzFocusFar.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzIrisClose
            // 
            this.btnPtzIrisClose.Location = new System.Drawing.Point(191, 68);
            this.btnPtzIrisClose.Name = "btnPtzIrisClose";
            this.btnPtzIrisClose.Size = new System.Drawing.Size(31, 30);
            this.btnPtzIrisClose.TabIndex = 48;
            this.btnPtzIrisClose.Text = "-";
            this.btnPtzIrisClose.UseVisualStyleBackColor = true;
            this.btnPtzIrisClose.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzIrisClose_Click);
            this.btnPtzIrisClose.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzIrisOpen
            // 
            this.btnPtzIrisOpen.Location = new System.Drawing.Point(191, 10);
            this.btnPtzIrisOpen.Name = "btnPtzIrisOpen";
            this.btnPtzIrisOpen.Size = new System.Drawing.Size(31, 30);
            this.btnPtzIrisOpen.TabIndex = 50;
            this.btnPtzIrisOpen.Text = "+";
            this.btnPtzIrisOpen.UseVisualStyleBackColor = true;
            this.btnPtzIrisOpen.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzIrisOpen_Click);
            this.btnPtzIrisOpen.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // btnPtzFocusNear
            // 
            this.btnPtzFocusNear.Location = new System.Drawing.Point(154, 10);
            this.btnPtzFocusNear.Name = "btnPtzFocusNear";
            this.btnPtzFocusNear.Size = new System.Drawing.Size(31, 30);
            this.btnPtzFocusNear.TabIndex = 49;
            this.btnPtzFocusNear.Text = "+";
            this.btnPtzFocusNear.UseVisualStyleBackColor = true;
            this.btnPtzFocusNear.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ButtonPtzFocusNear_Click);
            this.btnPtzFocusNear.MouseUp += new System.Windows.Forms.MouseEventHandler(this.StopPtz);
            // 
            // lblZoom
            // 
            this.lblZoom.AutoSize = true;
            this.lblZoom.Location = new System.Drawing.Point(115, 47);
            this.lblZoom.Name = "lblZoom";
            this.lblZoom.Size = new System.Drawing.Size(34, 13);
            this.lblZoom.TabIndex = 51;
            this.lblZoom.Text = "Zoom";
            // 
            // lblFocus
            // 
            this.lblFocus.AutoSize = true;
            this.lblFocus.Location = new System.Drawing.Point(151, 47);
            this.lblFocus.Name = "lblFocus";
            this.lblFocus.Size = new System.Drawing.Size(36, 13);
            this.lblFocus.TabIndex = 52;
            this.lblFocus.Text = "Focus";
            // 
            // lblIris
            // 
            this.lblIris.AutoSize = true;
            this.lblIris.Location = new System.Drawing.Point(196, 47);
            this.lblIris.Name = "lblIris";
            this.lblIris.Size = new System.Drawing.Size(20, 13);
            this.lblIris.TabIndex = 53;
            this.lblIris.Text = "Iris";
            // 
            // gbAbsoluteMove
            // 
            this.gbAbsoluteMove.Controls.Add(this.btnSetPosition);
            this.gbAbsoluteMove.Controls.Add(this.btnGetPosition);
            this.gbAbsoluteMove.Controls.Add(this.lblAbsZ);
            this.gbAbsoluteMove.Controls.Add(this.lblAbsY);
            this.gbAbsoluteMove.Controls.Add(this.lblAbsX);
            this.gbAbsoluteMove.Controls.Add(this.txbxAbsZ);
            this.gbAbsoluteMove.Controls.Add(this.txbxAbsY);
            this.gbAbsoluteMove.Controls.Add(this.txbxAbsX);
            this.gbAbsoluteMove.Location = new System.Drawing.Point(12, 266);
            this.gbAbsoluteMove.Name = "gbAbsoluteMove";
            this.gbAbsoluteMove.Size = new System.Drawing.Size(210, 78);
            this.gbAbsoluteMove.TabIndex = 54;
            this.gbAbsoluteMove.TabStop = false;
            this.gbAbsoluteMove.Text = "Absolute Move";
            // 
            // btnSetPosition
            // 
            this.btnSetPosition.Location = new System.Drawing.Point(122, 45);
            this.btnSetPosition.Name = "btnSetPosition";
            this.btnSetPosition.Size = new System.Drawing.Size(75, 23);
            this.btnSetPosition.TabIndex = 7;
            this.btnSetPosition.Text = "Set Position";
            this.btnSetPosition.UseVisualStyleBackColor = true;
            this.btnSetPosition.Click += new System.EventHandler(this.ButtonSetPosition_Click);
            // 
            // btnGetPosition
            // 
            this.btnGetPosition.Location = new System.Drawing.Point(28, 45);
            this.btnGetPosition.Name = "btnGetPosition";
            this.btnGetPosition.Size = new System.Drawing.Size(75, 23);
            this.btnGetPosition.TabIndex = 6;
            this.btnGetPosition.Text = "Get Position";
            this.btnGetPosition.UseVisualStyleBackColor = true;
            this.btnGetPosition.Click += new System.EventHandler(this.ButtonGetPosition_Click);
            // 
            // lblAbsZ
            // 
            this.lblAbsZ.AutoSize = true;
            this.lblAbsZ.Location = new System.Drawing.Point(138, 22);
            this.lblAbsZ.Name = "lblAbsZ";
            this.lblAbsZ.Size = new System.Drawing.Size(14, 13);
            this.lblAbsZ.TabIndex = 5;
            this.lblAbsZ.Text = "Z";
            // 
            // lblAbsY
            // 
            this.lblAbsY.AutoSize = true;
            this.lblAbsY.Location = new System.Drawing.Point(73, 22);
            this.lblAbsY.Name = "lblAbsY";
            this.lblAbsY.Size = new System.Drawing.Size(14, 13);
            this.lblAbsY.TabIndex = 4;
            this.lblAbsY.Text = "Y";
            // 
            // lblAbsX
            // 
            this.lblAbsX.AutoSize = true;
            this.lblAbsX.Location = new System.Drawing.Point(8, 22);
            this.lblAbsX.Name = "lblAbsX";
            this.lblAbsX.Size = new System.Drawing.Size(14, 13);
            this.lblAbsX.TabIndex = 3;
            this.lblAbsX.Text = "X";
            // 
            // txbxAbsZ
            // 
            this.txbxAbsZ.Location = new System.Drawing.Point(158, 19);
            this.txbxAbsZ.Name = "txbxAbsZ";
            this.txbxAbsZ.Size = new System.Drawing.Size(39, 20);
            this.txbxAbsZ.TabIndex = 2;
            // 
            // txbxAbsY
            // 
            this.txbxAbsY.Location = new System.Drawing.Point(93, 19);
            this.txbxAbsY.Name = "txbxAbsY";
            this.txbxAbsY.Size = new System.Drawing.Size(39, 20);
            this.txbxAbsY.TabIndex = 1;
            // 
            // txbxAbsX
            // 
            this.txbxAbsX.Location = new System.Drawing.Point(28, 19);
            this.txbxAbsX.Name = "txbxAbsX";
            this.txbxAbsX.Size = new System.Drawing.Size(39, 20);
            this.txbxAbsX.TabIndex = 0;
            // 
            // gbRelativeMove
            // 
            this.gbRelativeMove.Controls.Add(this.btnMove);
            this.gbRelativeMove.Controls.Add(this.lblRelZ);
            this.gbRelativeMove.Controls.Add(this.lblRelY);
            this.gbRelativeMove.Controls.Add(this.lblRelX);
            this.gbRelativeMove.Controls.Add(this.txbxRelZ);
            this.gbRelativeMove.Controls.Add(this.txbxRelY);
            this.gbRelativeMove.Controls.Add(this.txbxRelX);
            this.gbRelativeMove.Location = new System.Drawing.Point(12, 350);
            this.gbRelativeMove.Name = "gbRelativeMove";
            this.gbRelativeMove.Size = new System.Drawing.Size(210, 78);
            this.gbRelativeMove.TabIndex = 55;
            this.gbRelativeMove.TabStop = false;
            this.gbRelativeMove.Text = "Relative Move";
            // 
            // btnMove
            // 
            this.btnMove.Location = new System.Drawing.Point(142, 45);
            this.btnMove.Name = "btnMove";
            this.btnMove.Size = new System.Drawing.Size(55, 23);
            this.btnMove.TabIndex = 7;
            this.btnMove.Text = "Move";
            this.btnMove.UseVisualStyleBackColor = true;
            this.btnMove.Click += new System.EventHandler(this.ButtonMove_Click);
            // 
            // lblRelZ
            // 
            this.lblRelZ.AutoSize = true;
            this.lblRelZ.Location = new System.Drawing.Point(138, 22);
            this.lblRelZ.Name = "lblRelZ";
            this.lblRelZ.Size = new System.Drawing.Size(14, 13);
            this.lblRelZ.TabIndex = 5;
            this.lblRelZ.Text = "Z";
            // 
            // lblRelY
            // 
            this.lblRelY.AutoSize = true;
            this.lblRelY.Location = new System.Drawing.Point(73, 22);
            this.lblRelY.Name = "lblRelY";
            this.lblRelY.Size = new System.Drawing.Size(14, 13);
            this.lblRelY.TabIndex = 4;
            this.lblRelY.Text = "Y";
            // 
            // lblRelX
            // 
            this.lblRelX.AutoSize = true;
            this.lblRelX.Location = new System.Drawing.Point(8, 22);
            this.lblRelX.Name = "lblRelX";
            this.lblRelX.Size = new System.Drawing.Size(14, 13);
            this.lblRelX.TabIndex = 3;
            this.lblRelX.Text = "X";
            // 
            // txbxRelZ
            // 
            this.txbxRelZ.Location = new System.Drawing.Point(158, 19);
            this.txbxRelZ.Name = "txbxRelZ";
            this.txbxRelZ.Size = new System.Drawing.Size(39, 20);
            this.txbxRelZ.TabIndex = 2;
            this.txbxRelZ.Text = "0";
            // 
            // txbxRelY
            // 
            this.txbxRelY.Location = new System.Drawing.Point(93, 19);
            this.txbxRelY.Name = "txbxRelY";
            this.txbxRelY.Size = new System.Drawing.Size(39, 20);
            this.txbxRelY.TabIndex = 1;
            this.txbxRelY.Text = "0";
            // 
            // txbxRelX
            // 
            this.txbxRelX.Location = new System.Drawing.Point(28, 19);
            this.txbxRelX.Name = "txbxRelX";
            this.txbxRelX.Size = new System.Drawing.Size(39, 20);
            this.txbxRelX.TabIndex = 0;
            this.txbxRelX.Text = "0";
            // 
            // gbPtzLock
            // 
            this.gbPtzLock.Controls.Add(this.lblExpireTime);
            this.gbPtzLock.Controls.Add(this.lblLockOwner);
            this.gbPtzLock.Controls.Add(this.btnLock);
            this.gbPtzLock.Controls.Add(this.btnRefreshLock);
            this.gbPtzLock.Location = new System.Drawing.Point(12, 434);
            this.gbPtzLock.Name = "gbPtzLock";
            this.gbPtzLock.Size = new System.Drawing.Size(200, 80);
            this.gbPtzLock.TabIndex = 56;
            this.gbPtzLock.TabStop = false;
            this.gbPtzLock.Text = "PTZ Lock";
            // 
            // lblExpireTime
            // 
            this.lblExpireTime.AutoSize = true;
            this.lblExpireTime.Location = new System.Drawing.Point(73, 53);
            this.lblExpireTime.Name = "lblExpireTime";
            this.lblExpireTime.Size = new System.Drawing.Size(47, 13);
            this.lblExpireTime.TabIndex = 12;
            this.lblExpireTime.Text = "Expires: ";
            // 
            // lblLockOwner
            // 
            this.lblLockOwner.AutoSize = true;
            this.lblLockOwner.Location = new System.Drawing.Point(76, 24);
            this.lblLockOwner.Name = "lblLockOwner";
            this.lblLockOwner.Size = new System.Drawing.Size(44, 13);
            this.lblLockOwner.TabIndex = 11;
            this.lblLockOwner.Text = "Owner: ";
            // 
            // btnLock
            // 
            this.btnLock.Location = new System.Drawing.Point(6, 19);
            this.btnLock.Name = "btnLock";
            this.btnLock.Size = new System.Drawing.Size(55, 23);
            this.btnLock.TabIndex = 10;
            this.btnLock.Text = "Lock";
            this.btnLock.UseVisualStyleBackColor = true;
            this.btnLock.Click += new System.EventHandler(this.ButtonLockClick);
            // 
            // btnRefreshLock
            // 
            this.btnRefreshLock.Location = new System.Drawing.Point(6, 48);
            this.btnRefreshLock.Name = "btnRefreshLock";
            this.btnRefreshLock.Size = new System.Drawing.Size(55, 23);
            this.btnRefreshLock.TabIndex = 8;
            this.btnRefreshLock.Text = "Refresh";
            this.btnRefreshLock.UseVisualStyleBackColor = true;
            this.btnRefreshLock.Click += new System.EventHandler(this.ButtonRefreshLock_Click);
            // 
            // PTZControlForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(230, 523);
            this.Controls.Add(this.gbPtzLock);
            this.Controls.Add(this.gbRelativeMove);
            this.Controls.Add(this.gbAbsoluteMove);
            this.Controls.Add(this.lblIris);
            this.Controls.Add(this.lblFocus);
            this.Controls.Add(this.lblZoom);
            this.Controls.Add(this.btnPtzIrisOpen);
            this.Controls.Add(this.btnPtzFocusNear);
            this.Controls.Add(this.btnPtzIrisClose);
            this.Controls.Add(this.btnPtzFocusFar);
            this.Controls.Add(this.gbPatterns);
            this.Controls.Add(this.gbPresets);
            this.Controls.Add(this.btnPtzZoomOut);
            this.Controls.Add(this.btnPtzZoomIn);
            this.Controls.Add(this.btnPtzUR);
            this.Controls.Add(this.btnPtzUL);
            this.Controls.Add(this.btnPtzDL);
            this.Controls.Add(this.btnPtzDR);
            this.Controls.Add(this.btnPtzD);
            this.Controls.Add(this.btnPtzR);
            this.Controls.Add(this.btnPtzL);
            this.Controls.Add(this.btnPtzU);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.SizableToolWindow;
            this.Name = "PTZControlForm";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "PTZ Control";
            this.TopMost = true;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.OnFormClosing);
            this.gbPatterns.ResumeLayout(false);
            this.gbPresets.ResumeLayout(false);
            this.gbAbsoluteMove.ResumeLayout(false);
            this.gbAbsoluteMove.PerformLayout();
            this.gbRelativeMove.ResumeLayout(false);
            this.gbRelativeMove.PerformLayout();
            this.gbPtzLock.ResumeLayout(false);
            this.gbPtzLock.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox gbPatterns;
        private System.Windows.Forms.ComboBox cbxPatterns;
        private System.Windows.Forms.Button btnTriggerPattern;
        private System.Windows.Forms.GroupBox gbPresets;
        private System.Windows.Forms.ComboBox cbxPresets;
        private System.Windows.Forms.Button btnTriggerPreset;
        private System.Windows.Forms.Button btnPtzZoomOut;
        private System.Windows.Forms.Button btnPtzZoomIn;
        private System.Windows.Forms.Button btnPtzUR;
        private System.Windows.Forms.Button btnPtzUL;
        private System.Windows.Forms.Button btnPtzDL;
        private System.Windows.Forms.Button btnPtzDR;
        private System.Windows.Forms.Button btnPtzD;
        private System.Windows.Forms.Button btnPtzR;
        private System.Windows.Forms.Button btnPtzL;
        private System.Windows.Forms.Button btnPtzU;
        private Button btnPtzFocusFar;
        private Button btnPtzIrisClose;
        private Button btnPtzIrisOpen;
        private Button btnPtzFocusNear;
        private Label lblZoom;
        private Label lblFocus;
        private Label lblIris;
        private GroupBox gbAbsoluteMove;
        private Label lblAbsZ;
        private Label lblAbsY;
        private Label lblAbsX;
        private TextBox txbxAbsZ;
        private TextBox txbxAbsY;
        private TextBox txbxAbsX;
        private Button btnSetPosition;
        private Button btnGetPosition;
        private GroupBox gbRelativeMove;
        private Button btnMove;
        private Label lblRelZ;
        private Label lblRelY;
        private Label lblRelX;
        private TextBox txbxRelZ;
        private TextBox txbxRelY;
        private Button btnStop;
        private TextBox txbxRelX;
        private GroupBox gbPtzLock;
        private Button btnLock;
        private Button btnRefreshLock;
        private Label lblExpireTime;
        private Label lblLockOwner;
    }
}