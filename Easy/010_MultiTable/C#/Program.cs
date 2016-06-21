using System;

class Program
{
    /// <summary>
    /// prints out the 12 x 12 multiplication table
    /// </summary>
    public static void PrintTable()
    {
        // only way is a double loop
        for (int i=1; i<=12; ++i)
        {
            for (int j=1; j<=12; ++j)
                Console.Write("{0,4}", i*j);
            Console.WriteLine();
        }
    }

    public static void Main (string[] args)
    {
        // call method to print table
        PrintTable();
    }
}