using System;
using System.IO;

namespace Labs9
{
    static class RandomExtensions
    {
        public static void Shuffle<T>(this Random rng, T[] array)
        {
            int n = array.Length;
            while (n > 1)
            {
                int k = rng.Next(n--);
                T temp = array[n];
                array[n] = array[k];
                array[k] = temp;
            }
        }
    }
    class Program
    {
        static Random Random = new Random();

        const int TotalTests = 30;
        const int TestCapacity = 20000;

        static void Main(string[] args)
        {
            Directory.SetCurrentDirectory(@"..\..\..\..\Tests");
            Console.WriteLine("Generating tests...");

            for (int i = 1; i <= TotalTests; i++)
            {
                GenerateTest(TestCapacity, i);
            }
        }

        static void GenerateTest(int count, int testNumber)
        {
            // deside what numbers (odd or even) will predominate
            int oddCount = Random.Next(count);
            int evenCount = count - oddCount;

            int[] result = new int[count];

            for (int i = 0; i < oddCount; i++)
            {
                result[i] = RandomOdd();
            }

            for (int i = oddCount; i < count; i++)
            {
                result[i] = RandomEven();
            }

            // sort result
            Array.Sort(result);

            if (oddCount < evenCount)
            {
                Array.Reverse(result);
            }

            // Write result
            WriteIntArray(testNumber + ".a", result);

            Random.Shuffle(result);

            // Write test set
            WriteIntArray(testNumber.ToString(), result);

            Console.WriteLine(@"Test #{0} ready!", testNumber);
        }

        static void WriteIntArray(string filename, int[] data)
        {
            string buffer = "";

            foreach (int number in data)
            {
                buffer += number + "\n";
            }

            File.WriteAllText(filename, buffer);
        }

        static int RandomOdd()
        {
            int n = Random.Next(1000000);
            if (n % 2 == 0)
            {
                n += 1;
            }

            return n;
        }
        static int RandomEven()
        {
            int n = Random.Next(1000000);
            if (n % 2 == 1)
            {
                n += 1;
            }

            return n;
        }
    }
}