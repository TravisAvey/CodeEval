#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <vector>

std::vector<int> Split(const std::string);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file.good())
    {
        std::string data;
        while (std::getline(file, data))
        {
            std::vector<int> nums = Split(data);
            for (int i : nums)
                std::cout << i << std::endl;
            std::cout << "********\n";
        }
    }
    std::cout << std::bitset<8>(125).to_string() << std::endl;
    return 0;
}

std::vector<int> Split(const std::string data)
{
    std::vector<int> v;
    std::stringstream ss(data);
    std::string token;
    
    while( std::getline(ss, token, ','))
        v.push_back(std::stoi(token));
    
    return v;  
}

