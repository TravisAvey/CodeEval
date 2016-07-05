using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    /// <summary>
    /// Simple class to hold the data and sort it
    /// </summary>
    public class SimpleSort
    {
        private static List<float> mList;

        /// <summary>
        /// Public constructor, pass in the string of data to
        /// be sorted
        /// </summary>
        public SimpleSort(string data)
        {
            ParseList(data);
        }

        /// <summary>
        /// parses the string and places into the private list member
        /// </summary>
        private void ParseList(string data)
        {
            mList = new List<float>(Array.ConvertAll(data.Split(' '), float.Parse));
        }

        /// <summary>
        /// Sorts the current instance of this object and return the sorted list
        /// </summary>
        public static List<float> Sort()
        {
            mList.Sort();
            var sorted = mList;
            return sorted;
        }
    }

    public static void Main (string[] args)
    {
        // for each line in the file
        foreach (var line in File.ReadLines(args[0]))
        {
            // create new SimpleSort object 
            var sort = new SimpleSort (line);
            // sort the list 
            var list = SimpleSort.Sort();
            // print out the list in required format
            foreach (var i in list)
                Console.Write ("{0:0.000} ", i);
            Console.WriteLine();
        }
    }
}
