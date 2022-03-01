namespace Lab11
{
    partial class Form
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form));
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.TeachersList = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.LoadTeachersButton = new System.Windows.Forms.ToolStripButton();
            this.CreateTeacherButton = new System.Windows.Forms.ToolStripButton();
            this.DeleteTeacherButton = new System.Windows.Forms.ToolStripButton();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.toolStrip2 = new System.Windows.Forms.ToolStrip();
            this.DegreesLoadButton = new System.Windows.Forms.ToolStripButton();
            this.DegreesNewButton = new System.Windows.Forms.ToolStripButton();
            this.DegreesDeleteButton = new System.Windows.Forms.ToolStripButton();
            this.DegreesList = new System.Windows.Forms.ListView();
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.toolStrip2.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Margin = new System.Windows.Forms.Padding(4);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(800, 450);
            this.tabControl1.TabIndex = 1;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.TeachersList);
            this.tabPage1.Controls.Add(this.toolStrip1);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Margin = new System.Windows.Forms.Padding(4);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(4);
            this.tabPage1.Size = new System.Drawing.Size(792, 421);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Преподаватели";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // TeachersList
            // 
            this.TeachersList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5});
            this.TeachersList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.TeachersList.FullRowSelect = true;
            this.TeachersList.GridLines = true;
            this.TeachersList.HideSelection = false;
            this.TeachersList.Location = new System.Drawing.Point(4, 31);
            this.TeachersList.Margin = new System.Windows.Forms.Padding(4);
            this.TeachersList.Name = "TeachersList";
            this.TeachersList.Size = new System.Drawing.Size(784, 386);
            this.TeachersList.TabIndex = 0;
            this.TeachersList.UseCompatibleStateImageBehavior = false;
            this.TeachersList.View = System.Windows.Forms.View.Details;
            this.TeachersList.DoubleClick += new System.EventHandler(this.listViewTeachers_DoubleClick);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Id";
            this.columnHeader1.Width = 65;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "FirstName";
            this.columnHeader2.Width = 143;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "MiddleName";
            this.columnHeader3.Width = 158;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "LastName";
            this.columnHeader4.Width = 157;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Degree";
            this.columnHeader5.Width = 148;
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.LoadTeachersButton,
            this.CreateTeacherButton,
            this.DeleteTeacherButton});
            this.toolStrip1.Location = new System.Drawing.Point(4, 4);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(784, 27);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // LoadTeachersButton
            // 
            this.LoadTeachersButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.LoadTeachersButton.Image = ((System.Drawing.Image)(resources.GetObject("LoadTeachersButton.Image")));
            this.LoadTeachersButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.LoadTeachersButton.Name = "LoadTeachersButton";
            this.LoadTeachersButton.Size = new System.Drawing.Size(81, 24);
            this.LoadTeachersButton.Text = "Загрузить";
            this.LoadTeachersButton.Click += new System.EventHandler(this.LoadTeachersButton_Click);
            // 
            // CreateTeacherButton
            // 
            this.CreateTeacherButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.CreateTeacherButton.Image = ((System.Drawing.Image)(resources.GetObject("CreateTeacherButton.Image")));
            this.CreateTeacherButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.CreateTeacherButton.Name = "CreateTeacherButton";
            this.CreateTeacherButton.Size = new System.Drawing.Size(80, 24);
            this.CreateTeacherButton.Text = "Добавить";
            this.CreateTeacherButton.Click += new System.EventHandler(this.CreateTeacherButton_Click);
            // 
            // DeleteTeacherButton
            // 
            this.DeleteTeacherButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.DeleteTeacherButton.Image = ((System.Drawing.Image)(resources.GetObject("DeleteTeacherButton.Image")));
            this.DeleteTeacherButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.DeleteTeacherButton.Name = "DeleteTeacherButton";
            this.DeleteTeacherButton.Size = new System.Drawing.Size(69, 24);
            this.DeleteTeacherButton.Text = "Удалить";
            this.DeleteTeacherButton.Click += new System.EventHandler(this.DeleteTeacherButton_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.DegreesList);
            this.tabPage2.Controls.Add(this.toolStrip2);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Margin = new System.Windows.Forms.Padding(4);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(4);
            this.tabPage2.Size = new System.Drawing.Size(792, 421);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Ученые степени";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // toolStrip2
            // 
            this.toolStrip2.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.DegreesLoadButton,
            this.DegreesNewButton,
            this.DegreesDeleteButton});
            this.toolStrip2.Location = new System.Drawing.Point(4, 4);
            this.toolStrip2.Name = "toolStrip2";
            this.toolStrip2.Size = new System.Drawing.Size(784, 27);
            this.toolStrip2.TabIndex = 2;
            this.toolStrip2.Text = "toolStrip2";
            // 
            // DegreesLoadButton
            // 
            this.DegreesLoadButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.DegreesLoadButton.Image = ((System.Drawing.Image)(resources.GetObject("DegreesLoadButton.Image")));
            this.DegreesLoadButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.DegreesLoadButton.Name = "DegreesLoadButton";
            this.DegreesLoadButton.Size = new System.Drawing.Size(81, 24);
            this.DegreesLoadButton.Text = "Загрузить";
            this.DegreesLoadButton.Click += new System.EventHandler(this.DegreesLoadButton_Click);
            // 
            // DegreesNewButton
            // 
            this.DegreesNewButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.DegreesNewButton.Image = ((System.Drawing.Image)(resources.GetObject("DegreesNewButton.Image")));
            this.DegreesNewButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.DegreesNewButton.Name = "DegreesNewButton";
            this.DegreesNewButton.Size = new System.Drawing.Size(80, 24);
            this.DegreesNewButton.Text = "Добавить";
            this.DegreesNewButton.Click += new System.EventHandler(this.DegreesNewButton_Click);
            // 
            // DegreesDeleteButton
            // 
            this.DegreesDeleteButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.DegreesDeleteButton.Image = ((System.Drawing.Image)(resources.GetObject("DegreesDeleteButton.Image")));
            this.DegreesDeleteButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.DegreesDeleteButton.Name = "DegreesDeleteButton";
            this.DegreesDeleteButton.Size = new System.Drawing.Size(69, 24);
            this.DegreesDeleteButton.Text = "Удалить";
            this.DegreesDeleteButton.Click += new System.EventHandler(this.DegreesDeleteButton_Click);
            // 
            // DegreesList
            // 
            this.DegreesList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader6,
            this.columnHeader7});
            this.DegreesList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.DegreesList.FullRowSelect = true;
            this.DegreesList.GridLines = true;
            this.DegreesList.HideSelection = false;
            this.DegreesList.Location = new System.Drawing.Point(4, 31);
            this.DegreesList.Margin = new System.Windows.Forms.Padding(4);
            this.DegreesList.Name = "DegreesList";
            this.DegreesList.Size = new System.Drawing.Size(784, 386);
            this.DegreesList.TabIndex = 3;
            this.DegreesList.UseCompatibleStateImageBehavior = false;
            this.DegreesList.View = System.Windows.Forms.View.Details;
            this.DegreesList.DoubleClick += new System.EventHandler(this.DegreesList_DoubleClick);
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Id";
            this.columnHeader6.Width = 65;
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "Title";
            this.columnHeader7.Width = 368;
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form";
            this.Text = "Lab 11";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.toolStrip2.ResumeLayout(false);
            this.toolStrip2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.ListView TeachersList;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton LoadTeachersButton;
        private System.Windows.Forms.ToolStripButton CreateTeacherButton;
        private System.Windows.Forms.ToolStripButton DeleteTeacherButton;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ListView DegreesList;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.ToolStrip toolStrip2;
        private System.Windows.Forms.ToolStripButton DegreesLoadButton;
        private System.Windows.Forms.ToolStripButton DegreesNewButton;
        private System.Windows.Forms.ToolStripButton DegreesDeleteButton;
    }
}

