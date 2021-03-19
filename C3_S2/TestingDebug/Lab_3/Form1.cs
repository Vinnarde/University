using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void tabPage1Button1_Click(object sender, EventArgs e)
        {
            var n = tabPage1NumericUpDown.Value;

            if (n % 400 == 0 || n % 4 == 0 && n % 100 != 0)
                tabPage1_output.Text = n.ToString() + " - високосный год.";
            else tabPage1_output.Text = n.ToString() + " - не високосный год.";
        }

        //delegate decimal F1(decimal x)
        //{
        //    return x - 5;
        //}

        //private decimal F2(decimal x)
        //{
        //    return 5 - x;
        //}

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            var a = tabPage2NumericUpDown_a.Value;
            var b = tabPage2NumericUpDown_b.Value;
            var eps = tabPage2NumericUpDown_eps.Value;

            Func<decimal, decimal> F = null;

            if (radioButton1.Checked)
                F = x => -(5 - x);
            else
            {
                F = x => x - 3;
            }
            /*1*/
            if (a >= b)
            {
                /*2*/
                MessageBox.Show("а должно быть < b", "Ошибка в данных.", MessageBoxButtons.YesNo,
                    MessageBoxIcon.Warning);
            }
            /*3*/
            else
            {
                /*4*/
                if (F(a) * F(b) > 0)
                {
                    /*5*/
                    tabPage2LabelOutput.Text = "Нет решений!";
                }
                /*6*/
                else
                {
                    /*8*/
                    while (a <= b)
                    {
                        var mid = (a + b) / 2;
                        /*9*/
                        if (Math.Abs(F(mid)) < eps)
                        {
                            /*10*/
                            tabPage2LabelOutput.Text = mid.ToString();
                            break;
                        }
                        /*11*/
                        else if (F(mid) < 0) a = mid;
                        /*12*/
                        else b = mid;
                    }
                }
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            Point p1 = new Point();
            Point p2 = new Point();

            p1.X = tabPage3NumericUpDownPoint1X.Value;
            p1.Y = tabPage3NumericUpDownPoint1Y.Value;

            p2.X = tabPage3NumericUpDownPoint2X.Value;
            p2.Y = tabPage3NumericUpDownPoint2Y.Value;

            Rectangle r1 = new Rectangle(p1, p2);

            p1.X = tabPage3NumericUpDownPoint3X.Value;
            p1.Y = tabPage3NumericUpDownPoint3Y.Value;

            p2.X = tabPage3NumericUpDownPoint4X.Value;
            p2.Y = tabPage3NumericUpDownPoint4Y.Value;

            Rectangle r2 = new Rectangle(p1, p2);


            decimal leftX = Math.Max(r1.p1.X, r2.p1.X);
            decimal rightX = Math.Min(r1.p2.X, r2.p2.X);
            decimal topY = Math.Min(r1.p1.Y, r2.p1.Y);

            decimal bottomY = Math.Max(r1.p2.Y, r2.p2.Y);

            if (leftX < rightX && bottomY < topY)
                tabPage3LabelResult.Text = "(" + leftX.ToString() + "; " + topY.ToString() + ") - (" +
                                           rightX.ToString() + "; " + bottomY.ToString() + ")";
            else
                tabPage3LabelResult.Text = "Нет пересечения!";
        }
    }


    class Point
    {
        public decimal X;
        public decimal Y;

        public Point()
        {
        }

        public Point(decimal x, decimal y)
        {
            this.X = x;
            this.Y = y;
        }
    }



    class Rectangle
    {
        public Point p1;
        public Point p2;

        public Rectangle(Point point1, Point point2)
        {
            p1 = new Point(Math.Min(point1.X, point2.X), Math.Max(point1.Y, point2.Y));
            p2 = new Point(Math.Max(point1.X, point2.X), Math.Min(point1.Y, point2.Y));
        }

    }



}


