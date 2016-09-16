#include <iostream>
#include <fstream>
#include <map>

void PrintRomanNumeral (const std::string &);


int main (int argc, char *argv[])
{
    std::fstream file (argv[1], std::ios::in);
    if (file)
    {
        std::string line;
        while (std::getline (file, line))
            std::cout << line << std::endl;
    }
    return 0;
}

void PrintRomanNumerals (const std::string &line)
{
    std::string romanNumerals[2][10] = {
        { {""}, {"I"}, {"II"}, {"III"}, {"IV"}, {"V"}, {"VI"}, {"VII"}, {"VIII"}, {"IX"} },
        { {""}, {"X"} }
    };
}