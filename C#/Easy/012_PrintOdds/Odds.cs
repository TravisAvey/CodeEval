using System;

class Odds
{
    public static void PrintOdds(int x, int y)
    {
        for (int i=x; i<=y; i+=2)
            Console.WriteLine(i);
    }
    static void Main(string[] args)
    {
        PrintOdds(1, 99);
    }
}
