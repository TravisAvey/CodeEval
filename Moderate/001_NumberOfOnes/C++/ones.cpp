#include <iostream>
#include <fstream>

std::string ToBinary(const int);
int CountOnes(std::string &);

int main (int argc, char *argv[])
{
    // open file 
    std::fstream file(argv[1], std::ios::in);
    
    // if file is opened
    if (file)
    {
        // get each line and put into a string
        std::string data;
        while (std::getline(file, data))
        {
            // get the binary string of the number
            std::string bin = ToBinary(std::stoi(data));
            // output the count of ones
            std::cout <<  CountOnes(bin) << std::endl;
        }
    }
    // close the file
    file.close();
    return 0;
}

/*
    This method converts an integer to a binary string
*/
std::string ToBinary(const int num)
{
    // get the mask 
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);
    // init a string
    std::string bin = "";
    
    // loop through each digit
    for (int i=0; i< (sizeof(int) * 8); ++i)
    {
        // if the current is a 0, add 0 to string : else add 1
        if ((num & mask) == 0)
            bin += '0';
        else
            bin += '1';
        // bit shift the mask one to the right
        mask >>= 1;
    }
    // return the string
    return bin;
}

/*
    This method return the count of '1's in 
    a string
*/
int CountOnes(std::string &binary)
{
    // init a counter
    int count = 0;
    // loop through each letter in the string
    for (auto b : binary)
        // if the letter is '1', inc counter
        if (b == '1')
            count++;
    // return the string
    return count;
}
