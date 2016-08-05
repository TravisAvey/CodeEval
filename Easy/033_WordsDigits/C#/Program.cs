using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    class Digitize
    {
        // Dictionary to hold the words->numbers
        Dictionary<string, int> mNums;

        /// <summary>
        /// Public constructor, intializes the dictionary
        /// </summary>
        public Digitize ()
        {
            // init the dictionary
            mNums = new Dictionary<string, int> ();
            // set up the dictionary
            Init ();
        }

        /// <summary>
        /// Sets the dictionary for each word 1-9 to digits
        /// </summary>
        void Init ()
        {
            mNums["zero"] = 0;
            mNums["one"] = 1;
            mNums["two"] = 2;
            mNums["three"] = 3;
            mNums["four"] = 4;
            mNums["five"] = 5;
            mNums["six"] = 6;
            mNums["seven"] = 7;
            mNums["eight"] = 8;
            mNums["nine"] = 9;
        }

        /// <summary>
        /// Prints out the digits of the passed in string
        /// </summary>
        public void PrintDigits (string data)
        {
            // put the words into an array, split on the ;
            string[] words = data.Split(';');

            // for every word in the array, print out the corresponding digit
            foreach (var word in words)
                Console.Write (mNums[word]);
            
            Console.WriteLine ();
        }
    }

    public static void Main (string[] args)
    {
        // for every line in the file
        foreach (var line in File.ReadLines(args[0]))
        {
            // create a ne Digitize object
            var digits = new Digitize ();
            // call method to print out the digits
            digits.PrintDigits (line);
        }
    }
}
