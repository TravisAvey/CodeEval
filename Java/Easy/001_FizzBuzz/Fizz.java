import java.util.*;
import java.lang.*;
import java.io.File;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class Fizz
{
    public static void FizzBuzz(int fizz, int buzz, int limit)
    {
        String result = "";
        for (int i=1; i<=limit; ++i)
        {
            if (i%fizz==0 && i%buzz==0)
                result+= "FB ";
            else if (i%fizz == 0)
                result += "F ";
            else if (i%buzz ==0)
                result += "B ";
            else
                result += i + " ";
                
        }
        
        System.out.println(result);
    }
    
    public static void main(String[] args)
    {
        
        File file = new File(args[0]);
        
        try (BufferedReader br = new BufferedReader(new FileReader(file))) 
        {
            String line;
            while ((line = br.readLine()) != null) 
            {
                String dataStr[] = line.split(" ");
                int data[] = new int[3];
                for (int i=0; i<3; ++i)
                    data[i] = Integer.parseInt(dataStr[i]);
                
                FizzBuzz(data[0], data[1], data[2]);
            }
        }
        catch (IOException e)
        {
            System.out.println(e.toString());
        }
    }
}
