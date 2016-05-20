#include <iostream>
#include <fstream>
#include <vector>

void PrintSum(std::vector<int>);

int main(int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    
    // check if file is opened (not null)
    if (file)
    {
        // declare string to hold each line
        std::string num;
        // declare vector to hold all the numbers in file
        std::vector<int> nums;
        // while we can get a line from file
        while(std::getline(file, num))
            // store number (convert to int :: stoi)
            nums.push_back(std::stoi(num));
        // call helper method to print the sum
        PrintSum(nums);
    }
    // file done? close it.
    file.close();
    return 0;
}

/*
    Helper method prints the sum of
    each number passed in vector
*/
void PrintSum(std::vector<int> data)
{
    int sum = 0;
    for (int i : data)
        sum += i;
    
    std::printf("%d\n",sum);
}
