using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    /// <summary>
    /// This method returns 1 if the number is happy
    /// :: sum of the square of digits is one after a while
    /// Returns 0 if it never gets to one
    /// </summary>
    private static int HappyNumber(int num)
    {
        // if value is 1, its happy already
        if (num == 1) return 1;

        // copy num over, init counter
        int n = num;
        int counter = 0;

        // 20 times is a lot, probably wont be happy if not within 20
        while (counter < 20)
        {
            // init a sum
            int sum = 0;
            // get a list of each digit in the number
            var digits = GetDigits (n);

            // for each digit, sum the square of the digits
            foreach (var i in digits)
                sum += i*i;
            
            // if the sum is 1, its a happy number
            if (sum == 1) return 1;

            // else set n to the current sum, increment counter
            n = sum;
            counter++;
        }
        return 0;

    }

    /// <summary>
    /// This method returns a list of the digits of the number
    /// </summary>
    private static List<int> GetDigits (int val)
    {
        // declare a List of integers
        var digits = new List<int>();

        // get each digit (val%10 gets the last, val/=10 removes that last)
        for (; val>0; val /= 10)
            digits.Add(val%10);
        
        // return it
        return digits;
    }

    public static void Main (string[] args)
    {
        
        foreach (var line in File.ReadLines(args[0]))
        {
            // parse the line to an int
            int num = int.Parse(line);
            // print out if a happy number (1) or not (0)
            Console.WriteLine(HappyNumber(num));
        }
    }
}