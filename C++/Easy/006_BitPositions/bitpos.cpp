#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <vector>
#include <cmath>

std::vector<int> Split(const std::string);
void BitPositions(const std::vector<int> &);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file.good())
    {
        std::string data;
        while (std::getline(file, data))
        {
            std::vector<int> nums = Split(data);
            BitPositions(nums);
        }
    }
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

void BitPositions(const std::vector<int> &data)
{
    int num = data[0];
    int posA = data[1];
    int posB = data[2];
    
    posA = abs(posA - 8);
    posB = abs(posB - 8);
    
    std::string bitString = std::bitset<8>(num).to_string();
   
    if (bitString[posA] == bitString[posB])
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}
