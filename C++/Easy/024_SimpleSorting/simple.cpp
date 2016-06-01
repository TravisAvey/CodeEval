#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

void Parse(std::string, std::vector<double> &, char);
void Sort(std::vector<double> &);

int main (int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    // if file is opened
    if(file)
    {
        // get each line
        std::string line;
        while (std::getline(file, line))
        {
            // declare a vector to hold the nums
            std::vector<double> nums;
            // method to parse each line delimit on ' '
            Parse(line, nums, ' ');
            // sort the nums
            Sort(nums);
            // print out each number, sorted
            for (auto n : nums)
                std::printf("%.3f ", n);
            // print out new line
            std::printf("\n");
        }
    }
    // close the file
    file.close();
    return 0;
}

/*
    This method parses the string, delimit on the char and put the
    numbers into the vector
*/
void Parse(std::string line, std::vector<double> &nums, char ch)
{
    // init a string stream on the string
    std::stringstream ss(line);
    // declare a string to hold each token
    std::string token;
    
    // get each token, convert to double, put into the vector
    while (std::getline(ss, token, ch))
        nums.push_back(std::stod(token));
}

/*
    Could've made my own sort, but just used STL's sort
    Possible source of 20kb of memory on my score (?)
*/
void Sort(std::vector<double> &nums)
{
    std::sort(nums.begin(), nums.end());
}
