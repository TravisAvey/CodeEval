using System;
using System.IO;
using System.Text.RegularExpressions;
using System.Collections.Generic;

class Program
{
    /// <summary>
    /// Helper class to store the coordinates of the points
    /// </summary>
    public class Vector2
    {
        // (x, y)
        private int _x;
        private int _y;

        /// <summary>
        /// get or set the x point
        /// </summary>
        public int x
        {
            get { return _x; }
            set { _x = value;}
        }

        /// <summary>
        /// Get or set the y point
        /// </summary>
        public int y
        {
            get { return _y; }
            set { _y = value; }
        }
    }

    public class Distance
    {

        // private member variables:

        // point a
        private Vector2 a;
        // point b
        private Vector2 b;
        // list to hold the numbers
        private List<int> nums;
        // a dictionary of separators to split the string up
        private string[] sep = {",", "(", ")", " "};

        /// <summary>
        /// Default constructor.  Initializes the new object made
        /// </summary>
        public Distance()
        {
            nums = new List<int>();
            a = new Vector2();
            b = new Vector2();
        }

        /// <summary>
        /// Returns the distance between the two points set
        /// </summary>
        public int Calculate ()
        {
            // distance = square root (x2-x1)^2 + (y2-y1)^2
            double x = b.x - a.x;
            double y = b.y - a.y;
            double d = Math.Sqrt (x*x + y*y);
            return (int) d;
        }

        /// <summary>
        /// Helper method that parses the string and places the numbers
        /// into the list
        /// </summary>
        /// <param name="line">The string containing the points (x1, y1)(x2, y2)</param>
        private void Parse (string line)
        {
            // splits the string into an array
            string[] numbers = line.Split (sep, StringSplitOptions.RemoveEmptyEntries);
            // for each item in the array
            foreach (var data in numbers)
            {
                // parse the data to an int
                int n = int.Parse (data);
                // add the number to the list
                nums.Add (n);
            }
            // call private method to handle setting the coordinates
            SetCoords();
        }

        /// <summary>
        /// Private helper method sets the coordinates
        /// </summary>
        private void SetCoords ()
        {
            a.x = nums[0];
            a.y = nums[1];
            b.x = nums[2];
            b.y = nums[3];

            // once set, clear the list as it's not needed to contain
            // anything
            nums.Clear ();
        }

        /// <summary>
        /// Initializes the object to find the distance
        /// </summary>
        /// <param name="data">The string of data containing the points</param>
        public void Init (string data)
        {
            Parse (data);
        }
    }

    public static void Main (string[] args)
    {
        // create a new distance object
        var distance = new Distance();
        // foreach line in the file
        foreach (var line in File.ReadLines(args[0]))
        {
            // initialize the distance object
            distance.Init (line);
            // print to stdout the distance between the points
            Console.WriteLine (distance.Calculate () );
        }
    }
}
