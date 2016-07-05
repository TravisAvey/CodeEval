#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

class Capital
{
private:
    // member variables
    std::list<std::string> mWords;

    // this method parses the line into
    // a list of words
    void Parse (std::string line)
    {
        // create a string stream on the line
        std::stringstream ss(line);
        // declare a string to hold the tokens
        std::string token;

        // while we can get the tokens from the line, put
        // into the list
        while (std::getline(ss, token, ' '))
            mWords.push_back (token);
    }

    // helper method to clear the list
    // for each time user calls capitalize
    // otherwise, will have a list full of all the words
    void ClearList()
    {
        mWords.clear();
    }

public:

    // sets the string into a list of words
    void SetWords(std::string line)
    {
        Parse(line);
    }

    // method capitalizes each word in the sentence
    std::string Capitalize ()
    {
        // init a string to hold the new string of captialized words
        std::string capital = "";
        
        // for each word in the current list
        for (auto word : mWords)
        {
            // cache the first letter
            auto ch = word[0];

            // if 1st char isnt a letter
            if (ch < 'a' || ch > 'z')
            {
                // append word and a space
                capital += word + ' ';
                // then continue to next word
                continue;
            }

            // upercase the first letter
            ch = toupper(ch);
            // append upper case letter + rest of word and a space
            capital += ch + word.substr(1) + ' ';
        }
        
        // call helper method to clear the list
        ClearList();
        // return captialized sentence to client
        return capital;
    }
};

int main(int argc, char *argv[])
{
    // open the file
    std::fstream file (argv[1], std::ios::in);
    // if file is good
    if (file)
    {
        // declare a string to hold the line
        std::string line;
        // init a Capital object
        auto capital = new Capital();

        // while we can get a line from the file
        while (std::getline(file, line))
        {
            // set the sentence to be capitalized
            capital->SetWords(line);
            // output the sentence with each word capitalized
            std::cout << capital->Capitalize() << std::endl;
        }
        
        // free up memory
        delete capital;
    }
    // done with file, close it
    file.close();
    
    return 0;
}