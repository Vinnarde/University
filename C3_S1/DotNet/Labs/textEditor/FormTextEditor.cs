using System;
using System.IO;
using System.Text;
using System.Windows.Forms;

public partial class FormTextEditor : Form
{
    private FileSystemWatcher watch = new FileSystemWatcher();
    private string path = "";
    private FileStream instream;
    private StreamReader sr;

    public FormTextEditor()
    {
        InitializeComponent();
    }

    private void openFile()
    {
        watch.Path = Path.GetDirectoryName(path);
        watch.Filter = Path.GetFileName(path);
        watch.Changed += reloadFile;
        watch.EnableRaisingEvents = true;

        instream = File.Open(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
        sr = new StreamReader(instream);
        reloadFile(null, null);        
    }

    private void reloadFile (object sender, FileSystemEventArgs e)
    {
        instream.Position = 0;
        sr.DiscardBufferedData();
        setText(sr.ReadToEnd());
    }

    private void saveFile ()
    {
        if (path.Length > 0)
        {
            File.WriteAllText(path, editor.Text, sr.CurrentEncoding);
        }
    }

    delegate void SetTextCallback(string text);

    private void setText(string text)
    {
        if (editor.InvokeRequired)
        {
            SetTextCallback d = new SetTextCallback(setText);
            Invoke(d, new object[] { text });
        }
        else
        {
            editor.Text = text;
        }
    }

    private void Form1_FormClosed(object sender, FormClosedEventArgs e)
    {
        if (path.Length > 0)
        {
            sr.Close();
            instream.Dispose();
        }
    }

    private void Form1_KeyDown(object sender, KeyEventArgs e)
    {
        if (e.Control && e.KeyCode == Keys.S)
        {
            saveFile();
        }
    }


    private void uploadToolStripMenuItem_Click(object sender, EventArgs e)
    {
        if (fileDialog.ShowDialog() == DialogResult.OK)
        {
            path = fileDialog.FileName;
            openFile();
        }
    }

    private void saveToolStripMenuItem_Click(object sender, EventArgs e)
    {
        saveFile();
    }
}
