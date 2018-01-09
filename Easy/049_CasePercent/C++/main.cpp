#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>

void casePercent(std::string &);

int main(int argc, char **argv) {
  // if no file, exit
  if (argc < 2) return -1;
  // open file
  std::fstream file(argv[1], std::ios::in);
  // if file is good
  if (file) {
    // init string to hold each line
    std::string line;
    // while we can get a line from file
    while (std::getline(file, line)) {
      // call method to get the case percent
      casePercent(line);
    }
  }
  return 0;
}

// This method calculates the percentage
// of upper and lower case
void casePercent(std::string &line) {
  // get the length of the string
  int len = line.length();
  // init lower and upper counts to 0
  int lower = 0;
  int upper = 0;
  // loop over string
  for (int i=0; i<len; i++) {
    // get the the current char
    char ch = line[i];
    // if char is alpha
    if (isalpha(ch)) {
      // if char is upper case
      if (isupper(ch))
        // increment upper case count
        upper++;
      // if is lower case
      else if (islower(ch))
        // increment lower case
        lower++;
    }
  }
  // calculate the percentage of upper/lower case
  double lowerPercent = (double) lower / len * 100;
  double upperPercent = (double) upper / len * 100;
  // output the percentages to stdout
  printf("lowercase: %.2f uppercase: %.2f\n", lowerPercent, upperPercent);
}
