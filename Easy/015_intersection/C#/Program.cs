using System;
using System.IO;
using System.Linq;

class Program
{
    private static void Split(string line, int[] a, int[] b)
    {
        string[] data = line.Split(';').ToArray();
        a = data[0].Split(',').Select(i => int.Parse(i)).ToArray();
        b = data[1].Split(',').Select(i => int.Parse(i)).ToArray();
    }
    
    public static void Main (string[] args)
    {
        foreach (string line in File.ReadLines(args[0]))
        {
            int[] a;
            int[] b;
            Split(line, a, b);
        }
    }
}