#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a buffer for each line
#define BUFFER 1024

int selfDescribe(char *);

int main(int argc, char **argv) {
    // open the file passed as 1st arguement
    FILE *file = fopen(argv[1], "r");
    // init a char array with size of BUFFER
    char line[BUFFER];

    // while we can get a line from the file, BUFFER amount at a time
    while (fgets(line, BUFFER, file)) {
        // init a string for the token
        char *token;
        // strip the line of new lines
        token = strtok(line, "\n");
        // output if the current line is self describing or not
        printf("%i\n",selfDescribe(token));
    }
    return 0;
}

int selfDescribe(char *line) {
    // for each char in the line
    int i;
    int len = strlen(line);
    for (i=0;i<len;i++) {

        // get the current char
        char c = line[i];
        // init a counter to 0
        int n = 0;

        // loop through and count how many times
        // the char occurs
        int k;
        for (k=0;k<len;k++) {
            // if the current index of the line
            // is the same as the current char
            if (i == ((int) line[k] - '0'))
                // increment the counter
                n++;
        }

        // if the count is not the same as
        // the char (not self describing)
        if (n != ((int) c - '0'))
            // return 0
            return 0;
    }
    // if we get here, the number is self describing
    return 1;
}