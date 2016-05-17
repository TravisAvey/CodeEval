#include <iostream>

void Sieve(int, bool *);

void PrintPrime(bool *, int);

int main()
{
    int num = 100;
    
    bool p[num];
    
    Sieve(num,p);
    
    PrintPrime(p, num);
    return 0;
}

void Sieve(int limit, bool *Prime)
{
    Prime = new bool[limit+1];
    
    for (int i=0; i<limit+1; ++i)
        Prime[i] = true;
    
    for (int i=2; i*i<=limit; ++i)
    {
        if (Prime[i])
            for (int j=i*2; j<=limit; j += i)
                Prime[j] = false;
    }
    
    // for (int i=2; i<=limit; ++i)
    //     if (Prime[i])
    //         std::cout << i << ' ';
}

void PrintPrime(bool *Prime, int n)
{
    for (int i=2; i<=n; ++i)
        if (Prime[i])
            std::cout << i << ' ';
}