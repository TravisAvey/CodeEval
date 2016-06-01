#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// enum for instructions, to set or query
enum INS { SetCol, SetRow, QueryCol, QueryRow };

void InitBoard (int [][256]);

INS GetInstructions(std::string &, std::vector<int> &);

void InsertRow(int[][256], std::vector<int> &);
void InsertCol(int[][256], std::vector<int> &);

int SumRow(int [][256], int);
int SumCol(int [][256], int);


int main (int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    
    // if file is opened
    if (file)
    {
        // declare a 256x256 matrix
        int board[256][256];
        // init the matrix to 0 for each cell
        InitBoard(board);
        // get each line from the file
        std::string line;
        while (std::getline(file, line))
        {
            // declare a vector to hold the row/col and vals
            std::vector<int> data;
            // get the instructions and row/col, vals
            INS ins = GetInstructions(line, data);
            
            // check which instruction then set or query 
            if (ins == SetRow)
                InsertRow(board, data);
            else if (ins == SetCol)
                InsertCol(board, data);
            else if (ins == QueryRow)
                std::cout << SumRow(board, data[0]) << std::endl;
            else if (ins == QueryCol)
                std::cout << SumCol(board, data[0]) << std::endl;                   
        }
    }
    // close file
    file.close();
    
    return 0;
}

/*
    This method sets each cell in the matrix
    to 0
*/
void InitBoard(int board[][256])
{
    for (int i=0; i<256; ++i)
        for (int j=0; j<256; ++j)
            board[i][j] = 0;
}

/*
    This method parses the string and returns an Enum
    for the instructions to set or query the matrix.  It
    fills the vector with the data from the string
*/
INS GetInstructions(std::string &line, std::vector<int> &data)
{
    // init instruction enum
    INS ins = SetCol;
    
    // init a stringstream on the string
    std::stringstream ss(line);
    
    // declare the following to hold variables:
    std::string instruction;
    int a = 0;
    int b = 0;
    
    // while we can get data from the stringstream
    while (ss.good())
    {
        // get the instruction
        ss >> instruction;
        // get the first int
        ss >> a;
        
        // if we are going to query, then we are done with this string
        if (instruction == "QueryCol" || instruction == "QueryRow")
            break;
        
        // get the second int
        ss >> b;
    }

    // check which instruction, set the enum
    if (instruction == "SetCol")
            ins = SetCol;
    else if (instruction == "SetRow")
            ins = SetRow;
    else if (instruction == "QueryCol")
            ins = QueryCol;
    else if (instruction == "QueryRow")
            ins = QueryRow;
    
    // put the data in the vector
    data.push_back(a);
    data.push_back(b);
    // return the instruction
    return ins;
}

/*
    This method inserts the row into the board 
    O(n)
*/
void InsertRow(int board[][256], std::vector<int> &data)
{
    // the row is the first 
    int row = data[0];
    // the val is the second
    int val = data[1];
    // put the val into the row
    for (int i=0; i<256; ++i)
        board[row][i] = val;
}

/*
    This method insert a col of vals into the board
    O(n)
*/
void InsertCol(int board[][256], std::vector<int> &data)
{
    // get the data from the vector
    int col = data[0];
    int val = data[1];
    // insert into the board
    for (int i=0; i<256; ++i)
        board[i][col] = val;
}

/*
    This method returns the sums of the specified row
    O(n) 
*/
int SumRow(int board[][256], int row)
{
    // init sum
    int sum = 0;
    // sum the row
    for (int i=0; i<256; ++i)
        sum += board[row][i];
    // return the sum of the row
    return sum;
}

/*
    This method return the sum of the specified col
*/
int SumCol(int board[][256], int col)
{
    // init the sum
    int sum = 0;
    // sum the col
    for (int i=0; i<256; ++i)
        sum += board[i][col];
    // return the sum of the col
    return sum;
}

