#include <iostream>
#include <fstream>

int Sum(int, const int &);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    
    if (file.good())
    {
        std::string line;
        while (std::getline(file, line))
        {
            int len = line.length();
            int num = std::stoi(line);
            std::cout << Sum(num, len) << std::endl;
        }
    }
    
    file.close();
    
    return 0;
}

int Sum(int num, const int &len)
{
    int n = 0;
    int sum = 0;
    for (int i=1; i<=len; ++i)
    {
        n = num % 10;
        num /= 10;
        sum += n;
    }
    
    return sum;
}
