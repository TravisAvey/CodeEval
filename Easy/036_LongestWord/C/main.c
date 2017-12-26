#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512 // buffer size
#define SIZE 20 // size of array to hold words

void longestWord(char *);

int main(int argc, char **argv) {
    // if file not passed, exit
    if (argc < 2) return EXIT_FAILURE;
    // open the file
    FILE *file = fopen(argv[1], "r");
    // init a string to hold the lines
    char line[BUF];
    // while we get a line from the file
    while (fgets(line, BUF, file)) {
        // ignore empty lines
        if (line[0] == '\n') continue;
        // strip the \n from each line
        char *token = strtok(line, "\n");
        // call method that prints longest word
        longestWord(token);
    }
    return EXIT_SUCCESS;
}

// this method prints out the longest word
// in the line
void longestWord(char *line) {
    // init an array of strings
    char *words[SIZE];
    // tokenize the string on spaces
    char *token = strtok(line, " ");
    // continue looping until token is null
    int i = 0;
    while (token) {
        // store the current word
        words[i++] = token;
        // get the next token
        token = strtok(NULL, " ");
    }

    // init a pos, for the longest word in the array
    int pos = 0;
    // init a int for the length of the longest word
    int longest = 0;
    // loop through words array
    int j;
    for (j=0; j<i; j++) {
        // store length of current word
        int len = strlen(words[j]);
        // if the current word length is greater than the longest
        if (len > longest) {
            // store the position
            pos = j;
            // store the length
            longest = len;
        }
    }
    // print the longest word
    printf("%s\n", words[pos]);
}