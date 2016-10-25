#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void Compress (std::string &);

int main (int argc, char **argv)
{
    std::fstream file (argv[1], std::ios::in);

    if (file)
    {
        std::string line;
        while (std::getline(file, line))
        {
            Compress (line);
        }
    }

    return 0;
}

void Compress (std::string &line)
{
    std::vector<int> nums;
    std::vector<int> count;
    std::stringstream ss (line);
    std::string token;
    int i = 1;
    int prevNum = 0;

    while (std::getline (ss, token, ' '))
    {
        int num = std::stoi (token);
        // logic fails here: num will change on first time,
        // therefore the first count will be 1 regardless..
        if (num != prevNum)
        {
            nums.push_back (std::stoi (token));
            count.push_back (i);
            i = 1;
        }
        i++;
        prevNum = num;
    }

    for (auto n : nums)
        std::cout << n << std::endl;
    std::cout << "------\n";
    for (auto c : count)
        std::cout << c << std::endl;
    
}