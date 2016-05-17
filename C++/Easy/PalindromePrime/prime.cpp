#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> Sieve(int, bool *);
int FindPalindrome(std::vector<int>);

int main()
{
    // clock for begin time
	std::clock_t begin = std::clock();
	
    // limit number of primes
    int num = 1000;
    
    // declare an array for primes
    bool p[num];
    
    // call Sieve method to get primes into a vector
    std::vector<int> primes = Sieve(num,p);
    
    // output the highest prime number that is a palindrome
    std::cout << FindPalindrome(primes);
   	
    // end the clock timer
   	std::clock_t end = std::clock();
    // calculate the elpased time
   	double elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
       
    // output the elapsed time
   	std::printf("\nTime elapsed %f\n", elapsed);
   	
    return 0;
}

/*
    This method puts all the prime numbers into
    a vector, calculates by Sieve of Eratosthenes.
*/
std::vector<int> Sieve(int limit, bool *Prime)
{
    // initialize the array
    Prime = new bool[limit+1];
    // declare vector to hold the primes
    std::vector<int> primes;
    
    // set all numbers in array to true to start
    for (int i=0; i<limit+1; ++i)
        Prime[i] = true;
    
    // loop through, starting at 2, where i squared less than limit
    for (int i=2; i*i<=limit; ++i)
    {
        // if true, loop through and set the numbers not prime to false
        if (Prime[i])
            for (int j=i*2; j<=limit; j += i)
                Prime[j] = false;
    }
    
    // loop through Prime[] and push prime numbers into the vector
    for (int i=2; i<=limit; ++i)
        if (Prime[i])
            primes.push_back(i);
            
    return primes;
}

/*
    This method finds the Highest Palindrome
    of supplied vector
*/
int FindPalindrome(std::vector<int> nums)
{
    // initialize a variable to hold the hi
	int hi = 0;
	
    // for each item in the vector
	for (int num : nums)
	{
        // initalize variable to hold current number
		int n = num;
        // initalize reverse and digit
		int reverse = 0;
		int digit = 0;
		while (num > 0)
		{
            // get the digit off the number
			digit = num % 10;
            // shift the number and add the digit at the end
			reverse = reverse * 10 + digit; 
            // divide number by 10
			num /= 10;
		}
        // check if palindrome and if current is greater than hi
		if (n == reverse && n > hi)
			hi = n;
	}
    // return highest palindrome in the set of numbers
	return hi;
}