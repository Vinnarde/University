namespace _4_2
{
    partial class MainMenu
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportXMLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportJSONToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportBinaryToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importXMLToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.importJSONToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.importBinaryToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.employeeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ToolStripMenuItemAdd = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.jobToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.typeOfWorkToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.tabControlWork = new System.Windows.Forms.TabControl();
            this.tabPageEmployee = new System.Windows.Forms.TabPage();
            this.listViewEmployee = new System.Windows.Forms.ListView();
            this.columnId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnFullName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnSalary = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.tabPageJob = new System.Windows.Forms.TabPage();
            this.tabPageTypeOfWork = new System.Windows.Forms.TabPage();
            this.listViewTypeOfWork = new System.Windows.Forms.ListView();
            this.columntypeofworkId = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderPermentPerDay = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnDescription = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.saveFileDialogMain = new System.Windows.Forms.SaveFileDialog();
            this.openFileDialogMain = new System.Windows.Forms.OpenFileDialog();
            this.menuStrip1.SuspendLayout();
            this.tabControlWork.SuspendLayout();
            this.tabPageEmployee.SuspendLayout();
            this.tabPageTypeOfWork.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.employeeToolStripMenuItem,
            this.jobToolStripMenuItem,
            this.typeOfWorkToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(521, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.saveToolStripMenuItem,
            this.importToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exportXMLToolStripMenuItem,
            this.exportJSONToolStripMenuItem,
            this.exportBinaryToolStripMenuItem});
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.saveToolStripMenuItem.Text = "Export";
            // 
            // exportXMLToolStripMenuItem
            // 
            this.exportXMLToolStripMenuItem.Name = "exportXMLToolStripMenuItem";
            this.exportXMLToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.exportXMLToolStripMenuItem.Text = "XML";
            this.exportXMLToolStripMenuItem.Click += new System.EventHandler(this.exportXMLToolStripMenuItem_Click);
            // 
            // exportJSONToolStripMenuItem
            // 
            this.exportJSONToolStripMenuItem.Name = "exportJSONToolStripMenuItem";
            this.exportJSONToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.exportJSONToolStripMenuItem.Text = "JSON";
            this.exportJSONToolStripMenuItem.Click += new System.EventHandler(this.exportJSONToolStripMenuItem_Click);
            // 
            // exportBinaryToolStripMenuItem
            // 
            this.exportBinaryToolStripMenuItem.Name = "exportBinaryToolStripMenuItem";
            this.exportBinaryToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.exportBinaryToolStripMenuItem.Text = "Binary";
            this.exportBinaryToolStripMenuItem.Click += new System.EventHandler(this.exportBinaryToolStripMenuItem_Click);
            // 
            // importToolStripMenuItem
            // 
            this.importToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.importXMLToolStripMenuItem1,
            this.importJSONToolStripMenuItem1,
            this.importBinaryToolStripMenuItem1});
            this.importToolStripMenuItem.Name = "importToolStripMenuItem";
            this.importToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.importToolStripMenuItem.Text = "Import";
            // 
            // importXMLToolStripMenuItem1
            // 
            this.importXMLToolStripMenuItem1.Name = "importXMLToolStripMenuItem1";
            this.importXMLToolStripMenuItem1.Size = new System.Drawing.Size(180, 22);
            this.importXMLToolStripMenuItem1.Text = "XML";
            this.importXMLToolStripMenuItem1.Click += new System.EventHandler(this.importXMLToolStripMenuItem1_Click);
            // 
            // importJSONToolStripMenuItem1
            // 
            this.importJSONToolStripMenuItem1.Name = "importJSONToolStripMenuItem1";
            this.importJSONToolStripMenuItem1.Size = new System.Drawing.Size(180, 22);
            this.importJSONToolStripMenuItem1.Text = "JSON";
            this.importJSONToolStripMenuItem1.Click += new System.EventHandler(this.importJSONToolStripMenuItem1_Click);
            // 
            // importBinaryToolStripMenuItem1
            // 
            this.importBinaryToolStripMenuItem1.Name = "importBinaryToolStripMenuItem1";
            this.importBinaryToolStripMenuItem1.Size = new System.Drawing.Size(180, 22);
            this.importBinaryToolStripMenuItem1.Text = "Binary";
            this.importBinaryToolStripMenuItem1.Click += new System.EventHandler(this.importBinaryToolStripMenuItem1_Click);
            // 
            // employeeToolStripMenuItem
            // 
            this.employeeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ToolStripMenuItemAdd,
            this.editToolStripMenuItem});
            this.employeeToolStripMenuItem.Name = "employeeToolStripMenuItem";
            this.employeeToolStripMenuItem.Size = new System.Drawing.Size(71, 20);
            this.employeeToolStripMenuItem.Text = "Employee";
            // 
            // ToolStripMenuItemAdd
            // 
            this.ToolStripMenuItemAdd.Name = "ToolStripMenuItemAdd";
            this.ToolStripMenuItemAdd.Size = new System.Drawing.Size(96, 22);
            this.ToolStripMenuItemAdd.Text = "Add";
            this.ToolStripMenuItemAdd.Click += new System.EventHandler(this.addToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(96, 22);
            this.editToolStripMenuItem.Text = "Edit";
            this.editToolStripMenuItem.Click += new System.EventHandler(this.editToolStripMenuItem_Click);
            // 
            // jobToolStripMenuItem
            // 
            this.jobToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addToolStripMenuItem,
            this.editToolStripMenuItem2});
            this.jobToolStripMenuItem.Name = "jobToolStripMenuItem";
            this.jobToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.jobToolStripMenuItem.Text = "Job";
            // 
            // addToolStripMenuItem
            // 
            this.addToolStripMenuItem.Name = "addToolStripMenuItem";
            this.addToolStripMenuItem.Size = new System.Drawing.Size(96, 22);
            this.addToolStripMenuItem.Text = "Add";
            this.addToolStripMenuItem.Click += new System.EventHandler(this.addToolStripMenuItem_Click_1);
            // 
            // editToolStripMenuItem2
            // 
            this.editToolStripMenuItem2.Name = "editToolStripMenuItem2";
            this.editToolStripMenuItem2.Size = new System.Drawing.Size(96, 22);
            this.editToolStripMenuItem2.Text = "Edit";
            this.editToolStripMenuItem2.Click += new System.EventHandler(this.editToolStripMenuItem2_Click);
            // 
            // typeOfWorkToolStripMenuItem
            // 
            this.typeOfWorkToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addToolStripMenuItem1,
            this.editToolStripMenuItem1});
            this.typeOfWorkToolStripMenuItem.Name = "typeOfWorkToolStripMenuItem";
            this.typeOfWorkToolStripMenuItem.Size = new System.Drawing.Size(88, 20);
            this.typeOfWorkToolStripMenuItem.Text = "Type of Work";
            // 
            // addToolStripMenuItem1
            // 
            this.addToolStripMenuItem1.Name = "addToolStripMenuItem1";
            this.addToolStripMenuItem1.Size = new System.Drawing.Size(96, 22);
            this.addToolStripMenuItem1.Text = "Add";
            this.addToolStripMenuItem1.Click += new System.EventHandler(this.addToolStripMenuItem1_Click);
            // 
            // editToolStripMenuItem1
            // 
            this.editToolStripMenuItem1.Name = "editToolStripMenuItem1";
            this.editToolStripMenuItem1.Size = new System.Drawing.Size(96, 22);
            this.editToolStripMenuItem1.Text = "Edit";
            this.editToolStripMenuItem1.Click += new System.EventHandler(this.editToolStripMenuItem1_Click);
            // 
            // tabControlWork
            // 
            this.tabControlWork.Controls.Add(this.tabPageEmployee);
            this.tabControlWork.Controls.Add(this.tabPageJob);
            this.tabControlWork.Controls.Add(this.tabPageTypeOfWork);
            this.tabControlWork.Location = new System.Drawing.Point(12, 27);
            this.tabControlWork.Name = "tabControlWork";
            this.tabControlWork.SelectedIndex = 0;
            this.tabControlWork.Size = new System.Drawing.Size(497, 299);
            this.tabControlWork.TabIndex = 1;
            // 
            // tabPageEmployee
            // 
            this.tabPageEmployee.Controls.Add(this.listViewEmployee);
            this.tabPageEmployee.Location = new System.Drawing.Point(4, 22);
            this.tabPageEmployee.Name = "tabPageEmployee";
            this.tabPageEmployee.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageEmployee.Size = new System.Drawing.Size(489, 273);
            this.tabPageEmployee.TabIndex = 0;
            this.tabPageEmployee.Text = "Epmloyee";
            this.tabPageEmployee.UseVisualStyleBackColor = true;
            // 
            // listViewEmployee
            // 
            this.listViewEmployee.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.listViewEmployee.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnId,
            this.columnFullName,
            this.columnSalary});
            this.listViewEmployee.FullRowSelect = true;
            this.listViewEmployee.GridLines = true;
            this.listViewEmployee.HideSelection = false;
            this.listViewEmployee.Location = new System.Drawing.Point(0, 3);
            this.listViewEmployee.MultiSelect = false;
            this.listViewEmployee.Name = "listViewEmployee";
            this.listViewEmployee.Size = new System.Drawing.Size(486, 267);
            this.listViewEmployee.TabIndex = 0;
            this.listViewEmployee.UseCompatibleStateImageBehavior = false;
            this.listViewEmployee.View = System.Windows.Forms.View.Details;
            this.listViewEmployee.KeyUp += new System.Windows.Forms.KeyEventHandler(this.listViewEmployee_KeyUp);
            // 
            // columnId
            // 
            this.columnId.Text = "ID";
            this.columnId.Width = 189;
            // 
            // columnFullName
            // 
            this.columnFullName.Text = "Full Name";
            this.columnFullName.Width = 194;
            // 
            // columnSalary
            // 
            this.columnSalary.Text = "Salary";
            this.columnSalary.Width = 230;
            // 
            // tabPageJob
            // 
            this.tabPageJob.Location = new System.Drawing.Point(4, 22);
            this.tabPageJob.Name = "tabPageJob";
            this.tabPageJob.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageJob.Size = new System.Drawing.Size(489, 273);
            this.tabPageJob.TabIndex = 1;
            this.tabPageJob.Text = "Job";
            this.tabPageJob.UseVisualStyleBackColor = true;
            // 
            // tabPageTypeOfWork
            // 
            this.tabPageTypeOfWork.Controls.Add(this.listViewTypeOfWork);
            this.tabPageTypeOfWork.Location = new System.Drawing.Point(4, 22);
            this.tabPageTypeOfWork.Name = "tabPageTypeOfWork";
            this.tabPageTypeOfWork.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageTypeOfWork.Size = new System.Drawing.Size(489, 273);
            this.tabPageTypeOfWork.TabIndex = 2;
            this.tabPageTypeOfWork.Text = "TypeOfWork";
            this.tabPageTypeOfWork.UseVisualStyleBackColor = true;
            // 
            // listViewTypeOfWork
            // 
            this.listViewTypeOfWork.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columntypeofworkId,
            this.columnHeaderPermentPerDay,
            this.columnDescription});
            this.listViewTypeOfWork.FullRowSelect = true;
            this.listViewTypeOfWork.GridLines = true;
            this.listViewTypeOfWork.HideSelection = false;
            this.listViewTypeOfWork.LabelWrap = false;
            this.listViewTypeOfWork.Location = new System.Drawing.Point(0, 3);
            this.listViewTypeOfWork.MultiSelect = false;
            this.listViewTypeOfWork.Name = "listViewTypeOfWork";
            this.listViewTypeOfWork.Size = new System.Drawing.Size(486, 267);
            this.listViewTypeOfWork.TabIndex = 3;
            this.listViewTypeOfWork.UseCompatibleStateImageBehavior = false;
            this.listViewTypeOfWork.View = System.Windows.Forms.View.Details;
            this.listViewTypeOfWork.KeyUp += new System.Windows.Forms.KeyEventHandler(this.listViewTypeOfWork_KeyUp);
            // 
            // columntypeofworkId
            // 
            this.columntypeofworkId.Text = "ID";
            // 
            // columnHeaderPermentPerDay
            // 
            this.columnHeaderPermentPerDay.Text = "Perment Per Day";
            this.columnHeaderPermentPerDay.Width = 109;
            // 
            // columnDescription
            // 
            this.columnDescription.Text = "Description";
            this.columnDescription.Width = 309;
            // 
            // openFileDialogMain
            // 
            this.openFileDialogMain.FileName = "openFileDialogMain";
            // 
            // MainMenu
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.ClientSize = new System.Drawing.Size(521, 338);
            this.Controls.Add(this.tabControlWork);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainMenu";
            this.ShowIcon = false;
            this.Text = "Main Menu";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.tabControlWork.ResumeLayout(false);
            this.tabPageEmployee.ResumeLayout(false);
            this.tabPageTypeOfWork.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem employeeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem ToolStripMenuItemAdd;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem typeOfWorkToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem addToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem jobToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem addToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem2;
        private System.Windows.Forms.TabControl tabControlWork;
        private System.Windows.Forms.TabPage tabPageEmployee;
        private System.Windows.Forms.TabPage tabPageJob;
        private System.Windows.Forms.TabPage tabPageTypeOfWork;
        private System.Windows.Forms.ListView listViewEmployee;
        private System.Windows.Forms.ColumnHeader columnId;
        private System.Windows.Forms.ColumnHeader columnFullName;
        private System.Windows.Forms.ColumnHeader columnSalary;
        private System.Windows.Forms.ListView listViewTypeOfWork;
        private System.Windows.Forms.ColumnHeader columnHeaderPermentPerDay;
        private System.Windows.Forms.ColumnHeader columnDescription;
        private System.Windows.Forms.ColumnHeader columntypeofworkId;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportXMLToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportJSONToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportBinaryToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem importToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem importXMLToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem importJSONToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem importBinaryToolStripMenuItem1;
        private System.Windows.Forms.SaveFileDialog saveFileDialogMain;
        private System.Windows.Forms.OpenFileDialog openFileDialogMain;
    }
}

