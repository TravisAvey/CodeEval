#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF 512 // Read file buffer size

void rollerCoaster(char *);

int main(int argc, char **argv) {
    // if no file, exit
    if (argc < 2) return EXIT_FAILURE;
    // open file
    FILE *file = fopen(argv[1], "r");
    // if file not good
    if (!file) {
        // output error and exit
        fprintf(stderr, "Error file %s not found.\n", argv[1]);
        return EXIT_FAILURE;
    }
    // init a string
    char line[BUF];
    // get each line and store into above string
    while (fgets(line, BUF, file)) {
        // if line is just a new line, skip
        if (line[0] == '\n') continue;
        // remove new lines from the line
        char *token = strtok(line, "\n");
        // call roller coaster method
        rollerCoaster(token);
    }
}

// This method outputs the string as a
// roller coaster.  EvErY oThEr LeTtEr
// is lower case or capitalized
void rollerCoaster(char *line) {
    // get the length of the line
    int len = strlen(line);
    // if first char is not upper case
    if (!isupper(line[0])) {
        // change to upper case
        line[0] = toupper(line[0]);
    }
    // init count to 1, where line[0] was 1
    int count = 1;
    // loop over string starting at line[1]
    int i;
    for (i=1; i<len; i++) {
        // cache the current char
        char ch = line[i];
        // if char is an alpha char
        if (isalpha(ch)) {
            // check if it is upper and odd
            if (isupper(ch) && count % 2 != 0) {
                // change the case
                line[i] = ch+32;
            // if lower and even
            } else if (islower(ch) && count % 2 == 0) {
                // change the case
                line[i] = ch-32;
            }
            // increment count to keep track if even or odd
            count++;
        }
    }
    // output roller coaster'd string to stdout
    printf("%s\n", line);
}