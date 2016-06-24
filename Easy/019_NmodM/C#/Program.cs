using System;
using System.IO;
using System.Linq;

class Program
{   
    /// <summary>
    /// This method calculates the modulus of 
    /// two numbers passed to function
    /// 
    /// n mod m
    /// 1) n / m = x
    /// 2) x * m = y
    /// 3) n - y = modulus
    /// </summary>
    private static int Modulus(int n, int m)
    {
        // calculate and return n % m
        int x = n / m;
        int y = x * m;
        return n - y;
    }

    public static void Main (string[] args)
    {
        // get each line from the File
        foreach (var line in File.ReadLines(args[0]))
        {
            // create an array of ints, split from the line on ',' and parse to int
            int[] nums = line.Split(',').Select(i => int.Parse(i)).ToArray();
            // write to stdout the modulus of the two numbers from the line
            Console.WriteLine(Modulus(nums[0], nums[1]));
        }
    }
}
