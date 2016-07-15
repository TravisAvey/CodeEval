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
            // init a value for the label
            int val = 0;

            // keep looping till we break it
            while (true)
            {
                // get the current location (at the end of) the word
                int found = json.IndexOf(word);
                //System.Console.WriteLine("found: {0}", found);
                if (found == -1 || found > json.Length) break;
               
                
                // set the json to the new location.
                // the value should be " value ..."
                string rest = json.Substring (found + word.Length);
                
                // find the next number after the word
                string result = Regex.Match (rest, @"\d+").Value;
                
                // try to parse the number (just to be sure we are getting the number out)
                int num;
                bool isNum = Int32.TryParse (result, out num);
                
                // set the json string to the substring (found -> end of string)
                json = rest;

                // if we parsed a number, add to val.. else continue to next loop
                if (isNum)
                    val += num;
                else
                    continue;

            }
            // finally return the value
            return val;
        }
    }

    public static void Main (string[] args)
    {
        // create a new parseJSON object
        var parse = new ParseJson();

        // for each line in the file
        foreach (var line in File.ReadLines(args[0]))
        {
            // if line is empty, continue to next line
            if (line == "") continue;
            // print the value found after the word label
            Console.WriteLine (parse.FindValue (line, "Label "));
        }
    }
}
