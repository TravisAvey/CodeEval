using System;
using System.IO;

class Program
{
    
    public static void Main (string[] args)
    {
        // init fileinfo object
        var file = new FileInfo(args[0]);
        // get the size in kb of the file
        var size = file.Length;
        // output the file 
        Console.WriteLine(size);
    }
}