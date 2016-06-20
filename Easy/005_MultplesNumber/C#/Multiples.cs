using System;
using System.IO;
using System.Linq;

class Multiples
{
    ///<summary>
    /// This method will print out the lowest multiple of y that is greater than or equal to x
    ///</summary>
    private static void LowestMultiple(int x, int y)
    {
        // x is hurdle, y is the power of 2 (POT)

        // checking all numbers from 1 to x
        for (int i=1; i<=x; ++i)
        {
            // get the multiple of current i * y
            int multiple = i * y;
            
            // if it is greater than or equal to x, we have the lowest mulitple of y
            if (multiple >= x)
            {
                // print it out, and break out of loop
                Console.WriteLine(multiple);
                break;
            }
        }
    }

    public static void Main(string[] args)
    {
        // foreach string in the IEnumarable<string> from ReadLines
        foreach (string line in File.ReadLines(args[0]))
         {
            // get the numbers. split on ',', Select(Linq method) lambda to parse, and convert to array
            int[] nums = line.Split(',').Select(s => int.Parse(s)).ToArray();
            
            // call method to get lowest mulitples
            LowestMultiple(nums[0], nums[1]);
         }
    }
}
