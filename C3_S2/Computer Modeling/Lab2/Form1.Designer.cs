
namespace Lab2
{
    partial class Form1
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button1 = new System.Windows.Forms.Button();
            this.numericUpDownBeta = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.numericUpDownSpeed = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownMu = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.numericUpDownb = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.numericUpDownRadius = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownWeight = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.label7 = new System.Windows.Forms.Label();
            this.numericUpDownH = new System.Windows.Forms.NumericUpDown();
            this.label8 = new System.Windows.Forms.Label();
            this.labelTextL = new System.Windows.Forms.Label();
            this.numericUpDownL = new System.Windows.Forms.NumericUpDown();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownBeta)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownSpeed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMu)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownb)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownRadius)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownWeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownH)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownL)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.numericUpDown1);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.numericUpDownH);
            this.groupBox1.Controls.Add(this.label8);
            this.groupBox1.Controls.Add(this.labelTextL);
            this.groupBox1.Controls.Add(this.numericUpDownL);
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Controls.Add(this.numericUpDownBeta);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.numericUpDownSpeed);
            this.groupBox1.Controls.Add(this.numericUpDownMu);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.numericUpDownb);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.numericUpDownRadius);
            this.groupBox1.Controls.Add(this.numericUpDownWeight);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Right;
            this.groupBox1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.groupBox1.Location = new System.Drawing.Point(1654, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(250, 1041);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 893);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(224, 61);
            this.button1.TabIndex = 1;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // numericUpDownBeta
            // 
            this.numericUpDownBeta.DecimalPlaces = 1;
            this.numericUpDownBeta.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.numericUpDownBeta.Location = new System.Drawing.Point(116, 305);
            this.numericUpDownBeta.Maximum = new decimal(new int[] {
            175,
            0,
            0,
            0});
            this.numericUpDownBeta.Minimum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDownBeta.Name = "numericUpDownBeta";
            this.numericUpDownBeta.Size = new System.Drawing.Size(120, 29);
            this.numericUpDownBeta.TabIndex = 11;
            this.numericUpDownBeta.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(8, 304);
            this.label4.Margin = new System.Windows.Forms.Padding(5);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(100, 30);
            this.label4.TabIndex = 10;
            this.label4.Text = "angle: ";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // numericUpDownSpeed
            // 
            this.numericUpDownSpeed.DecimalPlaces = 2;
            this.numericUpDownSpeed.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.numericUpDownSpeed.Location = new System.Drawing.Point(116, 258);
            this.numericUpDownSpeed.Maximum = new decimal(new int[] {
            60,
            0,
            0,
            0});
            this.numericUpDownSpeed.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownSpeed.Name = "numericUpDownSpeed";
            this.numericUpDownSpeed.Size = new System.Drawing.Size(120, 29);
            this.numericUpDownSpeed.TabIndex = 9;
            this.numericUpDownSpeed.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // numericUpDownMu
            // 
            this.numericUpDownMu.DecimalPlaces = 3;
            this.numericUpDownMu.Increment = new decimal(new int[] {
            1,
            0,
            0,
            196608});
            this.numericUpDownMu.Location = new System.Drawing.Point(116, 158);
            this.numericUpDownMu.Maximum = new decimal(new int[] {
            2,
            0,
            0,
            65536});
            this.numericUpDownMu.Minimum = new decimal(new int[] {
            15,
            0,
            0,
            131072});
            this.numericUpDownMu.Name = "numericUpDownMu";
            this.numericUpDownMu.Size = new System.Drawing.Size(120, 29);
            this.numericUpDownMu.TabIndex = 8;
            this.numericUpDownMu.Value = new decimal(new int[] {
            15,
            0,
            0,
            131072});
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(8, 257);
            this.label5.Margin = new System.Windows.Forms.Padding(5);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(100, 30);
            this.label5.TabIndex = 7;
            this.label5.Text = "Speed: ";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(8, 214);
            this.label6.Margin = new System.Windows.Forms.Padding(5);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(100, 30);
            this.label6.TabIndex = 6;
            this.label6.Text = "b: ";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // numericUpDownb
            // 
            this.numericUpDownb.DecimalPlaces = 3;
            this.numericUpDownb.Increment = new decimal(new int[] {
            1,
            0,
            0,
            196608});
            this.numericUpDownb.Location = new System.Drawing.Point(116, 215);
            this.numericUpDownb.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            196608});
            this.numericUpDownb.Minimum = new decimal(new int[] {
            30,
            0,
            0,
            196608});
            this.numericUpDownb.Name = "numericUpDownb";
            this.numericUpDownb.Size = new System.Drawing.Size(120, 29);
            this.numericUpDownb.TabIndex = 5;
            this.numericUpDownb.Value = new decimal(new int[] {
            30,
            0,
            0,
            196608});
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(8, 157);
            this.label3.Margin = new System.Windows.Forms.Padding(5);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(100, 30);
            this.label3.TabIndex = 4;
            this.label3.Text = "μ: ";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // numericUpDownRadius
            // 
            this.numericUpDownRadius.DecimalPlaces = 3;
            this.numericUpDownRadius.Increment = new decimal(new int[] {
            1,
            0,
            0,
            196608});
            this.numericUpDownRadius.Location = new System.Drawing.Point(116, 111);
            this.numericUpDownRadius.Maximum = new decimal(new int[] {
            200,
            0,
            0,
            196608});
            this.numericUpDownRadius.Minimum = new decimal(new int[] {
            30,
            0,
            0,
            196608});
            this.numericUpDownRadius.Name = "numericUpDownRadius";
            this.numericUpDownRadius.Size = new System.Drawing.Size(120, 29);
            this.numericUpDownRadius.TabIndex = 3;
            this.numericUpDownRadius.Value = new decimal(new int[] {
            30,
            0,
            0,
            196608});
            // 
            // numericUpDownWeight
            // 
            this.numericUpDownWeight.DecimalPlaces = 3;
            this.numericUpDownWeight.Increment = new decimal(new int[] {
            1,
            0,
            0,
            196608});
            this.numericUpDownWeight.Location = new System.Drawing.Point(116, 68);
            this.numericUpDownWeight.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            196608});
            this.numericUpDownWeight.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            196608});
            this.numericUpDownWeight.Name = "numericUpDownWeight";
            this.numericUpDownWeight.Size = new System.Drawing.Size(120, 29);
            this.numericUpDownWeight.TabIndex = 2;
            this.numericUpDownWeight.Value = new decimal(new int[] {
            10,
            0,
            0,
            196608});
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(8, 110);
            this.label2.Margin = new System.Windows.Forms.Padding(5);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(100, 30);
            this.label2.TabIndex = 1;
            this.label2.Text = "Radius: ";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(8, 67);
            this.label1.Margin = new System.Windows.Forms.Padding(5);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(100, 30);
            this.label1.TabIndex = 0;
            this.label1.Text = "Weight: ";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.DecimalPlaces = 1;
            this.numericUpDown1.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.numericUpDown1.Location = new System.Drawing.Point(116, 447);
            this.numericUpDown1.Maximum = new decimal(new int[] {
            175,
            0,
            0,
            0});
            this.numericUpDown1.Minimum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(120, 29);
            this.numericUpDown1.TabIndex = 17;
            this.numericUpDown1.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // label7
            // 
            this.label7.Location = new System.Drawing.Point(8, 446);
            this.label7.Margin = new System.Windows.Forms.Padding(5);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(100, 30);
            this.label7.TabIndex = 16;
            this.label7.Text = "a: ";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // numericUpDownH
            // 
            this.numericUpDownH.DecimalPlaces = 2;
            this.numericUpDownH.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.numericUpDownH.Location = new System.Drawing.Point(116, 400);
            this.numericUpDownH.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            131072});
            this.numericUpDownH.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownH.Name = "numericUpDownH";
            this.numericUpDownH.Size = new System.Drawing.Size(120, 29);
            this.numericUpDownH.TabIndex = 15;
            this.numericUpDownH.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label8
            // 
            this.label8.Location = new System.Drawing.Point(8, 399);
            this.label8.Margin = new System.Windows.Forms.Padding(5);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(100, 30);
            this.label8.TabIndex = 14;
            this.label8.Text = "H: ";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // labelTextL
            // 
            this.labelTextL.Location = new System.Drawing.Point(8, 356);
            this.labelTextL.Margin = new System.Windows.Forms.Padding(5);
            this.labelTextL.Name = "labelTextL";
            this.labelTextL.Size = new System.Drawing.Size(100, 30);
            this.labelTextL.TabIndex = 13;
            this.labelTextL.Text = "L: ";
            this.labelTextL.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // numericUpDownL
            // 
            this.numericUpDownL.DecimalPlaces = 3;
            this.numericUpDownL.Increment = new decimal(new int[] {
            1,
            0,
            0,
            196608});
            this.numericUpDownL.Location = new System.Drawing.Point(116, 357);
            this.numericUpDownL.Maximum = new decimal(new int[] {
            2000,
            0,
            0,
            196608});
            this.numericUpDownL.Minimum = new decimal(new int[] {
            300,
            0,
            0,
            196608});
            this.numericUpDownL.Name = "numericUpDownL";
            this.numericUpDownL.Size = new System.Drawing.Size(120, 29);
            this.numericUpDownL.TabIndex = 12;
            this.numericUpDownL.Value = new decimal(new int[] {
            300,
            0,
            0,
            196608});
            // 
            // Form1
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.ClientSize = new System.Drawing.Size(1904, 1041);
            this.Controls.Add(this.groupBox1);
            this.DoubleBuffered = true;
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MinimumSize = new System.Drawing.Size(1920, 1080);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownBeta)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownSpeed)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownMu)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownb)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownRadius)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownWeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownH)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownL)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.NumericUpDown numericUpDownBeta;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown numericUpDownSpeed;
        private System.Windows.Forms.NumericUpDown numericUpDownMu;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown numericUpDownb;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown numericUpDownRadius;
        private System.Windows.Forms.NumericUpDown numericUpDownWeight;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown numericUpDownH;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label labelTextL;
        private System.Windows.Forms.NumericUpDown numericUpDownL;
    }
}

