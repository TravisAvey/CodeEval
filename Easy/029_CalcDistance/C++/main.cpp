#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstring>

class Distance
{
private:
    // data structure to hold the points
    struct Vector2
    {
        int x;
        int y;
    };

    // member variables to hold the coordinates
    Vector2 coordsA;
    Vector2 coordsB;

    // vector to hold the number
    std::vector<int> mNums;

    // method parses the string into the appropriate Vector2s
    void Parse (std::string line)
    {   
        // Regex doesn't work on CodeEval yet.. 
        // found this solution on stackoverflow

        // token the string, requires a char *, so &string[0] works
        // 2nd arguement is the delimeters
        char *tok = std::strtok(&line[0], "(), ");
        // while tok is not null
        while (tok)
        {
            // add the numbers to the vector, converting to ints
            mNums.push_back(std::stoi(tok));
            // set tok to the next strtok 
            tok = std::strtok(NULL, "(), ");
        }
        
        // set the Vector2s to correct coordinates
        coordsA.x = mNums[0];
        coordsA.y = mNums[1];
        coordsB.x = mNums[2];
        coordsB.y = mNums[3];
        // clear out the list (because not making a new Distance object each line from file)
        mNums.clear();
    }

public:
    // public interface to Init the data
    void Init (std::string data)
    {
        // parse the data
        Parse (data);
    }

    // returns the distance between the points
    int GetDistance ()
    {
        // d = sqrt( (x2 - x1)^2 + (y2 -y1)^2 )
        double x = coordsB.x - coordsA.x;
        double y = coordsB.y - coordsA.y;
        double d = sqrt(x*x + y*y);
        return (int)d/1;
    }
};

int main (int argc, char *argv[])
{
    // open the file
    std::fstream file (argv[1], std::ios::in);
    // if file is good
    if (file)
    {
        // create a new distance object
        auto distance = new Distance();
        // declare a string to hold each line
        std::string line;
        // while we can get a line from the file
        while (std::getline(file, line))
        {
            // init the distance object with the line
            distance->Init (line);
            // output to stdout the distance between the points
            std::cout << distance->GetDistance() << std::endl;
        }
        // free up memory
        delete distance;
    }
    // close the file
    file.close();
    return 0;
}
