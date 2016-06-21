using System;
using System.IO;
using System.Linq;

class Program
{
    class SumDigits
    {
        private int mLength;

        public int Sum(int num)
        {
            return GetSum(num);
        }

        public int Length
        {
            set { mLength = value; }
        }
        private int GetSum(int num)
        {
            int ans = 0;
            int n = 0;

            for (int i=1; i<=mLength; ++i)
            {
                n = num % 10;
                num /= 10;
                ans += n;
            }
            
            return ans;
        }
    }


    public static void Main (string[] args)
    {
        SumDigits sumDigits = new SumDigits();

        foreach (string line in File.ReadLines(args[0]))
        {
            int num = int.Parse(line);
            sumDigits.Length = line.Length;
            Console.WriteLine(sumDigits.Sum(num));
        }
    }
}