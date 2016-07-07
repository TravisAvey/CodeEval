#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <math.h>


class Distance
{
private:
    struct Vector2
    {
        int x;
        int y;
    };

    Vector2 coordsA;
    Vector2 coordsB;

    std::vector<int> mNums;

    void Parse (std::string data)
    {
        std::regex rgx("-?[0-9]+");
        std::smatch match;
        while ( std::regex_search (data, match, rgx) )
        {
            for (auto &x : match)
                mNums.push_back(std::stoi(x));
                
            data = match.suffix().str();
        }

       
        coordsA.x = mNums[0];
        coordsA.y = mNums[1];
        coordsB.x = mNums[2];
        coordsB.y = mNums[3];
        mNums.clear();
    }

public:
    void Init (std::string data)
    {
        Parse (data);
    }
    int GetDistance ()
    {
        int x = coordsB.x - coordsA.x;
        int y = coordsB.y - coordsA.y;
        double d = sqrt(x*x + y*x);
        return (int)d/1;
    }
};

int main (int argc, char *argv[])
{
    std::fstream file (argv[1], std::ios::in);
    
    if (file)
    {
        auto distance = new Distance();
        std::string line;
        while (std::getline(file, line))
        {
            distance->Init (line);
            std::cout << distance->GetDistance() << std::endl;
        }
    }
    return 0;
}
