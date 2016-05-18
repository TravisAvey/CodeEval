#include <iostream>
#include <fstream>
#include <sstream>

void Multiples(int *);
int *Split(const std::string &);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file.good())
    {
        std::string line;
        while (std::getline(file, line))
        {
            int *A = Split(line);
            Multiples(A);
            delete [] A;
        }
    }
    file.close();
    return 0;
}

void Multiples(int *A)
{
    // first number is the 'hurdle', must be greater than or equal to
    int x = A[0];
    
    // second number is a power of 2, where we must print out the smallest
    // multiple of n that is greater than x (no division or modulus)
    int n = A[1];
    //std::cout << x << "," << n << std::endl;
    
    for (int i=1; i<=x; ++i)
    {
        int multiple = i*n;
        if (multiple >= x)
        {
            std::cout << multiple << std::endl;
            break;
        }
    }
    
}

int *Split(const std::string &line)
{
    std::stringstream ss(line);
    std::string token;
    int *A = new int[2];
    
    int i=0;
    while (std::getline(ss, token, ','))
        A[i++] = std::stoi(token);
        
    return A;
}

/*
wrong answer.. had 10 inputs...

1600
256
2048
2048
2048

*/
