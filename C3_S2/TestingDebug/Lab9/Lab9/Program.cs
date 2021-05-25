
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace Labs9
{
    class Program
    {
        static Random random = new Random();
        private static List<int> answer = new List<int>();
        static UInt64 totalEven = 0ul;
        static UInt64 totalOdd = 0ul;


        static void Main(string[] args)
        {
            for (int testNumber = 0; testNumber < 20; testNumber++)
            {
                GenerateTest(testNumber + 1);
            }
        }

        static void GenerateTest(int testNumber)
        {
            string inputFilename = testNumber.ToString("00") + ".txt";
            string outputFilename = testNumber.ToString("00") + "a.txt";
            string helperFilename = testNumber.ToString("00") + "h.txt";
            //int totalAnswer = 0;

            int linesNumber = random.Next(20, 30); //колв-во строк от 20 до 30
            string[] stringBuilder = new string[linesNumber];
            for (int j = 0; j < linesNumber; j++)
            {
                int answerForLine = random.Next(1, 1000); //кол-во четных от 1 до 1000
                totalEven += (ulong)answerForLine;
                stringBuilder[j] = GenerateLine(answerForLine, random.Next(3000));
            }

            if (totalOdd >= totalEven)
            {
                var newList = answer.OrderBy(x => x).ToList();
                File.WriteAllLines(outputFilename, newList.Select(d => d.ToString()));
            }
            else
            {
                var newList = answer.OrderByDescending(x => x).ToList();
                File.WriteAllLines(outputFilename, newList.Select(d => d.ToString()));
            }

            File.WriteAllLines(inputFilename, stringBuilder);
            File.WriteAllText(helperFilename,
                "Even: " + totalEven.ToString() + "\r\n" + "Odd: " + totalOdd.ToString()
                + Environment.NewLine + Environment.NewLine);
            //File.WriteAllLines(outputFilename, answer);
        }

        static string GenerateLine(int evenNumbers, int additionalNumber = 1)
        {
            int count = evenNumbers + additionalNumber;
            string[] numbers = new string[count];
            int i;
            for (i = 0; i < evenNumbers; i++)
            {
                numbers[i] = (random.Next(int.MinValue >> 1, int.MaxValue >> 1) * 2).ToString(CultureInfo.InvariantCulture);

                answer.Add(Convert.ToInt32(numbers[i]));
            }
            for (i = 0; i < additionalNumber; i++)
            {
                double chislo;
                int ost = i % 3;
                if (ost == 0) //случайное не четное вещественное число
                {
                    chislo = random.NextDouble() * (int.MaxValue - 1);
                    if (Math.Abs(Math.Truncate(chislo) - chislo) < 0.0001) chislo += 0.1;
                    numbers[i + evenNumbers] = chislo.ToString("0.#####", CultureInfo.InvariantCulture) + "3";


                    // Если считать вещественные как не четные(что как бы неправильно, ибо это хар-ка целых цисел)
                    //totalOdd++;
                    //answer.Add(numbers[i + evenNumbers]);
                }
                if (ost == 1) //случайное целое не четное число
                {
                    chislo = random.Next((int.MinValue + 10) >> 1, (int.MaxValue - 10) >> 1) * 2 - 1;
                    numbers[i + evenNumbers] = chislo.ToString(CultureInfo.InvariantCulture);

                    totalOdd++;
                    answer.Add(Convert.ToInt32(numbers[i + evenNumbers]));
                }
                if (ost == 2) //случайное целое число с буквами внутри (т.е. не число)
                {
                    chislo = random.Next((int.MinValue + 10) >> 1, (int.MaxValue - 10) >> 1) * 2;
                    char letter = (char)('a' + random.Next(26));
                    if (letter == 'e') letter = 'b';
                    string cc = chislo.ToString(CultureInfo.InvariantCulture);
                    numbers[i + evenNumbers] = cc.Insert(cc.Length - 1, "" + letter);
                }
            }

            //Перемешаем
            for (i = 0; i < count; i++)
            {
                int n = random.Next(count);
                string buf = numbers[i];
                numbers[i] = numbers[n];
                numbers[n] = buf;
            }

            string result = "";
            for (i = 0; i < count; i++)
            {
                result += numbers[i] + GenerateDelimeter(random.Next(4) + 2);
            }
            return result;
        }

        static string GenerateDelimeter(int len = 3)
        {
            string r = "";
            string symbols = ",.!@#$%^&*()=;";
            for (int i = 0; i < len; i++)
            {
                r += symbols[random.Next(symbols.Length)];
            }
            return " " + r + " ";
        }
    }
}