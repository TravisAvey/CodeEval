#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void dataRecovery(std::string &);
void getData(std::string &, std::string []);
int storeData(std::string [], std::string [], int []);

int main(int argc, char **argv) {

  if (argc < 2) return -1;
  
  std::fstream file(argv[1], std::ios::in);

  if (file) {

    std::string line;
    while (std::getline(file, line)) {
      dataRecovery(line);
    }
  }

  return 0;
}


void dataRecovery(std::string &line) {

  std::string data[2];
  std::string words[64];
  int nums[64];
  getData(line, data);

  int count = storeData(data, words, nums);
  printf("%i\n", count);
}

void getData(std::string &line, std::string data[]) {

  std::stringstream ss(line);
  std::string token;
  int i = 0;
  while (std::getline(ss, token, ';')) {
    data[i++] = token;
  }
}

int storeData(std::string data[], std::string words[], int nums[]) {
  // store the words
  std::stringstream ss(data[0]);
  std::string token;
  int i = 0;
  while (std::getline(ss, token, ' ')) {
    words[i++] = token;
  }
  // store the numbers
  int j = 0;
  std::stringstream stream(data[1]);
  while (std::getline(stream, token, ' ')) {
    nums[j++] = std::stoi(token);
  }
  return j;

}
