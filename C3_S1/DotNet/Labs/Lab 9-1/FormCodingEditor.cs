using System;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace Lab9
{
    public partial class FormCodingEditor : Form
    {

        private string text, original;
        private string path;
        private Encoding currEncoding, originalEn;

        public FormCodingEditor()
        {
            InitializeComponent();

            encodingCombo.Items.Clear();
            encodingCombo.DisplayMember = "EncodingName";
            foreach (EncodingInfo ei in Encoding.GetEncodings())
            {
                Encoding e = ei.GetEncoding();
                encodingCombo.Items.Add(e);
            }
        }

        private void save()
        {
            File.WriteAllText(path, text, currEncoding);
        }

        private void open()
        {
            if (openFile.ShowDialog() == DialogResult.OK)
            {
                path = openFile.FileName;
                text = original = File.ReadAllText(path);
                textBox.Text = text;
                currEncoding = originalEn = GetEncoding(path);
                encodingCombo.SelectedItem = currEncoding;
            }
        }

        private void changeEncoding()
        {
            var en = (Encoding) encodingCombo.SelectedItem;

            byte[] originalBytes = originalEn.GetBytes(original);
            byte[] convertedBytes = Encoding.Convert(originalEn, en, originalBytes);

            char[] convertedChars = new char[en.GetCharCount(convertedBytes, 0, convertedBytes.Length)];
            en.GetChars(convertedBytes, 0, convertedBytes.Length, convertedChars, 0);

            text = new string(convertedChars);
            textBox.Text = text;
            originalEn = en;
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            open();
        }

        private void SaveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            save();
        }

        public static Encoding GetEncoding(string filename)
        {
            var bom = new byte[4];
            using (var file = new FileStream(filename, FileMode.Open, FileAccess.Read))
            {
                file.Read(bom, 0, 4);
            }

            if (bom[0] == 0x2b && bom[1] == 0x2f && bom[2] == 0x76) return Encoding.UTF7;
            if (bom[0] == 0xef && bom[1] == 0xbb && bom[2] == 0xbf) return Encoding.UTF8;
            if (bom[0] == 0xff && bom[1] == 0xfe && bom[2] == 0 && bom[3] == 0) return Encoding.UTF32;
            if (bom[0] == 0xff && bom[1] == 0xfe) return Encoding.Unicode;
            if (bom[0] == 0xfe && bom[1] == 0xff) return Encoding.BigEndianUnicode; 
            if (bom[0] == 0 && bom[1] == 0 && bom[2] == 0xfe && bom[3] == 0xff) return new UTF32Encoding(true, true);

            return Encoding.ASCII;
        }

        private void encodingCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            changeEncoding();
        }
    }
}
