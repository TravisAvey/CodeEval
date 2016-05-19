#include <iostream>
#include <fstream>
#include <algorithm>

void PrintLowerCase(const std::string &);
std::string ToLower(const std::string &);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file.good())
    {
        std::string line;
        while (std::getline(file, line))
            PrintLowerCase(line);
    }
    else
        std::cout << "Error opening file!" << std::endl;
        
    file.close();
    
    return 0;
}

void PrintLowerCase(const std::string &line)
{
    std::cout << ToLower(line) << std::endl;
}

std::string ToLower(const std::string &data)
{
    std::string lower = data;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}
