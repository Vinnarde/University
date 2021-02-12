using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
          
            Stopwatch sw = new Stopwatch();

            sw.Start();

            textBox_output.Text = FactorizeFast(numericUpDown1.Value);
            //division(numericUpDown1.Value);
            sw.Stop();
            label1.Text =  "Time taken: " + sw.Elapsed.ToString();
            
        }
    }
}
