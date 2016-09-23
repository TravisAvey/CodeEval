
var fs  = require("fs");

// this method changes a float value to an int
function FloatToInt (n)
{
    // using binary OR, truncates the floating point values
    return n | 0;
}

// this method Finds the highest palindrome
function Palindrome (primes, max)
{
    // init a hi for the highes palindrome
    var hi = 0;

    // loop over every value 
    for (var i=0; i<max; ++i)
    {
        // if the number is prime
        if (primes[i])
        {
            // declare variables
            var n = i;
            var num = n;
            var reverse = 0;
            var digit = 0;

            // while current num is greater than 0
            while (num > 0)
            {
                // take the last number off
                digit = FloatToInt (num % 10);
                // append to the reverse number
                reverse = FloatToInt (reverse * 10 + digit);
                // divide number by 10
                num = FloatToInt (num/10);
            }
            
            
            // if it is the reverse and higher than n
            if (n == reverse && n > hi)
                hi = n;
        }
    }
    // return the highest palindrome
    return hi;
}

// This method creates a Sieve of bool values for the prime numbers
function Sieve (limit)
{
    // init an array of the size limit
    var sieve = [limit];

    // set all to true to start
    for (var n=0; n<limit; ++n)
        sieve[n] = true;
    
    // 0,1 are not prime numbers
    sieve[0] = false;
    sieve[1] = false;

    // set all the numbers that aren't prime to false
    for (var i=2; i<Math.sqrt(limit); ++i)
        for (var j=i*i; j<limit; j+=i)
            sieve[j] = false;

    // call method that finds the palindrome
    return Palindrome (sieve, limit);
}

(function ()
{
    // display the highest prime number that is a palindrome
    console.log (Sieve (1000));
})();