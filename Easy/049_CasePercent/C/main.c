#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 64  // buffer size

void casePercent(char *);

int main(int argc, char **argv) {
    // if no file exit
    if (argc < 2) {
        fprintf(stderr, "Missing file\n");
        return EXIT_FAILURE;
    }
    // open file
    FILE *file = fopen(argv[1], "r");
    // init a string
    char line[BUF];
    // get each line
    while (fgets(line, BUF, file)) {
        // if new line, skip
        if (line[0] == '\n') continue;
        // strip new line
        char *token = strtok(line, "\n");
        // call method to get case percentage
        casePercent(token);
    }
    return EXIT_SUCCESS;
}

// This method finds the percentage
// of lower/upper case chars
void casePercent(char *line) {
    // init counts
    int lower = 0;
    int upper = 0;
    int count = strlen(line);

    // loop over number of chars in string
    int i;
    for (i=0; i<count; i++) {
        // cache the current char
        char ch = line[i];
        // if lower case, increment lower count
        if (ch >= 'a'&& ch <= 'z')
            lower++;
        // if upper case, increment upper count
        else if (ch >= 'A' && ch <= 'Z')
            upper++;
    }

    // calculate the percentage of each lower and upper
    double lowPer = (double) lower / count * 100;
    double uppPer = (double) upper / count * 100;
    // output to 2 decimal places the percentage of lower/upper
    printf("lowercase: %.2f uppercase: %.2f\n", lowPer, uppPer);
}
