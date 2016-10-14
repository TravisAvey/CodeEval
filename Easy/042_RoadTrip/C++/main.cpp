#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

void ExtractData (std::vector<int> &, std::string &);
void PrintDistances (std::vector<int> &);

int main (int argc, char **argv)
{
    std::fstream file (argv[1], std::ios::in);

    if (file)
    {
        std::string line;
        std::vector<int> miles;
        while (std::getline(file, line))
        {
            ExtractData (miles, line);
            PrintDistances (miles);
        }
    }

    return 0;
}

void ExtractData (std::vector<int> &vect, std::string &line)
{
    std::stringstream ss1(line);
    std::string tok1;
    std::vector<std::string> rawD;

    while (std::getline (ss1, tok1, ' '))
        rawD.push_back (tok1);
    
    for (auto data : rawD)
    {
        auto a = data.find (',');
        auto b = data.find (';');
        
        vect.push_back (std::stoi ( data.substr (a+1, b-a-1)) );
    }
}

void PrintDistances (std::vector<int> &vect)
{
    std::sort ( vect.begin (), vect.end () );
    
    
}
