#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void PrintRomanNumerals (std::string &);


int main (int argc, char *argv[])
{
    // open file
    std::fstream file (argv[1], std::ios::in);
    // if file is opened
    if (file)
    {
        // declare a string to hold each line
        std::string line;
        // while we can get a line from the file
        while (std::getline (file, line))
            // call method to convert the Roman Numeral and print it
            PrintRomanNumerals (line);
    }
    // close the file
    file.close ();
    return 0;
}

/*
    This method converts the passed in string to a Roman Numeral,
    given that the string is a number
*/
void PrintRomanNumerals (std::string &line)
{
    // a vector of vectors of type string for all the roman numerals
    std::vector<std::vector <std::string> > romanNumerals = {
        { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, // ones
        { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" }, // tens
        { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  // hundreds
        { "", "M", "MM", "MMM"}                                         // thousands
    };

    // reverse the string
    std::reverse (line.begin(), line.end());
    // get the length of the line
    auto i = line.length ();

    // initialize a new string to hold the answer
    std::string romanNumeral("");

    // loop through the line
    while (i-- > 0)
    {
        // get the second index.. we create a string from the char type, and then use
        // stoi (string to int) to convert to an int
        int index = std::stoi(std::string(1, line[i]));
        // append the corresponding letter to roman numeral string
        // i is the place, so if 0 its ones, 1 its tens, etc..
        // the second index is for that vector, so [0][8] corresponds to VIII
        romanNumeral += romanNumerals[i][index];
    }
    // output the roman numeral
    std::cout << romanNumeral << std::endl;
}
