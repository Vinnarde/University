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

namespace Lab_1
{
    public partial class Form1 : Form
    {
        UInt64 counter = 0;
        Stopwatch sw = new Stopwatch();
        Point p1, p2;
        public Form1()
        {
            GlobalMouseHandler gmh = new GlobalMouseHandler();
            gmh.TheMouseMoved += new MouseMovedEvent(gmh_TheMouseMoved);
            Application.AddMessageFilter(gmh);
            p1.X = p1.Y = 0;

            InitializeComponent();
            //MoveCursor();
        }

        private void MoveCursor()
        {
            // Set the Current cursor, move the cursor's Position,
            // and set its clipping rectangle to the form. 

            this.Cursor = new Cursor(Cursor.Current.Handle);
            //Cursor.Position = new Point(Form1,Form1.MousePosition.Y);
            //Cursor.Clip = new Rectangle(this.Location, this.Size);
        }

        void gmh_TheMouseMoved()
        {
            if (p1.X == 0 && p1.Y == 0)
            {
                p2 = System.Windows.Forms.Cursor.Position;
                p1 = p2;
            }
            else if (p1 != p2)
            {
                counter++;

                p1 = p2;

                if (counter == 1)
                    sw.Start();
            }
            p2 = System.Windows.Forms.Cursor.Position;

            //Point cur_pos = System.Windows.Forms.Cursor.Position;
            //textBox1.Text += cur_pos.ToString();
            //System.Console.WriteLine(cur_pos);
        }

        public delegate void MouseMovedEvent();

        public class GlobalMouseHandler : IMessageFilter
        {
            private const int WM_MOUSEMOVE = 0x0200;

            public event MouseMovedEvent TheMouseMoved;

            #region IMessageFilter Members

            public bool PreFilterMessage(ref Message m)
            {
                if (m.Msg == WM_MOUSEMOVE)
                {
                    if (TheMouseMoved != null)
                    {
                        TheMouseMoved();
                    }
                }
                // Always allow message to continue to the next filter control
                return false;
            }

            #endregion
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            sw.Stop();
            textBox1.Text += sw.Elapsed.ToString() + "\r\n";
            sw.Reset();
            counter = 0;
        }
    }
}
