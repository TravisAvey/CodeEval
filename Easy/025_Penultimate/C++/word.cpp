#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void Parse(std::string, std::vector<std::string> &, char);

int main (int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    if (file)
    {
        // get each line
        std::string line;
        while (std::getline(file, line))
        {
            // parse the line
            std::vector<std::string> words;
            Parse(line, words, ' ');
            
            int len = words.size();
            // print the second to last word (last = len -1, 2nd = len -2)
            std::cout << words[len-2] << std::endl;
        }
    }
    return 0;
}

/*
    THis method parses the string on the char, and puts them into the
    string vector
*/
void Parse(std::string line, std::vector<std::string> & words, char ch)
{
    std::stringstream ss(line);
    std::string token;
    
    while (std::getline(ss, token, ch))
        words.push_back(token);
}
