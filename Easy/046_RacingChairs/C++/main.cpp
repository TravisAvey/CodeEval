#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

void racingChars(std::vector<std::string> &);

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
            // put the current line into the vector
            data.push_back(line);
        }
        // call the racing chars method!
        racingChars(data);
    }

    return 0;
}

/*
    This method moves through the maze based on 
    the last position and the current position

    a line: ######C##_##
    where: # is impassable
           C is a check point
           _ is a gate

    We want to go through the C, if no C then use _
*/
void racingChars(std::vector<std::string> &data)
{
    // current location
    int currentGate;
    int currentChck;
    // last position
    int prevPos;
    // booleans for having a gate or a check point
    bool hasGate;
    bool hasCheck;
    // boolean for first run
    bool firstRun = true;

    // all the chars
    char checkPoint = 'C';
    char gate       = '_';
    char straight   = '|';
    char left       = '/';
    char right      = '\\';

    // loop through each string
    for (auto line : data)
    {
        // loop over all the chars in the string
        for (int i=0; i<line.length(); i++)
        {
            // if current char is a checkpoint.
            if (line[i] == checkPoint)
            {
                hasCheck = true;
                currentChck = i;
            }
            // if current char is a gate
            if (line[i] == gate)
            {
                hasGate = true;
                currentGate = i;
            }
        }

        // if we are in the first run
        if (firstRun)
        {
            // set the firstRun bool to false
            firstRun = false;
            // if this iter has a check point
            if (hasCheck)
            {
                // store the current checkpoint for the next iter
                prevPos = currentChck;
                // replace the checkpoint char with the straight (first run!)
                std::replace(line.begin(), line.end(), checkPoint, straight);
            }
            else
            {
                // store the current gate location for next iter
                prevPos = currentGate;
                // replace the gate char with the straight char
                std::replace(line.begin(), line.end(), gate, straight);
            }
        }
        // else not first run
        else
        {
            // if current iter has a check point
            if (hasCheck)
            {
                // find out if current is the same, less, or greater than last pos
                // this determines which way we go, straight, left, or right
                if (prevPos == currentChck)
                    std::replace(line.begin(), line.end(), checkPoint, straight);
                else if (prevPos < currentChck)
                    std::replace(line.begin(), line.end(), checkPoint, right);
                else if (prevPos > currentChck)
                    std::replace(line.begin(), line.end(), checkPoint, left);

                // store current pos for next iter
                prevPos = currentChck;
            }
            // if current iter is a gate, but no check!
            else if (hasGate && !hasCheck)
            {
                // find out if current is the same, less, or greater than last pos
                // this determines which way we go, straight, left, or right
                if (prevPos == currentGate)
                    std::replace(line.begin(), line.end(), gate, straight);
                else if (prevPos < currentGate)
                    std::replace(line.begin(), line.end(), gate, right);
                else if (prevPos > currentGate)
                    std::replace(line.begin(), line.end(), gate, left);
                
                // store current pos for next iter
                prevPos = currentGate;
            }
        }

        // output the line for current iter
        std::cout << line << std::endl;

        // reset check point and gate booleans
        hasCheck = false;
        hasGate = false;
    
    }
}
