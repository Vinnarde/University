using System;

namespace ServerClasses
{
    [Serializable]
    public class Book
    {
        public int id;
        public string title;
        public string genre;
        public int authorId;
        public int pages;

        public override string ToString()
        {
            return $"{title} ({genre})";
        }
    }
}
