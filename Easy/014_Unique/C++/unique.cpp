#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

void Split(std::list<int> &, std::string, char);
void PrintUnique(const std::list<int> &);

int main(int argc, char *argv[])
{
    // open file passed to program
    std::fstream file(argv[1], std::ios::in);
    
    // if file opened
    if (file)
    {
        // declare string
        std::string line;
        // get each line from the file
        while (std::getline(file, line))
        {
            // declare a list
            std::list<int> data;
            // call method do split up the string on ','
            Split(data, line, ',');
            // call method to print out the unique 
            PrintUnique(data);
        }
    }
    
    // done with file, close it
    file.close();
    return 0;
}

/*
    Method to split up a string on the passed in delimeter
    and put into the list
*/
void Split(std::list<int> &v, std::string line, char delimeter)
{
    // init a string stream on the string
    std::stringstream ss(line);
    // declare a string to hold the data
    std::string data;
    
    // while can get the data from the string stream on delimeter
    // push back into the list
    while(std::getline(ss, data, delimeter))
        v.push_back(std::stoi(data)); 
}

/*
    This method prints out the unique ints
    in the list
*/
void PrintUnique(const std::list<int> &v)
{
    // init a new list copy in passed in list
    std::list<int> output(v);
   
    // call method unique() on list
    output.unique();
    
    // declare a string for the results
    std::string result;
    
    // for each int in the output
    for (int j : output)
        // call to string on each int and add the ','
        result += std::to_string(j) + ',';
    
    // remove last ','
    result.pop_back();
    // output the unique list
    std::cout << result << std::endl;
}
