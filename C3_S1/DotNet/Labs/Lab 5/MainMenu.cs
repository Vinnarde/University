using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibraryWork;
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
            var employee = new Employee();
            FormEmployee formClient = new FormEmployee(employee);
            if (formClient.ShowDialog() == DialogResult.OK)
            {
                Human.Employees.Add(employee.EmployeeId, formClient.employee);
                UpdateEmployeeList();
            }
        }

        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var employee = listViewEmployee.SelectedItems[0].Tag as Employee;
            FormEmployee formClient = new FormEmployee(employee);
            if (formClient.ShowDialog() == DialogResult.OK)
            {
                UpdateEmployeeList();
            }
        }

        private void addToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            var typeOfWork = new TypeOfWork();
            FormTypeOfWork formClient = new FormTypeOfWork(typeOfWork);
            if (formClient.ShowDialog() == DialogResult.OK)
            {
                Human.TypeOfWorks.Add(typeOfWork.TypeOfWorkId, formClient.typeOfWork);
                UpdateTypeOfWorkList();
            }
        }

        private void editToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            var typeOfWork = listViewTypeOfWork.SelectedItems[0].Tag as TypeOfWork;
            FormTypeOfWork formClient = new FormTypeOfWork(typeOfWork);
            if (formClient.ShowDialog() == DialogResult.OK)
            {
                UpdateTypeOfWorkList();
            }
        }


        private void addToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            var job = new Job();
            FormJob formClient = new FormJob(job);
            if (formClient.ShowDialog() == DialogResult.OK)
            {
                Human.Jobs.Add(formClient.job);
                UpdateJobList();
            }
        }

        private void editToolStripMenuItem2_Click(object sender, EventArgs e)
        {
            var job = listViewJob.SelectedItems[0].Tag as Job;
            
            FormJob formClient = new FormJob(job);
            if (formClient.ShowDialog() == DialogResult.OK)
            {
                UpdateJobList();
            }
        }

        private void UpdateEmployeeList()
        {
            listViewEmployee.Items.Clear();
            foreach (var employee in Human.Employees.Values)
            {
                var listViewItem = new ListViewItem
                {
                    Tag = employee,
                    Text = employee.EmployeeId.ToString()
                };

                listViewItem.SubItems.Add(employee.ToString());
                listViewItem.SubItems.Add(employee.Salary.ToString());
                listViewEmployee.Items.Add(listViewItem);

            }
        }

        private void UpdateTypeOfWorkList()
        {
            listViewTypeOfWork.Items.Clear();
            foreach (var typeOfWork in Human.TypeOfWorks.Values)
            {
                var listViewItem = new ListViewItem
                {
                    Tag = typeOfWork,
                    Text = typeOfWork.TypeOfWorkId.ToString()
                };

                listViewItem.SubItems.Add(typeOfWork.ToString());
                listViewItem.SubItems.Add(typeOfWork.Description.ToString());
                listViewTypeOfWork.Items.Add(listViewItem);

            }
        }

        private void UpdateJobList()
        {
            listViewJob.Items.Clear();
            foreach (var job in Human.Jobs)
            {
                var listViewItem = new ListViewItem
                {
                    Tag = job,
                    Text = job.Worker.ToString()
                };

                listViewItem.SubItems.Add(job.Position.Description.ToString());
                listViewJob.Items.Add(listViewItem);
            }
        }
    }
}
