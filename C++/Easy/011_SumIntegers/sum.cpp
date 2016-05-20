#include <iostream>
#include <fstream>
#include <vector>

void PrintSum(std::vector<int>);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file)
    {
        std::string num;
        std::vector<int> nums;
        while(std::getline(file, num))
            nums.push_back(std::stoi(num));
        PrintSum(nums);
    }
    file.close();
    return 0;
}

void PrintSum(std::vector<int> data)
{
    int sum = 0;
    for (int i : data)
        sum += i;
    
    std::printf("%d\n",sum);
}
