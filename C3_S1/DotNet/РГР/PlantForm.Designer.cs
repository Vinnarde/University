
namespace RGR_DOT
{
    partial class PlantForm
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
            System.Windows.Forms.Label nameLabel;
            System.Windows.Forms.Label categoryLabel;
            System.Windows.Forms.Label familyLabel;
            System.Windows.Forms.Label latinNameLabel;
            System.Windows.Forms.Label anotherNameLabel;
            System.Windows.Forms.Label uRLLabel;
            this.plantDataSet = new RGR_DOT.PlantDataSet();
            this.plantBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.plantTableAdapter = new RGR_DOT.PlantDataSetTableAdapters.PlantTableAdapter();
            this.tableAdapterManager = new RGR_DOT.PlantDataSetTableAdapters.TableAdapterManager();
            this.nameTextBox = new System.Windows.Forms.TextBox();
            this.categoryTextBox = new System.Windows.Forms.TextBox();
            this.familyTextBox = new System.Windows.Forms.TextBox();
            this.latinNameTextBox = new System.Windows.Forms.TextBox();
            this.anotherNameTextBox = new System.Windows.Forms.TextBox();
            this.uRLTextBox = new System.Windows.Forms.TextBox();
            this.buttonSave = new System.Windows.Forms.Button();
            nameLabel = new System.Windows.Forms.Label();
            categoryLabel = new System.Windows.Forms.Label();
            familyLabel = new System.Windows.Forms.Label();
            latinNameLabel = new System.Windows.Forms.Label();
            anotherNameLabel = new System.Windows.Forms.Label();
            uRLLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.plantDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.plantBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // plantDataSet
            // 
            this.plantDataSet.DataSetName = "PlantDataSet";
            this.plantDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // plantBindingSource
            // 
            this.plantBindingSource.DataMember = "Plant";
            this.plantBindingSource.DataSource = this.plantDataSet;
            // 
            // plantTableAdapter
            // 
            this.plantTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.PlantTableAdapter = this.plantTableAdapter;
            this.tableAdapterManager.UpdateOrder = RGR_DOT.PlantDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // nameLabel
            // 
            nameLabel.AutoSize = true;
            nameLabel.Location = new System.Drawing.Point(25, 29);
            nameLabel.Name = "nameLabel";
            nameLabel.Size = new System.Drawing.Size(49, 17);
            nameLabel.TabIndex = 3;
            nameLabel.Text = "Name:";
            // 
            // nameTextBox
            // 
            this.nameTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.plantBindingSource, "Name", true));
            this.nameTextBox.Location = new System.Drawing.Point(134, 26);
            this.nameTextBox.Name = "nameTextBox";
            this.nameTextBox.Size = new System.Drawing.Size(244, 22);
            this.nameTextBox.TabIndex = 1;
            // 
            // categoryLabel
            // 
            categoryLabel.AutoSize = true;
            categoryLabel.Location = new System.Drawing.Point(25, 57);
            categoryLabel.Name = "categoryLabel";
            categoryLabel.Size = new System.Drawing.Size(69, 17);
            categoryLabel.TabIndex = 5;
            categoryLabel.Text = "Category:";
            // 
            // categoryTextBox
            // 
            this.categoryTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.plantBindingSource, "Category", true));
            this.categoryTextBox.Location = new System.Drawing.Point(134, 54);
            this.categoryTextBox.Name = "categoryTextBox";
            this.categoryTextBox.Size = new System.Drawing.Size(244, 22);
            this.categoryTextBox.TabIndex = 2;
            // 
            // familyLabel
            // 
            familyLabel.AutoSize = true;
            familyLabel.Location = new System.Drawing.Point(25, 85);
            familyLabel.Name = "familyLabel";
            familyLabel.Size = new System.Drawing.Size(52, 17);
            familyLabel.TabIndex = 7;
            familyLabel.Text = "Family:";
            // 
            // familyTextBox
            // 
            this.familyTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.plantBindingSource, "Family", true));
            this.familyTextBox.Location = new System.Drawing.Point(134, 82);
            this.familyTextBox.Name = "familyTextBox";
            this.familyTextBox.Size = new System.Drawing.Size(244, 22);
            this.familyTextBox.TabIndex = 3;
            // 
            // latinNameLabel
            // 
            latinNameLabel.AutoSize = true;
            latinNameLabel.Location = new System.Drawing.Point(25, 113);
            latinNameLabel.Name = "latinNameLabel";
            latinNameLabel.Size = new System.Drawing.Size(84, 17);
            latinNameLabel.TabIndex = 9;
            latinNameLabel.Text = "Latin Name:";
            // 
            // latinNameTextBox
            // 
            this.latinNameTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.plantBindingSource, "LatinName", true));
            this.latinNameTextBox.Location = new System.Drawing.Point(134, 110);
            this.latinNameTextBox.Name = "latinNameTextBox";
            this.latinNameTextBox.Size = new System.Drawing.Size(244, 22);
            this.latinNameTextBox.TabIndex = 4;
            // 
            // anotherNameLabel
            // 
            anotherNameLabel.AutoSize = true;
            anotherNameLabel.Location = new System.Drawing.Point(25, 141);
            anotherNameLabel.Name = "anotherNameLabel";
            anotherNameLabel.Size = new System.Drawing.Size(103, 17);
            anotherNameLabel.TabIndex = 11;
            anotherNameLabel.Text = "Another Name:";
            // 
            // anotherNameTextBox
            // 
            this.anotherNameTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.plantBindingSource, "AnotherName", true));
            this.anotherNameTextBox.Location = new System.Drawing.Point(134, 138);
            this.anotherNameTextBox.Name = "anotherNameTextBox";
            this.anotherNameTextBox.Size = new System.Drawing.Size(244, 22);
            this.anotherNameTextBox.TabIndex = 12;
            this.anotherNameTextBox.Tag = "5";
            // 
            // uRLLabel
            // 
            uRLLabel.AutoSize = true;
            uRLLabel.Location = new System.Drawing.Point(25, 169);
            uRLLabel.Name = "uRLLabel";
            uRLLabel.Size = new System.Drawing.Size(40, 17);
            uRLLabel.TabIndex = 13;
            uRLLabel.Text = "URL:";
            // 
            // uRLTextBox
            // 
            this.uRLTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.plantBindingSource, "URL", true));
            this.uRLTextBox.Location = new System.Drawing.Point(134, 166);
            this.uRLTextBox.Name = "uRLTextBox";
            this.uRLTextBox.Size = new System.Drawing.Size(244, 22);
            this.uRLTextBox.TabIndex = 14;
            this.uRLTextBox.Tag = "6";
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(157, 204);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(99, 28);
            this.buttonSave.TabIndex = 15;
            this.buttonSave.Tag = "7";
            this.buttonSave.Text = "Сохранить";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // PlantForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(409, 244);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(nameLabel);
            this.Controls.Add(this.nameTextBox);
            this.Controls.Add(categoryLabel);
            this.Controls.Add(this.categoryTextBox);
            this.Controls.Add(familyLabel);
            this.Controls.Add(this.familyTextBox);
            this.Controls.Add(latinNameLabel);
            this.Controls.Add(this.latinNameTextBox);
            this.Controls.Add(anotherNameLabel);
            this.Controls.Add(this.anotherNameTextBox);
            this.Controls.Add(uRLLabel);
            this.Controls.Add(this.uRLTextBox);
            this.Name = "PlantForm";
            this.Text = "PlantForm";
            this.Load += new System.EventHandler(this.PlantForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.plantDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.plantBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private PlantDataSet plantDataSet;
        private System.Windows.Forms.BindingSource plantBindingSource;
        private PlantDataSetTableAdapters.PlantTableAdapter plantTableAdapter;
        private PlantDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.TextBox nameTextBox;
        private System.Windows.Forms.TextBox categoryTextBox;
        private System.Windows.Forms.TextBox familyTextBox;
        private System.Windows.Forms.TextBox latinNameTextBox;
        private System.Windows.Forms.TextBox anotherNameTextBox;
        private System.Windows.Forms.TextBox uRLTextBox;
        private System.Windows.Forms.Button buttonSave;
    }
}