#include <iostream>
#include <fstream>
#include <vector>

bool IsSelfDescribe(std::string &);

int main (int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    // if file is opened
    if (file)
    {
        // declare string to hold each line
        std::string line;
        // get each line -> string
        while (std::getline(file, line))
            // output if number is self describing
            std::cout << IsSelfDescribe(line) << std::endl;
    }
    // close file
    file.close();
    return 0;
}

/*
    This method checks if the number is self describing.
    2020 is, 22 is not
    
    number like an array, 0 pos = # of 0s, 1 pos = # of 1s
    so 2020: 2 0s, 0 1s, 2 2s, 0 3s is true
    
    22: 2 0s and 2 1s. is false 
*/
bool IsSelfDescribe(std::string &numStr)
{   
    // get length of numStr
    int len = numStr.length();
    
    // loop through each num in str 
    for (int i=0; i<len; ++i)
    {
        
        int count = 0;
        // get the current char
        char c = numStr[i];
        
        // count the number of times current index occurs
        for (int k=0; k<len; ++k)
            if (i == ((int)numStr[k] - 48))
                count++;
        
        // if count isnt the same as current char #
        // return false
        if (count != ((int)c - 48))
            return false;

    }

    // if we get here, number is self describing
    return true;
}
