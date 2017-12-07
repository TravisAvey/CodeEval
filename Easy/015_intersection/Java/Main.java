import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Main {

  public static void main(String[] args) throws IOException {

    ArrayList<String> list = new ArrayList<>();

    if (args.length > 0) {

      BufferedReader reader = new BufferedReader(new FileReader(args[0]));

      String line = "";

      while ((line = reader.readLine()) != null) {

        list.add(line);
      }

      reader.close();
      
      for (String data : list) {

        String[] items = data.split(";");

        printIntersection(items);
      }
    }
  }

  private static void printIntersection(String[] data) {

      for (String d : data) {

        System.out.println(d);
      }
  }

}
