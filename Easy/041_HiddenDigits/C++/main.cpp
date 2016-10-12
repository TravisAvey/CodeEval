#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

// This class handles retrieving the hidden digits from the data
class HiddenDigits
{
private:
    std::map <char, int> digits;
public:
    // public constructor inits the map
    HiddenDigits ()
    {
        digits['a'] = 0;    digits['0'] = 0;
        digits['b'] = 1;    digits['1'] = 1;
        digits['c'] = 2;    digits['2'] = 2;
        digits['d'] = 3;    digits['3'] = 3;
        digits['e'] = 4;    digits['4'] = 4;
        digits['f'] = 5;    digits['5'] = 5;
        digits['g'] = 6;    digits['6'] = 6;
        digits['h'] = 7;    digits['7'] = 7;
        digits['i'] = 8;    digits['8'] = 8;
        digits['j'] = 9;    digits['9'] = 9;
    }

    // returns the digit based on the char passed
    int GetDigit (const char &ch)
    {
        return digits[ch];
    }

    // checks if the char is in the map of hidden digits
    bool Exists (const char &ch)
    {
        if (digits.find(ch) == digits.end ())
            return false;
        else
            return true;
    }

};

void OutputDigits (const std::string &, HiddenDigits *);

int main (int argc, char **argv)
{
    // open the file
    std::fstream file (argv[1], std::ios::in);
    // if the file is opened
    if (file)
    {
        // init a string to hold each line
        std::string line;
        // dynamically created HiddenDigits object
        auto hd = new HiddenDigits ();
        // while we can get a line from the file
        while (std::getline (file, line))
            // output the digits
            OutputDigits (line, hd);

        // delete dynamically created object
        delete hd;
    }

    return 0;
}

/*
    This method will find the hidden digits from the the string
*/
void OutputDigits (const std::string &line, HiddenDigits *hd)
{
    // flag to determine if we the string has any hidden digits
    bool flag = false;
    // for each char in the string
    for (auto ch : line)
    {
        // if the current char exists
        if (hd->Exists (ch))
        {
            // output the hidden digit
            std::cout << hd->GetDigit (ch);
            // set the flag that we have a hidden digit
            flag = true;
        }
    }

    // if the flag is false by this point, output none
    if (!flag)
        std::cout << "NONE";
    std::cout << std::endl;
}
