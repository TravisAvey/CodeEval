using System;
using System.IO;

class Program
{
    /// <summary>
    /// This method takes input string and outputs the value of
    /// the beautufil value of the string
    /// </summary>
    private static void BeautifulStrings(string line)
    {
        // an int array, holds value for each char in string
        int[] chars = new int[26];
        // get the lower case version of the string
        line = line.ToLower();
        
        // loop through each char in the string
        foreach (char ch in line)
        {
            // if current char isn't a-z, continue
            if (ch < 'a' || ch > 'z')
                continue;
            
            // increment current letter value, if two a's in string 2 for the a position
            chars[ch-'a']++;
        }

        // sort the array of char values
        Array.Sort(chars);

        // init beautiful value
        int beautiful = 0;
        // this value is for the multiple (most chars get multiplied by 26, second most by 25, etc)
        int n = 26;

        for (int i=25; i>=0; --i)
            // add current char # times current n value (then decrement n)
            beautiful += chars[i]*n--;

        // write out the beautiful string value
        Console.WriteLine(beautiful);
    }

    public static void Main (string[] args)
    {
        // for each line in the file, output the beautiful string value
        foreach (var line in File.ReadLines(args[0]))
            BeautifulStrings(line);
        
    }
}