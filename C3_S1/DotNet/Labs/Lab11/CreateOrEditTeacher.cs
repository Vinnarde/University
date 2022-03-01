using System.Collections.Generic;
using Lab11.Models;

namespace Lab11
{
    public partial class CreateOrEditTeacher : System.Windows.Forms.Form
    {
        public Teacher Model;
        private List<Degree> Degrees;

        public CreateOrEditTeacher(Teacher model, List<Degree> degrees)
        {
            Degrees = degrees;
            Model = model;
            if (Model == null)
                Model = new Teacher();
         
            InitializeComponent();
            Fill();
        }

        private void Fill()
        {
            DegreeField.Items.Clear();
            foreach (Degree d in Degrees)
            {
                DegreeField.Items.Add(d);
            }
            FirstNameField.Text = Model.FirstName;
            MiddleNameField.Text = Model.MiddleName;
            LastNameField.Text = Model.LastName;
            DegreeField.Text = Model.DegreeTitle;
        }

        private void SaveButton_Click(object sender, System.EventArgs e)
        {
            Model.Degree = ((Degree)DegreeField.SelectedItem).Id;
            Model.DegreeTitle = ((Degree)DegreeField.SelectedItem).Title;
            Model.FirstName = FirstNameField.Text;
            Model.MiddleName = MiddleNameField.Text;
            Model.LastName = LastNameField.Text;
        }
    }
}
