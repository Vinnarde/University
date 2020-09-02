using System;

namespace Lab
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 0)

                Console.WriteLine("Args is empty!");
            else
                Console.WriteLine("Hello, " + args[0]);
        }
    }
}
