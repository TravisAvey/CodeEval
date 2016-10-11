#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>

class MixedContent
{
private:
    std::vector <int> nums;
    std::vector <std::string> words;

    // This method checks if we can convert the string to an int
    bool IsInt (const std::string &str)
    {
        // try the conversion
        try
        {
            // if this converts, return true
            int num = std::stoi (str);
            return true;
        }
        // if the conversion fails, skips over return true.. now return false
        catch (const std::invalid_argument)
        {
            return false;
        }
    }

public:
    
    // This method extracts the data from the line
    void ExtractData (const std::string & line)
    {
        // init a string stream on the line
        std::stringstream ss (line);
        // init a string to hold each token in the line
        std::string token;

        // while we can get a token, separated by a comma
        while (std::getline (ss, token, ','))
        {
            // if this current token is an int, then add to the nums vector
            if (IsInt (token))
                nums.push_back (std::stoi (token));
            // else this is a word, add to the words vector
            else
                words.push_back (token);
        }
    }

    // This method outputs the data
    void OutputData ()
    {
        
        // if we have any words
        if (words.size () > 0)
        {
            std::string outputWords;
            // append the words to the string
            for (auto w : words)
                outputWords += w + ',';
                
            // remove the last ','
            outputWords = outputWords.substr (0, outputWords.length () -1);
            // if we have any nums, output the separator
            if (nums.size () > 0)
                outputWords += '|';
            // output the words
            std::cout << outputWords;
        }

        // if we have any nums
        if (nums.size () > 0)
        {
            // loop through the nums
            for (int i=0; i<nums.size (); ++i)
            {
                // output the current num
                std::cout << nums[i];
                // if we are at the last one, break
                if (i == nums.size() -1)
                    break;
                // output a comma
                std::cout << ',';
            }
        }
        // output an end line
        std::cout << std::endl;
    }

};


int main (int argc, char **argv)
{
    // try to open the file
    std::fstream file (argv[1], std::ios::in);
    // if we can open the file
    if (file)
    {
        std::string line;
        // get each line from the file
        while (std::getline (file, line))
        {
            // init to mixedcontent object
            MixedContent mc;
            // exctract the data
            mc.ExtractData (line);
            // output the results
            mc.OutputData ();
        }   
    }
    return 0;
}
