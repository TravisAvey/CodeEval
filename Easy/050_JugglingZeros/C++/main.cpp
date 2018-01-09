#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>

#define SIZE 128

void juggleZeros(std::string &);
int extractData(std::string &, std::string []);
void getBinaryStr(std::string[], std::string &, int &);

int main(int argc, char **argv) {
  // if no file, exit
  if (argc < 2) return -1;
  // open file
  std::fstream file(argv[1], std::ios::in);
  // if file is good
  if (file) {
    // init a string
    std::string line;
    // while we can get a line from the file
    while (std::getline(file, line)) {
      // call method to juggle the zeros
      juggleZeros(line);
    }
  }
  return 0;
}

// This method handles converting the input
// exmple: 00 0 0 00 00 0
// into 1001 as a string
// then into the decimal 9
void juggleZeros(std::string &line) {
  // init an array to hold the zeros
  std::string zeros[SIZE];
  // init a string to hold the binary string
  std::string binaryStr;
  // get the data from the string, get number of items
  int count = extractData(line, zeros);
  // get the binary string from the zeros array
  getBinaryStr(zeros, binaryStr, count);
  // output decimal version of binary string
  std::cout << std::bitset<32>(binaryStr).to_ulong() << std::endl;

}

// Helper method that gets the data from the line, then
// puts into the string array and returns the count
int extractData(std::string &line, std::string zeros[]) {
  // init a string stream on the line
  std::stringstream ss(line);
  // declare a token
  std::string token;
  // init an index counter to 0
  int i = 0;
  // while we can get a token from the stream
  while (std::getline(ss, token, ' '))
    // put the token in the array
    zeros[i++] = token;
  // return index counter
  return i;
}

// This method gets the binary string from the array of zeros
void getBinaryStr(std::string zeros[], std::string &binaryStr, int &len) {
  // loop over number of items in zeros array
  for (int i=0; i<len; i++) {
    // if current is a 0
    if (zeros[i] == "0") {
      // next set of 0s are put into binary string
      binaryStr += zeros[++i];
    }
    // if current is 00
    else if (zeros[i] == "00") {
      // next set of zeros are put in as 1s
      // get the current string of 0s
      std::string z = zeros[++i];
      // loop over the length
      for (int j=0; j<z.length(); j++)
        // put a 1 for every zero in current string
        binaryStr += "1";
    }
  }
}
