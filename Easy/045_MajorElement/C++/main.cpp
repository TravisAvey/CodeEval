#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

void majorElement (std::string &);

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
            majorElement(line);
        }
    }

    return 0;
}

/*
    This method takes the line and finds the major element
*/
void majorElement(std::string &line)
{

    // create a map to hold the numbers and the count
    std::map<std::string, int> map;
    // init a string stream on the line
    std::stringstream ss(line);
    // declare a token
    std::string token;
    // init a count to 0
    int count = 0;
    // while we can parse the line on a ','
    while(std::getline(ss, token, ','))
    {
        // initialize a map iterator
        std::map<std::string, int>::iterator it;
        // find the token
        it = map.find(token);
        // if found
        if (it != map.end())
        {
            // get the current count
            int count = map[token];
            // update count
            map[token] = ++count;
        }
        else
        {
            // else, set count to 1
            map[token] = 1;
        }
        // increment the count
        count++;
    }
    
    // declare a string to hold the num
    std::string num;
    // declare a boolean to false, we haven't found the num
    bool found = false;
    // init a iterator at the begining of the map
    std::map<std::string, int>::iterator it = map.begin();
    // loop through the map
    for (std::pair<std::string, int>ele : map)
    {
        // if the count is atleast 1/2 the length of numbers
        if (ele.second >= (count/2))
        {
            // set the num
            num = ele.first;
            // we found one
            found = true;
        }
    }
    // if found, output the num, else output none to stdout
    if (found)
        std::cout << num << std::endl;
    else
        std::cout << "None" << std::endl;

}
