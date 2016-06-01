#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

enum INS { SetCol, SetRow, QueryCol, QueryRow };

void InitBoard (int [256][256]);
INS GetInstructions(std::string &, std::vector<int> &);
void InsertNumbers(int [256][256], std::vector<int> &, INS);
uint32_t QueryBoard(int [256][256], std::vector<int> &, INS);
void PrintBoard(int [256][256]);

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
                InsertNumbers(board, data, ins);
            else if (ins == QueryCol || ins == QueryRow)
                // call method to get the sum of Col or Row
                std::cout << QueryBoard(board, data, ins) << std::endl;
                       
        }
        //PrintBoard(board);
    }
    
    file.close();
    return 0;
}

void InitBoard(int board[256][256])
{
    for (int i=0; i<256; ++i)
        for (int j=0; j<256; ++j)
            board[i][j] = 0;
}

INS GetInstructions(std::string &line, std::vector<int> &data)
{
    INS ins = SetCol;
    
    std::stringstream ss(line);
    
    std::string token;
    
    std::string instruction;
    
    int a = 0;
    int b = 0;
    while (ss.good())
    {
        ss >> instruction;
        ss >> a;
        
        if (instruction == "QueryCol" || instruction == "QueryRow")
            break;
        
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

void InsertNumbers(int board[256][256], std::vector<int> & data, INS instruction)
{
    int index = data[0];
    int value = data[1];
    
    if (instruction == SetRow)
    {
        for (int i=0; i<index; ++i)
            for (int j=0; j<256; ++i)
                board[i][j] = value;
        
    }
    else if (instruction == SetCol)
    {
        for (int i=0; i<256; ++i)
            for (int j=0; j<index; ++j)
                board[j][i] = value;
    }
}

uint32_t QueryBoard(int board[256][256], std::vector<int> &data, INS instruction)
{
    int index = data[0];
    uint32_t sum = 0;
    if (instruction == QueryRow)
    {
        // sum each value in row data[0]
        for (int i=0; i<index; ++i)
        {
            for (int j=0; j<256; j++)
                sum += board[i][j];
        }
    }
    else if (instruction == QueryCol)
    {
        for (int i=0; i<256; ++i)
        {
            for (int j=0; j<index; ++j)
                sum += board[j][i];
        }
    }
}

void PrintBoard(int board[256][256])
{
    for (int i=0; i<256; ++i)
    {
        for (int j=0; j<256; ++j)
            std::cout << board[i][j] << ' ';
        std::cout << std::endl;
    }
}