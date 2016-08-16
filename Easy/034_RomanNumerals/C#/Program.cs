using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    class RomanNumerals 
    {
        string number
        string output;
        Dictionary<int, string> numDict;

        public RomanNumerals ()
        {
            Init ();
        }

        public void Convert (string val)
        {
            
        }

        private void ParseNum ()
        {

        }

        private void Init ()
        {
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
        foreach (var line in File.ReadLines(args[0]))
        {
            Console.WriteLine (line);
        }
    }
}