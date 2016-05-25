#include <iostream>
#include <fstream>
#include <string>

int CharPos(const std::string &, char);

int main(int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file)
    {
        while (true)
        {
            if (file.eof()) break;
            
            std::string line;
            std::getline(file, line);
            
            char ch = line.back();
            std::string copy = line.substr(0, line.length()-1);
            int pos = CharPos(copy, ch);
            
            if (pos != -1)
                std::cout << pos << std::endl;
        }
    }
    return 0;
}

int CharPos(const std::string &line, char ch)
{
    int pos = -1;
    for (int i=0; i<line.length(); ++i)
    {
        if (line[i] == ch)
            pos = i;
    }
    return pos;
    //return line.find_first_of(ch);
}
