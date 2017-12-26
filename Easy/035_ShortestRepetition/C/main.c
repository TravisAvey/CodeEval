#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// buffer size
#define BUF 256

int repetition(char *);

int main(int argc, char **argv) {
    // if no file passed, exit
    if (argc < 2) return EXIT_FAILURE;
    // open the file passed to program
    FILE *file = fopen(argv[1], "r");
    // init a string to hold each line
    char line[BUF];
    // while we can get a line from the file
    while (fgets(line, BUF, file)) {
        // ignore empty lines
        if (line[0] == '\n') continue;
        // strip new lines from each line
        char *token = strtok(line, "\n");
        // output the repetition
        printf("%i\n", repetition(token));
    }

    return EXIT_SUCCESS;
}

// This method finds the shortest repetition
// 
// loops through the string, checks if the current
// char is the same as the first char.  if it is
// then return that length (current char from index 0)
// if we loop through and find no matches : no repetition
// and return the length of the string
int repetition(char *data) {
    // init the count to 0
    int repetition = 0;
    // get the length of the data
    int len = strlen(data);
    // init the index at 0
    int i = 0;
    // loop over the string
    int j;
    for (j=1; j<len; j++) {
        // if the current char is equal to first char
        if (data[i] == data[j]) {
            // the repetition is current char
            // minus i
            repetition = j - i;
            // break out of for loop
            break;
        }
    }

    // if the repetition is still 0
    if (repetition == 0)
        // there was no repetition, set to strlen
        repetition = len;
    // return the count of the shortest repetition
    return repetition;
}