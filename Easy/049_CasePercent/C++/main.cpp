#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>

void casePercent(std::string &);

int main(int argc, char **argv) {
  if (argc < 2) return -1;
  std::fstream file(argv[1], std::ios::in);
  if (file) {
    std::string line;
    while (std::getline(file, line)) {
      casePercent(line);
    }

  }
  return 0;
}

void casePercent(std::string &line) {
  int len = line.length();
  int lower = 0;
  int upper = 0;
  for (int i=0; i<len; i++) {
    char ch = line[i];
    if (isalpha(ch)) {
      if (isupper(ch))
        upper++;
      else if (islower(ch))
        lower++;
    }
  }
  double lowerPercent = (double) lower / len * 100;
  double upperPercent = (double) upper / len * 100;
  printf("lowercase: %.2f uppercase %.2f\n", lowerPercent, upperPercent);

}
