#include <iostream>
#include <fstream>
#include <string>

void SwapCase (std::string &);

int main (int argc, char *argv[])
{
    // open the file
    std::fstream file (argv[1], std::ios::in);

    // if file is good
    if (file)
    {
        // declare a string to hold the line
        std::string line;
        // while we can get a line from the file
        while (std::getline(file, line))
        {
            // call the swap case method
            SwapCase (line);
            // output the swapped case string
            std::cout << line << std::endl;
        }

    }
    // close the file
    file.close();
    return 0;
}

/*
    This method swaps the case on the string passed
    to the method
*/
void SwapCase (std::string &words)
{
    // for each char in the string
    for (auto i=0; i<words.length(); ++i)
    {
        // cache the character
        char ch = words[i];

        // if the char is not an alpha, continue to next char
        if ( !isalpha(ch) )
            continue;
        
        // swap the char case
        if ( isupper (ch) )
            words[i] = tolower (ch);
        else if ( islower (ch) )
            words[i] = toupper (ch);
    }
}
