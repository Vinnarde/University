using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using ServerClasses;

public partial class Form : System.Windows.Forms.Form
{   
    Socket socket;
    byte[] bytes = new byte[10240];

    List<Book> books = new List<Book>();

    public Form()
    {
        InitializeComponent();
    }

    void ConnectToServer()
    {
        socket = ConnectSocket("localhost", 8888);
        if (socket == null)
        {
            MessageBox.Show("Unable to connect to server!");
        }

    }

    void LoadBooks()
    {
        Request request = new Request() { action = "get_all_books" };
        string jsonRequest = JsonConvert.SerializeObject(request) + "#";
        byte[] msg = Encoding.UTF8.GetBytes(jsonRequest);
        socket.Send(msg);

        int bytesRec = socket.Receive(bytes);
        string rawResponse = Encoding.UTF8.GetString(bytes, 0, bytesRec);

        Console.WriteLine("[REQUEST]: {0}\n", jsonRequest);
        Console.WriteLine("[RESPONSE]: {0}\n", rawResponse);

        Response response = JsonConvert.DeserializeObject<Response>(rawResponse);
        JArray array = (JArray)response.data;
        books = array.ToObject<List<Book>>();

        booksList.Items.Clear();
        foreach (Book book in books)
        {
            var litem = new ListViewItem(book.ToString()) { Tag = book };
            booksList.Items.Add(litem);
        }
    }

    Socket ConnectSocket(string server, int port)
    {
        Socket s = null;
        IPHostEntry hostEntry = Dns.GetHostEntry(server);

        // Loop through the AddressList to obtain the supported AddressFamily. This is to avoid
        // an exception that occurs when the host IP Address is not compatible with the address family
        // (typical in the IPv6 case).
        foreach (IPAddress address in hostEntry.AddressList)
        {
            IPEndPoint ipe = new IPEndPoint(address, port);
            Socket tempSocket =
                new Socket(ipe.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            try
            {
                tempSocket.Connect(ipe);
            }
            catch (Exception) {}

            if (tempSocket.Connected)
            {
                s = tempSocket;
                break;
            }
            else continue;
        }
        return s;
    }

    private void EditBook(Book book)
    {
        var form = new CreateOrEditBook(socket, book);

        if (form.ShowDialog() == DialogResult.OK)
            LoadBooks();
    }

    private void DeleteBook(int id)
    {
        Request request = new Request() { action = "delete_book", data = id };
        string jsonRequest = JsonConvert.SerializeObject(request) + "#";
        byte[] msg = Encoding.UTF8.GetBytes(jsonRequest);
        byte[] bytes = new byte[1024];
        socket.Send(msg);

        int bytesRec = socket.Receive(bytes);
        string jsonResponse = Encoding.UTF8.GetString(bytes, 0, bytesRec);

        Console.WriteLine("[REQUEST]: {0}\n", jsonRequest);
        Console.WriteLine("[RESPONSE]: {0}\n", jsonResponse);

        LoadBooks();
    }

    private void CreateBook()
    {
        var form = new CreateOrEditBook(socket);

        if (form.ShowDialog() == DialogResult.OK)
            LoadBooks();
    }


    private void Form_Load(object sender, EventArgs e)
    {
        ConnectToServer();
        if (socket != null)
            LoadBooks();
    }

    private void booksList_DoubleClick(object sender, EventArgs e)
    {
        var list = (ListView)sender;
        if (list.SelectedItems.Count > 0)
        {
            EditBook((Book)list.SelectedItems[0].Tag);
        }
    }

    private void createButton_Click(object sender, EventArgs e)
    {
        CreateBook();
    }

    private void booksList_KeyUp(object sender, KeyEventArgs e)
    {
        if (e.KeyCode == Keys.Delete)
        {
            var list = (ListView)sender;
            if (list.SelectedItems.Count > 0)
            {
                var book = (Book)list.SelectedItems[0].Tag;
                DeleteBook(book.id);
            }
        }
    }
}
