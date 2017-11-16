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
                majorElement(item);
            }
        }
    }

    /*
        This method prints to stdout the major element
        of a set of numbers, where the set looks like:
        2,3,3,4,5,5,9,1,89,9,3

        If a number has count that is greater than half
        the number of elements, then its the major element

     */
    private static void majorElement(String line)
    {
        // split the line on commas, into an array of strings
        String data[] = line.split(",");

        // init a new Hash Map that will contain the number
        // and the count of that number
        HashMap<String, Integer> countMap = new HashMap<>();

        // init a string to hold what the major element is
        String major = "";
        // init a boolean to keep track if we found a major element
        boolean hasMajor = false;

        // loop over the array of numbers
        for (String num : data)
        {

            // if we have this key
            if (countMap.containsKey(num))
            {
                // increment the count
                int count = countMap.get(num);
                countMap.put(num, ++count);

                // if this count is a major element
                if (++count >= data.length/2)
                {
                    // set the bool, and string; then break
                    hasMajor = true;
                    major = num;
                    break;
                }
            }
            // otherwise, put count of the current number : 1
            else
                countMap.put(num, 1);
        }

        // if we have a major, then output the number
        if (hasMajor)
            System.out.println(major);
        // otherwise output None
        else
            System.out.println("None");


    }
}
