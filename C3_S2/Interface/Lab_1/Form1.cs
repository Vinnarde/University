using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_1
{
    public partial class Form1 : Form
    {
        #region variables

        private ulong _counter;
        private readonly Stopwatch _sw = new Stopwatch();
        private Point _p1, _p2;
        private readonly Pen _p = new Pen(Color.DarkGray, 2.0f);
        private int missClickCount;
        private int curIndex;

        #endregion

        public Form1()
        {
            var gmh = new GlobalMouseHandler();
            gmh.TheMouseMoved += gmh_TheMouseMoved;
            Application.AddMessageFilter(gmh);
            _p1.X = _p1.Y = 0;


            InitializeComponent();
            //MoveCursor();
        }


        private void MoveCursor()
        {
            // Set the Current cursor, move the cursor's Position,
            // and set its clipping rectangle to the form. 

            Cursor = new Cursor(Cursor.Current.Handle);
            Cursor.Position = new Point(Location.X + 1330 / 2 + 40, Location.Y + 1060 / 2 + 20);

            _sw.Stop();
            _sw.Reset();
            _p1.X = _p1.Y = 0;
            _counter = 0;
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

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private async void button2_Click(object sender, EventArgs e)
        {
            const int size = 6;
            var temp = new Size(Convert.ToInt32(size * 1.5), size);
            button1.Size = temp;

            textBox1.Text = "";
            button1.Visible = true;
            var g = CreateGraphics();
            const int centerX = 1320 / 2 + 40;
            const int centerY = 1000 / 2 + 20;

            var shape = new Rectangle(100, 100, 20, 20);

            int[] array = { 0, 20, 40, 60, 100, 150, 200, 250, 300, 350 };
            foreach (var x in array)
            {
                shape.X = centerX - x;
                shape.Y = centerY - x;
                shape.Width = shape.Height = 2 * x;
                g.Clear(Color.WhiteSmoke);
                g.DrawEllipse(_p, shape);

                textBox1.Text += "S = " + x + "\r\n";

                for (var i = 0; i < 5; i++)
                {
                    MoveCursor();
                    _p1.X = _p1.Y = 0;
                    _sw.Stop();

                    var rand = new Random();
                    var angle = 1 + rand.Next(359);
                    var xPos = x * Math.Sin(angle * Math.PI / 180) + centerX;
                    var yPos = x * Math.Cos(angle * Math.PI / 180) + centerY;

                    if (angle <= 90)
                    {
                    }
                    else if (angle <= 180)
                    {
                        yPos -= button1.Size.Height;
                    }
                    else if (angle <= 270)
                    {
                        xPos -= button1.Size.Width;
                        yPos -= button1.Size.Height;
                    }
                    else
                    {
                        xPos -= button1.Size.Width;
                    }

                    var tempPoint = new Point(Convert.ToInt32(xPos), Convert.ToInt32(yPos));
                    button1.Location = tempPoint;

                    await button1.WhenClicked();
                }

                g.Clear(Color.WhiteSmoke);
                textBox1.Text += "\r\n\r\n";
                button1.Visible = false;
                await button5.WhenClicked();
                button1.Visible = true;
            }

            button1.Visible = false;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            MoveCursor();
            if (curIndex < 10)
                missClickCount++;
            curIndex++;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
        }

        private async void button3_Click(object sender, EventArgs e)
        {
            var size = 6;
            button1.Size = new Size(Convert.ToInt32(1.5 * size), size);

            var distance = 300;

            textBox1.Text = "";
            button1.Visible = true;
            var g = CreateGraphics();
            const int centerX = 1320 / 2 + 40;
            const int centerY = 1000 / 2 + 20;


            var shape = new Rectangle { Y = centerY - distance, X = centerX - distance };
            shape.Width = shape.Height = 2 * distance;
            g.DrawEllipse(_p, shape);


            int[] array = { 8, 10, 12, 15, 20, 30, 40, 50, 70, 100 };
            foreach (var x in array)
            {
                var temp = new Size(Convert.ToInt32(x * 1.5), x);
                button1.Size = temp;


                textBox1.Text += "D = " + x + "\r\n";

                for (var i = 0; i < 5; i++)
                {
                    MoveCursor();

                    var rand = new Random();
                    var angle = 1 + rand.Next(359);
                    var xPos = distance * Math.Sin(angle * Math.PI / 180) + centerX;
                    var yPos = distance * Math.Cos(angle * Math.PI / 180) + centerY;

                    if (angle <= 90)
                    {
                    }
                    else if (angle <= 180)
                    {
                        yPos -= button1.Size.Height;
                    }
                    else if (angle <= 270)
                    {
                        xPos -= button1.Size.Width;
                        yPos -= button1.Size.Height;
                    }
                    else
                    {
                        xPos -= button1.Size.Width;
                    }

                    var tempPoint = new Point(Convert.ToInt32(xPos), Convert.ToInt32(yPos));
                    button1.Location = tempPoint;

                    await button1.WhenClicked();
                }

                textBox1.Text += "\r\n\r\n";
                button1.Visible = false;
                await button5.WhenClicked();
                button1.Visible = true;
            }

            button1.Visible = false;
            g.Clear(Color.WhiteSmoke);
        }

        private async void button4_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            button1.Visible = true;
            var g = CreateGraphics();
            const int centerX = 1320 / 2 + 40;
            const int centerY = 1000 / 2 + 20;

            var shape = new Rectangle(100, 100, 20, 20);

            int[] arrayS = { 0, 20, 40, 60, 100, 150, 200, 250, 300, 350 };
            int[] arrayD = { 8, 10, 12, 15, 20, 30, 40, 50, 70, 100 };
            textBox1.Text += "S/D \t Time" + Environment.NewLine;
            foreach (var x in arrayS)
            {
                shape.X = centerX - x;
                shape.Y = centerY - x;
                shape.Width = shape.Height = 2 * x;
                


                foreach (var y in arrayD)
                {
                    var temp = new Size(Convert.ToInt32(y * 1.5), y);
                    button1.Size = temp;

                    long avgTime = 0;

                    for (var i = 0; i < 3; i++)
                    {
                        MoveCursor();
                        

                        var rand = new Random();
                        var angle = 1 + rand.Next(359);
                        var xPos = x * Math.Sin(angle * Math.PI / 180) + centerX;
                        var yPos = x * Math.Cos(angle * Math.PI / 180) + centerY;

                        if (angle <= 90)
                        {
                        }
                        else if (angle <= 180)
                        {
                            yPos -= button1.Size.Height;
                        }
                        else if (angle <= 270)
                        {
                            xPos -= button1.Size.Width;
                            yPos -= button1.Size.Height;
                        }
                        else
                        {
                            xPos -= button1.Size.Width;
                        }

                        var tempPoint = new Point(Convert.ToInt32(xPos), Convert.ToInt32(yPos));
                        button1.Location = tempPoint;
                        g.Clear(Color.WhiteSmoke);
                        g.DrawEllipse(_p, shape);

                        await button1.WhenClicked();
                        avgTime += _sw.ElapsedMilliseconds;
                    }

                    avgTime /= 3;
                    textBox1.Text += 1.0 * x / y + "\t" + avgTime + Environment.NewLine;
                }

                button1.Visible = false;
                await button5.WhenClicked();
                button1.Visible = true;
            }

            textBox1.Text += "\r\n\r\n";


            g.Clear(Color.WhiteSmoke);
            button1.Visible = false;
        }

        private async void button6_Click(object sender, EventArgs e)
        {
            var size = 7; // size of button 2D*D rectangle
            var timeLimit = 1200; // ms
            const int centerX = 1320 / 2 + 40;
            const int centerY = 1000 / 2 + 20;
            int[] distanceArr = { 0, 20, 40, 60, 100, 150, 200, 250, 300, 350 };

            var timeExceedsCount = 0;
            var g = CreateGraphics();
            var shape = new Rectangle();

            button1.Size = new Size(2 * size, size);

            label1.Visible = label2.Visible = label3.Visible = label4.Visible = button1.Visible = true;
            textBox1.Clear();

            textBox1.Text += "S \t Errors" + Environment.NewLine;

            foreach (var x in distanceArr)
            {
                shape.X = centerX - x;
                shape.Y = centerY - x;
                shape.Width = shape.Height = 2 * x;
                missClickCount = timeExceedsCount = 0;

                for (curIndex = 0; curIndex < 10; curIndex++)
                {
                    MoveCursor();

                    var rand = new Random();
                    var angle = 1 + rand.Next(359);
                    var xPos = x * Math.Sin(angle * Math.PI / 180) + centerX;
                    var yPos = x * Math.Cos(angle * Math.PI / 180) + centerY;

                    if (angle <= 90)
                    {
                    }
                    else if (angle <= 180)
                    {
                        yPos -= button1.Size.Height;
                    }
                    else if (angle <= 270)
                    {
                        xPos -= button1.Size.Width;
                        yPos -= button1.Size.Height;
                    }
                    else
                    {
                        xPos -= button1.Size.Width;
                    }

                    var tempPoint = new Point(Convert.ToInt32(xPos), Convert.ToInt32(yPos));
                    button1.Location = tempPoint;

                    g.Clear(Color.Blue);
                    g.DrawEllipse(_p, shape);

                    if (curIndex >= 10) break;

                    await button1.WhenClicked();
                    var time = _sw.ElapsedMilliseconds;
                    if (time >= timeLimit && curIndex < 10)
                        timeExceedsCount++;
                    _sw.Reset();

                    label1.Text = "Time taken: " + time;
                    label2.Text = "Errors: " + (timeExceedsCount + missClickCount);
                    label3.Text = "Errors by accuracy: " + missClickCount;
                    label4.Text = "Errors by time: " + timeExceedsCount;
                }
                button1.Visible = false;
                g.Clear(Color.Blue);
                textBox1.Text += x + " \t " + (timeExceedsCount + missClickCount) + Environment.NewLine;
                await button5.WhenClicked();
                button1.Visible = true;
            }

            label1.Visible = label2.Visible = label3.Visible = label4.Visible = button1.Visible = false;
        }

        private async void button7_Click(object sender, EventArgs e)
        {
            var distance = 150; // distance to button
            var timeLimit = 1200; // ms
            const int centerX = 1320 / 2 + 40;
            const int centerY = 1000 / 2 + 20;
            int[] buttonSizeArr = { 5, 6, 7, 8, 9, 10, 12, 15, 20, 25 };

            var timeExceedsCount = 0;
            var g = CreateGraphics();
            var shape = new Rectangle();

            shape.X = centerX - distance;
            shape.Y = centerY - distance;
            shape.Width = shape.Height = 2 * distance;

            label1.Visible = label2.Visible = label3.Visible = label4.Visible = button1.Visible = true;
            textBox1.Clear();

            textBox1.Text += "D \t Errors" + Environment.NewLine;

            foreach (var x in buttonSizeArr)
            {
                button1.Size = new Size(2 * x, x);
                missClickCount = timeExceedsCount = 0;

                for (curIndex = 0; curIndex < 10; curIndex++)
                {
                    MoveCursor();

                    var rand = new Random();
                    var angle = 1 + rand.Next(359);
                    var xPos = distance * Math.Sin(angle * Math.PI / 180) + centerX;
                    var yPos = distance * Math.Cos(angle * Math.PI / 180) + centerY;

                    if (angle <= 90)
                    {
                    }
                    else if (angle <= 180)
                    {
                        yPos -= button1.Size.Height;
                    }
                    else if (angle <= 270)
                    {
                        xPos -= button1.Size.Width;
                        yPos -= button1.Size.Height;
                    }
                    else
                    {
                        xPos -= button1.Size.Width;
                    }

                    button1.Location = new Point(Convert.ToInt32(xPos), Convert.ToInt32(yPos));

                    g.Clear(Color.Blue);
                    g.DrawEllipse(_p, shape);

                    if (curIndex >= 10) break;

                    await button1.WhenClicked();
                    var time = _sw.ElapsedMilliseconds;
                    if (time >= timeLimit && curIndex < 10)
                        timeExceedsCount++;
                    _sw.Reset();

                    label1.Text = "Time taken: " + time;
                    label2.Text = "Errors: " + (timeExceedsCount + missClickCount);
                    label3.Text = "Errors by accuracy: " + missClickCount;
                    label4.Text = "Errors by time: " + timeExceedsCount;
                }
                button1.Visible = false;
                g.Clear(Color.Blue);
                textBox1.Text += x + " \t " + (timeExceedsCount + missClickCount) + Environment.NewLine;
                await button5.WhenClicked();
                button1.Visible = true;
            }

            label1.Visible = label2.Visible = label3.Visible = label4.Visible = button1.Visible = false;
        }

        private void button5_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //_sw.Stop();
            //textBox1.Text += _sw.Elapsed + "\r\n";
            //_sw.Reset();
            //_counter = 0;
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

    public class MultiMap<V>
    {
        Dictionary<string, List<V>> _dictionary =
            new Dictionary<string, List<V>>();

        public void Add(string key, V value)
        {
            // Add a key.
            List<V> list;
            if (this._dictionary.TryGetValue(key, out list))
            {
                list.Add(value);
            }
            else
            {
                list = new List<V>();
                list.Add(value);
                this._dictionary[key] = list;
            }
        }

        public IEnumerable<string> Keys
        {
            get
            {
                // Get all keys.
                return this._dictionary.Keys;
            }
        }

        public List<V> this[string key]
        {
            get
            {
                // Get list at a key.
                List<V> list;
                if (!this._dictionary.TryGetValue(key, out list))
                {
                    list = new List<V>();
                    this._dictionary[key] = list;
                }
                return list;
            }
        }
    }
}