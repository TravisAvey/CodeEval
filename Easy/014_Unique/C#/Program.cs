using System;
using System.IO;
using System.Linq;

class Program
{
    /// <summary>
    /// This method prints out the unique members of an array
    /// a,a,b,b,c ::
    /// a,b,c
    /// </summary>
    public static void PrintUnique(int[] nums)
    {
        // Linq method Distinct gets the distinct members
        int[] unique = nums.Distinct().ToArray();
        
        // loop through every element
        for (int i=0; i<unique.Length; ++i)
        {
            // write the current element
            Console.Write(unique[i]);
            
            // if we aren't at the last, write a ','
            if (i != unique.Length-1)
                Console.Write(',');
        }
        // make a new line
        Console.WriteLine();
    }
    
    public static void Main(string[] args)
    {
        // for each line in the file
        foreach (var line in File.ReadLines(args[0]))
        {
            // parse the line and put into an array
            int[] nums = line.Split(',').Select(i => int.Parse(i)).ToArray();
            // call method to print the unique values of the current line
            PrintUnique(nums);
        }
    }
}