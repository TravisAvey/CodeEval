#include <iostream>
#include <fstream>
#include <vector>

int Fibonacci(int);

int main(int argc, char *argv[])
{
    
    std::fstream file(argv[1], std::ios::in);
    
    if (file.good())
    {
        std::string data;
        while (std::getline(file, data))
            std::cout << Fibonacci(std::stoi(data)) << std::endl;
    }
    
    file.close();
    return 0;
}

int Fibonacci(int n)
{
    std::vector<int> arr;
    
    arr.push_back(0);
    arr.push_back(1);
    
    for (int i=2; i<=n; ++i)
        arr.push_back(arr[i-1] + arr[i-2]);
        
    int result = arr[n];
    return result;
}
