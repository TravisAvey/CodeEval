using System;

class sum
{
    /// <summary>
    /// This method returns the sum of prime numbers
    /// where the int passed is the number of primes 
    /// to sum
    /// </summary>
    static int SumPrimes(int primes)
    {
        // init sum, i, count
        int sum = 0;
        int i = 2;
        int count = 0;
        // while count is less than primes
        while (count < primes)
        {
            // check if current number is a prime
            if (IsPrime(i))
            {
                // add to sum
                sum += i;
                // increment counter
                count++;
            }
            // next number
            i++;
        }
        // return the sum
        return sum;
    }
    
    /// <summary>
    /// This method checks if the number passed 
    /// is a prime number. Returns true if, false otherwise
    /// </summary>
    static bool IsPrime(int n)
    {
        // loop through each number 2->n (not 1, every number is divisible by 1)
        for (int i=2; i<n; ++i)
            // if n is divisible by current number, return false
            if (n % i == 0)
                return false;
        // we get here, number is a prime
        return true;
    }
    
    public static void Main (string[] args)
    {
        Console.WriteLine(SumPrimes(1000));
    }
}