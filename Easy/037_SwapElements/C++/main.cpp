#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

class Swap
{
private:
    // private member variables
    std::vector <std::string> mData;
    std::vector <std::string> mNums;
    std::vector <std::string> mSwaps;
    std::string mRawData;
    std::string mPositions;

    // private methods:
    void SplitData ();

public:
    // public constructor
    Swap (const std::string &data) : mRawData (data) 
    {
        SplitData ();
    };

    // public methods:
    void SwapElements ();

};

int main (int argc, char *argv[])
{
    // open the file
    std::fstream file (argv[1], std::ios::in);
    // if the file can be opened
    if (file)
    {
        // declare a string to hold each line
        std::string line;
        while (std::getline (file, line))
        {
            // create a new Swap object
            auto swap = new Swap (line);
            // swap the elements
            swap->SwapElements ();
            delete swap;
        }
    }

    return 0;
}

void Swap::SplitData ()
{
    // Extract the raw data
    std::stringstream ss(mRawData);
    std::string token;
    // split on numbers and the positions to swap
    while (std::getline(ss, token, ':'))
        mData.push_back (token);
    
    // remove the white space around the positions to be swapped
    mData[1].erase (std::remove_if (mData[1].begin (), mData[1].end (), ::isspace), mData[1].end ());
    mPositions = mData[1];

    // Extract the numbers and put into separate vector
    std::stringstream stream (mData[0]);
    std::string tok;
    while (std::getline (stream, tok, ' '))
        mNums.push_back (tok);
}

void Swap::SwapElements ()
{
    std::string numbers;

    // perform the swap

    // data could look like: 0-4,1-8
    // so we first swap the 0 with 4 postion, next we swap the 1 with 8

    // try to find a comma
    size_t sep = mPositions.find(',');
    // if we found a comma
    if (sep != std::string::npos)
    {
        // init a string stream on the positions
        std::stringstream ss (mPositions);
        // declare a string to hold the tokens
        std::string token;

        // while we can get the tokens split on a comma, add to swaps vector
        while (std::getline (ss, token, ','))
            mSwaps.push_back (token);
    }
    // else just add the mPositions to the vector
    else
        mSwaps.push_back (mPositions);

    // for each swap in the swaps vector
    for (auto swaps : mSwaps)
    {
        // init an array of 2
        int pos[2];
        // find the '-' in the swaps
        auto i = swaps.find ('-');
        // get the first and second positions
        pos[0] = std::stoi ( swaps.substr (0, i++));
        pos[1] = std::stoi ( swaps.substr (i));

        // perform the swap, thanks to the std swap function
        std::swap (mNums[pos[0]], mNums[pos[1]]);
    }

    // output the numbers after the swap
    for (auto num : mNums)
        std::cout << num << ' ';
    std::cout << std::endl;
}