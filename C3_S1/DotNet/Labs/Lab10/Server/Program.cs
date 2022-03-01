using ServerClasses;
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Threading;

class Server
{
    static void Main()
    {
        Console.WriteLine("Loading server...");
        IPEndPoint localEndPoint = new IPEndPoint(IPAddress.Any, 8888);

        Database.Initialize();

        TimerCallback tmCallback = Backup;
        Timer timer = new Timer(tmCallback, "", 10000, 10000);

        try
        {
            Socket listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            listener.Bind(localEndPoint);
            listener.Listen(10);

            Console.Clear();
            Console.WriteLine("Listening on {0}", localEndPoint);

            while (true)
            { 
                Socket socket = listener.Accept();
                Task handlerTask = new Task(Handle, socket);
                handlerTask.Start();
            }

        }
        catch (Exception ex) { Console.WriteLine(ex.ToString()); }
        finally { Console.ReadLine(); }
            
    }

    private static void Handle(object o)
    {
        Socket sock = (Socket)o;

        if (sock == null) return;

        while(true)
        {
            string data = "";
            while (true)
            {
                byte[] bytes = new byte[1024];
                int bytesRec = sock.Receive(bytes);
                data += Encoding.UTF8.GetString(bytes, 0, bytesRec);
                if (data.IndexOf("#") > -1)
                {
                    break;
                }
            }
            // remove hash symbol
            data = data.Remove(data.Length - 1);

            Console.WriteLine("REQUEST: {0}", data);

            Response response;

            try
            {
                Request request = JsonConvert.DeserializeObject<Request>(data);
                response = ProcessRequest(request);
            }
            catch (Exception)
            {
                response = new Response() { error = "Error processing request" };
            }
            try
            {
                var jsonResponse = JsonConvert.SerializeObject(response);
                byte[] msg = Encoding.UTF8.GetBytes(jsonResponse);
                sock.Send(msg);
                Console.WriteLine("JSON RESPONSE: " + jsonResponse);
            }
            catch (Exception)
            {
                break;
            }
        }

        sock.Shutdown(SocketShutdown.Both);
        sock.Close();
    }

    static Response ProcessRequest(Request request)
    {
        JObject jobj;
        Book book; long id;

        Console.WriteLine("Processing request" + request.action);
        Response response = new Response();

        switch (request.action)
        {
            case "get_book":
                id = (long)request.data;
                response.data = GetBook(id);
                break;
            case "get_all_books":
                response.data = GetAllBooks();
                break;
            case "create_book":
                jobj = (JObject)request.data;
                book = jobj.ToObject<Book>();
                response.data = CreateBook(book);
                break;
            case "update_book":
                jobj = (JObject)request.data;
                book = jobj.ToObject<Book>();
                response.data = UpdateBook(book);
                break;
            case "delete_book":
                id = (long)request.data;
                response.data = DeleteBook(id);
                break;
            default:
                break;
        }

        return response;
    }

    static object GetBook(long id)
    {
        return Database.GetBookById(id);
    }

    static object GetAllBooks()
    {
        return Database.GetAllBooks();
    }

    static object CreateBook(Book book)
    {
        return Database.CreateBook(book);
    }

    static object UpdateBook(Book book)
    {
        Database.UpdateBook(book);
        return book;
    }

    static object DeleteBook(long id)
    {
        Database.DeleteBook(id);
        return id;
    }

    static void Backup (object _)
    {
        Console.WriteLine("Creating a backup...");
        Database.SaveToJSON();
    }

}
