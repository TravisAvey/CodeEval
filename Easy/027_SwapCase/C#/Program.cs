using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    public static class CaseSwap
    {
        /// <summary>
        /// This method will swap the case of each letter in the string
        /// </summary>
        /// <param name="word">The string to swap the letters case </param>
        public static string Swap(string word)
        {
            // init an empty string
            string sentence = "";
            // go through each letter
            for (var i=0; i<word.Length; ++i)
            {
                // check if letter is a letter or not
                if (!Char.IsLetter(word[i])) 
                {
                    // add the char to the string
                    sentence += word[i];
                    // continue to next char
                    continue;
                }

                // if we get here, char is a letter, so swap case
                if (Char.IsUpper(word[i]) == true)
                    sentence += Char.ToLower(word[i]);
                else if (Char.IsLower(word[i]))
                    sentence += Char.ToUpper(word[i]);
                
            }
            // finally return the swapped string
            return sentence;
        }
    }

    public static void Main (string[] args)
    {
        // for each line in the file, print out the case swapped string
        foreach (var line in File.ReadLines(args[0]))
            Console.WriteLine (CaseSwap.Swap (line));
    }
}
