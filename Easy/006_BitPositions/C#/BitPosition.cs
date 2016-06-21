using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class BitPosition
{

    private static void BitPositions(int num, int a, int b)
    {
        if (CompareBits(num, a, b))
            Console.WriteLine("true");
        else
            Console.WriteLine("false");
    }

    private static bool CompareBits(int val, int a, int b)
    {
        string bits = Convert(val);

        if (bits[a] == bits[b])
            return true;
        else
            return false;
    }

    private static string Convert(int val)
    {
        // char[] bits = new char[32];
        // int i = 0;

        // while (val != 0) 
        // {
        //     bits[i++] = (val & 1) == 1 ? '1' : '0';
        //     val >>= 1;
        // }

        // Array.Reverse(bits, 0, i);
        // return new string(bits);

        char[] b = new char[32];
        int pos = 31;
        int i = 0;

        while (i < 32)
        {
            if ((val & (1 << i)) != 0)
                b[pos] = '1';
            else
                b[pos] = '0';
            
            pos--;
            i++;
        }
        Array.Reverse(b);
        return new string(b);
    }
    public static void Main (string[] args)
    {
        foreach (string line in File.ReadLines(args[0]))
        {
            int[] nums = line.Split(',').Select(i => int.Parse(i)).ToArray();
            int val = nums[0];
            int a = nums[1] - 1;
            int b = nums[2] - 1;
            BitPositions(val, a, b);
        }
    }
}
