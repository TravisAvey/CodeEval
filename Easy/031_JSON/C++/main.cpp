#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>

class ParseJSON
{
private:
    std::string mJson;

    int ExtractNumber (std::string line)
    {
        std::string temp;
        std::cout << "In extract number line is " << line << std::endl;
        for (int i=0; i<line.size(); ++i)
        {
            std::cout << "line[i] : " << line[i] << std::endl;
            if (isdigit(line[i]))
            {
                for (int j=i; j<line.size(); ++j)
                    temp += line[j];
            }
            break;
        }
        std::cout << "temp " << temp << std::endl;
        int num = std::stoi (temp);
        return num;
    }

public:
    int FindValue (std::string word)
    {
        int val = 0;
        std::size_t found = mJson.find_first_of (word);
        std::cout << "found before loop " << found << std::endl;
        while (found != std::string::npos)
        {
            
            val += ExtractNumber (mJson.substr (found));
            
            found = mJson.find_first_of (word);
            std::cout << "found in while loop " << found << std::endl;
        }

        return val;
    }

    void SetJSON (std::string json)
    {
        mJson = json;
    }

};

int main (int argc, char *argv[])
{
    std::fstream file (argv[1], std::ios::in);

    if (file)
    {
        std::string line;
        auto parse = new ParseJSON ();
        while (std::getline(file, line))
        {
            if (line == "") continue;
            parse->SetJSON (line);
            std::cout << parse->FindValue ("Label ") << std::endl;
        }
    }

    file.close (); 
    return 0;
}