namespace Lab12
{
    partial class MainForm
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
            this.TabControl = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.TeachersDataGrid = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn7 = new System.Windows.Forms.DataGridViewComboBoxColumn();
            this.degreesBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.Lab11DataSet = new Lab12.Lab11DataSet();
            this.photo = new System.Windows.Forms.DataGridViewImageColumn();
            this.TeachersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.DegreesDataGrid = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.DegreesTableAdapter = new Lab12.lab11dbDataSetTableAdapters.degreesTableAdapter();
            this.tableAdapterManager = new Lab12.lab11dbDataSetTableAdapters.TableAdapterManager();
            this.TeachersTableAdapter = new Lab12.lab11dbDataSetTableAdapters.teachersTableAdapter();
            this.MenuStrip = new System.Windows.Forms.MenuStrip();
            this.AddTeacherMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.DeleteTeacherMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.SaveMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.PrintToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.PrintPreviewMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.PrintMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fKTeacherDegreeBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.TabControl.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TeachersDataGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.degreesBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Lab11DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.TeachersBindingSource)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.DegreesDataGrid)).BeginInit();
            this.MenuStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fKTeacherDegreeBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // TabControl
            // 
            this.TabControl.Controls.Add(this.tabPage1);
            this.TabControl.Controls.Add(this.tabPage2);
            this.TabControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.TabControl.Location = new System.Drawing.Point(0, 30);
            this.TabControl.Name = "TabControl";
            this.TabControl.SelectedIndex = 0;
            this.TabControl.Size = new System.Drawing.Size(860, 465);
            this.TabControl.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.AutoScroll = true;
            this.tabPage1.Controls.Add(this.TeachersDataGrid);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(852, 436);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Teachers";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // TeachersDataGrid
            // 
            this.TeachersDataGrid.AutoGenerateColumns = false;
            this.TeachersDataGrid.BackgroundColor = System.Drawing.SystemColors.Window;
            this.TeachersDataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.TeachersDataGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn4,
            this.dataGridViewTextBoxColumn6,
            this.dataGridViewTextBoxColumn5,
            this.dataGridViewTextBoxColumn7,
            this.photo});
            this.TeachersDataGrid.DataSource = this.TeachersBindingSource;
            this.TeachersDataGrid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.TeachersDataGrid.Location = new System.Drawing.Point(3, 3);
            this.TeachersDataGrid.Name = "TeachersDataGrid";
            this.TeachersDataGrid.RowHeadersWidth = 51;
            this.TeachersDataGrid.RowTemplate.Height = 24;
            this.TeachersDataGrid.Size = new System.Drawing.Size(846, 430);
            this.TeachersDataGrid.TabIndex = 0;
            this.TeachersDataGrid.DoubleClick += new System.EventHandler(this.TeachersDataGrid_DoubleClick);
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.DataPropertyName = "first_name";
            this.dataGridViewTextBoxColumn4.HeaderText = "First name";
            this.dataGridViewTextBoxColumn4.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            this.dataGridViewTextBoxColumn4.Width = 125;
            // 
            // dataGridViewTextBoxColumn6
            // 
            this.dataGridViewTextBoxColumn6.DataPropertyName = "middle_name";
            this.dataGridViewTextBoxColumn6.HeaderText = "Middle name";
            this.dataGridViewTextBoxColumn6.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
            this.dataGridViewTextBoxColumn6.Width = 125;
            // 
            // dataGridViewTextBoxColumn5
            // 
            this.dataGridViewTextBoxColumn5.DataPropertyName = "last_name";
            this.dataGridViewTextBoxColumn5.HeaderText = "Last name";
            this.dataGridViewTextBoxColumn5.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            this.dataGridViewTextBoxColumn5.Width = 125;
            // 
            // dataGridViewTextBoxColumn7
            // 
            this.dataGridViewTextBoxColumn7.DataPropertyName = "degree";
            this.dataGridViewTextBoxColumn7.DataSource = this.degreesBindingSource;
            this.dataGridViewTextBoxColumn7.DisplayMember = "title";
            this.dataGridViewTextBoxColumn7.HeaderText = "Degree";
            this.dataGridViewTextBoxColumn7.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
            this.dataGridViewTextBoxColumn7.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewTextBoxColumn7.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            this.dataGridViewTextBoxColumn7.ValueMember = "id";
            this.dataGridViewTextBoxColumn7.Width = 125;
            // 
            // degreesBindingSource
            // 
            this.degreesBindingSource.DataMember = "degrees";
            this.degreesBindingSource.DataSource = this.Lab11DataSet;
            // 
            // Lab11dbDataSet
            // 
            this.Lab11DataSet.DataSetName = "lab11dbDataSet";
            this.Lab11DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // photo
            // 
            this.photo.DataPropertyName = "photo";
            this.photo.HeaderText = "Photo";
            this.photo.ImageLayout = System.Windows.Forms.DataGridViewImageCellLayout.Zoom;
            this.photo.MinimumWidth = 6;
            this.photo.Name = "photo";
            this.photo.Width = 125;
            // 
            // teachersBindingSource
            // 
            this.TeachersBindingSource.DataMember = "teachers";
            this.TeachersBindingSource.DataSource = this.Lab11DataSet;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.DegreesDataGrid);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(852, 438);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Degrees";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // DegreesDataGrid
            // 
            this.DegreesDataGrid.AutoGenerateColumns = false;
            this.DegreesDataGrid.BackgroundColor = System.Drawing.SystemColors.Window;
            this.DegreesDataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DegreesDataGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn1,
            this.dataGridViewTextBoxColumn2});
            this.DegreesDataGrid.DataSource = this.degreesBindingSource;
            this.DegreesDataGrid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.DegreesDataGrid.Location = new System.Drawing.Point(3, 3);
            this.DegreesDataGrid.Name = "DegreesDataGrid";
            this.DegreesDataGrid.RowHeadersWidth = 51;
            this.DegreesDataGrid.RowTemplate.Height = 24;
            this.DegreesDataGrid.Size = new System.Drawing.Size(846, 432);
            this.DegreesDataGrid.TabIndex = 0;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this.dataGridViewTextBoxColumn1.DataPropertyName = "id";
            this.dataGridViewTextBoxColumn1.HeaderText = "id";
            this.dataGridViewTextBoxColumn1.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
            this.dataGridViewTextBoxColumn1.ReadOnly = true;
            this.dataGridViewTextBoxColumn1.Width = 125;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.DataPropertyName = "title";
            this.dataGridViewTextBoxColumn2.HeaderText = "title";
            this.dataGridViewTextBoxColumn2.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            this.dataGridViewTextBoxColumn2.Width = 125;
            // 
            // DegreesTableAdapter
            // 
            this.DegreesTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.degreesTableAdapter = this.DegreesTableAdapter;
            this.tableAdapterManager.teachersTableAdapter = this.TeachersTableAdapter;
            this.tableAdapterManager.UpdateOrder = Lab12.lab11dbDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // TeachersTableAdapter
            // 
            this.TeachersTableAdapter.ClearBeforeFill = true;
            // 
            // MenuStrip
            // 
            this.MenuStrip.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.MenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.AddTeacherMenuItem,
            this.DeleteTeacherMenuItem,
            this.SaveMenuItem,
            this.PrintToolStripMenuItem});
            this.MenuStrip.Location = new System.Drawing.Point(0, 0);
            this.MenuStrip.Name = "MenuStrip";
            this.MenuStrip.Size = new System.Drawing.Size(860, 30);
            this.MenuStrip.TabIndex = 1;
            this.MenuStrip.Text = "menuStrip1";
            // 
            // AddTeacherMenuItem
            // 
            this.AddTeacherMenuItem.Name = "AddTeacherMenuItem";
            this.AddTeacherMenuItem.Size = new System.Drawing.Size(104, 26);
            this.AddTeacherMenuItem.Text = "Add teacher";
            this.AddTeacherMenuItem.Click += new System.EventHandler(this.AddTeacher_Click);
            // 
            // DeleteTeacherMenuItem
            // 
            this.DeleteTeacherMenuItem.Name = "DeleteTeacherMenuItem";
            this.DeleteTeacherMenuItem.Size = new System.Drawing.Size(120, 26);
            this.DeleteTeacherMenuItem.Text = "Delete teacher";
            this.DeleteTeacherMenuItem.Click += new System.EventHandler(this.DeleteTeacher_Click);
            // 
            // SaveMenuItem
            // 
            this.SaveMenuItem.Name = "SaveMenuItem";
            this.SaveMenuItem.Size = new System.Drawing.Size(112, 26);
            this.SaveMenuItem.Text = "Save changes";
            this.SaveMenuItem.Click += new System.EventHandler(this.SaveChangesMenuItem_Click);
            // 
            // PrintToolStripMenuItem
            // 
            this.PrintToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.PrintPreviewMenuItem,
            this.PrintMenuItem});
            this.PrintToolStripMenuItem.Name = "PrintToolStripMenuItem";
            this.PrintToolStripMenuItem.Size = new System.Drawing.Size(53, 26);
            this.PrintToolStripMenuItem.Text = "Print";
            // 
            // PrintPreviewMenuItem
            // 
            this.PrintPreviewMenuItem.Name = "PrintPreviewMenuItem";
            this.PrintPreviewMenuItem.Size = new System.Drawing.Size(143, 26);
            this.PrintPreviewMenuItem.Text = "Preview";
            this.PrintPreviewMenuItem.Click += new System.EventHandler(this.PrintPreviewMenuItem_Click);
            // 
            // PrintMenuItem
            // 
            this.PrintMenuItem.Name = "PrintMenuItem";
            this.PrintMenuItem.Size = new System.Drawing.Size(143, 26);
            this.PrintMenuItem.Text = "Print";
            this.PrintMenuItem.Click += new System.EventHandler(this.PrintMenuItem_Click);
            // 
            // fKTeacherDegreeBindingSource
            // 
            this.fKTeacherDegreeBindingSource.DataMember = "FK_TeacherDegree";
            this.fKTeacherDegreeBindingSource.DataSource = this.degreesBindingSource;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(860, 495);
            this.Controls.Add(this.TabControl);
            this.Controls.Add(this.MenuStrip);
            this.MainMenuStrip = this.MenuStrip;
            this.Name = "MainForm";
            this.Text = "Lab12";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.TabControl.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.TeachersDataGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.degreesBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Lab11DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.TeachersBindingSource)).EndInit();
            this.tabPage2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.DegreesDataGrid)).EndInit();
            this.MenuStrip.ResumeLayout(false);
            this.MenuStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fKTeacherDegreeBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TabControl TabControl;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private Lab11DataSet Lab11DataSet;
        private System.Windows.Forms.BindingSource degreesBindingSource;
        private lab11dbDataSetTableAdapters.degreesTableAdapter DegreesTableAdapter;
        private lab11dbDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private lab11dbDataSetTableAdapters.teachersTableAdapter TeachersTableAdapter;
        private System.Windows.Forms.BindingSource TeachersBindingSource;
        private System.Windows.Forms.DataGridView TeachersDataGrid;
        private System.Windows.Forms.DataGridView DegreesDataGrid;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.MenuStrip MenuStrip;
        private System.Windows.Forms.ToolStripMenuItem AddTeacherMenuItem;
        private System.Windows.Forms.ToolStripMenuItem DeleteTeacherMenuItem;
        private System.Windows.Forms.ToolStripMenuItem PrintToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem SaveMenuItem;
        private System.Windows.Forms.BindingSource fKTeacherDegreeBindingSource;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn7;
        private System.Windows.Forms.DataGridViewImageColumn photo;
        private System.Windows.Forms.ToolStripMenuItem PrintPreviewMenuItem;
        private System.Windows.Forms.ToolStripMenuItem PrintMenuItem;
    }
}

