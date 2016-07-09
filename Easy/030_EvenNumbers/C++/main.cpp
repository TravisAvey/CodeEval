#include <iostream>
#include <fstream>

int main (int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);

    // if file is good
    if (file)
    {
        // declare a string to hold each line from file
        std::string line;
        // while we can get a line from the file
        while (std::getline(file, line))
        {
            // convert the line to an int
            int num = std::stoi(line);
            // if number is even, print 0 else print 1
            if (num % 2 == 0)
                std::cout << 1 << std::endl;
            else
                std::cout << 0 << std::endl;
        }
    }
    file.close();

    return 0;
}
