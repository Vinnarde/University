using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class TargetClass
{
    public int[] ParseStrings(string[] lines)
    {
        int[] result = new int[lines.Length];

        for (int i = 0; i < lines.Length; i++)
        {
            if (int.TryParse(lines[i], out int num))
            {
                result[i] = num;
            }
        }

        Array.Sort(result);

        int even = CountEven(result);

        if ((result.Length - even) <= even)
            Array.Reverse(result);

        return result;
    }

    private int CountEven(int[] numbers)
    {
        int count = 0;
        foreach (int n in numbers)
            if (n % 2 == 0)
                count++;
        return count;
    }


}
