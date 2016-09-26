#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void PrintLongestWord (std::string &);
void GetWords (std::vector<std::string> *, std::string &);
int GetLongestWord (const std::vector<std::string> *);

int main (int argc, char *argv[])
{
    // open file
    std::fstream file (argv[1], std::ios::in);
    if (file)
    {
        // declare a string to hold each line
        std::string line;
        // while we can get a line from the file, print the longest word
        while (std::getline (file, line))
            PrintLongestWord (line);
    }
    return 0;
}

/*
    This method handles printing the longest word in the line 
*/
void PrintLongestWord (std::string &line)
{
    // create a vector to hold the words from the line
    auto words = new std::vector<std::string>;
    // method call to get the words from the line
    GetWords (words, line);

    // call method to get the longest position
    auto longest = GetLongestWord (words);
    // output the longest word in the line
    std::cout << words->at (longest) << std::endl;
    // remove dynamically created memory
    delete words;
}

/*
    This method breaks up the words in the sentance
*/
void GetWords (std::vector<std::string> *vect, std::string &words)
{
    // init a string stream on the words string
    std::stringstream ss(words);
    // declarea string to hold the tokens
    std::string token;

    // while we can get the words from the string stream, separated by a space
    while (std::getline (ss, token, ' '))
        // add the word to the vector
        vect->push_back (token);
}

/*
    This method handles finding the longest word in the vector and returns
    the position of that word
*/
int GetLongestWord (const std::vector<std::string> *words)
{
    // init variables
    int longest = 0;
    int pos = 0;
    int i = 0;
    // for each word in the vector of words
    for (auto word : *words)
    {
        // if the current word's length is greater than the longest
        if (word.length () > longest)
        {
            // set the longest to the length and set pos to current
            longest = word.length ();
            pos = i;
        }
        // increment i
        i++;
    }
    // return the longest word's position
    return pos;
}
