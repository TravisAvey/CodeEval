using System;
using System.IO;
using System.Collections.Generic;

class reverse
{
    ///<summary>
    /// This method takes the array of words and prints the reverse
    ///</summary>
    private static void PrintReverse(string[] words)
    {
        // start at the end; loop to first element of words
        for (int i=words.Length-1; i>=0; --i)
        {    
            // output the word
            Console.Write(words[i]);
            // if we aren't at the end add a space (no space at end!)
            if (i != 0)
                Console.Write(' ');
        }
        // write a new line
        Console.WriteLine();
    }

    public static void Main (string[] args)
    {
        // loop through each line from reading all lines from the file and call PrintReverse
        foreach (string line in File.ReadLines(args[0]))
            PrintReverse(line.Split(' '));
    }
}
