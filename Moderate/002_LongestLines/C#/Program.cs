using System;
using System.IO;
using System.Collections.Generic;

class Program
{

    public static void Main (string[] args)
    {
        List<string> lines = new List<string> ();

        foreach (var line in File.ReadLines (args[0]))
            lines.Add (line);

        int n = int.Parse (lines[0]);

        
        
    }
}