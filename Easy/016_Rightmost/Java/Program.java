import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main
{

    public static void main(String[] args) throws IOException
    {

        if (args.length > 0)
        {
            // create a reader to read the file
            BufferedReader reader = new BufferedReader(new FileReader(args[0]));

            // init a string to hold each line
            String line = "";

            // while able to get a line from the file, add to the list
            while ((line = reader.readLine()) != null)
                rightMost(line);

            // close out the reader
            reader.close();
        }
    }

    // This method prints out the location of the 
    // right most char
    // Input: Hello World,r
    // Ouput: location of 'r' in 'Hello World' : 8
    private static void rightMost(String line) {
        // split the line on the comma
        String data[] = line.split(",");
        // get the char in question 
        char ch = data[1].charAt(0);
        // init a loc to -1, if not found will output -1
        int loc = -1;
        // loop through the string in question
        for (int i = 0; i < data[0].length(); i++) {
            // if the current char is the char in question
            if (data[0].charAt(i) == ch)
                // set the loc to the current
                loc = i;
        }
        // output loc, if not found it will be -1
        System.out.println(loc);
    }

}