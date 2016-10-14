#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main (int argc, char **argv)
{
    std::fstream file (argv[1], std::ios::in);

    if (file)
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
    }

    return 0;
}

