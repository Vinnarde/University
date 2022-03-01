using System;
using System.Windows.Forms;
using System.Data.SqlClient;
using Lab11.Models;

namespace Lab11
{
    public partial class Form : System.Windows.Forms.Form
    {
        private readonly SqlConnection _connection;


        public Form()
        {
            InitializeComponent();
            _connection = new SqlConnection(
                "Data Source=localhost;Initial Catalog=Lab11DB;" +
                "Integrated Security=True;Persist Security Info=False;" +
                "Pooling=False;MultipleActiveResultSets=False;" +
                "Encrypt=False;TrustServerCertificate=True"
            );
        }

        private void LoadTeachersButton_Click(object sender, EventArgs e)
        {
            LoadTeachers();
        }

        private void LoadTeachers()
        {
            var teachers = Teacher.List(_connection);
            TeachersList.Items.Clear();
            for (int i = 0; i < teachers.Count; i++)
            {
                ListAddTeacher(teachers[i]);
            }
        }

        private void ListAddTeacher(Teacher teacher)
        {
            var listListViewItem = TeachersList.Items.Add(teacher.Id.ToString());
            listListViewItem.Tag = teacher;
            listListViewItem.SubItems.Add(teacher.FirstName);
            listListViewItem.SubItems.Add(teacher.MiddleName);
            listListViewItem.SubItems.Add(teacher.LastName);
            listListViewItem.SubItems.Add(teacher.DegreeTitle);
        }

        private void CreateTeacherButton_Click(object sender, EventArgs e)
        {
            var degrees = Degree.List(_connection);
            CreateOrEditTeacher form = new CreateOrEditTeacher(null, degrees);

            if (form.ShowDialog() == DialogResult.OK)
            {
                Teacher.Insert(_connection, form.Model);
                LoadTeachers();
            }
        }

        private void listViewTeachers_DoubleClick(object sender, EventArgs e)
        {
            var list = TeachersList;
            if (list.SelectedItems.Count > 0)
            {
                Teacher teacher = (Teacher) list.SelectedItems[0].Tag;
                var degrees = Degree.List(_connection);
                CreateOrEditTeacher form = new CreateOrEditTeacher(teacher, degrees);

                if (form.ShowDialog() == DialogResult.OK)
                {
                    Teacher.Update(_connection, form.Model);
                    LoadTeachers();
                }
            }
        }

        private void DeleteTeacherButton_Click(object sender, EventArgs e)
        {
            var list = TeachersList;
            if (list.SelectedItems.Count > 0)
            {
                Teacher teacher = (Teacher)list.SelectedItems[0].Tag;
                var confirm = MessageBox.Show(
                    "Are you sure to delete this record?",
                    "Confirm deletion",
                    MessageBoxButtons.YesNo
                );

                if (confirm == DialogResult.Yes)
                {
                    Teacher.Delete(_connection, teacher.Id);
                    LoadTeachers();
                }
            }
        }

        private void DegreesLoadButton_Click(object sender, EventArgs e)
        {
            LoadDegrees();
        }

        private void LoadDegrees()
        {
            DegreesList.Items.Clear();
            var degrees = Degree.List(_connection);
            foreach (Degree deg in degrees)
            {
                var li = DegreesList.Items.Add(deg.Id.ToString());
                li.Tag = deg;
                li.SubItems.Add(deg.Title);
            }
        }

        private void DegreesNewButton_Click(object sender, EventArgs e)
        {
            CreateOrEditDegree form = new CreateOrEditDegree(null);

            if (form.ShowDialog() == DialogResult.OK)
            {
                Degree.Insert(_connection, form.Model);
                LoadDegrees();
            }
        }

        private void DegreesList_DoubleClick(object sender, EventArgs e)
        {
            var list = DegreesList;
            if (list.SelectedItems.Count > 0)
            {
                Degree degree = (Degree)list.SelectedItems[0].Tag;
                CreateOrEditDegree form = new CreateOrEditDegree(degree);

                if (form.ShowDialog() == DialogResult.OK)
                {
                    Degree.Update(_connection, form.Model);
                    LoadDegrees();
                    LoadTeachers();
                }
            }
        }

        private void DegreesDeleteButton_Click(object sender, EventArgs e)
        {
            var list = DegreesList;
            if (list.SelectedItems.Count > 0)
            {
                Degree degree = (Degree)list.SelectedItems[0].Tag;
                var confirm = MessageBox.Show(
                    "Are you sure to delete this record?",
                    "Confirm deletion",
                    MessageBoxButtons.YesNo
                );

                if (confirm == DialogResult.Yes)
                {
                    Degree.Delete(_connection, degree.Id);
                    LoadDegrees();
                    LoadTeachers();
                }
            }
        }
    }
}
