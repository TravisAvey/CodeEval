#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>


void SetCounts(std::string &);
void RemovePuncSpaces(std::string &);


int main (int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    // if file opened
    if (file)
    {
        // get each line and call the method to get the count
        std::string line;
        while (std::getline(file, line))
            SetCounts(line);
    }
    
    // close file
    file.close();
    return 0;
}

/*
    This method outputs the Beautiful # of each string
*/
void SetCounts(std::string &line)
{
    // set each char to lowercase
    std::transform (line.begin(), line.end(), line.begin(), ::tolower);
    
    // declare a vector to hold the possible characters
    // we only need the number of each char, dont care about the chars
    // themselves
    std::vector<int> posChars;
    
    // init all chars ('a-z') to 0
    for (int i=0; i<26; ++i)
        posChars.push_back(0);
    
    // for each char in the string    
    for (char c : line)
    {
        // if not a letter, continue
        if (c < 'a' || c > 'z')
            continue;
        // increment the current char
        posChars[c-'a']++;
    }
    
    // sort the vector (this is low to hi)
    std::sort(posChars.begin(), posChars.end());
    
    // declare vars to hold sum
    int sum = 0;
    int n = 26;
    // start at end of vector
    for (int i=25; i>=0; --i)
        // increment sum with the current char # multiply by n
        sum += posChars[i]*n--;
    
    // output the sum
    std::cout << sum << std::endl;
        
}

