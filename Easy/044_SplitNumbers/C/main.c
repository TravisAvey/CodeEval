#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256 // buffer size

void splitNumbers(char *);
void extractData(char *, char **, char **);

int main(int argc, char **argv) {
    // if no file passed, exit
    if (argc < 2) return EXIT_FAILURE;
    // open file
    FILE *file = fopen(argv[1], "r");
    // init a string
    char line[BUF];
    // read file line by line into string
    while (fgets(line, BUF, file)) {
        // if line is new line, skip
        if (line[0] == '\n') continue;
        // strip new line from the line
        char *token = strtok(line, "\n");
        // call method to split the numbers
        splitNumbers(token);
    }
    return EXIT_SUCCESS;
}

// This method splits the numbers and
// outputs the operation
//
// Sample:
// 1234 ab+cd
//
// Output:
// 46
void splitNumbers(char *data) {

    // declare 2 strings to hold the data
    char *numbers, *pattern;
    // call method to extract the data
    extractData(data, &numbers, &pattern);
    // declare a char to hold the operator
    char op;
    // declare a string to hold the first number
    char x[10];
    // loop over the pattern
    int i;
    for (i=0;i<strlen(pattern); i++) {
        // if the current char is a + or -
        if (pattern[i] == '+' || pattern[i] == '-') {
            // set what the pattern is and break out of loop
            op = pattern[i];
            break;
        }
        // put current char into the number array
        x[i] = numbers[i];
    }
    
    // declare stirng to hold second number
    char y[10];
    // copy from i to end into y
    strncpy(y, numbers + i, strlen(numbers) - i);
    // output corresponding math on the two numbers
    if (op == '+')
        printf("%i\n", atoi(x) + atoi(y));
    else if (op == '-')
        printf("%i\n", atoi(x) - atoi(y));
}

// This method extracts the data from the string
// input the data, and pointer to the numbers string and pointer
// to the pattern string
void extractData(char *data, char **numbers, char **pattern) {
    // tokenize string on a space
    char *token = strtok(data, " ");
    // first token is the number
    *numbers = token;
    // get second token
    token = strtok(NULL, " ");
    // second is the pattern, i.e.: a-cdef
    *pattern = token;
}