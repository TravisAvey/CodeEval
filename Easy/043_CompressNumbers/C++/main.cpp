#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void Compress (std::string &);

int main (int argc, char **argv)
{
    // if argc is less than 2, no file passed
    if (argc < 2)
        // output message
        printf("Usage: ./a.out file.txt\n");
        
    // grab file user passed to program
    std::fstream file (argv[1], std::ios::in);

    // if the file is good
    if (file)
    {
        // declare a string to hold each line
        std::string line;

        // while we can get a line from the file
        while (std::getline(file, line))
        {
            // call method on current line
            Compress (line);
        }
    }

    return 0;
}

/*
    This method compresses a sequence of numbers
    4 4 4 5 5 11 11 9
    as
    3 4 2 5 2 11 1 9
*/
    void Compress (std::string &line)
    {
        // declare a vector to hold the numbers
        std::vector<int> nums;
        
        // initialize a string stream on the line
        std::stringstream ss (line);
        // declare a string to hold each token
        std::string token;
        
        // while we can get a token from the string stream
        while (std::getline (ss, token, ' '))
        {
            // parse the token to an int
            int num = std::stoi (token);
            // place the int in the number vector
            nums.push_back(num);
        }

        // init a counter to 1
        int count = 1;
        // loop through the numbers, but not very last
        for (int i=0; i<nums.size()-1; i++)
        {
            // if the current is the same as the next
            if (nums[i] == nums[i+1])
                // increment the counter
                count++;
        else
        {
            // else, we print out the count of the number
            printf("%d %d ", count, nums[i]);
            // re-init counter back to 1
            count = 1;
        }
    }
   // finally print out the final count number
   printf("%d %d\n", count, nums[nums.size()-1]); 
}