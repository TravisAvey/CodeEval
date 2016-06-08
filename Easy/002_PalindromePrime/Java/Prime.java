import java.util.*;
import java.lang.*;
import java.io.*;

class Prime
{
    /*
        This method creats a sieve of primes numbers
        using a boolean array
    */
    public static int Sieve (int limit)
    {
        // init a boolean array 
        boolean primes[] = new boolean[limit];
        
        // initially set all to true
        for (int i=0; i<limit; ++i)
            primes[i] = true;
        
        // set 0 and 1 to false, they aren't primes
        primes[0] = false;
        primes[1] = false;
        
        // set all non-primes to false
        for (int i=2; i<Math.sqrt(limit); ++i)
            for (int j=i*i; j<limit; j += i)
                primes[j] = false;
        
        // call the method that finds the highest palindrome
        return Palindrome(primes, limit);
    }
    
    /*
        This method finds the highest palindrom of the prime number
        sieve passed.  It returns this number
    */
    public static int Palindrome(boolean primes[], int max)
    {
        // declare a variable to hold the highest
        int hi = 0;
        
        // loop through each boolean value
        for (int i=0; i<max; ++i)
        {
            // if the number is prime
            if (primes[i])
            {
                // declare variables
                int n = i;
                int num =n;
                
                int reverse = 0;
                int digit = 0;
                // while current num is greater than 0
                while (num > 0)
                {
                    // take the last number off
                    digit = num % 10;
                    // append to the reverse number
                    reverse = reverse * 10 + digit;
                    // divide number by 10
                    num /= 10;
                }
                
                // if it is the reverse and higher than n
                if (n == reverse && n > hi)
                    hi = n;
            }
        }
        // return highest palindrome
        return hi;
    }

    
    public static void main(String[] args)
    {
        System.out.println(Sieve(1000));
    }
    
}
