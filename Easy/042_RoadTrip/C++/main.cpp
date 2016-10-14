#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

void ExtractData (std::vector<int> &, std::string &);
void PrintDistances (std::vector<int> &);

int main (int argc, char **argv)
{
    std::fstream file (argv[1], std::ios::in);

    if (file)
    {
        std::string line;
        
        while (std::getline(file, line))
        {
            std::vector<int> miles;
            ExtractData (miles, line);
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

    PrintDistances (vect);
}

void PrintDistances (std::vector<int> &vect)
{
    std::sort ( vect.begin (), vect.end () );
    
    int dist = 0;
    std::string result;
    for (auto v : vect)
    {
        result += std::to_string (v-dist);
        result += ',';
        dist = v;
    }
    std::cout << result.substr (0, result.length()-1) << std::endl;

}
