using System;
using System.IO;

class Program
{
    /// <summary>
    /// This method prints out the position of the right most char in the string
    /// </summary>
    public static void RightMost(string line)
    {
        // get the last char in the line
        char ch = line[line.Length - 1];
        // initially set pos to -1
        int pos = -1;

        // loop through the string
        for (int i=0; i<line.Length-2; ++i)
        {
            // if the current char is the char, set pos to i
            if (line[i] == ch)
                pos = i;
        }
        // print out the pos (-1 if not found)
        Console.WriteLine(pos);
    }

    public static void Main (string[] args)
    {
        // for each line in the file, Get right most char position
        foreach (var line in File.ReadLines(args[0]))
            RightMost(line);
    }
}