#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void splitNumbers (std::string &);
std::vector<std::string> *parseLine(std::string &);
void operate(int, int, char);

int main (int argc, char **argv)
{
    // if argc is less than 2, no file passed
    if (argc < 2)
        // output message
        printf("Usage: ./a.out file.txt\n");
        
    // grab file user passed to program
    std::fstream file (argv[1], std::ios::in);

    // if the file is good
    if (file)
    {
        // declare a string to hold each line
        std::string line;

        // while we can get a line from the file
        while (std::getline(file, line))
        {
            // call method on current line
            splitNumbers (line);
        }
    }

    return 0;
}

/*
    Splits Numbers based on string of ab+cd
    1234 ab+cd = 12 + 34
*/
void splitNumbers (std::string &line)
{
    // call method to parse the line into two parts
    std::vector<std::string> *ptr = parseLine(line);
    // get the reference of the vector
    std::vector<std::string> &data = *ptr;

    // first find the operator, + or -
    // and get the index where to split number
    char opr;
    int index;
    // loop over second string, will be something
    // like abc+defg
    for (int i=0; i<data[1].length(); i++)
    {
        // if we found the '+' operator
        if (data[1][i] == '+')
        {
            // assign operator and index
            opr = '+';
            index = i;
        }
        // if we found the '-' operator
        if (data[1][i] == '-')
        {
            // assign the opr and index
            opr = '-';
            index = i;
        }
    }
    // convert numbers to int
    std::string strNumX;
    for (int i=0; i<index; i++)
    {
        strNumX += data[0][i];
    }

    // convert the number to an int:
    // declare a string
    std::string strNumY;
    // loop through the length of the number
    for (int i=index; i<data[0].length(); i++)
        // append the current char to the string
        strNumY += data[0][i];
    
    // call method to operate
    operate(stoi(strNumX), stoi(strNumY), opr);
}

/*
    This method parses the line and returns
    the parsed values as a vector
*/
std::vector<std::string> *parseLine(std::string &line)
{
    // create a new vector
    std::vector<std::string> *data = new std::vector<std::string>;
    // initilize a string stream on the line
    std::stringstream ss(line);
    // declare a string to hold the token
    std::string token;

    // while we can get a token, separated by a ' '
    while (std::getline(ss, token, ' '))
        // push the data into the vector
        data->push_back(token);

    // return the vector
    return data;
}

/*
    This method conducts the operation
*/
void operate(int x, int y, char opr)
{
    // declare an integer for the answer
    int answer;
    // if the operator is a plus sign
    if (opr == '+')
        // add the values
        answer = x + y;
    // if the operator is a minus sign
    if (opr == '-')
        // subtract the values
        answer = x - y;
    // output the answer to stdout
    printf("%d\n", answer);
}