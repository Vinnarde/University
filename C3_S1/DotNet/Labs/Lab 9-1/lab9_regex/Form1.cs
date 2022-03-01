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
        string[] input = inputTextbox.Text.Split(new[] { Environment.NewLine }, StringSplitOptions.None);
        string pattern = @"(?<!static.*)(\b\w+\b)\s*\(.*\)";
        string result = "";
        
        Regex regex = new Regex(pattern);

        foreach (string line in input)
        {
            Match match = regex.Match(line);
            if (match.Success)
                result += match.Groups[1].Value + "\r\n";
        }

        resultTextbox.Text = result;
    }

    private void inputTextbox_KeyUp(object sender, KeyEventArgs e)
    {
        FindMethods();
    }
}
