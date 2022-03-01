using System;
using System.Data;
using System.Drawing;
using System.Drawing.Printing;
using System.IO;
using System.Windows.Forms;

namespace Lab12
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private Font PrintFont;

        // The PrintPage event is raised for each page to be printed.
        /*private void pd_PrintPage(object sender, PrintPageEventArgs ev)
        {
            float linesPerPage;
            float yPos;
            float leftMargin = ev.MarginBounds.Left;
            float topMargin = ev.MarginBounds.Top;
            string line;
            int lineCount = 0;
            DataRowView dataRowView;
            lab11dbDataSet.teachersRow row;

            // Calculate the number of lines per page.
            linesPerPage = ev.MarginBounds.Height /
               printFont.GetHeight(ev.Graphics);

            while (PrintIndex < teachersBindingSource.Count && lineCount < linesPerPage)
            {
                teachersBindingSource.Position = PrintIndex;
                dataRowView = (DataRowView)teachersBindingSource.Current;
                row = (lab11dbDataSet.teachersRow)dataRowView.Row;
                line = $"{row.id} - {row.first_name} {row.middle_name} {row.last_name} {row.degree}";
                yPos = topMargin + (lineCount * printFont.GetHeight(ev.Graphics));
                ev.Graphics.DrawString(line, printFont, Brushes.Black, leftMargin, yPos, new StringFormat());

                lineCount++;
                PrintIndex++;
            }

            // If more lines exist, print another page.
            ev.HasMorePages = (PrintIndex < teachersBindingSource.Count);
        }*/

        // The PrintPage event is raised for each page to be printed.
        private void pd_PrintSingle(object sender, PrintPageEventArgs ev)
        {
            float leftMargin = ev.MarginBounds.Left;
            float yPos = ev.MarginBounds.Top;
            string line;
            DataRowView dataRowView = (DataRowView)TeachersBindingSource.Current;
            Lab11DataSet.teachersRow row = (Lab11DataSet.teachersRow)dataRowView.Row;

            PrintFont = new Font("Arial", 20, FontStyle.Bold);
            line = "Teacher record report:";
            ev.Graphics.DrawString(line, PrintFont, Brushes.Black, leftMargin, yPos, new StringFormat());
            yPos += PrintFont.GetHeight(ev.Graphics);


            PrintFont = new Font("Arial", 14);
            line = $"ID = {row.id}\r\n" +
                   $"FIRST NAME = {row.first_name}\r\n" +
                   $"MIDDLE_NAME = {row.middle_name}\r\n" +
                   $"LAST_NAME = {row.last_name}\r\n" +
                   $"DEGREE = {row.degreesRow.title}";

            ev.Graphics.DrawString(line, PrintFont, Brushes.Black, leftMargin, yPos, new StringFormat());
            yPos += PrintFont.GetHeight(ev.Graphics) * 10;


            try
            {
                using (var ms = new MemoryStream(row.photo))
                {
                    ev.Graphics.DrawImage(Image.FromStream(ms), new Point((int)leftMargin, (int)yPos));
                }
            }
            catch (Exception)
            { }

            ev.HasMorePages = false;
        }

        // Print the file.
        public void Printing()
        {
            try
            {
                PrintDocument pd = new PrintDocument();
                pd.PrintPage += new PrintPageEventHandler(pd_PrintSingle);
                // Print the document.
                pd.Print();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        public void PrintingPreview()
        {
            try
            {
                PrintPreviewDialog preview = new PrintPreviewDialog();
                PrintDocument pd = new PrintDocument();
                pd.PrintPage += new PrintPageEventHandler(pd_PrintSingle);
                preview.Document = pd;
                preview.ShowDialog();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            TeachersTableAdapter.Fill(Lab11DataSet.teachers);
            DegreesTableAdapter.Fill(Lab11DataSet.degrees);
        }

        private void TeachersDataGrid_DoubleClick(object sender, EventArgs e)
        {
            var form = new TeacherForm(TeachersBindingSource.Position);
            form.ShowDialog();
            TeachersTableAdapter.Fill(Lab11DataSet.teachers);
        }

        private void AddTeacher_Click(object sender, EventArgs e)
        {
            var form = new TeacherForm(-1);
            form.ShowDialog();
            TeachersTableAdapter.Fill(Lab11DataSet.teachers);
        }

        private void DeleteTeacher_Click(object sender, EventArgs e)
        {
            TeachersBindingSource.RemoveCurrent();
        }

        private void SaveChangesMenuItem_Click(object sender, EventArgs e)
        {
            DegreesTableAdapter.Update(Lab11DataSet.degrees);
            TeachersTableAdapter.Update(Lab11DataSet.teachers);
        }

        private void PrintMenuItem_Click(object sender, EventArgs e)
        {
            Printing();
        }

        private void PrintPreviewMenuItem_Click(object sender, EventArgs e)
        {
            PrintingPreview();
        }
    }
}
