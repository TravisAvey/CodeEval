using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

// Only got 60/65 on this one.. a lot of memory, try looking at IList or IEnumerable for lest memory
class Program
{
    /// <summary>
    /// Prints out the N longest strings, where N is the first in the list
    /// </summary>
    private static void Longest (List<string> data)
    {
        // snag the N
        int n = int.Parse (data[0]);

        // Sort the data (this was faster than Linq, but more memory)
        data.Sort ((x,y) => x.Length - y.Length);

        // get the number of items in the list
        int i = data.Count;
        // count down and print out the N number of longest strings
        while (n > 0)
        {
            i--;
            n--;
            Console.WriteLine (data[i]);
        }
        
    }

    public static void Main (string[] args)
    {
        // create a list to hold the lines
        List<string> lines = new List<string> ();

        // for each line in the file, add to the list
        foreach (var line in File.ReadLines (args[0]))
            lines.Add (line);

        // call method to print out the longest
        Longest (lines);
    }
}
