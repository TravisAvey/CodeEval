using System;
using System.IO;
using System.Linq;

class Multiples
{
    private static void LowestMultiple(int x, int y)
    {
        // x is hurdle, y is the power of 2 (POT)
        for (int i=1; i<=x; ++i)
        {
            int multiple = i * y;

            if (multiple >= x)
            {
                Console.WriteLine(multiple);
                break;
            }
        }
    }

    public static void Main(string[] args)
    {
        foreach (string line in File.ReadLines(args[0]))
         {
            int[] nums = line.Split(',').Select(s => int.Parse(s)).ToArray();
            
            LowestMultiple(nums[0], nums[1]);
         }
    }
}
