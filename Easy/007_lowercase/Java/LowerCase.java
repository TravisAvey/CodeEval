import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class LowerCase
{

    public static void main(String[] args) throws IOException
    {
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
                // print to stdout, the lower case version of the string
                System.out.println(item.toLowerCase());
            }
        }

    }

}