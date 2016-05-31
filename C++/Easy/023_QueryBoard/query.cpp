#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

enum INS { SetCol, SetRow, QueryCol, QueryRow };

void InitBoard (int [][256]);
INS GetInstructions(std::string &, std::vector<int> &);

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
            INS ins = GetInstructions(line, data);
            if (ins == SetCol || ins == SetRow)
                // call method to insert numbers
                std::cout << "Call Insert Method" << std::endl;
            else if (ins == QueryCol || ins == QueryRow)
                // call method to get the sum of Col or Row
                std::cout << "call query method" << std::endl;
                       
        }
    }
    
    file.close();
    return 0;
}

void InitBoard(int board[][256])
{
    for (int i=0; i<255; ++i)
        for (int j=0; j<255; ++j)
            board[i][j] = 0;
}

INS GetInstructions(std::string &line, std::vector<int> &data)
{
    INS ins;
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

    if (instruction == "SetCol")
            ins = SetCol;
    else if (instruction == "SetRow")
            ins = SetRow;
    else if (instruction == "QueryCol")
            ins = QueryCol;
    else if (instruction == "QueryRow")
            ins = QueryCol;

    
    data.push_back(a);
    data.push_back(b);
    return ins;
}