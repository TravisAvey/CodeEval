using System;
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

    private static string Convert(int x)
    {
        char[] bits = new char[32];
        int i = 0;

        while (x != 0) 
        {
            bits[i++] = (x & 1) == 1 ? '1' : '0';
            x >>= 1;
        }

        Array.Reverse(bits, 0, i);
        return new string(bits);
    }
    public static void Main (string[] args)
    {
        foreach (string line in File.ReadLines(args[0]))
        {
            int[] nums = line.Split(',').Select(i => int.Parse(i)).ToArray();
            BitPositions(nums[0], nums[1]--, nums[2]--);
        }
    }
}
