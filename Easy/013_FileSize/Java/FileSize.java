import java.io.File;
import java.io.IOException;

public class Main
{

    public static void main(String[] args) throws IOException
    {
        
        // get the size, in bytes, of the file
        long size = new File(args[0]).length();
        // print to stdout the file size
        System.out.println(size);

    }



}