using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Program
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            textBox1.Clear();

            for (int i = 1; i < numericUpDown1.Value - 1; i++)
            {
                textBox1.Text += i + ", ";
            }
            textBox1.Text += numericUpDown1.Value > 1 ? Convert.ToString(numericUpDown1.Value - 1) : "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox2.Text != "")
            {
                comboBox1.Items.Add(textBox2.Text);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            comboBox1.Items.Clear();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox3.Text = Convert.ToString(comboBox1.SelectedItem);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            tab3_textbox3.Text = Convert.ToString(Convert.ToDouble(tab3_textbox1.Text) + Convert.ToDouble(tab3_textbox2.Text));
        }

        private void tab3_SubtractButton_Click(object sender, EventArgs e)
        {
            tab3_textbox3.Text = Convert.ToString(Convert.ToDouble(tab3_textbox1.Text) - Convert.ToDouble(tab3_textbox2.Text));
        }

        private void tab3_MultiplyButton_Click(object sender, EventArgs e)
        {
            tab3_textbox3.Text = Convert.ToString(Convert.ToDouble(tab3_textbox1.Text) * Convert.ToDouble(tab3_textbox2.Text));
        }

        private void tab3_DivideButton_Click(object sender, EventArgs e)
        {
            tab3_textbox3.Text = Convert.ToString(Convert.ToDouble(tab3_textbox1.Text) / Convert.ToDouble(tab3_textbox2.Text));
        }

        private void tab4_button_Click(object sender, EventArgs e)
        {
            double d;

            tab4_comboBox.Items.Clear();

            foreach (string str in tab4_textBox.Lines)
            {
                if (double.TryParse(str,out d))
                {
                    tab4_comboBox.Items.Add(d);
                }
            }
        }

        private void tab5_button_Click(object sender, EventArgs e)
        {
            tab5_textBox.Clear();

            decimal epsilon = tab5_numericUpDown.Value;
            decimal sum = 0M;
            decimal previous = -1;
            
            for (int i = 1; sum - previous > epsilon; i++)
            {
                previous = sum;
                sum += 1M / i;

               // tab5_textBox.Text += "x = " + i + ": " + sum + Environment.NewLine;

            }
            tab5_textBox.Text += "Result: " + sum + Environment.NewLine;
        }

        private void tab6_button_Click(object sender, EventArgs e)
        {
            tab6_textBox2.Clear();
            for (int i = 0; i < tab6_textBox.Lines.Length; i++)
            {
                double d;
                if (!double.TryParse(tab6_textBox.Lines[tab6_textBox.Lines.Length - 1 - i], out d))
                {
                    tab6_textBox2.Text += tab6_textBox.Lines[tab6_textBox.Lines.Length - 1 - i] + Environment.NewLine;
                }
            }
        }
    }
}
