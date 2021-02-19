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

namespace Lab_2
{
    public partial class Form1 : Form
    {

        private ulong _counter;
        private readonly Stopwatch _sw = new Stopwatch();
        private Point _p1, _p2;
        private readonly Pen _p = new Pen(Color.DarkGray, 2.0f);
        public Form1()
        {
            var gmh = new GlobalMouseHandler();
            gmh.TheMouseMoved += gmh_TheMouseMoved;
            Application.AddMessageFilter(gmh);
            _p1.X = _p1.Y = 0;

            InitializeComponent();
        }

        private void MoveCursor()
        {
            // Set the Current cursor, move the cursor's Position,
            // and set its clipping rectangle to the form. 

            Cursor = new Cursor(Cursor.Current.Handle);
            Cursor.Position = new Point(Location.X + Size.Width/2, Location.Y + Size.Height);

            _sw.Stop();
            _sw.Reset();
            _p1.X = _p1.Y = 0;
            _counter = 0;
            //Cursor.Clip = new Rectangle(this.Location, this.Size);
        }

        private void gmh_TheMouseMoved()
        {
            if (_p1.X == 0 && _p1.Y == 0)
            {
                _p2 = Cursor.Position;
                _p1 = _p2;
            }
            else if (_p1 != _p2)
            {
                _counter++;

                _p1 = _p2;

                if (_counter == 1)
                    _sw.Start();
            }

            _p2 = Cursor.Position;

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
                if (m.Msg == WM_MOUSEMOVE) TheMouseMoved?.Invoke();

                // Always allow message to continue to the next filter control
                return false;
            }

            #endregion
        }

        private async void button10_Click(object sender, EventArgs e)
        {
            Button[] listOfButtons = new Button[]
                {button1, button2, button3, button4, button5, button6, button7, button8, button9};

            for (var i = 8; i < 10; i++)
            {
                int[] arr = new int[i];

                for (int k = 0; k < i; k++)
                    arr[k] = k;

                for (var j = 0; j < 5; j++)
                {
                    foreach (var x in listOfButtons)
                    {
                        x.Visible = false;
                    }

                    Random rand = new Random();
                    var rngResult = rand.Next(i);
                    label1.Text = Convert.ToString(rngResult + 1);

                    shuffle(arr);



                    for (var l = 0; l < i; l++)
                    {
                        listOfButtons[l].Text = Convert.ToString(arr[l] + 1);
                        listOfButtons[l].Visible = true;
                    }

                    var resultIndex = 0;
                    for (int h = 0; h < i; h++)
                        if (listOfButtons[h].Text == label1.Text)
                            resultIndex = h;


                    await listOfButtons[resultIndex].WhenClicked();
                    MoveCursor();
                    label2.Text = "Time taken: " + _sw.ElapsedMilliseconds + "ms";


                }
            }

        }

        public static void shuffle(int[] array)
        {
            Random rng = new Random();   // i.e., java.util.Random.
            int n = array.Length;        // The number of items left to shuffle (loop invariant).
            while (n > 1)
            {
                int k = rng.Next(n);  // 0 <= k < n.
                n--;                     // n is now the last pertinent index;
                int temp = array[n];     // swap array[n] with array[k] (does nothing if k == n).
                array[n] = array[k];
                array[k] = temp;
            }
        }


    }
    public static class Utils
    {
        public static Task WhenClicked(this Control target)
        {
            var tcs = new TaskCompletionSource<object>();
            EventHandler onClick = null;
            onClick = (sender, e) =>
            {
                target.Click -= onClick;
                tcs.TrySetResult(null);
            };
            target.Click += onClick;
            return tcs.Task;
        }
    }
}
