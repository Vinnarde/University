using System;
using System.Windows.Forms;

namespace Lab7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public void Intersection(Line line1, Line line2)
        {
            var A1 = line1.p2.y - line1.p1.y;
            var B1 = line1.p1.x - line1.p2.x;
            var C1 = A1 * line1.p1.x + B1 * line1.p1.y;

            var A2 = line2.p2.y - line2.p1.y;
            var B2 = line2.p1.x - line2.p2.x;
            var C2 = A2 * line2.p1.x + B2 * line2.p1.y;

            var det = A1 * B2 - A2 * B1;

            if (det == 0)
            {
                labelResult.Text = "Lines don't intersect";
            }
            else
            {
                var x = (B2 * C1 - B1 * C2) / det;
                var y = (A1 * C2 - A2 * C1) / det;
                labelResult.Text = "Lines intersect at (" + x + "; " + y + ")";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var line1 = new Line
            (
                new Point(numericUpDownLine1X1.Value, numericUpDownLine1Y1.Value),
                new Point(numericUpDownLine1X2.Value, numericUpDownLine1Y2.Value)
            );

            var line2 = new Line
            (
                new Point(numericUpDownLine2X1.Value, numericUpDownLine2Y1.Value),
                new Point(numericUpDownLine2X2.Value, numericUpDownLine2Y2.Value)
            );

            Intersection(line1, line2);
        }
    }


    public class Point
    {
        public decimal x;
        public decimal y;

        public Point()
        {
        }

        public Point(decimal x, decimal y)
        {
            this.x = x;
            this.y = y;
        }
    }

    public class Line
    {
        public Point p1, p2;

        public Line()
        {
        }

        public Line(Point p1, Point p2)
        {
            this.p1 = p1;
            this.p2 = p2;
        }
    }
}