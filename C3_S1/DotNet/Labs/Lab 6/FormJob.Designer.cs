namespace _4_2
{
    partial class FormJob
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
            this.labelEmployee = new System.Windows.Forms.Label();
            this.labelTypeOfWork = new System.Windows.Forms.Label();
            this.buttonSaveJob = new System.Windows.Forms.Button();
            this.comboBoxEmployee = new System.Windows.Forms.ComboBox();
            this.comboBoxTypeOfWork = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // labelEmployee
            // 
            this.labelEmployee.AutoSize = true;
            this.labelEmployee.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelEmployee.Location = new System.Drawing.Point(12, 25);
            this.labelEmployee.Name = "labelEmployee";
            this.labelEmployee.Size = new System.Drawing.Size(91, 20);
            this.labelEmployee.TabIndex = 11;
            this.labelEmployee.Text = "Cотрудник";
            // 
            // labelTypeOfWork
            // 
            this.labelTypeOfWork.AutoSize = true;
            this.labelTypeOfWork.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelTypeOfWork.Location = new System.Drawing.Point(12, 59);
            this.labelTypeOfWork.Name = "labelTypeOfWork";
            this.labelTypeOfWork.Size = new System.Drawing.Size(100, 20);
            this.labelTypeOfWork.TabIndex = 12;
            this.labelTypeOfWork.Text = "Вид работы";
            // 
            // buttonSaveJob
            // 
            this.buttonSaveJob.Location = new System.Drawing.Point(136, 96);
            this.buttonSaveJob.Name = "buttonSaveJob";
            this.buttonSaveJob.Size = new System.Drawing.Size(111, 28);
            this.buttonSaveJob.TabIndex = 13;
            this.buttonSaveJob.Text = "Сохранить";
            this.buttonSaveJob.UseVisualStyleBackColor = true;
            this.buttonSaveJob.Click += new System.EventHandler(this.buttonSaveJob_Click);
            // 
            // comboBoxEmployee
            // 
            this.comboBoxEmployee.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.comboBoxEmployee.FormattingEnabled = true;
            this.comboBoxEmployee.Location = new System.Drawing.Point(148, 22);
            this.comboBoxEmployee.Name = "comboBoxEmployee";
            this.comboBoxEmployee.Size = new System.Drawing.Size(214, 28);
            this.comboBoxEmployee.TabIndex = 14;
            // 
            // comboBoxTypeOfWork
            // 
            this.comboBoxTypeOfWork.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.comboBoxTypeOfWork.FormattingEnabled = true;
            this.comboBoxTypeOfWork.Location = new System.Drawing.Point(148, 56);
            this.comboBoxTypeOfWork.Name = "comboBoxTypeOfWork";
            this.comboBoxTypeOfWork.Size = new System.Drawing.Size(214, 28);
            this.comboBoxTypeOfWork.TabIndex = 15;
            // 
            // FormJob
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(383, 136);
            this.Controls.Add(this.comboBoxTypeOfWork);
            this.Controls.Add(this.comboBoxEmployee);
            this.Controls.Add(this.buttonSaveJob);
            this.Controls.Add(this.labelTypeOfWork);
            this.Controls.Add(this.labelEmployee);
            this.Name = "FormJob";
            this.Text = "FormJob";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelEmployee;
        private System.Windows.Forms.Label labelTypeOfWork;
        private System.Windows.Forms.Button buttonSaveJob;
        private System.Windows.Forms.ComboBox comboBoxEmployee;
        private System.Windows.Forms.ComboBox comboBoxTypeOfWork;
    }
}