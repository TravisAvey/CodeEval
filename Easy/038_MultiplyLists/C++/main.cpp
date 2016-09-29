#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

enum FL {INT, STR};

template <class T>
void Split (std::vector<T> &, const std::string &, const char &, FL);
void Multiply (const std::vector<std::string> &);

int main (int argc, char **argv)
{
    std::fstream file (argv[1], std::ios::in);
    if (file)
    {
        std::string line;
        while (std::getline (file, line))
        {
            std::vector <std::string> data;
            Split (data, line, '|', FL::STR);
            Multiply (data);
            
        }
    }
    return 0;
}

template <class T>
void Split (std::vector<T> &vect, const std::string &line, const char &ch, FL fl)
{
    std::stringstream ss (line);
    std::string token;

    while (std::getline (ss, token, ch))
    {
        if (fl == INT)   
            vect.push_back (std::stoi (token));
        else
            vect.push_back (token);
    }
}

void Multiply (const std::vector<std::string> &data)
{
    std::string first = data[0];
    std::string second = data[1];

    std::cout << "first :" << first << " second :" << second << std::endl;

    std::vector <int> nums1;
    std::vector <int> nums2;

    Split (nums1, first, ' ');
    Split (nums2, second, ' ');

    /*
    while (std::getline (ss1, tok1, ' '))
        nums1.push_back (std::stoi(tok1));

    while (std::getline (ss2, tok2, ' '))
        nums2.push_back (std::stoi(tok2));

    for (int i=0; i<nums1.size (); ++i)
    {
        std::cout << nums1[i] * nums2[i] << ' ';
    }
    */
    std::cout << std::endl;
}