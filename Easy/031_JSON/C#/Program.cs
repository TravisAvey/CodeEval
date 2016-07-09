using System;
using System.IO;

class Program
{

    public static void Main (string[] args)
    {
        foreach (var line in File.ReadLines(args[0]))
        {
            if (line == "") continue;
            System.Console.WriteLine(line);
        }
    }
}