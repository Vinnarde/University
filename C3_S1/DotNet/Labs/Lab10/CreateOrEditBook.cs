using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using ServerClasses;

public partial class CreateOrEditBook : System.Windows.Forms.Form
{
    public Book Model;
    private bool isCreate = false;
    private Socket Socket;


    public CreateOrEditBook(Socket socket)
    {
        Socket = socket;
        isCreate = true;
        Model = new Book();
        InitializeComponent();
    }

    public CreateOrEditBook(Socket sock, Book book)
    {
        Socket = sock;
        Model = book;
        InitializeComponent();
        Fill();
    }

    private void Fill()
    {
        titleField.Text = Model.title;
        genreField.Text = Model.genre;
        authorIdField.Text = Model.authorId.ToString();
        pagesField.Text = Model.pages.ToString();
    }

    private void ChangeModel()
    {
        Model.title = titleField.Text;
        Model.genre = genreField.Text;
        int.TryParse(authorIdField.Text, out Model.authorId);
        int.TryParse(pagesField.Text, out Model.pages);
    }

    private void saveButton_Click(object sender, EventArgs e)
    {
        ChangeModel();

        Request request = new Request() 
        { 
            action = isCreate ? "create_book" : "update_book", 
            data = Model 
        };
        string jsonRequest = JsonConvert.SerializeObject(request) + "#";
        byte[] msg = Encoding.UTF8.GetBytes(jsonRequest);
        byte[] bytes = new byte[1024];
        Socket.Send(msg);

        int bytesRec = Socket.Receive(bytes);
        string rawResponse = Encoding.UTF8.GetString(bytes, 0, bytesRec);

        Console.WriteLine("Запрос к серверу: {0}\n", jsonRequest);
        Console.WriteLine("Ответ от сервера: {0}\n", rawResponse);
    }
}
