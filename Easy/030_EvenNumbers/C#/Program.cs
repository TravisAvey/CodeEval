using System;
using System.IO;

class Program
{

    public static void Main (string[] args)
    {
        // for each line in the file
        foreach (var line in File.ReadLines(args[0]))
        {
            // parse line to an int
            int num = int.Parse(line);

            // if even print 1, else print 1
            if (num % 2 == 0)
                Console.WriteLine (1);
            else
                Console.WriteLine (0);
        }
    }
}
