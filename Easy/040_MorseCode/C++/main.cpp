#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

// This class holds the morse code data
class MorseCode
{
private:
    std::map<std::string, char> code;
public:
    // public constructor
    MorseCode ()
    {
        // init the morse code map with each letter and number
        code[".-"] = 'A';       code[".."] = 'I';       code["--.-"] = 'Q';     code["-.--"] = 'Y';
        code["-..."] = 'B';     code[".---"] = 'J';     code[".-."] = 'R';      code["--.."] = 'Z';
        code["-.-."] = 'C';     code["-.-"] = 'K';      code["..."] = 'S';
        code["-.."] = 'D';      code[".-.."] = 'L';     code["-"] = 'T';
        code["."] = 'E';        code["--"] = 'M';       code["..-"] = 'U';
        code["..-."] = 'F';     code["-."] = 'N';       code["...-"] = 'V';
        code["--."] = 'G';      code["---"] = 'O';      code[".--"] = 'W';
        code["...."] = 'H';     code[".--."] = 'P';     code["-..-"] = 'X';


        code["-----"] = '0';         code["....."] = '5';
        code[".----"] = '1';         code["-...."] = '6';
        code["..---"] = '2';         code["--..."] = '7';
        code["...--"] = '3';         code["---.."] = '8';
        code["....-"] = '4';         code["----."] = '9';
    }

    // this method returns the corresponding letter/number for the code
    char GetLetter (const std::string &morse)
    {
        return code[morse];
    }
};

void GetCode (std::string &, MorseCode *);

int main (int argc, char **argv)
{
    // open the file
    std::fstream file (argv[1], std::ios::in);
    // if file can be opened
    if (file)
    {
        // create a new MorseCode object
        auto morseCode = new MorseCode ();
        // init a string to hold each line in the file
        std::string line;
        // while we can get a line from the file
        while (std::getline (file, line))
            // call method to output the morse code
            GetCode (line, morseCode);
        // delete dynamically created object
        delete morseCode;
    }

    return 0;
}

// This method outputs the morse code for the line
void GetCode (std::string &line, MorseCode *mc)
{
    // init a position
    auto pos = 0;
    // init a vector
    std::vector<std::string> words;
    // loop till we break
    while (true)
    {
        // if we can't find a double space
        if ( (pos = line.find("  ")) == std::string::npos)
        {
            // add the rest to the words
            words.push_back (line);
            break;
        }
        
        // add the word to the vector
        words.push_back (line.substr(0, pos));
        // set the line to the rest of the line, past the double space
        line = line.substr (pos+2);
        // increment counter to avoid an endless loop
        pos++;
    }

    // for each word in the words vector
    for (auto w : words)
    {
        // init a string stream
        std::stringstream ss(w);
        // init a string to hold each token
        std::string token;

        // while we can get a token delimited by a space
        while (std::getline (ss, token, ' '))
            // output the corresponding letter/number
            std::cout << mc->GetLetter (token);
        // output a space here, because it will be a new word
        std::cout << ' ';
    }
    // output a new line to separate the morse codes
    std::cout << std::endl;
}
