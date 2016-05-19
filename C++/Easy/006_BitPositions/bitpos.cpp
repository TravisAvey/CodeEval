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
    // open file passed in console
    std::fstream file(argv[1], std::ios::in);
    // if file is good
    if (file.good())
    {
        // declare a string to hold the data
        std::string data;
        // getline for each line in the file
        while (std::getline(file, data))
        {
            // get the data from the string, put into a vector
            std::vector<int> nums = Split(data);
            // call method to check bit positions
            BitPositions(nums);
        }
    }
    // done with file, close it
    file.close();
    
    return 0;
}

/*
    This method parses a string on ','
    returns a vector of ints
*/
std::vector<int> Split(const std::string data)
{
    // declare vector to hold parsed data
    std::vector<int> v;
    // init string stream on passed in data string
    std::stringstream ss(data);
    // declare a string to hold the token
    std::string token;
    
    // while we can get data from the data string
    // delimited on ',', add the parsed data to an
    // int vector
    while( std::getline(ss, token, ','))
        v.push_back(std::stoi(token));
    
    // return vector
    return v;  
}

/*
    This method checks the bit positions of the passed
    int data.  First is num, second 2 are positions where
    bits should be checked
*/
void BitPositions(const std::vector<int> &data)
{
    // get number to check
    int num = data[0];
    // get 2 bit positions
    int a = data[1];
    int b = data[2];
    // 1 based, decrement to be 0 based
    a--;
    b--;
    
    // compare the bits and output true/false
    if (CompareBits(num,a,b))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

/*
    GetBit returns t/f based on shifting
    off the bits
*/
bool GetBit(unsigned int val, int pos)
{
    // return on binary AND shift left 1 pos,
    // then shift right
    return (val & (1 << pos)) >> pos;
}

/*
    Returns true or false if bits are same
    or different
*/
bool CompareBits(unsigned int val, int a, int b)
{
    // if bits are same and given positions,
    // return true, else return false
    if (GetBit(val,a) ^ GetBit(val,b)) 
        return false;
    else
        return true;
}
