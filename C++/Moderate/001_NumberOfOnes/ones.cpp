#include <iostream>
#include <fstream>

int main (int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    
    if (file)
    {
        std::string data;
        while (std::getline(file, data))
        {
            unsigned int num = std::stoi(data);
            while (num > 0)
            {
                int b = num & 1;
                std::cout << b;
                num >>= 1;
            }
            std::cout << std::endl;
        }
    }
    file.close();
    return 0;
}
