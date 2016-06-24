using System;
using System.Collections.Generic;
using System.IO;

/*
    This program determines if a number is an Armstrong number or not

    An armstrong number is the sum of the nth power of its digits, i.e:

    6 : 6^1 = 6 
    1634 : 1^4 + 6^4 + 3^4 + 4^4 = 1634
*/
class Program
{
    /// <summary>
    /// This method returns a list of the digits in a number
    /// </summary>
    private static List<int> GetDigits(int num)
    {
        var digits = new List<int>();
        // copy number to n
        var n = num;
        // looping through each digit (n/=10 pops of last digit of the number)
        for (; n>0; n/=10)
            // add the last digit of the number
            digits.Add(n%10);
        // return the list
        return digits;
    }

    /// <summary>
    /// This method prints out True if the number is an armstrong or False if not
    /// </summary>
    private static void ArmstrongNumber(int num)
    {
        // get the digits 
        var digits = GetDigits(num);

        // init a sum
        int sum = 0;
        // loop through each digit, summing the digit^numDigits
        for (int i=0; i<digits.Count; ++i)
            sum += (int)Math.Pow(digits[i], digits.Count);
        
        // if sum is num, armstrong number
        if (sum == num)
            Console.WriteLine("True");
        else
            Console.WriteLine("False");
    }

    public static void Main (string[] args)
    {
        // for every line in the file
        foreach (var line in File.ReadLines(args[0]))
        {
            // parse the line to an int
            int val = int.Parse(line);
            // call method to check if armstrong or not
            ArmstrongNumber(val);
        }
    }
}