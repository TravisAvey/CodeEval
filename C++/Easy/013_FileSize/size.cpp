#include <iostream>
#include <fstream>


int main(int arc, char *argv[])
{
    // open file
    // ate opens file and moves cursor to end
    // binary is binary mode
    std::ifstream fileCheck(argv[1], std::ifstream::ate | std::ifstream::binary);
    // output how many bytes: tellg() :: input position
    // since we opend file in binary and seeked to the end
    // tellg will report the position in how many bytes
    std::cout << fileCheck.tellg() << std::endl;
    
    // close the file
    fileCheck.close();
    
    return 0;
}
