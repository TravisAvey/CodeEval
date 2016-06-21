
class Program
{
    
    public static void Main (string[] args)
    {
        // init the sum
        int sum = 0;
        // for each line in the file
        foreach (var line in System.IO.File.ReadLines(args[0]))
        {
            // parse the line to an int
            int num = int.Parse(line);
            // increment the sum with the number
            sum += num;
            
        }
        
        // output the number
        System.Console.WriteLine(sum);
    } 
   
}