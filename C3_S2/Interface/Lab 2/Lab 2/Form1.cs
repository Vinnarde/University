using System;
using System.Diagnostics;
using System.Drawing;
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
        Random rand = new Random();


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
            Cursor.Position = new Point(Location.X + label1.Location.X + label1.Width / 2, Location.Y + label1.Location.Y + label1.Height / 5 * 3);

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
            textBox1.Clear();
            var listOfButtons = new Button[] { button1, button2, button3, button4, button5, button6, button7, button8, button9 };
            MoveCursor();
            _sw.Start();

            for (var i = 2; i < 10; i++)
            {
                var arr = new int[i];

                long avgTime = 0;

                for (var k = 0; k < i; k++)
                    arr[k] = k;

                for (var j = 0; j < 5; j++)
                {
                    foreach (var x in listOfButtons) x.Visible = false;

                    var rngResult = rand.Next(i);
                    label1.Text = Convert.ToString(rngResult + 1);

                    Shuffle(arr);


                    for (var l = 0; l < i; l++)
                    {
                        listOfButtons[l].Text = Convert.ToString(arr[l] + 1);
                        listOfButtons[l].Visible = true;
                    }

                    var resultIndex = 0;
                    for (var h = 0; h < i; h++)
                        if (listOfButtons[h].Text == label1.Text)
                            resultIndex = h;


                    await listOfButtons[resultIndex].WhenClicked();
                    avgTime += _sw.ElapsedMilliseconds;
                    label2.Text = "Time taken: " + _sw.ElapsedMilliseconds + "ms";
                    MoveCursor();
                }

                avgTime /= 5;
                textBox1.Text += i + "\t" + avgTime + Environment.NewLine;
            }
        }

        private async void button11_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            label1.Visible = false;
            var listOfButtons = new Button[] { button1, button2, button3, button4, button5, button6, button7, button8, button9 };
            MoveCursor();
            _sw.Start();

            var fontColor = new Color[] { Color.Yellow, Color.Green, Color.Blue, Color.Red };
            //var fontColor = new Color[] {Color.Green };

            //foreach (var c in fontColor)
            //{
            //    textBox1.Text += c + Environment.NewLine;
            //    for (var i = 2; i < 10; i++)
            //    {
            //        long avgTime = 0;

            //        avgTime = 0;


            //        for (var j = 0; j < 5; j++)
            //        {
            //            foreach (var x in listOfButtons)
            //            {
            //                x.Visible = false;
            //                x.ForeColor = Color.Black;
            //                x.BackColor = Color.White;
            //            }

            //            var rngResult = rand.Next(i);
            //            listOfButtons[rngResult].ForeColor = c;

            //            for (var l = 0; l < i; l++)
            //            {
            //                listOfButtons[l].Visible = true;
            //            }

            //            await listOfButtons[rngResult].WhenClicked();
            //            avgTime += _sw.ElapsedMilliseconds;
            //            label2.Text = "Time taken: " + _sw.ElapsedMilliseconds + "ms";
            //            MoveCursor();
            //        }
            //        avgTime /= 5;
            //        textBox1.Text += i + "\t" + avgTime + Environment.NewLine;

            //    }
            //}

            //textBox1.Text += Environment.NewLine + Environment.NewLine;

            var backColor = new Color[] { Color.Black, Color.Yellow, Color.Green, Color.Blue, Color.Red };

            foreach (var c in backColor)
            {
                textBox1.Text += c + Environment.NewLine;
                for (var i = 2; i < 10; i++)
                {
                    long avgTime = 0;

                    avgTime = 0;

                    for (var j = 0; j < 5; j++)
                    {
                        foreach (var x in listOfButtons)
                        {
                            x.Visible = false;
                            x.ForeColor = Color.Black;
                            x.BackColor = Color.White;
                        }

                        var rngResult = rand.Next(i);
                        listOfButtons[rngResult].BackColor = c;

                        for (var l = 0; l < i; l++)
                        {
                            listOfButtons[l].Visible = true;
                        }

                        await listOfButtons[rngResult].WhenClicked();
                        avgTime += _sw.ElapsedMilliseconds;
                        label2.Text = "Time taken: " + _sw.ElapsedMilliseconds + "ms";
                        MoveCursor();
                    }
                    avgTime /= 5;
                    textBox1.Text += i + "\t" + avgTime + Environment.NewLine;

                }
            }
        }

        public static void Shuffle(int[] array)
        {
            var rng = new Random(); // i.e., java.util.Random.
            var n = array.Length; // The number of items left to shuffle (loop invariant).
            while (n > 1)
            {
                var k = rng.Next(n); // 0 <= k < n.
                n--; // n is now the last pertinent index;
                var temp = array[n]; // swap array[n] with array[k] (does nothing if k == n).
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