using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class BitPosition
{

    ///<summary>
    /// This method checks the bit positions of a and b on the number passed
    /// if they are they same, prints true, else prints false
    ///</summary>
    private static void BitPositions(int num, int a, int b)
    {
        if (CompareBits(num, a, b))
            Console.WriteLine("true");
        else
            Console.WriteLine("false");
    }

    ///<summary>
    /// This method compares the bits of the value passed in
    /// returns true if they are, false if not
    ///</summary>
    private static bool CompareBits(int val, int a, int b)
    {
        // convert the value to a string in binary
        string bits = Convert(val);

        // check if a position is the same as b position
        if (bits[a] == bits[b])
            return true;
        else
            return false;
    }

    ///<summary>
    /// This method converts the value to a bit string
    ///</summary>
    private static string Convert(int val)
    {
        // declare a new char array of 32
        char[] b = new char[32];
        // basic index counters
        int pos = 0;
        int i = 0;

        while (i < 32)
        {
            // check if the value bitwise AND (1 shift right on i) is not 0
            if ((val & (1 << i)) != 0)
                b[pos] = '1';
            else
                b[pos] = '0';
            
            // inc and dec accordingly
            pos++;
            i++;
        }
        // return the array as a string
        return new string(b);
    }

    public static void Main (string[] args)
    {
        // for each line in the file
        foreach (string line in File.ReadLines(args[0]))
        {
            // convert the line into an array of ints
            int[] nums = line.Split(',').Select(i => int.Parse(i)).ToArray();
            int val = nums[0];
            // bit positions are 1 based, we need 0 based
            int a = nums[1] - 1;
            int b = nums[2] - 1;
            // call method to check the BitPositions
            BitPositions(val, a, b);
        }
    }
}
