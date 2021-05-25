using System;
using System.IO;

namespace Lab_10
{
    class Program
    {
        static void Main(string[] args)
        {
            bool success = true;
            try
            {
                var files = Directory.GetFiles(".", "??");
                for (int i = 0; i < files.Length; i++)
                {
                    try
                    {
                        var lines = File.ReadAllLines(files[i]);
                        var testing = new ClassForTesting();
                        var result = testing.CountEvenNumber(lines);
                        var correctResult = File.ReadAllText(files[i] + ".a");
                        var buf = correctResult.Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries);
                        if (buf.Length > 0)
                        {
                            int correctNumbers = int.Parse(buf[0]);
                            if (correctNumbers == result)
                            {
                                Console.WriteLine("Ok (test {0})", files[i]);
                            }
                            else
                            {
                                success = false;
                                Console.WriteLine("Different answer! (test {0}: {1}!={2}) ", files[i], result, correctNumbers);
                            }
                        }
                        else
                        {
                            success = false;
                            Console.WriteLine("Error on test {0}", files[i]);
                        }
                    }
                    catch (Exception)
                    {
                        success = false;
                        Console.WriteLine("Error on test {0}", files[i]);
                    }
                }
            }
            catch (Exception)
            {
                success = false;
                Console.WriteLine("Error");
            }
            if (success)
            {
                Console.WriteLine("Testing has been successfully completed");
            }
            else
            {
                Console.WriteLine("Testing with errors");
            }
        }
    }
}
