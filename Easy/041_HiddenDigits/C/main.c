#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 128

void hiddenDigits(char *);
int getDigit(char);

int main(int argc, char **argv) {
    // if no file, return
    if (argc < 2) return EXIT_FAILURE;
    // open file
    FILE *file = fopen(argv[1], "r");
    // create a string to hold each line
    char line[BUF];
    // read each line into the string
    while (fgets(line, BUF, file)) {
        // remove the newlines
        char *token = strtok(line, "\n");
        // call method to find the hidden digits
        hiddenDigits(token);
    }
    return EXIT_SUCCESS;
}

// This method finds the hidden digits
void hiddenDigits(char *line) {
    // flag if found hidden digits
    int hasDigits = 0;
    // get the length of the string
    int len = strlen(line);
    // loop over the string
    int i;
    for (i=0; i<len;i++) {
        // store the current char
        char c = line[i];
        // if char is one of the digits we care about
        if (c >= 'a' && c <= 'j' || c >= '0' && c <= '9') {
            // output the hidden digit
            printf("%i", getDigit(c);
            // set flag that we found a hidden digit
            hasDigits = 1;
        }
    }
    // if we had digits
    if (hasDigits)
        // output new line
        puts("");
    // we didnt have hidden digits
    else
        // output none
        printf("NONE\n");
}

// this method returns the corresponding hidden digit
int getDigit(char c) {
    // return the corresponding
    if(c == 'a') return 0;
    else if (c == 'b') return 1;
    else if (c == 'c') return 2;
    else if (c == 'd') return 3;
    else if (c == 'e') return 4;
    else if (c == 'f') return 5;
    else if (c == 'g') return 6;
    else if (c == 'h') return 7;
    else if (c == 'i') return 8;
    else if (c == 'j') return 9;
    else if (c == '0') return 0;
    else if (c == '1') return 1;
    else if (c == '2') return 2;
    else if (c == '3') return 3;
    else if (c == '4') return 4;
    else if (c == '5') return 5;
    else if (c == '6') return 6;
    else if (c == '7') return 7;
    else if (c == '8') return 8;
    else if (c == '9') return 9;
}
