using Lab11.Models;

namespace Lab11
{
    public partial class CreateOrEditDegree : System.Windows.Forms.Form
    {
        public Degree Model;

        public CreateOrEditDegree(Degree model)
        {
            Model = model;
            if (Model == null)
                Model = new Degree();
         
            InitializeComponent();
            Fill();
        }

        private void Fill()
        {
            TitleField.Text = Model.Title;
        }

        private void SaveButton_Click(object sender, System.EventArgs e)
        {
            Model.Title = TitleField.Text;
        }
    }
}
