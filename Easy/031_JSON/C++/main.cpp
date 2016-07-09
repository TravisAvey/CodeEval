#include <iostream>
#include <fstream>

class ParseJSON
{
private:
    std::string mJson;

public:


};

int main (int argc, char *argv[])
{
    std::fstream file (argv[1], std::ios::in);

    if (file)
    {
        std::string line;

        while (std::getline(file, line))
        {
            if (line == "") continue;

            std::cout << line << std::endl;
        }
    }
}