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
    public partial class FormTypeOfWork : Form
    {

        public TypeOfWork typeOfWork { get; set; }

        public FormTypeOfWork(TypeOfWork typeOfWork)
        {
            InitializeComponent();
            this.typeOfWork = typeOfWork;
            numericUpDownPayBayDay.Value = typeOfWork.PaymentPerDay;
            textBoxDescription.Text = typeOfWork.Description;
            
        }

        private void buttonSaveTypeOfWork_Click(object sender, EventArgs e)
        {
            this.typeOfWork.PaymentPerDay = (int)numericUpDownPayBayDay.Value;
            this.typeOfWork.Description = textBoxDescription.Text;

            this.DialogResult = DialogResult.OK;
        }
    }
}
