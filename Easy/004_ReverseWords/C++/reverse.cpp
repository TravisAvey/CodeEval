#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>

void ReverseWords(const std::string &);
std::stack<std::string> SplitString(const std::string &);

int main(int argc, char *argv[])
{
    // open file passed in as argv[1]
    std::fstream file(argv[1], std::ios::in);
    
    // if file is opened
    if (file.good())
    {
        // declare string to use for each line
        std::string line;
        
        // while able to get line on the file, call Reverse words method
        while (std::getline(file, line))
            ReverseWords(line);
    }
    
    // close file
    file.close();
    return 0;
}

/*
    This method takes in a string of words as a parameter
    to be reveresed.  And outputs the words in reverse order
    to std output
*/
void ReverseWords(const std::string &line)
{
    // get a stack of words calling split string method on passed in string
    std::stack<std::string> words = SplitString(line);
    
    // get the number of words in the stack
    int len = words.size();
    
    // we are ignoring empty lines.. return
    if (len == 0) return;
    
    // init the results string
    std::string result = "";
   
    // loop through every word in the stack   
    for (int i=0; i<len; ++i)
    {
        // get the top word, append to string add a space
        result += words.top() + " ";
        // pop top word off
        words.pop();
    }
    
    // we are finding the last whitespace in the string
    size_t endpos = result.find_last_not_of(" \t");
    // if npos is not endpos, set string to appropriate substring
    if( std::string::npos != endpos )
        result = result.substr( 0, endpos+1 );
    
    // output the result
    std::cout << result << std::endl;
}

/*
    This method takes in a string of words as a parameter
    and splits up the words and puts them in a stack
*/
std::stack<std::string> SplitString(const std::string &line)
{
    // declare a stack of strings
    std::stack<std::string> words;
    // init a string string on the passed in param
    std::stringstream ss(line);
    // declare a string to hold each word
    std::string token;
    
    // while we can get a word, add to stack 
    while (std::getline(ss, token, ' '))
        words.push(token);
        
    // return said stack
    return words;
}
