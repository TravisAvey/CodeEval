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
    int i=1;
    while(i<=12)
    {
            
        for (int j=1; j<=12; ++j)
        {
            std::cout << std::setw(4) << std::right << i*j;
        }
        i++;
        std::cout << "\n";
    }
}

