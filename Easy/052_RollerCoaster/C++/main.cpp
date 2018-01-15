#include <iostream>
#include <fstream>
#include <sstream>


void rollerCoaster(std::string &);

int main(int argc, char **argv) {
	// if no file, exit
	if (argc < 2) return EXIT_FAILURE;
	// open the file
	std::fstream file(argv[1], std::ios::in);
	// if the file is open
	if (file) {
		// init a string to hold each line
		std::string line;
		// while getline can get a line from file
		while (std::getline(file, line))
			// call method to create a roller coaster
			rollerCoaster(line);
	}

	return EXIT_SUCCESS;
}


/*
	This method turns the line into a roller coaster
	example:
		We are the world
	ouput:
		We ArE tHe WoRlD
*/
void rollerCoaster(std::string &line) {
	// get the length of the line
	int len = line.length();
	// init count to 1; for the first
	int count = 1;
	// get first char
	char first = line[0];
	// if first is lower
	if (islower(first))
		// change to upper
		line[0] = toupper(first);
	// loop over rest of string
	for (int i = 1; i < len; i++) {
		// cache the current char
		char current = line[i];
		// only if alpha char
		if (isalpha(current)) {
			// if even
			if (count % 2 == 0) {
				// change to upper
				line[i] = toupper(current);
			}
			else {
				// else count is odd, change to lower
				line[i] = tolower(current);
			}
			// increment count
			count++;
		}
	}
	// output to stdout the rollercoast line
	std::cout << line << std::endl;
}
