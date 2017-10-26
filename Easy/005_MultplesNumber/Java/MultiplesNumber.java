package com.cyphyerbytes.easy;

import java.util.ArrayList;

public class MultiplesNumber
{
    private static final int N = 2;

    private String regex;
    private ArrayList<String> lines;

    public MultiplesNumber(ArrayList<String> lines)
    {
        this.lines = lines;
        regex = ",";
    }

    public void multiples()
    {
        // loop through every line
        for (String line : lines)
        {
            // split the line on the regex of ","
            String[] numberString = line.split(regex);
            // create an integer array of size N : (2)
            int[] numbers = new int[N];

            // loop through the string array and convert to integers
            for (int i=0; i<N; i++)
                numbers[i] = Integer.parseInt(numberString[i]);

            // call method to get the smallest multiples
            smallestMultiples(numbers);
        }
    }

    private void smallestMultiples(int[] nums)
    {
        int x = nums[0];
        int n = nums[1];

        int i = 1;
        // loop until we are found the smallest multiple
        while (true)
        {
            // if the multiple of i * n is greater than x
            if (n * i >= x)
            {
                // we found our smallest multiple, done
                System.out.println(n*i);
                break;
            }
            // haven't found, increment counter
            i++;
        }
    }
}
