using System;
using System.Collections.Generic;
using System.IO;

namespace Labs10ClassLibrary
{
    public class ClassForTesting
    {

        public bool IsSorted(List<int> list)
        {

        }

        public int CountEvenNumber(List<int> numbers)
        {
            int countEven = 0;
            int countOdd = 0;
            foreach (var e in numbers)
            {
                if (IsEven(e))
            }
            return count;
        }

        private int CountEvenNumber(string line)
        {
            int count = 0;
            var items = line.Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries);
            foreach (var item in items)
            {
                if (IsEven(item)) count++;
            }
            return count;
        }

        private bool IsEven(int item)
        {
            if ((item & 1) == 0)
                {
                    return true;
                }
            }
            return false;
        }
    }
}