/*
    This method checks if the number n
    is prime or not

    Loops through number, not 1 and not it self.
    if number is divisible by any number in the loop,
    it is not a prime.  If we make it through, dividing
    each number and checking if it divisible, then we have
    a prime number and return true
*/
function IsPrime (n)
{
    // loop through the number
    for (var i=2; i<n; ++i)
    {
        // if the number is divisible by 
        // any of i, then return false (not prime)
        if (n % i == 0)
            return false;
    }
    // if we make it through, we have a prime number
    return true;
}

/*
    This method sums the prime numbers from
    2 to x, we skip 0,1 because they are not
    prime number
*/
function SumPrimes (x)
{
    // init variables
    var result = 0;
    var count = 0;
    var i = 2;

    // while the count is less than x
    while (count < x)
    {
        // check if current number is prime
        if (IsPrime (i))
        {
            // if it is:

            // add number to result
            result += i;
            // increment the number of primes 
            count++;
        }
        // go to the next number
        i++;
    }
    // return the sum of primes
    return result;
}

// self calling method
(function ()
{
    // print out the sum of the firt 1000 prime numbers
    console.log (SumPrimes (1000));
})();