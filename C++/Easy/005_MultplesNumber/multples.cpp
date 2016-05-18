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
    
    return 0;
}

void Multiples(int *A)
{
    std::cout << A[0] << ", " << A[1] << std::endl;
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
