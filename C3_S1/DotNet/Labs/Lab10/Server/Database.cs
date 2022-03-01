using Newtonsoft.Json;
using ServerClasses;
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public static class Database
{
    private static ConcurrentDictionary<int, Book> data;
    private static int _maxID = 5;
    private static string _backupFile = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "/backup.json";
        
    public static void Initialize()
    {
        //data = new ConcurrentDictionary<int, Book>();
        //Book book1 = new Book() { id = _maxID++, authorId = 1, genre = "Programming", pages = 1000, title = "SQL cookbook" };
        //Book book2 = new Book() { id = _maxID++, authorId = 2, genre = "Programming", pages = 234, title = "Идеальный код" };
        //Book book3 = new Book() { id = _maxID++, authorId = 3, genre = "Programming", pages = 763, title = "C Programming language" };
        //data.TryAdd(book1.id, book1);
        //data.TryAdd(book2.id, book2);
        //data.TryAdd(book3.id, book3);

        //SaveToJSON();

        LoadFromFile();
    }

    private static void LoadFromFile()
    {
        data = JsonConvert.DeserializeObject<ConcurrentDictionary<int, Book>>(File.ReadAllText(_backupFile));
    }

    public static void SaveToJSON ()
    {
        string json = JsonConvert.SerializeObject(data);
        File.WriteAllText(_backupFile, json);
    }

    public static Book GetBookById(long id)
    {
        return data[(int)id];
    }
    public static Book[] GetAllBooks()
    {
        return data.Values.ToArray();
    }

    public static Book CreateBook(Book book)
    {
        book.id = _maxID++;
        data.TryAdd(book.id, book);
        return book;
    }

    public static void UpdateBook(Book book)
    {
        data.TryUpdate(book.id, book, data[book.id]);
    }

    public static void DeleteBook(long id)
    {
        Book _;
        data.TryRemove((int)id, out _);
    }
}
