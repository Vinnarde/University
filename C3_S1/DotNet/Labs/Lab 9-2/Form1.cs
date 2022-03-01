using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Text.RegularExpressions;
using System.Windows.Forms;


public partial class Form1 : Form
{
    public Form1()
    {
        InitializeComponent();
        FindMethods();
    }

    public void FindMethods()
    {
        string str = inputTextbox.Text;
        string pattern = @"(?s)\benum\b.+\{(.+)\}";
        string enumeration = Regex.Match(str, pattern).Groups[1].Value;
        pattern = @"(?m)^\s*(\w+)";
        List<string> values = new List<string>();
        foreach (Match match in Regex.Matches(enumeration, pattern))
        {
            resultTextbox.AppendText(match.Groups[1].Value + Environment.NewLine);
      
        }
    }

    private void inputTextbox_KeyUp(object sender, KeyEventArgs e)
    {
        FindMethods();
    }
}
