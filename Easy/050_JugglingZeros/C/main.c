#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512
#define SIZE 128

void juggleZeros(char *);
int extractZeros(char *, char *[]);
char *getBinaryString(char *[], int);
void append(char *, char);
long convert(char *);

int main(int argc, char **argv) {
    // if no file, exit
    if (argc < 2) {
        fprintf(stderr, "Error: No File\nExiting..\n");
        return EXIT_FAILURE;
    }
    // open the file
    FILE *file = fopen(argv[1], "r");
    // init a string
    char line[BUF];
    // get each line of the file
    while (fgets(line, BUF, file)) {
        // if new line, skip
        if (line[0] == '\n') continue;
        // strip new lines
        char *token = strtok(line, "\n");
        juggleZeros(token);
    }
}

// this method handles converting the
// sequence of zeros into a binary number
// then converting to a integer
void juggleZeros(char *line) {
    // init a string array for the zeros in the line
    char *zeros[SIZE];
    // extract the zeros into array and get the number of 'strings'
    int i = extractZeros(line, zeros);
    // get the binary string from the string array
    char *binaryString = getBinaryString(zeros, i);
    // output the converted binary string
    printf("%ld\n", convert(binaryString));
}

// helper method extracts the zeros from the line
// and puts into the zeros string array
int extractZeros(char *line, char *zeros[]) {
    // tokenize string on a space
    char *token = strtok(line, " ");
    // init a counter
    int i = 0;
    // while token is good
    while (token) {
        // put current into array
        zeros[i++] = token;
        // get next
        token = strtok(NULL, " ");
    }
    // return number of strings found
    return i;
}

// helper method returns the binary string
// from the string array
char *getBinaryString(char *zeros[], int len) {
    // declare a string for current zeros
    char *current;
    // allocate enough memory for the binary string
    char *binaryString = malloc(sizeof(char) *SIZE);
    // init a counter for array access
    int j = 0;
    // loop over array
    while (j < len) {
        // get the flag, "0" or "00"
        char *flag = zeros[j];
        // if flag is 0
        if (strcmp(flag, "0") == 0) {
            // get next string of zeros
            current = zeros[++j];
            // get the length
            int len = strlen(current);
            // loop over the number of zeros
            int k;
            for (k=0;k<len;k++)
                // append '0' to the binary string
                append(binaryString, '0');
        // else flag is "00"
        } else {
            // get next string of zeros
            current = zeros[++j];
            // loop over zeros
            int k;
            for (k=0; k<strlen(current); k++)
                // append '1' to binary string
                append(binaryString, '1');
        }
        // go to next flag
        j++;
    }
    // return the binary string
    return binaryString;
}

// helper method to append the char
// to the string
void append(char *string, char ch) {
    // get the length of the string
    int len = strlen(string);
    // make last char the char passed
    string[len] = ch;
}

// helper method converts
// binary string to a long
long convert(char *binStr) {
    char *st = &binStr[0];
    long num = 0;
    while (*st) {
        num *= 2;
        if (*st++ == '1') 
            num += 1;
    }
    return num;
}