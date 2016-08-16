#include <iostream>
#include <fstream>
#include <vector>

void FindLongest (std::vector<std::string> &);

int main (int argc, char *argv[])
{
    std::fstream file (argv[1], std::ios::in);

    if (file)
    {
        std::vector<std::string> lines;
        std::string line;

        while (std::getline (file, line))
            lines.push_back (line);

        FindLongest (lines);
    }

    return EXIT_SUCCESS;
}

void FindLongest (std::vector<std::string> &nums)
{
    int n = std::stoi(nums[0]);
    
    std::vector<std::string> longest;
    std::vector<int> lengths;

    for (auto s : nums)
    {
        std::cout << s << std::endl;
    }
}
