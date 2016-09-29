using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    /// <summary>
    /// This method prints the longest word in the array
    /// </summary>
    private static void LongestWord (string[] words)
    {
        // set longest and pos
        int longest = 0;
        int pos     = 0;

        // loop through words
        for (int i=0; i<words.Length; ++i)
        {
            // if the current word is the longest
            if (words[i].Length > longest)
            {
                // set the longest and the position of the longest
                longest = words[i].Length;
                pos = i;
            }
        }

        // printout the longest word
        Console.WriteLine (words[pos]);
    }

    public static void Main (string[] args)
    {
        // use a reader to open the file
        using (var reader = File.OpenText(args[0]))
        // while we haven't gotten to end of the file
        while (!reader.EndOfStream)
        {
            // read a line
            string line = reader.ReadLine ();
            // put that line into an array
            string[] words = line.Split (' ');
            // print the longest word in the line
            LongestWord (words);
        }
    }
}
