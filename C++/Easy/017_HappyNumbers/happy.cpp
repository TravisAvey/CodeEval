#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> GetDigits(int);
bool SquareOfDigits(int);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    
    if (file)
    {
        std::string line;
        while(std::getline(file, line))
        {
            bool happy = SquareOfDigits(std::stoi(line));
            std::cout << happy << std::endl;
        }
    }
    
    file.close();
    return 0;
}

bool SquareOfDigits(int num)
{
    if (num == 1) return true;
    
    int n = num;
    int count = 0;
    // ?? not sure about 20 iterations to find if num == happy or not
    while (count <20)
    {
        int sum = 0;
        std::vector<int> digits = GetDigits(n);
        for (int i : digits)
            sum += i * i;
        
        if (sum == 1) return true;
        n = sum;
        count++;
    }
    
    return false;
}

std::vector<int> GetDigits(int val)
{
    std::vector<int> digits;
    
    for ( ; val > 0; val /= 10)
    {
        digits.push_back(val%10);
    }
    
    return digits;
}
