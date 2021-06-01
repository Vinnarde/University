using System;
using System.Linq;
using System.Text.RegularExpressions;

namespace Lab6
{
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
            //var rating = 0.5 * CountFirstParam() + 0.5 * CountSecondParam();
            var rating = 0.3 * CountFirstParam() + 0.7 * CountSecondParam();
            return rating;
        }
        /// <summary>
        /// Определяет "простой" параметр "полезности" сообщения (кол-во букв в сообщении)
        /// </summary>
        /// <returns>Значение "простого" параметра "полезности" сообщения</returns>
        private double CountFirstParam()
        {
            return Message.Count(char.IsLetter);
        }
        /// <summary>
        /// Определяет "сложный" параметр "полезности" сообщения (кол-во различных слов в сообщении)
        /// </summary>
        /// <returns>Значение "сложного" параметра "полезности" сообщения</returns>
        private double CountSecondParam()
        {
            var split = new[] { ' ', ',', ':', '.', '!', '?', '—', '-', '"', '(', ')' };
            var words = Message
                .Split(split, StringSplitOptions.RemoveEmptyEntries)
                .Where(w => w.Any(c => !char.IsDigit(c)))
                .Distinct();
            double param = words.Count();
            return param;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Post p1 = new Post()
            {
                Author = "Pepega",
                Date = DateTime.Now,
                Message = "Domestic car sales slumped 50 per cent on an annual basis in 2020 to 532407 vehicles from 1.03 million vehicles in 2019, as the pandemic, according to Association of Indonesian Automotive Manufacturers (Gaikindo) data."
            };

            Post p2 = new Post()
            {
                Author = "Pepega",
                Date = DateTime.Now,
                Message = "Тестовая: строка со \"специальными\" - символами??!!"
            };

            Post p3 = new Post()
            {
                Author = "Pepega",
                Date = DateTime.Parse("Mar 17, 2009"),
                Message = "That is what I have always understood to be the essence of anarchism: the conviction that " +
                "the burden of proof has to be placed on authority, and that it should be dismantled if that burden cannot be met"
            };

            Console.WriteLine("Post 1: {0} \nPost 2: {1}\nPost 3: {2}", p1.CountRating(), p2.CountRating(), p3.CountRating());

        }
    }
}
