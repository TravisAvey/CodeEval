#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

enum Instructions { SetCol, SetRow, QueryCol, QueryRow };

void InitBoard (int [][256]);
Instructions GetInstructions(std::string &, std::vector<int> &);

int main (int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    
    if (file)
    {
        
        std::string line;
        int board[256][256];
        InitBoard(board);
        while (std::getline(file, line))
        {
            std::vector<int> data;
            GetInstructions(line, data);
                       
        }
    }
    
    file.close();
    return 0;
}

void InitBoard(int board[][256])
{
    for (int i=0; i<255; ++i)
    {
        for (int j=0; j<255; ++j)
            board[i][j] = 0;
    }
}

Instructions GetInstructions(std::string &line, std::vector<int> &data)
{
    Instructions ins;
    ins = SetCol;
    std::stringstream ss(line);
    std::string token;
    std::string instruction;
    int a;
    int b;
    while (ss.good())
    {
        ss >> instruction;
        ss >> a;
        if (instruction == "QueryCol" || instruction == "QueryRow")
        {
            b = 0;
            break;
        }
        ss >> b;
    }
    std::cout << instruction << ' ' << a << ' ' << b << std::endl;
    return ins;
}