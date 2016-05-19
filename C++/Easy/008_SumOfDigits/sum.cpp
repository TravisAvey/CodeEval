#include <iostream>
#include <fstream>

int Sum(int, const int &);

int main(int argc, char *argv[])
{
    // open file passed to program
    std::fstream file(argv[1], std::ios::in);
    
    // if file is opened and good to go
    if (file.good())
    {
        // declare string and get each line, put into string
        std::string line;
        while (std::getline(file, line))
        {
            // get the number of digits
            int len = line.length();
            // convert string to an int
            int num = std::stoi(line);
            // output the sum of each digit
            std::cout << Sum(num, len) << std::endl;
        }
    }
    
    // done with file, closed
    file.close();
    
    return 0;
}

/*
    This method returns the sum of
    each digit from passed in number
*/
int Sum(int num, const int &len)
{
    // init an int and sum to 0
    int n = 0;
    int sum = 0;
    
    // for each digit in number
    for (int i=1; i<=len; ++i)
    {
        // get last digit off number
        n = num % 10;
        // divide by 10 (after above modulus number will have a zero at end)
        num /= 10;
        // add the digit to sum
        sum += n;
    }
    
    // return sum
    return sum;
}
