#include <iostream>

void printOdds(int x, int y)
{
    for (int i=x; i<=y; i+=2)
        std::cout << i << std::endl;
}

int main(int argc, char *argv[]) 
{
    printOdds(1, 99);
    
    return 0;
} 
