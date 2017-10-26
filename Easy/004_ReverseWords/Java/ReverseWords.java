package com.cyphyerbytes.easy;

import java.util.ArrayList;

/*
    Score: 27.934 / 35.000
    Memory: 8,175,616 bytes
    Time: 139 ms

    VS. C++
    Score: 34.957
    Memory: 49,789
    Time: 1 ms
 */
public class ReverseWords
{
    private ArrayList<String> lines;

    public ReverseWords(ArrayList<String> lines)
    {
        this.lines = lines;
    }

    public void reverse()
    {
        // loop through the lines array list
        for (String line : lines)
        {
            // skip empty lines
            if (line.equals(""))
                continue;

            // create an array of words from the line, split on ' '
            String[] words = line.split(" ");
            // init a new string builder
            StringBuilder builder = new StringBuilder();
            // loop through the words array, going backwards
            for (int i = words.length-1; i>=0; i--)
            {
                // append the word
                builder.append(words[i]);
                // append a space
                builder.append(" ");
            }

            // remove the last space
            builder.deleteCharAt(builder.length()-1);
            // output the result
            System.out.println(builder.toString());
        }
    }

}
