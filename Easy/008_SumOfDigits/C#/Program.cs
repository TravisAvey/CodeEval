using System;
using System.IO;
using System.Linq;

class Program
{
    class SumDigits
    {
        private int mLength;

        /// <summary>
        /// Returns the sum of the number passed
        /// </summary>
        public int Sum(int num)
        {
            return GetSum(num);
        }

        /// <summary>
        /// setter for the length of the int
        /// </summary>
        public int Length
        {
            set { mLength = value; }
        }

        /// <summary>
        /// Private method that calculates the sum of the number 
        /// </summary>
        private int GetSum(int num)
        {
            // two variables to hold the answer and each digit (n)
            int ans = 0;
            int n = 0;

            // loop through each digit
            for (int i=1; i<=mLength; ++i)
            {
                // get the digit on the right
                n = num % 10;
                // remove last digit 
                num /= 10;
                // sum digit to the answer
                ans += n;
            }
            // return the answer
            return ans;
        }
    }


    public static void Main (string[] args)
    {
        // init a SumDigits object
        SumDigits sumDigits = new SumDigits();

        // for each line in the file
        foreach (string line in File.ReadLines(args[0]))
        {
            // convert the current line to an integer
            int num = int.Parse(line);
            // set the number of digits
            sumDigits.Length = line.Length;
            // print out the sum of the digits
            Console.WriteLine(sumDigits.Sum(num));
        }
    }
}
