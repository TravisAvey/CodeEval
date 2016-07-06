#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


/*
    This class decodes a string to a writer with thier birthdate

    Pass a string containing the code and the decrypt code:

    osSE5Gu0Vi8WRq93UvkYZCjaOKeNJfTyH6tzDQbxFm4M1ndXIPh27wBA rLclpg| 3 35 27 62 51 27 46 57 26 10 46 63 57 45 15 43 53

    decodes to

    Stephen King 1947
*/
class FindWriter
{
private:
    // private member variables, letters and indices
    std::vector<int> mIndices;
    std::string mLetters;

    /*
        Helper method to parse the indices from
        the string
    */
    void Parse (std::string data)
    {
        // init a string stream
        std::stringstream ss(data);
        // delcare a token to hold each number
        std::string token;

        // while we can get the token from the stream
        while (std::getline (ss, token, ' '))
            // add the number to the vector (calling string to int method)
            mIndices.push_back(std::stoi(token));
    }

    // Helper method to clear the indices vector
    void ClearVector ()
    {
        mIndices.clear();
    }

public:
    /*
        This method inits the line,
        splits the string into a string
        of letters and a vector of ints
    */
    void Init (std::string line)
    {
        // declare a vector to hold the strings
        std::vector<std::string> data;
        // init a string stream on the line
        std::stringstream ss(line);
        // declare a string to hold the tokens
        std::string token;

        // split the string into two string
        while (std::getline(ss, token, '|'))
            data.push_back(token);
        // first part is the letters
        mLetters = data[0];
        // second part is the the code (first char is a space, substring 1 to end)
        Parse (data[1].substr(1));
    }

    /*
        Method returns a string that is
        the writer and birthdate decrypted
        from the string that was init
    */
    std::string GetWriter ()
    {
        // init an empty string
        std::string writer = "";

        // for each index in the indices vector
        for (auto i : mIndices)
            // add the letter with the code to the string
            writer += mLetters[i-1];
        
        // clear the vector
        ClearVector();
        // return string to client
        return writer;
    }
};


int main (int argc, char *argv[])
{
    // init a file with the data from console
    std::fstream file (argv[1], std::ios::in);

    // if file is good
    if (file)
    {
        // declare a string to hold the line from the file
        std::string line;
        // init a new FindWriter object
        auto writer = new FindWriter();
        // while we can get a line from the file
        while (std::getline(file, line))
        {
            // file will be data then blank line, so
            // if the line is blank, continue to next line
            if (line == "") continue;

            // init the line
            writer->Init(line);
            // write to stdout the decoded writer + birthdate
            std::cout << writer->GetWriter() << std::endl;
        }
        // delete pointer
        delete writer;
    }
    // close the file
    file.close();

    return 0;
}
