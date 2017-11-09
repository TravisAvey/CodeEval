#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void racingChairs(std::vector<std::string> &);

int main (int argc, char **argv)
{
    // if argc is less than 2, no file passed
    if (argc < 2)
        // output message
        printf("Usage: ./a.out file.txt\n");

    // grab file user passed to program
    std::fstream file (argv[1], std::ios::in);

    // if the file is good
    if (file)
    {
        // declare a string to hold each line
        std::string line;
        std::vector<std::string> data;
        // while we can get a line from the file
        while (std::getline(file, line))
        {
            data.push_back(line);
        }
        racingChairs(data);
    }

    return 0;
}

void racingChairs(std::vector<std::string> &data)
{
    int prevGate = -1;
    int prevChck = -1;
    int currentGate;
    int currentChck;
    bool hasGate;
    bool hasCheck;
    char checkPoint = 'C';
    char gate       = '_';

    // loop through each string
    for (auto line : data)
    {
        // loop over all the chars in the string
        for (int i=0; i<line.length(); i++)
        {
            if (line[i] == checkPoint)
            {
                hasCheck = true;
                currentChck = i;
            }

            if (line[i] == gate)
            {
                hasGate = true;
                currentGate = i;
            }
        }

        if (prevGate == -1)
            prevGate = currentGate;
        if (prevChck == -1)
            prevChck = currentChck;

        if (hasCheck)
            printf("Current has a check point\n");
        if (hasGate)
            printf("Current has a gate\n");
        
        hasCheck = false;
        hasGate = false;
    
    }
}
