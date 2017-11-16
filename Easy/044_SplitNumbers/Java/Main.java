import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main
{

    public static void main(String[] args) throws IOException
    {

        // create a list to hold each line of the file
        ArrayList<String> list = new ArrayList<>();

        if (args.length > 0)
        {
            // create a reader to read the file
            BufferedReader reader = new BufferedReader(new FileReader(args[0]));

            // init a string to hold each line
            String line = "";

            // while able to get a line from the file, add to the list
            while ((line = reader.readLine()) != null)
                list.add(line);

            // close out the reader
            reader.close();

            // for each item in the list
            for (String item : list)
            {
                splitNumbers(item);
            }
        }
    }

    /*
        This method handles splitting the numbers
     */
    private static void splitNumbers(String line)
    {
        // create an array by splitting the line on a ' '
        // args[0] is the number
        // args[1] is the pattern: ab+cdef
        String args[] = line.split(" ");

        // create a char array for the pattern
        char pattern[] = args[1].toCharArray();

        // init 2 chars for add and sub
        char add = '+';
        char sub = '-';

        // loop through the pattern array
        for (int i=0; i<args[0].length(); i++)
        {
            // if the current char is add
            if (pattern[i] == add)
            {
                // set the index and operator
                operate(args[0], i, add);
            }
            // else if the char is to subtract
            else if (pattern[i] == sub)
            {
                // set the index and operator
                operate(args[0], i, sub);
            }
        }

    }

    /*
        This method takes the string of numbers and conducts the operation
        on it.  The index is where to split the number
     */
    private static void operate(String data, int index, char operator)
    {
        // get the 2 numbers:
        int x = Integer.parseInt(data.substring(0, index));
        int y = Integer.parseInt(data.substring(index));

        // initialize the answer to 0
        int answer = 0;
        // if add
        if (operator == '+')
            answer = x + y;
        // if subtract
        else if (operator == '-')
            answer = x - y;

        // output answer to stdout
        System.out.println(answer);
    }
}
