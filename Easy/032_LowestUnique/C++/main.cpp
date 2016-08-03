#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>


class LowestUnique
{
private:
    std::map<int, int> nums;
    std::vector<int> input;
    /*
        This method initializes the map that holds the count
        of each integer
    */
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

    /*
        This method gets the numbers from the string
        of data passed to the method
    */
     void GetNumbers (std::string line)
    {
        // create a string stream on the line
        std::stringstream ss (line);
        // declare a token to hold each int
        std::string token;

        // init an index counter
        int i=0;
        // while we can get a token from the string stream
        while (std::getline (ss, token, ' '))
        {
            // convert the token to an int
            int num = std::stoi (token);
            // get the count from the nums map
            int count = nums[num];
            // increment the count based on the num
            nums[num] = ++count;
            // push back that number into the input vector
            input.push_back(num);
        }
    }
public:
    // public constructor that initializes the object
    LowestUnique (std::string line)
    {
        InitMap ();
        GetNumbers (line);
    }

    /*
        GetLowest finds the first number with only 1 in the count.
        Then takes that number and locates the index in the input vector
    */
    int GetLowest ()
    {
        // init a var to hold the lowest number
        int lowestNum = 0;
        // first number with only one is the winner
        for (int i=1; i<=9; ++i)
        {
            // if this num has only one in the counter
            if (nums[i] == 1)
            {
                // set the num to lowestNum and break
                lowestNum = i;
                break;
            }
        }
        // if the lowest num is 0, we dont have a unique num return 0
        if (lowestNum == 0)
            return 0;
        else
        {
            // init an index counter
            int index = 0;
            // for each item in the input vector
            for (auto i : input)
            {
                // increment the index
                index++;
                // if the i is the lowestNume, return the index
                if (i == lowestNum)
                    return index;
            }
        }

        // just to be safe, return 0 here also
        return 0;
    }
};

int main (int argc, char *argv[])
{
    // open the file
    std::fstream file (argv[1], std::ios::in);

    // if the file is good
    if (file)
    {
        // declare a string to hold each line
        std::string line;
        // while we can get a line from the file
        while (std::getline(file, line))
        {
            // init a new LowestUnique object with the ine
            auto lowest = new LowestUnique (line);
            
            // output the lowest unique index
            std::cout << lowest->GetLowest () << std::endl;

            // free up memory
            delete lowest;    
        }

    }

    // close the file
    file.close();
    return 0;
}
