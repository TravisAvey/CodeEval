#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <climits>
class LowestUnique
{
private:
    std::map<int, int> nums;
    void InitMap ()
    {
        nums[1] = 0;
        nums[2] = 0;
        nums[3] = 0;
        nums[4] = 0;
        nums[5] = 0;
        nums[6] = 0;
        nums[7] = 0;
        nums[8] = 0;
        nums[9] = 0;
    }

     void GetNumbers (std::string line)
    {
        std::stringstream ss (line);
        std::string token;

        while (std::getline (ss, token, ' '))
        {
            int num = std::stoi (token);
            int count = nums[num];
            nums[num] = ++count;
        }
    }
public:
    LowestUnique (std::string line)
    {
        InitMap ();
        GetNumbers (line);
    }

    int GetLowest ()
    {
        int count = INT_MAX;
        int lo = 0;
        for (int i=1; i<=9; ++i)
        {
            int num = nums[i];
            if (num == 0)
                continue;
            if (num < count)
            {
                lo = i;
                count = num;
            }
        }

        if (lo == INT_MAX)
            return 0;
        else
            return lo;
    }
};

int main (int argc, char *argv[])
{

    std::fstream file (argv[1], std::ios::in);

    if (file)
    {

        std::string line;
        while (std::getline(file, line))
        {
            auto lowest = new LowestUnique (line);
            
            std::cout << lowest->GetLowest () << std::endl;
            
        }
    }

    file.close();
    return 0;
}
