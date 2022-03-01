using System;
using System.Windows.Forms;
using ClassLibraryWork;

namespace _4_2
{
    public partial class FormTypeOfWork : Form
    {

        private TypeOfWork _typeOfWork;

        public TypeOfWork TypeOfWork
        {
            get { return _typeOfWork; }
            set
            {
                _typeOfWork = value;
                numericUpDownPayBayDay.Value = _typeOfWork.PaymentPerDay;
                textBoxDescription.Text = _typeOfWork.Description;
            }
        }


        public FormTypeOfWork()
        {
            InitializeComponent();
        }

        private void Employee_FormClosed(object sender, FormClosedEventArgs e)
        {

        }

        private void buttonSaveTypeOfWork_Click(object sender, EventArgs e)
        {
            _typeOfWork.PaymentPerDay = (int)numericUpDownPayBayDay.Value;
            _typeOfWork.Description = textBoxDescription.Text;
            this.DialogResult = DialogResult.OK;
        }

    }
}
