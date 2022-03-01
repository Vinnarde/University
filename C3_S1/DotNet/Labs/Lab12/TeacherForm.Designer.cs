namespace Lab12
{
    partial class TeacherForm
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
            System.Windows.Forms.Label first_nameLabel;
            System.Windows.Forms.Label last_nameLabel;
            System.Windows.Forms.Label middle_nameLabel;
            System.Windows.Forms.Label degreeLabel;
            System.Windows.Forms.Label photoLabel;
            this.Lab11DataSet = new Lab12.Lab11DataSet();
            this.TeachersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.TeachersTableAdapter = new Lab12.lab11dbDataSetTableAdapters.teachersTableAdapter();
            this.TableAdapterManager = new Lab12.lab11dbDataSetTableAdapters.TableAdapterManager();
            this.DegreesTableAdapter = new Lab12.lab11dbDataSetTableAdapters.degreesTableAdapter();
            this.first_nameTextBox = new System.Windows.Forms.TextBox();
            this.last_nameTextBox = new System.Windows.Forms.TextBox();
            this.middle_nameTextBox = new System.Windows.Forms.TextBox();
            this.DegreesBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.fKTeacherDegreeBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.SaveButton = new System.Windows.Forms.Button();
            this.DegreesCombo = new System.Windows.Forms.ComboBox();
            this.PhotoPictureBox = new System.Windows.Forms.PictureBox();
            this.ChangePhotoButton = new System.Windows.Forms.Button();
            this.FileDialog = new System.Windows.Forms.OpenFileDialog();
            first_nameLabel = new System.Windows.Forms.Label();
            last_nameLabel = new System.Windows.Forms.Label();
            middle_nameLabel = new System.Windows.Forms.Label();
            degreeLabel = new System.Windows.Forms.Label();
            photoLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.Lab11DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.TeachersBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.DegreesBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTeacherDegreeBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.PhotoPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // first_nameLabel
            // 
            first_nameLabel.AutoSize = true;
            first_nameLabel.Location = new System.Drawing.Point(12, 8);
            first_nameLabel.Name = "first_nameLabel";
            first_nameLabel.Size = new System.Drawing.Size(78, 17);
            first_nameLabel.TabIndex = 1;
            first_nameLabel.Text = "First name:";
            // 
            // last_nameLabel
            // 
            last_nameLabel.AutoSize = true;
            last_nameLabel.Location = new System.Drawing.Point(12, 110);
            last_nameLabel.Name = "last_nameLabel";
            last_nameLabel.Size = new System.Drawing.Size(78, 17);
            last_nameLabel.TabIndex = 2;
            last_nameLabel.Text = "Last name:";
            // 
            // middle_nameLabel
            // 
            middle_nameLabel.AutoSize = true;
            middle_nameLabel.Location = new System.Drawing.Point(12, 59);
            middle_nameLabel.Name = "middle_nameLabel";
            middle_nameLabel.Size = new System.Drawing.Size(92, 17);
            middle_nameLabel.TabIndex = 4;
            middle_nameLabel.Text = "Middle name:";
            // 
            // degreeLabel
            // 
            degreeLabel.AutoSize = true;
            degreeLabel.Location = new System.Drawing.Point(12, 161);
            degreeLabel.Name = "degreeLabel";
            degreeLabel.Size = new System.Drawing.Size(59, 17);
            degreeLabel.TabIndex = 6;
            degreeLabel.Text = "Degree:";
            // 
            // photoLabel
            // 
            photoLabel.AutoSize = true;
            photoLabel.Location = new System.Drawing.Point(333, 12);
            photoLabel.Name = "photoLabel";
            photoLabel.Size = new System.Drawing.Size(49, 17);
            photoLabel.TabIndex = 9;
            photoLabel.Text = "Photo:";
            // 
            // Lab11DataSet
            // 
            this.Lab11DataSet.DataSetName = "lab11dbDataSet";
            this.Lab11DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // TeachersBindingSource
            // 
            this.TeachersBindingSource.DataMember = "teachers";
            this.TeachersBindingSource.DataSource = this.Lab11DataSet;
            // 
            // TeachersTableAdapter
            // 
            this.TeachersTableAdapter.ClearBeforeFill = true;
            // 
            // TableAdapterManager
            // 
            this.TableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.TableAdapterManager.degreesTableAdapter = this.DegreesTableAdapter;
            this.TableAdapterManager.teachersTableAdapter = this.TeachersTableAdapter;
            this.TableAdapterManager.UpdateOrder = Lab12.lab11dbDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // DegreesTableAdapter
            // 
            this.DegreesTableAdapter.ClearBeforeFill = true;
            // 
            // first_nameTextBox
            // 
            this.first_nameTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.TeachersBindingSource, "first_name", true));
            this.first_nameTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.first_nameTextBox.Location = new System.Drawing.Point(12, 31);
            this.first_nameTextBox.Name = "first_nameTextBox";
            this.first_nameTextBox.Size = new System.Drawing.Size(290, 27);
            this.first_nameTextBox.TabIndex = 2;
            // 
            // last_nameTextBox
            // 
            this.last_nameTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.TeachersBindingSource, "last_name", true));
            this.last_nameTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.last_nameTextBox.Location = new System.Drawing.Point(12, 133);
            this.last_nameTextBox.Name = "last_nameTextBox";
            this.last_nameTextBox.Size = new System.Drawing.Size(290, 27);
            this.last_nameTextBox.TabIndex = 3;
            // 
            // middle_nameTextBox
            // 
            this.middle_nameTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.TeachersBindingSource, "middle_name", true));
            this.middle_nameTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.middle_nameTextBox.Location = new System.Drawing.Point(12, 82);
            this.middle_nameTextBox.Name = "middle_nameTextBox";
            this.middle_nameTextBox.Size = new System.Drawing.Size(290, 27);
            this.middle_nameTextBox.TabIndex = 5;
            // 
            // DegreesBindingSource
            // 
            this.DegreesBindingSource.DataMember = "degrees";
            this.DegreesBindingSource.DataSource = this.Lab11DataSet;
            // 
            // fKTeacherDegreeBindingSource
            // 
            this.fKTeacherDegreeBindingSource.DataMember = "FK_TeacherDegree";
            this.fKTeacherDegreeBindingSource.DataSource = this.DegreesBindingSource;
            // 
            // SaveButton
            // 
            this.SaveButton.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.SaveButton.Location = new System.Drawing.Point(598, 230);
            this.SaveButton.Name = "SaveButton";
            this.SaveButton.Size = new System.Drawing.Size(113, 37);
            this.SaveButton.TabIndex = 8;
            this.SaveButton.Text = "Save";
            this.SaveButton.UseVisualStyleBackColor = true;
            this.SaveButton.Click += new System.EventHandler(this.SaveButton_Click);
            // 
            // DegreesCombo
            // 
            this.DegreesCombo.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.DegreesCombo.FormattingEnabled = true;
            this.DegreesCombo.Location = new System.Drawing.Point(15, 189);
            this.DegreesCombo.Name = "DegreesCombo";
            this.DegreesCombo.Size = new System.Drawing.Size(287, 26);
            this.DegreesCombo.TabIndex = 9;
            // 
            // PhotoPictureBox
            // 
            this.PhotoPictureBox.DataBindings.Add(new System.Windows.Forms.Binding("Image", this.TeachersBindingSource, "photo", true));
            this.PhotoPictureBox.Location = new System.Drawing.Point(336, 42);
            this.PhotoPictureBox.Name = "PhotoPictureBox";
            this.PhotoPictureBox.Size = new System.Drawing.Size(375, 173);
            this.PhotoPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.PhotoPictureBox.TabIndex = 10;
            this.PhotoPictureBox.TabStop = false;
            this.PhotoPictureBox.DoubleClick += new System.EventHandler(this.PhotoPictureBox_DoubleClick);
            // 
            // ChangePhotoButton
            // 
            this.ChangePhotoButton.Location = new System.Drawing.Point(388, 9);
            this.ChangePhotoButton.Name = "ChangePhotoButton";
            this.ChangePhotoButton.Size = new System.Drawing.Size(35, 23);
            this.ChangePhotoButton.TabIndex = 11;
            this.ChangePhotoButton.Text = "+";
            this.ChangePhotoButton.UseVisualStyleBackColor = true;
            this.ChangePhotoButton.Click += new System.EventHandler(this.ChangePhoto_Click);
            // 
            // FileDialog
            // 
            this.FileDialog.Filter = "Image Files(*.jpg; *.jpeg; *png; *.gif; *.bmp)|*.jpg; *.jpeg; *.gif; *.bmp; *.png" +
    ";";
            // 
            // TeacherForm
            // 
            this.AcceptButton = this.SaveButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(720, 274);
            this.Controls.Add(this.ChangePhotoButton);
            this.Controls.Add(photoLabel);
            this.Controls.Add(this.PhotoPictureBox);
            this.Controls.Add(this.DegreesCombo);
            this.Controls.Add(this.SaveButton);
            this.Controls.Add(degreeLabel);
            this.Controls.Add(middle_nameLabel);
            this.Controls.Add(this.middle_nameTextBox);
            this.Controls.Add(last_nameLabel);
            this.Controls.Add(this.last_nameTextBox);
            this.Controls.Add(first_nameLabel);
            this.Controls.Add(this.first_nameTextBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "TeacherForm";
            this.Text = "Teacher";
            ((System.ComponentModel.ISupportInitialize)(this.Lab11DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.TeachersBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.DegreesBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTeacherDegreeBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.PhotoPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Lab11DataSet Lab11DataSet;
        private System.Windows.Forms.BindingSource TeachersBindingSource;
        private lab11dbDataSetTableAdapters.teachersTableAdapter TeachersTableAdapter;
        private lab11dbDataSetTableAdapters.TableAdapterManager TableAdapterManager;
        private System.Windows.Forms.TextBox first_nameTextBox;
        private System.Windows.Forms.TextBox last_nameTextBox;
        private System.Windows.Forms.TextBox middle_nameTextBox;
        private lab11dbDataSetTableAdapters.degreesTableAdapter DegreesTableAdapter;
        private System.Windows.Forms.BindingSource DegreesBindingSource;
        private System.Windows.Forms.Button SaveButton;
        private System.Windows.Forms.BindingSource fKTeacherDegreeBindingSource;
        private System.Windows.Forms.ComboBox DegreesCombo;
        private System.Windows.Forms.PictureBox PhotoPictureBox;
        private System.Windows.Forms.Button ChangePhotoButton;
        private System.Windows.Forms.OpenFileDialog FileDialog;
    }
}