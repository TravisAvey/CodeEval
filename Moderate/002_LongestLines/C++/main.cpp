#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Method declaration to find the longest strings in the file
void FindLongest (std::vector<std::string> &);

// compare operator that returns a bool based on length of the string
struct compare
{
    // the operator, compares 2 strings
    bool operator()(const std::string &l, const std::string &r) const
    {
        // returns true if left string is less than right
        return l.size() < r.size();
    }
};

int main (int argc, char *argv[])
{
    // open the file
    std::fstream file (argv[1], std::ios::in);

    // if the file is opened
    if (file)
    {
        // declare a vector to hold all the lines
        std::vector<std::string> lines;
        // declare a string to hold each line
        std::string line;

        // while we can get a line from the file
        while (std::getline (file, line))
            // add the line to the vector
            lines.push_back (line);
        
        // call method that will printout the n longest strings
        FindLongest (lines);
    }
    
    // close the file
    file.close ();

    return EXIT_SUCCESS;
}

/*
    This method prints out the longest n length strings,
    where n is the first in the vector
*/
void FindLongest (std::vector<std::string> &nums)
{
    // sort the vector, using the compare struct we made above
    std::sort (nums.begin (), nums.end (), compare ());
    
    // get the number of strings we need to print out
    int n = std::stoi (nums[0]);
    // get the total number of words in the vector
    int len = nums.size ();

    // while we have n to print out
    while (n > 0)
    {
        // decrement len first because we'd be out of range first iteration
        len--;
        // output the answer
        std::cout << nums[len] << std::endl;
        // decrement the n
        n--;
    }
}
