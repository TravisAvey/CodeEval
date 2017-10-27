import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.stream.Collectors;

public class PrintUnique
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
        for (String data : list)
        {
          // create a list of the data, removing any ','
          List<String> items = new LinkedList<>(Arrays.asList(data.split(",")));
          // remove any duplicates using Java8 Streams
          items = items.stream().distinct().collect(Collectors.toList());
          // call method to print the unique items
          printUnique(items);

        }
      }
    }

    public static void printUnique(List<String> data)
    {
      // init a new string builder
      StringBuilder sb = new StringBuilder();
      // loop over the data
      for (int i=0; i<data.size(); i++)
      {
        // append the ith item
        sb.append(data.get(i));
        // append a ','
        sb.append(",");
      }
      // shorten the stringbuilder by 1, removing last ,
      sb.setLength(sb.length()-1);
      // print to stdout the answer
      System.out.println(sb.toString());
    }
}