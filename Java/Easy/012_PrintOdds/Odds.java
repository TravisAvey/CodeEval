import java.util.*;
import java.lang.*;
import java.io.*;

class Odds
{
	public static void PrintOdds(int start, int end)
	{
		for (int i=start; i<=end; i+=2)
			System.out.println(i);
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		PrintOdds(1, 99);
	}
}