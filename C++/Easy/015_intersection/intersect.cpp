#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <string>

void SplitLine(std::vector<std::string> &, std::string);
void Interect(std::vector<std::string> &);
std::vector<int> Split(std::string, char);

int main(int argc, char *argv[])
{
    // was curious how fast this one was going to take
    // start the timer
    std::clock_t begin = std::clock();
    
    // open the file in argv[1]
    std::fstream file(argv[1], std::ios::in);
    
    // if file is opened
    if (file)
    {
        // declare a string to hold eachline
        std::string line;
        // get each line from the file
        while(std::getline(file, line))
        {
            // declare a vector of strings
            std::vector<std::string> a;
            // Split each line on ';'
            SplitLine(a, line);
            // find the intersect on the two strings in the vector
            Interect(a);
        }
    }
    
    // done with file, close it
    file.close();
    
    // stop the clock
    std::clock_t end = std::clock();
    // calculate the time the program took
    double time = (double)(end-begin) / CLOCKS_PER_SEC;
    // print the time it took
    std::printf("Time: %.9f\n",time);
    
    return 0;
}

/*
    This method splits a string on ';' and puts
    all the tokens into a vector
*/
void SplitLine(std::vector<std::string> &l, std::string line)
{
    // init string stream on the line passed 
    std::stringstream ss(line);
    // declare a string to hold data
    std::string a;

    // split and put into vector
    while(std::getline(ss, a, ';'))
        l.push_back(a);
}

/*
    This method finds the intersect on the vector of
    strings passed
*/
void Interect(std::vector<std::string> &data)
{
    // get the first string
    std::string first = data.front();
    // get the second string
    std::string last = data.back();
    // call method to split the string into vector of ints
    std::vector<int> a = Split(first, ',');
    std::vector<int> b = Split(last, ',');
    
    // declare a vector to hold results
    // of intersections
    std::vector<int> result;
    
    // init counter variables
    int i = 0;
    int j = 0;
    // while less than a and b
    while (i < a.size() && j < b.size())
    {
        // if current of a and b are the same
        if (a[i] == b[j])
        {
            // put into vector
            result.push_back(a[i]);
            // increment i and j
            i++;
            j++;
        }
        // if a is greater inc j, else inc i
        else if (a[i] > b[j])
            j++;
        else
            i++;
    }
    
    // if we have results
    if (result.size() > 0)
    {
        // declare string to hold answer
        std::string answer;
        // for each item in results vector, append
        for (auto i : result)
            answer += std::to_string(i) + ',';
        // remove last ',' from string
        answer.pop_back();
        // output the answer
        std::cout << answer << std::endl;
    }
    // else no results, print out a line
    else
        std::cout << std::endl;
}

/*
    This method splits the string into a vector on passed in
    delimeter
*/
std::vector<int> Split(std::string line, char delimeter)
{
    // declare a vector
    std::vector<int> data;
    
    // init string stream on line passed
    std::stringstream ss(line);
    // declare a string 
    std::string token;
    
    // while we can get data on the string stream, add to vector
    while(std::getline(ss, token, delimeter))
        data.push_back(std::stoi(token));
    // return vector
    return data;
}
