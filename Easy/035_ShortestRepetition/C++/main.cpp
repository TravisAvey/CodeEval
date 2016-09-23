#include <iostream>
#include <fstream>


int GetRepeition (const std::string &);

int main (int argc, char *argv[])
{
    // open the file
    std::fstream file (argv[1], std::ios::in);

    // if file is good
    if (file)
    {
        // create a string to hold each line
        std::string line;
        
        // while we can get a line from the file
        while (std::getline (file, line))
            // output the repetition for the line
            std::cout << GetRepeition (line) << std::endl;
        
    }

    return 0;
}

/*
    This method finds the cycle of repetion
*/
int GetRepeition (const std::string &line)
{
    // init the repetition count
    int repetition = 0;

    // init a count
    int i = 0;

    // loop through the line starting at 2nd char
    for (int j=1; j < line.length(); ++j)
    {
        // when we find the first letter again, should have a cycle
        if (line[i] == line[j])
        {
            // set the repetition cycle
            repetition = j - i;
            // break out of loop
            break;
        }
    }

    // if we went through entire string without finding the same letter again
    // it means the entire string is the cycle
    if (repetition == 0)
        repetition = line.length ();   

    // return the cycle
    return repetition;

}
