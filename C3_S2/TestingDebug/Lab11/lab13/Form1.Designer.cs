
namespace lab13
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
            this.components = new System.ComponentModel.Container();
            this.groupBoxAdd = new System.Windows.Forms.GroupBox();
            this.buttonAdd = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.comboBoxTarrifAdd = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.numericUpDownTarrifRateAdd = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownSumAdd = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.dateTimePickerAdd = new System.Windows.Forms.DateTimePicker();
            this.groupBoxFind = new System.Windows.Forms.GroupBox();
            this.notifyIcon1 = new System.Windows.Forms.NotifyIcon(this.components);
            this.buttonFind = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.comboBoxTarrifFind = new System.Windows.Forms.ComboBox();
            this.dataGridViewFind = new System.Windows.Forms.DataGridView();
            this.groupBoxAdd.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownTarrifRateAdd)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownSumAdd)).BeginInit();
            this.groupBoxFind.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFind)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBoxAdd
            // 
            this.groupBoxAdd.Controls.Add(this.buttonAdd);
            this.groupBoxAdd.Controls.Add(this.label4);
            this.groupBoxAdd.Controls.Add(this.comboBoxTarrifAdd);
            this.groupBoxAdd.Controls.Add(this.label3);
            this.groupBoxAdd.Controls.Add(this.label2);
            this.groupBoxAdd.Controls.Add(this.numericUpDownTarrifRateAdd);
            this.groupBoxAdd.Controls.Add(this.numericUpDownSumAdd);
            this.groupBoxAdd.Controls.Add(this.label1);
            this.groupBoxAdd.Controls.Add(this.dateTimePickerAdd);
            this.groupBoxAdd.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.groupBoxAdd.Location = new System.Drawing.Point(12, 12);
            this.groupBoxAdd.Name = "groupBoxAdd";
            this.groupBoxAdd.Size = new System.Drawing.Size(380, 639);
            this.groupBoxAdd.TabIndex = 0;
            this.groupBoxAdd.TabStop = false;
            this.groupBoxAdd.Text = "Добавить контракт";
            // 
            // buttonAdd
            // 
            this.buttonAdd.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonAdd.Location = new System.Drawing.Point(23, 578);
            this.buttonAdd.Name = "buttonAdd";
            this.buttonAdd.Size = new System.Drawing.Size(322, 55);
            this.buttonAdd.TabIndex = 8;
            this.buttonAdd.Text = "Добавить!";
            this.buttonAdd.UseVisualStyleBackColor = true;
            this.buttonAdd.Click += new System.EventHandler(this.button1_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(19, 148);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(78, 24);
            this.label4.TabIndex = 7;
            this.label4.Text = "Тариф: ";
            // 
            // comboBoxTarrifAdd
            // 
            this.comboBoxTarrifAdd.FormattingEnabled = true;
            this.comboBoxTarrifAdd.Location = new System.Drawing.Point(125, 144);
            this.comboBoxTarrifAdd.Name = "comboBoxTarrifAdd";
            this.comboBoxTarrifAdd.Size = new System.Drawing.Size(201, 32);
            this.comboBoxTarrifAdd.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(19, 113);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(100, 24);
            this.label3.TabIndex = 5;
            this.label3.Text = "TarrifRate: ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(19, 75);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 24);
            this.label2.TabIndex = 4;
            this.label2.Text = "Сумма: ";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // numericUpDownTarrifRateAdd
            // 
            this.numericUpDownTarrifRateAdd.DecimalPlaces = 3;
            this.numericUpDownTarrifRateAdd.Increment = new decimal(new int[] {
            1,
            0,
            0,
            196608});
            this.numericUpDownTarrifRateAdd.Location = new System.Drawing.Point(126, 109);
            this.numericUpDownTarrifRateAdd.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownTarrifRateAdd.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            196608});
            this.numericUpDownTarrifRateAdd.Name = "numericUpDownTarrifRateAdd";
            this.numericUpDownTarrifRateAdd.Size = new System.Drawing.Size(200, 29);
            this.numericUpDownTarrifRateAdd.TabIndex = 3;
            this.numericUpDownTarrifRateAdd.Value = new decimal(new int[] {
            1,
            0,
            0,
            196608});
            // 
            // numericUpDownSumAdd
            // 
            this.numericUpDownSumAdd.Increment = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.numericUpDownSumAdd.Location = new System.Drawing.Point(126, 71);
            this.numericUpDownSumAdd.Maximum = new decimal(new int[] {
            -727379968,
            232,
            0,
            0});
            this.numericUpDownSumAdd.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.numericUpDownSumAdd.Name = "numericUpDownSumAdd";
            this.numericUpDownSumAdd.Size = new System.Drawing.Size(200, 29);
            this.numericUpDownSumAdd.TabIndex = 2;
            this.numericUpDownSumAdd.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 40);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 24);
            this.label1.TabIndex = 1;
            this.label1.Text = "Дата: ";
            // 
            // dateTimePickerAdd
            // 
            this.dateTimePickerAdd.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.dateTimePickerAdd.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dateTimePickerAdd.Location = new System.Drawing.Point(126, 36);
            this.dateTimePickerAdd.MaxDate = new System.DateTime(2021, 6, 5, 0, 0, 0, 0);
            this.dateTimePickerAdd.MinDate = new System.DateTime(2021, 1, 1, 0, 0, 0, 0);
            this.dateTimePickerAdd.Name = "dateTimePickerAdd";
            this.dateTimePickerAdd.Size = new System.Drawing.Size(200, 29);
            this.dateTimePickerAdd.TabIndex = 0;
            this.dateTimePickerAdd.Value = new System.DateTime(2021, 6, 5, 0, 0, 0, 0);
            // 
            // groupBoxFind
            // 
            this.groupBoxFind.Controls.Add(this.dataGridViewFind);
            this.groupBoxFind.Controls.Add(this.buttonFind);
            this.groupBoxFind.Controls.Add(this.label5);
            this.groupBoxFind.Controls.Add(this.comboBoxTarrifFind);
            this.groupBoxFind.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.groupBoxFind.Location = new System.Drawing.Point(408, 12);
            this.groupBoxFind.Name = "groupBoxFind";
            this.groupBoxFind.Size = new System.Drawing.Size(562, 639);
            this.groupBoxFind.TabIndex = 1;
            this.groupBoxFind.TabStop = false;
            this.groupBoxFind.Text = "Найти контракт";
            // 
            // notifyIcon1
            // 
            this.notifyIcon1.Text = "notifyIcon1";
            this.notifyIcon1.Visible = true;
            // 
            // buttonFind
            // 
            this.buttonFind.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonFind.Location = new System.Drawing.Point(132, 578);
            this.buttonFind.Name = "buttonFind";
            this.buttonFind.Size = new System.Drawing.Size(322, 55);
            this.buttonFind.TabIndex = 11;
            this.buttonFind.Text = "Найти";
            this.buttonFind.UseVisualStyleBackColor = true;
            this.buttonFind.Click += new System.EventHandler(this.buttonFind_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(26, 42);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(78, 24);
            this.label5.TabIndex = 10;
            this.label5.Text = "Тариф: ";
            // 
            // comboBoxTarrifFind
            // 
            this.comboBoxTarrifFind.FormattingEnabled = true;
            this.comboBoxTarrifFind.Location = new System.Drawing.Point(132, 38);
            this.comboBoxTarrifFind.Name = "comboBoxTarrifFind";
            this.comboBoxTarrifFind.Size = new System.Drawing.Size(201, 32);
            this.comboBoxTarrifFind.TabIndex = 9;
            // 
            // dataGridViewFind
            // 
            this.dataGridViewFind.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewFind.Location = new System.Drawing.Point(6, 76);
            this.dataGridViewFind.Name = "dataGridViewFind";
            this.dataGridViewFind.Size = new System.Drawing.Size(551, 496);
            this.dataGridViewFind.TabIndex = 12;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(982, 663);
            this.Controls.Add(this.groupBoxFind);
            this.Controls.Add(this.groupBoxAdd);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBoxAdd.ResumeLayout(false);
            this.groupBoxAdd.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownTarrifRateAdd)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownSumAdd)).EndInit();
            this.groupBoxFind.ResumeLayout(false);
            this.groupBoxFind.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFind)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxAdd;
        private System.Windows.Forms.GroupBox groupBoxFind;
        private System.Windows.Forms.DateTimePicker dateTimePickerAdd;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown numericUpDownSumAdd;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown numericUpDownTarrifRateAdd;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox comboBoxTarrifAdd;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NotifyIcon notifyIcon1;
        private System.Windows.Forms.Button buttonAdd;
        private System.Windows.Forms.Button buttonFind;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox comboBoxTarrifFind;
        private System.Windows.Forms.DataGridView dataGridViewFind;
    }
}

