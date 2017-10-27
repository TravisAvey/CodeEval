import java.io.IOException;


public class Multitable
{
    public static void main(String[] args) throws IOException
    {
        
        // double loop to make a 12x12 table
        for (int i=1; i<=12; i++)
        {
          for (int j=1; j<=12; j++)
          {
            // for the first row, just print the number
            if (j == 1)
              System.out.print(i*j);
            // otherwise, print the number with a width of 4
            // and justified to the right
            else
              System.out.print(String.format("%1$4s", i*j));
          }
          // print out a new line
          System.out.println();
        }
    }
}