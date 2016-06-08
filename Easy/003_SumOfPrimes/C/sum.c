#include <stdio.h>

int GetSum(int);
short IsPrime(int);
int main(int argc, char *argv[])
{
    int sum = GetSum(1000);
    printf("%d\n", sum);
    return 0;
}

/*
    This method returns the sum of the first nth prime
    numbers
*/
int GetSum(int limit)
{
    // init a sum, counter, and i starts at 2.. 1 not a prime
    int sum = 0;
    int i = 2;
    int count = 0;
    
    // keep suming until count is = to limit
    while (count < limit)
    {
        // if the current number is a prime number
        if (IsPrime(i) == 1)
        {
            // add prime to sum
            sum += i;
            // increment number of primes
            count++;
        }
        // go to the next number
        i++;
    }
    
    // return the sum of primes
    return sum;
}

/*
    This method Checks if the number is a prime or not.
*/
short IsPrime(int num)
{
    // loop from 2 -> the num
    for (int i=2; i<num; ++i)
        // if the num is divisible by any of the numbers
        if (num % i == 0)
            // return 0 for false
            return 0;
    // looped all the way through and didnt return? we have a prime number
    return 1;
}
