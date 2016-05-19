#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


std::vector<int> Split(const std::string);
void BitPositions(const std::vector<int> &);
bool GetBit(unsigned int, int);
bool CompareBits(unsigned int, int, int);

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
    int a = data[1];
    int b = data[2];
    a--;
    b--;
    
    
    if (CompareBits(num,a,b))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

bool GetBit(unsigned int val, int pos)
{
    return (val & (1<< pos)) >> pos;
}

bool CompareBits(unsigned int val, int a, int b)
{
    if (GetBit(val,a) ^ GetBit(val,b)) 
        return false;
    else
        return true;
}
