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
                // call the method to compress the sequence
                CompressSequence(item);
            }
        }

    }

    /*
        This method compresses a sequence:
        40 40 40 11 11 9 10 10 10 10
        as
        3 40 2 11 1 9 4 10
     */
    private static void CompressSequence(String data)
    {
        // convert the string param to a list
        List<String> nums = new ArrayList<>(Arrays.asList(data.split(" ")));

        // initialize a count as 1
        int count = 1;
        // loop through all but last in the list
        for (int i=0; i<nums.size() -1; i++)
        {
            // if the current number is same as the next number
            if (Objects.equals(nums.get(i), nums.get(i + 1)))
                // increment count
                count++;
            else
            {
                // otherwise, we output the count and the number
                System.out.print(count + " " + nums.get(i) + " ");
                // re init the count to 1
                count = 1;
            }

        }
        // finally, output the last count and number in list
        System.out.println(count + " " + nums.get(nums.size()-1));
    }
}

