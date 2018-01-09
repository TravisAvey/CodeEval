#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#define SIZE 64 // Array size

void dataRecovery(std::string &);
void getData(std::string &, std::string []);
int storeData(std::string [], std::string [], int []);
int findMissing(int [], int);

int main(int argc, char **argv) {
  // if no file, exit
  if (argc < 2) return -1;
  // open the file for reading
  std::fstream file(argv[1], std::ios::in);
  // if file is good
  if (file) {
    // declare a string to hold each line
    std::string line;
    // while we can get a line from the file
    while (std::getline(file, line)) {
      // call method to recover the data
      dataRecovery(line);
    }
  }
  return 0;
}

// Method handles the data recovery
void dataRecovery(std::string &line) {

  // data array ,0 -> words, 1 -> numbers
  std::string data[2];
  // array of words
  std::string words[SIZE];
  // array for output
  std::string output[SIZE];
  // array of the indices
  int nums[SIZE];
  // call method to get the data into array
  getData(line, data);
  // call method to store data and get the 
  // number of words in the string
  int count = storeData(data, words, nums);
  // find the missing index
  int missing = findMissing(nums, count-1);
  
  // loop over the number of indices
  for (int i=0; i<count-1; i++) {
    // store the index (-1 b/c the input indices are 1 based)
    int pos = nums[i] - 1;
    // store the output in the corect order
    output[pos] = words[i];
  }
  // finally put the final word
  output[missing-1] = words[count-1];
  // loop and output the correct order
  for (int i=0; i<count; i++)
    std::cout << output[i] << ' ';
  std::cout << std::endl;
}

// Helper method extracts data into an array
// data[0] = words
// data[1] = numbers (as string)
void getData(std::string &line, std::string data[]) {
  // init string stream on the line
  std::stringstream ss(line);
  // declare a token
  std::string token;
  int i = 0;
  // tokenize string on the ;
  while (std::getline(ss, token, ';')) {
    // put into the array
    data[i++] = token;
  }
}

// Helper method stores the data in the corresponding arrays
int storeData(std::string data[], std::string words[], int nums[]) {
  // create a string stream on the string of words
  std::stringstream ss(data[0]);
  // declare a string for the token
  std::string token;
  // init a counter
  int i = 0;
  // tokenize the string on spaces
  while (std::getline(ss, token, ' ')) {
    // add the word to the array
    words[i++] = token;
  }
  // init a counter for the indices
  int j = 0;
  // create a new string stream on the string of numbers
  std::stringstream stream(data[1]);
  // tokenize the string on spaces
  while (std::getline(stream, token, ' ')) {
    // add the current number (convert to int)
    nums[j++] = std::stoi(token);
  }
  // returns number of words,
  // as j is only number of indices found (always 1 less than)
  return i;

}

// Helper method finds the missing index
// from the array of nums
int findMissing(int nums[], int len) {
  // mSum for what sum should be
  int mSum = 0;
  // sum for what the nums array has
  int sum = 0;

  // add up what sum should be
  for (int i=1; i<=len+1; i++)
    mSum += i;

  // add up what sum is
  for (int i=0; i<len; i++)
    sum += nums[i];

  // the missing sum is what the sum is
  // from what the sum should be.
  return mSum - sum;
}
