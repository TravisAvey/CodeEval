using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    class RomanNumerals 
    {
        // private member variables
        int number;
        int digits;
        Dictionary<int, string> numDict;
        List<int> integers;

        // public constructor
        public RomanNumerals ()
        {
            // call method to init class
            Init ();
        }

        /// <summary>
        /// Converts the value to a Roman Numeral
        /// </summary>
        public void Convert (string val)
        {
            // store the val as an int
            number = int.Parse (val);
            // get the length of the val
            digits = val.Length;
            // parse the num
            ParseNum ();
        }

        /// <summary>
        /// This method will parse the number
        /// </summary>
        private void ParseNum ()
        {
            //Console.WriteLine ("{0}:", number);
            // init a variable to hold the digit
            int n = 0;
            // loop over the digits
            for (int i = 0; i < digits; ++i)
            {
                // pop off last digit
                n = number % 10;
                // shift number over to the right one
                number /= 10;
                // add the digit to the integers list
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
            
            
            // initialize the place
            int place = 0;
            while (digits >= 0)
            {
                // if we have 3 digits, this is the thousands place
                if (digits == 3)
                {
                    place = integers[digits--] * 1000;
                    // call a method that will print out appropriate Roman Numeral Value
                    PrintRomanNumeral (place);
                }
                // 2 digits = 100s place
                if (digits == 2)
                {
                    place = integers[digits--] * 100;
                    PrintRomanNumeral (place);
                }
                // 1 digit = 10s place
                if (digits == 1)
                {
                    place = integers[digits--] * 10;
                    PrintRomanNumeral (place);
                }
                // 0 digit = 1s place
                if (digits == 0)
                {
                    place = integers[digits--];
                    PrintRomanNumeral (place);
                }
            }
            Console.WriteLine ();
            
        }

        /// <summary>
        /// This method prints out the roman numeral of the int passed in
        /// </summary>
        private void PrintRomanNumeral (int n)
        {
            Console.Write(numDict[n]);
        }

        /// <summary>
        /// Private helper method that initializes the class
        /// </summary>
        private void Init ()
        {
            integers = new List<int> ();
            numDict = new Dictionary<int, string> ();

            // 1s
            numDict[0] = "";
            numDict[1] = "I";
            numDict[2] = "II";
            numDict[3] = "III";
            numDict[4] = "IV";
            numDict[5] = "V";
            numDict[6] = "VI";
            numDict[7] = "VII";
            numDict[8] = "VIII";
            numDict[9] = "IX";

            // 10s
            numDict[10] = "X";
            numDict[20] = "XX";
            numDict[30] = "XXX";
            numDict[40] = "XL";
            numDict[50] = "L";
            numDict[60] = "LX";
            numDict[70] = "LXX";
            numDict[80] = "LXXX";
            numDict[90] = "XC";

            // 100s
            numDict[100] = "C";
            numDict[200] = "CC";
            numDict[300] = "CCC";
            numDict[400] = "CD";
            numDict[500] = "D";
            numDict[600] = "DC";
            numDict[700] = "DCC";
            numDict[800] = "DCCC";
            numDict[900] = "CM";

            // 1000s
            numDict[1000] = "M";
            numDict[2000] = "MM";
            numDict[3000] = "MMM";
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