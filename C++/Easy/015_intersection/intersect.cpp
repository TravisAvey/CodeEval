#include <iostream>
#include <fstream>
#include <list>

std::list<int> Split(std::list<int> &, std::string, char);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    
    if (file)
    {
        std::string line;
        while(std::getline(file, line))
        {
            std::list<int> a;
            std::list<int> b = Split(a, line, ',');
        }
        
    }
    file.close();
    return 0;
}

std::list<int> Split(std::list<int> &l, std::string line, char delimeter)
{
    std::list<int> d;
    std::string a;
    std::string b;
    while(std::getline(line, a, ';'))
        std::cout << a << std::endl;
    
    return d;
}