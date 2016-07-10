using System;
using System.IO;
using System.Text.RegularExpressions;
class Program
{
    public class ParseJson
    {
        /// <summary>
        /// Finds the value after the string passed
        /// </summary>
        /// <param name="word">The word to parse the JSON for</param>
        /// <param name="json">The json in a string format</param>
        public int FindValue (string json, string word)
        {
            int val = 0;

            while (true)
            {
                // get the current location (at the end of) the word
                int found = json.IndexOf(word) + word.Length;
                
                if (found == 0) break;
                Console.WriteLine ("found: {0} json {1}", found, json.Length);
                // set the json to the new location.
                // the value should be " value ..."
                json = json.Substring (found);

                

                // val += int.Parse(a);
            }
            return val;
        }
    }

    public static void Main (string[] args)
    {
        var parse = new ParseJson();
        foreach (var line in File.ReadLines(args[0]))
        {
            if (line == "") continue;
            Console.WriteLine (parse.FindValue (line, "Label "));
        }
    }
}