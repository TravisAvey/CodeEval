import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class SumIntegers
{

    public static void main(String[] args) throws IOException
    {
        ArrayList<String> list = new ArrayList<>();

        // create a buffered reader to read the file
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        // init a string to hold each line
        String line = "";

        // while we can read a line from the file, add to the list
        while ((line = reader.readLine()) != null)
            list.add(line);
        // close the reader
        reader.close();

        // init a sum to 0
        int sum = 0;

        // for each item in the list
        for (String item : list)
        {
            // add to the sum, parsing the string to an int
            sum += Integer.parseInt(item);
        }

        // ouput answer to stdout
        System.out.println(sum);

    }



}
