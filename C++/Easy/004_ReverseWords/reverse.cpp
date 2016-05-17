#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>

void ReverseWords(const std::string &);
std::stack<std::string> SplitString(const std::string &);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file.good())
    {
        std::string line;
        while (std::getline(file, line))
            ReverseWords(line);
    }
    file.close();
    return 0;
}

void ReverseWords(const std::string &line)
{
    std::stack<std::string> words = SplitString(line);
    
    int len = words.size();
    
    if (len == 0) return;
    
    std::string result = "";
   
    for (int i=0; i<len; ++i)
    {
        result += words.top() + " ";
            
        words.pop();
    }
    
    size_t endpos = result.find_last_not_of(" \t");
    if( std::string::npos != endpos )
    {
        result = result.substr( 0, endpos+1 );
    }
    
    std::cout << result << std::endl;
}

std::stack<std::string> SplitString(const std::string &line)
{
    std::stack<std::string> words;
    std::stringstream ss(line);
    std::string token;
    
    while (std::getline(ss, token, ' '))
        words.push(token);
        
   return words;
}
