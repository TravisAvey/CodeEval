#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

class Digitize
{
private:
    std::map<std::string, int> numMap;
    std::vector<std::string> input;

    // This method initializes the char -> int map
    void Init ()
    {
        numMap["zero"]  = 0;
        numMap["one"]   = 1;
        numMap["two"]   = 2;
        numMap["three"] = 3;
        numMap["four"]  = 4;
        numMap["five"]  = 5;
        numMap["six"]   = 6;
        numMap["seven"] = 7;
        numMap["eight"] = 8;
        numMap["nine"]  = 9;
    }

    // parses the data and places into the input vector
    void Parse (std::string &data)
    {
        // init a string stream on the data
        std::stringstream ss (data);
        // declare a string to hold each token in the string
        std::string token;

        // while we can get the token delimeted by a ;, place into the intut vector
        while (std::getline (ss, token, ';'))
            input.push_back (token);
    }

public:
    // public construtor, pass data to be parsed to actual numbers
    Digitize (std::string &data)
    {
        // init the map && parse the string
        Init ();
        Parse (data);
    }

    // Public interface to output the words to digits
    void Output ()
    {
        // loop over the input array, output the corresponding digit
        for (auto num : input)
            std::cout << numMap[num];
        
        // end the stdout line
        std::cout << std::endl;
    }

};

int main (int argc, char *argv[])
{
    // open the file
    std::fstream file(argv[1], std::ios::in);

    // if the file is good
    if (file)
    {
        // declare a string to hold each line from file
        std::string line;
        // get that line from the file
        while (std::getline (file, line))
        {
            // init a new Digitize object, passing the line to it
            auto digit = new Digitize (line);
            // call the method that outputs the digits
            digit->Output ();
            // delete dynamically allocated memory
            delete digit;
        }
    }

    // close the file
    file.close ();

    return EXIT_SUCCESS;
}
