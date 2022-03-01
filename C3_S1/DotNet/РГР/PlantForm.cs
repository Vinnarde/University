using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RGR_DOT
{
    public partial class PlantForm : Form
    {
        public PlantForm(int pos = -1)
        {
            InitializeComponent();
            this.plantTableAdapter.Fill(this.plantDataSet.Plant);

            if (pos == -1)
            {
                plantBindingSource.AddNew();
                plantBindingSource.MoveLast();
            }
            else plantBindingSource.Position = pos;
        }

        private void plantBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.plantBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.plantDataSet);

        }

        private void PlantForm_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'plantDataSet.Plant' table. You can move, or remove it, as needed.

        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrWhiteSpace(nameTextBox.Text) || string.IsNullOrWhiteSpace(categoryTextBox.Text) || string.IsNullOrWhiteSpace(familyTextBox.Text) || string.IsNullOrWhiteSpace(uRLTextBox.Text))
                {
                    MessageBox.Show("Данные заполнены некорректно!", "Ошибка");
                }
                else
                {
                    this.Validate();
                    this.plantBindingSource.EndEdit();
                    this.tableAdapterManager.UpdateAll(this.plantDataSet);
                    Close();
                }
            }
            catch (System.Exception exception)
            {

                MessageBox.Show(exception.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }   
        }
    }
}
