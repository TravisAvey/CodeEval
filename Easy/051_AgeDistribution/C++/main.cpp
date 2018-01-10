#include <iostream>
#include <fstream>
#include <sstream>

void ageDistribution(std::string &);

int main(int argc, char **argv) {
  // if no file exit
  if (argc < 2) return -1;
  // open file
  std::fstream file(argv[1], std::ios::in);
  // if file is opened
  if (file) {
    // init a string
    std::string line;
    // get each line in file, store in string
    while (std::getline(file, line)) {
      // call method for age distribution
      ageDistribution(line);
    }
  }
  return 0;
}

// This method outputs a statement to stdout
// based on the input, string as age
void ageDistribution(std::string &line) {
  // init a string stream on the line
  std::stringstream ss(line);
  // init an integer value to hold age
  int age = 0;
  // read from stringstream into the int
  ss >> age;
  //int age = std::stoi(line);
  // Ouput message based on age
  if (age >= 0 && age <= 2)
    std::cout << "Still in Mama's arms" << std::endl;
  else if (age >= 3 && age <= 4)
    std::cout << "Preschool Maniac" << std::endl;
  else if (age >= 5 && age <= 11)
    std::cout << "Elementary school" << std::endl;
  else if (age >= 12 && age <= 14)
    std::cout << "Middle school" << std::endl;
  else if (age >= 15 && age <= 18)
    std::cout << "High school" << std::endl;
  else if (age >= 19 && age <= 22)
    std::cout << "College" << std::endl;
  else if (age >= 23 && age <= 65)
    std::cout << "Working for the man" << std::endl;
  else if (age >= 66 && age <= 100)
    std::cout << "The Golden Years" << std::endl;
  else if (age < 0 || age > 100)
    std::cout << "This program is for humans" << std::endl; 
}
