using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    public class FindWriter
    {
        private string mLetters;
        private List<int> mIndices;

        /// <summary>
        /// Initialize the Find Writer with a string to decode
        /// </summary>
        /// <param name="code">The unciphered code</param>
        public void Init (string code)
        {
            // split the string letters | numbers
            string[] data = Array.ConvertAll(code.Split('|'), e => e.ToString());
            // first half is the letter to get the code from
            mLetters = data[0];
            
            // Call method to Parse the data (first char is a ' ', so only pass on [1]->[last])
            Parse (data[1].Substring(1));
        }

        /// <summary>
        /// Returns the Decoded string that should be a writer + birthdate
        /// </summary>
        public string GetWriter()
        {
            // init an empty string
            string writer = "";
            // for each index, append that to the string
            foreach (var i in mIndices)
                writer += mLetters[i-1];
            // return writer with birthdate
            return writer;
        }

        /// <summary>
        /// Parses the string of numbers to a List
        /// </summary>
        /// <param name="nums">The numbers to decode the string</param>
        private void Parse (string nums)
        {
            // convert string of nums to list
            mIndices = new List<int>(Array.ConvertAll (nums.Split(' '), int.Parse));
        }
    }

    public static void Main (string[] args)
    {
        // init a new FindWriter object
        var findWriter = new FindWriter();

        // for each line in the file
        foreach (var line in File.ReadLines(args[0]))
        {   
            // if the line is blank continue (the data is line, then empty line)
            if (line == "") continue;

            // initialize the findWriter object with the line
            findWriter.Init (line); 
            // write out to stdout the writer and birthdate
            Console.WriteLine (findWriter.GetWriter());   
        }
    }
}
