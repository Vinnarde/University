using System;
using System.Windows.Forms;
using ClassLibraryWork;

namespace _4_2
{
    public partial class FormJob : Form
    {
        private Job _job;
        public Job Job
        {
            get { return _job; }
            set
            {
                _job = value;
                comboBoxEmployee.SelectedItem = _job.Worker;
                comboBoxTypeOfWork.SelectedItem = _job.Position;
            }
        }

        private readonly Human _human = Human.Instance;
        
        public FormJob()
        {
            InitializeComponent();
            _human.EmployeeAdded     += _human_EmployeeAdded;
            _human.EmployeeRemoved   += _human_EmployeeRemoved;
            _human.TypeOfWorkAdded   += _human_TypeOfWorkAdded;
            _human.TypeOfWorkRemoved += _human_TypeOfWorkRemoved; 
            
            foreach (var employee in _human.Employees)
            {
                comboBoxEmployee.Items.Add(employee);
            }

            foreach (var typeOfWork in _human.TypeOfWorks)
            {
                comboBoxTypeOfWork.Items.Add(typeOfWork);
            }
        }

        private void _human_TypeOfWorkRemoved(object sender, EventArgs e)
        {
            int key = (int)sender;
            for (int i = 0; i < comboBoxTypeOfWork.Items.Count; i++)
            {
                var typeOfWork = comboBoxTypeOfWork.Items[i] as TypeOfWork;
                if (typeOfWork?.TypeOfWorkId == key)
                {
                    comboBoxTypeOfWork.Items.RemoveAt(i); 
                    break;
                }
            }
        }

        private void _human_TypeOfWorkAdded(object sender, EventArgs e)
        {
            comboBoxTypeOfWork.Items.Add(sender);
        }

        private void _human_EmployeeRemoved(object sender, EventArgs e)
        {
            int key = (int)sender;
            for (int i = 0; i <
            comboBoxEmployee.Items.Count; i++)
            {
                var employee = comboBoxEmployee.Items[i] as Employee;
         
                if (employee?.EmployeeId == key)
                {
                    comboBoxEmployee.Items.RemoveAt(i); 
                    break;
                }
            }
        }

        private void _human_EmployeeAdded(object sender, EventArgs e)
        {
            comboBoxEmployee.Items.Add(sender);
        }

        private void buttonSaveJob_Click(object sender, EventArgs e)
        {
            _job.Worker   = comboBoxEmployee.SelectedItem as Employee;
            _job.Position = comboBoxTypeOfWork.SelectedItem as TypeOfWork;
            this.DialogResult = DialogResult.OK;
        }
      
    }
}
