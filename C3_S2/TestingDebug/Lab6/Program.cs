using System;
using System.Linq;

namespace Lab6
{
    class Program
    {
        static void Main(string[] args)
        {

        }
    }

    public class Post
    {
        public string Message { get; set; }
        public DateTime Date { get; set; }
        public string Author { get; set; }
        /// <summary>
        /// Определяет "рейтинг" сообщения
        /// </summary>
        /// <returns>Значение "рейтинга"</returns>
        public double CountRating()
        {
            var rating = 0.3 * CountFirstParam() + 0.7 * CountSecondParam();
            return rating;
        }
        /// <summary>
        /// Определяет "простой" параметр "полезности" сообщения (кол-во букв в сообщении)
        /// </summary>
        /// <returns>Значение "простого" параметра "полезности" сообщения</returns>
        private double CountFirstParam()
        {
            double param = Message.Count(Char.IsLetter);
            return param;
        }
        /// <summary>
        /// Определяет "сложный" параметр "полезности" сообщения (кол-во различных слов в сообщении)
        /// </summary>
        /// <returns>Значение "сложного" параметра "полезности" сообщения</returns>
        private double CountSecondParam()
        {
            var split = new[] { ' ', ',', ':', '.', '!', '?', '/', '-',};
            double param = Message.Split(split, StringSplitOptions.RemoveEmptyEntries).Distinct().Count();
            return param;
        }
    }

}
