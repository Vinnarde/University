using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms;

namespace Lab2
{
    public partial class Form1 : Form
    {
        private const int CenterX = 16 + 1654 / 2;
        private const int BottomY = 1080 - 80;
        private readonly Pen _p = new Pen(Color.Black, 4.0f);
        private static System.Timers.Timer aTimer;
        private float tickSpeed = 1000.0f / 1000.0f;
        private const float g = 9.81f;

        private float x_0, y_0, x_1, y_1, xSpeed_0, ySpeed_0, xSpeed_1, ySpeed_1, radius, b, L, H, alpha, m;


        public Form1()
        {
            InitializeComponent();
            SetStyle(
                ControlStyles.AllPaintingInWmPaint |
                ControlStyles.OptimizedDoubleBuffer |
                ControlStyles.UserPaint,
                true);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var shape = new Rectangle
            (
                (int)(CenterX + L * 500.0f - b * 1000.0f),
                (int)(BottomY - radius * 500.0f),
                (int)(radius * 1000.0f),
                (int)(radius * 1000.0f)
            );


            var angleValue = Convert.ToDouble(numericUpDownBeta.Value) * Math.PI / 180.0;
            xSpeed_1 = xSpeed_0 = (float)(numericUpDownSpeed.Value * Convert.ToDecimal(Math.Cos(angleValue)));
            ySpeed_1 = ySpeed_0 = (float)(numericUpDownSpeed.Value * Convert.ToDecimal(Math.Sin(angleValue)));
            radius = (float)numericUpDownRadius.Value;
            b = (float)numericUpDownb.Value;
            L = (float)numericUpDownL.Value;
            H = (float)numericUpDownH.Value;
            m = (float)numericUpDownMu.Value;
            x_1 = x_0 = (float)(CenterX + L * 500.0f - b * 1000.0f);
            y_1 = y_0 = BottomY - radius * 500.0f;


            alpha = ((float)numericUpDown1.Value) * (float)Math.PI / 180.0f;
            SetTimer();
            aTimer.Start();
        }

        private void SetTimer()
        {
            // Create a timer with a 16ms interval.
            aTimer = new System.Timers.Timer(tickSpeed);
            // Hook up the Elapsed event for the timer. 
            aTimer.Elapsed += OnTimedEvent;
            aTimer.AutoReset = true;

        }

        private void OnTimedEvent(Object source, ElapsedEventArgs e)
        {
            Draw(CreateGraphics());
        }

        private void Draw(Graphics gr)
        {
            gr.Clear(Color.AliceBlue);
            gr.DrawLine(_p, CenterX - L * 500.0f, BottomY, CenterX - L * 500.0f, BottomY - H * 250.0f);
            gr.DrawLine(_p, CenterX + L * 500.0f, BottomY, CenterX + L * 500.0f, BottomY - H * 250.0f);
            gr.DrawLine(_p, CenterX - L * 500.0f, BottomY - H * 250.0f, CenterX - L * 500.0f + (float)Math.Cos(alpha) * 10000.0f, 0 - (float)Math.Sin(alpha) * 10000.0f);
            gr.DrawLine(_p, CenterX + L * 500.0f, BottomY - H * 250.0f, CenterX + L * 500.0f + (float)Math.Cos(alpha) * 10000.0f, 0 - (float)Math.Sin(alpha) * 10000.0f);
            //new Point(x + Math.Cos(angle) * length, y + Math.Sin(angle) * length);

            var shape = new Rectangle
                (
                (int)(x_0),
                (int)(y_0),
                (int)(radius * 1000.0f),
                (int)(radius * 1000.0f)
                );

            if (ySpeed_0 - m * g * tickSpeed/1000.0f > 0)
            {
                x_0 = x_1;
                y_0 = y_1;
                ySpeed_0 = ySpeed_1;

                x_1 = x_0 + xSpeed_0 * tickSpeed - m * g / 2.0f * tickSpeed * tickSpeed;
                y_1 = y_0 + ySpeed_0 * tickSpeed - m * g / 2.0f * tickSpeed * tickSpeed;
                ySpeed_1 = ySpeed_0 - m * g * tickSpeed / 1000.0f;
            }
            gr.DrawEllipse(_p, shape);




            //for (var i = 0; i < 100; i++)
            //{
            //    gr.DrawLine(_p, CenterX - 100, BottomY, CenterX - 100, BottomY - 400);
            //    gr.DrawLine(_p, CenterX + 100, BottomY, CenterX + 100, BottomY - 400);
            //}

        }
    }
}
