import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Fibonacci
{

    public static void main(String[] args) throws IOException
    {
        ArrayList<String> list = new ArrayList<>();

        // create a reader for the file
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));

        // init a String to hold each line of the file
        String line = "";

        // while we can get a line from the file, add to the array list
        while ((line = reader.readLine()) != null)
            list.add(line);
        // close the reader
        reader.close();

        // for each item in the list, call the fibonacci method
        for (String item : list)
            System.out.println(fibonacci(Integer.parseInt(item)));

    }

    /*
        This method gets the nth number of the
        fibonacci sequence
    */
    private static int fibonacci(int n)
    {
        // create a list to hold the sequence
        List<Integer> fib = new ArrayList<>();

        // add the first 2 to the sequence
        fib.add(0);
        fib.add(1);

        // F(n) = F(n-1) + F(n-2)
        for (int i=2; i<=n; i++)
            fib.add(fib.get(i-1) + fib.get(i-2));

        // return the nth fibonacci number
        return fib.get(n);
    }

}
