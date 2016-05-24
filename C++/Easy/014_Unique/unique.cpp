#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

void Split(std::list<int> &, std::string, char);
void PrintUnique(const std::list<int> &);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    
    if (file)
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::list<int> data;
            Split(data, line, ',');
            
            PrintUnique(data);
        }
    }
    
    file.close();
    return 0;
}

void Split(std::list<int> &v, std::string line, char delimeter)
{
    std::stringstream ss(line);
    std::string data;
    
    while(std::getline(ss, data, delimeter))
        v.push_back(std::stoi(data));
        
}

void PrintUnique(const std::list<int> &v)
{
    std::list<int> output(v);
   
    output.unique();
    
    std::string result;
    
    for (int j : output)
        result += std::to_string(j) + ',';
        
    result.pop_back();
        
    std::cout << result << std::endl;
}
