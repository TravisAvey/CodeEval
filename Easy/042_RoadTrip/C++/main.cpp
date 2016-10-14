#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

void ExtractData (std::string &);
void PrintDistances (std::vector<int> &);

int main (int argc, char **argv)
{
    // open file
    std::fstream file (argv[1], std::ios::in);
    // if can be opened
    if (file)
    {
        // init line
        std::string line;
        while (std::getline(file, line))
        {
            // extract the data
            ExtractData (line);
        }
    }

    return 0;
}

// This method Extracts the data and calls method to print the results
void ExtractData (std::string &line)
{
    auto vect = new std::vector<int>;
    // init a string stream on the line
    std::stringstream ss1(line);
    // init a string
    std::string tok1;
    // while we can get a token, separated by a space
    while (std::getline (ss1, tok1, ' '))
    {
        // find the ','
        auto a = tok1.find (',');
        // find the ';'
        auto b = tok1.find (';');
        // the number is in between , & ;
        vect->push_back (std::stoi ( tok1.substr (a+1, b-a-1)) );
    }
    // call method to print the distances
    PrintDistances (*vect);

    delete vect;
}

// This method prints out the distances between the cities
void PrintDistances (std::vector<int> &vect)
{
    // need to sort (possible reason for more memory, lower pts)
    std::sort ( vect.begin (), vect.end () );
    // init a distance variable and result string
    int dist = 0;
    std::string result;
    // for each item in the vector
    for (auto v : vect)
    {
        // add to the string the distance to v from the last point
        result += std::to_string (v-dist);
        // add a comma
        result += ',';
        // set the distance to the current point
        dist = v;
    }
    // output the results, removing last comma
    std::cout << result.substr (0, result.length()-1) << std::endl;

}
