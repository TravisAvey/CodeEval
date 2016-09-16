using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    class RomanNumerals 
    {
        int number;
        string output;
        int digits;
        Dictionary<int, string> numDict;
        List<int> integers;

        public RomanNumerals ()
        {
            Init ();
        }

        public void Convert (string val)
        {
            number = int.Parse (val);
            digits = val.Length;
            ParseNum ();
        }

        private void ParseNum ()
        {
            int n = 0;
            for (int i = 0; i < digits; ++i)
            {
                n = number % 10;
                number /= 10;
                integers.Add (n);
            }

            // now each integer is in the List of integers
            // but it is in reverse order.
            

            // we know the numbers will be 1-3999..
            // so the max number of digits will be 4

            // We have the number of digits (digits (int))
            // if digits is 4, then the last digit in the list is the 1000s place
            // then we decrement digits and get the next to last digit, which would be 100s place
            // decrement again and get the 10s place
            // finally decrement and get the 1s place.. 

            // decrement digits for a 0 based List
            digits--;

            // while digits isn't out of range for the List
            while (digits >= 0)
            {
                // initialize the place
                int place = 0;
                // if we have 3 digits, this is the thousands place
                if (digits == 3)
                {
                    place = integers[digits--] * 1000;
                    Console.WriteLine (place);
                }
                if (digits == 2)
                {
                    place = integers[digits--] * 100;
                    Console.WriteLine (place);
                }
                if (digits == 1)
                {
                    place = integers[digits--] * 10;
                    Console.WriteLine (place);
                }
                if (digits == 0)
                {
                    place = integers[digits--];
                    Console.WriteLine (place);
                }
                Console.WriteLine ();
            }
        }

        private void Init ()
        {
            integers = new List<int> ();
            numDict = new Dictionary<int, string> ();
            numDict[1] = "I";
            numDict[2] = "II";
            numDict[3] = "III";
            numDict[4] = "IV";
            numDict[5] = "V";
            // 6 = 5 + 1
            // 7 = 5 + 2
            // 8 = 5 + 3
            numDict[9] = "IX";
            numDict[10] = "X";
            // 11 - 19 = 10 + 1..2..3..
            numDict[40] = "XL";
            numDict[50] = "L";
            numDict[90] = "XC";
            numDict[100] = "C";
            numDict[500] = "D";
            numDict[900] = "CM";
            numDict[1000] = "M";
        }
        
        
    }

    public static void Main (string[] args)
    {
       
        foreach (var line in File.ReadLines(args[0]))
        {
            var romanNumerals = new RomanNumerals ();
            romanNumerals.Convert (line);
        }
    }
}