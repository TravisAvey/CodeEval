import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class SumOfDigits
{

    public static void main(String[] args) throws IOException
    {
        ArrayList<String> list = new ArrayList<>();

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
            // get an array of each digit of the string
            int[] array = parseToIntArray(item);

            // init a sum
            int sum = 0;
            // for each number in the array, add to sum
            for (int n : array)
                sum += n;
            // output to stdout the sum
            System.out.println(sum);
        }

    }

    /*
        This method parses a string to an array of ints
         data - a string that is a number: 123
          returns an array of the number: {1, 2, 3}
    */
    private static int[] parseToIntArray(String data)
    {
        // create an integer array to hold each number
        int[] numbers = new int[data.length()];
        // take the string and change to a char array
        char[] chars = data.toCharArray();
        // loop through the char array
        for (int i=0; i<chars.length; i++)
            // add the integer version of each character
            numbers[i] = Integer.parseInt(String.valueOf(chars[i]));

        // return the integer array
        return numbers;
    }
    
}