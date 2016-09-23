using System;
using System.IO;

class Program
{
    /// <summary>
    /// This method returns the count of the shortest cycle
    /// in the string
    /// </summary>
    private static int GetCycleCount (string line)
    {
        // init a count
        int count = 0;

        // loop through each char in the string
        for (int i=1; i<line.Length; ++i)
        {
            // if we get a match with first char and char i
            if (line[0] == line[i])
            {
                // set the count to i
                count = i;
                // break
                break;
            }
        }
        // if count is 0 return length, else return the count we found
        return (count == 0) ? line.Length : count;
    }

    public static void Main (string[] args)
    {
        // for each line in the file read
        foreach (var line in File.ReadLines(args[0]))
            // write out the Cycle count of the data
            Console.WriteLine (GetCycleCount (line));
    }
}
