#include <iostream>
#include <fstream>
#include <map>

void SetupMap(std::map<char, int> &);
int GetLetterValue(std::map<char, int> &, char);
int main (int argc, char *argv[])
{
    std::fstream file(argv[1], std::ios::in);
    if (file)
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::map<char, int> dict;
            SetupMap(dict);
            int sum = 0;
            for (auto i : line)
                sum += GetLetterValue(dict, i);
                
            std::cout << sum << std::endl;
        }
    }
    file.close();
    return 0;
}

void SetupMap(std::map<char, int> & scores)
{
    
    scores['A'] = 24;  scores['b'] = 25;  scores['C'] = 26;
    scores['a'] = 24;  scores['B'] = 25;  scores['c'] = 26;
    
    scores['D'] = 21;  scores['E'] = 22;  scores['F'] = 23;
    scores['d'] = 21;  scores['e'] = 22;  scores['f'] = 23;
    
    scores['G'] = 18;  scores['H'] = 19;  scores['I'] = 20;
    scores['g'] = 18;  scores['h'] = 19;  scores['i'] = 20;
    
    scores['J'] = 15;  scores['K'] = 16;  scores['L'] = 17;
    scores['j'] = 15;  scores['k'] = 16;  scores['l'] = 17;
    
    scores['M'] = 12;  scores['N'] = 13;  scores['O'] = 14;
    scores['m'] = 12;  scores['n'] = 13;  scores['o'] = 14;
    
    scores['P'] = 9;  scores['Q'] = 10;  scores['R'] = 11;
    scores['p'] = 9;  scores['q'] = 10;  scores['r'] = 11;
    
    scores['S'] = 6;  scores['T'] = 7;  scores['U'] = 8;
    scores['s'] = 6;  scores['t'] = 7;  scores['u'] = 8;
    
    scores['V'] = 3;  scores['W'] = 4;  scores['X'] = 5;
    scores['v'] = 3;  scores['w'] = 4;  scores['x'] = 5;
    
    scores['Y'] = 1;  scores['Z'] = 2;  
    scores['y'] = 1;  scores['z'] = 2;
}

int GetLetterValue(std::map<char, int> &dict, char ch)
{
    return dict[ch];
}