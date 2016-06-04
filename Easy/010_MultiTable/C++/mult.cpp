#include <iostream>
#include <iomanip>
#include <vector>

void PrintTable();

int main()
{
    PrintTable();
    return 0;
}

void PrintTable()
{
    // init outer column to 1
    int i=1;
    // while i is less than 12
    while(i<=12)
    {
        // loop through 1-12 for each i
        for (int j=1; j<=12; ++j)
            // multiply and display the row
            std::cout << std::setw(4) << std::right << i*j;
        // increment i
        i++;
        // output a new line for the next row
        std::cout << std::endl;
    }
}

