#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int modulo(int, int);
void Split(std::vector<int> &, std::string);

int main(int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    // if file is opened
    if (file)
    {
        // get each line put into string
        std::string line;
        while (std::getline(file, line))
        {
            // declare a vector to hold each num
            std::vector<int> nums;
            // split the numbers from string -> vector
            Split(nums, line);
            // output the modulo of the two numbers
            std::cout << modulo(nums[0], nums[1]) << std::endl;
        }
    }
    // close the file
    file.close();
    return 0;
}

/*
    This method calculates the modulus of 
    two numbers passed to function
    
    20 mod 6 = 2
    1) 20 / 6 = 3
    2) 3 * 6 = 18
    3) 20 - 18 = 2
*/
int modulo(int n, int m)
{
    // calculate n mod m
    int x = n / m;
    int y = (x * m);
    int modulo = n - y;
    return modulo;
}

/*
    This method splits the passed in string, which are
    two numbers separated by a comma: 20,6
    and places them into the vector
*/
void Split(std::vector<int> &nums, std::string data)
{
    // string stream on the string passed
    std::stringstream ss(data);
    // declare string to hold the pieces
    std::string token;
    
    // get each part of string separated by ','
    while (std::getline(ss, token, ','))
        // convert to int place into vector
        nums.push_back(std::stoi(token));
}
