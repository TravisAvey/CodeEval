#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Swap
{
private:
    std::vector <std::string> mData;
    std::vector <std::string> mNums;
    std::string mRawData;
    std::string mPositions;
    void SplitData ();

public:
    Swap (const std::string &data) : mRawData (data) 
    {
        SplitData ();
    };

    std::string SwapElements ();

};




int main (int argc, char *argv[])
{
    std::fstream file (argv[1], std::ios::in);
    if (file)
    {
        std::string line;
        while (std::getline (file, line))
        {
            auto swap = new Swap (line);
            swap->SwapElements ();
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
    mData[1].erase (std::remove (mData[1].begin (), mData[1].end (), ' '), mData[1].end ());
    mPositions = mData[1];

    // Extract the numbers and put into separate vector
    std::stringstream stream (mData[0]);
    std::string tok;
    while (std::getline (stream, tok, ' '))
        mNums.push_back (tok);
}

std::string Swap::SwapElements ()
{
    std::string numbers;

    // perform the swap

    // data could look like: 0-4,1-8
    // so we first swap the 0 with 4 postion, next we swap the 1 with 8

    while (true)
    {
        // find a separator.. this separatest the swaps we do
        auto sep = mPositions.find (',');
        // if we don't find one, we done
        if (sep == std::string::npos)
            break;
        
        // we now have the positions to swap.. from 0 to sep 
        std::string swaps = mPositions.substr (0, sep);
        std::cout << swaps << std::endl;

        // set the string to the ',' to work on next set of and    
        mPositions = mPositions.substr (sep+1);
    }

    return "";
}