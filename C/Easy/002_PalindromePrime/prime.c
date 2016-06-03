#include <stdio.h>
#include <stdlib.h>

void Sieve(int max, int *prime);
int FindPalindrome(int *primes, int len);

int main(int argc, char *argv[])
{
    int limit = 1001;
    int prime[limit];
    Sieve(limit, prime);
    
    printf("%d\n", FindPalindrome(prime, limit));
    
    return 0;
}

void Sieve (int max, int *prime)
{
    // set all to true
    for (int i=0; i<max+1; ++i)
        prime[i] = 1;
    
    // set 0 and 1 to false (not primes!)
    prime[0] = 0;
    prime[1] = 0;
    
    for (int i=2; i<max/2; ++i)
        for (int j=i*i; j<max; j += i)
            prime[j] = 0;
    
}

int FindPalindrome (int *primes, int len)
{
    int hi = 0;
    
    for (int i=0; i<len; ++i)
    {
            if (primes[i] == 1)
            {
            int n = i;
            int num = n;
            
            int reverse = 0;
            int digit = 0;
            
            while (num > 0)
            {
                digit = num % 10;
                
                reverse = reverse * 10 + digit;
                
                num /= 10;
            }
            
            if (n == reverse && n > hi)
                hi = n;
        }
            
    }
    
    return hi;
    
}