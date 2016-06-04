using System;
using System.Collections.Generic;

class FizzBuzz
{
    ///<summary>
    /// This method prints off numbers 1 through the max
    /// it will print a F if its divisible by the fizz
    /// a B if divisible by the buzz param, or FB if divisible
    /// by both fizz and buzz
    ///</summary>
    static void PrintFizzBuzz(int fizz, int buzz, int max)
    {
        // loop from 1 to max
        for (int i=1; i<=max; ++i)
        {
            // if divisible by fizz and buzz, print fb
            if (i % fizz == 0 && i % buzz == 0)
                Console.Write("FB");
            // if divisible by fizz, print F
            else if (i % fizz == 0)
                Console.Write("F");
            // if divizible by buzz print B
            else if (i % buzz == 0)
                Console.Write("B");
            // else just print the number
            else
                Console.Write(i);
            // write a space after each
            Console.Write(" ");
        }  
        // write new line
        Console.WriteLine();  
    }
    
    static void Main(string[] args)
    {
       // open file
       var file = new System.IO.StreamReader(args[0]);
       
       int fizz, buzz, max;
       string line;
        // while we can get a line
        while ((line = file.ReadLine()) != null)
        {
            // split line into an array, parse to int
            List<int> data = new List<int>(Array.ConvertAll(line.Split(' '), int.Parse));
            // extract the data needed
            fizz = data[0];
            buzz = data[1];
            max = data[2];
            // print out the fizz buzz
            PrintFizzBuzz(fizz, buzz, max);
            
        }

       file.Close();
    }
}
