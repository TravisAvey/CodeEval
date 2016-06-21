using System;
using System.IO;
using System.Linq;

class Program
{
    class Fibonacci
    {
        private int[] FSequence;
        private int size = 50;

        /// <summary>
        /// Constructor.  Inits the Fibonacci sequence
        /// </summary>
        public Fibonacci()
        {
            FSequence = new int[size];
            SetFibonacci();
        }

        /// <summary>
        /// Returns the nth number in the Fibonacci sequence
        /// </summary>
        public int GetFibo(int n)
        {
            return FSequence[n];
        }

        // Set the fibonacci sequence
        private void SetFibonacci ()
        {
            // first 2 are 0, 1
            FSequence[0] = 0;
            FSequence[1] = 1;

            // the rest are F[n] = F[n-1] + F[n-2]
            for (int i=2; i<size; ++i)
                FSequence[i] = FSequence[i-1] + FSequence[i-2];

        }
    }

    public static void Main (string[] args)
    {
        // init fibonacci object
        Fibonacci f = new Fibonacci();

        // for each line in the file
        foreach (string line in File.ReadLines(args[0]))
        {
            // parse the line to an int
            int num = int.Parse(line);
            // print to stdout the nth Fibonacci
            Console.WriteLine(f.GetFibo(num));
        }
    }
}