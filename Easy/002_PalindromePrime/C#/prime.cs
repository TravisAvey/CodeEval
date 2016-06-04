using System;
using System.Collections.Generic;

class prime
{
    /// <summary>
    /// This method makes a sieve of primes
    /// </summary>
    static void Sieve (int limit, int[] primes)
    {
        // init a new array of bools
        bool [] prime = new bool[limit+1];
        
        // set all to true
        for (int i=0; i<limit; ++i)
            prime[i] = true;
        
        // 0 and 1 are not primes
        prime[0] = false;
        prime[1] = false;
         
        // loop through 2 -> i squared < than the limit
        for (int i=2; i*i<=limit; ++i)
        {
            // set the non primes to false
            for (int j=0; j<=limit; j+=i)
                prime[j] = false;
        }
        
        // init a counter
        int n = 0;
        // loop through the bool array and 
        // if prime, add to the sieve primes[]
        for (int i=2; i<=limit; ++i)
            if (prime[i])
                primes[n++] = i;  
    }
    
    /// <summary>
    /// This method finds the highest prime number that is a palindrome
    /// </summary>
    static int PrimePalindrom(int[] primes)
    {
        // init a variable to for the largest prime number
        int hi = 0;
        
        // loop through all numbers in the prime array
        for (int i=0; i<1000; ++i)
        {
            // declare variables to use
            int num = primes[i];
            int n = num;
            // declare a var to hold the reverse of the number
            int reverse = 0;
            // decalare a var to hold each digit of the number
            int digit = 0;
            
            while (n > 0)
            {
                // get the last digit off the number
                digit = n % 10;
                // set the reverse 
                reverse = reverse * 10 + digit;
                // pop off last digit of the number
                n /= 10;
            }
            // if num is a palindrome, and highest set to hi
            if (num == reverse && num > hi)
                hi = num;
        }
        // return the highest
        return hi;
    }
    
    public static void Main (string[] args)
    {
        // declare the limit
        int limit = 1000;
        // create int array to hold the primes
        int[] primes = new int[limit];
        // get the sieve 
        Sieve (limit, primes);
        // print the highest palindrome 
        Console.WriteLine(PrimePalindrom(primes));
    }
}