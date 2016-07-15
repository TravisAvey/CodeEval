#include <iostream>
#include <fstream>
#include <string>

// Class to Parse the JSON
class ParseJSON
{
private:
    // string to hold the JSON
    std::string mJson;

    // Extracts first number in the string passed
    int ExtractNumber (std::string line)
    {
        // a temp string to hold the number as a strin
        std::string temp;
        
        // loop through the lin
        for (int i=0; i<line.size(); ++i)
        {
            // current char is a digit
            if (isdigit(line[i]))
            {
                // loop until we don't 
                for (int j=i; j<line.size(); ++j)
                    temp += line[j];
            }
            break;
        }
        
        // convert temp to an int and return
        int num = std::stoi (temp);
        return num;
    }

public:
    // finds the value assocaiated with the word passed in
    int FindValue (std::string word)
    {
        // init the value to 0
        int val = 0;

        // find the location of the first word in the JSON
        std::size_t found = mJson.find (word);

        // while the word is found
        while (found != std::string::npos)
        {
            // set the mJson to a substring (else forever loop || wont get a number)
            mJson = mJson.substr (found + word.length());

            // add the value
            val += ExtractNumber (mJson);
            
            found = mJson.find(word);
           // std::cout << "found in while loop " << found << std::endl;
        }
        // return the value
        return val;
    }

    // Set the JSON string
    void SetJSON (std::string json)
    {
        mJson = json;
    }

};

int main (int argc, char *argv[])
{
    // open the file
    std::fstream file (argv[1], std::ios::in);

    // if file is good
    if (file)
    {
        // init a string for the line
        std::string line;
        // init a new object to Parse the JSON
        auto parse = new ParseJSON ();
        // while we can get a line
        while (std::getline(file, line))
        {
            // if the line is blank, continue to next
            if (line == "") continue;
            // set the JSON to parse
            parse->SetJSON (line);
            // output the value found after each Label in the JSON
            std::cout << parse->FindValue ("Label ") << std::endl;
        }
        // delete the pointer
        delete parse;
    }
    // close the file
    file.close (); 
    return 0;
}
