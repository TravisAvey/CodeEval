#include <iostream>
#include <fstream>
#include <algorithm>

void PrintLowerCase(const std::string &);
std::string ToLower(const std::string &);

int main(int argc, char *argv[])
{
    // open file passed to program
    std::fstream file(argv[1], std::ios::in);
    // if file is opened
    if (file.good())
    {
        // declare string to hold each line
        std::string line;
        // for each line, calll print to lower case on the line
        while (std::getline(file, line))
            PrintLowerCase(line);
    }
    else
        // ru-roh! problem opening file
        std::cout << "Error opening file!" << std::endl;
        
    // done with the file, close it
    file.close();
    
    return 0;
}

/*
    This method will print out the lower case
    version of string passed in
*/
void PrintLowerCase(const std::string &line)
{
    std::cout << ToLower(line) << std::endl;
}

/*
    This method will return the lower cased
    version of the passed in string
*/
std::string ToLower(const std::string &data)
{
    // init new string to lower case
    std::string lower = data;
    // call algorithm from beginging to end of string, flag tolower
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    // return lower cased string
    return lower;
}
