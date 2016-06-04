#include <iostream>
#include <ctime>

bool isPrime(const int &);
uint32_t getSum(const int &);

int main()
{
    // start the timer
    std::clock_t begin = std::clock();
    
    // output the sum of the first 1000 prime numbers
    std::cout << getSum(1000) << std::endl;
    
    // stop the timer
    std::clock_t end = std::clock();
    
    // calculate the time it took
    double time = (double)(end-begin) / CLOCKS_PER_SEC;
    
    // output the time
    std::printf("Total time: %f\n", time);
    
    return 0;
}

/*
    This method calculates the sum of the first n 
    numbers primes (limit)
*/
uint32_t getSum(const int &limit)
{
    // init result, counter, and index
    uint32_t result = 0;
    int count = 0;
    // start at 2 because we know 1 is not a prime
    int i = 2;
    
    // while count is less than the limit
    while (count < limit)
    {
        // if current i is a prime
        if (isPrime(i))
        {
            // add to result
            result += i;
            // counter here because we are only
            // couting primes!
            count++;
        }
        // regardless if prime or not, increment index
        ++i;
    }
    
    // return the sum of the prime numbers
    return result;
}

/*
    This method checks if the number passed include
    is a prime number.  Returns bool value
*/
bool isPrime(const int &n)
{
    // loop through all numbers
    // starting at 2 (n / 1)
    for (int i=2; i<n; ++i)
        // if n / current index is divisible,
        // not a prime, return false
        if (n % i == 0)
            return false;
    
    // if we get here, number is prime - return true
    return true;
}