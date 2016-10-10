#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class MixedContent
{
private:
    std::vector <int> nums;
    std::vector <std::string> words;

public:
    
    void ExtractData (const std::string & line)
    {
        std::stringstream ss (line);
        std::string token;

        while (std::getline (ss, token, ','))
        {
            int num;
            std::string word;
            //if ( (int num = std::stoi (token) != std::exceptions )
              //  nums.push_back (num);


        }
    }

};


int main (int argc, char **argv)
{
    std::fstream file (argv[1], std::ios::in);
    if (file)
    {
        MixedContent mc;
        std::string line;
        while (std::getline (file, line))
            std::cout << line << std::endl;
    }

    return 0;
}
