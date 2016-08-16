using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    class RomanNumerals 
    {
        string number;
        string output;
        int digits;
        Dictionary<int, string> numDict;

        public RomanNumerals ()
        {
            Init ();
        }

        public string Convert (string val)
        {
            number = val;
            digits = val.Length;
            ParseNum ();
            return number;
        }

        private void ParseNum ()
        {
            for (int n=0; n<digits; ++n)
            {
                

                Console.WriteLine (number[n]);
            }
        }

        private void Init ()
        {
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
            numDict[1000] = "M";
        }
        
        
    }

    public static void Main (string[] args)
    {
        var romanNumerals = new RomanNumerals ();
        foreach (var line in File.ReadLines(args[0]))
        {
            romanNumerals.Convert (line);
        }
    }
}