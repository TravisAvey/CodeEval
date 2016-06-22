using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Program
{
    /// <summary>
    /// This method splits up the string into two arrays and
    /// then calls the method to find the intersection
    /// </summary>
    private static void FindIntersection(string line)
    {
        // split that data into arrays
        string[] data = line.Split(';').ToArray();
        int[] a = data[0].Split(',').Select(i => int.Parse(i)).ToArray();
        int[] b = data[1].Split(',').Select(i => int.Parse(i)).ToArray();

        // print the intersection
        PrintIntersect(a, b);
    }

    /// <summary>
    /// This method finds the intersection of the two arrays
    /// </summary>
    private static void PrintIntersect(int[] a, int[] b)
    {
        // init a list to hold answers.
        var intersect = new List<int>();

        // init 3 counters
        int i=0;
        int j=0;
        int count = 0;

        // while we havent gone out of range for a or b
        while(i<a.Length && j<b.Length)
        {
            // if a and b are equal, we have an intersection
            if (a[i]==b[j])
            {
                // add the intersection, increment counters
                intersect.Add(a[i]);
                i++;
                j++;
                count++;
            }
            // if a is greater than b, inc j else inc i
            else if (a[i] > b[j])
                j++;
            else
                i++;
        }

        // if we have a count, we have intersections in this data set
        if (count > 0)
        {
            // loop through the intersect list
            for (int k=0; k<count; k++)
            {
                // write out current
                Console.Write(intersect[k]);
                // write out a ',', if not last
                if (k != count - 1)
                    Console.Write(',');
            }
            // finally write a new line
            Console.WriteLine();
        }
        // if no intersect, write a new line
        else
            Console.WriteLine();
        
    }
    
    public static void Main (string[] args)
    {
        // for each line in the file
        foreach (string line in File.ReadLines(args[0]))
        {
            // Find the intersection
            FindIntersection(line);
        }
    }
}
