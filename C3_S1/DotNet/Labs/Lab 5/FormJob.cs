using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ClassLibraryWork;

namespace _4_2
{
    public partial class FormJob : Form
    {
        public Job job { get; set; }

        public FormJob(Job job)
        {
            InitializeComponent();
            this.job = job;

            foreach(var employee in Human.Employees.Values)
            {
                comboBoxEmployee.Items.Add(employee);
            }

            foreach (var typeOfWork in Human.TypeOfWorks.Values)
            {
                comboBoxTypeOfWork.Items.Add(typeOfWork);
            }

            comboBoxEmployee.SelectedItem = job.Worker;
            comboBoxTypeOfWork.SelectedItem = job.Position;

        }

        private void buttonSaveJob_Click(object sender, EventArgs e)
        {
            job.Worker = comboBoxEmployee.SelectedItem as Employee;
            job.Position = comboBoxTypeOfWork.SelectedItem as TypeOfWork;
            this.DialogResult = DialogResult.OK;
        }

    }
}
