using System;
using System.IO;

class Program
{
    /// <summary>
    /// Returns 1 if number is self descrbing, 0 if no
    /// </summary>
    private static int SelfDescribing(string num)
    {
        // get the length of the string
        int len = num.Length;
        
        // loop through the string
        for (int i=0; i<len; ++i)
        {
            // init a counter
            int count = 0;
            // get current char
            char ch = num[i];

            // loop through string getting number of that char
            for (int j=0; j<len; ++j)
                if (i == ((int)num[j]-48))
                    count++;
            
            // if the count doesn't match the position, not self describing
            if (count != ((int)ch-48)) return 0;
        }
        // if we made it here, it is self describing
        return 1;
    }

    public static void Main (string[] args)
    {
        // for each line in the fail, print out if SelfDescribing or not
        foreach (var line in File.ReadLines(args[0]))
            Console.WriteLine(SelfDescribing(line));
        
    }
}