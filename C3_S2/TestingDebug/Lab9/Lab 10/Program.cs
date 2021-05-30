using System;
using System.Linq;
using System.IO;

class Program
{

    static void Main(string[] args)
    {
        bool success = true;
        try
        {
            Directory.SetCurrentDirectory(@"..\..\..\..\Tests");
            var files = Directory.GetFiles(".", "??");
            for (int i = 0; i < files.Length; i++)
            {
                try
                {
                    string[] lines = File.ReadAllLines(files[i]);

                    TargetClass testing = new();
                    int[] actual = testing.ParseStrings(lines);

                    string[] expectedLines = File.ReadAllLines(files[i] + ".a");
                    int[] expected = LinesToNumbers(expectedLines);

                    if (expected.Length != actual.Length)
                    {
                        Console.WriteLine($"Error on test {files[i]}, Expected sequence length={expected.Length}, actual={actual.Length}");
                        success = false;
                    }
                    else if (expected.SequenceEqual(actual))
                    {
                        Console.WriteLine("Ok (test {0})", files[i]);
                    }
                    else
                    {
                        // find the difference between sequences
                        int j = 0;
                        while (j < actual.Length && expected[j] == actual[j])
                        {
                            j++;
                        }

                        success = false;
                        Console.WriteLine($"Different elements! (test {files[i]}: i={j}: {actual[j]} (actual) != {expected[j]})");
                    }
                }
                catch (Exception)
                {
                    success = false;
                    Console.WriteLine("Error on test {0}", files[i]);
                }
            }
        }
        catch (Exception e)
        {
            success = false;
            Console.WriteLine("Exception: " + e.Message);
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

    static public int[] LinesToNumbers(string[] lines)
    {
        int[] result = new int[lines.Length];

        for (int i = 0; i < lines.Length; i++)
        {
            if (int.TryParse(lines[i], out int num))
            {
                result[i] = num;
            }
        }

        return result;
    }

}
