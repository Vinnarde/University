using System;
using System.Windows.Forms;

using ClassLibraryWork;

namespace _4_2
{
    public partial class FormEmployee : Form
    {

        private Employee _employee;

        public Employee Employee
        {
            get { return _employee; }
            set
            {
                _employee = value;
                textBoxFirstName.Text = Employee.FirstName;
                textBoxLastName.Text = Employee.LastName;
                textBoxPatronymic.Text = Employee.Patronymic;
                numericUpDownSalary.Value = (decimal)Employee.Salary;
            }
        }


        public FormEmployee()
        {
            InitializeComponent();
        }

        private void Employee_FormClosed(object sender, FormClosedEventArgs e)
        {
          
        }

        private void buttonSaveEmployee_Click(object sender, EventArgs e)
        {
            _employee.FirstName = textBoxFirstName.Text;
            _employee.LastName = textBoxLastName.Text;
            _employee.Patronymic = textBoxPatronymic.Text;
            _employee.Salary = (double)numericUpDownSalary.Value;
            this.DialogResult = DialogResult.OK;
        }
    }
}
