using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4_2
{
    public partial class MainMenu : Form
    {
        public MainMenu()
        {
            InitializeComponent();
        }

        private void addToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormEmployee dialog_employee = new FormEmployee();
            dialog_employee.Show();
        }

        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormEmployee dialog_employee = new FormEmployee();
            dialog_employee.Show();
        }

        private void addToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            FormTypeOfWork dialog_typeofwork = new FormTypeOfWork();
            dialog_typeofwork.Show();
        }

        private void editToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            FormTypeOfWork dialog_typeofwork = new FormTypeOfWork();
            dialog_typeofwork.Show();
        }
    }
}
