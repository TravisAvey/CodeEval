#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


void Split (std::vector<std::string> &, const std::string &);
void Multiply (const std::vector<std::string> &);

int main (int argc, char **argv)
{
    // open the file
    std::fstream file (argv[1], std::ios::in);
    if (file)
    {
        // declare a string to hold each line
        std::string line;
        // get each line
        while (std::getline (file, line))
        {
            // init a vector 
            std::vector <std::string> data;
            // split the data
            Split (data, line);
            // multiply the two lists
            Multiply (data);
            
        }
    }
    return 0;
}

/*
    This method splits the data on the '|'
*/
void Split (std::vector<std::string> &vect, const std::string &line)
{
    // init a string stream on the line
    std::stringstream ss (line);
    // decalare a token to hold each parsed data
    std::string token;

    // while we can get the parsed data
    while (std::getline (ss, token, '|'))
        // add to the vector
        vect.push_back (token);
    
}

/*
    This method multiplies the two lists together
*/
void Multiply (const std::vector<std::string> &data)
{
    // get the first and second
    std::string first = data[0];
    std::string second = data[1];
    // second has a space 1 8 | 7 1
    //                         ^
    second = second.substr (1);

    // parse each list:
    std::vector <int> nums1;
    std::vector <int> nums2;
    std::stringstream ss1(first);
    std::string tok1;
    std::stringstream ss2(second);
    std::string tok2;
    while (std::getline (ss1, tok1, ' '))
        nums1.push_back (std::stoi(tok1));

    while (std::getline (ss2, tok2, ' '))
        nums2.push_back (std::stoi(tok2));

    // output the multiplied lists
    for (int i=0; i<nums1.size (); ++i)
        std::cout << nums1[i] * nums2[i] << ' ';
    
    std::cout << std::endl;
}