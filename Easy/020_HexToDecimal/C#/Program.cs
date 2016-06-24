using System;
using System.IO;

class Program
{

    public static void Main (string[] args)
    {
        // for each line convert hex to int..
        foreach (var line in File.ReadLines(args[0]))
            Console.WriteLine(int.Parse(line, System.Globalization.NumberStyles.HexNumber));
        
        /*
            System.Globalization.NumberStyles.HexNumber is an enumeration that is a flag attribute
            and allows int.Parse() to convert the passed in string (hex) to an int
            see more at:
            https://msdn.microsoft.com/en-us/library/system.globalization.numberstyles(v=vs.110).aspx
        */
    }
}
