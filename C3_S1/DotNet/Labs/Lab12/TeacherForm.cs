using System;
using System.Data;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace Lab12
{
    public partial class TeacherForm : Form
    {
        public TeacherForm(int pos)
        {
            InitializeComponent();

            DegreesTableAdapter.Fill(Lab11DataSet.degrees);
            TeachersTableAdapter.Fill(Lab11DataSet.teachers);

            if (pos == -1)
            {
                TeachersBindingSource.AddNew();
                TeachersBindingSource.MoveLast();
            }
            else
                TeachersBindingSource.Position = pos;
            
            DegreesCombo.DataSource = DegreesBindingSource;
            DegreesCombo.DisplayMember = "Title";
            DegreesCombo.ValueMember = "Id";
            DegreesCombo.DataBindings.Add(new Binding("SelectedValue", TeachersBindingSource, "degree", true));
        }


        private void SaveButton_Click(object sender, EventArgs e)
        {
            Validate();
            TeachersBindingSource.EndEdit();
            TableAdapterManager.UpdateAll(Lab11DataSet);
        }

        private void ChangePhoto_Click(object sender, EventArgs e)
        {
            if (FileDialog.ShowDialog() == DialogResult.OK)
            {
                ChangePhoto(FileDialog.FileName);
            }
        }

        private void ChangePhoto(string fileName)
        {
            Image img = Image.FromFile(fileName);
            PhotoPictureBox.Image = img;

            DataRowView drw = (DataRowView) TeachersBindingSource.Current;
            Lab11DataSet.teachersRow row = (Lab11DataSet.teachersRow)drw.Row;
            MemoryStream memStream = new MemoryStream();
            img.Save(memStream, img.RawFormat);

            row.photo = memStream.ToArray();
            memStream.Close();
            TeachersTableAdapter.Update(row);
        }

        private void PhotoPictureBox_DoubleClick(object sender, EventArgs e)
        {
            Form propForm = new Form();

            PropertyGrid propGrid = new PropertyGrid();
            propGrid.CommandsVisibleIfAvailable = true;
            propGrid.Size = new Size(600, 500);
            propGrid.TabIndex = 1;
            propGrid.Text = "Property Grid";
            propGrid.SelectedObject = PhotoPictureBox;
            propForm.Controls.Add(propGrid);

            propForm.Show();
        }
    }
}
