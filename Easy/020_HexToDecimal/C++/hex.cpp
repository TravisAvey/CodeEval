#include <iostream>
#include <fstream>

int main (int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    // if file is opened
    if (file)
    {
        // get each line
        std::string line;
        while (std::getline(file, line))
            // output the decimal version of the hex string
            std::cout << std::strtol(line.c_str(), NULL, 16) << std::endl;
        
    }
    // close file
    file.close();
    return 0;
}
