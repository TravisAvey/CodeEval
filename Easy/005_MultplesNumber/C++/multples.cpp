#include <iostream>
#include <fstream>
#include <sstream>

void Multiples(int *);
int *Split(const std::string &);

int main(int argc, char *argv[])
{
    // open file passed by console
    std::fstream file(argv[1], std::ios::in);
    
    // if file is opened
    if (file.good())
    {
        std::string line;
        // get each line store in string
        while (std::getline(file, line))
        {
            // call method that splits the line and returns an array
            int *A = Split(line);
            // call the method to determine the multple
            Multiples(A);
            // delete dynamically created array
            delete [] A;
        }
    }
    // done with file, close 
    file.close();
    
    return 0;
}

/*
    This method determines the smallest multiple of a value (that is a power of 2)
    that is greater than or equal to another value
*/
void Multiples(int *A)
{
    // first number is the 'hurdle', must be greater than or equal to
    int x = A[0];
    
    // second number is a power of 2, where we must print out the smallest
    // multiple of n that is greater than x (no division or modulus)
    int n = A[1];
    
    // loop through each number from 1 - x
    for (int i=1; i<=x; ++i)
    {
        // get the multiple of current index * n
        int multiple = i*n;
        // if greater o equal to
        if (multiple >= x)
        {
            // output the answer
            std::cout << multiple << std::endl;
            // break, we found the answer
            break;
        }
    }
    
}

/*
    This method splits up a string and returns an array
*/
int *Split(const std::string &line)
{
    // init the stringstream on passed in line
    std::stringstream ss(line);
    // declare a string as a token to hold data parsed
    std::string token;
    // declare an array
    int *A = new int[2];
    // init counter for array
    int i=0;
    // while we can get data from string stream, split on ','
    while (std::getline(ss, token, ','))
        A[i++] = std::stoi(token);
        
    // return the array
    return A;
}
