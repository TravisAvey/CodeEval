#include <iostream>
#include <fstream>

/*
    Armstrong number is an n-digit number equal to the sum of the nth powers of its digits
    
    6 : 6^1 = 6
    1634 : 1^4 + 6^4 + 3^4 + 4^4 = 1634
*/

int main (int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file)
    {
        std::string data;
        while (std::getline(file, data))
        {
            std::cout << data << std::endl;
        }
    }
    file.close();
    return 0;
}
