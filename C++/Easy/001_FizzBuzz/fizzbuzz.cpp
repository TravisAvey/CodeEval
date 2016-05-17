#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void Split(std::string, std::vector<int>&);
void FizzBuzz(int, int, int);

int main(int argc, char * argv[])
{
    if (argc < 1)
    {
        std::cerr << "Need to pass in a file!" << std::endl;
        return -1;
    }
    
    std::fstream file(argv[1], std::ios::in);
    std::string line;
    
    if (file.good())
    {
        while (std::getline(file, line, '\n'))
        {
            std::vector<int> nums;
            Split(line, nums);
            FizzBuzz(nums[0], nums[1], nums[2]);
            
        }
    }
    
           
    return 0;
}

void Split(std::string data, std::vector<int> &vect)
{
    std::stringstream ss(data);
    std::string token;
    
    while (std::getline(ss, token, ' '))
        vect.push_back(std::stoi(token));
        //std::cout << token << std::endl;
}

void FizzBuzz(int x, int y, int n)
{
    for (int i=1; i<=n; ++i)
    {
        if (i % x == 0 && i % y == 0)
            std::cout << "FB";
        else if (i % x == 0)
            std::cout << "F";
        else if (i % y == 0)
            std::cout << "B";
        else
            std::cout << i;
        std::cout << ' ';
    }
    std::cout << std::endl;
}
