#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

class LowestUnique
{
private:
    std::map<int, int> nums;
    void InitMap (int n)
    {
        
    }
};

void GetNumbers (std::vector<int> &, std::string);
int GetUnique (const std::vector<int> &);
void InitMap (std::map<int, int> &, int);

int main (int argc, char *argv[])
{

    std::fstream file (argv[1], std::ios::in);

    if (file)
    {

        std::string line;
        while (std::getline(file, line))
        {
            std::vector<int> numbers;
            GetNumbers (numbers, line);
            
        }
    }

    file.close();
    return 0;
}

void GetNumbers (std::vector<int> &vect, std::string line)
{
    std::stringstream ss(line);
    std::string token;

    while (std::getline (ss, token, ' '))
        vect.push_back (std::stoi(token));
}

int GetUnique (const std::vector<int> &vect)
{
    int lowest = 10;
    std::map <int, int> numCount;
    // loop over each number
    for (auto i : vect)
    {
        // 
    }

    return lowest;
}

void InitMap (std::map<int, int> nums, int n)
{

}