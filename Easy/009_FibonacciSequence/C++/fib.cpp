#include <iostream>
#include <fstream>
#include <vector>

int Fibonacci(int);

int main(int argc, char *argv[])
{
    // open file passed to program
    std::fstream file(argv[1], std::ios::in);
    
    // if file is good
    if (file.good())
    {
        // declare string to hold each line
        std::string data;
        // get each line put into string
        while (std::getline(file, data))
            // output the nth fibonacci
            std::cout << Fibonacci(std::stoi(data)) << std::endl;
    }
    
    // close file
    file.close();
    return 0;
}

/*
    This method returns the nth element of the
    Fibonacci Sequence
*/
int Fibonacci(int n)
{
    // declare a vector
    std::vector<int> arr;
    
    // add first two 0,1
    arr.push_back(0);
    arr.push_back(1);
    
    // loop through the rest Fn = F(n-1) + F(n-2)
    for (int i=2; i<=n; ++i)
        arr.push_back(arr[i-1] + arr[i-2]);
        
    // return the result
    int result = arr[n];
    return result;
}
