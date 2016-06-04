#include <iostream>
#include <fstream>
#include <string>

int CharPos(const std::string &, char);

int main(int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    // if file is opened
    if (file)
    {
        // keep looping
        while (true)
        {
            // if we are at the end of file, break out of inf loop
            if (file.eof()) break;
            
            // get the current line
            std::string line;
            std::getline(file, line);
            
            // get the last character from the line
            char ch = line.back();
            // remove that last char
            std::string copy = line.substr(0, line.length()-2);
            // get the position of the character
            int pos = CharPos(copy, ch);
            // output that position
            std::cout << pos << std::endl;
        }
    }
    
    // close the file
    file.close();
    
    return 0;
}

/*
    This method receives a string and a char 
    and returns the position of that char in 
    the string.
*/
int CharPos(const std::string &line, char ch)
{
    // set position to -1
    int pos = -1;
    // loop through each char in the string
    for (int i=0; i<line.length(); ++i)
    {
        // if we find a match, set pos to index
        if (line[i] == ch)
            pos = i;
    }
    
    // lastly, return the position.
    // if not found in string will be -1
    return pos;
}
