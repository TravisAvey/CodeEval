#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <string>

void SplitLine(std::vector<std::string> &, std::string);
void Interect(std::vector<std::string> &);
std::vector<int> Split(std::string, char);

int main(int argc, char *argv[])
{
    std::clock_t begin = std::clock();
    
    std::fstream file(argv[1], std::ios::in);
    
    if (file)
    {
        std::string line;
        while(std::getline(file, line))
        {
            std::vector<std::string> a;
            SplitLine(a, line);
            Interect(a);
        }
        
    }
    file.close();
    
    std::clock_t end = std::clock();
    double time = (double)(end-begin) / CLOCKS_PER_SEC;
    std::printf("Time: %.9f\n",time);
    
    return 0;
}

void SplitLine(std::vector<std::string> &l, std::string line)
{
    std::stringstream ss(line);
    std::string a;

    while(std::getline(ss, a, ';'))
        l.push_back(a);


}

void Interect(std::vector<std::string> &data)
{
    std::string first = data.front();
    std::string last = data.back();
    std::vector<int> a = Split(first, ',');
    std::vector<int> b = Split(last, ',');
    
    std::vector<int> result;
    
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            result.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] > b[j])
            j++;
        else
            i++;
    }
    
    if (result.size() > 0)
    {
        std::string answer;
        for (auto i : result)
            answer += std::to_string(i) + ',';
        answer.pop_back();
        std::cout << answer << std::endl;
    }
    else
        std::cout << std::endl;
}

std::vector<int> Split(std::string line, char delimeter)
{
    std::vector<int> data;
    
    std::stringstream ss(line);
    std::string token;
    
    while(std::getline(ss, token, delimeter))
        data.push_back(std::stoi(token));
        
    return data;
}
