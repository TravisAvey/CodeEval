using System;
using System.IO;
using System.Collections.Generic;

class Program
{

    class LowestUnique
    {
        // private data structures

        // input numbers
        List<int> userInput;
        // holds the count for each number
        Dictionary<int, int> nums;

        /// <summary>
        /// Constructor, pass in string of numbers
        /// </summary>
        public LowestUnique (string data)
        {
            // init the dictionary
            nums = new Dictionary <int, int> ();
            // init the data
            Init (data);
        }

        /// <summary>
        /// Returns the lowest unique number in the data set, 0 if none are unique
        /// </summary>
        public int GetLowest ()
        {
            // init a variable to hold the lowest
            var lowest = 0;

            // loop through the dictionary
            for (int i=1; i<=9; ++i)
            {
                // first number with a count of 1 is the lowest unique
                if (nums[i] == 1)
                {
                    // set the lowest to the number (1-9)
                    lowest = i;
                    // break out of this loop!
                    break;
                }
            }

            // if lowest is 0, we didnt find a lowest unique number, return 0
            if (lowest == 0)
                return 0;
            else
            {
                // init an index
                int index = 0;
                // loop through the input numbers
                foreach (var i in userInput)
                {
                    // increment first, because answer is not 0 based
                    index++;
                    // if current number is the lowest unique, return that index
                    if (i == lowest)
                        return index;
                }
            }
            // return 0 here just in case
            return 0;
        }

        // Initializes data passed to constructor
        void Init (string data)
        {
            // set the dictionary, each number with a count of 0
            for (int i=1; i<=9; ++i)
                nums[i] = 0;
            
            // parse the string to the list
            userInput = new List<int> (Array.ConvertAll (data.Split (' '), int.Parse));

            // loop over user input, and increment the dictionary counts where applicable
            foreach (var i in userInput)
            {
                // get the count of current number
                int counter = nums[i];
                // increment that count for current number
                nums[i] = ++counter;
            }

        }

        
    }

    public static void Main (string[] args)
    {
        // for every line in the file
        foreach (var line in File.ReadLines (args[0]))
        {
            // create a new LowestUnique object, passing the line in
            var lowest = new LowestUnique (line);
            // write to stdout the lowest unique number
            Console.WriteLine (lowest.GetLowest () );
        }
    }
}
