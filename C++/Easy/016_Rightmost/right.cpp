#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int CharPos(const std::string &, char);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file)
    {
        std::string line;
        while (std::getline(file, line))
        {
            char ch = line.back();
            
            line.pop_back();
            line.pop_back();
            std::cout << CharPos(line, ch) << std::endl;
        }
    }
    return 0;
}

int CharPos(const std::string &line, char ch)
{
    
    return line.find_first_of(ch);
}
